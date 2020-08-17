#include <stdio.h>
#include <string.h>
#include "include/listaVendedores.h"
#include "include/listaClientes.h"
#include "include/manejoDatos.h"

int main() {

    ListaVendedores vendedores;

	registrarVendedor(vendedores);
	registrarVendedor(vendedores);
	registrarVendedor(vendedores);
    imprimeLista_vendedores(vendedores);
    
    eliminarVendedor_rut(vendedores);
    imprimeLista_vendedores(vendedores);
    return 0;
}