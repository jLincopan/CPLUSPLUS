
#include <stdio.h>
#include <stdlib.h> //Para los números aleatorios
#include <time.h> //Para los números aleatorios
#include "toqueFama.h"

static int limiteSuperior;
static int limiteInferior;
static int numero;
static int dificultad;
static int sup;
static int inf;
static int toquesJugador = 0;
static int famasJugador = 0;
static int toquesBot = 0;
static int famasBot = 0;
static int aciertos = 0;
static int turnos = 1;

static bool aprobado = false;
static bool ganador = false;
static bool turnoJ = true;

//Función principal del juego
int toqueFama() {
	pantallaInicio();
	inf = elevar((dificultad-2), 10); //Límite inferior del rango de números para el bot
	sup = (elevar(dificultad-1, 10)) - 1;//Límite superior

	int numeroUsuario[dificultad];
	int jugadaUsuario[dificultad];
  int numeroBot[dificultad];
  int jugadaBot[dificultad];
	int aciertosBot[dificultad];

  printf("\e[2J\e[H");

  while(aprobado == false) {

	printf("\n\nElija su número para la partida, (%i dígitos sin repetir)\n\n", dificultad);
	    fflush(stdin);
	scanf("%i", &numero);
	aprobado = separarNum(numero, numeroUsuario);
	if(aprobado == false) {
		printf("\e[2J\e[H");
		printf("\bEl número ingresado no es válido\n");
		}
	}
	aprobado = false;

	//El bot elije su número para la partida
	do {
			numero = numAleatorio(inf, sup); //generamos un número dentro del rango
			aprobado = separarNum(numero, numeroBot); //Solo se aprueba si no se repite ningún dígito
	} while(aprobado == false);

	aprobado = false;

	for(int i = 0; i <= dificultad - 1; i++) {
		printf("%i ", numeroBot[i]);
		}

	printf("\e[2J\e[H");
	//¡Empieza el juego!
	//Definimos las variables de nuevo para asegurarnos de que no hayan problemas al abrir
	//El mismo juego de nuevo desde el menú
	toquesJugador = 0;
	famasJugador = 0;
	toquesBot = 0;
	famasBot = 0;
	aciertos = 0;
	turnos = 1;

	ganador = false;
	turnoJ = true;

	while(ganador == false) {
		turnoJugador(jugadaUsuario);
		compararJugadas(jugadaUsuario, numeroBot, aciertosBot);
		turnoJ = false;
		turnoBot(jugadaBot);
		compararJugadas(jugadaBot, numeroUsuario, aciertosBot);

		printf("Toques jugador: %i     Famas jugador: %i                              Turno n°: %i\n\n", toquesJugador, famasJugador, turnos);
		printf("Toques pc: %i          Famas pc: %i\n", toquesBot, famasBot);
		printf("Numeros encontrados por el pc: ");
		for(int i = 0; i < dificultad; i++) {
				if(aciertosBot[i] < 0 || aciertosBot[i] > 9) { //Para excluir los números fuera de rango de un array sin inicializar
					printf("_ ");
				} else {
					printf("%i ", aciertosBot[i]);
				}
		}

		printf("\n\n");

		if(famasJugador == dificultad) {
			ganador = true;
			printf("\n\n¡Felicidades!, le ganaste al bot en %i turnos\n\n", turnos);
			return 0;
			}
			else if (aciertos == dificultad) {
				ganador = true;

				printf("\e[2J\e[H");
				printf("El número del pc era: ");
				for(int i = 0; i < dificultad; i++) {
						printf("%i", numeroBot[i]);
				}
				printf("\n\n¡Has sido derrotado por el booooot en %i turnos!, Skynet is coming\n\n", turnos);
				return 0;
			}
				else {
				turnos++;
				turnoJ = true;
				toquesJugador = 0;
				famasJugador = 0;
				toquesBot = 0;
				famasBot = 0;
				}
		}
	}

//Genera un número aleatorio dentro del rango que recibe como parámetro
int numAleatorio(int inf, int sup) {
	srand(time(NULL)); //Usamos la hora actual como semilla para "randomizar"
	int numero = (rand() % (sup-inf+1))+ inf; //Generamos un número, y lo acotamos dentro del rango
	return numero;
	}

