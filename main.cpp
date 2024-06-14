/**
 * Proyecto Refugio main
 * María José Zamora
 * A01704264
 * 14 de junio del 2024
 * Versión 5
 * Este es un programa pensado para usarse en refugios de animales. El ob-
 * jetivo es permitir al usuario observar la lista de animales que se 
 * encuentran en el refugio, al igual que registrar más animales, o dar de
 * baja a otros que hayan sido adoptados. 
 */

#include "Refugio.h"
#include "Animal.h"
#include <iostream>

using namespace std;

Refugio refugio; //Creo mi objeto de tipo refugio para acceder a sus métodos

/**
 * Esta función crea objetos de tipo Animal. A su vez, usaré el método
 * registrarAnimal() para ingresarlos al arreglo animales[]. 
 * @param 
 * @return
 */
void initAnimales(){
    refugio.registrarAnimal(1, "Perro", "Miguel Bosé", 3, 'M', "Pug", "Beige", 
    "Chico", true, "Jaime", 0);
    refugio.registrarAnimal(2, "Perro", "Pepa", 10, 'H', "Beagle","Blanco con café",
    "Mediano", false, "", 0);
    refugio.registrarAnimal(3, "Perro", "Raúl", 9, 'M', "Airedale Terrier", 
    "Café con negro", "Grande", true, "Jimena", 0);
    refugio.registrarAnimal(4, "Gato", "Bernarda", 2, 'H', "Bombay", "Negro", "",
    false, "", 9);
    refugio.registrarAnimal(5, "Gato", "Pate", 7, 'M', "Siberiano", "Gris", "", 
    false, "", 4);
}

/**
 * Esta función desplegará el menú principal que permitirá al usuario decidir qué
 * hacer dentro del programa. Solicitaré una elección, y dependiendo de esta, 
 * indicaré al programa qué ejecutar. 
 * @param
 * @return un 0
 */
void menu(){
    int opcion;
    bool continua; 
    //Establezco una variable con un valor de true para desplegar el menú en loop.
    //Este ciclo se romperá hasta que el usuario decida salir
    continua = true;
    while (continua == true){
        cout << endl;
        cout << "Bienvenido" << endl;
        cout << "1. Ver animales" << endl;
        cout << "2. Agregar animal" << endl;
        cout << "3. Eliminar animal" << endl;
        cout << "4. Salir" << endl;
        cout << endl;
        cout << "Selecciona una opción: " << endl;
        cin >> opcion;

        if (opcion == 1){
            refugio.mostrarAnimales();
        }

        else if (opcion == 2){ 
            cout << endl; 
            cout << "¿Cuál es el número de ID del animal?: " << endl;
            //La siguiente línea recomienda un ID en base a la cantidad de 
            //animales que estén/hayan estado registrados en el refugio.
            //La intención es que el usuario sepa que ID usar para evitar
            //sobreescribir animales con el mismo ID, y también para que
            //no se pueda repetir el uso de ningún ID que haya sido 
            //asignado anteriormente.
            cout << "ID recomendado: " << refugio.getCantidadA() + 1 << endl; 
            int id; 
            cin >> id;
            cin.ignore();
            cout << endl; 
            cout << "¿Qué tipo de animal es?"<< endl;
            cout << "Escribe la primera letra en mayúscula: "<< endl;
            string tipo; 
            cin >> tipo; 
            cin.ignore();
            cout << endl; 
            cout << "¿Cuál es el nombre del animal?: " << endl; 
            string nombre; 
            getline(cin, nombre);
            cout << endl; 
            cout << "¿Cuántos años tiene el animal?: " << endl; 
            int edad; 
            cin >> edad; 
            cin.ignore();
            cout << endl; 
            cout << "¿Cuál es su sexo? Ingresa únicamente un caracter" << endl;
            cout << "H para hembra, M para macho: " << endl;
            char sexo; 
            cin >> sexo; 
            cin.ignore();
            cout << endl; 
            cout << "¿Cuál es la raza del animal?: " << endl;
            string raza; 
            getline(cin, raza);
            cout << endl;
            cout << "¿Cuál es el color del animal?: " << endl; 
            string color; 
            getline(cin, color);
            cout << endl;
            cout << "Si el animal es un gato, ingresa NA" << endl; 
            cout << "¿El tamaño del perro es chico, mediano, o grande?" << endl;
            cout << "Escribe la primera letra en mayúsculas "<< endl;
            string tamanio; 
            cin >> tamanio; 
            cin.ignore();
            cout << endl;
            cout << "Si el animal es un gato, ingrese 0" << endl; 
            cout << "¿El perro está entrenado?" << endl; 
            cout << "Escribe 0 si no, o 1 en el caso contrario: " << endl; 
            int entrada; 
            cin >> entrada;
            cin.ignore();
            bool entrenado;
            if (entrada == 0){ //Utilizo ifs para establecer mis valores booleanos
                entrenado = false;
            }
            else if (entrada == 1){
                entrenado = true;
            }
            cout << endl; 
            cout << "Si el animal es un gato, ingrese NA" << endl;
            cout << "Si el perro no está entrenado, ingresa NA." << endl;
            cout << "Si el perro está entrenado, ¿quién lo entrenó?" << endl; 
            string entrenador;
            getline(cin, entrenador);
            cout << endl; 
            cout << "Si el animal es un perro, ingresa 0" << endl; 
            cout << "¿Cuál es el nivel de independencia del gato (1-10)?: " << endl; 
            int independencia; 
            cin >> independencia; 
            cin.ignore();
            //Una vez que terminé de recopilar los atributos del animal, ahora accedo al 
            //método registrarAnimal()
            refugio.registrarAnimal(id, tipo, nombre, edad, sexo, raza, color,
            tamanio, entrenado, entrenador, independencia);
        }

        else if (opcion == 3){
            cout << "¿Cuál es el id del animal que quieres eliminar?: "<< endl; 
            //Solicito un índice para saber qué posición del arreglo eliminar
            int indice;
            cin >> indice; 
            refugio.eliminarAnimal(indice);
        }
        
        else if (opcion == 4){
            //Esta condicional rompe el ciclo que hacía que el menú se 
            //desplegará hasta qeu el usuario solicitara salir.  
            cout << endl;
            cout << "Hasta luego" << endl;
            cout << endl;
            continua = false; 
            //Establecemos la variable como falsa para salir del ciclo
        }

        else{ 
            //Esta última condición la escribí en caso de que el usuario escriba
            //cualquier otra opción que no esté contenida en el menú. 
            cout << "Por favor, selecciona una opción válida" << endl;
        }
    }
};

/**
 * Este es mi main. Llamaré a la función initAnimales() que crea todos los objetos
 * de tipo Animal. 
 * De igual manera llamo a la función que desplegará el menú principal
 * @param
 * @return un 0
 */
int main(){
    initAnimales();
    menu();
    return 0;
}

