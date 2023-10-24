#include "pedido.h"

Pedido::pedido(){
    mesa = 0;
    nombre = "";
    personas = 0;
    menu_pedido = completo;
    lugar_pedido = trece;
    finalizado = true;

}
Pedido::pedido(int m, string n, int p, menu )