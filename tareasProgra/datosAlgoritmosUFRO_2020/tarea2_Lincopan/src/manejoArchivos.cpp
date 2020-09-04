#include <string.h> 
#include "include/manejoArchivos.h"
#include "include/listaVendedores.h"


/*
	Nombre de la función: extraerListaVendedores_binario
	Tipo de función: void
	Parámetros: lista, de tipo &listaVendedores
	Dato de retorno: ninguno
	Descripción de la función: lee datos desde el archivo definido en
                               src/include/manejoArchivos.h y los guarda
                               en la lista de vendedores recibida como 
                               parámetro
*/

void extraerListaVendedores_binario(ListaVendedores &lista) {
    FILE* archivo_fuente = fopen("datos/ventas.bin", "rb");
    if(archivo_fuente == NULL) {
        printf("Archivo %s no encontrado... Iniciando desde cero\n\n", RUTA_DATOS);
        return;
    }

    int contadorClientes = 0;
    int vendedores = 0;
    int clientes = 0;

    char comparar[sizeof(FIN_VENDEDOR)];
    Vendedor vendedor_tmp = {0};
    Cliente cliente_tmp = {0};

    printf("Leyendo datos desde ""%s""\n\n", RUTA_DATOS);
    while(fread(&vendedor_tmp, 1, sizeof(Vendedor), archivo_fuente) == sizeof(Vendedor)) {
        vendedor_tmp.clientes.primero = NULL;
        fread(&comparar, 1, sizeof(FIN_VENDEDOR), archivo_fuente);
        

        if(strcmp(comparar, FIN_VENDEDOR) == 0) {
            insertarUltimo_listaVendedores(vendedor_tmp, lista);
            printf("Vendedor cargado: %s, %i cliente(s) encontrado(s)\n", vendedor_tmp.nombre, contadorClientes);
            vendedor_tmp = {0};
        } else {
            fseek(archivo_fuente, -sizeof(FIN_VENDEDOR), SEEK_CUR);

            while(fread(&cliente_tmp, 1, sizeof(Cliente), archivo_fuente) == sizeof(Cliente)) {
                fread(&comparar, 1, sizeof(FIN_VENDEDOR), archivo_fuente);

                if(strcmp(comparar, FIN_VENDEDOR) == 0) {
                    
                    insertarUltimo_listaClientes(cliente_tmp, vendedor_tmp.clientes);
                    insertarUltimo_listaVendedores(vendedor_tmp, lista);
                    contadorClientes++;
                    
                    printf("Vendedor cargado: %s, %i cliente(s) encontrado(s)\n", vendedor_tmp.nombre, contadorClientes);

                    break;
                } else {
                    insertarUltimo_listaClientes(cliente_tmp, vendedor_tmp.clientes);
                    contadorClientes++;
                    cliente_tmp = {0};
                    fseek(archivo_fuente, -sizeof(FIN_VENDEDOR), SEEK_CUR);
                }
                
            }
            clientes = contadorClientes + clientes;
            contadorClientes = 0;

        }
        vendedores++;
    }

    printf("\nArchivo leído: %i vendedores y %i clientes cargados\n\n", vendedores, clientes);
    fclose(archivo_fuente);
}

/*
	Nombre de la función: guardarListaVendedores_binario
	Tipo de función: void
	Parámetros: datos, de tipo listaVendedores
	Dato de retorno: ninguno
	Descripción de la función: lee datos desde la lista de vendedores recibida como 
                               parámetro y los guarda en formato binario en
                               el archivo definido en 
                               src/include/manejoArchivos.h
*/

void guardarListaVendedores_binario(ListaVendedores datos) {
    FILE* archivo_fuente = fopen("datos/ventas.bin", "wb");
    Vendedor bufferVendedores = {0};
    Cliente bufferClientes = {0};

    if(!listaVendedores_vacia(datos)) {
        
        for(int i = 1; i < largoLista_vendedores(datos); i++) {

            bufferVendedores = obtenerVendedor_lista(i, datos);
            fwrite(&bufferVendedores, sizeof(struct Vendedor), 1, archivo_fuente);

            for(int j = 1; j < largoLista_clientes(bufferVendedores.clientes); j++) {

                bufferClientes = obtenerCliente_lista(j, bufferVendedores.clientes);
                fwrite(&bufferClientes, sizeof(Cliente), 1, archivo_fuente);
                bufferClientes = {0};
            }
            fwrite(FIN_VENDEDOR, sizeof(FIN_VENDEDOR), 1, archivo_fuente);
            bufferVendedores = {0};
        }
    }
    fclose(archivo_fuente);
}

