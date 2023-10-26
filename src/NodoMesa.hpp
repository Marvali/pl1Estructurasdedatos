#ifndef NODOMESA_HPP // si COLA_HPP no está definido. Si no está definido, entonces el código que sigue (hasta el #endif) se incluirá en el programa.
#define NODOMESA_HPP // define COLA_HPP. Así que la próxima vez que el preprocesador encuentre #ifndef COLA_HPP, COLA_HPP ya estará definido y el código que sigue no se incluirá en el programa
#include <iostream> // Incluimos la librería iostream para usar Null
using namespace std; // Usamos el espacio de nombres std
#include "mesa.h"


class NodoMesa
{
public:
    NodoMesa(Mesa *x, NodoMesa *sig = NULL); // Constructor de la clase Nodo  El asterisco (*) indica que sig es un puntero.

    ~NodoMesa(); // Destructor de la clase Nodo
private:
    Mesa *valor; // Valor del nodo
    NodoMesa *siguiente; // Puntero al siguiente nodo
    friend class Pila; // Declaramos la clase Cola como amiga de la clase Nodo 
    friend class Cola;
    friend class PilaMesa;
    /*cuando decimos que una clase es "amiga" de otra, significa que la clase amiga tiene acceso a los miembros privados y protegidos de la otra clase.
    Esto significa que la clase Pila puede acceder a los miembros privados y protegidos de la clase Nodo. Esto es útil cuando una clase necesita acceder
    a los miembros de otra clase que normalmente estarían fuera de su alcance, pero aún así quieres mantener la encapsulación de los datos.
    Es importante notar que la relación de amistad en C++ no es bidireccional. Es decir, si la clase A es amiga de la clase B, no significa que la clase B sea amiga de la clase A.
    */
};

typedef NodoMesa *pnodoMesa; // Definimos pNodo como un puntero a un objeto de tipo Nodo

#endif // fin de la definición de NODO_HPP

NodoMesa::NodoMesa(Mesa *x, NodoMesa *sig) // Constructor de la clase Nodo  El asterisco (*) indica que sig es un puntero.
{
    valor = x; // El valor del nodo es v
    siguiente = sig; // El siguiente nodo es NULL
}

NodoMesa::~NodoMesa() // Destructor de la clase Nodo
{
    
}

