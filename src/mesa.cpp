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
        //numero de mesa incremental
        numeroMesa = rand() % 100 + 1;
        capacidad = rand() % 8 + 1;
        int lugar = rand() % 2;
        if (lugar == 1)
            lugar_mesa = terraza;
        else
            lugar_mesa = interior;
    
    }

    // Getters y setters
    int Mesa::get_numeroMesa()
    {
        return numeroMesa;
    }
    void Mesa::set_lugar_mesa(int x)
    {
        lugar_mesa = static_cast<lugar>(x);
    }
    void Mesa::set_capacidad(int c)
    {
        capacidad = c;
    }

    void Mesa::set_numeroMesa(int n)
    {
        numeroMesa = n;
    }

    int Mesa::get_capacidad()
    {
        return capacidad;
    }

    Mesa::lugar Mesa::get_lugar_mesa()
    {
        return lugar_mesa;
    }