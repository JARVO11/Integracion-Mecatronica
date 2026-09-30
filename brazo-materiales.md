---
layout: default
title: Materiales y fabricación
parent: "Brazo robótico de 3 GDL"
nav_order: 2
---

<div class="project-page-header">
  <p class="portfolio-eyebrow">BRAZO 3 GDL · LISTA PRELIMINAR</p>
  <h1>Materiales y fabricación</h1>
  <p>Componentes recomendados para construir y probar un prototipo escolar seguro y fácil de modificar.</p>
</div>

## Lista preliminar de materiales

| Sistema | Componente | Cantidad | Recomendación inicial |
|:--|:--|:--:|:--|
| Control | ESP32 DevKit | 1 | Microcontrolador principal con USB y conectividad inalámbrica. |
| PWM | Módulo PCA9685 de 16 canales | 1 | Genera señales estables para los cuatro servos mediante I²C. |
| Movimiento | Servo de engranes metálicos de alto torque | 3 | Para base, hombro y codo; punto de partida: 15–20 kg·cm. |
| Pinza | Servo de engranes metálicos | 1 | Para abrir y cerrar; punto de partida: 2–4 kg·cm. |
| Potencia | Fuente regulada de 5–6 V | 1 | Capacidad inicial recomendada: 8–10 A, según los servos elegidos. |
| Protección | Fusible de 7.5–10 A e interruptor | 1 de cada uno | Protegen y permiten desconectar la alimentación de los servos. |
| Estabilidad | Capacitor electrolítico de 1000–2200 µF, 10 V o más | 1 | Colocarlo cerca de la entrada de potencia del controlador. |
| Estructura | MDF | Según planos | 3 mm puede servir como referencia, pero debe coincidir con las ranuras CAD. |
| Impresión 3D | PLA+ o PETG | Según piezas | PLA+ para prototipo; PETG para piezas con mayor esfuerzo o flexión. |
| Ensamble | Tornillería M3/M4, arandelas y tuercas autofrenantes | Según CAD | Evitan que las uniones se aflojen con el movimiento. |
| Articulaciones | Ejes, pernos de hombro, bujes o rodamientos | Según CAD | Elegir después de confirmar diámetros y espesores. |
| Cableado | Cable 16–18 AWG para potencia y 22–24 AWG para señales | Según recorrido | Añadir conectores, terminales y funda organizadora. |
| Acabado | Patas de goma y cinchos | 4 y varios | Mejoran la estabilidad y el manejo del cableado. |

## Herramientas sugeridas

- Cortadora láser para los paneles de MDF.
- Impresora 3D para separadores, soportes, engranes y pinza.
- Cautín, estaño, pelacables y pinzas de crimpado.
- Multímetro para verificar voltajes, continuidad y consumo.
- Calibrador Vernier para comprobar espesores, ejes y perforaciones.
- Juego de llaves, brocas y desarmadores.

## Selección de servos

El valor de torque indicado es una **estimación inicial**, no una compra definitiva. Para seleccionar correctamente los servos hay que conocer la longitud de cada eslabón, su masa, el peso máximo del objeto y la distancia del centro de masa al eje. El hombro suele ser la articulación más exigida.

Antes de comprar se debe comprobar que las dimensiones de la carcasa, la posición del eje y los orificios del servo coincidan con los soportes del CAD.

## Alimentación eléctrica segura

{: .warning }
**No se deben alimentar los cuatro servos desde el pin de 5 V del ESP32.** Los servos usarán una fuente externa regulada. La tierra de esa fuente, la del PCA9685 y la del ESP32 deben estar conectadas en común.

Durante el arranque o cuando el brazo se detiene contra un límite, varios servos pueden demandar mucha corriente al mismo tiempo. Por eso la fuente, el fusible y el calibre de los cables deben elegirse con margen.

## Recomendaciones de fabricación

1. Confirmar el espesor real del MDF y adaptar las ranuras del ensamble antes del corte.
2. Imprimir primero una pequeña prueba de tolerancia para ejes, tornillos y alojamientos de servo.
3. Ensamblar la estructura sin adhesivo para detectar interferencias.
4. Mover cada articulación manualmente y comprobar que no existan bloqueos.
5. Instalar y centrar los servos antes de fijar sus brazos o engranes.
6. Añadir topes de software antes de hacer pruebas con carga.
