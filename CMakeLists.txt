cmake_minimum_required(VERSION 3.23)
project(pl1Estructurasdedatos)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(pl1Estructurasdedatos
        src/Cola.cpp
        src/cpedido.cpp
        src/hola.cpp
        src/main.cpp
        src/menu.cpp
        src/mesa.cpp
        src/mesa.h
        src/NodoMesa.hpp
        src/NodoPedido.hpp
        src/NodoReserva.hpp
        src/Pedido.h
        src/Pila.hpp
        src/PilaMesa.cpp
        src/reserva.cpp
        src/reserva.h
        src/tempCodeRunnerFile.cpp)
