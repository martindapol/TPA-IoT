# Programación en Arduino
## Lenguaje C/C++

* Creado por Dennis Ritchie en los laboratorios de AT&T entre 1969 y 1973
* Para escribir el SO Unix en un Lenguaje de Alto Nivel e independiente del hardware 
* Basado en el B de Ken Thompson
* En 1978 Ritchie junto a Bryan Kernigan publican el libro: “El lenguaje de programación C”
* A partir de dicho libro surge el lenguaje conocido como “el C de Kernigan y Ritchie” o simplemente “K&R C”
* A mediados de los 80 Bjarne Stroustrup crea el Lenguaje C++

> Para programar un Arduino, el lenguaje estándar es C++, aunque es posible programarlo en otros lenguajes. No es un C++ puro sino que es una adaptación que proveniente de avr-libc que provee de una librería de C de alta calidad para usar con GCC en los microcontroladores AVR de Atmel y muchas funciones específicas para los MCU AVR de Atmel.

### Fundamentos

* Lenguaje de programación estructurada + POO
* Originalmente concebido como de alto nivel, hoy de medio/bajo nivel en comparación con los lenguajes actuales
* Lenguaje Compilado, es decir que se parte del código fuente se compila en una plataforma y se obtiene un ejecutable para esa plataforma
* Manejo libre y a cargo del programador de la memoria
* Lenguaje fuertemente tipado.

### Comentarios

Dos posibilidades para definir comentarios en el código de un sketch:
* Comentario de una sola línea: //comentario...
* Comentario en más de una línea : /*...*/

### Tipo de datos

El ambiente Arduino es realmente C++, con bibliotecas de soporte, y además asume algunos parámetros relativos al microcontrolador, para simplificar el proceso de programación. C++ define una cantidad de tipos de datos distintos.

A continuación se listan tipos de datos comúnmente utilizados en el ambiente **Arduino**, con el tamaño de memoria de cada uno entre paréntesis.

* **boolean** (8 bit)- lógico simple verdadero/falso.
* **byte** (8 bit)- número sin signo entre 0 y 255.
* **char** (8 bit)- número con signo, entre -128 y 127. En algunos casos el compilador intentará interpretar este tipo de dato como un caracter, lo que puede generar resultados inesperados.
* **unsignedchar** (8 bit)- lo mismo que ‘byte’; si es que eso es lo que necesitas, deberías usar ‘byte’, para que el código sea más claro.
* **word** (16 bit)- número sin signo entre, 0 y 65535.
* **unsignedint** (16 bit)- lo mismoque ‘word’. Utiliza ‘word’ por simplicidad y brevedad.
* **int** (16 bit)- número con signo, entre -32768 y 32767. Este tipo es el más usado para variables de propósito general en Arduino, en los códigos de ejemplo que vienen con el IDE.
* **unsignedlong** (32 bit)- número sin signo entre 0 y 4294967295. Este tipo se usa comúnmente para almacenar el resultado de la función millis(), la cual retorna el tiempo que el código actual ha estado corriendo, en milisegundos.
* **long** (32 bit)- número con signo, entre -2,147,483,648 y 2,147,483,647.
* **float** (32 bit)- número con signo, entre 3.4028235E38 y 3.4028235E38. El Punto Flotante no es un tipo nativo en Arduino; el compilador debe realizar varios saltos para poder hacerlo funcionar. Evítalo siempre que te sea posible. Hablaremos de eso más tarde; En una fecha próxima se publicará un tutorial más riguroso en el uso genérico de la matemática de punto decimal en Arduino.

### Variables simples y estructuras de control

Al igual que C++ es posible definir variables simples y estructuradas; y combinarlas con estructuras  de control condicionales y repetitivas. El detalle completo de variables, operadores, funciones, punteros y estructuras de control está disponible en la documentación de referencia de Arduino: https://www.arduino.cc/reference/en/.

### Arreglos

Un array (**o arreglo**) es un conjunto estático de valores (todos del mismo tipo) a los que se accede con un número índice. Cualquier valor puede ser recogido haciendo uso del nombre de la variable y el número del índice. El primer valor del arreglo es el que está indicado con el índice 0, es decir el primer valor del conjunto es el de la posición 0. Un array tiene que ser declarado y opcionalmente asignados valores a cada posición antes de ser utilizado.

Tener en cuenta:
>* Para definir: **tipo_de_dato** nombre[size]; O también **tipo_de_dato** nombre[] = >val, val2,….,valn};
>* Para acceder: nombre[índice]
>* Las cadenas tienen un tratamiento especial, pero se manejan como arreglos de caracteres. Por ejemplo: char message[6] = "hello";

### Uso de funciones


![Picture01](images/anatomy_function.png)

#### Parámetros por Valor

> Pasar parámetros por valor o copia, las modificaciones realizadas en la función no se mantienen al terminar la misma.
![Picture02](images/function_params_valor.png)

