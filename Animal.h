/**
 * Proyecto Refugio clase Animal
 * María José Zamora
 * A01704264
 * 14 de junio del 2024
 * Versión 5
 * Esta clase define los objetos de tipo Animal. Las clases hijas serán Gato y Perro,
 * las cuales heredarán los atributos de la clase madre. 
 */

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

using namespace std;

class Animal {
protected: 
//Declaro los atributos con modificador de acceso "protected", pues estos atributos
//serán heredados por las subclases.  
    int id;
    string tipo;
    string nombre;
    int edad;
    char sexo;
    string raza;
    string color;

public:
    Animal(int id_, string tipo_, string nombre_, int edad_, char sexo_,
    string raza_, string color_); //Constructor de los objetos tipo Animal
    virtual ~Animal(){};//Destructor para evitar warnings ligados a eliminarAnimal(indice)
    virtual void mostrarInfo() = 0; //Método abstracto que se sobreescribirá
};

Animal::Animal(int id_, string tipo_, string nombre_, int edad_, char sexo_,
string raza_, string color_){
    id = id_;
    tipo = tipo_;
    nombre = nombre_;
    edad = edad_;
    sexo = sexo_;
    raza = raza_;
    color = color_;
}

class Perro : public Animal { 
//Creo la clase Perro que tiene una relación de herencia con la clase madre 
private: //Privados pues no serán heredados por otra subclase
    string tamanio;
    bool entrenado;
    string entrenador;

public:
    /**En los dos siguientes métodos veremos dos constructores que lucen
     * casi idénticos, pero el primero será utilizado para los perros que
     * no estén entrenados. De ahi viene que la variable entrenado sea false
     */
    Perro(int id_, string tipo_, string nombre_, int edad_, char sexo_, 
    string raza_, string color_, string tamanio_, bool entrenado_) :
    Animal(id_, tipo_, nombre_, edad_, sexo_, raza_, color_){
        tamanio = tamanio_;
        entrenado = false;
    }

    /**El siguiente constructor nos ayudará a crear objetos de tipo Perro
     * pero que sí estén entrenados. Debido a esto, entrenado será true, y 
     * también usaremos otro atributo llamado "entrenador". La intención al 
     * tener dos distintos constructores para perro, es demostrar la
     * competencia que involucra el uso de sobrecarga
     */
    Perro(int id_, string tipo_, string nombre_, int edad_, char sexo_, 
    string raza_, string color_, string tamanio_, bool entrenado_, 
    string entrenador_) : Animal(id_, tipo_, nombre_, edad_, sexo_, 
    raza_, color_){
        tamanio = tamanio_;
        entrenado = true;
        entrenador = entrenador_;
    }

    /** La siguiente función involucrará sobreescritura.
     * El objetivo de este método es imprimir todos los atributos de los
     * objetos de tipo Perro.
     * En este caso, no hay necesidad de usar getters, pues estoy accediendo
     * a los atributos dentro de la clase Perro, entonces basta con escribir
     * cout << "Atributo: " << atributo << endl; 
     * De igual manera, habrá una condición que debe cumplirse para que
     * también se imprima el atributo de entrenador. 
     * @param
     * @return
     */
    void mostrarInfo(){
        cout << endl; 
        cout << "ID: " << id << endl;
        cout << "Tipo: " << tipo<< endl;
        cout << "Nombre: " << nombre << endl; 
        cout << "Edad: " << edad << endl; 
        cout << "Sexo: " << sexo << endl; 
        cout << "Raza: " << raza << endl; 
        cout << "Color: " << color << endl; 
        cout << "Tamaño: " << tamanio << endl; 
        cout << "Entrenado: " << entrenado << endl; 
        if (entrenado == true){
            cout << "Entrenador/a: " << entrenador << endl;
        }
    }
};

class Gato : public Animal {
private: 
//Declaro los atributos que pertenecen únicamente a los objetos de tipo Gato. 
    int independencia;

public:
    /**El siguiente, será el constructor que utilizaré para crear objetos de
     * tipo Gato y que utilizará diferentes atributos al constructor de Perro
     */
    Gato(int id_, string tipo_, string nombre_, int edad_, char sexo_, 
    string raza_, string color_, int independencia_) : Animal(id_, 
    tipo_, nombre_, edad_, sexo_, raza_, color_){ 
        independencia = independencia_;
    }
    /**Nuevamente, este método nos servirá para imprimir la información de
     * cada uno de los objetos de tipo Gato. Aunque tengan el mismo nombre, 
     * este mostrarInfo() es distinto al que fue implementado en la clase
     * Perro, pues como cuentan con diferentes atributos, también imprimiremos
     * cosas diferentes. 
     * @param
     * @return
     */
    void mostrarInfo(){
        cout << endl; 
        cout << "ID: " << id << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Nombre: " << nombre << endl; 
        cout << "Edad: " << edad << endl; 
        cout << "Sexo: " << sexo << endl; 
        cout << "Raza: " << raza << endl; 
        cout << "Color: " << color << endl; 
        cout << "Independencia (1-10): " << independencia << endl;       
    }
};

#endif

