/*
 *
 *Proyecto Agencia de Transporte clase Viajes
 *Iván Ricardo Paredes Avilez
 *A01705083
 *10/06/2022
 *Version: 3
 *Esta clase define el objeto Viaje que contiene las clases heredadas
 *TaxiLocal, TaxiInterurbano y Flete
 */

#ifndef VIAJE_H_
#define VIAJE_H_

//Nos permite imprimir
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

        //Constructor Default
        Viaje(): id(0), tipo(""), direccion_origen(""), direccion_destino(""), kilometros(0), tarifa_kilometros(0) {};
        //Constructor
        Viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km);

        //Funciones de la clase
        double calc_tarifa_por_km();
        void mostrar_tarifa_por_km();
        virtual double calc_tarifa_total() = 0;
        virtual void mostrar_tarifa_total() = 0;
        virtual void mostrar_viaje() = 0;

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
    tarifa_kilometros = tarifa_km;
}

//Funciones de la clase

/**
 *calc_tarifa_por_km calcula la tarifa por la cantidad de kilometros recorridos.
 *
 *toma la cantidad de kilometros recorridos y los multiplica por la cuota que se tiene por cada kilómetro
 */
double Viaje::calc_tarifa_por_km(){
    double tarifa = get_kilometros()*get_tarifa_kilometros();
    return tarifa;
}

/**
 *mostrar_tarifa_por_km muestra la tarifa por la cantidad de kilometros recorridos.
 *
 *crea una salida de texto donde también se manda a llamar a la función calc_tarifa_por_km
 */
void Viaje::mostrar_tarifa_por_km(){
    cout << "La suma de la tarifa por kilómetros recorridos es de: " << calc_tarifa_por_km() << endl;
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
class TaxiLocal: public Viaje{

    //Atributos de la clase TaxiLocal
    private:
        bool horario_concurrido;

    //Métodos de la clase TaxiLocal
    public:
        //Constructor Default
        TaxiLocal(): Viaje(){
            horario_concurrido = false;
        };
        //Constructor
        TaxiLocal(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu):Viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km){
            bool horario_concurrido = horario_concu;
        }

        //Funciones
        double calc_tarifa_hora_concurrida();
        void mostrar_tarifa_por_hora_concurrida();
        double calc_tarifa_total();
        void mostrar_tarifa_total();
        void mostrar_viaje();

        //Getters
        bool get_horario_concurrido(){return horario_concurrido;}

        //Setters
        void set_horario_concurrido(bool horario_concu);
};

//Funciones de la clase TaxiLocal
/**
 *calc_tarifa_hora_concurrida calcula la tarifa por km en caso de que el viaje se haya realizado o no en un horario concurrido.
 *
 *en caso de que se esté en un horario concurrido la tarifa por kilometro es del doble de precio.
 */
double TaxiLocal::calc_tarifa_hora_concurrida(){
    if (get_horario_concurrido() == true){
        return (2*get_tarifa_kilometros());
    }
    else{
        return (get_tarifa_kilometros());
    }
}

/**
 *mostrar_tarifa_por_hora_concurrida muestra la tarifa por km en caso de que el viaje se haya realizado o no en un horario concurrido
 *
 *crea una salida de texto donde también se manda a llamar a la función calc_tarifa_hora_concurrida
 */
void TaxiLocal::mostrar_tarifa_por_hora_concurrida(){
    if (get_horario_concurrido() == true){
        cout << "La tarifa por kilómetro según la saturación del servicio es de: " << calc_tarifa_hora_concurrida();
    }
    else{
        cout << "La tarifa por kilómetro según la saturación del servicio es de: " << calc_tarifa_hora_concurrida();
    }
}

/**
 *calc_tarifa_total calcula el costo total del viaje
 *
 *Se obtiene la tarifa por kilometro dependiendo del horario con la función calc_tarifa_hora_concurrida() y se multiplica por el total de kilometros
 */
double TaxiLocal::calc_tarifa_total(){
    return (calc_tarifa_hora_concurrida()*get_kilometros());
}

/**
 *mostrar_tarifa_total muestra el costo total del viaje
 *
 *crea una salida de texto donde también se manda a llamar a la función calc_tarifa_total
 */
void TaxiLocal::mostrar_tarifa_total(){
    cout << "La tarifa total del viaje " << get_id() << " fue de: " << calc_tarifa_total() << endl;
}

