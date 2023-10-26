#ifndef NODOPEDIDO_HPP
#define NODOPEDIDO_HPP
#include <iostream>
using namespace std;
#include "pedido.h"

class NodoPedido{
private:
    Pedido valor;
    NodoPedido *siguiente;
    friend class Cola;
    friend class cpedido;
public:
    NodoPedido(Pedido x, NodoPedido *sig = NULL);
    ~NodoPedido();
};

typedef NodoPedido *pnodoPedido;

#endif

//Constructor de la clase nodo
NodoPedido::NodoPedido(Pedido x, NodoPedido *sig){
    valor = x;
    siguiente = sig;
}

//Destructor de la clase nodo
NodoPedido::~NodoPedido(){
}
