//Iván Ricardo Paredes Avilez A01705083
//03/06/2022
//viaje.h
//Versión 2

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
        virtual double calc_tarifa_total(double kilometros, double tarifa_kilometros);
        virtual void mostrar_tarifa_total(double kilometros, double tarifa_kilometros, int id);
        virtual void mostrar_viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km);

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
double Viaje::calc_tarifa_por_km(double kilometros, double tarifa_por_km){
    double tarifa = kilometros*tarifa_por_km;
    return tarifa;
}

void Viaje::mostrar_tarifa_por_km(double kilometros, double tarifa_por_km){
    double tarifa = kilometros*tarifa_por_km;
    cout << "La suma de la tarifa por kilómetros recorridos es de: " << tarifa << endl;
}

//Funciones que existian en la version anterior (solo por si se volvieran a usar después)
double Viaje::calc_tarifa_total(double kilometros, double tarifa_kilometros){
    double tarifa = kilometros*tarifa_kilometros;
    return tarifa;
}

void Viaje::mostrar_tarifa_total(double kilometros, double tarifa_kilometros, int id){
    cout << "La tarifa total del viaje " << id << " fue de: " << calc_tarifa_total(kilometros, tarifa_kilometros) << endl;
}

void Viaje::mostrar_viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km){
    cout << "El viaje con id " << id << " tiene una tarifa de " << tarifa_km << " pesos por kilometro y va desde " << direccion_o << " hasta " << direccion_d << " (" << km << ") " << endl;
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
        //Constructor
            TaxiLocal(): Viaje(0, "Taxi local", "Direccion de origen", "Direccion de destino", 0, 0) {};
        TaxiLocal(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu):Viaje(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km){
            bool horario_concurrido = horario_concu;
        }
        //Funciones
        double calc_tarifa_hora_concurrida(bool horario_concurrido, double tarifa_kilometros);
        void mostrar_tarifa_por_hora_concurrida(bool horario_concurrido, double tarifa_kilometros);
        void mostrar_viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu);
        double calc_tarifa_total(double kilometros, double tarifa_kilometros, bool horario_concurrido);
        void mostrar_tarifa_total(double kilometros, double tarifa_kilometros, double tarifa_hora_concurrida, int id);
        //Getters
        bool get_horario_concurrido(){return horario_concurrido;}
        //Setters
        void set_horario_concurrido(bool horario_concu);
};

//Funciones de la clase TaxiLocal
double TaxiLocal::calc_tarifa_hora_concurrida(bool horario_concurrido, double tarifa_kilometros){
    double tarifa = 0;
    if (horario_concurrido == true){
        tarifa = 2*tarifa_kilometros;
        return tarifa;
    }
    else{
        return tarifa_kilometros;
    }
}

void TaxiLocal::mostrar_tarifa_por_hora_concurrida(bool horario_concurrido, double tarifa_kilometros){
    double tarifa = 0;
    if (horario_concurrido == true){
        tarifa = 2*tarifa_kilometros;
        cout << "La tarifa por kilómetro según la saturación del servicio es de: " << tarifa;
    }
    else{
        cout << "La tarifa por kilómetro según la saturación del servicio es de: " << tarifa_kilometros;
    }
}

double TaxiLocal::calc_tarifa_total(double kilometros, double tarifa_kilometros, bool horario_concurrido){
    double tarifa = 0;
    if (horario_concurrido == true){
        tarifa = 2*tarifa_kilometros;
        tarifa = tarifa * kilometros;
        return tarifa;
    }
    else{
        tarifa = tarifa * kilometros;
        return tarifa;
    }
}

void TaxiLocal::mostrar_tarifa_total(double kilometros, double tarifa_kilometros, double tarifa_hora_concurrida, int id){
    double tarifa = 0;
    if (horario_concurrido == true){
        tarifa = 2*tarifa_kilometros;
        tarifa = tarifa * kilometros;
        cout << "La tarifa total del viaje " << id << " fue de: " << tarifa << endl;
    }
    else{
        tarifa = tarifa * kilometros;
        cout << "La tarifa total del viaje " << id << " fue de: " << tarifa << endl;
    }
}

