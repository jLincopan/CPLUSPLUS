#ifndef STRUCT_CLIENTE_H
    #define STRUCT_CLIENTE_H
    struct Cliente{
		int id = 0;
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
		nodoCliente* sgte;
	};

	struct cabeceraCliente{
		nodoCliente* primero;
	};
#endif