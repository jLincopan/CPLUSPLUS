#ifndef LISTA_STRUCT_VENDEDORES_H
	#define LISTA_STRUCT_VENDEDORES_H

	#include <stdio.h>
	#include "structCliente.h"
	#define tipoDato2 Cliente

struct nodo2{
	tipoDato2 dato;
	struct nodo2* next;
	nodo2(){
		next=NULL;
	}
	nodo2(tipoDato2 x){
		nodo2();
		dato=x;
	}
};

struct ListaClientes //define las listas de clientes a usar
{
	struct nodo2* primero;
	ListaClientes(){
		primero=NULL;
	}
};


#endif