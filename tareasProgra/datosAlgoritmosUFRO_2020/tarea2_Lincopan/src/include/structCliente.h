#ifndef STRUCT_CLIENTE_H
    #define STRUCT_CLIENTE_H
    struct Cliente{
		char nombre[15] = {0};
		char apellido[15] = {0};
		char rut[10] = {0};
		long telefono = 0;
		char direccion[50] = {0};
		int edad = 0;
		char profesion[30] = {0};
		long deuda = 0;
		char fechaCobro[11] = {0};
	};
#endif