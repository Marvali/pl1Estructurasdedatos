#include "cola.h"

Cola::Cola() // Constructor de la clase Cola  Los dos puntos :: indican que Cola() es un miembro de la clase Cola.
{
    primero = NULL; // Inicializamos el puntero primero a NULL
    ultimo = NULL; // Inicializamos el puntero ultimo a NULL
}
void Cola::insetar(Reserva *y) // insetar un elemento en la cola
{
    pnodo nuevo; // Creamos un puntero a un nodo
    // reservamos memoria para el nodo y guardamos la dirección en el puntero nuevo
    nuevo = new Nodo(y); // El nuevo nodo apunta al último nodo que había en la cola, v es el valor del nodo
    if(ultimo)
     ultimo->siguiente = nuevo; // Si la cola no está vacía, el último nodo de la cola apunta al nuevo nodo
    ultimo = nuevo; // Ahora el último nodo de la cola es el nodo nuevo
    if(!primero) primero = nuevo; // Si la cola está vacía, el primer nodo de la cola es el nodo nuevo

}

Reserva* Cola::eliminar()
{
    pnodo nodo; // Creamos un puntero a un nodo
    Reserva* v; // Creamos una variable de tipo Reserva 
    nodo = primero; // El puntero nodo apunta al primer nodo de la cola
    if(!primero) return v; // Si la cola está vacía, retornamos v
    primero = nodo->siguiente; // El primer nodo de la cola es el nodo siguiente al que apunta nodo, -> es el operador de acceso a miembros de una estructura,
    // es decir, nodo->siguiente es el miembro siguiente de la estructura nodo
    // dentro de la estructura nodo, podemos acceder con operador -> a valor y a siguiente
    if(!primero) ultimo = NULL; // Si la cola está vacía, el último nodo de la cola es NULL
    v = nodo->valor; // Guardamos el valor del nodo en la variable v
    cout << "eliminando la reserva de  : " << v->nombre << endl; // Mostramos el valor extraído
    delete nodo; // Borramos el nodo
    return v; // Retornamos el valor del nodo
}

void Cola::mostrar()
{
    pnodo aux; // Creamos un puntero a un nodo
    aux = primero; // El puntero aux apunta al primer nodo de la cola
    cout << "   +++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "   + Listado de todos los elementos de la cola:  +"<< endl;
    cout << "   +++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    while(aux) // Mientras que aux no sea NULL
    
    {
        //hacer una tabla con los datos de la reserva

        cout << "###################################" << endl;
        cout << "#                                 #" << endl;

        cout << "# Nombre de la reserva : ";
        //imprimir el # dependiendo del tamaño del nombre, coger el tamaño del nombre 
        //y luego imprimir el numero de # que sea necesario, nombre mas larg menos espacios
        int tam = aux->valor->nombre.size();
        cout << aux->valor->nombre; 
        for (int i = 0; i < 9-tam; i++){
            cout << " ";
        }
        cout << "#" << endl;
        cout << "# Numero de personas : ";
        cout << aux->valor->personas <<"          #" << endl;
        cout << "# Lugar de la reserva : " ;
        if (aux->valor->lugar_reserva == 0)
            cout << "interior  #" << endl;
        else
            cout << "terraza   #" << endl;
        if (aux->valor->menu_reserva == 0)
            cout << "# Menu : vegano                   #" << endl;
        else if (aux->valor->menu_reserva == 1)
            cout << "# Menu : sin gluten               #" << endl;
        else
            cout << "# Menu : completo                 #" << endl;
        if (aux->valor->hora_reserva == 0)
            cout << "# Hora : 13:00                    #" << endl;
        else if (aux->valor->hora_reserva == 1)
            cout << "# Hora : 14:00                    #" << endl;
        else
            cout << "# Hora : 15:00                    #" << endl;
        
        aux = aux->siguiente; // El puntero aux apunta al siguiente nodo de la cola
        cout << "#                                 #" << endl;
        cout << "###################################" << endl;
    cout << endl;
    
    }
}
Cola::~Cola() // Destructor de la clase Cola
{
    pnodo nodo; // Creamos un puntero a un nodo
    while(primero) // Mientras que primero no sea NULL
        eliminar(); // Eliminamos un nodo de la cola

}

Reserva* Cola::get_primero(){
    if (primero != nullptr){
        return primero->valor;
    }
    else return nullptr;
}



