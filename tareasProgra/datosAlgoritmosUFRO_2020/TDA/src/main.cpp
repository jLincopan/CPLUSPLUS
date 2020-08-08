#include <stdio.h>
#include "include/lista.h"
#include "include/cola.h"
#include "include/pila.h"

int main() {
	Lista a;

  printf("\n\n");
	insertarDato_lista(8,1,a);
  insertarUltimo_lista(2,a);
  insertarUltimo_lista(3,a);
	imprimeLista(a);

	Cola c;
	ponerEnCola(5,c);
	ponerEnCola(3,c);
	ponerEnCola(2,c);
	ponerEnCola(1,c);


	imprimeCola(c);
	imprimeCola(c);

	Pila p;
	printf("\n");
	push(7,p);
	push(2,p);
	push(15,p);
	push(23,p);
	push(70,p);
	push(20,p);
	imprimirPila(p);
	suprimirElemento_pila(0, p);	
	imprimirPila(p);

  return 0;
}