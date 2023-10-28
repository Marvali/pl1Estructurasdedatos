
#include "PilaMesa.h" // Incluimos el archivo PilaMesa.h donde se encuentra la declaración de la clase PilaMesa

PilaMesa::PilaMesa() // Constructor de la clase PilaMesa  Los dos puntos :: indican que PilaMesa() es un miembro de la clase PilaMesa.
{
    ultimo = NULL; // Inicializamos el puntero ultimo a NULL
}

void PilaMesa::insertar(Mesa *y) // insetar un elemento en la pila
{
    pnodoMesa nuevo; // Creamos un puntero a un nodo
    // reservamos memoria para el nodo y guardamos la dirección en el puntero nuevo
    nuevo = new NodoMesa(y,ultimo); // El nuevo nodo apunta al último nodo que había en la pila, v es el valor del nodo
    ultimo = nuevo; // Ahora el último nodo de la pila es el nodo nuevo
}

Mesa* PilaMesa::eliminar()
{
    pnodoMesa aux; // Creamos un puntero a un nodo
    pnodoMesa nodo; // Creamos un puntero a un nodo
    Mesa* v; // Creamos una variable de tipo Mesa 
    nodo = ultimo; // El puntero nodo apunta al último nodo de la pila
    if(!ultimo) return v; // Si la pila está vacía, retornamos v
    ultimo = nodo->siguiente; // El último nodo de la pila es el nodo siguiente al que apunta nodo, -> es el operador de acceso a miembros de una estructura,
    // es decir, nodo->siguiente es el miembro siguiente de la estructura nodo
    // dentro de la estructura nodo, podemos acceder con operador -> a valor y a siguiente
    v = nodo->valor; // Guardamos el valor del nodo en la variable v
    //acceder al valor mesa->numero
    cout << "eliminando la mesa numero : " << nodo->valor->numeroMesa << endl; // Mostramos el valor extraído
    
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
        cout << "###################" << endl;
        //si el numero de la mesa es mayor de 10, se muestran 1 espacios en blanco si es menor solo 1
        if (aux->valor->numeroMesa > 9)
            cout << "# Mesa: " << aux->valor->numeroMesa << "        #" << endl;
        else
            cout << "# Mesa: " << aux->valor->numeroMesa << "         #" << endl;
        cout << "# Capacidad: " << aux->valor->capacidad << "    #" << endl;
        if (aux->valor->lugar_mesa == 0)
            cout << "# Lugar: " << "interior #" << endl;
        else
            cout << "# Lugar: " << "terraza  #" << endl;

        cout << "###################" << endl;
        cout << "#                 #" << endl;
        cout << endl;

       
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

Mesa* PilaMesa::get_ultimo(){

    if (ultimo != nullptr){
        return ultimo->valor;
    }
    else{
        return nullptr;
    }
}

