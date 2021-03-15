#include "include/lista.h"
#include <stdio.h>

bool listaVacia(Lista lista){
	return largoLista(lista)==primerElemento_lista(lista);
}

int primerElemento_lista(Lista lista){
	return 1;
}

int largoLista(Lista lista){
	int c=1;
	nodo*aux = lista.primero;
	while(aux!=NULL){
		aux = aux->next;
		c++;
	}
	return c;
}

int retrocederLista(int p, Lista lista){
	return p-1;
}

int avanzarLista(int p, Lista lista){
	return p+1;
}

void insertarDato_lista(tipoDato x, int p, Lista &lista){
	nodo* nuevo= new nodo(x);
	nodo* aux = lista.primero;
	if(primerElemento_lista(lista)==p){
		nuevo->next=lista.primero;
		lista.primero = nuevo;
	}else{
		for(int i=0;i<p-2;i++)
			aux=aux->next;
		nuevo->next=aux->next;
		aux->next=nuevo;
	}
}

void imprimeLista(Lista lista){
	for(int i=primerElemento_lista(lista);i<largoLista(lista);i=avanzarLista(i,lista)){
		tipoDato x = obtenerDato_lista(i,lista);
		printf("[%d]->",x);
	}
	printf("\n");
}


void eliminarLista(Lista &lista){
	while(!listaVacia(lista))
		eliminarDato_lista(primerElemento_lista(lista),lista);
}

int localizarDato_lista(tipoDato x, Lista lista){
	for(int i=primerElemento_lista(lista);i<largoLista(lista);i=avanzarLista(i,lista)) {
		if(obtenerDato_lista(i,lista)==x) {
			return i;
		}
	}
	return largoLista(lista);
}

tipoDato obtenerDato_lista(int p, Lista lista){
	nodo* aux = lista.primero;
	for(int i=1;i<p;i++) {
		aux=aux->next;
	}
	return aux->dato;
}
void eliminarDato_lista(int p, Lista &lista){
	nodo* aux = lista.primero;
	if(primerElemento_lista(lista)==p) {
		lista.primero=aux->next;

	} else{
		nodo* aux2 = lista.primero;
		for(int i=0;i<p-2;i++)
			aux2=aux2->next;
		aux=aux2->next;
		aux2->next = aux->next;
	}
	aux->next = NULL;
	delete aux;
}

//añade un nuevo dato inmediatamente después del último elemento de la lista
void insertarUltimo_lista(tipoDato dato, Lista &lista) {
  int id = largoLista(lista);
  insertarDato_lista(dato, id, lista);
}