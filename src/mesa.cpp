 #include "mesa.h"

    Mesa::Mesa() // Constructor por defecto
    {
        numeroMesa = 0;
        capacidad = 0;
        lugar_mesa = interior;
    }

    Mesa::Mesa(int n, int c, lugar l) // Constructor con parámetros
    {
        numeroMesa = n;
        capacidad = c;
        lugar_mesa = l;
    }

    Mesa::~Mesa() // Destructor
    {
        cout << "Se ha destruido la mesa " << numeroMesa << endl;
    }

    void Mesa::mostrar_mesa()
    {
        cout << "Mesa " << numeroMesa << endl;
        cout << "Capacidad: " << capacidad << endl;
        if (lugar_mesa == interior)
            cout << "Lugar: " << "interior" << endl;
        else
            cout << "Lugar: " << "terraza" << endl;
        
    }
    //genera una mesa aleatoria
    void Mesa::generar_mesa()
    {
        numeroMesa = rand() % 20 + 1;
        capacidad = rand() % 10 + 1;
        int lugar = rand() % 2 + 1;
        if (lugar == 1)
            lugar_mesa = terraza;
        else
            lugar_mesa = interior;
    
    }