/**
 *mostrar_viaje muestra las características del viaje en cuestión
 *
 *crea una salida de texto donde también se utilizan getters para obtener los atributos del objeto,
 *pero también manda a llamar a la función calc_tarifa_hora_concurrida para mostrar la tarifa por kilometro
 */
void TaxiLocal::mostrar_viaje(){
    if (get_horario_concurrido() == true){
        cout << "El viaje en " << get_tipo() << " con id " << get_id() << " si se encuentra en un horario concurrido. Tiene una tarifa de " << calc_tarifa_hora_concurrida() << " pesos por kilometro y va desde " << get_direccion_origen() << " hasta " << get_direccion_destino() << " (" << get_kilometros() << " km) " << endl;
    }
    else{
        cout << "El viaje en " << get_tipo() << " con id " << get_id() << " no se encuentra en un horario concurrido. Tiene una tarifa de " << calc_tarifa_hora_concurrida() << " pesos por kilometro y va desde " << get_direccion_origen() << " hasta " << get_direccion_destino() << " (" << get_kilometros() << " km) " << endl;
    }
}

//Setters
void TaxiLocal::set_horario_concurrido(bool horario_concu){
    horario_concurrido = horario_concu;
}

//Clase TaxiInterurbano que es heredada de Viaje
class TaxiInterurbano: public Viaje{

    //Atributos
    private:
        int num_pasajeros;
        int cant_equipaje;

    //Métodos
    public:
        //Constructor Default
        TaxiInterurbano(): Viaje(){
            num_pasajeros = 0;
            cant_equipaje = 0;
        };
        //Constructor
        TaxiInterurbano(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip):Viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km){
            int num_pasajeros = num_pas;
            int cant_equipaje = cant_equip;
        }

        //Funciones
        double calc_tarifa_por_pasajero();
        void mostrar_tarifa_por_pasajero();
        double calc_tarifa_por_equipaje();
        void mostrar_tarifa_por_equipaje();
        double calc_tarifa_total();
        void mostrar_tarifa_total();
        void mostrar_viaje();

        //Getters
        int get_num_pasajeros(){return num_pasajeros;}
        int get_cant_equipaje(){return cant_equipaje;}

        //Setters
        void set_num_pasajeros(int num_pas);
        void set_cant_equipaje(int cant_equip);
};

//Funciones de la clase TaxiInterurbano

/**
 *calc_tarifa_por_pasajero calcula el aumento porcentual que debe hacerse a la tarifa por kilometro dependiendo del numero de pasajeros
 *
 *el número de pasajeros se multiplica por 0.25, porque cada uno involucra un aumento del 25% en el precio
 */
double TaxiInterurbano::calc_tarifa_por_pasajero(){
    if (get_num_pasajeros() == 1){
        return get_tarifa_kilometros();
    }
    else{
        return ((get_num_pasajeros()*0.25));
    }
}

/**
 *mostrar_tarifa_por_pasajero muestra el aumento añadido a la tarifa por kilometros debido al numero de pasajeros
 *
 *crea una salida de texto donde también se manda a llamar a la función calc_tarifa_por_pasajero
 */
void TaxiInterurbano::mostrar_tarifa_por_pasajero(){
    cout << "La tarifa aplicada por número pasajeros en el viaje " << get_id() << " fue de: " << calc_tarifa_por_pasajero() << "%" << endl;
    }

/**
 *calc_tarifa_por_equipaje calcula el aumento porcentual que debe hacerse a la tarifa por kilometro dependiendo de la cantidad de equipaje
 *
 *La cantidad de equipaje se multiplica por 0.05, porque cada uno involucra un aumento del 5% en el precio
 */
double TaxiInterurbano::calc_tarifa_por_equipaje(){
    return ((get_cant_equipaje()*0.05));
}

/**
 *mostrar_tarifa_por_equipaje muestra el aumento añadido a la tarifa por kilometros debido a la cantidad de equipaje
 *
 *crea una salida de texto donde también se manda a llamar a la función calc_tarifa_por_equipaje
 */
void TaxiInterurbano::mostrar_tarifa_por_equipaje(){
    cout << "La tarifa aplicada por cantidad de equipaje en el viaje " << get_id() << " fue de " << calc_tarifa_por_equipaje() << "%" << endl;
}

