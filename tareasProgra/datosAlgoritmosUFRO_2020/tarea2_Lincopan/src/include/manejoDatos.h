#ifndef DATOS_H
    #define DATOS_H
    #define BUFFER_SIZE 40
    #include <stdlib.h>

	struct Cliente{
		int id;
		char nombre[15];
		char apellido[15];
		char rut[10];
		long telefono;
		char direccion[50];
		int edad;
		char profesion[30];
		long deuda;
		char fechaCobro[11];
	};

	struct nodoCliente{
		Cliente dato;
		nodoCliente*sgte;
	};

	struct cabeceraCliente{
		int largo;
		nodoCliente* primero;
	};
	
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
		cabeceraCliente* clientes;
	};
	
	struct nodoVendedor{
		Vendedor dato;
		nodoVendedor* sgte;
	};

	struct cabeceraVendedor{
		int largo;
		nodoVendedor* primero; 
	};  


	void registrarVendedor(Vendedor &buffer);
	void leerLinea_texto(size_t largo, char buffer[]);
	void mostrarDatos_vendedor(Vendedor vendedor);
#endif
