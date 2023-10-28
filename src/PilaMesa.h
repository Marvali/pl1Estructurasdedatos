#ifndef PILAMESA_H // si PILAMESA_HPP no está definido. Si no está definido, entonces el código que sigue (hasta el #endif) se incluirá en el programa.
#define PILAMESA_H // define PILAMESA_HPP. Así que la próxima vez que el preprocesador encuentre #ifndef PILAMESA_HPP, PILAMESA_HPP ya estará definido y el código que sigue no se incluirá en el programa
#include "NodoMesa.hpp" // Incluimos la clase Nodo
#include <iostream> // Incluimos la librería iostream para usar Null
#include "reserva.h"

using namespace std; // Usamos el espacio de nombres std

class PilaMesa
{
public:
    PilaMesa(); // Constructor de la clase PilaMesa
    ~PilaMesa(); // Destructor de la clase PilaMesa
    void insertar(Mesa *m); // insetar un elemento en la pila
    Mesa* eliminar(); // Elimina un elemento de la pila
    void mostrar(); // Muestra la pila
    void recorrer_editar(int personasReserva, Reserva lugar); 
    Mesa* get_ultimo();
private:
  pnodoMesa ultimo; // Puntero al último elemento de la pila, la cima

//getters y setters
    
    
};
#endif // fin de la definición de PILAMESA_HPP
