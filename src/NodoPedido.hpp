#ifndef NODOPEDIDO_HPP // si NODOPEDIDO_HPP no está definido. Si no está definido, entonces el código que sigue (hasta el #endif) se incluirá en el programa.
#define NODOPEDIDO_HPP
#include <iostream> 
using namespace std;
#include "Pedido.h"


class NodoPedido
{
public:
    NodoPedido(Pedido *x, NodoPedido *sig = NULL); // Constructor de la clase Nodo  El asterisco (*) indica que sig es un puntero.

    ~NodoPedido(); // Destructor de la clase Nodo
private:

    Pedido *valor; // Valor del nodo
    NodoPedido *siguiente; // Puntero al siguiente nodo
    friend class ColaPedido; // Declaramos la clase Cola como amiga de la clase Nodo
    /*cuando decimos que una clase es "amiga" de otra, significa que la clase amiga tiene acceso a los miembros privados y protegidos de la otra clase.
    Esto significa que la clase Pila puede acceder a los miembros privados y protegidos de la clase Nodo. Esto es útil cuando una clase necesita acceder
    a los miembros de otra clase que normalmente estarían fuera de su alcance, pero aún así quieres mantener la encapsulación de los datos.
    Es importante notar que la relación de amistad en C++ no es bidireccional. Es decir, si la clase A es amiga de la clase B, no significa que la clase B sea amiga de la clase A.
    */
};

typedef NodoPedido *pnodoPedido; // Definimos pNodo como un puntero a un objeto de tipo Nodo

#endif // fin de la definición de NODO_HPP


NodoPedido::NodoPedido(Pedido *x, NodoPedido *sig) // Constructor de la clase Nodo  El asterisco (*) indica que sig es un puntero.
{
    valor = x; // El valor del nodo es v
    siguiente = sig; // El siguiente nodo es NULL
}

NodoPedido::~NodoPedido() // Destructor de la clase Nodo
{
    
}