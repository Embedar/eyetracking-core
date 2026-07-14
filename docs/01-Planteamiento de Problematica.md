# Diseño Inicial: Prototipo Eye Tracking Core

---

# 1. Definición del Problema

## ¿Qué problema técnico o necesidad global estoy resolviendo?

Se busca desarrollar un prototipo de software capaz de medir y visualizar el movimiento de la mirada de un usuario mientras utiliza un computador, empleando únicamente hardware de bajo costo.

Este prototipo tiene como propósito servir como una primera aproximación al desarrollo de sistemas de Eye Tracking accesibles, permitiendo comprender el funcionamiento general del seguimiento ocular antes de avanzar hacia sistemas de mayor complejidad.

---

## ¿Qué quiero construir exactamente?

Se desea construir una aplicación capaz de:

- Detectar continuamente la dirección de la mirada del usuario.
- Estimar hacia qué región de la pantalla está observando.
- Mostrar en tiempo real un indicador visual (cursor o marcador) que represente dicha estimación.
- Obtener métricas básicas del comportamiento ocular para su posterior análisis.

El objetivo principal no es controlar el cursor del sistema operativo, sino validar que el seguimiento ocular realizado por el software representa correctamente la dirección de la mirada.

---

## ¿Por qué quiero construirlo?

Este proyecto constituye la primera etapa de una investigación orientada al desarrollo de un sistema de Eye Tracking de bajo costo.

La finalidad a largo plazo es disponer de una plataforma que permita estudiar la respuesta ocular frente a diferentes estímulos y que, eventualmente, pueda utilizarse como base para herramientas de apoyo al diagnóstico de patologías relacionadas con el movimiento ocular.

Antes de llegar a ese punto es necesario comprender completamente el proceso de adquisición, procesamiento y visualización del movimiento de la mirada mediante un prototipo funcional.

---

## ¿Qué necesidad existe?

Actualmente la mayoría de dispositivos comerciales de Eye Tracking poseen costos elevados, lo que limita considerablemente su utilización en:

- Laboratorios de investigación.
- Universidades.
- Centros educativos.
- Pequeños grupos de investigación.
- Proyectos Open Source.

Contar con una alternativa basada en hardware convencional podría facilitar el acceso a este tipo de tecnologías y abrir nuevas oportunidades de investigación.

---

## ¿Qué problema quiero ayudar a resolver?

Democratizar el acceso a tecnologías de seguimiento ocular mediante soluciones abiertas y de bajo costo que permitan reducir la dependencia de equipos especializados de alto precio.

---

## ¿Quién presenta este problema?

Principalmente:

- Grupos de investigación.
- Laboratorios universitarios.
- Investigadores independientes.
- Desarrolladores de tecnologías médicas.
- Proyectos Open Source relacionados con visión por computador y Eye Tracking.

---

## ¿Cuál es mi problema actual?

Actualmente no poseo experiencia práctica desarrollando sistemas de seguimiento ocular.

Por ello este proyecto busca construir un prototipo sencillo que permita comprender completamente el flujo de funcionamiento de un sistema de Eye Tracking antes de abordar soluciones de mayor precisión.

---

## ¿Quién interactúa con el sistema?

Los actores principales son:

- Usuario.
- Aplicación de Eye Tracking.

Como elementos externos participan:

- Cámara utilizada como fuente de video.
- Sistema Operativo.

---

## ¿Cuál es el resultado esperado?

El sistema debe ser capaz de estimar continuamente la dirección de la mirada del usuario mientras utiliza el computador y representar dicha información mediante un indicador visual en pantalla, permitiendo validar el correcto funcionamiento del algoritmo y obtener información útil sobre el comportamiento ocular.

---

# 2. Requisitos y Restricciones

## Requisitos Funcionales

El sistema deberá ser capaz de:

