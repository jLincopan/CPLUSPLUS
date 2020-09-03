#ifndef STRUCT_VENDEDOR_H
    #define STRUCT_VENDEDOR_H

    #include "structCliente.h"
    #include "listaStructClientes.h"
	struct Vendedor{
		long cuenta = 0;
		char nombre[15] = {0};
		char apellido[15] = {0};
		char rut[10] = {0};
		long telefono = 0;
		char direccion[20] = {0};
		int edad = 0;
		char profesion[20] = {0};
		long deuda = 0;
		ListaClientes clientes;
	};
	
	struct nodoVendedor{
		Vendedor dato = {0};
		nodoVendedor* sgte;
	};

	struct cabeceraVendedor{
		nodoVendedor* primero; 
	};  
#endif
