#ifndef REFUGIO_H
#define REFUGIO_H
#include "Animal.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Refugio{
public:
    Animal *animales[1000]; //Creo un arreglo que contendrá objetos de tipo Animal. Debo establecer un tamaño inicial, por lo le daré una longitud de 1000. De igual manera emplearé apuntadores de tipo animal para usar polimorfismo. 

public:
    void eliminarAnimal(int indice){
        delete animales[indice];
        animales[indice] = nullptr; //EL motivo por el cual decidí agregar un apuntador nulo, fue para indicar que, tras eliminar el animal de algún índice, su apuntador ya no apunta a ningún objeto válido. 
    }

    void registrarAnimal(int id, string tipo, string nombre, int edad, char sexo, string raza, string color, string tamanio, bool entrenado, string entrenador, int independencia){ //Establezco todos los parámetros que podrían llegar a usarse para registrar a algún animal, sea este un perro o un gato. 
        if (tipo == "Perro") //Estableceré una condición que me ayudará a diferenciar entre perros y gatos, pues estos no tienen los mismos atributos.
        {
            animales[id] = new Perro(id, tipo, nombre, edad, sexo, raza, color, tamanio, entrenado, entrenador);
        }
        else if (tipo == "Gato")
        {
            animales[id] = new Gato(id, tipo, nombre, edad, sexo, raza, color, independencia);
        }
    }


};

#endif
