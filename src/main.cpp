#include "reserva.h"
#include "reserva.cpp"
#include "Cola.cpp"
#include "mesa.h"
#include "mesa.cpp"
#include "PilaMesa.cpp"
#include "Pedido.h"
#include "cpedido.cpp"
int main()
{
   
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

  /*en la cola se incluirán, al
menos y en este orden, cuatro reservas para las 13:00, cuatro para las 14:00 y cuatro para las 15:00,
el resto de los datos en cada reserva será aleatorio, TODO EN MEMORIA DINAMICA

*/
       Cola *cola = new Cola();
       for (int i = 0; i < 4; i++)
       {
          Reserva *r = new Reserva();
          r->reserva_generar();
          //hacer que las reservas sean a las 13:00, con set_hora
            r->set_hora(13);
          cola->insetar(*r);
       }
         for (int i = 0; i < 4; i++)
         {
            Reserva *r = new Reserva();
            r->reserva_generar();
            //hacer que las reservas sean a las 14:00, con set_hora
               r->set_hora(14);
            cola->insetar(*r);
         }

         for (int i = 0; i < 4; i++)
         {
            Reserva *r = new Reserva();
            r->reserva_generar();
            //hacer que las reservas sean a las 15:00, con set_hora
               r->set_hora(15);
            cola->insetar(*r);
         }

         // mostrar la cola
         cola->mostrar();

         // eliminar la cola Reserva Cola::eliminar()
          cola->~Cola();

         //Generar aleatoriamente la pMesas (al menos ocho serán en terraza, la capacidad será aleatoria).
         PilaMesa *pila = new PilaMesa();
         for (int i = 0; i < 8; i++)
         {
            Mesa *m = new Mesa();
            m->generar_mesa();
            //hacer que las mesas sean en terraza, con set_lugar_mesa
            m->set_lugar_mesa(1);
            pila->insertar(*m);
         }

         //8 mesas en interior
         for (int i = 0; i < 8; i++)
         {
            Mesa *m = new Mesa();
            m->generar_mesa();
            //hacer que las mesas sean en interior, con set_lugar_mesa
            m->set_lugar_mesa(0);
            pila->insertar(*m);
         }


         // mostrar la pila
         pila->mostrar();


         //borrar la pila
         pila->~PilaMesa();
return 0;
}