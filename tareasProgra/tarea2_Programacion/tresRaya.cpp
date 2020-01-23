#include <stdio.h>

#include "tresRaya.h"

static const int largo = 3;
static const int ancho = 3;

//Carácteres con los que los jugadores verán sus jugadas en la pantalla
static char caracterJugador1 = 'X';
static char caracterJugador2 = 'O';
static char caracterFondo = '*';
static char espaciosPorVerificar = 3; //Cantidad de espacios para ganar
static int ultimaJugadaX = 0;
static int ultimaJugadaY = 0;
static char tablero[ancho][largo]; //Matriz que continene el tablero de juego
//Variables globales

static bool turnoJugador1 = true;
static bool turnoJugador2 = false;

static char caracterMatch;

 void tresRaya() { //Función principal del juego

	printf("\e[2J\e[H");

	int opcion = menuInicio();
	generarPantalla();
	printf("\e[2J\e[H");

	while(opcion == 1) {

		mostrarTablero();
		registrarJugada();

		if(verificarSiHayGanador()) {
				felicitaciones();
			break;
			}

		}
	}

//Llena el tablero con Os
static void generarPantalla() {

	for(int a = 0; a < ancho; a++) { //Recorriendo el tablero

		for(int b = 0; b < largo; b++) {

			tablero[a][b] = caracterFondo;

			}
		}

	}

//Muestra el tablero actualizado
static void mostrarTablero() {

	printf("\n\n-");
	for(int i = 0; i <= largo; i++) {

		printf("---");

		}

	printf("\n");
	for(int a = 0; a < ancho; a++) {
	if(ancho >= 10 && a < 9) {

		printf(" ");

		}
	printf("%i| ", a+1); //imprimiendo números del eje y

		for(int b = 0; b < largo; b++) { //Imprimiendo el contenido de la matriz que recibe como argumento

			printf("%c  ", tablero[a][b]);

			}
			printf("|\n");
		}

		//Imprimiendo los números del eje x, además de la barra separadora
		for(int i = 0; i <= largo; i++) {

		printf("---");

			}
		printf(">\n  | ");
		if(ancho < 10) {
			printf("\b");
			}
		for(int i = 1; i <= largo; i++) {

			if(i >= 10) {
				printf("\b"); //Borramos un espacio para acomodar el dígito adicional
				}
			printf("%i  ", i); //Imprimimos los números


			}


		printf("\n");
}
//Función que registra las jugadas, y además valida las entradas
static int registrarJugada() {

	//Variables para las coordenadas en el tablero
	int x = 0;
	int y = 0;

	if (turnoJugador1) { //Le toca al jugador 1

		printf("Jugador 1, ingrese su jugada (x,y)\n\n");

		scanf("%i,%i", &x, &y);

		if ((x >= 1 && x <= largo) && (y >= 1 && y <= ancho)) {

			x = x-1;
			y = y-1;

			if (tablero[y][x] != caracterFondo) { //Se trabaja con las coordenadas al revés, ya que c genera las matrices en formato [fila][columna]
				printf("\e[2J\e[H");
				printf("La jugada no es válida: no se puede sobreescribir una jugada anterior");
				return 1;
				}
			tablero[y][x] = caracterJugador1;
			caracterMatch = caracterJugador1;

			ultimaJugadaX = x;
			ultimaJugadaY = y;

			printf("\e[2J\e[H");

			} else {

				printf("\e[2J\e[H");
				printf("La jugada no es válida");

				return 1;
				}

		//Esto solo se ejecuta si la jugada es válida
		turnoJugador1 = false;
		turnoJugador2 = true;

		}
	else if (turnoJugador2) { //Si no le toca al jugador 1 le toca al jugador 2

		printf("Jugador 2, ingrese su jugada (x,y)\n\n");
		fflush(stdin);
		scanf("%i,%i", &x,&y);

		if ((x >= 1 && x <= largo) && (y >= 1 && y <= ancho)) {

			x = x-1;
			y = y-1;

			if (tablero[y][x] != caracterFondo) {
				printf("\e[2J\e[H");
				printf("La jugada no es válida: no se puede sobreescribir una jugada anterior");
				return 1;
				}
			tablero[y][x] = caracterJugador2;
			caracterMatch = caracterJugador2;

			ultimaJugadaX = x;
			ultimaJugadaY = y;

			printf("\e[2J\e[H");

			} else {
				printf("\e[2J\e[H");

				printf("La jugada no es válida");
				return 1;
				}

		//Esto solo se ejecuta si la jugada es válida, le "pasa" el turno al otro jugador
		turnoJugador1 = true;
		turnoJugador2 = false;
		}

	return 0;
	}

