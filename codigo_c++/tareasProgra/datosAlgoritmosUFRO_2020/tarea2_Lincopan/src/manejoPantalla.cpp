#include <stdio.h>
#include "include/manejoPantalla.h"

void vaciarStdin() {
    while ( getchar() != '\n' ); //vaciamos stdin
}
void pausa() {
    vaciarStdin();
    getchar(); //pausa, esperando cualquier tecla
}

void limpiarPantalla() { //solo funciona en sistemas tipo UNIX
    printf("\e[2J\e[H");
}

/*
	Nombre de la función: mostrarDatos_vendedor
	Tipo de función: void
	Parámetros: vendedor, de tipo Vendedor
	Dato de retorno: ninguno
	Descripción de la función: muestra los datos del vendedor recibido como parámetro
*/

void mostrarDatos_vendedor(Vendedor vendedor) {
    printf(" | %-13s ", vendedor.nombre);
    printf(" | %-13s ", vendedor.apellido);
    printf(" | %-7s ", vendedor.rut);
    printf(" | %-7li ", vendedor.telefono);  
    printf(" | %-18s ", vendedor.direccion);
    printf(" | %-11li ", vendedor.cuenta);
	printf(" | %-3i ", vendedor.edad);
    printf(" | %-19s |", vendedor.profesion);
}

/*
	Nombre de la función: mostrarDatos_cliente
	Tipo de función: void
	Parámetros: cliente, de tipo Cliente
	Dato de retorno: ninguno
	Descripción de la función: muestra los datos del cliente recibido como parámetro
*/

void mostrarDatos_cliente(Cliente cliente) {
    
    printf(" | %-13s ", cliente.nombre);
    printf(" | %-13s ", cliente.apellido);
    printf(" | %-7s ", cliente.rut);
    printf(" | %-7li ", cliente.telefono);  
    printf(" | %-18s ", cliente.direccion);
	printf(" | %-3i ", cliente.edad);
    printf(" | %-19s ", cliente.profesion);
    printf(" | %-7li", cliente.deuda);
    printf(" | %-14s |\n", cliente.fechaCobro);
}

/*
	Nombre de la función: mostrarDatos_clientes
	Tipo de función: void
	Parámetros: vendedores, de tipo &ListaVendedores
	Dato de retorno: ninguno
	Descripción de la función: muestra los datos de un vendedor de la lista recibida como
                               parámetro
*/

void mostrarDatos_clientes(ListaVendedores &vendedores) {

    int idVendedor = 0;
    int largoLista = 0;

    while(1) {
        if(listaVendedores_vacia(vendedores)) {
            limpiarPantalla();
            printf("Error en función mostrarDatos_clientes: no hay vendedores registrados\n");
            return;
        }

        printf("\nVendedores registrados actualmente: \n");
        imprimeLista_vendedores(vendedores);
        printf("\nIngrese la id del vendedor para mostrar sus clientes registrados\n");

        idVendedor = leerInt();
        largoLista = largoLista_vendedores(vendedores);

        if(idVendedor <= largoLista && idVendedor > 0) {
            break;
        } else {
            limpiarPantalla();
            printf("\nLa id ingresada no es válida, inténtelo nuevamente\n");
        }
    }

    Vendedor tmp = {0};
    tmp = obtenerVendedor_lista(idVendedor, vendedores);
    limpiarPantalla();

    if(listaClientes_vacia(tmp.clientes)) {
        limpiarPantalla();
        printf("Error en función mostrarDatos_clientes: no hay clientes registrados\n");
        return;
    }
    printf("\n\nDatos de los clientes:\n");
    imprimeLista_clientes(tmp);
    printf("\nPresione cualquier tecla para continuar\n\n");
    pausa();
    limpiarPantalla();
 
}

/*
	Nombre de la función: menuPrincipal
	Tipo de función: void
	Parámetros: vendedores, de tipo &ListaVendedores
	Dato de retorno: ninguno
	Descripción de la función: El menú principal... Recibe como parámetro la lista
                               de vendedores con la que trabaja el programa
                               (la que se guardará en el archivo)
*/

void menuPrincipal(ListaVendedores &vendedores) {

    int opcion = 0;

    while(1) {
        printf("\n\n1) Registrar nuevo vendedor\n");
        printf("\n2) Registrar nuevo cliente\n");
        printf("\n3) Buscar vendedor por rut\n");
        printf("\n4) Buscar cliente por rut\n");
        printf("\n5) Mostrar vendedores\n");
        printf("\n6) Mostrar clientes\n");
        printf("\n7) Calcular total a cobrar de un vendedor\n");
        printf("\n8) Eliminar vendedor por rut\n");
        printf("\n9) Salir\n\n");

        opcion = leerInt();
        getchar();

        switch(opcion)
        {
        case 1:
            limpiarPantalla();
            registrarVendedor(vendedores);
            break;
        case 2:
            limpiarPantalla();
            registrarCliente(vendedores);
            break;
        case 3:
            limpiarPantalla();
            buscarVendedor_rut(vendedores);
            break;
        case 4:
            limpiarPantalla();
            buscarCliente_rut(vendedores);
            break;
        case 5:
            limpiarPantalla();
            imprimeLista_vendedores(vendedores);
            break;
        case 6: 
            limpiarPantalla();
            mostrarDatos_clientes(vendedores);
            break;
        case 7:
            limpiarPantalla();
            calcularCobro_vendedor(vendedores);
            break;
        case 8:
            limpiarPantalla();
            eliminarVendedor_rut(vendedores);
            break;
        case 9:
            limpiarPantalla();
            return;
        default:
            limpiarPantalla();
            printf("\nOpción no válida, inténtelo nuevamente\n\n");
            break;
        }
    }
    
}