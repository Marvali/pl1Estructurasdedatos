#include "reserva.h"

Reserva::Reserva() // Constructor por defecto
{
    nombre = "";
    personas = 0;
    lugar_reserva = interior;
    hora_reserva = trece;
    menu_reserva = completo;
}
Reserva::Reserva(string n, int m, int p, lugar l, hora h, menu me) // Constructor con parámetros
{
    nombre = n;
    personas = p;
    lugar_reserva = l;
    hora_reserva = h;
    menu_reserva = me;
}
// Destructor 
Reserva::~Reserva()
{
    cout << "Se ha borrado la reserva de " << nombre << endl;
}


// Métodos escribir,mostrar y generar_reserva
void Reserva::escribir_reserva()
{
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Personas: ";
    cin >> personas;
    int temp;
    cout << "Lugar (0: interior, 1: terraza): ";
    cin >> temp;
    lugar_reserva = static_cast<lugar>(temp);// static_cast<lugar>(temp) convierte temp en lugar
    cout << "Hora (0: 13:00, 1: 14:00, 2: 15:00): ";
    cin >> temp;
    hora_reserva = static_cast<hora>(temp);
    cout << "Menu (0: vegano, 1: sin gluten, 2: completo): ";
    cin >> temp;
    menu_reserva = static_cast<menu>(temp);
}

void Reserva::mostrar_reserva()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Personas: " << personas << endl;
    //mostramos el valor del enumerado lugar
    if (lugar_reserva == interior)
        cout << "Lugar: interior" << endl;
    else
        cout << "Lugar: terraza" << endl;
    //mostramos el valor del enumerado hora
    if (hora_reserva == trece)
        cout << "Hora: 13:00" << endl;
    else if (hora_reserva == catorce)
        cout << "Hora: 14:00" << endl;
    else
        cout << "Hora: 15:00" << endl;
    //mostramos el valor del enumerado menu
    if (menu_reserva == vegano)
        cout << "Menu: vegano" << endl;
    else if (menu_reserva == sin_gluten)
        cout << "Menu: sin gluten" << endl;
    else
        cout << "Menu: completo" << endl;
}

void Reserva::reserva_generar()
{
//generar reservas aleatorias para hacer pruebas 
/*cuatro reservas para las 13:00, cuatro para las 14:00 y cuatro para las 15:00,
el resto de los datos en cada reserva será aleatorio*/ 

/**/
    string nombres[] = {"Juan", "Pedro", "Maria", "Ana", "Luis", "Carlos", "Sara", "Laura", "Pablo", "Javier"};
    lugar lugares[] = {interior, terraza};
    hora horas[] = {trece, catorce, quince};
    menu menus[] = {vegano, sin_gluten, completo};
    int aleatorio;
    aleatorio = rand() % 10;
    nombre = nombres[aleatorio];
    aleatorio = rand() % 8+1;
    personas = aleatorio;
    aleatorio = rand() % 2;
    aleatorio = rand() % 2;
    lugar_reserva = lugares[aleatorio];
    aleatorio = rand() % 3;
    hora_reserva = horas[aleatorio];
    aleatorio = rand() % 3;
    menu_reserva = menus[aleatorio];


}

void Reserva::set_hora(int x)
{
   if (x ==13)
   {
      hora_reserva = trece;
   }
   else if (x == 14)
   {
      hora_reserva = catorce;
   }
   else if (x == 15)
   {
      hora_reserva = quince;
   }
   else
   {
      cout << "hora no válida" << endl;
   }
}