#ifndef LISTA_STRUCT_H
	#define LISTA_STRUCT_H

	#include <stdio.h>
	#include "structVendedor.h"
	#define tipoDato Vendedor

struct nodo{
	tipoDato dato;
	struct nodo* next;
	nodo(){
		next=NULL;
	}
	nodo(tipoDato x){
		nodo();
		dato=x;
	}
};

struct ListaVendedores{
	struct nodo* primero;
	ListaVendedores(){
		primero=NULL;
	}
};

#endif
