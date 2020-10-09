#ifndef _ARBOL_BIN_H_
    #define _ARBOL_BIN_H_
    #include "../arbol/arbol.h"
    #include "arbolBinStruct.h"

    static datoArbol NODO_NULO = {0};

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
    void buscarPorNombre(ArbolBin n, ArbolBin &buffer, const char nombre[sizeof(NODO_NULO.nombre)]);
    void mostrarNivel(ArbolBin raiz, int nivel);
    void mostrarArbolBinario(ArbolBin raiz);
    void buscarPadrePorNombre(ArbolBin &raiz);
    void encontrarPadre(ArbolBin raiz, char nombre[sizeof(NODO_NULO.nombre)], ArbolBin &buffer);
    void buscarHijosPorNombre(ArbolBin raiz);
    void familiaresConVida(ArbolBin &raiz);
    void editarDatosPorNombre(ArbolBin raiz);
    int leerInt();
    void generacionPorNombre(ArbolBin raiz);
    void familiarMasLongevo(ArbolBin raiz);
#endif