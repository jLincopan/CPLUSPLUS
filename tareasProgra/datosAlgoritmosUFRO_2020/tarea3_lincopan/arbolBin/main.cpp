#include <stdio.h>
#include <string.h> 
#include "arbolBin.h"

int main(){
	
	ArbolBin raiz = creaNodo(registrarDatos(1, "Raul", "1901-01-27", "1985-04-15"));

	ArbolBin maria = creaNodo(registrarDatos(2, "María", "1925-09-12", "1967-02-10"));
	ArbolBin josefina = creaNodo(registrarDatos(2, "Josefina", "1930-02-14", "1990-12-02"));

	ArbolBin tomas = creaNodo(registrarDatos(3, "Tomás", "1950-05-22", " "));
	ArbolBin jose = creaNodo(registrarDatos(3, "José", "1952-12-17", "1957-07-29"));
	ArbolBin rafael = creaNodo(registrarDatos(3, "Rafael", "1950-09-14", " "));
	ArbolBin camila = creaNodo(registrarDatos(3, "Camila", "1960-07-07", " "));

	ArbolBin josefa = creaNodo(registrarDatos(4, "Josefa", "1984-08-02", " "));
	ArbolBin felipe = creaNodo(registrarDatos(4, "Felipe", "1980-12-02", " "));
	ArbolBin valentina = creaNodo(registrarDatos(4, "Valentina", "1982-04-04", " "));

	ArbolBin ignacio = creaNodo(registrarDatos(5, "Ignacio", "2009-12-12", " "));
	ArbolBin pedro = creaNodo(registrarDatos(5, "Pedro", "2011-03-24", " "));


	printf("\n");
	
	insertaHijoIzq(raiz, maria);
	maria = hijoIzq(raiz);
	insertaHijoDer(raiz, josefina);
	josefina = hijoDer(raiz);

	insertaHijoIzq(josefina, rafael);
	rafael = hijoIzq(josefina);
	insertaHijoDer(josefina, camila);
	camila = hijoDer(josefina);

	insertaHijoIzq(maria, tomas);
	tomas = hijoIzq(maria);
	insertaHijoDer(maria, jose);
	jose = hijoDer(maria);

	insertaHijoIzq(rafael, felipe);
	felipe = hijoIzq(rafael);
	insertaHijoDer(rafael, valentina);
	valentina = hijoDer(rafael);

	insertaHijoDer(tomas, josefa);
	josefa = hijoDer(tomas);

	insertaHijoIzq(valentina, ignacio);
	ignacio = hijoIzq(valentina);
	insertaHijoDer(valentina, pedro);
	pedro = hijoDer(valentina);


	mostrarArbolBinario(raiz);
	return 0;
}
