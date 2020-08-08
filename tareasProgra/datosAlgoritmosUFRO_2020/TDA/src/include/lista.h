#ifndef __LISTA_H__
  #define __LISTA_H__

  #include "listaStruct.h"

  //declaración de funciones:

  bool listaVacia(Lista lista);
  int primerElemento_lista(Lista lista);
  int largoLista(Lista lista);
  int retrocederLista(int p, Lista lista);
  int avanzarLista(int p, Lista lista);
  void insertarDato_lista(tipoDato dato, int id, Lista &lista);
  tipoDato obtenerDato_lista(int p, Lista lista);
  void imprimeLista(Lista lista);
  int localiza(tipoDato x, Lista lista);
  void eliminarDato_lista(int p, Lista &lista);
  void eliminarLista(Lista &lista);
  void insertarUltimo_lista(tipoDato dato, Lista &lista);

#endif
