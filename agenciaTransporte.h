//Iván Ricardo Paredes Avilez A01705083
//03/06/2022
//agenciaTransporte.h
//Version 1

#ifndef AGENCIATRANSPORTE_H_
#define AGENCIATRANSPORTE_H_

#include <iostream>
#include "viaje.h" //importamos la clase de viaje

using namespace std;

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
        void agrega_taxi_local(string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu);
        void agrega_taxi_interurbano(string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip);
        void agrega_flete(string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car);
};


//Generación de objetos como ejemplo
void AgenciaTransporte::crea_ejemplos() {

    viaj[num_viajes] = new TaxiLocal(1, "Taxi local", "Juriquilla", "El Refugio", 17, 6.3, false);
    num_viajes++;
    viaj[num_viajes] = new TaxiLocal(2, "Taxi local", "El pueblito", "Plaza Puerta La Victoria", 9.1, 5.9, true);
    num_viajes++;
    viaj[num_viajes] = new TaxiInterurbano(3, "Taxi interurbano", "Querétaro", "Ciudad de México", 213, 7, 2, 2);
    num_viajes++;
    viaj[num_viajes] = new TaxiInterurbano(4, "Taxi interurbano", "Querétaro", "León GTO", 169, 7.1, 3, 3);
    num_viajes++;
    viaj[num_viajes] = new Flete(5, "Flete", "El marqués", "San Miguel de Allende", 70, 12, 560.5);
    num_viajes++;
    viaj[num_viajes] = new Flete(6, "Flete", "Corregidora", "", 70, 12, 560.5);
    num_viajes++;
}


//Funciones de la clase AgenciaTransporte
void AgenciaTransporte::muestra_viajes(){

    //Ciclo que recorre toda la lista de viajes
    for (int i = 0; i < num_viajes; i++){
        int i_d = viaj[i] -> get_id();
        string tipo_viaje = viaj[i] -> get_tipo();
        string direccion_o = viaj[i] -> get_direccion_origen();
        string direccion_d = viaj[i] -> get_direccion_destino();
        double km = viaj[i] -> get_kilometros();
        double tarifa_km = viaj[i] -> get_tarifa_kilometros();
        viaj[i] -> mostrar_viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km);
    }
}

void AgenciaTransporte::muestra_viajes(string tipo){
    //Ciclo que recorre toda la lista de viajes en busca de cierto tipo de viaje en especial
    for (int i = 0; i < num_viajes; i++){
        int i_d = viaj[i] -> get_id();
        string tipo_viaje = viaj[i] -> get_tipo();
        string direccion_o = viaj[i] -> get_direccion_origen();
        string direccion_d = viaj[i] -> get_direccion_destino();
        double km = viaj[i] -> get_kilometros();
        double tarifa_km = viaj[i] -> get_tarifa_kilometros();
        if(viaj[i] -> get_tipo() == tipo){
            viaj[i] -> mostrar_viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km);
        }
    }
}

/**Funciones aun no terminadas
double AgenciaTransporte::calc_ingreso_total(){

    double ingreso_total = 0;
    for (int i = 0; i < num_viajes; i ++)
        ingreso_total = ingreso_total + viaj[i] -> calc_tarifa_total();
    return ingreso_total;
}

double AgenciaTransporte::calc_ingreso_total(string tipo){

    double ingreso_total = 0;
    for (int i = 0; i < num_viajes; i++){
        if(viaj[i] -> get_tipo() == tipo)
            ingreso_total = ingreso_total + viaj[i] -> calc_tarifa_total();
    }
    return ingreso_total
}


//Funciones para agregar objetos
void AgenciaTransporte::agrega_taxi_local(string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu){
    viaj[num_viajes] = new TaxiLocal(direccion_o, direccion_d, km, tarifa_km, horario_concu);
    num_viajes++;
}

void AgenciaTransporte::agrega_taxi_interurbano(string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip){
    viaj[num_viajes] = new TaxiInterurbano(string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip);
    num_viajes++;
}

void AgenciaTransporte::agrega_flete(string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car){
    viaj[num_viajes] = new Flete(string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car);
    num_viajes++;
}
**/

#endif // AGENCIATRANSPORTE_H_
