#include <string.h> 
#include "include/manejoArchivos.h"
#include "include/listaVendedores.h"

void extraerVendedor_binario(Vendedor &buffer, int idVendedor) {

    char finCliente[13] = "FIN_VENDEDOR";
    char comparar[sizeof(finCliente)];
    FILE* archivo_fuente = fopen("datos/ventas.bin", "rb");
    Cliente cliente_tmp = {0};

    if(archivo_fuente == NULL) {
        printf("Error, no se pudo abrir el archivo que contiene los datos\n\n");
        exit(EXIT_FAILURE);
    }

    buffer = {0};
    fseek(archivo_fuente, (idVendedor-1)*(sizeof(Vendedor)), SEEK_SET);
    fread(&buffer, sizeof(Vendedor), 1, archivo_fuente);
    fread(&comparar, sizeof(finCliente), 1, archivo_fuente);

    while(strcmp(finCliente, comparar) == 0) {

        fread(&cliente_tmp, sizeof(Cliente), 1, archivo_fuente);
        insertarUltimo_listaClientes(cliente_tmp, buffer.clientes);
        fread(&comparar, sizeof(finCliente), 1, archivo_fuente);
    }
    fclose(archivo_fuente);

}

 void extraerListaVendedores_binario(ListaVendedores &lista) {
    char finVendedor[13] = "FIN_VENDEDOR";
    char comparar[sizeof(finVendedor)];
    FILE* archivo_fuente = fopen("datos/ventas.bin", "rb");
    Vendedor vendedor_tmp = {0};
    Cliente cliente_tmp = {0};

    if(archivo_fuente == NULL) {
        printf("Error, no se pudo abrir el archivo que contiene los datos\n\n");
        exit(EXIT_FAILURE);
    }

    int bytes_leidos = 0;
    do {
        //intentamos leer los datos de un cliente
        fread(&vendedor_tmp, sizeof(Vendedor), 1, archivo_fuente);
        //leemos 13 bytes más adelante por si encontramos un "FIN_VENDEDOR"
        bytes_leidos = fread(&comparar, sizeof(finVendedor), 1, archivo_fuente);

        //si no se lee información, salir
        if(bytes_leidos == 0) {
            break;
        } else if(strcmp(finVendedor, comparar) != 0) { //si NO se lee la cadena "FIN_VENDEDOR"
            //Leer clientes y asociarlos al vendedor hasta llegar a la cadena "FIN_VENDEDOR"
            while(strcmp(finVendedor, comparar) != 0) {
                fseek(archivo_fuente, -sizeof(finVendedor), SEEK_CUR);
                fread(&cliente_tmp, sizeof(Cliente), 1, archivo_fuente);
                insertarUltimo_listaClientes(cliente_tmp, vendedor_tmp.clientes);
                fread(&comparar, sizeof(finVendedor), 1, archivo_fuente);
            }
        }
         else {
            //si no se encuentra la cadena "FIN_VENDEDOR", retroceder el puntero
            //de lectura del archivo en 13 bytes (tamaño de "FIN_VENDEDOR")
            fseek(archivo_fuente, -sizeof(finVendedor), SEEK_CUR);
        }
        //Insertar el Vendedor junto con sus clientes en la lista
        insertarUltimo_listaVendedores(vendedor_tmp, lista);
        vendedor_tmp = {0};
        cliente_tmp = {0};
    } while (1);

    fclose(archivo_fuente);
}

void escribirDato_binario(ListaVendedores datos) {
    FILE* archivo_fuente = fopen("datos/ventas.bin", "wb");
    Vendedor bufferVendedores = {0};
    Cliente bufferClientes = {0};
    char finCliente[] = "FIN_VENDEDOR";

    for(int i = 1; i < largoLista_vendedores(datos); i++) {

        bufferVendedores = obtenerVendedor_lista(i, datos);
        fwrite(&bufferVendedores, sizeof(struct Vendedor), 1, archivo_fuente);

        for(int j = 1; j < largoLista_clientes(bufferVendedores.clientes); j++) {

            bufferClientes = obtenerCliente_lista(j, bufferVendedores.clientes);
            fwrite(&bufferClientes, sizeof(Cliente), 1, archivo_fuente);
            bufferClientes = {0};
        }
        fwrite(finCliente, sizeof(finCliente), 1, archivo_fuente);
        bufferVendedores = {0};
    }

    fclose(archivo_fuente);
}