/*
--------------------------------------------------------
|                        MMMMMMM                       |       Universidad de La Frontera
|                  MM              MM                  |
|               M                      M               |
|             M                          MM            |       ICC-202 PROGRAMACION DE COMPUTADORES
|           M          $$$$   $$$$                     |
|         M        $$   $$$   $$    $$       M         |       Tarea 2
|        M       $$$$$    $   $    $$$$$      $        |
|       M      $$$$$$$$          $$$$$$$$$     M       |       Autores:  -Javier Lincopán, (j.lincopan01@ufromail.cl)
|      M      $$$$$$$$$$$$$   $$$$$$$$$$$$$     $      |                 -Samuel Orellana, (s.orellana02@ufromail.cl)
|            $$$$$$$$$$$$$$   $$$$$$$$$$$$$$     M     |
|     M        $$$$$$$$$$$$   $$$$$$$$$$$$        M    |
|               $$$$$$$$$$$   $$$$$$$$$$               |
|    M     $$    $$$$$$$        $$$$$$$    $$$    M    |      Descripción general del programa: un compendio de juegos!
|    M     $$$$   $$$$$          $$$$$$   $$$$    M    |
|    M                                            M    |
|    M                                            M    |
|    M     $$$M   $$$$$,         $$$$$$   $$$$    M    |
|    M     $$    $$$$$$$4       $$$$$$$M    $$    M    |
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
#include <stdlib.h> //Para los números aleatorios
#include <time.h> //Para los números aleatorios

#include "toqueFama.h"
#include "conecta4.h"
#include "tresRaya.h"

/* * Nombre de la función: main.
* Tipo de función: int.
* Parámetros: "array" de tipo int[].
* Dato de retorno: "0" si termina con éxito
* Descripción de la función: la función principal de todo! */

int main(int argc, char **argv) {

	int eleccion;

	printf("\e[2J\e[H");
	printf("  ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ \n");
	printf(" |______|______|______|______|______|______|______|______|______|______|\n");
	printf(" | |                                                                 | |\n");
	printf(" | |     _ _    _ ______ _____  ____   _____     _____ _____ ______  | |  \n");
	printf(" | |    | | |  | |  ____/ ____|/ __ \\ / ____|   |_   _/ ____|  ____| | |\n");
	printf(" | |    | | |  | | |__ | |  __| |  | | (___       | || |    | |__    | |\n");
	printf(" | |    | | |  | |  __|| | |_ | |  | |\\___ \\      | || |    |  __|   | |\n");
	printf(" | | |__| | |__| | |___| |__| | |__| |____) |    _| || |____| |____  | |\n");
	printf(" | |\\____/ \\____/|______\\_____|\\____/|_____/    |_____\\_____|_____|  | |\n");
	printf(" |_|____ ______ ______ ______ ______ ______ ______ ______ ______ ____|_|\n");
	printf(" |______|______|______|______|______|______|______|______|______|______|\n\n");

	printf("Bienvenido/a a JuegosICE, ¡La mejor colección de juegos del mundo mundial!\n");
  printf("                                ®2019-9999 Palta INC. All rights reserved\n\n");

	while(1) {

		printf("¡Elija el juego que desea jugar!\n\n");
		printf("0) Salir\n");
		printf("1) Tres en Raya\n");
		printf("2) Conecta4\n");
		printf("3) Toque y Fama\n\n");

		scanf("%i", &eleccion);

		if(eleccion == 1) {
				printf("\e[2J\e[H");
				tresRaya();
		} else if(eleccion == 2) {
				printf("\e[2J\e[H");
				conecta4();
		} else if(eleccion == 3) {
				printf("\e[2J\e[H");
				toqueFama();
		} else if(eleccion == 0) {
			return 0;
		} else {
			printf("\e[2J\e[H");
			printf("La opción ingresada no es válida, por favor... Inténtelo nuevamente\n\n");
		}
	}
}
