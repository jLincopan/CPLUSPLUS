#include <string.h> 
#include "include/manejoArchivos.h"
#include "include/listaVendedores.h"

void extraerVendedor_binario(Vendedor &buffer, int idVendedor) {

    char finVendedor[13] = "FIN_VENDEDOR";
    char comparar[sizeof(finVendedor)];
    FILE* archivo_fuente = fopen("datos/ventas.bin", "rb");
    Cliente cliente_tmp = {0};

    if(archivo_fuente == NULL) {
        printf("Error, no se pudo abrir el archivo que contiene los datos\n\n");
        exit(EXIT_FAILURE);
    }

    buffer = {0};
    fseek(archivo_fuente, (idVendedor-1)*(sizeof(Vendedor)), SEEK_SET);
    fread(&buffer, sizeof(Vendedor), 1, archivo_fuente);
    fread(&comparar, sizeof(finVendedor), 1, archivo_fuente);

    while(strcmp(finVendedor, comparar) == 0) {

        fread(&cliente_tmp, sizeof(Cliente), 1, archivo_fuente);
        insertarUltimo_listaClientes(cliente_tmp, buffer.clientes);
        fread(&comparar, sizeof(finVendedor), 1, archivo_fuente);
    }
    fclose(archivo_fuente);

}

void prueba(ListaVendedores &lista) {
    FILE* archivo_fuente = fopen("datos/ventas.bin", "rb");
    if(archivo_fuente == NULL) {
        printf("Error, no se pudo abrir el archivo que contiene los datos\n\n");
        exit(EXIT_FAILURE);
    }
    
    char finVendedor[] = "FIN_VENDEDOR";
    char comparar[sizeof(finVendedor)];
    Vendedor vendedor_tmp = {0};
    Cliente cliente_tmp = {0};
    
    fread(&vendedor_tmp, 1, sizeof(Vendedor), archivo_fuente);
    vendedor_tmp.clientes.primero = new nodo2;

    printf("\nVendedor cargado en memoria\n\n");

    insertarUltimo_listaVendedores(vendedor_tmp, lista);
    insertarUltimo_listaClientes(cliente_tmp, lista.primero->dato.clientes);

    fclose(archivo_fuente);

}

void extraerListaVendedores_binario(ListaVendedores &lista) {
    FILE* archivo_fuente = fopen("datos/ventas.bin", "rb");
    if(archivo_fuente == NULL) {
        printf("Archivo ventas.bin no encontrado... Iniciando desde cero\n\n");
        return;
    }

    int contadorClientes = 0;    
    char finVendedor[] = "FIN_VENDEDOR";
    char comparar[sizeof(finVendedor)];
    Vendedor vendedor_tmp = {0};
    Cliente cliente_tmp = {0};

    printf("Leyendo datos desde ""ventas.bin""\n\n");
    while(fread(&vendedor_tmp, 1, sizeof(Vendedor), archivo_fuente) == sizeof(Vendedor)) {

        fread(&comparar, 1, sizeof(finVendedor), archivo_fuente);
        

        if(strcmp(comparar, finVendedor) == 0) {
            insertarUltimo_listaVendedores(vendedor_tmp, lista);
            vendedor_tmp = {0};
        } else {
            fseek(archivo_fuente, -sizeof(finVendedor), SEEK_CUR);

            while(fread(&cliente_tmp, 1, sizeof(Cliente), archivo_fuente) == sizeof(Cliente)) {

                fread(&comparar, 1, sizeof(finVendedor), archivo_fuente);

                if(strcmp(comparar, finVendedor) == 0) {
                    vendedor_tmp.clientes.primero = new nodo2;
                    insertarUltimo_listaClientes(cliente_tmp, vendedor_tmp.clientes);
                    insertarUltimo_listaVendedores(vendedor_tmp, lista);
                    contadorClientes++;
                    
                    printf("Vendedor cargado: %s, %i clientes encontrados\n", vendedor_tmp.nombre, contadorClientes);

                    break;
                } else {
                    vendedor_tmp.clientes.primero = new nodo2;
                    insertarUltimo_listaClientes(cliente_tmp, vendedor_tmp.clientes);
                    cliente_tmp = {0};
                    fseek(archivo_fuente, -sizeof(finVendedor), SEEK_CUR);
                }
            }

        }
        printf("\nArchivo leido\n\n");
    }

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