//Separando el número recibido como parámetro en dígitos y guárdandolo en el array también recibido
//como parámetro
bool separarNum(int num, int array[]) {
	int resto;
	int contador = dificultad - 1;
	int digitos = 0;

	while(num > 0) {

		resto = num%10;
		num = num/10;
		array[contador] = resto;
		contador--;
		digitos++;
		}

		if(digitos != dificultad) {
			return false;
			}

	//Verificando si algún dígito se repite, recorremos
	//todo el array comparándo los números de derecha a izquierda
	for(int i = dificultad - 1; i >= 0; i--) {
		for(int a = i, repetido = 0; a >= 0; a--) {
			if(array[i] == array[a]) {
				repetido++;
				if(repetido > 1) {
					return false;
					}
				}
			}
		}
	return true;
	}

//Función para la operación potencia un número, en el juego se usa para determinar
//el rango de números que puede "elegir" el pc
int elevar(int exponente, int base) {

	int resultado = base;
	for(int i = 0; i < exponente; i++) {
		resultado = resultado * base;
		}
	return resultado;
	}

//Se encarga de pedir un número al usuario y procesarlo, además de verificar que no se repitan dígitos
int turnoJugador(int array[]) {

	int numeroIngresado;

	while(aprobado == false) {
		printf("Haga su jugada, ¡sin dígitos repetidos!\n\n");
		scanf("%i", &numeroIngresado);
		aprobado = separarNum(numeroIngresado, array);
		if(aprobado == false) {
					printf("\e[2J\e[H");
					printf("\bEL número ingresado no es válido\n\n");
		}

	}
	printf("\e[2J\e[H");
	aprobado = false;
	return numeroIngresado;
}

int turnoBot(int array[]) {
	//Se encarga de generar un número aleatorio, que será la jugada del bot
	int numBot_generado;
	while(aprobado == false) {
		numBot_generado = numAleatorio(inf, sup);
		aprobado = separarNum(numBot_generado, array); //Solo se aprueba si no se repite ningún dígito
		}
	aprobado = false;
	return numBot_generado;
}

void pantallaInicio() {
	int a;
	printf("\e[2J\e[H");

	printf("  _ _______                                   ______                    _ \n");
	printf(" (_)__   __|                                 |  ____|                  | |\n");
	printf(" | |  | | ___   __ _ _   _  ___     _   _    | |__ __ _ _ __ ___   __ _| |\n");
	printf(" | |  | |/ _ \\ / _` | | | |/ _ \\   | | | |   |  __/ _` | '_ ` _ \\ / _` | |\n");
	printf(" | |  | | (_) | (_| | |_| |  __/   | |_| |   | | | (_| | | | | | | (_| |_|\n");
	printf(" |_|  |_|\\___/ \\__, |\\__,_|\\___|    \\__, |   |_|  \\__,_|_| |_| |_|\\__,_(_)\n");
	printf("                  | |                __/ |                                \n");
	printf("                  |_|               |___/                                 \n\n");
	printf("Bienvenido/a al Toque y Fama, ¡el tercer mejor juego del mundo mundial!\n\n");
	printf("                                ®2019-9999 Palta INC. All rights reserved\n\n");


	while(1) {
		printf("\n\nIngrese la dificultad (cantidad de dígitos, 2-5)\n\n");
		a = scanf("%i", &dificultad);

		if(dificultad < 2 || dificultad > 5 || a != 1) {
			printf("\nEl valor ingresado no es válido por favor... Inténtelo nuevamente");
			printf("\e[2J\e[H");
			dificultad = 0;
			} else {break;}
		}
}
void compararJugadas(int jugador[], int bot[], int aciertosBot[]) {
	//Busca toques y famas
	if(turnoJ) {
		for(int a = 0; a < dificultad; a++) {
			for(int b = 0; b < dificultad; b++) {
				if(jugador[a] == bot[b]) {
					if(a == b) {
						famasJugador++;
						} else {
							toquesJugador++;
						}
					}
				}
			}
		}

	if(!turnoJ) {
		for(int a = 0; a < dificultad; a++) {
			for(int b = 0; b < dificultad; b++) {
				if(bot[a] == jugador[b]) {
					if(a == b) {
						famasBot++;
						if(aciertosBot[a] == jugador[a]) { //Un control adicional para las famas del pc
							aciertos++;                      //Sin esto tomaría como "número encontrado"
						}                                  //Los ceros del array no inicializado
						aciertosBot[a] = bot[a];
						} else {
							toquesBot++;
						}
					}
				}
			}
		}
	}
