/*
 *
 *Proyecto Agencia de Transporte main
 *Iván Ricardo Paredes Avilez
 *A01705083
 *16/06/2022
 *Version: 3
 *Este es un programa que nos permite administrar la información
 *de distintos tipos de viajes que pertenecen a una agencia de Transporte.
 *Podemos ver los detalles de cada viaje y hacer el calculo de los ingresos
 *que tenemos en un conjunto de viajes o en su totalidad. También podemos
 *registrar otros viajes.
 */

//Nos permite imprimir
#include <iostream>

//Importamos nuestras clases creadas en otros archivos
#include "viaje.h"
#include "agenciaTransporte.h"

using namespace std;

//Instanciamos el objeto agencia
AgenciaTransporte agencia;


/**
 *la funcion menu imprime una serie de opciones enumeradas que
 *a la vez hacen referencia a funciones del programa.
 *
 *Se trata solo de  salidas de texto enumeradas para que el usuario
 *pueda elegir la que necesite.
 *
 *@param No se tienen parámetros
 *
 *@return No se devuelve ningún valor
 */
void menu(){
    cout << "Que es lo que deseas hacer?: \n" << endl;
    cout << "1. Crear ejemplos" << endl;
    cout << "2. Mostrar viajes" << endl;
    cout << "3. Mostrar solo viajes de taxis locales" << endl;
    cout << "4. Mostrar solo viajes de taxis interurbanos" << endl;
    cout << "5. Mostrar solo viajes de fletes" << endl;
    cout << "6. Mostrar el ingreso solo de los taxis locales" << endl;
    cout << "7. Mostrar el ingreso solo de los taxis interurbanos" << endl;
    cout << "8. Mostrar el ingreso solo de los Fletes" << endl;
    cout << "9. Mostrar el ingreso total de la agencia de transporte" << endl;
    cout << "10. Registrar un viaje de taxi local" << endl;
    cout << "11. Registrar un viaje de taxi interurbano" << endl;
    cout << "12. Registrar un viaje de flete" << endl;
    cout << "13. Salir" << endl;
    cout << endl;
}

/**
 *En el main se hace uso de la función menu para poder
 *desplegar las opciones y se tiene un ciclo while con diferentes
 *condicionales que ejecutan las funciones del programa. El ciclo
 *no se rompe hasta que el usuario teclea el número 13.
 *
 *@param No se tienen parámetros
 *
 *@return int con valor de 0
 */
