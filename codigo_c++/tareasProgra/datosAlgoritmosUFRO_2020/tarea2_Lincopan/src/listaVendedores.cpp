#include <stdio.h>
#include "include/listaVendedores.h"
#include "include/manejoDatos.h"


/*
	Nombre de la función: primerElemento_lista
	Tipo de función: static int
	Parámetros: lista, de tipo listaVendedores
	Dato de retorno: 1
	Descripción de la función: Siempre devuelve 1!
*/

static int primerElemento_lista(ListaVendedores lista){
	return 1;
}

/*
	Nombre de la función: listaVendedores_vacía
	Tipo de función: bool
	Parámetros: lista, de tipo listaVendedores
	Dato de retorno: ¿?
	Descripción de la función: devuelve true si la lista está vacía, false si no
*/

bool listaVendedores_vacia(ListaVendedores lista){
	return largoLista_vendedores(lista)==primerElemento_lista(lista);
}

/*
	Nombre de la función: largoLista_vendedores
	Tipo de función: int
	Parámetros: lista, de tipo listaVendedores
	Dato de retorno: c, de tipo int
	Descripción de la función: la longitud de una lista de vendedores
*/

int largoLista_vendedores(ListaVendedores lista){
	int c=1;
	nodo*aux = lista.primero;
	while(aux!=NULL){
		aux = aux->next;
		c++;
	}
	return c;
}


/*
	Nombre de la función: insertarDato_lista
	Tipo de función: static void
	Parámetros: x, de tipo tipoDato
				p, de tipo int
				lista, de tipo &listaVendedores
	Dato de retorno: ninguno
	Descripción de la función: inserta x en la posicion p de la lista
*/

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

/*
	Nombre de la función: obtenerVendedor_lista
	Tipo de función: tipodato
	Parámetros: p, de tipo int
				lista, de tipo listaVendedores
	Dato de retorno: no sé como describirlo
	Descripción de la función: obtiene el vendedor p desde la lista dada como argumento
*/

tipoDato obtenerVendedor_lista(int p, ListaVendedores lista){
	nodo* aux = lista.primero;
	for(int i=1;i<p;i++) {
		aux=aux->next;
	}
	return aux->dato;
}

/*
	Nombre de la función: siguienteVendedor
	Tipo de función: tipodato
	Parámetros: idActual, de tipo int
				lista, de tipo listaVendedores
	Dato de retorno: devuelve un vendedor
	Descripción de la función: devuelve el vendedor idActual+1
							   desde la lista dada como parámetro
*/

tipoDato siguienteVendedor(int idActual, ListaVendedores lista) {
	nodo* aux = lista.primero;
	for(int i=1;i<idActual+1;i++) {
		aux=aux->next;
	}
	return aux->dato;
}

/*
	Nombre de la función: avanzarLista
	Tipo de función: static int
	Parámetros: p, de tipo int
				lista, de tipo listaVendedores
	Dato de retorno: p+1
	Descripción de la función: devuelve p+1
*/

static int avanzarLista(int p, ListaVendedores lista){
	return p+1;
}

/*
	Nombre de la función: imprimeLista_vendedores
	Tipo de función: void
	Parámetros: lista, de tipo ListaVendedores
	Dato de retorno: ninguno
	Descripción de la función: Imprime la lista de clientes asociada con el vendedor
							   dado como parámetro
*/

void imprimeLista_vendedores(ListaVendedores lista){
	Vendedor tmp;
		printf("__________| Nombre         |");
    	printf(" Apellido       |");
    	printf(" RUT      |");
    	printf(" Teléfono |");  
    	printf(" Dirección           |");
    	printf(" Cuenta banco |");
		printf(" Edad |");
    	printf(" Profesión:          |");
	for(int i=primerElemento_lista(lista);i<largoLista_vendedores(lista);i=avanzarLista(i,lista)){
		tmp = obtenerVendedor_lista(i, lista);
		printf("\n| ID: %d  ",i);
		mostrarDatos_vendedor(tmp);
	}
	printf("\n¯¯¯¯¯¯¯¯¯¯¯\n");
}

/*
	Nombre de la función: eliminarListaVendedores
	Tipo de función: void
	Parámetros: lista, de tipo &listaVendedores
	Dato de retorno: ninguno
	Descripción de la función: elimina de la memoria la lista dada como argumento
*/

void eliminarListaVendedores(ListaVendedores &lista){
	while(!listaVendedores_vacia(lista))
		eliminarDato_listaVendedores(primerElemento_lista(lista),lista);
}

/*
	Nombre de la función: eliminarDato_listaVendedores
	Tipo de función: void
	Parámetros: p, de tipo int
				lista, de tipo &listaVendedores
	Dato de retorno: ninguno
	Descripción de la función: elimina el dato p desde la lista dada como parámetro
*/

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

/*
	Nombre de la función: insertarUltimo_listaVendedores
	Tipo de función: void
	Parámetros: dato, de tipo dato
				lista, de tipo &listaVendedores
	Dato de retorno: ninguno
	Descripción de la función: añade un nuevo dato inmediatamente 
							   después del último elemento de la lista
*/

void insertarUltimo_listaVendedores(tipoDato dato, ListaVendedores &lista) {
  int id = largoLista_vendedores(lista);
  insertarDato_lista(dato, id, lista);
}