#ifndef PROGRAMA_TICKET_H

  #define PROGRAMA_TICKET_H
  #define longitudNombre_max 10
  #define longitudPass_max 10
  #define USUARIOS_MAX 5
  #define ENTRADAS_MAX 10

  typedef struct {
    char nombre[longitudNombre_max+1];
    char password[longitudPass_max+1];
  } datos;
  extern datos usuarios[];
  int login(char* nombre, char* password);
  int returnID(char* nombre);
  int registrarUsuario();
  int loginScreen();
  void pantallaInicio();
  void comedyDiamante(int cantidadEntradas);
  void generarPantalla();
  void mostrarTablero();
  int registrarPosicion();
#endif
