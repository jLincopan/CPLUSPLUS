#include <stdio.h>
#include <string.h>
#include "include/manejoDatos.h"

long leerLong() {
    long a;
    long rc;
    printf("enter a number: ");
    while ((rc = scanf("%li", &a)) == 0) { // Neither success (1) nor EOF
        // clear what is left, the * means only match and discard:
        scanf("%*[^\n]");
        // input was not a number, ask again:
        printf("enter a number: ");
    }
    return a;
}

int leerInt() {
    int a;
    int rc;
    while ((rc = scanf("%d", &a)) == 0){  // Neither success (1) nor EOF
        // clear what is left, the * means only match and discard:
        scanf("%*[^\n]");
        // input was not a number, ask again:
        printf("Dato no válido, ingrese el número de nuevo:\n");
    }
    return a;
}

void leerLinea_texto(size_t largo, char buffer[]) {

    char tmp[largo];
    
    while (1) {
        if (fgets(tmp, largo, stdin)) {
            tmp[strcspn(tmp, "\n")] = 0;
            break;
        } else {
            printf("Error en función leerLinea_texto, cadena de texto no válida\n");
            printf("intentelo de nuevo:\n\n");
        }
    }

    strncpy(buffer, tmp, largo);
}

void registrarVendedor(Vendedor &buffer) {
    
    printf("Ingrese los datos del vendedor:\n\n");

    printf("Ingrese el número de cuenta bancaria: \n");
    buffer.cuenta = leerLong();

    getchar();
    printf("ingrese su nombre:\n");
    leerLinea_texto(sizeof(buffer.nombre), buffer.nombre);

    printf("ingrese su apellido:\n");
    leerLinea_texto(sizeof(buffer.apellido), buffer.apellido);

    printf("ingrese su rut:\n");
    leerLinea_texto(sizeof(buffer.rut), buffer.rut);

    printf("ingrese su teléfono de contacto:\n");
    buffer.telefono = leerLong();

    getchar();
    printf("ingrese su dirección:\n");
    leerLinea_texto(sizeof(buffer.direccion), buffer.direccion);

    printf("ingrese su edad:\n");
    buffer.edad = leerInt();

    getchar();
    printf("ingrese su profesión:\n");
    leerLinea_texto(sizeof(buffer.profesion), buffer.profesion);

}

void mostrarDatos_vendedor(Vendedor vendedor) {
    printf("Datos del vendedor:\n\n");
    printf("Nombre: %s\n", vendedor.nombre);
    printf("Apellido: %s\n", vendedor.apellido);
    printf("RUT: %s\n", vendedor.rut);
    printf("N° de teléfono: %li\n", vendedor.telefono);  
    printf("Dirección: %s\n", vendedor.direccion);
    printf("Cuenta bancaria: %li\n", vendedor.cuenta);
	printf("Edad: %i\n", vendedor.edad);
    printf("Profesión: %s\n", vendedor.profesion);
}
