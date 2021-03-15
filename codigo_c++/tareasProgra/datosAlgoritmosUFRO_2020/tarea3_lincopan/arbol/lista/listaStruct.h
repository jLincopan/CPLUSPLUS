#ifndef LISTA_STRUCT_H
#define LISTA_STRUCT_H

struct Lista{
	struct nodo* primero;
	Lista(){
		primero=NULL;
	}
};

struct Arbol:Lista{
	
};

struct datoArbol {
	unsigned int generacion = 0;
	char nombre[20] = {0};
	char fecha_nacimiento[11] = {0};
	char fecha_fallecimiento[11] = {0};
};


struct nodoArbol{
	datoArbol dato;
	Arbol hijos;
};

#define tipoDato nodoArbol
/* Estructuras*/


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

#endif

