#ifndef __PILA_H__
    #define __PILA_H__
    #include "lista.h"
    #include "pilaStruct.h"

    // PROTOTIPOS
    bool pilaVacia(Pila p);
    void push(tipoDato x, Pila &p);
    void pop(Pila &p);
    tipoDato top(Pila p);
    void borrarPila(Pila &p);
    int localizarDato_pila(Pila &p, tipoDato x);
    void imprimirPila(Pila p);
    void suprimirElemento_pila(int id, Pila &pila);

#endif