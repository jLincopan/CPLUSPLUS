#ifndef _ARBOL_BIN_H_
    #define _ARBOL_BIN_H_
    #include "../arbol/arbol.h"
    #include "arbolBinStruct.h"

    ArbolBin arbolToBin(Arbol n);
    ArbolBin creaNodo(datoArbol u);
    ArbolBin hijoIzq(ArbolBin n);
    ArbolBin hijoDer(ArbolBin n);
    void insertaHijoIzq(ArbolBin & n, ArbolBin & Ti);
    void insertaHijoDer(ArbolBin & n, ArbolBin & Td);
    datoArbol etiqueta(ArbolBin n);
    void reEtiqueta(datoArbol e, ArbolBin & n, ArbolBin raiz);
    ArbolBin padre(ArbolBin n, ArbolBin raiz);
    ArbolBin raiz(ArbolBin raiz);
    void anula(ArbolBin & raiz);
    ArbolBin podarHijoIzq(ArbolBin  & n);
    ArbolBin podarHijoDer(ArbolBin  & n);

    // Adicionales al TDA
    bool esHoja(ArbolBin n);
    bool esNulo(ArbolBin n);
    bool esNodoTerminal(ArbolBin n);
    void ordenSimetrico(ArbolBin n);
    void ordenPrevio(ArbolBin n);
    void ordenPosterior(ArbolBin n);
    datoArbol registrarDatos(unsigned int generacion, const char nombre[], const char nacimiento[], const char fallecimiento[]);
    void mostrarDatos(ArbolBin dato);
    void mostrarNombre(ArbolBin dato);
    void mostrarNivel(ArbolBin raiz, int nivel);
    void mostrarArbolBinario(ArbolBin raiz);
#endif