int main() {

    //Inicializamos la variable "opcion" que va a introducir el usuario
    int opcion = 0;

    //Ciclo while para desplegar el menu y que el usuario introduzca una opción
    while (opcion != 13){
        //Se despliega el menu
        menu();
        //El usuario introduce una opcion
        cin >> opcion;

        //Se generan ejemplos
        if (opcion == 1){
            agencia.crea_ejemplos();
            cout << "Se han creado los ejemplos" << endl;
            cout << endl;
        }

        //Se muestra la información de los viajes
        else if (opcion == 2){
            cout << "Estos son todos los viajes: \n" << endl;
            agencia.muestra_viajes();
        }

        //Impresión de solo los viajes de tipo: Taxi Local
        else if (opcion == 3){
            cout << "Estos son los viajes de tipo Taxi Local: \n" << endl;
            agencia.muestra_viajes("Taxi local");
        }

        //Impresión de solo los viajes de tipo: Taxi Interurbano
        else if (opcion == 4){
            cout << "Estos son los viajes de tipo Taxi Interurbano: \n" << endl;
            agencia.muestra_viajes("Taxi interurbano");
        }

        //Impresión de solo los viajes de tipo: Taxi Interurbano
        else if (opcion == 5){
            cout << "Estos son los viajes de tipo Taxi Flete: \n" << endl;
            agencia.muestra_viajes("Flete");
        }

        //Se muestra el ingreso de los taxis locales
        else if (opcion == 6){
            cout << "El ingreso total de los taxis locales fue: $" << agencia.calc_ingreso_total("Taxi local") << " pesos." << endl;
            cout << endl;
        }

        //Se muestra el ingreso de los taxis interurbanos
        else if (opcion == 7){
            cout << "El ingreso total de los taxis interurbanos fue: $" << agencia.calc_ingreso_total("Taxi interurbano") << " pesos." << endl;
            cout << endl;
        }

        //Se muestra el ingreso de los fletes
        else if (opcion == 8){
            cout << "El ingreso total de los fletes fue: $" << agencia.calc_ingreso_total("Flete") << " pesos." << endl;
            cout << endl;
        }

        //Se muestra el ingreso total de la agencia
        else if (opcion == 9){
            cout << "El ingreso total de la agencia fue: $" << agencia.calc_ingreso_total() << " pesos." << endl;
            cout << endl;
        }

        //Se genera un viaje de tipo "Taxi local"
        else if (opcion == 10){

            //Definimos las variables
            int i_d = (agencia.get_num_viajes() + 1);
            string tipo_viaje = "Taxi local";
            string direccion_o;
            string direccion_d;
            double km;
            double tarifa_km;
            string horario_concu_usuario;
            bool horario_concu;

            //Pedimos los datos al usuario
            cout << "Introduce la direccion de origen (sin espacios)" << endl;
            cin >> direccion_o;
            cout << "Introduce la direccion de destino (sin espacios)" << endl;
            cin >> direccion_d;
            cout << "Introduce la cantidad de kilometros que tiene el viaje" << endl;
            cin >> km;
            cout << "Introduce la tarifa por kilometro (precio por kilometro recorrido)" << endl;
            cin >> tarifa_km;
            cout << "El viaje fue realizado en horario concurrido? (si/no)" << endl;
            cin >> horario_concu_usuario;
            //Condicional para el horario concurrido. "si" es igual a true, "no" es igual a false
            if (horario_concu_usuario == "si"){
                horario_concu = true;
            }
            else{
                horario_concu = false;
            }

            //Generamos el viaje con la funcion agrega_taxi_local
            agencia.agrega_taxi_local(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, horario_concu);
            cout << "Se ha creado el viaje de tipo: Taxi local" << endl;
        }

        //Se genera un viaje de tipo "Taxi interurbano"
        else if (opcion == 11){

            //Definimos las variables
            int i_d = (agencia.get_num_viajes() + 1);
            string tipo_viaje = "Taxi interurbano";
            string direccion_o;
            string direccion_d;
            double km;
            double tarifa_km;
            int num_pas;
            int cant_equip;

            //Pedimos los datos al usuario
            cout << "Introduce la direccion de origen (sin espacios)" << endl;
            cin >> direccion_o;
            cout << "Introduce la direccion de destino (sin espacios)" << endl;
            cin >> direccion_d;
            cout << "Introduce la cantidad de kilometros que tiene el viaje" << endl;
            cin >> km;
            cout << "Introduce la tarifa por kilometro (precio por kilometro recorrido)" << endl;
            cin >> tarifa_km;
            cout << "Introduce la cantidad de pasajeros" << endl;
            cin >> num_pas;
            cout << "Introduce la cantidad de equipaje (cuantas maletas se llevan)" << endl;
            cin >> cant_equip;

            //Generamos el viaje con la función agrega_taxi_interurbano
            agencia.agrega_taxi_interurbano(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, num_pas, cant_equip);
            cout << "Se ha creado el viaje de tipo: Taxi interurbano" << endl;
        }

        //Se genera un viaje de tipo "Flete"
        else if (opcion == 12){

            //Definimos las variables
            int i_d = (agencia.get_num_viajes() + 1);
            string tipo_viaje = "Flete";
            string direccion_o;
            string direccion_d;
            double km;
            double tarifa_km;
            double peso_car;

            //Pedimos los datos al usuario
            cout << "Introduce la direccion de origen (sin espacios)" << endl;
            cin >> direccion_o;
            cout << "Introduce la direccion de destino (sin espacios)" << endl;
            cin >> direccion_d;
            cout << "Introduce la cantidad de kilometros que tiene el viaje" << endl;
            cin >> km;
            cout << "Introduce la tarifa por kilometro (precio por kilometro recorrido)" << endl;
            cin >> tarifa_km;
            cout << "Introduce la cantidad de peso" << endl;
            cin >> peso_car;

            //Generamos el viaje con la función agrega_taxi_interurbano
            agencia.agrega_flete(i_d, tipo_viaje, direccion_o, direccion_d, km, tarifa_km, peso_car);
            cout << "Se ha creado el viaje de tipo: Flete" << endl;
        }

        //Despedida cuando el usuario sale del programa
        else if (opcion == 13){
            cout << "Adios" << endl;
        }

        //Mensaje de error cuando se teclea un número inexistente en el menu
        else{
            cout << "Opcion invalida" << endl;
        }
    }

return 0;
}