//Función que verifica si hay algún ganador buscando 4 "matchs" en todas las direcciones posibles
static int verificarSiHayGanador() {

	int contador = 0; //Contador para los "matchs"
	int espaciosVerificados = 0;

    //Recorriendo el eje x

    if(ultimaJugadaX > 0) {

	for(int i = 0; i < espaciosPorVerificar; i++) {

		if(tablero[ultimaJugadaY][ultimaJugadaX-i] == caracterMatch) {
			//printf("\nx = %i y = %i\n", ultimaJugadaX-i, ultimaJugadaY);
			contador++;
			espaciosVerificados++;
			//printf("\n1) %i", contador);
			} else {
				break;
				}
		}
		if (contador == espaciosPorVerificar) {
			//printf("\n1) %i", contador);
			return 1;
			}
			contador--;
		}

	if(ultimaJugadaX < ancho-1) {

		for(int i = 0; i < espaciosPorVerificar; i++) {

			if(tablero[ultimaJugadaY][ultimaJugadaX+i] == caracterMatch) {
				//printf("\nx = %i y = %i\n", ultimaJugadaX+i, ultimaJugadaY);
				contador++;
				//printf("\n2) %i", contador);
				} else {
					break;
					}

			}
		if(contador == espaciosPorVerificar) {
			//printf("\n2) %i", contador);
			return 1;

			}
		}
		contador = 0;
		espaciosVerificados = 0;

		//recorriendo el eje y

		if(ultimaJugadaY > 0) {

			for(int i = 0; i < espaciosPorVerificar; i++) {

				if(tablero[ultimaJugadaY-i][ultimaJugadaX] == caracterMatch) {
					//printf("\nx = %i y = %i\n", ultimaJugadaX, ultimaJugadaY-i);
					contador++;
					espaciosVerificados++;

					//printf("\n4) %i", contador);
					} else {
					break;
					}

				}
			if(contador == espaciosPorVerificar) {
				//printf("\n4) %i", contador);
				return 1;
				}
			contador--;
			}

		if(ultimaJugadaY < ancho - 1) {

			for(int i = 0; i < espaciosPorVerificar; i++) {

				if(tablero[ultimaJugadaY+i][ultimaJugadaX] == caracterMatch) {
					//printf("\nx = %i y = %i\n", ultimaJugadaX-i, ultimaJugadaY-i);
					contador++;
					//printf("\n3) %i", contador);
					} else {
					break;
					}

				}

			if(contador == espaciosPorVerificar) {
				//printf("\n3) %i", contador);
				return 1;
				}
			}


		contador = 0;
		espaciosVerificados = 0;
//Recorriendo el tablero en forma de x, con centro en la última jugada

		//Primer cuadrante tomando como origen la última jugada
		if((ultimaJugadaX < ancho - 1) && (ultimaJugadaY > 0) ) {

			for(int i = 0; i < espaciosPorVerificar; i++) {

				if(tablero[ultimaJugadaY-i][ultimaJugadaX+i] == caracterMatch) {
					//printf("\nx = %i y = %i\n", ultimaJugadaX+i, ultimaJugadaY-i);
					contador++;
					espaciosVerificados++;
					//printf("\n5) %i", contador);
					} else {
					break;
					}
				}
			if(contador == espaciosPorVerificar) {
				//printf("\n5) %i", contador);
				return 1;
				}
			contador--;
			}
		//tercer cuadrante tomando como origen la última jugada
		if((ultimaJugadaX > 0) && (ultimaJugadaY < ancho - 1)) {

			for(int i = 0; i < espaciosPorVerificar; i++) {

				if(tablero[ultimaJugadaY+i][ultimaJugadaX-i] == caracterMatch) {
					//printf("\nx = %i y = %i\n", ultimaJugadaX-i, ultimaJugadaY+i);
					contador++;
					//printf("\n6) %i", contador);
					} else {
					break;
					}
				}
			if(contador == espaciosPorVerificar) {
				//printf("\n6) %i", contador);
				return 1;
				}
			espaciosVerificados = 0;
			}
		contador = 0;

		//Segundo cuadrante tomando como origen la última jugada
		if((ultimaJugadaX > 0) && (ultimaJugadaY > 0)) {

			for(int i = 0; i < espaciosPorVerificar; i++) {

				if(tablero[ultimaJugadaY-i][ultimaJugadaX-i] == caracterMatch) {
					//printf("\nx = %i y = %i\n", ultimaJugadaX-i, ultimaJugadaY-i);
					contador++;
					//printf("\n7) %i", contador);
					} else {
					break;
					}
				}
			if(contador == espaciosPorVerificar) {
				//printf("\n7) %i", contador);
				return 1;
				}
				contador--;
			}

		//Cuarto cuadrante tomando como origen la última jugada
		if((ultimaJugadaX < largo - 1 ) && (ultimaJugadaY < ancho - 1)) {

			for(int i = 0; i < espaciosPorVerificar; i++) {

				if(tablero[ultimaJugadaY+i][ultimaJugadaX+i] == caracterMatch) {
					//printf("\nx = %i y = %i\n", ultimaJugadaX+i, ultimaJugadaY+i);
					contador++;
					//printf("\n8) %i", contador);
					} else {
					break;
					}
				}
			if(contador == espaciosPorVerificar) {
				//printf("\n8) %i", contador);
				return 1;
				}
			contador = 0;
			}
		return 0;

	}

