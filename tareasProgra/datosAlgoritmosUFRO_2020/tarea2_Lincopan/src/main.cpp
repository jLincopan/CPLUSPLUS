#include <stdio.h>
#include <string.h>

#include "include/listaVendedores.h"
#include "include/listaClientes.h"
#include "include/manejoDatos.h"
#include "include/manejoArchivos.h"
#include "include/manejoPantalla.h"

bool modificacion = false;

int main() {

    ListaVendedores listaPrincipal;

    limpiarPantalla();
    extraerListaVendedores_binario(listaPrincipal);

    menuPrincipal(listaPrincipal);

    if(modificacion) {
        escribirListaVendedores_binario(listaPrincipal);
    }

    return 0;
}