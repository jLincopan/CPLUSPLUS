#include <stdio.h>
#include "pila.h"

Lista ordena(Pila &p);

int main(){
	Pila p;
	push(8,p);
	push(7,p);
	push(2,p);
	push(5,p);
	push(1,p);
	push(3,p);
	push(2,p);
	push(1,p);
	push(8,p);
	imprime(p);
	Lista l = ordena(p);
	imprime((Pila)p);
	imprime(l);

	return 0;
}

Lista ordena(Pila &p){
	Lista l;
	Pila aux;
	Pila orden;
	while(!vacia(p)){		
		while(!vacia(orden) && top(orden)<top(p)){
			push(top(orden),aux);
			pop(orden);
		}
		if(!vacia(orden) && top(p) == top(orden))
			inserta(top(p),fin(l),l);
		else
			push(top(p),orden);
		pop(p);
		while(!vacia(aux)){
			push(top(aux),orden);
			pop(aux);
		}
	}
	while(!vacia(orden)){
		push(top(orden),p);
		pop(orden);
	}
	return l;
}
