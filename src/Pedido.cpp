#include "Pedido.h"

Pedido::Pedido() // Constructor por defecto
{
    numeroMesa = 0;
    nombreCliente = "";
    numeroPersonas = 0;
    menu_reserva = completo;
    lugar_reserva = interior;
    estado = false;
}

Pedido::Pedido(int n, string nc, int np, menu m, lugar l, bool e) // Constructor con parámetros
{
    numeroMesa = n;
    nombreCliente = nc;
    numeroPersonas = np;
    menu_reserva = m;
    lugar_reserva = l;
    estado = e;
}

Pedido::~Pedido() // Destructor
{
    cout << "Se ha borrado el pedido de " << nombreCliente << endl;
}

Pedido Pedido::generar_pedido(Mesa *mesa, Reserva *reserva)
{
   
    numeroMesa = mesa->get_numeroMesa();
    nombreCliente = reserva->get_nombre();
    numeroPersonas = reserva->get_personas();
    if (reserva->get_menu() == 0)
        menu_reserva = vegano;
    else if (reserva->get_menu() == 1)
        menu_reserva = sin_gluten;
    else
        menu_reserva = completo;
    if (reserva->get_lugar() == 0)
        lugar_reserva = interior;
    else
        lugar_reserva = terraza;

    
    estado = false;
    return *this;
}