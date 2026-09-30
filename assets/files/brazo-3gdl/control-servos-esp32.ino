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
  {'B', "Base",    0, 20, 160, 600, 2400, 90},
  {'H', "Hombro", 1, 35, 145, 600, 2400, 90},
  {'C', "Codo",    2, 25, 155, 600, 2400, 90},
  {'G', "Garra",   3, 30,  90, 600, 2400, 45}
};

constexpr size_t NUM_ARTICULACIONES = sizeof(articulaciones) / sizeof(articulaciones[0]);

uint16_t microsegundosATicks(uint16_t microsegundos) {
  return (uint32_t)microsegundos * SERVO_FREQ * 4096UL / 1000000UL;
}

void escribirAngulo(size_t indice, int angulo) {
  Articulacion &a = articulaciones[indice];
  angulo = constrain(angulo, a.anguloMin, a.anguloMax);
  uint16_t pulsoUs = map(angulo, a.anguloMin, a.anguloMax, a.pulsoMinUs, a.pulsoMaxUs);
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
  Serial.printf("%s: %d grados\n", articulaciones[indice].nombre, articulaciones[indice].anguloActual);
}
