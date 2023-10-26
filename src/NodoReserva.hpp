
#ifndef NODORESERVA_HPP  // si COLA_HPP no está definido. Si no está definido, entonces el código que sigue (hasta el #endif) se incluirá en el programa.
#define NODORESERVA_HPP // define COLA_HPP. Así que la próxima vez que el preprocesador encuentre #ifndef COLA_HPP, COLA_HPP ya estará definido y el código que sigue no se incluirá en el programa
#include <iostream> // Incluimos la librería iostream para usar Null
using namespace std; // Usamos el espacio de nombres std
#include "reserva.h"

class Nodo
{   
public:
    Nodo(Reserva *x, Nodo *sig = NULL); // Constructor de la clase Nodo  El asterisco (*) indica que sig es un puntero.

    ~Nodo(); // Destructor de la clase Nodo
private:
    Reserva *valor; // Valor del nodo
    Nodo *siguiente; // Puntero al siguiente nodo
    friend class Pila; // Declaramos la clase Cola como amiga de la clase Nodo 
    friend class Cola;
    /*cuando decimos que una clase es "amiga" de otra, significa que la clase amiga tiene acceso a los miembros privados y protegidos de la otra clase.
    Esto significa que la clase Pila puede acceder a los miembros privados y protegidos de la clase Nodo. Esto es útil cuando una clase necesita acceder
    a los miembros de otra clase que normalmente estarían fuera de su alcance, pero aún así quieres mantener la encapsulación de los datos.
    Es importante notar que la relación de amistad en C++ no es bidireccional. Es decir, si la clase A es amiga de la clase B, no significa que la clase B sea amiga de la clase A.
    */
};
typedef Nodo *pnodo; // Definimos pNodo como un puntero a un objeto de tipo Nodo 

#endif // fin de la definición de NODO_HPP



Nodo::Nodo(Reserva *x, Nodo *sig) // Constructor de la clase Nodo  El asterisco (*) indica que sig es un puntero.
{
    valor = x; // El valor del nodo es v
    siguiente = sig; // El siguiente nodo es NULL
}

Nodo::~Nodo() // Destructor de la clase Nodo
{
    
}