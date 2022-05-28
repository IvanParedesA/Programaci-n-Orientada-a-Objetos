//Iván Ricardo Paredes Avilez A01705083
//27/05/2022
//viaje.h


#ifndef VIAJE_H_
#define VIAJE_H_

#include <iostream>

using namespace std;

//Se declara la clase abstracta de viaje
class Viaje {

    //Se declaran los atributos del objeto
    private:

        int id;
        string tipo;
        string direccion_origen;
        string direccion_destino;
        double kilometros;
        double tarifa_kilometros;

    //Se declaran los métodos del objeto
    public:

        //Constructores
        Viaje(): id(0), tipo(""), direccion_origen(""), direccion_destino(""), kilometros(0), tarifa_kilometros(0) {}; //constructor default
        Viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km);

        //Funciones de la clase
        double calc_tarifa_por_km(double kilometros, double tarifa_kilometros);
        void mostrar_tarifa_por_km(double kilometros, double tarifa_kilometros);
        double calc_tarifa_total(double kilometros, double tarifa_kilometros);

        //Getters
        int get_id() {return id;}
        string get_tipo() {return tipo;}
        string get_direccion_origen() {return direccion_origen;}
        string get_direccion_destino() {return direccion_destino;}
        double get_kilometros() {return kilometros;}
        double get_tarifa_kilometros() {return tarifa_kilometros;}

        //Setters
        void set_id(int i_d);
        void set_tipo(string tipo_viaje);
        void set_direccion_origen(string direccion_o);
        void set_direccion_destino(string direccion_d);
        void set_kilometros(double km);
        void set_tarifa_kilometros(double tarifa_km);
};

//Constructor
Viaje::Viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km){
    id = i_d;
    tipo = tipo_viaje;
    direccion_origen = direccion_o;
    direccion_destino = direccion_d;
    kilometros = km;
    tarifa_kilometros = tarifa_km
}

//Funciones de la clase
double Viaje::calc_tarifa_por_km(double kilometros, double tarifa_por_km){
    tarifa = kilometros*tarifa_por_km;
    return tarifa;
}

void Viaje::mostrar_tarifa_por_km(double kilometros, double tarifa_kilometros){
    cout << "La suma de la tarifa por kilómetros recorridos es de: " << calc_tarifa_por_km(double kilometros, double tarifa_por_km) << endl;
}

double Viaje::calc_tarifa_total(double kilometros, double tarifa_kilometros){
    tarifa = kilometros*tarifa_por_km;
    return tarifa;
}

void Viaje::mostrar_tarifa_total(double kilometros, double tarifa_kilometros, id){
    cout << "La tarifa total del viaje " << id << " fue de: " << calc_tarifa_total(double kilometros, double tarifa_kilometros) << endl;
}

//Setters
void Viaje::set_id(int i_d){
    id = i_d;
}

void Viaje::set_tipo(string tipo_viaje){
    tipo = tipo_viaje;
}

void Viaje::set_direccion_origen(string direccion_o){
    direccion_origen = direccion_o;
}

void Viaje::set_direccion_destino(string direccion_d){
    direccion_destino = direccion_d;
}

void Viaje::set_kilometros(double km){
    kilometros = km;
}

void Viaje::set_tarifa_kilometros(double tarifa_km){
    tarifa_kilometros = tarifa_km;
}

//Clase TaxiLocal que es heredada de la clase Viaje
class TaxiLocal : public Viaje{

    //Atributos
    private:
        bool horario_concurrido;

    //Métodos
    public:
        //Constructor
        TaxiLocal(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu):Viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km){
            bool horario_concurrido = horario_concu;
        }
        //Funciones
        double calc_tarifa_hora_concurrida(bool horario_concurrido, double tarifa_kilometros);
        void mostrar_tarifa_por_hora_concurrida(bool horario_concurrido, double tarifa_kilometros);
        //Getters
        bool get_horario_concurrido(){return horario_concurrido;}
        //Setters
        void set_horario_concurrido(bool horario_concu);
};

//Funciones de la clase TaxiLocal
double TaxiLocal::calc_tarifa_hora_concurrida(bool horario_concurrido, double tarifa_kilometros){
    if (horario_concurrido == True)
        tarifa = 2*tarifa_kilometros;
        return tarifa;
    else
        return tarifa_kilometros;
}

void TaxiLocal::mostrar_tarifa_por_hora_concurrida(bool horario_concurrido, double tarifa_kilometros){
    cout << "La tarifa por kilómetro según la hora (concurrida o no) es de: " << calc_tarifa_hora_concurrida(bool horario_concurrido, double tarifa_kilometros);
}

double TaxiLocal::calc_tarifa_total(double kilometros, double tarifa_kilometros, bool horario_concurrido){
    tarifa = kilometros*calc_tarifa_hora_concurrida(bool horario concurrido, double tarifa_kilometros);
    return tarifa;
}