/**
 *calc_tarifa_total calcula el costo total del viaje
 *
 *Se suman los porcentajes añadidos y se multiplica tanto por la tarifa por kilometro como por el total de kilometros
 */
double TaxiInterurbano::calc_tarifa_total(){
    return ((calc_tarifa_por_equipaje() + calc_tarifa_por_pasajero() + 1)*get_tarifa_kilometros()*get_kilometros());
}

/**
 *mostrar_tarifa_total muestra la tarifa final debido a la cantidad de equipaje y el numero de pasajeros
 *
 *crea una salida de texto donde también se manda a llamar a la función calc_tarifa_total
 */
void TaxiInterurbano::mostrar_tarifa_total(){
    cout << "La tarifa total del viaje " << get_id() << " fue de: " << calc_tarifa_total() << endl;
}

/**
 *mostrar_viaje muestra las características del viaje en cuestión
 *
 *crea una salida de texto donde también se utilizan getters para obtener los atributos del objeto,
 */
void TaxiInterurbano::mostrar_viaje(){
    cout << "El viaje en " << get_tipo() << " con id " << get_id() << " tiene " << get_num_pasajeros() << " pasajeros con " << get_cant_equipaje() << " maletas. Ademas, tiene una tarifa de " << get_tarifa_kilometros() << " pesos por kilometro y va desde " << get_direccion_origen() << " hasta " << get_direccion_destino() << " (" << get_kilometros() << " km) " << endl;
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
        //Constructor Default
        Flete(): Viaje(){
            peso_carga = 0;
        };
        //Constructor
        Flete(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car):Viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km){
            double peso_carga = peso_car;
        }
        //Funciones
        double calc_tarifa_por_peso();
        void mostrar_tarifa_por_peso();
        double calc_tarifa_total();
        void mostrar_tarifa_total();
        void mostrar_viaje();
        //Getter
        double get_peso_carga(){return peso_carga;}
        //Setter
        void set_peso_carga(double peso_car);
};

//Funciones

/**
 *calc_tarifa_por_peso calcula el aumento porcentual que debe hacerse a la tarifa por kilometro dependiendo de la cantidad de peso
 *
 *El peso se divide entre 200 porque es cada 200kg que aumenta 25% la cuota.
 */
double Flete::calc_tarifa_por_peso(){
    if ((get_peso_carga()-200) <= 0){
        return get_tarifa_kilometros();
    }
    else{
        return ((get_peso_carga()/200)*0.25);
    }
}

/**
 *mostrar_tarifa_por_peso muestra el aumento añadido a la tarifa por kilometros debido a la cantidad de peso
 *
 *crea una salida de texto donde también se manda a llamar a la función calc_tarifa_por_peso
 */
void Flete::mostrar_tarifa_por_peso(){
    cout << "La tarifa aplicada por peso para el viaje " << get_id() << " fue de " << calc_tarifa_por_peso() << endl;
}

/**
 *calc_tarifa_total calcula el costo total del viaje
 *
 *Se añaden los porcentajes y se multiplica tanto por la tarifa por kilometro como por el total de kilometros
 */
double Flete::calc_tarifa_total(){
    return (get_kilometros()*get_tarifa_kilometros()*(1+calc_tarifa_por_peso()));
}

/**
 *mostrar_tarifa_total muestra la tarifa final debido a la cantidad de equipaje peso y kilometros
 *
 *crea una salida de texto donde también se manda a llamar a la función calc_tarifa_total
 */
void Flete::mostrar_tarifa_total(){
    cout << "La tarifa total para el viaje " << get_id() << " fue de " << calc_tarifa_total() << endl;
}

/**
 *mostrar_viaje muestra las características del viaje en cuestión
 *
 *crea una salida de texto donde también se utilizan getters para obtener los atributos del objeto,
 */
void Flete::mostrar_viaje(){
    cout << "El " << get_tipo() << " con id " << get_id() << " tiene una tarifa de " << get_tarifa_kilometros() << " pesos por kilometro y va desde " << get_direccion_origen() << " hasta " << get_direccion_destino() << " (" << get_kilometros()<< " km) " << endl;
}

//Setters
void Flete::set_peso_carga(double peso_car){
    peso_carga = peso_car;
}

#endif // VIAJE_H_
