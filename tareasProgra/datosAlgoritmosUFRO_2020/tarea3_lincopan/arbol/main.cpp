#include <stdio.h>
#include "arbol.h"
#include "../pila/pila.h"

void ordenPrevio(Arbol n);
void ordenPosterior(Arbol n);
void ordenSimetrico(Arbol n);

void imprimePar(Arbol n);
void imprimeNivel(Arbol n, int nivel);
void nivel(Arbol n, int nivel);
void altura(Arbol n, int nivel, int &h);
void altura2(Arbol n, int nivel, int &h);
void arbolOStoPila(Arbol n, Pila &p);

void ordenSimetrico2(Arbol n);

Arbol creaArbolEjemplo();

void reEtiqueta2(datoArbol e, Arbol & n);

int numeroHijos(Arbol A, tipoDato B);

int main(){
	Arbol a = creaArbolEjemplo();
	tipoDato b = recupera(3,a.primero->dato.hijos);
	
	imprime(a.primero->dato.hijos);
	imprime(b.hijos);
	return 0;
}

int numeroHijos(Arbol A, tipoDato B){
	if(B.primero->dato.dato == A.primero->dato.dato){
		int contador = fin(A.primero->dato.hijos)-1;
		return contador;
		}	else {
			if(B.primero->dato.dato == A.primero->dato.hijos.primero->dato.dato){
				int contador = fin(A.primero->dato.hijos)-1;
				return contador;
				}
			}
	return 0;
	}


void reEtiqueta2(datoArbol e, Arbol & n){
	tipoDato nodoAux = recupera(primero(n),n);
	n.primero->dato.dato = e;
}

Arbol creaArbolEjemplo(){
	Arbol n1 = creaRaiz(1);
	Arbol n2 = creaRaiz(2);
	Arbol n3 = creaRaiz(3);
	Arbol n4 = creaRaiz(4);
	Arbol n5 = creaRaiz(5);
	Arbol n6 = creaRaiz(6);
	Arbol n7 = creaRaiz(7);
	Arbol n8 = creaRaiz(8);
	Arbol n9 = creaRaiz(9);
	Arbol n10 = creaRaiz(10);
	
	insertaHijoMasIzq(n1,n2);
	n2 = hijoMasIzq(n1);
	insertaHermanoDer(n2,n3);
	n3 = hermanoDer(n2);
	insertaHermanoDer(n3,n4);
	n4 = hermanoDer(n3);
	insertaHijoMasIzq(n3,n5);
	n5 = hijoMasIzq(n3);
	insertaHermanoDer(n5,n6);
	n6 = hermanoDer(n5);
	insertaHijoMasIzq(n4,n7);
	n7 = hijoMasIzq(n4);
	insertaHijoMasIzq(n5,n8);
	n8 = hijoMasIzq(n5);
	insertaHermanoDer(n8,n9);
	n9 = hermanoDer(n8);
	insertaHijoMasIzq(n6,n10);
	n10 = hijoMasIzq(n6);
		
	return n1;
	}

void imprimePar(Arbol n){
	for(Arbol c=hijoMasIzq(n); !esNulo(c); c=hermanoDer(c))
		imprimePar(c);
	datoArbol dato = etiqueta(n);
	if(dato%2==0)
		printf("%d ",dato);
}
void imprimeNivel(Arbol n, int nivel){
	datoArbol dato = etiqueta(n);
	printf("%d [%d] ",dato,nivel);
	nivel++;
	for(Arbol c=hijoMasIzq(n); !esNulo(c); c=hermanoDer(c))
		imprimeNivel(c, nivel);
}
void altura(Arbol n, int nivel, int &h){
	if(nivel>h)
		h=nivel;
	nivel++;
	for(Arbol c=hijoMasIzq(n); !esNulo(c); c=hermanoDer(c))
		altura(c, nivel,h);	
}
void altura2(Arbol n, int nivel, int &h){
	h=nivel;
	nivel++;
	if(h<=nivel)
		h=nivel-1;
	for(Arbol c=hijoMasIzq(n); !esNulo(c); c=hermanoDer(c))
		altura2(c, nivel,h);	
}
void nivel(Arbol n, int h){
	datoArbol dato = etiqueta(n);
	Arbol c=hijoMasIzq(n);
	if(!esNulo(c)){
		h++;
		nivel(c, h);
		printf("%d [%d] ",dato,h);
		for(Arbol c=hermanoDer(c); !esNulo(c); c=hermanoDer(c))
			nivel(c, h);
	}
}
void ordenSimetrico(Arbol n){
	if(!esHoja(n)){
		ordenSimetrico(hijoMasIzq(n));
	}
	datoArbol dato = etiqueta(n);
	printf("%d ",dato);
	if(!esHoja(n))
		for(Arbol c=hermanoDer(hijoMasIzq(n)); !esNulo(c); c=hermanoDer(c))
			ordenSimetrico(c);
}
void ordenSimetrico2(Arbol n){
		for(Arbol c=hermanoDer(hijoMasIzq(n)); !esNulo(c); c=hermanoDer(c)){
			datoArbol dato = etiqueta(n);
			printf("%d ",dato);
			ordenSimetrico2(c);
		}
		datoArbol dato = etiqueta(n);
			printf("%d ",dato);
}
/*
void arbolOStoPila(Arbol n, Pila &p){
	if(!esHoja(n)){
		arbolOStoPila(hijoMasIzq(n),p);
	}
	datoArbol dato = etiqueta(n);
	push(dato,p);
	if(!esHoja(n))
		for(Arbol c=hermanoDer(hijoMasIzq(n)); !esNulo(c); c=hermanoDer(c))
			arbolOStoPila(c,p);
}*/

void ordenPrevio(Arbol n){
	datoArbol dato = etiqueta(n);
	printf("%d ",dato);
	for(Arbol c=hijoMasIzq(n); !esNulo(c); c=hermanoDer(c))
		ordenPrevio(c);
}

void ordenPosterior(Arbol n){
	for(Arbol c=hijoMasIzq(n); !esNulo(c); c=hermanoDer(c))
		ordenPosterior(c);
	datoArbol dato = etiqueta(n);
	printf("%d ",dato);
}
