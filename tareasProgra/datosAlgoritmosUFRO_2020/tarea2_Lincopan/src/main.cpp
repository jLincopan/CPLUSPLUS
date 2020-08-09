#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include "include/manejoDatos.h"

int main() {
    cabeceraVendedor inicioLista_vendedores;
    inicioLista_vendedores.largo = 0;

    nodoVendedor* vendedorTMP;
    Vendedor tmp;



	char caca[10];

	registrarVendedor(tmp);
	mostrarDatos_vendedor(tmp);	
    return 0;
}