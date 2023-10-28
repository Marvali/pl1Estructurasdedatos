#ifndef COLAPEDIDO_H
#define COLAPEDIDO_H
#include "Pedido.h"
#include "NodoPedido.hpp"

class ColaPedido
{
public:
    ColaPedido(); // Constructor de la clase Cola
    ~ColaPedido(); // Destructor de la clase Cola
    void insetar(Pedido *p); // insetar un elemento en la cola
    Pedido* eliminar(); // Elimina un elemento de la cola
    void mostrar(); // Muestra la cola
    Pedido* get_primero();
private:
    
        pnodoPedido primero; // Puntero al primer elemento de la cola
        pnodoPedido ultimo; // Puntero al último elemento de la cola
    };

#endif 