#include "Pedido.h"
#include <string>
Pedido::Pedido(){
    mesa = 0;
    nombre = "";
    personas = 0;
    menu_pedido = completo;
    lugar_pedido = interior; // Change the value to a valid one
    finalizado = false;
}

Pedido::Pedido(int mesa, string nombre, menu menu_pedido, lugar lugar_pedido, bool finalizado){
    this->mesa = mesa;
    this->nombre = nombre;
    this->personas = personas;
    this->menu_pedido = menu_pedido;
    this->lugar_pedido = lugar_pedido;
    this->finalizado = finalizado;
}

Pedido::~Pedido(){
    cout << "Se ha borrado el pedido de " << nombre << endl;
}

// Metodos escribir, mostrar y generar pedido

void Pedido::escribir_pedido(){
    cout << "Numero de mesa: ";
    cin >> mesa;
    cout << "Nombre del Cliente: ";
    cin >> nombre;
    cout << "Numero de personas";
    cin >> personas;
    int valor;
    cout << "Menu (0: vegano, 1: sin gluten, 2: completo): ";
    cin >> valor;
    menu_pedido = static_cast<menu>(valor);
    cout << "Lugar (0: interior, 1: terraza): ";
    cin >> valor;
    lugar_pedido = static_cast<lugar>(valor);
    cout << "¿El pedido a finalizado?: ";
    cin >> finalizado;


}

void Pedido::mostrar_pedido(){
    //mostramos al cliente su pedido
    cout << "Su pedido es: " << endl;
    cout << "Numero de mesa: " << mesa << endl;
    cout << "Nombre del Cliente: " << nombre << endl;
    cout << "Numero de personas: " << personas << endl;
    //mostramos el valor del enumerado menu
    if (menu_pedido == vegano)
        cout << "Menu: vegano" << endl;
    else if (menu_pedido == sin_gluten)
        cout << "Menu: sin gluten" << endl;
    else
        cout << "Menu: completo" << endl;

    //mostramos el valor del enumerado lugar
    if (lugar_pedido == interior)
        cout << "Lugar: interior" << endl;
    else
        cout << "Lugar: terraza" << endl;

    //mostramos el valor del booleano finalizado
    if (finalizado == true)
        cout << "El pedido ha finalizado" << endl;
    else
        cout << "El pedido no ha finalizado" << endl;
    
}

//generar pedido aleatorio

void Pedido::generar_pedido(){
    mesa = rand() % 20 + 1;
    string nombre[] = {"Juan", "Pedro", "Maria", "Ana", "Luis", "Carlos", "Sara", "Laura", "Pablo", "Javier"};
    personas = rand() % 8 + 1;
    int valor = rand() % 2 + 1;
    if (valor == 1)
        menu_pedido = vegano;
    else if (valor == 2)
        menu_pedido = sin_gluten;
    else
        menu_pedido = completo;
    valor = rand() % 2 + 1;
    if (valor == 1)
        lugar_pedido = interior;
    else
        lugar_pedido = terraza;
    finalizado = false;
}