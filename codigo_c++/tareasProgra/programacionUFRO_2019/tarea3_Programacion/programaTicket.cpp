#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "programaTicket.h"
#include "eventos.h"
#include "password.h"

datos usuarios[USUARIOS_MAX];
static size_t contadorUsuarios = 0;
int contadorUbicaciones[numEventos];

/* * Nombre de la función: login.
* Tipo de función: int.
* Parámetros: nombre, de tipo char* y password, de tipo char*
* Dato de retorno: int, 0 si finaliza con éxito, otro valor si hay algún error
* Descripción de la función: Dados un usuario y su contraseña, verifica
* si ya está registrado y si su contraseña corresponde a la guardada
* para ese usuario*/

int login(char* nombre, char* password) {
  size_t id = returnID(nombre); //determinamos la id del usuario
  if(strcmp(password, usuarios[id].password) == 0) {
    return 0; //Login exitoso
  } else {
    return 1; //Contraseña no válida
  }
}

/* * Nombre de la función: returnID.
* Tipo de función: int.
* Parámetros: nombre, de tipo char*
* Dato de retorno: int, devuelve la ID de un nombre de usuario si finaliza con éxito,
* -1 si el usuario no está registrado
* Descripción de la función: Dado un nombre de usuario, verifica si está registrado. Si lo está,
* devuelve su ID, si no... Devuelve -1*/

int returnID(char* nombre) {
  for(int id = 0; id < USUARIOS_MAX; id++) {
    if(strcmp(nombre, usuarios[id].nombre) == 0) {
      return id;
    }
  }
  printf("El usuario no está registrado\n\n");
  return -1;
}

void pantallaInicio() {
  int eleccion;
  int retorno;
  printf("\e[2J\e[H");
  while(1) {
    printf("    ____  ____  ____  __________  ___  __________________ __ ____________\n");
    printf("   / __ \\/ __ \\/ __ \\/ ____/ __ \\/   |/_  __/  _/ ____/ //_// ____/_  __/\n");
    printf("  / /_/ / /_/ / / / / / __/ /_/ / /| | / /  / // /   / ,<  / __/   / /   \n");
    printf(" / ____/ _, _/ /_/ / /_/ / _, _/ ___ |/ / _/ // /___/ /| |/ /___  / /    \n");
    printf("/_/   /_/ |_|\\____/\\____/_/ |_/_/  |_/_/ /___/\\____/_/ |_/_____/ /_/     \n\n");

    printf("1) Iniciar sesión\n");
    printf("2) Registrarse\n");
    eleccion = registrarEleccion(2);
    eleccion++;

    if(eleccion == 1) {
      retorno = loginScreen();
      if(retorno == 0) {
        printf("\e[2J\e[H");
        return; //exito
      } else if(retorno == 1) {
        printf("\e[2J\e[H");
        printf("\nLa combinación de usuario y contraseña ingresadas no es válida\n\n");
      } else {
        printf("\e[2J\e[H");
        printf("\nError desconocido\n\n");
      }
    } else if(eleccion == 2) {

      if(contadorUsuarios >= USUARIOS_MAX) {
        printf("\e[2J\e[H");
        printf("Error: límite de usuarios alcanzado\n\n");
      } else {
        retorno = registrarUsuario();
        if(retorno == 0) {
          printf("\e[2J\e[H");
          pantallaInicio();
          return;
        } else if(retorno == 1) {
          printf("\e[2J\e[H");
          printf("\nError: nombre de usuario demasiado largo\n\n");
        } else if(retorno == 2) {
          printf("\e[2J\e[H");
          printf("\nError: nombre de usuario vacío\n\n");
        } else if(retorno == 3) {
          printf("\e[2J\e[H");
          printf("\nError: nombre de usuario ya en uso\n\n");
        } else if(retorno == 4) {
          printf("\e[2J\e[H");
          printf("\nError: contraseña demasiado larga\n\n");
        } else if(retorno == 5) {
          printf("\e[2J\e[H");
          printf("\nError: contraseña vacía\n\n");
        } else {
          printf("\e[2J\e[H");
          printf("\nError desconocido\n\n");
        }
      }
    }
  }
}

/* * Nombre de la función: loginScreen.
* Tipo de función: int.
* Parámetros: ninguno
* Dato de retorno: int, devuelve 0 si finaliza con éxito
* Descripción de la función: Se encarga de realizar el inicio
* de sesion*/

int loginScreen() {
  char nombre[longitudNombre_max];
  char password[longitudPass_max];

  while(1) {
    printf("\e[2J\e[H");
    printf("Iniciar sesión:");
    printf("\nIngrese su nombre de usuario\n\n>");
    scanf("%s", nombre);
    printf("\e[2J\e[H");
    printf("\nIngrese su contraseña\n\n>");
    while ((getchar()) != '\n');
    getPassword(password);
    if(login(nombre, password) == 0) {
      return 0;
    } else {
      return 1;
    }
  }
}

