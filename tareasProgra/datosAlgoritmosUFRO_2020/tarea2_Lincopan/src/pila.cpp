#include <stdio.h>
#include "include/pila.h"

// IMPLEMENTACIONES
bool pilaVacia(Pila p) {
	return listaVacia((Lista)p);
}

void push(tipoDato x, Pila &p){
	insertarDato_lista(x, primerElemento_lista((Lista)p),(Lista&)p);  
}

void pop(Pila &p){
	eliminarDato_lista(primerElemento_lista((Lista)p),(Lista&)p);
}
	
tipoDato top(Pila p){
	return obtenerDato_lista(primerElemento_lista((Lista)p),p);
}

void borrarPila(Pila &p){
	while(!pilaVacia(p)){
		pop(p);
	}
}

int localizarDato_pila(Pila &p, tipoDato x) {

	if(pilaVacia(p)) {
		printf("Error en función localiza, la pila pasada como parámetro está vacia\n");
	}

	int posicion = 0;
	tipoDato dato = {0};

	while(!pilaVacia(p)) {

		dato = top(p);

		if(dato == x) {
			return posicion;
		}

		pop(p);
		posicion++;
	}

	printf("Error en función localiza: no se pudo encontrar el dato en la pila recibida como parámetro\n");
	return 0;
} 

void imprimirPila(Pila p){
	Pila aux;
	printf("Pila:\n");
	while(!pilaVacia(p)){
		tipoDato x = top(p);
		printf("%d\n",x);
		push(x,aux);
		pop(p);
	}
	while(!pilaVacia(aux)){
		push(top(aux),p);
		pop(aux);
	}
}

void suprimirElemento_pila(int id, Pila &pila) {
	printf("\n");
	if(pilaVacia(pila)) {
		printf("Error en función suprimir: La pila está vacía\n");
		return;
	}

	//Tuve que usar dos estructuras pila auxiliares acá... Ya que me salen 
	//errores medio obscuros y esotéricos si no lo hago así
	Pila tmp;
	Pila aux;

	int contador = 0;
	tipoDato dato;

	//copiando todos los elementos menos el seleccionado
	while(!pilaVacia(pila)) {
		dato = top(pila);
		if(contador != id) {
			push(dato, tmp);
		}
		contador++;
		pop(pila);
	}

	//copiandola de nuevo, gracias a que las pilas son "LIFO" quedará en el
	//orden original sin el elemento eliminado
	while(!pilaVacia(tmp)) {
		dato = top(tmp);
		push(dato, aux);
		pop(tmp);
	}

	pila = aux;
	printf("\n");
}