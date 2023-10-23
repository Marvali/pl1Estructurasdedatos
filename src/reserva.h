#ifndef RESERVA_H
#define RESERVA_H
#include <string>
#include <iostream>
using namespace std; // Para no tener que poner std::cout, std::string, std::endl, etc.

class reserva
{
private:
    string nombre;
    int mesa;
    enum lugar{interior, terraza};
    int personas;
    enum hora{trece, catorce, quince};
    enum menu{vegano, sin_gluten, completo};
    lugar lugar_reserva;
    hora hora_reserva;
    menu menu_reserva;
public:
    reserva(string nombre, int mesa, int personas, lugar lugar_reserva, hora hora_reserva, menu menu_reserva);
    string get_nombre();
    int get_mesa();
    int get_personas();
    lugar get_lugar();
    hora get_hora();
    menu get_menu();
    void set_nombre(string nombre);
    void set_mesa(int mesa);
    void set_personas(int personas);
    void set_lugar(lugar lugar_reserva);
    void set_hora(hora hora_reserva);
    void set_menu(menu menu_reserva);
    void mostrar_reserva();
};
#endif