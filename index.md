---
layout: default
title: Inicio
nav_order: 1
---

<div class="portfolio-hero">
  <p class="portfolio-eyebrow">PORTAFOLIO DE INTEGRACIÓN MECATRÓNICA</p>
  <h1>Diseñamos, fabricamos y documentamos</h1>
  <p class="portfolio-hero__lead">
    Este portal reúne el desarrollo completo de nuestros proyectos: desde la idea y el diseño CAD
    hasta la fabricación, el ensamble, la programación y las pruebas físicas.
  </p>
  <div class="portfolio-hero__actions">
    <a class="btn btn-primary" href="#proyectos">Explorar proyectos</a>
    <a class="btn" href="https://github.com/JARVO11/documentacion-robot-limpia-playas">Ver repositorio</a>
  </div>
</div>

<h2 id="proyectos">Proyectos</h2>

<p class="portfolio-section-lead">
  Cada sección funcionará como una bitácora técnica con planos, modelos 3D, fotografías,
  videos, resultados y archivos descargables.
</p>

<div class="project-grid">
  <a class="project-card project-card--featured" href="{{ '/brazo-robotico-3gdl/' | relative_url }}">
    <span class="project-card__number">01</span>
    <span class="project-badge">En desarrollo</span>
    <span class="project-card__title">Brazo robótico de 3 GDL</span>
    <p>Diseño CAD, piezas impresas en 3D, estructura de MDF cortada con láser, ensamble y pruebas tomando objetos.</p>
    <span class="project-card__link">Ver proyecto <span aria-hidden="true">→</span></span>
  </a>

  <a class="project-card" href="{{ '/robot-limpia-playas/' | relative_url }}">
    <span class="project-card__number">02</span>
    <span class="project-badge project-badge--outline">En documentación</span>
    <span class="project-card__title">Robot limpia playas</span>
    <p>Diseño y fabricación de un robot para apoyar la recolección de residuos, con documentación mecánica, electrónica y de pruebas.</p>
    <span class="project-card__link">Ver proyecto <span aria-hidden="true">→</span></span>
  </a>

  <a class="project-card" href="{{ '/fabricacion-pcb-kicad/' | relative_url }}">
    <span class="project-card__number">03</span>
    <span class="project-badge project-badge--outline">En documentación</span>
    <span class="project-card__title">Fabricación de PCB con KiCad</span>
    <p>Proceso completo desde el esquema y diseño de pistas hasta la fabricación, soldadura y validación de la placa.</p>
    <span class="project-card__link">Ver proyecto <span aria-hidden="true">→</span></span>
  </a>
</div>

## Cómo se organizará la documentación

<div class="documentation-flow">
  <div class="documentation-flow__item">
    <span>1</span>
    <span class="project-card__title">Diseño</span>
    <p>Requisitos, bocetos, cálculos, planos, CAD y decisiones técnicas.</p>
  </div>
  <div class="documentation-flow__item">
    <span>2</span>
    <span class="project-card__title">Fabricación</span>
    <p>Materiales, impresión 3D, corte láser, electrónica y ensamble físico.</p>
  </div>
  <div class="documentation-flow__item">
    <span>3</span>
    <span class="project-card__title">Validación</span>
    <p>Programación, videos de funcionamiento, pruebas, resultados y mejoras.</p>
  </div>
</div>

> La estructura crecerá de forma progresiva. Empezaremos con el **brazo robótico de 3 GDL** y añadiremos el material técnico conforme esté disponible.
