#include <stdio.h>
#include <string.h>
#include "include/listaVendedores.h"
#include "include/listaClientes.h"
#include "include/manejoDatos.h"
#include "include/manejoArchivos.h"

int main() {

    ListaVendedores listaPrincipal;

    extraerListaVendedores_binario(listaPrincipal);

    menuPrincipal(listaPrincipal);
    escribirDato_binario(listaPrincipal);
    return 0;
}