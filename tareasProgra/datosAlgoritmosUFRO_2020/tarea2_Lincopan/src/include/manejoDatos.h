#ifndef DATOS_H
    #define DATOS_H
    #define BUFFER_SIZE 40
    #include <stdlib.h>

	#include "listaClientes.h"
	#include "listaStructClientes.h"

	void leerLinea_texto(size_t largo, char buffer[]);
	void registrarVendedor(Vendedor &buffer);
	void mostrarDatos_vendedor(Vendedor vendedor);
	void registrarCliente(Cliente &buffer, Vendedor &vendedor);
	void mostrarDatos_cliente(Cliente cliente);
	void mostrarDatos_clientes(Vendedor &vendedor);
#endif
