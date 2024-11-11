# Galvan Engine 💻

## ¿De qué trata el proyecto? 😀

- Este proyecto se basa en el aprendizaje sobre el manejo y entendimiento de API's Gráficas.
- Se utilizarán varias estrategias y buenas prácticas de programación entre ellas patrones de diseño y el correcto uso de reuso de código.

## Documentación en forma de reporte 🍎

[Notion Notas 📄](https://jeasdeveloper.notion.site/Graficas-computacionales-3D-51cc6e7dcbb74f95b804307b9c2b6a26?pvs=25)

## Advertencia 🚨

Este proyecto está vinculado con una ruta absoluta, por tanto, es necesario modificar la ruta absoluta para que funcione el proyecto al momento de correrlo.

## Estructura del Proyecto 📁

### Actor.h

El archivo `Actor.h` define la clase `Actor`, que representa cualquier entidad que pueda participar en la escena del juego. Los actores pueden tener componentes y comportamientos específicos que les permiten interactuar con otros actores y el entorno.

### Component.h

`Component.h` define la clase base `Component` de la cual heredan todos los componentes del sistema. Los componentes agregan funcionalidad específica a los `Actor`, permitiendo una estructura modular y reutilizable. Algunos ejemplos de componentes podrían ser transformaciones, renderizado, física, etc.

### Entity.h

El archivo `Entity.h` contiene la definición de la clase `Entity`, que actúa como un gestor de entidades en la escena. Las entidades son objetos del juego que pueden tener múltiples componentes y comportamientos, gestionados por la `Entity`.

### Implementación de Imgui

`Imgui` es una biblioteca de interfaz gráfica de usuario (GUI) que se usa para depuración y herramientas de desarrollo. En este proyecto, `Imgui` sirve para implementar varias herramientas y vistas, como el inspector y la jerarquía.

- **Inspector:** Permite ver y editar las propiedades de los actores y componentes seleccionados.
- **Jerarquía:** Muestra la estructura de la escena, permitiendo seleccionar y organizar los actores.
- **Placer de Actores:** Proporciona una interfaz para agregar nuevos actores a la escena.

### Creación de Figuras con ShapeFactory

La `ShapeFactory` es una clase responsable de crear y gestionar formas geométricas en la escena. Esta fábrica puede crear diversas formas como círculos, rectángulos y triángulos, y ofrece métodos para manipular sus propiedades como posición, rotación, y escala.

### Otros Componentes Importantes

- **Transform:** Gestiona la posición, rotación y escala de los actores.
- **Window:** Encapsula la ventana de renderizado y los métodos asociados con la misma.
- **NotificationService:** Gestiona los mensajes de notificación y los errores durante la ejecución del proyecto.

## Características Principales 🌟

- **Modularidad:** Uso de componentes para añadir funcionalidades específicas a los actores.
- **Interacción en Tiempo Real:** Modificación de propiedades en tiempo real a través de `Imgui`.
- **Creación Dinámica:** Generación dinámica de formas y actores dentro de la escena del juego.
- **Gestión de Escena:** Jerarquía y control de entidades dentro de la escena.

## Contribuciones 🛠️

Las contribuciones son bienvenidas. Por favor, sigue las pautas establecidas en el archivo `CONTRIBUTING.md`.

## Licencia 📜

Este proyecto está bajo la licencia MIT. Consulta el archivo `LICENSE` para más detalles.

Si tienes más preguntas o necesitas asistencia, no dudes en consultar la documentación vinculada o contactar al equipo de desarrollo.
