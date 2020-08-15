#include <stdio.h>

#include "include/manejoDatos.h"
#include "include/listaClientes.h"
#include "include/listaStructClientes.h"

static int primerElemento_lista(ListaClientes lista){
	return 1;
}

bool listaClientes_vacia(ListaClientes lista){
	return largoLista_clientes(lista)==primerElemento_lista(lista);
}


int largoLista_clientes(ListaClientes lista){
	int c=1;
	nodo2* aux = lista.primero;
	while(aux!=NULL){
		aux = aux->next;
		c++;
	}
	return c;
}

static int avanzarLista(int p, ListaClientes lista){
	return p+1;
}

static void insertarDato_lista(tipoDato2 x, int p, ListaClientes &lista){
	nodo2* nuevo= new nodo2(x);
	nodo2* aux = lista.primero;
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

void eliminarListaClientes(ListaClientes &lista){
	while(!listaClientes_vacia(lista))
		eliminarDato_listaClientes(primerElemento_lista(lista),lista);
}

/*
int localizarDato_lista(tipoDato x, Lista lista){
	for(int i=primerElemento_lista(lista);i<largoLista(lista);i=avanzarLista(i,lista)) {
		if(obtenerDato_lista(i,lista)==x) {
			return i;
		}
	}
	return largoLista(lista);
}
*/

static tipoDato2 obtenerDato_lista(int p, ListaClientes lista){
	nodo2* aux = lista.primero;
	for(int i=1;i<p;i++) {
		aux=aux->next;
	}
	return aux->dato;
}
void eliminarDato_listaClientes(int p, ListaClientes &lista){
	nodo2* aux = lista.primero;
	if(primerElemento_lista(lista)==p) {
		lista.primero=aux->next;

	} else{
		nodo2* aux2 = lista.primero;
		for(int i=0;i<p-2;i++)
			aux2=aux2->next;
		aux=aux2->next;
		aux2->next = aux->next;
	}
	aux->next = NULL;
	delete aux;
}

void imprimeLista_clientes(Vendedor &vendedor){
	ListaClientes lista;
	Cliente tmp;
	for(int i=primerElemento_lista(lista);i<largoLista_clientes(lista);i=avanzarLista(i,lista)){
		tmp = obtenerDato_lista(i, lista);
		printf("\n\n[ID: %d]\n",i);
		mostrarDatos_cliente(tmp);
	}
	printf("\n");
}

//añade un nuevo dato inmediatamente después del último elemento de la lista
void insertarUltimo_listaClientes(tipoDato2 dato, ListaClientes &lista) {
  int id = largoLista_clientes(lista);
  insertarDato_lista(dato, id, lista);
}