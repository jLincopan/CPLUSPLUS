#ifndef STRUCT_VENDEDOR_H
    #define STRUCT_VENDEDOR_H

    #include "structCliente.h"
    #include "listaStructClientes.h"
	struct Vendedor{
		long cuenta;
		char nombre[15];
		char apellido[15];
		char rut[10];
		long telefono;
		char direccion[50];
		int edad;
		char profesion[30];
		long deuda;
		ListaClientes clientes;
	};
	
	struct nodoVendedor{
		Vendedor dato;
		nodoVendedor* sgte;
	};

	struct cabeceraVendedor{
		int largo;
		nodoVendedor* primero; 
	};  
#endif
