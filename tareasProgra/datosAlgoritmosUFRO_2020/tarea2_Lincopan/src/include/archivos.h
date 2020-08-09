#ifndef ARCHIVOS_H

    #define ARCHIVOS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "datos.h"

    int leerRegistro(datos *buffer, unsigned int ID);
    int guardarRegistro(datos *guardar);
    void guardarRegistro_ID(datos *guardar, int ID);
    void guardarID(int id);
    void borrarRegistro(unsigned int id);
    extern int ID_MAX;
#endif