//Desplegamos la pantalla de inicio y las opciones
static int menuInicio() {

	int opcion;

	printf("  _____                                    \n");
	printf(" |_   _| _ ___ ___                         \n");
	printf("   | || '_/ -_|_-<                         \n");
	printf("   |_||_| \\___/__/__ _ _                   \n");
	printf("                / -_) ' \\                  \n");
	printf("                \\___|_||_|_                \n");
	printf("                       | _ \\__ _ _  _ __ _ \n");
	printf("                       |   / _` | || / _` |\n");
	printf("                       |_|_\\__,_|\\_, \\__,_|\n");
	printf("                                 |__/      \n");

	printf("\n");

	//Malditos carácteres de escape

	printf("Bienvenido/a al Tres en raya, ¡el mejor juego del mundo mundial!\n\n");
  printf("                                ®2019-9999 Palta INC. All rights reserved\n\n");

	printf("1) ¡Jugar ya!\n");
	printf("2) Salir\n");

	scanf("%i", &opcion);

	if (opcion == 1) {
		return 1;
		}
		else if(opcion == 2) {
			return 2;
			}
		else {
			printf("La opción ingresada no es válida");
			}
		return 0;
	}

static void felicitaciones() {

	printf("\e[2J\e[H");

	printf(" |  ____| | (_)    (_) |           (_)                     | | |\n");
	printf(" | |__ ___| |_  ___ _| |_ __ _  ___ _  ___  _ __   ___  ___| | |\n");
	printf(" |  __/ _ \\ | |/ __| | __/ _` |/ __| |/ _ \\| '_ \\ / _ \\/ __| | |\n");
	printf(" | | |  __/ | | (__| | || (_| | (__| | (_) | | | |  __/\\__ \\_|_|\n");
	printf(" |_|  \\___|_|_|\\___|_|\\__\\__,_|\\___|_|\\___/|_| |_|\\___||___(_|_)\n");

	if(turnoJugador1 == true) {

		printf("\n                                        ¡Ha ganado el jugador 2!\n");

		} else {

			printf("\n                                        ¡Ha ganado el jugador 1!\n");

			}
	}
