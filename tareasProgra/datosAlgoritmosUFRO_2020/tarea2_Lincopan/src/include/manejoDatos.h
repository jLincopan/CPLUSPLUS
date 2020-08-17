#ifndef DATOS_H
    #define DATOS_H
    #define BUFFER_SIZE 40
    #include <stdlib.h>

	#include "listaClientes.h"
	#include "listaStructClientes.h"
	#include "listaStructVendedores.h"

	void limpiarPantalla();
	int leerInt();
	void leerLinea_texto(size_t largo, char buffer[]);
	void registrarVendedor(ListaVendedores &lista);
	void mostrarDatos_vendedor(Vendedor vendedor);
	void registrarCliente(ListaVendedores &lista);
	void mostrarDatos_cliente(Cliente cliente);
	void mostrarDatos_clientes(ListaVendedores &vendedores);
	int calcularCobro_vendedor(ListaVendedores lista);
	int buscarVendedor_rut(ListaVendedores lista);
	void buscarCliente_rut(ListaVendedores lista);
	void eliminarVendedor_rut(ListaVendedores &lista);
	void menuPrincipal(ListaVendedores &vendedores);
#endif
