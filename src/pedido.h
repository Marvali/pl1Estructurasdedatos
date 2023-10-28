#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <string>
#include <iostream>
#include "Mesa.h"
#include "Reserva.h"

using namespace std;

class Pedido
{
    private:
    int numeroMesa;
    string nombreCliente;
    int numeroPersonas;
    enum menu{vegano, sin_gluten, completo};
    menu menu_reserva;
    enum lugar{interior, terraza};
    lugar lugar_reserva;
    bool estado;
    friend class ColaPedido;

    public:
    Pedido();
    Pedido(int numeroMesa, string nombreCliente, int numeroPersonas, menu menu_reserva, lugar lugar_reserva, bool estado);
    ~Pedido();
    

    Pedido generar_pedido(Mesa *mesa, Reserva *reserva);

    // Getters y setters
    int get_numeroMesa();
    string get_nombreCliente();
    int get_numeroPersonas();
    menu get_menu();
    lugar get_lugar();
    bool get_estado();
    void set_numeroMesa(int numeroMesa);
    void set_nombreCliente(string nombreCliente);
    void set_numeroPersonas(int numeroPersonas);
    void set_menu(menu menu_reserva);
    void set_lugar(lugar lugar_reserva);
    void set_estado(bool estado);
};

#endif
