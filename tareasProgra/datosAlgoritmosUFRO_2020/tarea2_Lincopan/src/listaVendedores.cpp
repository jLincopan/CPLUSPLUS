#include <stdio.h>
#include "include/listaVendedores.h"
#include "include/manejoDatos.h"

static int primerElemento_lista(ListaVendedores lista){
	return 1;
}

bool listaVendedores_vacia(ListaVendedores lista){
	return largoLista_vendedores(lista)==primerElemento_lista(lista);
}

int largoLista_vendedores(ListaVendedores lista){
	int c=1;
	nodo*aux = lista.primero;
	while(aux!=NULL){
		aux = aux->next;
		c++;
	}
	return c;
}

static int avanzarLista(int p, ListaVendedores lista){
	return p+1;
}

static void insertarDato_lista(tipoDato x, int p, ListaVendedores &lista){
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

tipoDato obtenerVendedor_lista(int p, ListaVendedores lista){
	nodo* aux = lista.primero;
	for(int i=1;i<p;i++) {
		aux=aux->next;
	}
	return aux->dato;
}

void imprimeLista_vendedores(ListaVendedores lista){
	Vendedor tmp;
	for(int i=primerElemento_lista(lista);i<largoLista_vendedores(lista);i=avanzarLista(i,lista)){
		tmp = obtenerVendedor_lista(i, lista);
		printf("\n\n[ID: %d]\n",i);
		mostrarDatos_vendedor(tmp);
	}
	printf("\n");
}


void eliminarLista(ListaVendedores &lista){
	while(!listaVendedores_vacia(lista))
		eliminarDato_listaVendedores(primerElemento_lista(lista),lista);
}

void eliminarDato_listaVendedores(int p, ListaVendedores &lista){
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
void insertarUltimo_listaVendedores(tipoDato dato, ListaVendedores &lista) {
  int id = largoLista_vendedores(lista);
  insertarDato_lista(dato, id, lista);
}