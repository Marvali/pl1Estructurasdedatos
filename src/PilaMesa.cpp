#ifndef PILAMESA_HPP // si PILAMESA_HPP no está definido. Si no está definido, entonces el código que sigue (hasta el #endif) se incluirá en el programa.
#define PILAMESA_HPP // define PILAMESA_HPP. Así que la próxima vez que el preprocesador encuentre #ifndef PILAMESA_HPP, PILAMESA_HPP ya estará definido y el código que sigue no se incluirá en el programa
#include "NodoMesa.hpp" // Incluimos la clase Nodo
#include <iostream> // Incluimos la librería iostream para usar Null
using namespace std; // Usamos el espacio de nombres std

class PilaMesa
{
public:
    PilaMesa(); // Constructor de la clase PilaMesa
    ~PilaMesa(); // Destructor de la clase PilaMesa
    void insertar(Mesa m); // insetar un elemento en la pila
    Mesa eliminar(); // Elimina un elemento de la pila
    void mostrar(); // Muestra la pila

private:
  pnodoMesa ultimo; // Puntero al último elemento de la pila, la cima

};
#endif // fin de la definición de PILAMESA_HPP


PilaMesa::PilaMesa() // Constructor de la clase PilaMesa  Los dos puntos :: indican que PilaMesa() es un miembro de la clase PilaMesa.
{
    ultimo = NULL; // Inicializamos el puntero ultimo a NULL
}

void PilaMesa::insertar(Mesa y) // insetar un elemento en la pila
{
    pnodoMesa nuevo; // Creamos un puntero a un nodo
    // reservamos memoria para el nodo y guardamos la dirección en el puntero nuevo
    nuevo = new NodoMesa(y,ultimo); // El nuevo nodo apunta al último nodo que había en la pila, v es el valor del nodo
    ultimo = nuevo; // Ahora el último nodo de la pila es el nodo nuevo
}

Mesa PilaMesa::eliminar()
{
    pnodoMesa aux; // Creamos un puntero a un nodo
    pnodoMesa nodo; // Creamos un puntero a un nodo
    Mesa v; // Creamos una variable de tipo Mesa 
    nodo = ultimo; // El puntero nodo apunta al último nodo de la pila
    if(!ultimo) return v; // Si la pila está vacía, retornamos v
    ultimo = nodo->siguiente; // El último nodo de la pila es el nodo siguiente al que apunta nodo, -> es el operador de acceso a miembros de una estructura,
    // es decir, nodo->siguiente es el miembro siguiente de la estructura nodo
    // dentro de la estructura nodo, podemos acceder con operador -> a valor y a siguiente
    v = nodo->valor; // Guardamos el valor del nodo en la variable v
    //acceder al valor mesa->numero
    cout << "eliminando la mesa numero : " << nodo->valor.numeroMesa << endl; // Mostramos el valor extraído
    
    delete nodo; // Borramos el nodo
    return v; // Retornamos el valor del nodo
}

void PilaMesa::mostrar()
{
    pnodoMesa aux; // Creamos un puntero a un nodo
    aux = ultimo; // El puntero aux apunta al último nodo de la pila
    cout << "Listado de todos los elementos de la pilaMesa:\n";
    while(aux) // Mientras que aux no sea NULL
    {
        cout << aux->valor.numeroMesa << endl; // Mostramos el valor del nodo
        cout << aux->valor.capacidad << endl; // Mostramos el valor del nodo
        //si el valor.lugar_mesa es 0 es interior, si es 1 es terraza
        if(aux->valor.lugar_mesa == 0){
            cout << "interior" << endl;
        }else{
            cout << "terraza" << endl;
        }
       
        aux = aux->siguiente; // El puntero aux apunta al nodo siguiente
    }
    cout << endl;
}

PilaMesa::~PilaMesa() // Destructor de la clase PilaMesa
{
    pnodoMesa nodo; // Creamos un puntero a un nodo
    while(ultimo) // Mientras que ultimo no sea NULL
    {
        nodo = ultimo; // El puntero nodo apunta al último nodo de la pila
        ultimo = nodo->siguiente; // El último nodo de la pila es el nodo siguiente al que apunta nodo
        delete nodo; // Borramos el nodo
    }
}