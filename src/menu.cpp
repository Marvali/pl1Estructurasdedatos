#include <iostream>

using namespace std;
int menu()
{
    int opcion;
    cout << "------------------------------------" << endl;
    cout << "Bienvenido al restaurante" << endl;
    cout << "1. Generar aleatoriamente la cReservas" << endl;
    cout << "2. Mostrar en pantalla los datos de la cReservas" << endl;
    cout << "3. Borrar la cReservas" << endl;
    cout << "4. Generar aleatoriamente la pMesas" << endl;
    cout << "5. Mostrar en pantalla los datos de la pMesas" << endl;
    cout << "6. Borrar la pMesas" << endl;
    cout << "7. Simulacion la gestion 1" << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------------------" << endl;
    cin >> opcion;
    return opcion;
}