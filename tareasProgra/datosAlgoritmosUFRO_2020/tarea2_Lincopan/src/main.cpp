#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include "include/manejoDatos.h"

int main() {
    cabeceraVendedor inicioLista_vendedores;
    inicioLista_vendedores.largo = 0;

    nodoVendedor* nodoVendedores = new nodoVendedor;
    Vendedor tmp;

	registrarVendedor(tmp);
	nodoVendedores->dato = tmp;

	mostrarDatos_vendedor(nodoVendedores->dato);	

    return 0;
}