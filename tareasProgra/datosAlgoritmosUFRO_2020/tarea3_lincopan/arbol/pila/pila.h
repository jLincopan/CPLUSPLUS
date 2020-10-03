#include <stdio.h>
#include "../lista/lista.h"
#include "pilaStruct.h"

void anula(Pila &p);
bool vacia(Pila p);
tipoDato top(Pila p);
void pop(Pila &p);
void push(tipoDato x, Pila &p);
void imprime(Pila pila);
