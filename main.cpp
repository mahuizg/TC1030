#include "Refugio.h"
#include "Animal.h"
#include <iostream>

using namespace std;

Refugio refugio;

void initAnimales(){ //En las siguientes líneas, crearé mis objetos. A su vez, usaré la funcion .registrarAnimal() para poder ir ingresando cada uno de estos objetos al arreglo que contendrá todos los animale. 
    refugio.registrarAnimal(1, "Perro", "Miguel Bosé", 3, 'M', "Pug", "Beige", "Chico", true, "Jaime", 0);
    refugio.registrarAnimal(2, "Perro", "Pepa", 10, 'H', "Beagle", "Blanco con café", "Mediano", false, "", 0);
    refugio.registrarAnimal(3, "Perro", "Raúl", 9, 'M', "Airedale Terrier", "Café con negro", "Grande", true, "Jimena", 0);
    refugio.registrarAnimal(4, "Gato", "Bernarda", 2, 'H', "Bombay", "Negro", "", false, "", 9);
    refugio.registrarAnimal(5, "Gato", "Pate", 7, 'M', "Siberiano", "Gris", "", false, "", 4);
} //Como podemos ver, aquellos atributos que no aplican para cierto animal, simplemente los dejé vacíos, pero no los dejé fuera del cosntructor

int menu(){
    int opcion;
    bool continua; //Establezco una variable booleana con un valor inciial de true para que el menu se despliegue una y otra vez mientras el usuario no escoga la opción para salir.
    continua = true;
    while (continua == true){ //Las siguientes líneas imprimen los textos necesarios para mi menú inicial
        cout << endl;
        cout << "Bienvenido" << endl;
        cout << "1. Ver animales" << endl;
        cout << "2. Agregar animal" << endl;
        cout << "3. Eliminar animal" << endl;
        cout << "4. Salir" << endl;
        cout << endl;
        cout << "Selecciona una opción: " << endl;
        cin >> opcion; //Solicito una entrada al usuario para poder indicarle al código qué funciones ejecutar.
        if (opcion == 1){ // Si el usuario desea ver los animales, llamaré el método mostrarAnimales() el cual pertenece a la clase Refugio, y cuya lógica see encuentra en el archivo Refugio.h
            refugio.mostrarAnimales();
            break;
        }

        else if (opcion == 2){ //Por el momento, no he programado la lógica detrás de las elecciones 2 y 3, pues considero que, por el momento, me falta un poco del conocimiento que sé que Benji nos dará en próximas clases. 
            continue; //Usé continue únciamente para que el programa no crashee en caso de recibir la opcion 2 o 3
        }

        else if (opcion == 3){
            continue;
        }

        else if (opcion == 4){ //Esta condicional se despide del usuario y finalmente rompe el ciclo que hacía que el menú se desplegará hasta qeu el usuario solicitara salir. 
            cout << endl;
            cout << "Hasta luego" << endl;
            cout << endl;
            continua = false; //Establecemos la variable continua como falsa para salir del ciclo
        }

        else{ //Esta última condición la escribí en caso de que el usuario escriba cualquier otra opción que no esté contenida en el menú. 
            cout << "Por favor, selecciona una opción válida" << endl;
        }
    }
    return 0;
}

int main(){ //Dentro de mi función main, llamo a la función que me ayudará a inicializar todos los objetos de tipo Animal. De igual manera, llamo a la función que desplega el menú. 
    initAnimales();
    menu();
    return 0;
}