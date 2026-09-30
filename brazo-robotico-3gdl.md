---
layout: default
title: Brazo robótico de 3 GDL
nav_order: 2
has_children: true
---

<div class="project-page-header">
  <p class="portfolio-eyebrow">PROYECTO 01 · EN DESARROLLO</p>
  <h1>Brazo robótico de 3 GDL</h1>
  <p>Diseño y construcción de un brazo robótico escolar con estructura de MDF cortada en láser, piezas impresas en 3D y control electrónico mediante ESP32.</p>
</div>

## Descripción general

El proyecto busca fabricar un brazo capaz de posicionarse y tomar objetos. El mecanismo tiene **tres grados de libertad (3 GDL)** y utiliza **cuatro servomotores**:

| Actuador | Función | Clasificación |
|:--|:--|:--|
| Servo 1 | Giro de la base | GDL 1 |
| Servo 2 | Movimiento del hombro | GDL 2 |
| Servo 3 | Movimiento del codo | GDL 3 |
| Servo 4 | Apertura y cierre de la pinza | Efector final |

El servo de la pinza no se cuenta como un cuarto grado de libertad de posicionamiento porque su función es sujetar el objeto. Las **perillas visibles en el ensamble CAD son referencias del modelo y no se utilizarán** en la versión final.

## Documentación del proyecto

<div class="topic-grid">
  <a class="topic-card topic-card--link" href="{{ '/brazo-diseno-cad/' | relative_url }}">
    <strong>01 · Diseño CAD y piezas</strong>
    <p>Ensamble general, galería de componentes y función de las primeras piezas recibidas.</p>
    <span>Ver diseño →</span>
  </a>
  <a class="topic-card topic-card--link" href="{{ '/brazo-materiales/' | relative_url }}">
    <strong>02 · Materiales y fabricación</strong>
    <p>Lista preliminar de materiales, recomendaciones de fabricación y alimentación eléctrica.</p>
    <span>Ver materiales →</span>
  </a>
  <a class="topic-card topic-card--link" href="{{ '/brazo-electronica-control/' | relative_url }}">
    <strong>03 · Electrónica y control</strong>
    <p>Conexiones, comandos y código inicial del ESP32 para controlar los cuatro servos.</p>
    <span>Ver control →</span>
  </a>
  <div class="topic-card topic-card--pending">
    <strong>04 · Ensamble y pruebas</strong>
    <p>Próximamente: fotografías, videos, calibración, toma de objetos y resultados.</p>
    <span>En preparación</span>
  </div>
</div>

## Estado actual

Se integró la primera entrega de capturas CAD, una lista preliminar de materiales y un programa base para el ESP32. La documentación se ampliará conforme estén disponibles las piezas restantes, dimensiones, archivos de fabricación, fotografías y videos.

> **Importante:** antes de cortar MDF o comprar servos se deben comprobar las dimensiones reales de las ranuras, soportes y ejes en los archivos CAD.
