#include <stdio.h>
#include "include/cola.h"

// IMPLEMENTACIONES
bool colaVacia(Cola c){
	return listaVacia((Lista)c);
	}

tipoDato primerElemento_cola(Cola c){
	return obtenerDato_lista(primerElemento_lista((Lista)c),(Lista)c);
	}

void ponerEnCola(tipoDato x, Cola &c){
	insertarDato_lista(x,largoLista((Lista)c),(Lista&)c);
	}

void quitarDeCola(Cola &c){
	eliminarDato_lista(primerElemento_lista((Lista)c),(Lista&)c);
	}

void eliminarCola(Cola &c){
	while(!colaVacia(c)){
		quitarDeCola(c);
		}
	}

void imprimeCola(Cola c){
	Cola aux;
	while(!colaVacia(c)){
		tipoDato x = primerElemento_cola(c);
		printf("%d->",x);
		ponerEnCola(x,aux);
		quitarDeCola(c);
		}
	printf("\n");
	while(!colaVacia(aux)){
		tipoDato x = primerElemento_cola(aux);
		ponerEnCola(x,c);
		quitarDeCola(aux);
		}
	}

void suprimirElemento_cola(int pos, Cola &c) {

	if(colaVacia(c)) {
		printf("Error en función suprimirElemento_cola: La cola recibida como parámetro está vacía\n");
		return;
	}

	Cola tmp;
	tipoDato dato;
	int contador = 0;
		printf("\n");
	while(!colaVacia(c)) {

		dato = primerElemento_cola(c);
		if(pos != contador) {
			ponerEnCola(dato, tmp);
		}

		quitarDeCola(c);
		contador++;
	}

	eliminarLista(c);
	c = tmp;
}