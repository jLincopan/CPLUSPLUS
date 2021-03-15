#ifndef _PANTALLA_H_
    #define _PANTALLA_H_

    #include "manejoDatos.h"
    #include "listaVendedores.h"
    #include "listaClientes.h"

    void vaciarStdin();
    void pausa();
    void limpiarPantalla();
    void mostrarDatos_vendedor(Vendedor vendedor);
    void mostrarDatos_cliente(Cliente cliente);
    void mostrarDatos_clientes(ListaVendedores &vendedores);
    void menuPrincipal(ListaVendedores &vendedores);

#endif