#### Parámetros por referencia

> Los parámetros pasados por referencia pueden ser modificados en la función y dicha modificación sobrevive al final de la misma.
> * Se agrega operador & en la definición del prototipo de la función
int myFuncion(int &p1, int p2)
>
> * Otra manera de lograrlo es utilizar punteros:
>
>     int myFunction(int * p1, int p2)


### Constantes y funciones basicas de E/S

Para **E/S digitales**
| Función| Descripción |
| --- | --- |
|pinMode(pin, modo)|Configura el pin especificado para que se comporte como una entrada (INPUT) o una salida (OUTPUT). Adicionalmente es posible indicar INPUT_PULLUP,  INPUT_PULLDOWN para entradas con resistencias integradas PULL_UP o PULL_DOWN respectivamente|
|digitalWrite(pin, valor)|Escribe un valor HIGH o un LOW en un pin digital.|
|digitalRead(pin)|Lee el valor de un pin digital especificado, ya sea HIGH o LOW.|


Para **E/S analógicas**
| Función| Descripción |
| --- | --- |
|analogRead(pin)|Lee el valor del pin analógico especificado. Las placas Arduino contienen un convertidor analógico a digital multicanal de 10 bits. Esto significa que mapeará los voltajes de entrada entre 0 y el voltaje de funcionamiento (5 V o 3,3 V) en valores enteros entre 0 y 1023. Puntualmente en Esp32 es posible leer lecturas de 0 a 3.3V asignando un valor comprendido entre 0 y 4095.|
|analogWrite(pin,valor)|Escribe un valor analógico ( onda PWM ) en un pin. Se puede usar para encender un LED con diferentes brillos o impulsar un motor a varias velocidades.|
|analogReference()|Configura el voltaje de referencia utilizado para la entrada analógica (es decir, el valor utilizado como la parte superior del rango de entrada). En Esp32 el valor por defecto es 3.3V|


Para **comunicación Serie**
| Función| Descripción |
| --- | --- |
|Serial.begin(speed)|Establece la velocidad de datos en bits por segundo (baudios) para la transmisión de datos en serie. Para comunicarse con Serial Monitor, asegúrese de usar una de las velocidades en baudios enumeradas en el menú en la esquina inferior derecha de su pantalla. Un segundo argumento opcional configura los bits de datos (Serial.begin(speed, config)), paridad y parada. El valor predeterminado es 8 bits de datos, sin paridad, un bit de parada.|
|Serial.read()|Lee los datos seriales entrantes.|
|Serial.print(val,[format])|Imprime datos en el puerto serial como texto ASCII legible por humanos. Este comando puede tomar muchas formas. Los números se imprimen utilizando un carácter ASCII para cada dígito. Los flotantes se imprimen de manera similar como dígitos ASCII, por defecto con dos decimales. Los bytes se envían como un solo carácter. Los caracteres y las cadenas se envían tal cual.|
|Serial.println(val,[format])|Imprime datos en el puerto serie como texto ASCII legible por humanos seguido de un carácter de retorno de carro (ASCII 13 o '\r') y un carácter de nueva línea (ASCII 10 o '\n'). Este comando toma las mismas formas que Serial.print() .|
|Serial.available()|Obtiene la cantidad de bytes (caracteres) disponibles para leer desde el puerto serie. Estos son datos que ya llegaron y se almacenaron en el búfer de recepción en serie (que contiene 64 bytes).|

**Constantes** más usadas:
| Constantes| Descripción |
| --- | --- |
|INPUT/OUTPUT|Permite definir entradas o salidas mendiante la función pinMode().|
|HIGH (5V)/LOW (0V)| Permiten indicar un valor Alto o Bajo de tensión dependiendo la configuración del pin.|
|LED_BUILTIN|La mayoría de las placas Arduino tienen un pin conectado a un LED integrado en serie con una resistencia. La constante LED_BUILTIN es el número del pin al que está conectado el LED integrado. La mayoría de las placas tienen este LED conectado al pin digital 13. Para el caso de los Esp32 este valor corresponde a 2| 

## Ejercitación

> Caso práctico 02:
>* Desarrollar un sketch que permita encender/apagar un LED utilizando un pulsador.
>* Agregar al sketch la posibilidad de mostrar mediante una pantalla LCD (16x2) que muestre el estado del LED (cadenas: ENCENDIDO!/APAGADO! respectivamente)
Para ver el código de la solución acceder a esta carpeta: [Práctico 02](skectchs/Practico%2002/)


> Caso práctico 03:
> * Tomando el skectch anterior, refactorizarlo para soportar un relay que permita habilitar/deshabilitar el paso de corriente.
> * Adicionalmente crear un servidor Web que permita encender el el relay de manera remota utilizando la conexión WIFI a la red local.