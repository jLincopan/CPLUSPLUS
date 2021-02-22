#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define SIZE 10

/* * Nombre de la función: getPassword.
* Tipo de función: void.
* Parámetros: password, de tipo char[]
* Dato de retorno: ninguno
* Descripción de la función: Se encarga de registrar un string SIN mostrarlo en pantalla,
* almacenándolo en el array password que recibe como parámetro.
* He de admitir que esta la saqué de internet ya que no se me ocurría como hacerlo*/
void getPassword(char password[])
{
    static struct termios oldt, newt;
    int i = 0;
    int c;

    /*saving the old settings of STDIN_FILENO and copy settings for resetting*/
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;

    /*setting the approriate bit in the termios struct*/
    newt.c_lflag &= ~(ECHO);

    /*setting the new bits*/
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    /*reading the password from the console*/
    while ((c = getchar())!= '\n' && c != EOF && i < SIZE){
        password[i++] = c;
    }
    password[i] = '\0';

    /*resetting our old STDIN_FILENO*/
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

}