void TaxiLocal::mostrar_viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, bool horario_concu){
    if (horario_concu == false){
        cout << "El viaje en " << tipo_viaje << " con id " << get_id() << "no se encuentra en un horario concurrido. Tiene una tarifa de " << tarifa_km << " pesos por kilometro y va desde " << direccion_o << " hasta " << direccion_d << " (" << km << ") " << endl;
    }
    else{
        double tarifa = 0;
        if (horario_concurrido == true){
            tarifa = 2*tarifa_km;
            cout << "El viaje en " << tipo_viaje << " con id " << get_id() << "se encuentra en un horario concurrido. Tiene una tarifa de " << tarifa << " pesos por kilometro y va desde " << direccion_o << " hasta " << direccion_d << " (" << km << ") " << endl;
        }
    }
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
        double calc_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje);
        void mostrar_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje, int id);
        void mostrar_viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip);
        double calc_tarifa_total(double kilometros, double tarifa_kilometros, int cant_equipaje, int num_pasajeros);
        void mostrar_tarifa_total(double kilometros, double tarifa_kilometros, int cant_equipaje, int num_pasajeros, int id);
        //Getters
        int get_num_pasajeros(){return num_pasajeros;}
        int get_cant_equipaje(){return cant_equipaje;}
        //Setters
        void set_num_pasajeros(int num_pas);
        void set_cant_equipaje(int cant_equip);
};

//Funciones de la clase TaxiInterurbano
double TaxiInterurbano::calc_tarifa_por_pasajero(double tarifa_kilometros, int num_pasajeros){
    double tarifa = 0;
    if (num_pasajeros == 1)
        return tarifa_kilometros;
    else
        tarifa = tarifa_kilometros*(num_pasajeros*0.25);
        return tarifa;
}

void TaxiInterurbano::mostrar_tarifa_por_pasajero(double tarifa_kilometros, int num_pasajeros, int id){
    double tarifa = 0;
    if (num_pasajeros == 1){
        tarifa = tarifa_kilometros;
        cout << "La tarifa aplicada por número pasajeros en el viaje " << id << " fue de: " << 100*tarifa << "%" << endl;
    }
    else{
        tarifa = tarifa_kilometros*(num_pasajeros*0.25);
        cout << "La tarifa aplicada por número pasajeros en el viaje " << id << " fue de: " << 100*tarifa << "%" << endl;
    }
}

double TaxiInterurbano::calc_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje){
    double tarifa = 0;
    tarifa = tarifa_kilometros*(cant_equipaje*0.5);
    return tarifa;
}

void TaxiInterurbano::mostrar_tarifa_por_equipaje(double tarifa_kilometros, int cant_equipaje, int id){
    double tarifa = 0;
    tarifa = tarifa_kilometros*(cant_equipaje*0.5);
    cout << "La tarifa aplicada por cantidad de equipaje en el viaje " << id << " fue de " << 100*tarifa << "%" << endl;
}

double TaxiInterurbano::calc_tarifa_total(double kilometros, double tarifa_kilometros, int cant_equipaje, int num_pasajeros){
    double tarifa_tot = 0;
    double tarifa_por_pasajero = 0;
    double tarifa_por_equipaje = 0;
    double tarifa = 0;
    double tarifa_por_kilometros = 0;
    if (num_pasajeros == 1){
        tarifa_por_pasajero = tarifa_kilometros;
    }
    else{
        tarifa = tarifa_kilometros*(num_pasajeros*0.25);
        tarifa_por_pasajero = tarifa;
    }
    tarifa_por_equipaje = tarifa_kilometros*(cant_equipaje*0.5);
    tarifa_por_kilometros = kilometros*tarifa_kilometros;
    tarifa_tot = tarifa_por_kilometros*(1 + tarifa_por_pasajero + tarifa_por_equipaje);
    return tarifa_tot;
}

