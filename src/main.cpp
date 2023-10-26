#include "reserva.h"
#include "reserva.cpp"
#include "Cola.cpp"
#include "mesa.h"
#include "mesa.cpp"
#include "PilaMesa.cpp"
#include "Pedido.h"
#include "cpedido.cpp"
#include "menu.cpp"
int main()
{
   Cola *cola = new Cola();
   PilaMesa *pila = new PilaMesa();
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
           break;
       case 2:
           //mostrar en pantalla los datos de la cola de reservas
           cola->mostrar();
           break;
       case 3:
           //borrar la cola de reservas
           cola->~Cola();
           break;
       case 4:
           //generar aleatoriamente la pila de mesas 10 mesas de 4 personas y 10 mesas de 8 personas
           for (int i = 0; i < 10; i++)
           {
               Mesa *m = new Mesa();
               m->generar_mesa();
               //hacer que las mesas sean de 4 personas, con set_personas
               m->set_capacidad(4);
               m->set_numeroMesa(i+1);
               pila->insertar(*m);
           }
             for (int i = 0; i < 10; i++)
             {
                Mesa *m = new Mesa();
                m->generar_mesa();
                //hacer que las mesas sean de 8 personas, con set_personas
                m->set_capacidad(8);
                m->set_numeroMesa(i+10);
                pila->insertar(*m);
             }
           
           break;
       case 5:
           //mostrar en pantalla los datos de la pila de mesas
           pila->mostrar();
           break;
       case 6:
           //borrar la pila de mesas
           pila->~PilaMesa();
           break;
       case 7:
           //simulacion de la gestion 1
           //coger la
             break;
         default:
               cout << "Opcion incorrecta" << endl;
               break;
            }
            opcion = menu();

        } 
   
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