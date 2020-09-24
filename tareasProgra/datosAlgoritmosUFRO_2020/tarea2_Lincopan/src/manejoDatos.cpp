#include <stdio.h>
#include <string.h>
#include "include/manejoDatos.h"
#include "include/manejoPantalla.h"
#include "include/listaVendedores.h"
#include "include/listaClientes.h"

extern bool modificacion; //variable que indica si se ha modificado
                          //la lista principal de vendedores


/*
	Nombre de la función: leerLong
	Tipo de función: long
	Parámetros: ninguno
	Dato de retorno: a, de tipo long
	Descripción de la función: lee un valor, se asegura de que no sea un caracter y 
                               lo devuelve
*/

long leerLong() {
    long a = 0;
    long rc = 0;
    while ((rc = scanf("%li", &a)) == 0) {

        scanf("%*[^\n]");
        printf("Dato no válido, ingrese el número de nuevo:\n");
    }
    return a;
}

/*
	Nombre de la función: leerInt
	Tipo de función: long
	Parámetros: ninguno
	Dato de retorno: a, de tipo int
	Descripción de la función: lee un valor, se asegura de que no sea un caracter y 
                               lo devuelve
*/

int leerInt() {
    int a = 0;
    int rc = 0;
    while ((rc = scanf("%d", &a)) == 0){
        scanf("%*[^\n]");
        printf("Dato no válido, ingrese el número de nuevo:\n");
    }
    return a;
}

/*
	Nombre de la función: leerLinea_texto
	Tipo de función: void
	Parámetros: largo, de tipo size_t
                buffer, de tipo char[]
	Dato de retorno: ninguno
	Descripción de la función: Lee una linea de texto de largo predefinido,
                               y la guarda en el buffer recibido como parámetro
*/

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

/*
	Nombre de la función: registrarVendedor
	Tipo de función: void
	Parámetros: lista, de tipo &ListaVendedores
	Dato de retorno: ninguno
	Descripción de la función: registra un vendedor en la lista
                               recibida como parámetro
*/

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

    while(1) {
        printf("ingrese su edad:\n");
        tmp.edad = leerInt();
        if(tmp.edad > 0 && tmp.edad < 120) {
            break;
        } else {
            printf("\nLa edad ingresada no es válida, inténtelo nuevamente\n");
        }
    }   

    getchar();
    printf("ingrese su profesión:\n");
    leerLinea_texto(sizeof(tmp.profesion), tmp.profesion);
    
    insertarUltimo_listaVendedores(tmp, lista);
    limpiarPantalla();
    printf("Vendedor insertado\n");
    modificacion = true;
}

/*
	Nombre de la función: registrarCliente
	Tipo de función: void
	Parámetros: lista, de tipo &ListaVendedores
	Dato de retorno: ninguno
	Descripción de la función: registra un cliente en un vendedor de la lista
                               recibida como parámetro
*/

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

    while(1) {
        printf("ingrese su edad:\n");
        buffer.edad = leerInt();
        if(buffer.edad > 0 && buffer.edad < 120) {
            break;
        } else {
            printf("\nLa edad ingresada no es válida, inténtelo nuevamente\n");
        }
    }   

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

/*
	Nombre de la función: calcularCobro_vendedor
	Tipo de función: int
	Parámetros: lista, de tipo ListaVendedores
	Dato de retorno: total, de tipo int
	Descripción de la función: calcula el total que debe de cobrar un vendedor
*/

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
        int largoListaClientes = largoLista_clientes(vendedor.clientes);
        for(int i = 1; i < largoListaClientes; i++) {
            tmp = obtenerCliente_lista(i, vendedor.clientes);
            total = total + tmp.deuda;
        }
        
        printf("Total a cobrar: %i", total);
        pausa();
        limpiarPantalla();
        return total; //por si alguna otra función necesita el dato
    }
}

/*
	Nombre de la función: buscarVendedor_rut
	Tipo de función: int
	Parámetros: lista, de tipo ListaVendedores
	Dato de retorno: i, de tipo int
	Descripción de la función: busca un vendedor por su rut, y devuelve su ID de existir
*/

int buscarVendedor_rut(ListaVendedores lista) {

    if(listaVendedores_vacia(lista)) {
        limpiarPantalla();
        printf("Error en función mostrarDatos_clientes: no hay vendedores registrados\n");
        return -1;
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
    printf("\nError: RUT no encontrado\n");
    return -1; //en cualquier parte en que se use esta funcion, el cero deberia ser un error
}

/*
	Nombre de la función: buscarCliente_rut
	Tipo de función: int
	Parámetros: lista, de tipo ListaVendedores
	Dato de retorno: i, de tipo int
	Descripción de la función: busca un cliente por su rut, y devuelve su ID de existir
*/

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

/*
	Nombre de la función: eliminarVendedor_rut
	Tipo de función: void
	Parámetros: lista, de tipo &ListaVendedores
	Dato de retorno: ninguno
	Descripción de la función: elimina una lista completa de vendedores
*/

void eliminarVendedor_rut(ListaVendedores &lista) {

    int id = buscarVendedor_rut(lista);
    if(id > 0) {
        eliminarDato_listaVendedores(id, lista);
        printf("\nVendedor eliminado\n"); 
        modificacion = true;
    }
    
}
