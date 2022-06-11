/*
 *
 *Proyecto Agencia de Transporte clase AgenciaTransporte
 *Iván Ricardo Paredes Avilez
 *A01705083
 *10/06/2022
 *Version: 2
 *Esta clase define el objeto AgenciaClase que contiene las operaciones
 *necesarias para instanciar objetos de clase Viaje, pero también para
 *determinar los ingresos totales de la agencia
 */

#ifndef AGENCIATRANSPORTE_H_
#define AGENCIATRANSPORTE_H_

//Nos permite imprimir
#include <iostream>

//importamos la clase de viaje
#include "viaje.h"

using namespace std;

//Constante para el número máximo de arreglos
const int arreglos_max = 100;

//Declaración de la clase AgenciaTransporte
class AgenciaTransporte {

    //Atributos de la clase AgenciaTransporte
    private:
        Viaje * viaj[arreglos_max];
        int num_viajes = 0;

    //Constructor y métodos de la clase empresaTransporte
    public:
        //Declaración del constructor default
        AgenciaTransporte(): num_viajes(0) {};

        //Métodos de la clase AgenciaTransporte
        void crea_ejemplos();
        void muestra_viajes();
        void muestra_viajes(string tipo);
        double calc_ingreso_total();
        double calc_ingreso_total(string tipo);
        void agrega_taxi_local(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu);
        void agrega_taxi_interurbano(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip);
        void agrega_flete(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car);
};

//Funciones de la clase AgenciaTransporte

/**
 *crea_ejemplos genera objetos de tipo TaxiLocal, TaxiInterurbano y Flete.
 *Estos se guardan en el arreglo viaj[] con el fin de hacer pruebas. Por la misma
 *razón estos datos deben ser considerados como falsos
 */
void AgenciaTransporte::crea_ejemplos() {

    viaj[num_viajes] = new TaxiLocal(1, "Taxi local", "Juriquilla", "El Refugio", 17, 6.3, true);
    num_viajes++;
    viaj[num_viajes] = new TaxiLocal(2, "Taxi local", "El pueblito", "Plaza Puerta La Victoria", 9.1, 5.9, false);
    num_viajes++;
    viaj[num_viajes] = new TaxiInterurbano(3, "Taxi interurbano", "Queretaro", "Ciudad de Mexico", 213, 7, 2, 2);
    num_viajes++;
    viaj[num_viajes] = new TaxiInterurbano(4, "Taxi interurbano", "Queretaro", "Leon GTO", 169, 7.1, 3, 3);
    num_viajes++;
    viaj[num_viajes] = new Flete(5, "Flete", "El marques", "San Miguel de Allende", 70, 12, 560.5);
    num_viajes++;
    viaj[num_viajes] = new Flete(6, "Flete", "Corregidora", "", 70, 12, 560.5);
    num_viajes++;
}

/**
 *muestra_viajes imprime viajes
 *
 *Se utiliza el arreglo de viaj[] y el número de viajes para poder
 *recorrer todo el arreglo e imprimir la información de cada uno
 *de los objetos que están dentro de él con sus propios métodos de mostrar_viaje
 */
void AgenciaTransporte::muestra_viajes(){
    //Ciclo que recorre toda la lista de viajes
    for (int i = 0; i < num_viajes; i++){
        viaj[i] -> mostrar_viaje();
    }
    cout << endl;
}

/**
 *muestra_viajes(string) imprime un tipo específico de objetos
 *
 *Se utiliza el arreglo de viaj[] y el número de viajes para poder
 *recorrer todo el arreglo e imprimir la información de cada uno
 *de los objetos que están dentro de él y que coinciden con el tipo
 */
void AgenciaTransporte::muestra_viajes(string tipo){
    //Ciclo que recorre toda la lista de viajes en busca de cierto tipo de viaje en especial
    for (int i = 0; i < num_viajes; i++){
        if(viaj[i] -> get_tipo() == tipo){
            viaj[i] -> mostrar_viaje();
        }
    }
    cout << endl;
}

/**
 *calc_ingreso_total representa el ingreso total de la agencia.
 *
 *Se utiliza el arreglo de viaj[] y el número de viajes para poder
 *recorrer todo el arreglo y guardar el valor de precio de las tarifas totales
 *de cada uno de los viajes. Sumándolo con los resultados anteriores.
 */
double AgenciaTransporte::calc_ingreso_total(){
    double ingreso_total = 0;
    for (int i = 0; i < num_viajes; i ++){
        ingreso_total = ingreso_total + viaj[i] -> calc_tarifa_total();
        //cout << "viaje " << i << ": " << viaj[i] -> calc_tarifa_total() << endl;
    }
    return ingreso_total;
}

/**
 *calc_ingreso_total(string) representa el ingreso generado por un tipo específico de objetos.
 *
 *Se utiliza el arreglo de viaj[] y el número de viajes para poder
 *recorrer todo el arreglo y guardar el valor de precio de las tarifas totales
 *de cada uno de los viajes. Sumándolo con los resultados anteriores.
 */
double AgenciaTransporte::calc_ingreso_total(string tipo){

    double ingreso_total = 0;
    for (int i = 0; i < num_viajes; i++){
        if(viaj[i] -> get_tipo() == tipo)
            ingreso_total = ingreso_total + viaj[i] -> calc_tarifa_total();
    }
    return ingreso_total;
}

//Agregar objetos

/**
 *agrega_taxi_local crea un objeto TaxiLocal y lo agrega al arreglo viaj[]
 *
 *Se utiliza como indice el número de viajes y este aumenta en 1 cada vez que se crea un nuevo objeto
 */
void AgenciaTransporte::agrega_taxi_local(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu){
    viaj[num_viajes] = new TaxiLocal(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, horario_concu);
    num_viajes++;
}

/**
 *agrega_taxi_interurbano crea un objeto TaxiInterurbano y lo agrega al arreglo viaj[]
 *
 *Se utiliza como indice el número de viajes y este aumenta en 1 cada vez que se crea un nuevo objeto
 */
void AgenciaTransporte::agrega_taxi_interurbano(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip){
    viaj[num_viajes] = new TaxiInterurbano(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, num_pas, cant_equip);
    num_viajes++;
}

/**
 *agrega_flete crea un objeto Flete y lo agrega al arreglo viaj[]
 *
 *Se utiliza como indice el número de viajes y este aumenta en 1 cada vez que se crea un nuevo objeto
 */
void AgenciaTransporte::agrega_flete(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car){
    viaj[num_viajes] = new Flete(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, peso_car);
    num_viajes++;
}

#endif // AGENCIATRANSPORTE_H_
