#include <stdio.h>

#include "include/manejoPantalla.h"
#include "include/manejoDatos.h"
#include "include/listaClientes.h"
#include "include/listaStructClientes.h"

/*
	Nombre de la función: primerElemento_lista
	Tipo de función: static int
	Parámetros: lista, de tipo listaClientes
	Dato de retorno: 1
	Descripción de la función: Siempre devuelve 1!
*/

static int primerElemento_lista(ListaClientes lista){
	return 1;
}

/*
	Nombre de la función: listaClientes_vacía
	Tipo de función: bool
	Parámetros: lista, de tipo listaClientes
	Dato de retorno: ¿?
	Descripción de la función: devuelve true si la lista está vacía, false si no
*/

bool listaClientes_vacia(ListaClientes lista){
	return largoLista_clientes(lista)==primerElemento_lista(lista);
}

/*
	Nombre de la función: largoLista_clientes
	Tipo de función: int
	Parámetros: lista, de tipo listaClientes
	Dato de retorno: c, de tipo int
	Descripción de la función: la longitud de una lista de clientes
*/

int largoLista_clientes(ListaClientes lista){
	int c=1;
	nodo2* aux = lista.primero;
	while(aux!=NULL){
		aux = aux->next;
		c++;
	}
	return c;
}

/*
	Nombre de la función: avanzarLista
	Tipo de función: static int
	Parámetros: p, de tipo int
				lista, de tipo listaClientes
	Dato de retorno: p+1
	Descripción de la función: devuelve p+1
*/

static int avanzarLista(int p, ListaClientes lista){
	return p+1;
}

/*
	Nombre de la función: insertarDato_lista
	Tipo de función: static void
	Parámetros: x, de tipo tipoDato2
				p, de tipo int
				lista, de tipo &listaClientes
	Dato de retorno: ninguno
	Descripción de la función: inserta x en la posicion p de la lista
*/

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

/*
	Nombre de la función: eliminarListaClientes
	Tipo de función: void
	Parámetros: lista, de tipo &listaClientes
	Dato de retorno: ninguno
	Descripción de la función: elimina de la memoria la lista dada como argumento
*/

void eliminarListaClientes(ListaClientes &lista){
	while(!listaClientes_vacia(lista))
		eliminarDato_listaClientes(primerElemento_lista(lista),lista);
}

/*
	Nombre de la función: obtenerCliente_lista
	Tipo de función: tipodato2
	Parámetros: p, de tipo int
				lista, de tipo listaClientes
	Dato de retorno: no sé como describirlo
	Descripción de la función: obtiene el cliente p desde la lista dada como argumento
*/

tipoDato2 obtenerCliente_lista(int p, ListaClientes lista){
	nodo2* aux = lista.primero;
	for(int i=1;i<p;i++) {
		aux=aux->next;
	}
	return aux->dato;
}

/*
	Nombre de la función: eliminarDato_listaClientes
	Tipo de función: void
	Parámetros: p, de tipo int
				lista, de tipo listaClientes
	Dato de retorno: ninguno
	Descripción de la función: elimina el dato p desde la lista dada como parámetro
*/

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

/*
	Nombre de la función: imprimeLista_clientes
	Tipo de función: void
	Parámetros: vendedor, de tipo &Vendedor
	Dato de retorno: ninguno
	Descripción de la función: Imprime la lista de clientes asociada con el vendedor
							   dado como parámetro
*/

void imprimeLista_clientes(Vendedor &vendedor){
	ListaClientes lista = vendedor.clientes;
	Cliente tmp;
	printf("__________| Nombre         |" );
    printf(" Apellido       |");
    printf(" RUT      |");
    printf(" Teléfono |");  
    printf(" Dirección           |");
	printf(" Edad |");
    printf(" Profesión:           |");
    printf(" Deuda   |");
    printf(" Fecha de cobro |\n");
	for(int i=primerElemento_lista(lista);i<largoLista_clientes(lista);i=avanzarLista(i,lista)){
		tmp = obtenerCliente_lista(i, lista);
		printf("| ID: %d  ",i);
		mostrarDatos_cliente(tmp);
	}
	printf("¯¯¯¯¯¯¯¯¯¯¯\n");
}

/*
	Nombre de la función: insertarUltimo_listaClientes
	Tipo de función: void
	Parámetros: dato, de tipo dato2
				lista, de tipo &listaClientes
	Dato de retorno: ninguno
	Descripción de la función: añade un nuevo dato inmediatamente 
							   después del último elemento de la lista
*/

void insertarUltimo_listaClientes(tipoDato2 dato, ListaClientes &lista) {
  int id = largoLista_clientes(lista);
  insertarDato_lista(dato, id, lista);
}