#include <stdio.h>
#include <string.h>
#include "include/listaVendedores.h"
#include "include/listaClientes.h"
#include "include/manejoDatos.h"

int main() {
    Vendedor tmp;
    Cliente cliente_tmp;

    ListaVendedores vendedores;
    //ListaClientes clientes;
	registrarVendedor(vendedores);
    insertarUltimo_listaVendedores(tmp, vendedores);

    registrarCliente(cliente_tmp, tmp);
    registrarCliente(cliente_tmp, tmp);
    registrarCliente(cliente_tmp, tmp);

    mostrarDatos_clientes(1, vendedores);

    return 0;
}