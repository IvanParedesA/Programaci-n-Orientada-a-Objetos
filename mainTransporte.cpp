/*
 *
 *Proyecto Agencia de Transporte main
 *Iván Ricardo Paredes Avilez
 *A01705083
 *10/06/2022
 *Version: 2
 *Este es un programa que nos permite administrar la información
 *de distintos tipos de viajes que pertenecen a una agencia de Transporte.
 *Podemos ver los detalles de cada viaje y hacer el calculo de los ingresos
 *que tenemos en un conjunto de viajes o en su totalidad.
 */

//Nos permite imprimir
#include <iostream>

//Importamos nuestras clases creadas en otros archivos
#include "viaje.h"
#include "agenciaTransporte.h"

using namespace std;

int main() {

    //Instanciamos el objeto agencia
    AgenciaTransporte agencia;

    //Generamos lo objteos
    agencia.crea_ejemplos();

    //Impresión de todos los viajes
    cout << "Estos son todos los viajes: \n" << endl;
    agencia.muestra_viajes();

    //Impresión de solo los viajes de tipo: Taxi Local
    cout << "Estos son los viajes de tipo Taxi Local: \n" << endl;
    agencia.muestra_viajes("Taxi local");

    //Ingreso total
    cout << "El ingreso total de la agencia fue: $" << agencia.calc_ingreso_total() << " pesos." << endl;

}
