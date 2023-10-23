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

    public:
    Mesa(); // Constructor por defecto
    Mesa(int numeroMesa, int capacidad, lugar lugar_mesa); // Constructor con parámetros
    ~Mesa(); // Destructor

};