void TaxiInterurbano::mostrar_tarifa_total(double kilometros, double tarifa_kilometros, int cant_equipaje, int num_pasajeros, int id){
    double tarifa_tot = 0;
    double tarifa_por_pasajero = 0;
    double tarifa_por_equipaje = 0;
    double tarifa = 0;
    double tarifa_por_kilometros = 0;
    if (num_pasajeros == 1){
        tarifa_por_pasajero = tarifa_kilometros;
    }
    else{
        tarifa = tarifa_kilometros*(num_pasajeros*0.25);
        tarifa_por_pasajero = tarifa;
    }
    tarifa_por_equipaje = tarifa_kilometros*(cant_equipaje*0.5);
    tarifa_por_kilometros = kilometros*tarifa_kilometros;
    tarifa_tot = tarifa_por_kilometros*(1 + tarifa_por_pasajero + tarifa_por_equipaje);
    cout << "La tarifa total del viaje " << id << " fue de: " << tarifa_tot << endl;
}

void TaxiInterurbano::mostrar_viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, int num_pas, int cant_equip){
    cout << "El viaje en " << tipo_viaje << " con id " << get_id() << " tiene " << num_pas << " pasajeros con " << cant_equip << " maletas. Además, tiene una tarifa de " << tarifa_km << " pesos por kilometro y va desde " << direccion_o << " hasta " << direccion_d << " (" << km << ") " << endl;
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
        void mostrar_viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car);
        double calc_tarifa_total(double kilometros, double tarifa_kilometros, double peso_carga);
        void mostrar_tarifa_total(double kilometros, double tarifa_kilometros, double peso_carga, int id);
        //Getter
        double get_peso_carga(){return peso_carga;}
        //Setter
        void set_peso_carga(double peso_car);
};

double Flete::calc_tarifa_por_peso(double tarifa_kilometros, double peso_carga){
    double tarifa = 0;
    if ((peso_carga-200) <= 0)
        return tarifa_kilometros;
    else
        tarifa = tarifa_kilometros*(1+((peso_carga/200)*0.25));
        return tarifa;
}

void Flete::mostrar_tarifa_por_peso(double tarifa_kilometros, double peso_carga, int id){
    double tarifa = 0;
    if ((peso_carga-200) <= 0){
         cout << "La tarifa aplicada por peso para el viaje " << id << " fue de " << tarifa_kilometros << endl;
    }
    else {
        tarifa = tarifa_kilometros*(1+((peso_carga/200)*0.25));
        cout << "La tarifa aplicada por peso para el viaje " << id << " fue de " << tarifa << endl;
    }
}

double Flete::calc_tarifa_total(double kilometros, double tarifa_kilometros, double peso_carga){
    double tarifa = 0;
    double tarifa_por_peso = 0;
    if ((peso_carga-200) <= 0){
        tarifa = kilometros*tarifa_kilometros;
        return tarifa;
    }
    else{
        tarifa_por_peso = tarifa_kilometros*(1+((peso_carga/200)*0.25));
        tarifa = kilometros*tarifa_por_peso;
        return tarifa;
    }
}

void Flete::mostrar_tarifa_total(double kilometros, double tarifa_kilometros, double peso_carga, int id){
    double tarifa = 0;
    double tarifa_por_peso = 0;
    if ((peso_carga-200) <= 0){
        tarifa = kilometros*tarifa_kilometros;
        cout << "La tarifa total para el viaje " << id << " fue de " << tarifa << endl;
    }
    else{
        tarifa_por_peso = tarifa_kilometros*(1+((peso_carga/200)*0.25));
        tarifa = kilometros*tarifa_por_peso;
        cout << "La tarifa total para el viaje " << id << " fue de " << tarifa << endl;
    }
}

void Flete::mostrar_viaje(int i_d, string tipo_viaje, string direccion_o, string direccion_d, double km, double tarifa_km, double peso_car){
    double tarifa = 0;
    if ((peso_carga-200) <= 0){
        cout << "El " << tipo_viaje << " con id " << get_id() << " tiene una tarifa de " << tarifa << " pesos por kilometro y va desde " << direccion_o << " hasta " << direccion_d << " (" << km << ") " << endl;
    }
    else{
        tarifa = tarifa_km*(1+((peso_carga/200)*0.25));
        cout << "El " << tipo_viaje << " con id " << get_id() << " tiene una tarifa de " << tarifa << " pesos por kilometro y va desde " << direccion_o << " hasta " << direccion_d << " (" << km << ") " << endl;
    }
}

//Setters
void Flete::set_peso_carga(double peso_car){
    peso_carga = peso_car;
}

#endif // VIAJE_H_
