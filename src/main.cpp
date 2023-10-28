#include <iostream>
using namespace std;

#include "reserva.h"
#include "reserva.cpp"
#include "Cola.h"
#include "Cola.cpp"

#include "mesa.h"
#include "mesa.cpp"
#include "PilaMesa.h"
#include "PilaMesa.cpp"

#include "pedido.h"
#include "pedido.cpp"
#include "ColaPedido.h"
#include "ColaPedido.cpp"

#include "menu.cpp"

void processReservas(Cola* cola, PilaMesa* pila, Cola* cPedidos, ColaPedido *colapendientes, int *cantidadReservas, int *cantidadmesas);
void processReservasHora(Cola* cola, PilaMesa* pila, Cola* cPedidos, ColaPedido *colapendientes, int *cantidadReservas, int *cantidadmesas);
void imprimirReservas(Cola* cola, PilaMesa* pila, Cola* cPedidos, ColaPedido *colapendientes, int *cantidadReservas, int *cantidadmesas);
void processAllReservas(Cola* cola, PilaMesa* pila, Cola* cPedidos, ColaPedido *colapendientes, int *cantidadReservas, int *cantidadmesas);
int main()

{
   
   Cola *cola = new Cola();
   PilaMesa *pila = new PilaMesa();
   PilaMesa *pila2 = new PilaMesa();
   Reserva *r = new Reserva();
   PilaMesa *pila_aux = new PilaMesa();
   Cola *cPedidos = new Cola();
   Cola *cPendientes = new Cola();
   Mesa *m = new Mesa();
   bool encontrado = false;
   int *cantidadmesas = new int(0);
   int *cantidadReservas = new int(0);
   ColaPedido *colapendientes = new ColaPedido();
   //inicio menu
   
   int opcion = menu();
   // switch case
   //hacer hasta que opcion sea 0

   while (opcion != 0)
   {
       switch (opcion)
       {
       case 1:
           //generar aleatoriamente la cola de reservas
          for (int i = 0; i < 4; i++)
       {
          Reserva *r = new Reserva();
          r->reserva_generar();
          //hacer que las reservas sean a las 13:00, con set_hora
            r->set_hora(13);
          cola->insetar(r);
          (*cantidadReservas)++;
       }
         for (int i = 0; i < 4; i++)
         {
            Reserva *r = new Reserva();
            r->reserva_generar();
            //hacer que las reservas sean a las 14:00, con set_hora
               r->set_hora(14);
            cola->insetar(r);
            (*cantidadReservas)++;
         }

         for (int i = 0; i < 4; i++)
         {
            Reserva *r = new Reserva();
            r->reserva_generar();
            //hacer que las reservas sean a las 15:00, con set_hora
               r->set_hora(15);
            cola->insetar(r);
            (*cantidadReservas)++;
         }
         cout << "               ++++++++++++++++++++++" << endl;
         cout << "               + RESERVAS GENERADAS +" << endl;
         cout << "               ++++++++++++++++++++++" << endl;
         cout << "CANTIDAD = " << *cantidadReservas << endl;
           break;
       case 2:
           //mostrar en pantalla los datos de la cola de reservas
           cola->mostrar();
           cout << "Cantidad de reservas : " << *cantidadReservas << endl;           
           break;
       case 3:
           //borrar la cola de reservas
           cola->~Cola();
         *cantidadReservas = 0;
         cout << "Cantidad de reservas : " << *cantidadReservas << endl; 
           break;
       case 4:
           //generar aleatoriamente la pila de mesas 10 mesas de 4 personas y 10 mesas de 8 personas
           
         for (int i = 0; i < 10; i++)
         {
            Mesa *m = new Mesa();
            m->generar_mesa();
            //hacer que las mesas sean de 4 personas, con set_personas
            m->set_capacidad(4);
            m->set_numeroMesa((*cantidadmesas)+1);
            pila->insertar(m);
            (*cantidadmesas)++;
         }
             for (int i = 0; i < 10; i++)
             {
                Mesa *m = new Mesa();
                m->generar_mesa();
                //hacer que las mesas sean de 8 personas, con set_personas
                m->set_capacidad(8);
                m->set_numeroMesa(*cantidadmesas+1);
                pila->insertar(m);
                (*cantidadmesas)++;
             }
               cout << "               +++++++++++++++++++" << endl;
               cout << "               + MESAS GENERADAS +" << endl;
               cout << "               +++++++++++++++++++" << endl;
               cout << "CANTIDAD = " << *cantidadmesas << endl;
           break;
       case 5:
           //mostrar en pantalla los datos de la pila de mesas
           pila->mostrar();
           cout << "Cantidad de mesas : " << *cantidadmesas << endl;
           break;
       case 6:
           //borrar la pila de mesas
           pila->~PilaMesa();
             *cantidadmesas = 0;
               cout << "Cantidad de mesas : " << *cantidadmesas << endl;
           break;
       case 7:
             //realizar 1 pedido
            processReservas(cola, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);
            imprimirReservas(cola, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);
             break;

         case 8:
         
            //simulacion de todas por horas
            processReservasHora(cola, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);
            imprimirReservas(cola, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);
            
           

         break; 

         case 9:
            
            //simulacion de todas las reservas
            processAllReservas(cola, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);
            imprimirReservas(cola, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);



          
         break;
         default:
               cout << "Opcion incorrecta" << endl;
               break;
            
            

        }opcion = menu(); }

        
   
   /* comprobación de clase reserva
   Reserva r2;
    r2.reserva_generar();
    r2.mostrar_reserva();
    Reserva r3;
    r3.reserva_generar();
    r3.mostrar_reserva();
    Reserva r4;
    r4.reserva_generar();
    r4.mostrar_reserva();
   
   */ 

  /* comprobación de la cola
    Cola cola;
    Reserva r1;
    r1.reserva_generar();
    cola.insetar(r1);
    cola.mostrar();
    Reserva r2;
    r2.reserva_generar();
    cola.insetar(r2);
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();
    
    */ 
 /* comprobación de la clase mesa
    Mesa m1;
    m1.generar_mesa();
    m1.mostrar_mesa();
    */

   /* comprobación de la pila de mesas
    PilaMesa pila;
    Mesa m1;
    m1.generar_mesa();
    pila.insertar(m1);
    pila.mostrar();
    */
   

   
/* comprobación de la clase pedido

    Pedido p2;
    p2.generar_pedido();
    p2.mostrar_pedido();
   
   */




 

return 0;
}


