#ifndef _TOQUEFAMA_H_
#define _TOQUEFAMA_H_

int numAleatorio(int sup, int inf);
int elevar(int exponente, int base);
int turnoBot(int array[]);
int turnoJugador(int array[]);
void compararJugadas(int jugador[], int bot[], int aciertosBot[]);
bool separarNum(int num, int array[]);
int toqueFama();
void pantallaInicio();

#endif
