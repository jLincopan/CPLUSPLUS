#include <stdio.h>
#include <string.h>
#include "include/listaVendedores.h"
#include "include/listaClientes.h"
#include "include/manejoDatos.h"
#include "include/manejoArchivos.h"

int main() {

    ListaVendedores vendedores;
    ListaVendedores tmp;

    registrarVendedor(vendedores);
    registrarCliente(vendedores);

    //escribirDato_binario(vendedores); si descomento esa linea todo funciona... ¿Por qué?
    
    extraerListaVendedores_binario(tmp);
    mostrarDatos_clientes(tmp);
    return 0;
}