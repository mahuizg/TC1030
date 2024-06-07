//TEMAS A RESOLVER: 
// 1 - Cuando imprimo los animales, donde dice "Entrenado: " ahora regresa un 1 esté el perro entrenado o no
// 2 - ¿Por qué se está imprimiendo "Entrenador: " incluso cuando el perro no está etrenado. Creo que esto tiene que ver con el error 1. 
// 3 - Tengo que seguir haciendo modificaciones en registrarAnimal()
// 4 - Si bien sí se elimina el animal que se encuentre en el índice que indique, también se dejan de imprimir todos los animales cuyo índice este después del índice del animal eliminado. 

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
        cout << "4. Realizar una donación" << endl; 
        cout << "5. Salir" << endl;
        cout << endl;
        cout << "Selecciona una opción: " << endl;
        cin >> opcion; //Solicito una entrada al usuario para poder indicarle al código qué funciones ejecutar.
        if (opcion == 1){ // Si el usuario desea ver los animales, llamaré el método mostrarAnimales() el cual pertenece a la clase Refugio, y cuya lógica see encuentra en el archivo Refugio.h
            refugio.mostrarAnimales();
        }

        else if (opcion == 2){ 
            cout << "¿Cuál es el número de ID del animal que quieres dar de alta?: " << endl;
            int id; 
            cin >> id;
            cout << endl; 
            cout << "¿Qué tipo de animal es? Escribe el tipo de animal con la primera letra mayúscula únicamente y sin espacios al final: ";
            string tipo; 
            cin >> tipo; 
            cout << endl; 
            cout << "¿Cuál es el nombre del animal?: " << endl; 
            string nombre; 
            cin >> nombre;
            cout << endl; 
            cout << "¿Cuántos años tiene el animal?: " << endl; 
            int edad; 
            cin >> edad; 
            cout << endl; 
            cout << "¿Cuál es su sexo? Asegúrate de ingresar únicamente un caracter (H para hembra, M para macho): " << endl;
            char sexo; 
            cin >> sexo; 
            cout << endl; 
            cout << "¿Cuál es la raza del animal?: " << endl;
            string raza; 
            cin >> raza; 
            cout << endl;
            cout << "¿Cuál es el color del animal?: " << endl; 
            string color; 
            cin >> color; 
            cout << endl;
            cout << "Si el animal es un gato, simplemente ingresa NA" << endl; 
            cout << "Si el animal es un perro, ¿su tamaño es chico, mediano, o grande? Recuerda ingresar tu respuesta en una sola palabra sin espacios y con la primera letra en mayúsculas: "<< endl;
            string tamanio; 
            cin >> tamanio; 
            cout << endl;
            cout << "Si el animal es un gato, ingrese 0" << endl; 
            cout << "Si el animal es un perro, ¿está entrenado? Escribe 0 si no lo está, o 1 en el caso contrario: " << endl; 
            int entrada; 
            cin >> entrada;
            bool entrenado;
            if (entrada == 0){
                entrenado = false;
            }
            else if (entrada == 1){
                entrenado = true;
            }
            cout << endl; 
            cout << "Si el animal es un gato, ingrese NA" << endl;
            cout << "Si el animal es un perro que no esté entrenado, ingresa NA. Si el perro sí está entrenado, ¿cuál es el nombre de su entrenador/a?: " << endl;
            string entrenador;
            cin >> entrenador; 
            cout << endl; 
            cout << "Si el animal es un perro, ingresa 0" << endl; 
            cout << "Si el animal es un gato, ¿cuál es su nivel de independencia en una escala del 1-10?: " << endl; 
            int independencia; 
            cin >> independencia; 

            refugio.registrarAnimal(id, tipo, nombre, edad, sexo, raza, color, tamanio, entrenado, entrenador, independencia);
        }

        else if (opcion == 3){
            cout << "¿Cuál es el id del animal que quieres eliminar?: "<< endl; 
            int indice;
            cin >> indice; 
            refugio.eliminarAnimal(indice);
        }
        
        else if (opcion == 4){
            int animalDonacion;
            cout << "¿Para qué animales deseas hacer la donación?" << endl; 
            cout << "1. Perros" << endl; 
            cout << "2. Gatos" << endl; 
            cin >> animalDonacion;
            float donacion;
            cout << "Ingresa el monto que desees donar: " << endl; 
            cin >> donacion; 
            int contador; 
            contador = 0;
            int condicion;  
            condicion = 0;
            continue; //Tengo que arreglar las siguientes líneas de código, pero aquí llamare a los métodos que fueron heredados y sobreescritos de la clase abstracta.  (INTERFACES)
            //if(animalDonacion == 1){
                //while (condicion == 0){
                    //if (Perro *perro = dynamic_cast<Perro *>(animales[contador])) {//Si el puntero en esta línea apunta a un objeto tipo Perro, la condición será verdadera, y ejecutará las siguientes líneas de código. 
                        //animales[contador]->agradecerDonacion(donacion); 
                        //contador = contador + 1; 
                        //condicion = 1;
                    //}
                    //else{
                       // contador = contador + 1;
                    //}
                //}
            //}

            //else if (animalDonacion == 2){ 
                //while (condicion == 0){
                    //if (Gato *gato = dynamic_cast<Gato *>(animales[contador])) {//Si el puntero en esta línea apunta a un objeto tipo Gato, la condición será verdadera, y ejecutará las siguientes líneas de código. 
                        //animales[contador]->agradecerDonacion(donacion); 
                        //contador = contador + 1; 
                        //condicion = 1;
                //}
                //else{
                    //contador = contador + 1;
                //}
            //}
        }

        else if (opcion == 5){ //Esta condicional se despide del usuario y finalmente rompe el ciclo que hacía que el menú se desplegará hasta qeu el usuario solicitara salir. 
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
};

int main(){ //Dentro de mi función main, llamo a la función que me ayudará a inicializar todos los objetos de tipo Animal. De igual manera, llamo a la función que desplega el menú. 
    initAnimales();
    menu();
    return 0;
}