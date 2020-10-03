#include <stdio.h>
#include "pila.h"


void anula(Pila &pila){
	while(!vacia(pila))
		pop(pila);
}
bool vacia(Pila pila){
	return vacia((Lista)pila);
}
tipoDato top(Pila pila){
	return recupera(primero((Lista)pila),(Lista)pila);
}
void pop(Pila &pila){
	return suprime(primero((Lista)pila),(Lista&)pila);
}
void push(tipoDato x, Pila &pila){
	return inserta(x,primero((Lista)pila),(Lista&)pila);
}
void imprime(Pila pila){
	if(vacia(pila)){
		printf("Pila vacia!\n");
		return;
	}
	Pila aux;
	printf("Pila:\n");
	while(!vacia(pila)){
		tipoDato x = top(pila);
		printf("%d\n",x);
		push(x,aux);
		pop(pila);
	}
	while(!vacia(aux)){
		push(top(aux),pila);
		pop(aux);
	}
}
