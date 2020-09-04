#ifndef MANEJO_ARCHIVOS_H
    #define MANEJO_ARCHIVOS_H
    #define RUTA_DATOS "datos/datos.bin"
    #define FIN_VENDEDOR "|FIN_VENDEDOR|"

    #include <stdio.h>
    #include <stdlib.h>
    #include "manejoDatos.h"

    void extraerVendedor_binario(Vendedor &buffer, int idVendedor);
    void extraerListaVendedores_binario(ListaVendedores &lista);
    void escribirListaVendedores_binario(ListaVendedores datos);

#endif    