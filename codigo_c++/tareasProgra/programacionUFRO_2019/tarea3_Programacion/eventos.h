#ifndef EVENTOS_H
  #define EVENTOS_H

  #define UBICACIONES_MAX 10
  #define numEventos 4

  int contarEventos();
  int mostrarEventos();
  void soloMostrarEventos();
  void inicializarEventos();
  int comprarTicket(int ID);
  int mostrarUbicaciones(int ID);
  int registrarEleccion(int limite);
  int string_a_int(char* texto);

  typedef struct {
    char nombre[30];
    char ubicaciones[UBICACIONES_MAX][40];
    int precioEntradas[UBICACIONES_MAX][10];
    int cantidad[UBICACIONES_MAX][10];
  } eventos;

  extern eventos datosEventos[];
  extern int contadorUbicaciones[];

#endif
