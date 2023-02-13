# Servidor Web con Esp32

### Introducción

Un servidor web con ESP32, ¿es posible alojar un servidor Web en la tarjeta?, ¿para qué?. La respuesta es sencilla: para poder acceder de manera remota a la placa mediante el protocolo de comunicación HTTP sin necesidad de tener hardware especializado. Esto permite tener el control remoto de la Esp32 desde cualquier punto de la red desde el que se tenga acceso. Esto último implica dos cosas: 
- tanto el cliente Web como el esp32 estan en la misma red (se accede directo por IP local asignada a la placa)
- la tarjeta tiene asignada una IP fija y el cliente accede desde cualquier punto por Internet.
Para más información consultar este [link](https://es.wikipedia.org/wiki/Direcci%C3%B3n_IP).


### ¿Cómo funciona un Servidor Web? 

Un servidor Web es un proceso dedicado capaz de responder  mensajes mediante el protocolo HTTP enviados desde un cliente. Típicamente los clientes Web más usados son los navegadores Web como Google Chrome, Firefox, etc.

Comunmente cuando se escribe la **URL** (cadena que identifica unívocamente a un recurso del servidor) desde un navegador lo que este hace es enviar una solicitud HTTP al servidor WEB (mediante un método específico del protocolo llamado **GET**). El trabajo se traslada al servidor WEB que debe de poder procesar esa solicitud.

Por ejemplo, si se escribe una URL como **http://192.168.1.125/ledon** en el navegador de un PC o móvil,  el navegador envía una solicitud HTTP al ESP32 (identificado como un nodo más de la red) para que procese esta solicitud, encendia un LED y devuelva como respuesta una página web (contenido HTML) al navegador mostrándole el estado del LED: ON.

### Modos de funcionamiento

El ESP32 con la librería Wifi.h nos posibilita trabajar de varias maneras diferentes. No solo la típica conexión al AP (punto de acceso) de tu router (como cualquier PC o móvil), sino que también permite una conexión directa entre ESP32 y los clientes sin pasar por el router, ni por su punto de acceso Wifi.

- **Modo Estación (STA)**: su comportamiento que como cualquier otro dispuesto en vuestra casa, móvil, PC o tablet.
- **Modo de Punto de acceso (AP)**: en este modo de operar, el ESP32 crea su propia red Wifi, permitiendo conexiones máquina a máquina, estableciendo una comunicación directa entre dos o más estaciones (PC, móvil, Tablets) sin un punto de acceso que enrute el tráfico.
- Existe un tercer modo que es un modo mixto, es decir, es un híbrido que se comporta de los dos modos anteriores.

Cualquiera de estos modos de operar son posibles con ESP32, la diferencia radica en decidir como se quiere que se comporte el ESP32. 

### Primer servidor Web

Para un primer ejemplo se creará un servidor web independiente con un ESP32 que controla las salidas (dos LED) mediante el entorno de programación Arduino IDE. El servidor web responde a dispositivos móviles y se puede acceder a él con cualquier dispositivo que funcione como navegador en la red local. Se mostrará cómo crear el servidor web y cómo funciona el código paso a paso.

#### Circuito del proyecto

Se conectan dos LED al ESP32 como se muestra en el siguiente diagrama esquemático: un LED conectado a **GPIO 26**, y el otro para **GPIO 27**.

![picture 1](images/esp32_web_server_schematic.webp) 

#### Código en Arduino IDE

El código de este primer servidor esta [aquí](/sketchs/Server_web/).

Para que el código anterior funcione es necesario obtener el SSID y clave de la red local a la se va a conectar tanto el Esp32 como el movil o pc desde donde se quiera hacer la prueba. Luego de definir dichos valores como constantes en el sketch es necesario subir el código a la placa y obtener desde el Monitor Serial la dirección IP asignada a la tarjeta (tal como se muestra a modo de ejemplo en la siguiente imagen).

![picture 2](images/ESP-IP-address-1.webp) 


### Consideraciones de funcionamiento:
> 
> Una vez definidos los valores de las constantes SSID y PASS >lo siguiente es crear un servidor en un puerto determinado por >ejemplo puerto 80 mediante la línea:

``` c++
WiFiServer server(80);
```

> Luego se programa qué hacer cuando un nuevo cliente establece una conexión con el servidor web, tal como se muestra en la línea:

``` c++
WiFiClient client = server.available();
if(client){
    //....
}
```
> El loop seguirá ejecutandose validando que la variable **client** no sea nula, en tal caso entiende que tiene un nuevo cliente que atender y comienza un nuevo ciclo mientras el cliente se encuentre conectado.

> Lo que sigue a continuación es el procesamiento típico de una solicitud HTTP: se lee byte a byte el header o cabecera de la solicitud hasta que se encuentra con un salto de línea o '\n'.En el header se encontrará tícamente con el método HTTP utilizado por el cliente (GET/POST) seguido de la URL que identifica el recurso solicitado. Con esta información es posible definir las acciones a tomar en función del estado de la placa.

> Por último se crea una cadena con el código HTML que será enviado al cliente como respuesta HTTP. Notar que el código incluye una sentencia break para salir del ciclo while() utilizado para el procesamiento de la petición.


## Ejercitación

> Caso práctico 03:
> * Tomando el skectch del caso práctico 02, refactorizar su código para crear un servidor Web que permita encender el relay de manera remota utilizando la conexión WIFI a la red local, y dejar sin efecto el encendio mediante el pulsador. Para ver el código de la solución acceder a esta carpeta: [Práctico 03](sketchs/Practico%2003/)