/* * Nombre de la función: registrarUsuario.
* Tipo de función: int.
* Parámetros: ninguno
* Dato de retorno: int, devuelve 0 si finaliza con éxito, otro valor
* si hay error
* Descripción de la función: Se encarga de realizar el registro
* de un usuario nuevo*/
int registrarUsuario() {

  char bufferNombres[100];
  char bufferComparacion[longitudNombre_max];
  char bufferPasswords[100];
  printf("\e[2J\e[H");

  printf("Registro: ");

  printf("\nIngrese su nombre\n\n>");
  scanf("%s", bufferNombres);
  const size_t  largoUsuario = (bufferNombres) ? strlen(bufferNombres) : 0;

  if(largoUsuario > longitudNombre_max) {return 1;} //demasiado largo
  if(largoUsuario < 1) {return 2;} //nombre de usuario vacío

  //verificando que no haya registrado otro usuario con el mismo nombre
  strcpy(bufferComparacion, bufferNombres);
  for(int i = 0; i < USUARIOS_MAX; i++) {
    if (strcmp(usuarios[i].nombre, bufferComparacion) == 0) {
      return 3; //usuario ya existe
    }
  }

  printf("\nIngrese su contraseña\n\n>");
  while ((getchar()) != '\n');
  getPassword(bufferPasswords);
  const size_t  largoPassword = (bufferPasswords) ? strlen(bufferPasswords) : 0;

  if(largoPassword > longitudPass_max) {return 4;} //demasiado largo
  if(largoPassword < 1) {return 5;} //contraseña vacía

  //procedemos a registrar el usuario
  strncpy(usuarios[contadorUsuarios].nombre, bufferNombres, longitudNombre_max+1);
  strncpy(usuarios[contadorUsuarios].password, bufferPasswords, longitudPass_max+1);
  contadorUsuarios++;
  return 0;
}

/* * Nombre de la función: registrarEleccion.
* Tipo de función: int.
* Parámetros: limite, de tipo int
* Dato de retorno: int, devuelve lo que introduce el usuario - 1
* */

int registrarEleccion(int limite) {
  int a;
  while(1) {
    printf("\n\n>");
    scanf("%i", &a);
    if(a < 1 || a > limite) {
      printf("El numero ingresado no es válido, inténtelo nuevamente");
    } else {
      return a-1;
    }
  }
}

/* * Nombre de la función: string_a_int.
* Tipo de función: int.
* Parámetros: texto, de tipo char*
* Dato de retorno: numero, de tipo int
* Descripción de la función: convertir un string a int */
int string_a_int(char* texto) {
  int numero = atoi(texto);
  return numero;
}

/* * Nombre de la función: mostrarUbicaciones.
* Tipo de función: int.
* Parámetros: ID, de tipo int
* Dato de retorno: int, devuelve la
* Descripción de la función: Se encarga de realizar el inicio
* de sesion*/

int mostrarUbicaciones(int ID) {
  int entradasRestantes = 0;
  printf("\n%s:\n", datosEventos[ID].nombre);
  printf("\n        Ubicaciones                    Valor      Entradas disponibles\n");
  for(int i = 0; i < contadorUbicaciones[ID]; i++) {
    printf("        %i) %-20s", i+1, datosEventos[ID].ubicaciones[i]);
    printf("        $%-18i", *datosEventos[ID].precioEntradas[i]);
    printf("        %-i\n\n", *datosEventos[ID].cantidad[i]);
    entradasRestantes = entradasRestantes + *datosEventos[ID].cantidad[i];
  }
  return entradasRestantes;
}

/* * Nombre de la función: comprarTicket.
* Tipo de función: int.
* Parámetros: ID, de tipo int
* Dato de retorno: restante, de tipo int
* Descripción de la función: Se encarga de realizar el proceso
* de compra, y devuelve la cantidas total de entradas disponibles
* en todos los eventos menos las que se vendieron*/

