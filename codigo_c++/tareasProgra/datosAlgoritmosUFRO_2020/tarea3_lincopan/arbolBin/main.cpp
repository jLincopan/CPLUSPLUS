/*	Universidad de La Frontera
*	Ingeniería Civil Telemática
*	IIE-344 Estructura de Datos y Algoritmos
*	Tarea 3
*	Autor: Javier Lincopán (j.lincopan01@gmail.com)
*	Fecha: 08/10/2020
*  	Descripción general del programa: ¡Programa para manejar un 
*									  árbol genealógico!
*/

/*⚠️⚠️⚠️______________ALERTA DE CÓDIGO SPAGUETTI______________⚠️⚠️⚠️
* Esta tarea se hizo más o menos a la rápida y por tanto, contiene
* una alta dosis de código spaguetti, se recomienda discreción
*/


#include <stdio.h>
#include <string.h> 
#include "arbolBin.h"

/* Nombre de la función: main.
* Tipo de función: int.
* Parámetros: ninguno.
* Dato de retorno: 0 si no hay errores
* Descripción de la función: Es la función principal del programa,
* crea el árbol, muestra un menú y llama otras funciones dependiendo
* de las opciones ingresadas
*/

int main(){
	
	ArbolBin raiz = creaNodo(registrarDatos(1, "Raul", "1901-01-27", "1985-04-15"));

	ArbolBin maria = creaNodo(registrarDatos(2, "María", "1925-09-12", "1967-02-10"));
	ArbolBin josefina = creaNodo(registrarDatos(2, "Josefina", "1930-02-14", "1990-12-02"));

	ArbolBin tomas = creaNodo(registrarDatos(3, "Tomás", "1950-05-22", "-"));
	ArbolBin jose = creaNodo(registrarDatos(3, "José", "1952-12-17", "1957-07-29"));
	ArbolBin rafael = creaNodo(registrarDatos(3, "Rafael", "1950-09-14", "-"));
	ArbolBin camila = creaNodo(registrarDatos(3, "Camila", "1960-07-07", "-"));

	ArbolBin josefa = creaNodo(registrarDatos(4, "Josefa", "1984-08-02", "-"));
	ArbolBin felipe = creaNodo(registrarDatos(4, "Felipe", "1980-12-02", "-"));
	ArbolBin valentina = creaNodo(registrarDatos(4, "Valentina", "1982-04-04", "-"));

	ArbolBin ignacio = creaNodo(registrarDatos(5, "Ignacio", "2009-12-12", "-"));
	ArbolBin pedro = creaNodo(registrarDatos(5, "Pedro", "2011-03-24", "-"));
	
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

	//Menu principal
	int opcion = 0;

	while (1) {
		printf("\nElija una opción\n");
		printf("\n1) Mostrar el árbol\n");
		printf("2) Mostrar hijos de una persona\n");
		printf("3) Buscar el padre de ina persona\n");
		printf("4) Mostrar la generación a la que pertenece alguien\n");
		printf("5) Modificar los datos de alguien\n");
		printf("6) Mostrar la cantidad de familiares con vida\n");
		printf("7) Mostrar el familiar más longevo\n");
		printf("8) Salir\n\n");

		opcion = leerInt();
		getchar();
		switch (opcion)
		{
		case 1:
			mostrarArbolBinario(raiz);
			break;
		case 2:
			buscarHijosPorNombre(raiz);
			break;
		case 3:
			buscarPadrePorNombre(raiz);
			break;
		case 4:
			generacionPorNombre(raiz);
			break;
		case 5:
			editarDatosPorNombre(raiz);
			break;
		case 6:
			familiaresConVida(raiz);
			break;
		case 7:
			familiarMasLongevo(raiz);
			break;
		case 8:
			return 0;
		default:
			printf("\nError, el dato ingresado no es válido\n");
			break;
		}
	}
	

	return 0;
}
