#ifndef __COLA_H__
    #define __COLA_H__
    #include "lista.h"
    #include "colaStruct.h"

    // PROTOTIPOS 
    bool colaVacia(Cola c);
    tipoDato primerElemento_cola(Cola c);
    void ponerEnCola(tipoDato x, Cola &c);
    void quitarDeCola(Cola &c);
    void eliminarCola(Cola &c);
    void imprimeCola(Cola c);
    void suprimirElemento_cola(int pos, Cola &c);

#endif
