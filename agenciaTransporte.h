/*
 *
 *Proyecto Agencia de Transporte clase AgenciaTransporte
 *Iván Ricardo Paredes Avilez
 *A01705083
 *16/06/2022
 *Version: 3
 *Esta clase define el objeto AgenciaTransporte que contiene las operaciones
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
const int arreglos_max = 1000;

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

        //Getters
        int get_num_viajes(){return num_viajes;}
};

//Funciones de la clase AgenciaTransporte

/**
 *crea_ejemplos genera objetos de tipo TaxiLocal, TaxiInterurbano y Flete.
 *Estos se guardan en el arreglo viaj[] con el fin de hacer pruebas.
 *Por la misma razón estos datos deben ser considerados como
 *viajes ficticios.
 *
 *@param No se tienen parámetros
 *
 *@return No se devuelve ningún valor
 */
void AgenciaTransporte::crea_ejemplos() {

    viaj[num_viajes] = new TaxiLocal(1, "Taxi local", "Juriquilla", "El Refugio", 17, 6.3, false);
    num_viajes++;
    viaj[num_viajes] = new TaxiLocal(2, "Taxi local", "El pueblito", "Plaza Puerta La Victoria", 9.1, 5.9, true);
    num_viajes++;
    viaj[num_viajes] = new TaxiInterurbano(3, "Taxi interurbano", "Queretaro", "Ciudad de Mexico", 213, 7, 2, 2);
    num_viajes++;
    viaj[num_viajes] = new TaxiInterurbano(4, "Taxi interurbano", "Queretaro", "Leon GTO", 169, 7.1, 3, 3);
    num_viajes++;
    viaj[num_viajes] = new Flete(5, "Flete", "El marques", "San Miguel de Allende", 70, 12, 560.5);
    num_viajes++;
    viaj[num_viajes] = new Flete(6, "Flete", "Corregidora", "Tequisquiapan", 73, 13, 412.4);
    num_viajes++;
}

/**
 *muestra_viajes imprime la información de los viajes
 *
 *Se utiliza el arreglo de viaj[] y el número de viajes para poder
 *recorrer todo el arreglo e imprimir la información de cada uno
 *de los objetos que están dentro de él con sus propios métodos de
 *mostrar_viaje
 *
 *@param No se tienen parámetros
 *
 *@return No se devuelve ningún valor
 */
void AgenciaTransporte::muestra_viajes(){
    //Ciclo que recorre toda la lista de viajes
    for (int i = 0; i < num_viajes; i++){
        viaj[i] -> mostrar_viaje();
    }
    cout << endl;
}

/**
 *muestra_viajes(string) imprime la información de un tipo
 *específico de objetos
 *
 *Se utiliza el arreglo de viaj[] y el número de viajes para poder
 *recorrer todo el arreglo e imprimir la información de cada uno
 *de los objetos que están dentro de él y que coinciden con el tipo
 *
 *@param string tipo debe ser: "Taxi local", "Taxi interurbano"
 *o "Flete".
 *
 *@return No se devuelve ningún valor
 */
void AgenciaTransporte::muestra_viajes(string tipo){
    //Ciclo que recorre toda la lista de viajes en busca 
    //de cierto tipo de viaje en especial
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
 *recorrer todo el arreglo y guardar el valor de precio de las
 *tarifas totales de cada uno de los viajes, sumándolo con los
 *resultados anteriores.
 *
 *@param No se tienen parámetros
 *
 *@return double con la suma de todos los ingresos de la agencia
 */
double AgenciaTransporte::calc_ingreso_total(){
    double ingreso_total = 0;
    for (int i = 0; i < num_viajes; i ++){
        ingreso_total = ingreso_total + viaj[i] -> calc_tarifa_total();
    }
    return ingreso_total;
}

/**
 *calc_ingreso_total(string) representa el ingreso generado por un
 *tipo específico de objetos.
 *
 *Se utiliza el arreglo de viaj[] y el número de viajes para poder
 *recorrer todo el arreglo y guardar el valor de precio de las tarifas
 *totales de cada uno de los viajes. Sumándolo con los resultados
 *anteriores.
 *
 *@param string tipo debe ser: "Taxi local", "Taxi interurbano"
 *o "Flete".
 *
 *@return double con la suma de todos los ingresos del tipo de viaje
 */
double AgenciaTransporte::calc_ingreso_total(string tipo){
    double ingreso_total = 0;
    for (int i = 0; i < num_viajes; i++){
        if(viaj[i] -> get_tipo() == tipo){
            ingreso_total = ingreso_total + (viaj[i] -> calc_tarifa_total());
        }
    }
    return ingreso_total;
}

//Agregar objetos

/**
 *agrega_taxi_local crea un objeto TaxiLocal y lo agrega al
 *arreglo viaj[]
 *
 *Se utiliza como indice el número de viajes y este aumenta en 1
 *cada vez que se crea un nuevo objeto
 *
 *@param int i_d: número de identificación,
 *string tipo_viaje: tipo de viaje,
 *string direccion_o: direccion de orígen,
 *string direccion_d: direccion de detino,
 *double km: kilómetros recorridos
 *double tarifa_km: tarifa por kilómetro recorrido,
 *bool horario_concu: horario concurrido como true o false
 *
 *@return No se devuelve ningún valor
 */
void AgenciaTransporte::agrega_taxi_local(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu){
    viaj[num_viajes] = new TaxiLocal(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, horario_concu);
    num_viajes++;
}

/**
 *agrega_taxi_interurbano crea un objeto TaxiInterurbano y lo
 *agrega al arreglo viaj[]
 *
 *Se utiliza como indice el número de viajes y este aumenta en 1
 *cada vez que se crea un nuevo objeto
 *
 *@param int i_d: número de identificación,
 *string tipo_viaje: tipo de viaje,
 *string direccion_o: direccion de orígen,
 *string direccion_d: direccion de detino,
 *double km: kilómetros recorridos
 *double tarifa_km: tarifa por kilómetro recorrido,
 *int num_pas: número de pasajeros
 *int cant_equip: número de maletas
 *
 *@return No se devuelve ningún valor
 */
void AgenciaTransporte::agrega_taxi_interurbano(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip){
    viaj[num_viajes] = new TaxiInterurbano(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, num_pas, cant_equip);
    num_viajes++;
}

/**
 *agrega_flete crea un objeto Flete y lo agrega al arreglo viaj[]
 *
 *Se utiliza como indice el número de viajes y este aumenta en 1
 *cada vez que se crea un nuevo objeto
 *
 *@param int i_d: número de identificación,
 *string tipo_viaje: tipo de viaje,
 *string direccion_o: direccion de orígen,
 *string direccion_d: direccion de detino,
 *double km: kilómetros recorridos
 *double tarifa_km: tarifa por kilómetro recorrido,
 *peso_car: peso total de carga
 *
 *@return No se devuelve ningún valor
 */
void AgenciaTransporte::agrega_flete(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car){
    viaj[num_viajes] = new Flete(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, peso_car);
    num_viajes++;
}

#endif // AGENCIATRANSPORTE_H
