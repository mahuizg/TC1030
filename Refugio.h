#ifndef REFUGIO_H
#define REFUGIO_H
#include "Animal.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Refugio{
private:
    Animal *animales[1000]; //Creo un arreglo que contendrá objetos de tipo Animal. Debo establecer un tamaño inicial, por lo le daré una longitud de 1000. 

public:
    void registrarAnimal(int num, string tipo, string nombre, int edad, char sexo, string raza, string color, string tamano, bool entrenado, string entrenador, int independencia) //Establezco todos los parámetros que podrían llegar a usarse para registrar a algún animal, sea este un perro o un gato. 
    {
        if (tipo == "Perro") //Estableceré una condición que me ayudará a diferenciar entre perros y gatos, pues estos no tienen los mismos atributos.
        {
            animales[num] = new Perro(num, tipo, nombre, edad, sexo, raza, color, tamano, entrenado, entrenador);
        }
        else if (tipo == "Gato")
        {
            animales[num] = new Gato(num, tipo, nombre, edad, sexo, raza, color, independencia);
        }
    }

    void mostrarAnimales()
    {

        for (int i = 1; i < 6; i++) //Por el momento, con el propósito de poder correr mi código, este ciclo for se iterará 5 vecs únciamente. Sin embargo, una vez que se implementen los métodos necesarios para registrar o dar de baja animales, este ciclo cambiará. 
        { //Utilizo apuntadores para obtener cada uno de los atributos de cualquier animal, pues con la función mostrarAnimales(), busco imprimir toda esta información para cada uno de ellos.
            cout << endl;
            cout << "Número de ID: " << animales[i]->getId() << endl;
            cout << "Tipo de animal: " << animales[i]->getTipo() << endl;
            cout << "Edad: " << animales[i]->getEdad() << endl;
            cout << "Sexo: " << animales[i]->getSexo() << endl;
            cout << "Raza: " << animales[i]->getRaza() << endl;
            cout << "Color: " << animales[i]->getColor() << endl;

            if (Perro *perro = dynamic_cast<Perro *>(animales[i])) //Si el puntero en esta línea apunta a un objeto tipo Perro, la condición será verdadera, y ejecutará las siguientes líneas de código. 
            {
                cout << "Entrenado: " << perro->getEntrenado() << endl; //Entrenado es un atributo que declaré como propio de un perro, pero no de un gato
                if (perro->getEntrenado() == true) //De igual manera, establezco una condición, para que, si el perro sí está entrenado, entonces también se imprima el nombre del entrenador. En caso de no estar entrenado, este último cout no se ejecutará- 
                {
                    cout << "Entrenador: " << perro->getEntrenado() << endl;
                }
            }
            else if (Gato *gato = dynamic_cast<Gato *>(animales[i])) //Esta línea de código funciona similar a la de la línea 40. Si nuestro apuntador nos lleva a un objeto de clase Gato, la siguientes línea de código se ejecutará, la cual contiene un atributo propio únicamente de los gatos. 
            {
                cout << "Nivel de Independencia (1-10): " << gato->getIndependencia() << endl;
            }

        }
    }
};

#endif