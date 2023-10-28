#include <iostream>
#include "Util.h"
#include <string>

using namespace std;



void processReservas(Cola* cola, PilaMesa* pila, Cola* cPedidos, Cola* cPendientes, int cantidadReservas, int cantidadmesas)
{
   Reserva* r;
   Mesa* m;
   PilaMesa* pila_aux = new PilaMesa();
   
   bool encontrado;
   //mientras que la cola de reservas no este vacia y haya mesas disponibles
   while ((cola->get_primero() != nullptr) && (cantidadmesas > 0))
   {
      //coger la primera reserva de la cola
      r = cola->eliminar();
      encontrado = false;
      //recorrer la pila de mesas hasta encontrar una mesa con capacidad suficiente
      //while pila not null
      while ((pila->get_ultimo() != nullptr) && (encontrado == false))
      {
         m = pila->eliminar();
         //si la mesa tiene capacidad suficiente y esta en el mismo lugar que la reserva, creamos el pedido y la mesa queda borrada
         if (((r->get_personas() <=4 && m->get_capacidad() ==4) || (r->get_personas() >4 && m->get_capacidad() ==8))&& (r->get_lugar() == m->get_lugar_mesa()))
         {
            cantidadmesas--;
            cantidadReservas--;
            cout << "---------------mesa encontrada---------------------" << endl;
            cout << "Reserva de : " << r->get_nombre() << endl;
            cout << "Numero de personas : " << r->get_personas() << endl;
            cout << "Lugar de la reserva : " ;
            if (r->get_lugar() == 0)
               cout << "interior" << endl;
            else
               cout << "terraza" << endl;
            cout << "mesa utilizada : " ;
            cout << "Capacidad : " << m->get_capacidad() << endl;
            cout << "Lugar de la mesa : " ;
            if (m->get_lugar_mesa() == 0)
               cout << "interior" << endl;
            else
               cout << "terraza" << endl;
            encontrado = true;
            cPedidos->insetar(r);
            cout << "---------------pedido creado---------------------" << endl;

            }

            else
            {

               pila_aux->insertar(m);
               
            }
            }
   }
 //si la pila de mesas esta vacia, meter la reserva en la cola de pendientes
               if (pila->get_ultimo()==nullptr){
                  cout << "No hay mesas disponibles" << endl;
                  cPendientes->insetar(r);
               }
               //recorremos la pila de mesas auxiliar, para colocar la pila de mesa en su estado original
               while(pila_aux!= nullptr){
                  if (pila_aux->get_ultimo() != nullptr) {
                     
                     m = pila_aux->eliminar();
                     pila->insertar(m);
                  } else {
                        break;  // Exit the loop if pila_aux is empty
                  }
               }
               //mostramos las dos colas y la pila
               // hacer una tabla con los datos de las reservas

               cout << "Cola de reservas" << endl;
               cola->mostrar();
               cout << "Reservas que quedan por resovolver" << endl;
               cout << cantidadReservas << endl;
               cout << "Cola de pedidos" << endl;
               cPedidos->mostrar();
               cout << "Mesas disponibles" << endl;
               pila->mostrar();
               cout << "Numero de mesas disponibles" << endl;
               cout << cantidadmesas << endl;

}