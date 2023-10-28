#ifndef UTIL_H
#define UTIL_H

#include "Reserva.h"
#include "Cola.h"
#include "COLA.cpp"
#include "PilaMesa.h"
#include "PilaMesa.cpp"



void processReservas(Cola* cola, PilaMesa* pila, Cola* cPedidos, Cola* cPendientes, int cantidadReservas, int cantidadmesas);

#endif