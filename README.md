# TC1030 Proyecto: Agencia de Transporte

El proyecto consiste en calcular los ingresos que genera una agencia de transporte a través de las tarifas que generan los distintos tipos de viajes que hay. Algo que debemos tener en cuenta es que los viajes comparten algunas características en común como: id de viaje, una etiqueta con el tipo de viaje, dirección de origen y destino, cantidad de kilometros recorridos y una tarifa por kilómetro recorrido. Sin embargo, en la siguiente lista podremos encontrar los diferentes tipos de viajes disponibles junto con sus características distintivas:

Taxi Local: Tiene una tarifa especial cuando se encuentra en un horario concurrido (El doble del precio)

Taxi Inter-urbano: Tiene una tarifa especial dependiendo de la cantidad de pasajeros y la cantidad de equipaje (25% extra por persona excepto cuando es solo un ocupante y 5% extra por cada uno de los equipajes)

Fletes: Tiene una tarifa especial dependiendo del peso de la carga (25% extra cada 200kg)

# Funcionalidad
El programa permitirá ver la información de los viajes guardados en la memoria

El programa podrá calcular los ingresos totales de la agencia de transporte

El programa podrá calcular el ingreso total por tipo de viaje

El programa le permitirá al usuario registrar más viajes de cualquiera de los tipos que hay

El programa consta de un menu con opciones y corre sobre consola

# Consideraciones
La clase principal que representa a la agencia, contiene dentro las clases que representan los tipos de viaje. Al usar elementos de composición para el proyecto, este dejaría de funcionar si la clase de la empresa es eliminada ya que al desaparecer ella, las demás clases también lo harían.

El programa solo corre en la consola y esta hecho con c++ standard, así que corre en todos los sistemas operativos.
