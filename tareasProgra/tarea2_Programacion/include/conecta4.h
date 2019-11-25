#ifndef _CONECTA4_H_
#define _CONECTA4_H_

#include <stdio.h>
const int largo = 7; 
const int ancho = 6;

//Carácteres con los que los jugadores verán sus jugadas en la pantalla
extern char caracterJugador1;
extern char caracterJugador2;
extern char caracterFondo;
extern char espaciosPorVerificar; //Cantidad de espacios para ganar

extern int ultimaJugadaX;
extern int ultimaJugadaY;
extern char caracterMatch;
extern char tablero[ancho][largo]; //Matriz que continene el tablero de juego
//Variables globales

extern bool turnoJugador1;
extern bool turnoJugador2;

void generarPantalla(char array[ancho][largo]);
int conecta4();
void felicitaciones();
int menuInicio();
void mostrarTablero(char array[ancho][largo]);
int registrarJugada();
int verificarSiHayGanador();

#endif
