#include <stdio.h>
#include <string.h>
#include "include/listaVendedores.h"
#include "include/listaClientes.h"
#include "include/manejoDatos.h"

int main() {

    ListaVendedores vendedores;

	registrarVendedor(vendedores);
    registrarCliente(1, vendedores);
    registrarCliente(1, vendedores);

    buscarCliente_rut(vendedores);
    return 0;
}