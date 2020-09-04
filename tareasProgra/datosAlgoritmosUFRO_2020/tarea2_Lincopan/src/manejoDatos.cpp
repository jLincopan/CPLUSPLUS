#include <stdio.h>
#include <string.h>
#include "include/manejoDatos.h"
#include "include/manejoPantalla.h"
#include "include/listaVendedores.h"
#include "include/listaClientes.h"

extern bool modificacion;

long leerLong() {
    long a = 0;
    long rc = 0;
    while ((rc = scanf("%li", &a)) == 0) { // Neither success (1) nor EOF

        scanf("%*[^\n]");
    }
    return a;
}

int leerInt() {
    int a = 0;
    int rc = 0;
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

void registrarVendedor(ListaVendedores &lista) {
    Vendedor tmp = {0};
    printf("Ingrese los datos del vendedor:\n\n");

    printf("Ingrese el número de cuenta bancaria: \n");
    tmp.cuenta = leerLong();

    getchar();
    printf("ingrese su nombre:\n");
    leerLinea_texto(sizeof(tmp.nombre), tmp.nombre);

    printf("ingrese su apellido:\n");
    leerLinea_texto(sizeof(tmp.apellido), tmp.apellido);

    printf("ingrese su rut:\n");
    leerLinea_texto(sizeof(tmp.rut), tmp.rut);

    printf("ingrese su teléfono de contacto:\n");
    tmp.telefono = leerLong();

    getchar();
    printf("ingrese su dirección:\n");
    leerLinea_texto(sizeof(tmp.direccion), tmp.direccion);

    printf("ingrese su edad:\n");
    tmp.edad = leerInt();

    getchar();
    printf("ingrese su profesión:\n");
    leerLinea_texto(sizeof(tmp.profesion), tmp.profesion);
    
    insertarUltimo_listaVendedores(tmp, lista);
    limpiarPantalla();
    printf("Vendedor insertado\n");
    modificacion = true;
}

void registrarCliente(ListaVendedores &lista) {

    if(listaVendedores_vacia(lista)) {
        limpiarPantalla();
        printf("Error en función mostrarDatos_clientes: no hay vendedores registrados\n");
        return;
    }
    
    Cliente buffer = {0};
    int idVendedor;

    while(1) {
        printf("\nIngrese la id del vendedor asociado al cliente\n");
        imprimeLista_vendedores(lista);
        idVendedor = leerInt();

        if(idVendedor <= largoLista_vendedores(lista) && idVendedor > 0) {
            limpiarPantalla();
            getchar();
            break;
        } else {
            limpiarPantalla();
            printf("\nLa id ingresada no es válida, inténtelo nuevamente\n");
        }
    }

    nodo* aux = lista.primero;
	for(int i=1;i<idVendedor;i++) {
		aux=aux->next;
	}
    Vendedor* vendedor_tmp = &aux->dato;
    
    printf("Ingrese los datos del cliente:\n\n");

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

    printf("ingrese el monto que debe el cliente:\n$");
    buffer.deuda= leerInt();

    getchar();
    printf("Ingrese la fecha de cobro:\n");
    leerLinea_texto(sizeof(buffer.fechaCobro), buffer.fechaCobro);

    insertarUltimo_listaClientes(buffer, vendedor_tmp->clientes);
    limpiarPantalla();
    printf("\nCliente insertado\n");

    modificacion = true;
}

int calcularCobro_vendedor(ListaVendedores lista) {

   if(listaVendedores_vacia(lista)) {
        limpiarPantalla();
        printf("Error en función mostrarDatos_clientes: no hay vendedores registrados\n");
        return 0;
    }

    Cliente tmp;

    int idVendedor = 0;
    int largoLista = 0;
    while(1) {
        
        imprimeLista_vendedores(lista);
        printf("\nIngrese la id del vendedor:\n");

        idVendedor = leerInt();
        largoLista = largoLista_vendedores(lista);

        if(idVendedor <= largoLista && idVendedor > 0) {
            break;
        } else {
            limpiarPantalla();
            printf("\nLa id ingresada no es válida, inténtelo nuevamente\n");
        }
    }

    Vendedor vendedor = obtenerVendedor_lista(idVendedor, lista);

    if(listaClientes_vacia(vendedor.clientes)) {
        printf("Error, el vendedor seleccionado no tiene clientes registrados\n");
        pausa();
        return 0;
    } else {
        int total = 0;

        for(int i = 1; i < largoLista; i++) {
            tmp = obtenerCliente_lista(i, vendedor.clientes);
            total = total + tmp.deuda;
        }
        
        printf("Total a cobrar: %i", total);
        pausa();
        limpiarPantalla();
        return total; //por si alguna otra función necesita el dato
    }
}

int buscarVendedor_rut(ListaVendedores lista) {

    if(listaVendedores_vacia(lista)) {
        limpiarPantalla();
        printf("Error en función mostrarDatos_clientes: no hay vendedores registrados\n");
        return 0;
    }

    Vendedor tmp;
    int largo = largoLista_vendedores(lista);
    char rutObjetivo[10] = {0};
    char rutBuffer[10] = {0};

    printf("\nIngrese el rut a buscar (sin dígito verificador):\n");
    leerLinea_texto(sizeof(rutObjetivo), rutObjetivo);

    for(int i = 1; i < largo; i++) {
        tmp = obtenerVendedor_lista(i, lista);
        strncpy(rutBuffer, tmp.rut, sizeof(rutBuffer));

        if(strcmp(rutObjetivo, rutBuffer) == 0) {
            limpiarPantalla();
            printf("RUT encontrado, ID vendedor: %i\n", i);
            return i;
        }
    }
    limpiarPantalla();
    printf("\nRut no encontrado\n");
    return 0; //en cualquier funcion en que se use esta funcion, el cero deberia ser un error
}

void buscarCliente_rut(ListaVendedores lista) {

   if(listaVendedores_vacia(lista)) {
        limpiarPantalla();
        printf("Error en función mostrarDatos_clientes: no hay vendedores registrados\n");
        return;
    }

    Vendedor vendedor_tmp;
    Cliente cliente_tmp;

    int largoVendedores = largoLista_vendedores(lista);
    int largoClientes;
    char rutObjetivo[10] = {0};
    char rutBuffer[10] = {0};

    printf("\nIngrese el rut a buscar (sin dígito verificador):\n");
    leerLinea_texto(sizeof(rutObjetivo), rutObjetivo);

    for(int contadorVendedores = 1; contadorVendedores < largoVendedores; contadorVendedores++) {
        vendedor_tmp = obtenerVendedor_lista(contadorVendedores, lista);
        largoClientes = largoLista_clientes(vendedor_tmp.clientes);

        for(int contadorClientes = 1; contadorClientes < largoClientes; contadorClientes++) {
            cliente_tmp = obtenerCliente_lista(contadorClientes, vendedor_tmp.clientes);
            strncpy(rutBuffer, cliente_tmp.rut, sizeof(rutBuffer));

            if(strcmp(rutObjetivo, rutBuffer) == 0) {
                limpiarPantalla();
                printf("RUT encotrado, ID vendedor: %i, ID cliente: %i\n", contadorVendedores, contadorClientes);
                return;
            }
        }
    }
    limpiarPantalla();
    printf("\nRut no encontrado\n");    
}

void eliminarVendedor_rut(ListaVendedores &lista) {
    int id = buscarVendedor_rut(lista);
    eliminarDato_listaVendedores(id, lista);
    printf("\nVendedor eliminado\n"); 
    
    modificacion = true;
}
