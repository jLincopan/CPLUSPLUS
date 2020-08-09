#include <stdio.h>
#include <stdlib.h>

void extraerDato_binario(char ruta[]) {
    FILE* archivo_fuente = fopen("datos/ventas.bin", "rb");
    if(archivo_fuente == NULL) {
        printf("Error, no se pudo abrir el archivo que contiene los datos\n\n");
        exit(EXIT_FAILURE);
    }

}

void escribirDato_binario() {

}

void eliminarDato_binario() {

}

void copiarArchivo_binario() {

}



