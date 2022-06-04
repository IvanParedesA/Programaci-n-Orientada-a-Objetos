//Iván Ricardo Paredes Avilez A01705083
//03/06/2022
//mainTransporte.cpp
//Version 1

#include <iostream>

//Importamos nuestras clases creadas en otros archivos
#include "viaje.h"
#include "agenciaTransporte.h"

using namespace std;

int main() {

    AgenciaTransporte agencia;
    agencia.crea_ejemplos();
    agencia.muestra_viajes();
    agencia.muestra_viajes("Taxi local");


}