1. Capturar continuamente el flujo de video proveniente de una cámara web.
2. Procesar cada imagen recibida.
3. Detectar el rostro del usuario.
4. Detectar ambos ojos.
5. Estimar la dirección de la mirada.
6. Mantener el seguimiento mientras el usuario mueve ligeramente la cabeza.
7. Mantener el seguimiento durante el parpadeo normal.
8. Recuperar automáticamente el seguimiento cuando el rostro vuelva a aparecer tras perderse temporalmente.
9. Priorizar el seguimiento del primer usuario detectado.
10. Mostrar un indicador visual en pantalla que represente la posición estimada de la mirada.
11. Ejecutarse en tiempo real.
12. Funcionar mientras el usuario utiliza otras aplicaciones.

---

## Entradas del sistema

La información de entrada corresponde a:

- Flujo continuo de video.
- Imagen a color.
- Movimiento de ojos.
- Movimiento natural de la cabeza.
- Parpadeo del usuario.

No se definen aún requisitos específicos de:

- FPS.
- Resolución.
- Latencia máxima aceptable.

Estos parámetros serán determinados durante la fase experimental.

---

## Salidas del sistema

El sistema deberá generar:

- Indicador visual del seguimiento ocular (cursor o círculo).
- Posición estimada de la mirada.
- (Opcional) Métricas básicas del seguimiento para validación del algoritmo.

---

## Requisitos No Funcionales

### Portabilidad

- Compatible principalmente con Windows.
- Deseable compatibilidad futura con Linux.

### Rendimiento

- Procesamiento en tiempo real.
- Uso eficiente de CPU.
- Posibilidad de utilizar GPU cuando sea conveniente.

### Disponibilidad

- Funcionamiento completamente offline.
- Sin dependencia de servicios en Internet.

### Modularidad

El software deberá dividirse en módulos independientes para facilitar mantenimiento, pruebas y futuras mejoras.

---

## Restricciones del entorno

El comportamiento esperado contempla las siguientes situaciones:

### Debe soportar

- Movimiento natural de ojos.
- Movimiento moderado de cabeza.
- Parpadeo normal.
- Recuperación automática del seguimiento tras perder temporalmente el rostro.

### Comportamiento esperado

Si el rostro desaparece:

- El seguimiento debe detenerse temporalmente.
- El software no debe fallar.
- Debe reanudar el seguimiento cuando el usuario vuelva a aparecer.

Si aparece una segunda persona:

- El sistema continuará siguiendo únicamente al primer usuario detectado.

---

## Casos no contemplados en esta primera versión

No forman parte del alcance inicial:

- Uso con gafas.
- Condiciones extremas de iluminación.
- Desconexión de la cámara.
- Cierre inesperado del software de captura de video.
- Congelamiento del flujo de video.

Estos escenarios podrán abordarse en versiones posteriores.

---

# 3. Arquitectura Conceptual Inicial

El sistema se dividirá conceptualmente en los siguientes módulos independientes:

## 1. Captura

Responsable de adquirir continuamente el flujo de video desde la cámara.

---

## 2. Detección

Localiza el rostro y los ojos dentro de cada imagen.

---

## 3. Estimación de la Mirada

Calcula la dirección aproximada hacia la que observa el usuario.

---

## 4. Visualización

Representa mediante un indicador visual la posición estimada de la mirada sobre la pantalla.

---

## 5. Registro de Métricas

Responsable de almacenar y presentar información relacionada con el seguimiento ocular para facilitar el análisis del algoritmo.

---

# 4. Objetivo General

Desarrollar un prototipo funcional de Eye Tracking capaz de estimar y visualizar en tiempo real la dirección de la mirada del usuario utilizando hardware convencional, con el propósito de comprender el funcionamiento del seguimiento ocular y sentar las bases para el desarrollo futuro de una plataforma abierta y de bajo costo orientada al estudio y análisis del comportamiento visual.

---

# 5. Alcance de esta Primera Versión

Esta primera versión busca únicamente demostrar que es posible:

- Detectar la mirada.
- Estimar su dirección.
- Representarla visualmente.
- Obtener una primera aproximación al comportamiento ocular.

No se pretende alcanzar precisión clínica ni realizar diagnósticos médicos. El proyecto constituye un prototipo de investigación y aprendizaje sobre tecnologías de Eye Tracking.