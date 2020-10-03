#include <stdio.h>
#include <string.h> 
#include "arbolBin.h"

int main(){
	
	ArbolBin raiz = creaNodo(registrarDatos(1, "Raul", "1901-01-27", "1985-04-15"));

	ArbolBin n2 = creaNodo(registrarDatos(2, "María", "1925-09-12", "1967-02-10"));
	ArbolBin n3 = creaNodo(registrarDatos(2, "Josefina", "1930-02-14", "1990-12-02"));

	ArbolBin n4 = creaNodo(registrarDatos(3, "Tomás", "1950-05-22", " "));
	ArbolBin n5 = creaNodo(registrarDatos(3, "José", "1952-12-17", "1957-07-29"));
	ArbolBin n6 = creaNodo(registrarDatos(3, "Rafael", "1950-09-14", " "));
	ArbolBin n7 = creaNodo(registrarDatos(3, "Camila", "1960-07-07", " "));

	ArbolBin n8 = creaNodo(registrarDatos(4, "Josefa", "1984-08-02", " "));
	ArbolBin n9 = creaNodo(registrarDatos(4, "Felipe", "1980-12-02", " "));
	ArbolBin n10 = creaNodo(registrarDatos(4, "Valentina", "1982-04-04", " "));

	ArbolBin n11 = creaNodo(registrarDatos(5, "Ignacio", "2009-12-12", " "));
	ArbolBin n12 = creaNodo(registrarDatos(5, "Pedro", "2011-03-24", " "));

	insertaHijoMasIzq(n10, n12);
	insertaHijoMasIzq(n10, n11);

	insertaHijoMasIzq(n6,n10);
	insertaHijoMasIzq(n6, n9);

	insertaHijoMasIzq(n3, n7);
	insertaHijoMasIzq(n3, n6);


	insertaHijoMasIzq(n4, n8);

	insertaHijoMasIzq(n2, n5);
	insertaHijoMasIzq(n2, n4);

	insertaHijoMasIzq(raiz, n3);
	insertaHijoMasIzq(raiz, n2);
	
	printf("\n");
	ordenPosterior(raiz);
	return 0;
}
