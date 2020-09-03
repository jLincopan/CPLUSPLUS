#ifndef MANEJO_ARCHIVOS_H
    #define MANEJO_ARCHIVOS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "manejoDatos.h"

    void extraerVendedor_binario(Vendedor &buffer, int idVendedor);
    void extraerListaVendedores_binario(ListaVendedores &lista);
    void escribirDato_binario(ListaVendedores datos);
     void prueba(ListaVendedores &lista);

#endif    