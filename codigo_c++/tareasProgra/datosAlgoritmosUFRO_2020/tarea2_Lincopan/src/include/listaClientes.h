#ifndef __LISTA_CLIENTES_H__
  #define __LISTA_CLIENTES_H__

  #include "listaStructClientes.h"
  #include "structVendedor.h"
  //declaración de funciones:

  bool listaClientes_vacia(ListaClientes lista);
  int largoLista_clientes(ListaClientes lista);
  void imprimeLista_clientes(Vendedor &vendedor);
  void eliminarDato_listaClientes(int p, ListaClientes &lista);
  void eliminarListaClientes(ListaClientes &lista);
  void insertarUltimo_listaClientes(tipoDato2 dato, ListaClientes &lista);
  tipoDato2 obtenerCliente_lista(int p, ListaClientes lista);

#endif
