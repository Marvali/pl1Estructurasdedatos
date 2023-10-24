
class Pedido{

    private:
        int mesa;
        string nombre;
        int personas;
        enum menu{vegano, sin_gluten, completo}// No entiendo porque ponemos enum
        menu menu_pedido
        enum lugar{interior, terraza}
        lugar lugar_pedido
        bool finalizado;

    public:
        Pedido();
        Pedido(int mesa, string nombre, menu menu_pedido, lugar lugar_pedido, bool finalizado);
        ~Pedido();

// Métodos escribir,mostrar y reserva_generar
    void escribir_pedido();
    void mostrar_pedido();
    void reserva_generar();

// Getters y setters
    int get_mesa();
    string get_nombre();
    int get_personas();
    menu get_menu();
    lugar get_lugar();
    bool get_finalizado();

    void set_mesa(int mesa);
    void set_nombre(string nombre);
    void set_personas(int personas);
    void set_menu(menu menu_reserva);
    void set_lugar(lugar lugar_reserva);
    void set_finalizad(bool finalizado);
    

}