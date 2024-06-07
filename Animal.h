#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

using namespace std;

class Animal {
protected: //Al ser la clase Animal la clase madre para Perro y Gato, sus atributos deben ser protegidos, de manera que las clases mencionadas anteriormente tengan acceso a dichos atributos. 
    int id;
    string tipo;
    string nombre;
    int edad;
    char sexo;
    string raza;
    string color;

public:
    Animal(int id_, string tipo_, string nombre_, int edad_, char sexo_, string raza_, string color_); //Declaro el constructor del objeto tipo Animal y que contiene todos los atributos que sí son compartidos por perros y gatos
    int getId() { return id; }
    string getTipo() { return tipo; }
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    char getSexo() { return sexo; }
    string getRaza() { return raza; }
    string getColor() { return color; }
    virtual void agradecerDonacion(float donacion) = 0; //Igualo este método a 0, con la intención de declarar esta como mi clase abstracta
    //De igual manera, uso virtual en este método para poder emplear sobreescritura de métodos más adelante
    virtual ~Animal() {} //Esta línea define un destructor virtual, de manera que se destruyan los objetos de tipo Animal (y aquellos creados mediante la herencia que Animal tiene sobre Perro y Gato). 
     
};

Animal::Animal(int id_, string tipo_, string nombre_, int edad_, char sexo_, string raza_, string color_){
    id = id_;
    tipo = tipo_;
    nombre = nombre_;
    edad = edad_;
    sexo = sexo_;
    raza = raza_;
    color = color_;
}

class Perro : public Animal { //Creo la clase Perro, la cual tiene una relación de herencia con la clase madre Animal
private: //Debido a que estos atributos no deberán ser heredados por ninguna otra clase, serán declarados como privados.
    string tamanio;
    bool entrenado;
    string entrenador;

public:
    //En los dos siguientes métodos, veremos dos constructores que lucen casi idénticos, pero el primero será utilizado para los perros que no estén entrenados. De ahí viene que la variable entrenado sea false
    Perro(int id_, string tipo_, string nombre_, int edad_, char sexo_, string raza_, string color_, string tamanio_, bool entrenado_) : Animal(id_, tipo_, nombre_, edad_, sexo_, raza_, color_){
        tamanio = tamanio_;
        entrenado = false;
    }
    //El siguiente constructor nos ayudará a crear objetos de tipo Perro pero que sí estén entrenados. Debido a esto, entrenado será true, y también usaremos otro atributo llamado "entrenador", el cual no tendría sentido que usara si llegara a crear perros no entrenados.
    //La intención al tener dos distintos constructores para perro, es demostrar la competencia que involucra el uso de sobrecarga. 
    Perro(int id_, string tipo_, string nombre_, int edad_, char sexo_, string raza_, string color_, string tamanio_, bool entrenado_, string entrenador_) : Animal(id_, tipo_, nombre_, edad_, sexo_, raza_, color_){
        tamanio = tamanio_;
        entrenado = true;
        entrenador = entrenador_;
    }
    bool getEntrenado() { return entrenado; }
    string getEntrenador() { return entrenador; }
    void agradecerDonacion(float donacion) override{ //Uso override para declarar que aquí habrá sobreescritura de métodos. (INTERFACES)
        cout << "¡Woof! Agradecemos tu donación de $" << donacion << endl;
    }
};

class Gato : public Animal {
private: //Declaro los atributos que pertenecen únicamente a los objetos de tipo Gato. 
    int independencia;

public:
    Gato(int id_, string tipo_, string nombre_, int edad_, char sexo_, string raza_, string color_, int independencia_) : Animal(id_, tipo_, nombre_, edad_, sexo_, raza_, color_){ //Constructor de los objetos de tipo Gato. 
        independencia = independencia_;
    }
    int getIndependencia() { return independencia; }
    void agradecerDonacion(float donacion) override { //Nuevamente, aquí habra sobreescritura de métodos, y aunque el nombre del método y el parámetro sea exactamente igual al contenido en la clase Perro, ambos desplegarán algo diferente. (INTERFACES)
        cout << "¡Miau! Agradecemos tu donación de $"<< donacion << endl; 
    }
};

#endif