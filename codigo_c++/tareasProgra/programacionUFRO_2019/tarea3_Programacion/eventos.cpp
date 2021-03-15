#include "eventos.h"
#include <stdio.h>
#include <string.h>

//Array que guarda todos los datos sobre eventos a utilizar durante
//la ejecución del programa. Mi idea es intentar que añadir y borrar
//eventos o ubicaciones nuevas sea sencillo... Para añadir un nuevo evento
//se necesitan 4 datos: nombre, ubicaciones, precios y el stock inicial
//de entradas (unidades) en ese orden
static const char atributos[][40] {

  /*cadena "Nombre" encontrada, añadiendo evento "concierto" con id 0
  "nombre", "Concierto",

              ubicacion 0   ubicacion 2    ubicacion 3    ubicacion 4       ubicacion 5
  "ubicaciones", "Tribuna", "Platea Alta", "Platea Baja", "Cancha General", "Cancha VIP",

  cadena "ubicaciones" encontrada, la función inicializarEventos()
  saltará a la siguiente cadena de texto y la almacenara como una
  ubicacion del evento "concierto" como la ubicacion 0,
  lo mismo con las demás hasta que
  encuentra la cadena "precios"

          valor ubicacion 0, valor ubicacion 1 ...             ...       valor ubicacion 5
                  |          |                                               |
  "precios",   "36800",   "46500",       "61750",       "76000",          "96750",

  cadena "precios" encontrada, la función inicializarEventos()
  saltará a la siguiente cadena de texto y la almacenara como el
  precio de la ubicacion 0 del evento "concierto",
  lo mismo con las demás hasta que
  encuentra la cadena "unidades"

      stock inicial ubicacion 0....    ......            ......      stock inicial ubicacion 5
                  |                                                          |
  "unidades",  "1000",    "3000",        "3000",        "7000",           "2000",

  cadena "unidades" encontrada, la función inicializarEventos()
  saltará a la siguiente cadena de texto y la almacenara como el
  stock inicial de entradas de ubicacion 0 del evento "concierto",
  lo mismo con las demás hasta que
  encuentra la cadena "nombre" para repetir el proceso de nuevo
  con el siguiente eventos con la ID 1, o la cadena
  "fin", en cuyo caso termina*/
  "nombre", "Concierto",
  "ubicaciones", "Tribuna", "Platea Alta", "Platea Baja", "Cancha General", "Cancha VIP",
  "precios",   "36800",   "46500",       "61750",       "76000",          "96750",
  "unidades",  "1000",    "3000",        "3000",        "7000",           "2000",

  "nombre", "Partido de fútbol",
  "ubicaciones", "Galería", "Andes", "Pacífico",
  "precios",   "3000",    "6000",  "9000",
  "unidades",  "9000",    "4500",  "4000",

  "nombre", "Show de Stand Up Comedy",
  "ubicaciones", "Silver", "Golden", "VIP Platinum", "Diamante",
  "precios",   "11000",  "13200",  "16500",        "22000",
  "unidades",  "200",    "150",    "100",          "50",

  "nombre", "Fiesta de la cerveza",
  "ubicaciones", "General",
  "precios",   "2500",
  "unidades", "5000",

  "fin"
};

eventos datosEventos[numEventos];
char buffer[10];
/* * Nombre de la función: inicializarEventos.
* Tipo de función: int.
* Parámetros: ninguno
* Dato de retorno: ninguno
* Descripción de la función: Busca y registra los distintos datos de eventos proporcionados al programa,
* los clasifica segun nombre, asignandole a cada nombre de evento un array con las respectivas ubicaciones, precios
* de las ubicaciones y su stock inicial*/

void inicializarEventos() {
  int contador = 0;
  int ubicaciones = 0;
  int num = 0;
  int aux = 0;

  bool flag = false;


  while(1) {

    flag = false;
    while(flag == false) {
      if(strcmp(atributos[contador], "nombre") == 0) {
        contador++;
        aux = 0;
      } else if(strcmp(atributos[contador], "ubicaciones") == 0) {
        flag = true;
        contador++;
        aux = 0;
      } else {
        strcpy(datosEventos[num].nombre, atributos[contador]);
        contador++;
        //printf("num = %i aux = %i contador = %i string = %s\n", num, aux, contador, datosEventos[num].nombre);
        aux++;
      }
    }
    //printf("\n");

    flag = false;
    while(flag == false) {
      if(strcmp(atributos[contador], "ubicaciones") == 0) {
        contador++;
        aux = 0;
      } else if(strcmp(atributos[contador], "precios") == 0) {
        flag = true;
        contador++;
        aux = 0;
      } else {
        strcpy(datosEventos[num].ubicaciones[aux], atributos[contador]);
        //printf("num = %i aux = %i contador = %i string = %s\n", num, aux, contador, datosEventos[num].ubicaciones[aux]);
        aux++;
        contador++;
        ubicaciones++;
      }
    }
    contadorUbicaciones[num] = ubicaciones;
    ubicaciones = 0;
    //printf("\n");

    flag = false;
    while(flag == false) {
      if(strcmp(atributos[contador], "precios") == 0) {
        contador++;
        aux = 0;
      } else if(strcmp(atributos[contador], "unidades") == 0) {
        flag = true;
        contador++;
        aux = 0;
      } else {
        strcpy(buffer, atributos[contador]);
        *datosEventos[num].precioEntradas[aux] = string_a_int(buffer);
        buffer[0] = '\0';
        //printf("num = %i aux = %i contador = %i string = %s\n", num, aux, contador, datosEventos[num].precioEntradas[aux]);
        aux++;
        contador++;
      }
    }
    //printf("\n");
    flag = false;
    while(flag == false) {
      if(strcmp(atributos[contador], "unidades") == 0) {
        contador++;
        aux = 0;
      } else if(strcmp(atributos[contador], "nombre") == 0) {
        flag = true;
        contador++;
        aux = 0;
      } else if(strcmp(atributos[contador], "fin") == 0) {
        return; //termina la ejecución
      } else {
        strcpy(buffer, atributos[contador]);
        *datosEventos[num].cantidad[aux] = string_a_int(buffer);
        buffer[0] = '\0';
        //printf("num = %i aux = %i contador = %i string = %s\n", num, aux, contador, datosEventos[num].cantidad[aux]);
        aux++;
        contador++;
      }
    }
    num++;
    //printf("\n");
  }
}

/* * Nombre de la función: mostrarEventos.
* Tipo de función: int.
* Parámetros: ninguno
* Dato de retorno: int, retorna la eleccion del usuario
* Descripción de la función: Muestra los eventos disponibles y registra la eleccion
* del usuario*/

int mostrarEventos() {

  int eleccion;
  printf("\n\n");
  printf("Eventos disponibles:\n\n");
  for(int i = 0; i < numEventos; i++) {
    printf("%i) %s\n", i+1, datosEventos[i].nombre);
  }

  eleccion = registrarEleccion(numEventos);
  return eleccion;
}

/* * Nombre de la función: mostrarEventos.
* Tipo de función: void.
* Parámetros: ninguno
* Dato de retorno: ninguno
* Descripción de la función: Solo muestra los eventos disponibles
* */

void soloMostrarEventos() {
  printf("Eventos disponibles:\n\n");
  for(int i = 0; i < numEventos; i++) {
    printf("%i) %s\n", i+1, datosEventos[i].nombre);
  }
}
