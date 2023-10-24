#ifndef RESERVA_H // si RESERVA_H no está definido. Si no está definido, entonces el código que sigue (hasta el #endif) se incluirá en el programa.
#define RESERVA_H
#include <string>
#include <iostream>
using namespace std; // Para no tener que poner std::cout, std::string, std::endl, etc.

class Reserva
{
private:
    string nombre;
    enum lugar{interior, terraza};
    int personas;
    enum hora{trece, catorce, quince};
    enum menu{vegano, sin_gluten, completo};
    lugar lugar_reserva;
    hora hora_reserva;
    menu menu_reserva;
    friend class Cola; // Declaramos la clase Cola como amiga de la clase Reserva
public:
    Reserva(); // Constructor por defecto
    Reserva(string nombre, int mesa, int personas, lugar lugar_reserva, hora hora_reserva, menu menu_reserva); // Constructor con parámetros
    ~Reserva(); // Destructor

// Métodos escribir,mostrar y reserva_generar
    void escribir_reserva();
    void mostrar_reserva();
    void reserva_generar();
    
    
// Getters y setters
    string get_nombre();
    int get_personas();
    lugar get_lugar();
    hora get_hora();
    menu get_menu();
    void set_nombre(string nombre);
    void set_personas(int personas);
    void set_lugar(lugar lugar_reserva);
    void set_hora(hora hora_reserva);
    void set_menu(menu menu_reserva);
    
};
#endif