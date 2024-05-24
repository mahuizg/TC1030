# TC1030
## Objetivo
El objetivo del programa que crearé durante las cinco semanas que corresponden a TC1030, es proveer un registro de los animales que se encuentran en un refugio. El usuario podrá dar de alta animales que lleguen al refugio, y también podrá dar de baja a los animales que sean adoptados. De igual manera, este programa facilitará la visualización de todos los animales que se encuentren en el refugio, junto con información relevante sobre el animal, como su nombre, edad, sexo, color, y raza. 

El objetivo es que, al ejecutar el programa, se despliegue un menú en el que el usuario pueda seleccionar entre registrar un animal, dar de baja a un animal, o desplegar la información de los animales. Análogamente, si el usuario opta por desplegar los datos de los animales del refugio, se le dará la opción de visualizar perros o gatos.

## Casos en los que el programa dejaría de funcionar
Debido a que la intención es poder implementar un menú con distintas opciones para que el usuario seleccione, el programa deberá recibir una entrada. El programa fallará si el usuario intenta ingresar una cadena de texto, pues las opciones disponibles serán únicamente números enteros. 

## Diagrama UML
Para el desarrollo de este proyecto, fue necesario iniciar con el diseño de un Diagrama UML. Mi diagrama consiste de una clase madre llamada Animal, la cual contiene todos los atributos que heredarán las clases de Perro y Gato (las cuales están unidas a dicha clase madre con una línea que termina en flecha), al igual que los métodos pertenecientes a la clase. Análogamente, tanto la clase Perro como la clase Gato poseen un atributo cada una, pues son atributos que no comparten entre ellos: para el perro, necesitaremos saber el tamaño, mientras que para el gato, tendremos un atributo de independencia, el cual será un número entero del 1-10. 
Por último, existe una relación de composición representada por la línea con un rombo relleno que une a la clase Animal y la clase Refugio. Esta es una relación de composición, puesto que el refugio, en este caso, no podría existir sin los animales. De igual manera, es importante recalcar que la clase Refugio contiene como un atributo, el vector animal, el cual será de tipo Animal (clase). 

## Cómo ejecutar el programa
Para poder ejecutar el programa, se deberán ingresar los siguientes textos en la terminal: 
g++ main.cpp -o main
./main
