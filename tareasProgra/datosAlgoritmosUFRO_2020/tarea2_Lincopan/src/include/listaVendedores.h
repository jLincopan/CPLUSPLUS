#ifndef __LISTA_VENDEDORES_H__c
  #define __LISTA_VENDEDORES_H__

  #include "listaStructVendedores.h"

  //declaración de funciones:
  
  tipoDato obtenerVendedor_lista(int p, ListaVendedores lista);
  bool listaVendedores_vacia(ListaVendedores lista);
  int largoLista_vendedores(ListaVendedores lista);
  void imprimeLista_vendedores(ListaVendedores lista);
  int localiza(tipoDato x, ListaVendedores lista);
  void eliminarDato_listaVendedores(int p, ListaVendedores &lista);
  void eliminarListaVendedores(ListaVendedores &lista);
  void insertarUltimo_listaVendedores(tipoDato dato, ListaVendedores &lista);

#endif