int comprarTicket(int ID) {
  int cantidad;
  int ubicacion;
  int restante;

  while(1) {
    printf("\e[2J\e[H");
    printf("\nElija su ubicacion");
    restante = mostrarUbicaciones(ID); //cantidad de entradas a vender
    ubicacion = registrarEleccion(contadorUbicaciones[ID]);

    printf("\n\nIngrese la cantidad de entradas a comprar");

    cantidad = registrarEleccion(ENTRADAS_MAX);

    if(*datosEventos[ID].precioEntradas[ubicacion] - cantidad < 0) {
      printf("¡No puede comprar más entradas que las disponibles!\n\n");
      return -1; //error
    } else {

      if(strcmp(datosEventos[ID].nombre,"Show de Stand Up Comedy") == 0 && strcmp(datosEventos[ID].ubicaciones[ubicacion], "Diamante") == 0) {
        comedyDiamante(cantidad);
      }

      *datosEventos[ID].cantidad[ubicacion] = *datosEventos[ID].cantidad[ubicacion] - (cantidad+1);
      printf("\e[2J\e[H");
      printf("Resumen de la compra: \n\n");
      printf("    El costo de sus entradas es de: $%i\n", (cantidad+1) * *datosEventos[ID].precioEntradas[ubicacion]);
      printf("    Cantidad de entradas: %i\n", cantidad+1);
      printf("    Evento: %s\n", datosEventos[ID].nombre);
      printf("    Ubicación: %s\n", datosEventos[ID].ubicaciones[ubicacion]);
      restante = restante - (cantidad+1);
      printf("\n\nPresione cualquier tecla para continuar\n\n");
      system("read");
      return restante; //compra exitosa
    }
  }
}

/* * Nombre de la función: comedyDiamante.
* Tipo de función: void.
* Parámetros: cantidadEntradas, de tipo int
* Dato de retorno: ninguno
* Descripción de la función: Se encarga de la eleccion de asientos
* para la ubicacion diamante del show de stand up comedy*/

void comedyDiamante(int cantidadEntradas) {
  printf("\e[2J\e[H");
  printf("\e[2J\e[H");
  int i = 0;
  while(cantidadEntradas >= i) {
    mostrarTablero();
    registrarPosicion();
    i++;
  }
}

const int largo = 5;
const int ancho = 10;

//Carácteres con los que los jugadores verán sus jugadas en la pantalla
static char asientoOcupado = '*';
static char asientoLibre = '-';
static char tablero[ancho][largo]; //Matriz que continene el tablero de juego

  /* * Nombre de la función: generarPantalla.
  * Tipo de función: void.
  * Parámetros: ninguno
  * Dato de retorno: ninguno
  * Descripción de la función: Se encarga de "inicializar"
  * el tablero */

  void generarPantalla() {

	for(int a = 0; a < ancho; a++) { //Recorriendo el tablero

		for(int b = 0; b < largo; b++) {

			tablero[a][b] = asientoLibre;

			}
		}
	}

/* * Nombre de la función: mostrarTablero.
* Tipo de función: void.
* Parámetros: ninguno
* Dato de retorno: ninguno
* Descripción de la función: Muestra en pantalla lo que contenga el array
* que representa el tablero*/

  void mostrarTablero() {

	printf("\n\n-");
	for(int i = 0; i <= largo; i++) {

		printf("---");

		}

	printf("\n");
	for(int a = 0; a < ancho; a++) {
	if(ancho >= 10 && a < 9) {

		printf(" ");

		}
	printf("%i| ", a+1); //imprimiendo números del eje y

		for(int b = 0; b < largo; b++) { //Imprimiendo el contenido de la matriz que recibe como argumento

			printf("%c  ", tablero[a][b]);

			}
			printf("|\n");
		}

		//Imprimiendo los números del eje x, además de la barra separadora
		for(int i = 0; i <= largo; i++) {
		    printf("---");
			}
		printf(">\n  | ");
		if(ancho < 10) {
			printf("\b");
			}
		for(int i = 1; i <= largo; i++) {

			if(i >= 10) {
				printf("\b"); //Borramos un espacio para acomodar el dígito adicional
				}
			printf("%i  ", i); //Imprimimos los números
			}
		printf("\n");
}

/* * Nombre de la función: registrarPosicion.
* Tipo de función: int.
* Parámetros: ninguno
* Dato de retorno: retorna "0" si la validación
* de las coordenadas ingresadas por el usuario es exitosa, o
* un "1" si falla
* Descripción de la función: Función que registra los asientos para la
* ubicacion diamante del show de stand up comedy, y además valida las coordenadas */

int registrarPosicion() {
	//Variables para las coordenadas en el tablero
	int x = 0;
	int y = 0;

	printf("Elija sus asientos (x,y)\n\n");

	scanf("%i,%i", &x, &y);

	if ((x >= 1 && x <= largo) && (y >= 1 && y <= ancho)) {

		x = x-1;
		y = y-1;

		if (tablero[y][x] != asientoLibre) { //Se trabaja con las coordenadas al revés, ya que c genera las matrices en formato [fila][columna]
			printf("\e[2J\e[H");
			printf("Posición no válida: no se puede sobreescribir una anterior");
			return 1;
			}
		tablero[y][x] = asientoOcupado;

		printf("\e[2J\e[H");

		} else {

			printf("\e[2J\e[H");
			printf("La posición elegida no es válida");
			return 1;
			}
  return 0;
}