void TaxiLocal::mostrar_tarifa_total(double kilometros, double tarifa_kilometros, double tarifa_hora_concurrida, id){
    cout << "La tarifa total del viaje " << id << " fue de: " << calc_tarifa_total(double kilometros, double tarifa_kilometros, double tarifa_hora_concurrida) << endl;
}

//Setters
void TaxiLocal::set_horario_concurrido(bool horario_concu){
    horario_concurrido = horario_concu;
}

//Clase TaxiInterurbano que es heredada de Viaje
class TaxiInterurbano : public Viaje{

    //Atributos
    private:
        int num_pasajeros;
        int cant_equipaje;

    //Métodos
    public:
        //Constructor
        TaxiInterurbano(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip):Viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km){
            int num_pasajeros = num_pas;
            int cant_equipaje = cant_equip;
        }
        //Funciones
        double calc_tarifa_por_pasajero(double tarifa_kilometros, int num_pasajeros);
        void mostrar_tarifa_por_pasajero(double tarifa_kilometros, int num_pasajeros, int id);
        double calc_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje, int id);
        void mostrar_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje, int id);
        //Getters
        int get_num_pasajeros(){return num_pasajeros;}
        int get_cant_equipaje(){return cant_equipaje;}
        //Setters
        void set_num_pasajeros(int num_pas);
        void set_cant_equipaje(int cant_equip);
};

//Funciones de la clase TaxiInterurbano
double TaxiInterurbano::calc_tarifa_por_pasajero(double tarifa_kilometros, int num_pasajeros){
    if (num_pasajeros == 1)
        return tarifa_kilometros;
    else
        tarifa = tarifa_kilometros*(num_pasajeros*0.25);
        return tarifa;
}

void TaxiInterurbano::mostrar_tarifa_por_pasajero(double tarifa_kilometros, int num_pasajeros, int id){
    cout << "La tarifa aplicada por número pasajeros en el viaje " << id << " fue de: " << 100*calc_tarifa_por_pasajero(double tarifa_kilometros, int num_pasajeros) << "%" << endl;
}

double TaxiInterurbano::calc_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje){
    tarifa = tarifa_kilometros*(cant_equipaje*0.5);
    return tarifa;
}

void TaxiInterurbano::mostrar_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje, int id){
    cout << "La tarifa aplicada por cantidad de equipaje en el viaje " << id << " fue de " << 100*calc_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje) << "%" << endl;
}

double TaxiInterurbano::calc_tarifa_total(double kilometros, double tarifa_kilometros, int cant_equipaje, int num_pasajeros){
    tarifa = kilometros*(tarifa_kilometros*(calc_tarifa_por_pasajero(double tarifa_kilometros, int num_pasajeros) + calc_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje)))
    return tarifa;
}

void TaxiInterurbano::mostrar_tarifa_total(double kilometros, double tarifa_kilometros, int cant_equipaje, int num_pasajeros, id){
    cout << "La tarifa total del viaje " << id << " fue de: " << calc_tarifa_total(double kilometros, double tarifa_kilometros, int cant_equipaje, int num_pasajeros) << endl;
}

//Setters
void TaxiInterurbano::set_num_pasajeros(int num_pas){
    num_pasajeros = num_pas;
}

void TaxiInterurbano::set_cant_equipaje(int cant_equip){
    cant_equipaje = cant_equip;
}

//Clase Flete que es heredada de Viaje
class Flete : public Viaje{

    //Atributos
    private:
        double peso_carga;

    //Métodos
    public:
        //Constructor
        Flete(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car):Viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km){
            double peso_carga = peso_car;
        }
        //Funciones
        double calc_tarifa_por_peso(double tarifa_kilometros, double peso_carga);
        void mostrar_tarifa_por_peso(double tarifa_kilometros, double peso_carga, int id);
        //Getter
        double get_peso_carga(){return peso_carga;}
        //Setter
        void set_peso_carga(double peso_car);
};

double Flete::calc_tarifa_por_peso(double tarifa_kilometros, double peso_carga){
    if ((peso_carga-200) <= 0)
        return tarifa_kilometros;
    else
        tarifa = tarifa_kilometros*(1+((peso_carga/200)*0.25));
        return tarifa;
}

void Flete::mostrar_tarifa_por_peso(double tarifa_kilometros, double peso_carga, int id){
    cout << "La tarifa aplicada por peso para el viaje " << id << " fue de " calc_tarifa_por_peso(double tarifa_kilometros, double peso_carga) << endl;
}

double Flete::calc_tarifa_total(double kilometros, double tarifa_kilometros, double peso_carga){
    tarifa = kilometros*calc_tarifa_por_peso(double tarifa_kilometros, double peso_carga);
    return tarifa;
}

void Flete::mostrar_tarifa_total(double kilometros, double tarifa_kilometros, double peso_carga, int id){
    cout << "La tarifa total para el viaje " << id << " fue de " calc_tarifa_total(double kilometros, double tarifa_kilometros, double peso_carga) << endl;
}

//Setters
void Flete::void set_peso_carga(double peso_car){
    peso_carga = peso_car;
}

#endif // VIAJE_H_
