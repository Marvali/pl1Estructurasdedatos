#ifndef MESA_H
#define MESA_H
#include <string>
#include <iostream>

using namespace std; // Para no tener que poner std::cout, std::string, std::endl, etc.

class Mesa
{
    private:
    int numeroMesa;
    int capacidad;
    enum lugar{interior, terraza};
    lugar lugar_mesa;
    friend class PilaMesa; // Declaramos la clase PilaMesa como amiga de la clase Mesa
    public:
    Mesa(); // Constructor por defecto
    Mesa(int numeroMesa, int capacidad, lugar lugar_mesa); // Constructor con parámetros
    ~Mesa(); // Destructor
    void mostrar_mesa();
    void generar_mesa();
    
   
    


    // Getters y setters
    void set_lugar_mesa(int x);
    void set_capacidad(int capacidad);
    void set_numeroMesa(int numeroMesa);
    int get_capacidad();
    lugar get_lugar_mesa();

};
 #endif