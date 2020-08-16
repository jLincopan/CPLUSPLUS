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
    registrarCliente(1, vendedores);

    mostrarDatos_clientes(1, vendedores);
    printf("\nTotal a cobrar para el vendedor 1: %i", calcularCobro_vendedor(1, vendedores));
    return 0;
}