#include "pedido.h"

Pedido::pedido(){
    mesa = 0;
    nombre = "";
    personas = 0;
    menu_pedido = completo;
    lugar_pedido = trece;
    finalizado = false;

}
Pedido::pedido(int m, string n, int p, menu me, lugar l, bool f){
    mesa = m;
    nombre = n;
    personas = p;
    menu_pedido = me;
    lugar_pedido = l;
    finalizado = f;
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
    menu_pedido =static_cast<menu>(valor);
    cout << "Lugar (0: interior, 1: terraza): ";
    cin >> valor;
    lugar_pedido = static_cast<lugar>(valor);
    cout << "¿El pedido a finalizado?: ";
    cin >> finalizado;

}

void Pedido::mostrar_pedido(){
    cout << "Numero de mesa: " << mesa << endl;
    cout << "Nombre del Cliente: " << nombre << endl;
    cout << "Numero de personas" << personas << endl;

    if (menu_pedido == vegano){
        cout << "Menu: Vegano" << endl;
    } else if (menu_pedido == sin_gluten){
        cout << "Menu: sin gluten" << endl;
    } else{
        cout << "Menu: completo" << endl;
    }

    if (menu_pedido == interior){
        cout << "Lugar: interior" << endl;
    }else{
       cout << "Lugar: terraza" << endl;
    }

    cout << "¿El pedido a finalizado?: " << finalizado <<endl;
}
