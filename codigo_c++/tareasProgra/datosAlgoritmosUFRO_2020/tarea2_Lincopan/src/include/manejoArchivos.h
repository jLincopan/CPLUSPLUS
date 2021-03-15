#ifndef MANEJO_ARCHIVOS_H
    #define MANEJO_ARCHIVOS_H
    #define RUTA_DATOS "datos/datos.bin" //ruta del archivo desde el que se leen datos, y donde se escriben
    #define FIN_VENDEDOR "|FIN_VENDEDOR|" //cadena que señana el fin de cada vendedor y sus clientes

    #include <stdio.h>
    #include <stdlib.h>
    #include "manejoDatos.h"

    void extraerListaVendedores_binario(ListaVendedores &lista);
    void guardarListaVendedores_binario(ListaVendedores datos);

#endif    