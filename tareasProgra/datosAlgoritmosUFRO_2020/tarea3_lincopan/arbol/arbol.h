#include "./lista/lista.h"
#include "arbolStruct.h"

Arbol creaRaiz(datoArbol u);
void anula(Arbol &raiz);
Arbol padre(Arbol n, Arbol raiz);
Arbol hijoMasIzq(Arbol n);
Arbol hermanoDer(Arbol n);
datoArbol etiqueta(Arbol n);
void reEtiqueta(datoArbol e, Arbol & n, Arbol raiz);
Arbol raiz(Arbol raiz);
void insertaHijoMasIzq(Arbol & n, Arbol & Ti);
void insertaHermanoDer(Arbol & n, Arbol & Td);
Arbol podarHijoMasIzq(Arbol n);
Arbol podarHermanoDer(Arbol n);

bool esHijo(Arbol n, Arbol padre);
bool esHoja(Arbol n);
bool esNulo(Arbol n);
Arbol& listaHijos(Arbol n);
