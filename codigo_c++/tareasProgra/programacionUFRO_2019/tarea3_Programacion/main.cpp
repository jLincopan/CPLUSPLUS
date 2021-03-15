/*
--------------------------------------------------------
|                        MMMMMMM                       |       Universidad de La Frontera
|                  MM              MM                  |
|               M                      M               |
|             M                          MM            |       ICC-202 PROGRAMACION DE COMPUTADORES
|           M          $$$$   $$$$                     |
|         M        $$   $$$   $$    $$       M         |       Tarea 3
|        M       $$$$$    $   $    $$$$$      $        |
|       M      $$$$$$$$          $$$$$$$$$     M       |       Autor:  -Javier Lincopán, (j.lincopan01@ufromail.cl)
|      M      $$$$$$$$$$$$$   $$$$$$$$$$$$$     $      |
|            $$$$$$$$$$$$$$   $$$$$$$$$$$$$$     M     |
|     M        $$$$$$$$$$$$   $$$$$$$$$$$$        M    |
|               $$$$$$$$$$$   $$$$$$$$$$               |
|    M     $$    $$$$$$$        $$$$$$$    $$$    M    |      Descripción general del programa: Programa que simula
|    M     $$$$   $$$$$          $$$$$$   $$$$    M    |      la venta de tickets para distintos eventos, se puede
|    M                                            M    |      añadir nuevos eventos, eliminar o modificar los precios,
|    M                                            M    |      nombres, stock inicial y demás datos modificando el
|    M     $$$M   $$$$$,         $$$$$$   $$$$    M    |      array atributos que se encuentra en el archivo
|    M     $$    $$$$$$$4       $$$$$$$M    $$    M    |      eventos.cpp
|               $$$$$$$$$$$   $$$$$$$$$$M         M    |
|     M       0$$$$$$$$$$$$   $$$$$$$$$$$$$            |
|            $$$$$$$$$$$$$$   $$$$$$$$$$$$$M           |
|      M      $$$$$$$$$$$$     $$$$$$$$$$$$     M      |
|       M      $$$$$$$$           $$$$$$$      M       |
|        M       $$$$     $   $    $$$$$      M        |
|          M       $    $$$   $$$    $       M         |
|           M          $$$$   $$$$         M           |
|             M                          M             |
|                MM                   M                |
|                    MM M MMMMM  MMM                   |
|------------------------------------------------------|
 * */

#include <stdio.h>
#include "programaTicket.h"
#include "eventos.h"

int main() {
  int entradasRestantes;
  int id;

  generarPantalla(); //Inicializamos el tablero de los asientos del Show
                    //de stand up comedy diamante

  inicializarEventos(); //cargamos los datos suministrados al programa
                       //clasificándolos segun evento, ubicacion, precio
                      //y stock inicial
  printf("\e[2J\e[H");
  while(1) { //No salimos de aquí hasta que se vendan todas las entradas
    pantallaInicio();
    id = mostrarEventos(); //obtenemos la id del evento que quiere el usuario
    entradasRestantes = comprarTicket(id); //comprar
    if(entradasRestantes == 0) {
      return 0; //Todas las entradas vendidas, termina con éxito
    }
  }
}
