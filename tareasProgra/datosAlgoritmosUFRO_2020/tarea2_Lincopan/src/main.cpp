/*  Universidad de La Frontera
*   Ingeniería Civil Telemática
*
*   IIE-344 Estructura de Datos y Algoritmos
*
*   Tarea 2
*
*   Autor: Javier Lincopán (j.lincopan01@ufromail.cl)
*
*   Fecha: 03/09/2020
*
*   Descripción general del programa:
*        Programa que utiliza un TDA lista
*        para mantener la información relevante sobre vendedores y los clientes asociados a cada vendedor
*        de una empresa de ventas puerta a puerta, hecho para la tarea 2 del ramo IIE-344 Estructura de 
*        Datos y Algoritmos.
*
*        Los datos se guardan en un archivo binario ubicado en datos/ventas.bin (modificable usando 
*        la macro RUTA_DATOS ubicada en src/include/manejoDatos.h). Se cargan desde ahí
*        cada vez que corre el programa y se sobreescribe cada vez que finaliza el programa 
*        y se hizo alguna modificacíon en la la lista de vendedores cargada en RAM, de lo contrario
*        solo se sale del programa.
*
*        En el archivo binario se guardan los vendedores y luego sus respectivos clientes, finalizando
*        con la cadena de texto |FIN_VENDEDOR| para señalar que se terminaron de escribir
*        los clientes asociados a un vendedor y dar paso a la escritura del siguiente vendedor
*        (modificable usando la macro FIN_VENDEDOR ubicada en src/include/manejoArchivos.h),
*        como se puede ver acá: 
*
*            Fragmento de la salida del comando hexdump -C datos/ventas.bin sobre datos usados para pruebas
*
*                        Cadena FIN_VENDEDOR señalando el fin de los datos de los clientes del vendedor anterior
*                                                                                ^
*                                                                                |    |----|
*            00000240  46 49 4e 5f 56 45 4e 44  45 44 4f 52 7c 00 7a 00  |FIN_VENDEDOR|.z.||-> //empiezan los datos
*            00000250  00 00 00 00 00 00 6a 61  76 69 65 72 00 00 00 00  |......javier....|    //del siguiente vendedor
*            00000260  00 00 00 00 00 31 32 33  00 00 00 00 00 00 00 00  |.....123........|
*            00000270  00 00 00 00 31 32 33 00  00 00 00 00 00 00 7b 00  |....123.......{.| //al leer los datos, se
*            00000280  00 00 00 00 00 00 31 32  33 00 00 00 00 00 00 00  |......123.......| //lee un trozo de datos del
*            00000290  00 00 00 00 00 00 00 00  00 00 7b 00 00 00 31 32  |..........{...12| //tamaño de una struct Vendedor
*            000002a0  33 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |3...............| //y se asume que lo que sigue
*            000002b0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 20 02  |.............. .| //o bien son clientes
*            000002c0  00 00 f0 60 00 00 31 32  33 00 00 00 00 00 00 00  |...`..123.......| //o un fin_vendedor
*            000002d0  00 00 00 00 00 31 32 33  00 00 00 00 00 00 00 00  |.....123........|
*            000002e0  00 00 00 00 31 32 33 00  00 00 00 00 00 00 7b 00  |....123.......{.|
*            000002f0  00 00 00 00 00 00 31 32  33 00 00 00 00 00 00 00  |......123.......|
*            00000300  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*            *
*            00000320  00 00 00 00 00 00 00 00  00 00 7b 00 00 00 31 32  |..........{...12|
*            00000330  33 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |3...............|
*            00000340  00 00 00 00 00 00 00 00  00 00 00 00 00 00 7b 00  |..............{.|
*            00000350  00 00 00 00 00 00 31 33  32 00 00 00 00 00 00 00  |......132.......|
*            00000360  00 1b 01 00 00 00 7c 46  49 4e 5f 56 45 4e 44 45  |......|FIN_VENDE|
*            00000370  44 4f 52 7c 00                                    |DOR|.| //Fin vendedor, además del 
*            00000375                                                            //fin del archivo binario
* 
*
*
*/

#include <stdio.h>
#include <string.h>

#include "include/listaVendedores.h"
#include "include/listaClientes.h"
#include "include/manejoDatos.h"
#include "include/manejoArchivos.h"
#include "include/manejoPantalla.h"

bool modificacion = false;

int main() {

    ListaVendedores listaPrincipal; //lista principal en RAM

    limpiarPantalla();
    extraerListaVendedores_binario(listaPrincipal); // Leemos los datos desde el archivo definido en 
                                                    // src/include/manejoArchivos.h
    menuPrincipal(listaPrincipal); //menú principal, duh

    //si no se modifica la lista principal, no se sobreescribirán los datos 
    //del archivo desde el que se leyeron
    if(modificacion) {
        guardarListaVendedores_binario(listaPrincipal);
    }

    return 0;
}