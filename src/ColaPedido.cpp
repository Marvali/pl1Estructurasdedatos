#include "ColaPedido.h"

ColaPedido::ColaPedido() // Constructor de la clase Cola
{
    primero = NULL;
    ultimo = NULL;
}

void ColaPedido::insetar(Pedido *p) // insetar un elemento en la cola
{
    pnodoPedido nuevo; // Creamos un puntero a un nodo
    // reservamos memoria para el nodo y guardamos la dirección en el puntero nuevo
    nuevo = new NodoPedido(p); // El nuevo nodo apunta al último nodo que había en la cola, v es el valor del nodo
    if(ultimo)
        ultimo->siguiente = nuevo; // Si la cola no está vacía, el último nodo de la cola apunta al nuevo nodo
    ultimo = nuevo; // Ahora el último nodo de la cola es el nodo nuevo
    if(!primero) primero = nuevo; // Si la cola está vacía, el primer nodo de la cola es el nodo nuevo

}

Pedido* ColaPedido::eliminar()
{
    pnodoPedido nodo; // Creamos un puntero a un nodo
    Pedido* v; // Creamos una variable de tipo Pedido 
    nodo = primero; // El puntero nodo apunta al primer nodo de la cola
    if(!primero) return v; // Si la cola está vacía, retornamos v
    primero = nodo->siguiente; // El primer nodo de la cola es el nodo siguiente al que apunta nodo, -> es el operador de acceso a miembros de una estructura,
    // es decir, nodo->siguiente es el miembro siguiente de la estructura nodo
    // dentro de la estructura nodo, podemos acceder con operador -> a valor y a siguiente
    if(!primero) ultimo = NULL; // Si la cola está vacía, el último nodo de la cola es NULL
    v = nodo->valor; // Guardamos el valor del nodo en la variable v
    cout << "eliminando el pedido de  : " << v->nombreCliente << endl; // Mostramos el valor extraído
    delete nodo; // Borramos el nodo
    return v; // Retornamos el valor del nodo
}

void ColaPedido::mostrar()
{
    pnodoPedido aux; // Creamos un puntero a un nodo
    aux = primero; // El puntero aux apunta al primer nodo de la cola
    cout << "   +++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "   + Listado de todos los elementos de la cola:  +"<< endl;
    cout << "   +++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    while(aux) // Mientras que aux no sea NULL
    {
        //hacer una tabla con los datos del pedido

        cout << "###################################" << endl;
        cout << "#                                 #" << endl;

        cout << "# Nombre del cliente : ";
        //imprimir el # dependiendo del tamaño del nombre, coger el tamaño del nombre 
        //y luego imprimir el numero de # que sea necesario, nombre mas larg menos espacios
        int tam = aux->valor->nombreCliente.size();
        cout << aux->valor->nombreCliente; 
        for (int i = 0; i < 11-tam; i++){
            cout << " ";
        }
        cout << "#" << endl;
        cout << "# Numero de personas : ";
        cout << aux->valor->numeroPersonas;
        cout << "          #" << endl;
        cout << "# Numero de mesa : ";
        cout << aux->valor->numeroMesa<< "             #"<< endl;
        cout << "# menu : ";                   
        if (aux->valor->menu_reserva == 0)
            cout << "vegano                   #" << endl;
        else if (aux->valor->menu_reserva == 1)
            cout << "sin gluten               #" << endl;
        else
            cout << "completo                 #" << endl;
        
        cout << "# hora : ";
        if (aux->valor->hora_reserva == 0)
            cout << "13:00                    #" << endl;
        else if (aux->valor->hora_reserva == 1)
            cout << "14:00                    #" << endl;
        else
            cout << "15:00                    #" << endl;
        
        //estado del pedido
        if (aux->valor->estado == 0)
            cout << "# PEDIDO SIN FINALIZAR            #" << endl;
        
        else
            cout << "# PEDIDO FINALIZADO               #" << endl;

           
        cout << "###################################" << endl;
        cout << endl;

        aux = aux->siguiente; // El puntero aux apunta al nodo siguiente
    }
    cout << endl;
}