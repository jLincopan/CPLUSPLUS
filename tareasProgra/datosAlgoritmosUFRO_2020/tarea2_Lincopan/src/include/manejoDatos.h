#ifndef DATOS_H
    #define DATOS_H
    #define BUFFER_SIZE 40
    #include <stdlib.h>

	#include "listaClientes.h"
	#include "listaStructClientes.h"
	#include "listaStructVendedores.h"

	void leerLinea_texto(size_t largo, char buffer[]);
	void registrarVendedor(ListaVendedores &lista);
	void mostrarDatos_vendedor(Vendedor vendedor);
	void registrarCliente(int id, ListaVendedores &lista);
	void mostrarDatos_cliente(Cliente cliente);
	void mostrarDatos_clientes(int id, ListaVendedores &vendedores);
	int calcularCobro_vendedor(int id, ListaVendedores lista);
	int buscarVendedor_rut(ListaVendedores lista);
	void buscarCliente_rut(ListaVendedores lista);
	void eliminarVendedor_rut(ListaVendedores &lista);
#endif
