---
layout: default
title: Electrónica y control
parent: "Brazo robótico de 3 GDL"
nav_order: 3
---

<div class="project-page-header">
  <p class="portfolio-eyebrow">BRAZO 3 GDL · ESP32</p>
  <h1>Electrónica y control</h1>
  <p>Arquitectura inicial para controlar cuatro servomotores sin utilizar las perillas que aparecen en el modelo CAD.</p>
</div>

## Arquitectura propuesta

El ESP32 envía por I²C las posiciones al controlador PCA9685. Este módulo genera las cuatro señales PWM y los servos reciben energía de una fuente externa de 5–6 V.

| Conexión | Origen | Destino |
|:--|:--|:--|
| SDA | ESP32 GPIO 21 | PCA9685 SDA |
| SCL | ESP32 GPIO 22 | PCA9685 SCL |
| 3.3 V | ESP32 | PCA9685 VCC lógico |
| GND | ESP32 | PCA9685 GND y negativo de la fuente |
| 5–6 V | Fuente externa | PCA9685 V+ de servos |
| Canales 0–3 | PCA9685 | Base, hombro, codo y pinza |

{: .warning }
Nunca conectes el positivo de la fuente de servos al pin de 5 V del ESP32. Sí es indispensable unir todas las tierras para que las señales tengan la misma referencia.

## Control inicial por monitor serial

Esta primera versión evita depender de perillas. Desde el monitor serial, configurado a **115200 baudios** y con salto de línea, se envía una letra seguida del ángulo deseado:

| Comando | Movimiento | Ejemplo |
|:--|:--|:--|
| `B` | Base | `B90` |
| `H` | Hombro | `H110` |
| `C` | Codo | `C70` |
| `G` | Garra | `G45` |

El programa limita el recorrido de cada articulación y mueve los servos de forma gradual. Más adelante se puede añadir una interfaz web, control Bluetooth, joystick o una secuencia automática de toma de objetos.

## Código para ESP32

Antes de compilar, instala desde el gestor de bibliotecas del IDE de Arduino la librería **Adafruit PWM Servo Driver Library**.

[Descargar el archivo `control-servos-esp32.ino`]({{ '/assets/files/brazo-3gdl/control-servos-esp32.ino' | relative_url }}){: .btn .btn-primary }

```cpp
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm(0x40);
constexpr uint16_t SERVO_FREQ = 50;

struct Articulacion {
  char comando;
  const char* nombre;
  uint8_t canal;
  int anguloMin;
  int anguloMax;
  uint16_t pulsoMinUs;
  uint16_t pulsoMaxUs;
  int anguloActual;
};

Articulacion articulaciones[] = {
  {'B', "Base",    0, 20, 160, 1000, 2000, 90},
  {'H', "Hombro", 1, 35, 145, 1000, 2000, 90},
  {'C', "Codo",    2, 25, 155, 1000, 2000, 90},
  {'G', "Garra",   3, 30,  90, 1000, 2000, 45}
};

constexpr size_t NUM_ARTICULACIONES =
  sizeof(articulaciones) / sizeof(articulaciones[0]);

uint16_t microsegundosATicks(uint16_t microsegundos) {
  return (uint32_t)microsegundos * SERVO_FREQ * 4096UL / 1000000UL;
}

void escribirAngulo(size_t indice, int angulo) {
  Articulacion &a = articulaciones[indice];
  angulo = constrain(angulo, a.anguloMin, a.anguloMax);

  uint16_t pulsoUs = map(
    angulo, a.anguloMin, a.anguloMax, a.pulsoMinUs, a.pulsoMaxUs
  );

  pwm.setPWM(a.canal, 0, microsegundosATicks(pulsoUs));
  a.anguloActual = angulo;
}

void moverSuave(size_t indice, int destino) {
  Articulacion &a = articulaciones[indice];
  destino = constrain(destino, a.anguloMin, a.anguloMax);
  int paso = (destino >= a.anguloActual) ? 1 : -1;

  while (a.anguloActual != destino) {
    escribirAngulo(indice, a.anguloActual + paso);
    delay(12);
  }
}

int buscarArticulacion(char comando) {
  comando = toupper(comando);
  for (size_t i = 0; i < NUM_ARTICULACIONES; i++) {
    if (articulaciones[i].comando == comando) return i;
  }
  return -1;
}

void mostrarAyuda() {
  Serial.println("Comandos: B=base, H=hombro, C=codo, G=garra");
  Serial.println("Ejemplo: B90");
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);

  for (size_t i = 0; i < NUM_ARTICULACIONES; i++) {
    escribirAngulo(i, articulaciones[i].anguloActual);
  }

  mostrarAyuda();
}

void loop() {
  if (!Serial.available()) return;

  String entrada = Serial.readStringUntil('\n');
  entrada.trim();
  if (entrada.length() < 2) return;

  int indice = buscarArticulacion(entrada.charAt(0));
  if (indice < 0) {
    Serial.println("Comando no valido.");
    mostrarAyuda();
    return;
  }

  int destino = entrada.substring(1).toInt();
  moverSuave(indice, destino);

  Serial.printf(
    "%s: %d grados\n",
    articulaciones[indice].nombre,
    articulaciones[indice].anguloActual
  );
}
```

## Calibración obligatoria

Los límites angulares y pulsos incluidos son valores iniciales conservadores. Antes de conectar los eslabones:

1. Probar un servo a la vez sin carga.
2. Comenzar cerca del centro, alrededor de 1500 µs.
3. Ampliar el recorrido lentamente y detenerse antes de que el servo fuerce la estructura.
4. Guardar límites diferentes para cada articulación.
5. Verificar que ninguna combinación provoque una colisión mecánica.

No todos los servos aceptan exactamente el mismo rango de pulsos; si el motor zumba o se calienta, se debe reducir el recorrido inmediatamente.
