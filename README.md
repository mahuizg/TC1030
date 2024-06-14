# TC1030
## Objetivo
El objetivo del programa que crearé durante las cinco semanas que corresponden a TC1030, es proveer un registro de los animales que se encuentran en un refugio. El usuario podrá dar de alta animales que lleguen al refugio, y también podrá dar de baja a los animales que sean adoptados. De igual manera, este programa facilitará la visualización de todos los animales que se encuentren en el refugio, junto con información relevante sobre el animal, como su nombre, edad, sexo, color, raza, etc. 

El objetivo es que, al ejecutar el programa, se despliegue un menú en el que el usuario pueda seleccionar entre registrar un animal, dar de baja a un animal, o desplegar la información de los animales.

## Nota de las actualizaciones
Al inicio del semestre, no sabía que debíamos actualizar los archivos en lugar de eliminar, y volver a subirlos cada que hiciéramos cambios, por lo que en las primeras entregas, habrán muchos "Delete [nombredelarchivo]". No obstante, en cuanto supe que era importante actualizar, dejé de eliminar los archivos, y para las últimas entregas, ya podremos ver "Update [nombredelarchivo]". 

## Casos en los que el programa dejaría de funcionar
Debido a que la intención es poder implementar un menú con distintas opciones para que el usuario seleccione, el programa deberá recibir una entrada. El programa fallará si el usuario intenta ingresar una cadena de texto, pues las opciones disponibles serán únicamente números enteros. 
De igual manera, si el programa está esperando una entrada de cierto datatype, pero el usuario ingresa otro, el programa no funcionará. 
Finalmente, es importante considerar también que, el programa recomienda al usuario el número de ID a utilizar, de manera que se evite la sobreescritura de algún objeto en el arreglo animales[], y aunque esto no significa que el programa deje de correr, es importante que el usuario tenga esto en consideración. 

## Diagrama UML
Para el desarrollo de este proyecto, fue necesario iniciar con el diseño de un Diagrama UML. Mi diagrama consiste de una clase madre llamada Animal, la cual contiene todos los atributos que heredarán las clases de Perro y Gato (las cuales están unidas a dicha clase madre con una línea que termina en flecha), al igual que los métodos pertenecientes a la clase. Análogamente, tanto la clase Perro como la clase Gato poseen distintos atributos, pues son características que no comparten entre ellos: para el perro, necesitaremos saber el tamaño, si este está entrenado, y el nombre de su entrenador; ,mientras que para el gato, tendremos un atributo de independencia, el cual será un número entero del 1-10. 
Por último, existe una relación de composición representada por la línea con un rombo relleno que une a la clase Animal y la clase Refugio. Esta es una relación de composición, puesto que el refugio, en este caso, no podría existir sin los animales. De igual manera, es importante recalcar que la clase Refugio contiene como un atributo, el arreglo animales[], el cual será de tipo Animal (clase). 

## Cómo ejecutar el programa
Para poder ejecutar el programa, se deberán ingresar los siguientes textos en la terminal: 

g++ main.cpp -o main

./main

## Referencias
1. Ravikiran, A. S. (2023). _An Introduction to C++ Getline with Syntax And Examples_. Simplilearn. Recuperado el 12 de junio del 2024, de: https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-getline#:~:text=Example%3A%20Using%20cin%20Object&text=That's%20because%20the%20compiler%20stopped,to%20use%20the%20getline%20function.
2. Team Gyata. (2024). _Destructor C++_. GYATA AI. Recuperado el 13 de junio del 2024, de: https://www.gyata.ai/es/c-plus-plus/c-destructor/