void processReservas(Cola* cola, PilaMesa* pila, Cola* cpendientes,ColaPedido *colaPedidos, int *cantidadReservas, int *cantidadmesas)
{
   
   Reserva* r;
   Mesa* m;
   PilaMesa* pila_aux = new PilaMesa();
   bool encontrado;
   
   
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
           (*cantidadmesas)--;
            (*cantidadReservas)--;
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

            //convertir el objeto reserva en un objeto pedido
            Pedido *p = new Pedido();
            p->generar_pedido(m, r);
            //meter el pedido en la cola de pedidos
            colaPedidos->insetar(p);
            cout << "---------------pedido creado---------------------" << endl;

            }

            else
            {

               pila_aux->insertar(m);
               
            }
            }
   
 //si la pila de mesas esta vacia, meter la reserva en la cola de pendientes
               if (pila->get_ultimo()==nullptr && encontrado == false){
                  cout << "No hay mesas disponibles" << endl;
                  cpendientes->insetar(r);
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

               

}

void processReservasHora (Cola* cola, PilaMesa* pila, Cola* cPedidos, ColaPedido *colapendientes, int *cantidadReservas, int *cantidadmesas)
{
   int hora;
   cout << "dime la hora de las reservas que quieres realizar : " << hora << endl;
   cout << "0: 13:00, 1: 14:00, 2: 15:00" << endl;
   cin >> hora;
   Cola* cola_aux = new Cola();
   Cola* cola_retorno = new Cola();
   Reserva* r;
   //recorrer la cola de reservas y meter las reservas de la hora que se ha introducido en la cola auxiliar, llamando a la funcion processReservas
   
   while (cola->get_primero() != nullptr)
   {
      Reserva* r = cola->eliminar();
      if (r->get_hora() == hora)
      {
         cola_aux->insetar(r);
         processReservas(cola_aux, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);
      }else {
         cola_retorno->insetar(r);
      }
   }  

   //recorrer la cola retorno y meter las reservas en la cola de reservas
   while (cola_retorno->get_primero() != nullptr)
   {
      Reserva* r = cola_retorno->eliminar();
      cola->insetar(r);
   }

  
   
}



      
void imprimirReservas(Cola* cola, PilaMesa* pila, Cola* cPedidos, ColaPedido *colapendientes, int *cantidadReservas, int *cantidadmesas)
{
   
   cout << "Pila de mesas" << endl;
   pila->mostrar();
   cout << "Cola de reservas" << endl;
   cola->mostrar();
   cout << "Cola de pedidos" << endl;
   colapendientes->mostrar();
   cout << "Cola de pendientes" << endl;
   cPedidos->mostrar();
   cout << "Numero de mesas disponibles" << endl;
   cout << *cantidadmesas << endl;
   cout << "Reservas que quedan por resolver" << endl;
   cout << *cantidadReservas << endl;
}

void processAllReservas(Cola* cola, PilaMesa* pila, Cola* cPedidos, ColaPedido *colapendientes, int *cantidadReservas, int *cantidadmesas)
{
   int numero=0;
   /*/*hasta que se hayan gestionado todas las reservas de ambas colas o no puedan
            gestionarse las reservas en cPendientes. Al finalizar, se mostrarán en pantalla ambas colas de
            reservas, la pila de mesas y la cola de pedidos.*/

   while ((cola->get_primero() != nullptr || cPedidos->get_primero() != nullptr) && (numero!=30))
   {
     if (numero % 3 == 0 && cPedidos->get_primero() != nullptr) {
      processReservas(cPedidos, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);
}    else if (cola->get_primero() != nullptr) {
      processReservas(cola, pila, cPedidos, colapendientes, cantidadReservas, cantidadmesas);
}
numero++;


  
   
}

}

  