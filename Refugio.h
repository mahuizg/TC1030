/**
 * Proyecto Refugio clase Refugio
 * María José Zamora
 * A01704264
 * 14 de junio del 2024
 * Versión 6
 * Esta clase define el objeto de tipo Refugio, y que a su vez, contendrá
 * los métodos necesarios para el funcionamiento del programa, como 
 * eliminarAnimal(indice), registrarAnimal(parámetros), o mostrarAnimales()
 */


#ifndef REFUGIO_H
#define REFUGIO_H
#include "Animal.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Refugio{
public:
    Animal *animales[100]; //Creo un arreglo que contendrá objetos de tipo Animal.
    //Debo establecer un tamaño inicial, por lo le daré una longitud de 100. 
    //De igual manera emplearé apuntadores de tipo animal para usar polimorfismo. 
    int cantidadAnimales; 

public:
    //GETTER
    int getCantidadA(){return cantidadAnimales;}

    /**
     * Este método nos permitirá eliminar un objeto de tipo Animal una vez que 
     * el usuario nos indique el indice del mismo. De igual manera, asignaremos
     * un apuntador nulo para indicar que, tras eliminar el animal de algún 
     * índice, su apuntador ya no apunta a ningún objeto válido. 
     * @param un entero que nos indique el índice del objeto que el usuario querrá 
     * eliminar
     * @return
     */
    void eliminarAnimal(int indice){
        delete animales[indice];
        animales[indice] = nullptr;
    }

    /**
     * Este método nos permitirá registrar objetos dentro de nuestro arreglo 
     * animales[]. Esto sucederá mediante polimorfismo utilizando New. De
     * igual manera, establezco una condición para saber qué constructor utilizar
     * dependiendo del tipo de animal. 
     * @param entero id, string tipo, string nombre, int edad, char sexo, string raza, 
     * string color, string tamanio, bool entrenado, string entrenador, int
     * independencia. 
     * @return
     */
    void registrarAnimal(int id, string tipo, string nombre, int edad, char sexo, 
    string raza, string color, string tamanio, bool entrenado, string entrenador,
    int independencia){ 
        if (tipo == "Perro" && entrenado == true){
            //Si el perro está entrenado, usaremos el constructor que requiere un
            //atributo entrenador
            animales[id] = new Perro(id, tipo, nombre, edad, sexo, raza, color, 
            tamanio, entrenado, entrenador);
            cantidadAnimales = cantidadAnimales + 1;
        }

        else if (tipo == "Perro" && entrenado == false){
            //Si el perro no está entrenado, usraé el constructor que no requiere
            //de un atributo entrenador
            animales[id]= new Perro(id, tipo, nombre, edad, sexo, raza,color,
            tamanio, entrenado);
            cantidadAnimales = cantidadAnimales +1;
        }
             
        else if (tipo == "Gato"){
            //Si el objeto es de tipo Gato, usaré el único constructor que hay
            //para gatos
            animales[id] = new Gato(id, tipo, nombre, edad, sexo, raza, color, 
            independencia);
            cantidadAnimales = cantidadAnimales+1;
        }
    }

    /**
     * Este método me ayudará a imprimir la información de cada uno de mis objetos
     * de tipo animal. Para esto, me apoyaré de un ciclo for que se iterará 100
     * veces, pues este es el límite de mi arreglo animales[]. De igual manera,
     * estableceré una condición para que se impriman todos los índices del
     * arreglo siempre y cuando estos no sean un apuntador nulo. 
     * Dentro de mi if, utilizaré apuntadores para obtener toda la información
     * relevante para perros y gatos respectivamente. 
     * @param
     * @return
     */
    void mostrarAnimales(){
        for (int i =0; i<100; i++){
            if(animales[i]!= nullptr){
                animales[i]-> mostrarInfo();
            }    
        }
    }
};

#endif
