# Plataformas IoT 

### Introducción
Una plataforma de IoT es una parte integral de cualquier servicio basado en el Internet de las Cosas. Puede ayudarte a acelerar el tiempo de comercialización, minimizar el riesgo, reducir el costo de desarrollo y ayudarte a llegar más rápido al mercado de los productos.

### ¿Qué es una plataforma de IoT?
Una plataforma de Internet de las cosas es un grupo de tecnologías que proporcionan los bloques de construcción para desarrollar un producto IoT. Las plataformas de IoT proveen la "infraestructura" que se usa para crear las características específicas de una solución.

Al asumir la funcionalidad no diferenciada, las plataformas de IoT ayudan a reducir el riesgo y el costo de desarrollo y a acelerar el tiempo de comercialización de un producto.

Cuando se habla de plataformas IoT, a menudo se lanza a la jerga técnica como protocolos de transporte, motores de reglas, repositorios de datos, etc. Si bien esas consideraciones son importantes y merecen una planificación cuidadosa, no ilustran claramente cómo una plataforma de IoT puede ayudar en el desarrollo de un producto IoT.

### Funcionalidades clave

Las tareas clave de una plataforma IoT son:

- Adquirir datos del mundo real a través de sensores
- Analizar los datos localmente (edge computing)
- Conectarse a la nube para transmitir datos y recibir órdenes
- Almacenar los datos en la nube
- Analizar los datos en la nube para crear una visión
- Ordenar a las "cosas" que realicen tareas específicas basadas en la comprensión
- Presentar las ideas a los usuarios
 
 Adicionalmente debería proporcionar servicios para:

- Realizar todas las operaciones de forma segura a través de la pila de tecnología IoT
- Identificar y gestionar todos sus dispositivos de IoT a escala

### Plataforma Cloud IOT
Esta categoría de plataformas IoT proporciona los elementos básicos para su producto, incluyendo el consumo, el transporte, el almacenamiento, el análisis y la visualización de datos. Como su nombre lo indica, su objetivo es permitir el rápido desarrollo de su aplicación abstrayendo las complejidades de la construcción de una solución IoT.

Hay cientos de plataformas de Internet de las cosas en el mercado, por lo que puede ser desalentador averiguar cuál de ellas utilizar. Las plataformas de habilitación de aplicaciones incluyen:

- Plataformas industriales
- Plataformas de consumo
- Plataformas dirigidas a los desarrolladores
- Plataformas de alto nivel (arrastrar y soltar), buenas para la - creación de prototipos o MVPs
- Plataformas que se centran en verticales específicas
- Plataformas en el lugar vs. Edge vs. Cloud

Algunos de los principales actores en el espacio de las plataformas cloud IoT incluyen:

- Microsoft Azure IoT
- AWS IoT
- Google Cloud IoT Core
- ThingSpeak
- Arduino IoT Cloud

### ThingSpeak

ThingSpeak es una plataforma abierta de aplicaciones, diseñada para permitir conectar personas con objetos. Se caracteriza por ser una plataforma Open Source  con una API para almacenar y recuperar datos de los objetos usando el protocolo HTTP sobre Internet o vía LAN (Local Area Network).

Se trata de una plataforma basada en Ruby on Rails 3.0 (RoR), este es un framework de aplicaciones web  de código abierto basado en Ruby, cuya arquitectura está basada en el Modelo Vista Controlador (MVC). Se caracteriza por su simplicidad a la hora de programar aplicaciones del mundo real, escribiendo menos código y con una configuración mucho más sencilla que otros frameworks. Otra de las características que hacen de RoR un framework perfecto para el desarrollo de aplicaciones es que permite el uso de meta programación, haciendo que su sintaxis sea más legible y llegue a un gran número de usuarios.

#### Características principales
Algunas características importantes de esta plataforma son:
- Dispone de una **API** de programación abierta. Un punto importante a la hora de desarrollar cualquier proyecto es encontrar un API disponible de forma sencilla para que el desarrollador tenga los mecanismos necesarios para el desarrollo de la aplicación. En este caso, ThigSpeak dispone de una API la cual está disponible en GitHub para su descarga en un servidor propio. Es totalmente abierta, por lo que también se puede modificar su código fuente original y así contribuir a la comunidad con nuevas características, un principio básico en toda
plataforma Open Source.

- **Plugins**: para extender la funcionalidad del sitio también se nos brinda la oportunidad de desarrollar plugins. Estos nos ofrecen la posibilidad de crear aplicaciones de forma nativa en nuestra plataforma ThigSpeak.  Soporta HTML, CSS y JavaScript como lenguajes de programación. Al igual que los canales los plugins pueden ser público o privados según sean nuestras necesidades.
- **Integración**: Uno de los puntos fuertes en cualquier plataforma IoT, es que permita una amplia integración con diversos dispositivos Hardware y software. En este caso ThingSpeak permite la integración de su plataforma con: Arduino/ Raspberry Pi/Móbiles/Aplicaciones web/Redes Sociales o Análisis de datos con MATLAB 

- Otra característica es que dispone de un conjunto de apps para conectar con redes sociales, soportar comunicación con Web Services, calendarizar tareas o incluso definir reglas que disparen acciones ante ciertos valores de datos recibidos en un canal.

#### Chanels

Los canales almacenan todos los datos que recopila una aplicación ThingSpeak. Cada canal incluye ocho campos que pueden contener cualquier tipo de datos, más tres campos para datos de ubicación y uno para datos de estado. Una vez que recopila datos en un canal, se utilizan las aplicaciones de ThingSpeak para analizarlos y visualizarlos.

Para crear canales es necesario contar primero con una cuenta en la plataforma. Una vez creado el usuario a partir de una mail validado, es posible crear canales para los proyectos.


#### Proyecto de aplicación

Para un primer proyecto de aplicación se propone generar un conjunto de valores aleatorios (con valores comprendidos entre 1 y 100) desde la placa Esp32 que podemos pensar en datos recolectados de un **sensor X** con un propósito específico y enviarlos a la plataforma para su visualización en tiempo real sobre un dashboard que grafique los valores enviados desde la placa.

Lo primero es crear un canal llamado **Random IoT Values** con un solo campo llamado **sensor**. Una vez confirmados los datos del canal, de la pestaña de **API Key** copiar los valores de: Channel ID y Write API Key. Dichos valores serán utilizados en el sketch de Arduino IDE para inicializar la librería de la plataforma. 

El código del proyecto se encuentra [aquí](/sketchs/random_values.ino)


## Ejercitación

Caso Práctico 04:
Diseñar una estación meteorológica desarrollada apartir de una placa ESP32 y los sensores DHT11, DHT22 y BMP180. La información recolectada por los sensores es enviada a un servidor de ThingSpeak mediante Wifi. 

El desarrollo completo de este proyecto se puede acceder mediante el siguiente [link](
https://github.com/ingeniero-yt/estacion-meteorologica).
