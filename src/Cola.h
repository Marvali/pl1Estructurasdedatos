#ifndef COLA_H
#define COLA_H
#include "reserva.h"
#include "NodoReserva.hpp"

class Cola
{
public:
    Cola(); // Constructor de la clase Cola
    ~Cola(); // Destructor de la clase Cola
    void insetar(Reserva *r); // insetar un elemento en la cola
    Reserva* eliminar(); // Elimina un elemento de la cola
    void mostrar(); // Muestra la cola
    Reserva* get_primero();
private:

    pnodo primero; // Puntero al primer elemento de la cola
    pnodo ultimo; // Puntero al último elemento de la cola
};
#endif // fin de la definición de COLA_HPP