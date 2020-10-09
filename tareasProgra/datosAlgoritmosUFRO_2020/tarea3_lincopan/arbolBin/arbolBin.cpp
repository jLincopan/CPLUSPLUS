/*⚠️⚠️⚠️______________ALERTA DE CÓDIGO SPAGUETTI______________⚠️⚠️⚠️
* Esta tarea se hizo más o menos a la rápida y por tanto, contiene
* una alta dosis de código spaguetti, se recomienda discreción
*/

#include <stdio.h>
#include <string.h>
#include "arbolBin.h"

/* Nombre de la función: arbolToBin.
* Tipo de función: ArbolBin.
* Parámetros: n, de tipo Arbol.
* Dato de retorno: bin, de tipo arbolBin
* Descripción de la función: Transforma un dato de tipo
* Arbol en uno de tipo ArbolBin
*/

ArbolBin arbolToBin(Arbol n){
	ArbolBin bin;
	bin.primero = n.primero;
	return bin;
}

/* Nombre de la función: creaNodo.
* Tipo de función: ArbolBin.
* Parámetros: u, de tipo Arbol.
* Dato de retorno: un nodo de tipo ArbolBin
* Descripción de la función: Crea un nodo ArbolBin a partir
* de un datoArbol
*/

ArbolBin creaNodo(datoArbol u){
	//crea el nodo raiz
	Arbol raiz = creaRaiz(u);
	//se crean e inserta el nodo terminal izquierdo
	Arbol Ti = creaRaiz(NODO_NULO);
	insertaHijoMasIzq(raiz, Ti);
	Ti = hijoMasIzq(raiz);
	//se crean e inserta el nodo terminal derecho
	Arbol Td = creaRaiz(NODO_NULO);
	insertaHermanoDer(Ti,Td);
	return arbolToBin(raiz);
}

/* Nombre de la función: hijoIzq.
* Tipo de función: ArbolBin.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: un nodo de tipo ArbolBin
* Descripción de la función: Devuelve el hijo a la izquierda
* del nodo ArbolBin recibido como parámetro
*/

ArbolBin hijoIzq(ArbolBin n){
	Arbol Ti = hijoMasIzq(n);
	return arbolToBin(Ti);
}

/* Nombre de la función: existeHijoIzq.
* Tipo de función: bool.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: un booleano
* Descripción de la función: devuelve true si existe un hijo
* a la izquierda de n, false si no
*/

bool existeHijoIzq(ArbolBin n) {
	Arbol Ti = hijoIzq(n);
	if(strncmp(NODO_NULO.nombre, Ti.primero->dato.dato.nombre, sizeof(NODO_NULO.nombre)) == 0)
		return false;
	return true;
}

/* Nombre de la función: existeHijoDer.
* Tipo de función: bool.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: un booleano
* Descripción de la función: devuelve true si existe un hijo
* a la derecha de n, false si no
*/

bool existeHijoDer(ArbolBin n) {
	Arbol Ti = hijoDer(n);
	if(strncmp(NODO_NULO.nombre, Ti.primero->dato.dato.nombre, sizeof(NODO_NULO.nombre)) == 0)
		return false;
	return true;
}

/* Nombre de la función: hijoDer.
* Tipo de función: ArbolBin.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: un nodo de tipo ArbolBin
* Descripción de la función: devuelve el hijo a la derecha
* de n
*/

ArbolBin hijoDer(ArbolBin n){
	ArbolBin Ti = hijoIzq(n);
	Arbol Td = hermanoDer(Ti);
	return arbolToBin(Td);
}

/* Nombre de la función: insertaHijoIzq.
* Tipo de función: void.
* Parámetros: n, de tipo &ArbolBin, Ti, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: inserta el nodo Ti como hijo
* a la izquierda de n
*/

void insertaHijoIzq(ArbolBin & n, ArbolBin & Ti){
	ArbolBin hi = podarHijoIzq(n);
	anula((Arbol&)hi);
	insertaHijoMasIzq(n, Ti);
}

/* Nombre de la función: insertaHijoIzq.
* Tipo de función: void.
* Parámetros: n, de tipo &ArbolBin, Td, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: inserta el nodo Td como hijo
* a la derecha de n
*/

void insertaHijoDer(ArbolBin & n, ArbolBin & Td){
	ArbolBin hd = podarHijoDer(n);
	anula((Arbol&)hd);
	ArbolBin Ti = hijoIzq(n);
	insertaHermanoDer(Ti, Td);	
}

/* Nombre de la función: etiqueta.
* Tipo de función: datoArbol.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: un dato de tipo DatoArbol
* Descripción de la función: devuelve la parte que contiene
* los datos de un ArbolBin
*/

datoArbol etiqueta(ArbolBin n){
	return etiqueta((Arbol)n);	
}

/* Nombre de la función: reEtiqueta.
* Tipo de función: void.
* Parámetros: e, de tipo datoArbol, n, de tipo &ArbolBin, raiz, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: reemplaza la etiqueta que contiene n por
* e
*/

void reEtiqueta(datoArbol e, ArbolBin & n, ArbolBin raiz){
	reEtiqueta(e, (Arbol&) n, (Arbol) raiz);
}

/* Nombre de la función: podarHijoIzq.
* Tipo de función: ArbolBin.
* Parámetros: n, de tipo &ArbolBin.
* Dato de retorno: un nuevo nodo.
* Descripción de la función: elimina el hijo a la izquierda de n
* y devuelve un nuevo nodo sin este
*/

ArbolBin podarHijoIzq(ArbolBin  & n){
	Arbol Ti = podarHijoMasIzq(n);
	return arbolToBin(Ti);
}

/* Nombre de la función: podarHijoIzq.
* Tipo de función: ArbolBin.
* Parámetros: n, de tipo &ArbolBin.
* Dato de retorno: un nuevo nodo.
* Descripción de la función: elimina el hijo a la derecha de n
* y devuelve un nuevo nodo sin este
*/

ArbolBin podarHijoDer(ArbolBin  & n){
	ArbolBin Ti = hijoIzq(n);
	Arbol Td = podarHermanoDer(Ti);
	return arbolToBin(Td);
}

// Adicionales al TDA

/* Nombre de la función: esHoja.
* Tipo de función: bool.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: true o false
* Descripción de la función: si el nodo n es una hoja devuelve true,
* false si no
*/

bool esHoja(ArbolBin n){
	return (esNodoTerminal(hijoIzq(n)) && esNodoTerminal(hijoDer(n)));
}

/* Nombre de la función: esNulo.
* Tipo de función: bool.
* Parámetros: raiz, de tipo ArbolBin.
* Dato de retorno: true o false
* Descripción de la función: si el nodo raiz está vacío devuelve true,
* false si no
*/

bool esNulo(ArbolBin raiz){
	return esNulo((Arbol)raiz);
}

/* Nombre de la función: esNodoTerminal.
* Tipo de función: bool.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: true o false
* Descripción de la función: si el nodo n no contiene datos devuelve true,
* false si no
*/

bool esNodoTerminal(ArbolBin n){
	
	if(strncmp(n.primero->dato.dato.nombre, NODO_NULO.nombre, sizeof(NODO_NULO.nombre)) == 0) {
		return true;
	}
	
	return false;
}

/* Nombre de la función: ordenSimetrico.
* Tipo de función: void.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: recorre los nodos que pueda contener
* n, y los muestra en orden simétrico
*/

void ordenSimetrico(ArbolBin n){
	if(esNulo(n) || esNodoTerminal(n))
		return;
	ordenSimetrico(hijoIzq(n));
	mostrarDatos(n);
	ordenSimetrico(hijoDer(n));
}

/* Nombre de la función: ordenPrevio.
* Tipo de función: void.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: recorre los nodos que pueda contener
* n, y los muestra en orden previo
*/

void ordenPrevio(ArbolBin n){
	if(esNulo(n) || esNodoTerminal(n))
		return;
	mostrarDatos(n);
	ordenPrevio(hijoIzq(n));
	ordenPrevio(hijoDer(n));
}

/* Nombre de la función: ordenPosterior.
* Tipo de función: void.
* Parámetros: n, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: recorre los nodos que pueda contener
* n, y los muestra en orden posterior
*/

void ordenPosterior(ArbolBin n){
	if(esNulo(n) || esNodoTerminal(n))
		return;
	ordenPosterior(hijoIzq(n));
	ordenPosterior(hijoDer(n));
	mostrarDatos(n);
}

/* Nombre de la función: registrarDatos.
* Tipo de función: datoArbol.
* Parámetros: generacion, de tipo int, nombre, de tipo char[], nacimiento, de tipo char[],
*			  fallecimiento, de tipo char[]
* Dato de retorno: tmp, de tipo datoArbol
* Descripción de la función: toma los datos que se le dan y los guarda
* 							 en tmp, para devolverlos
*/

datoArbol registrarDatos(unsigned int generacion, const char nombre[], const char nacimiento[], const char fallecimiento[]) {
	datoArbol tmp;
	tmp.generacion = generacion;
	strncpy(tmp.nombre, nombre, sizeof(tmp.nombre));
	strncpy(tmp.fecha_nacimiento, nacimiento, sizeof(tmp.fecha_nacimiento));
	strncpy(tmp.fecha_fallecimiento, fallecimiento, sizeof(tmp.fecha_fallecimiento));
	
	return tmp;
}

/* Nombre de la función: mostrarDatos.
* Tipo de función: void.
* Parámetros: dato, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: imprime por pantalla los datos
* que contenga dato
*/

void mostrarDatos(ArbolBin dato) {
	datoArbol d = etiqueta(dato);

	printf("Generación: %i Nombre: %s Nacimiento: %s Fallecimiento: %s\n",d.generacion, d.nombre, d.fecha_nacimiento, d.fecha_fallecimiento);
}

/* Nombre de la función: mostrarNombre.
* Tipo de función: void.
* Parámetros: dato, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: imprime por pantalla el campo nombre
* que contiene el parámetro dato
*/

void mostrarNombre(ArbolBin dato) {
	datoArbol d = etiqueta(dato);

	printf("%s\n", d.nombre);
}

/* Nombre de la función: leerInt.
* Tipo de función: int.
* Parámetros: ninguno
* Dato de retorno: a, de tipo int
* Descripción de la función: lee un int desde teclado, y lo valida
*/

int leerInt() {
    int a = 0;
    int rc = 0;
    while ((rc = scanf("%d", &a)) == 0){
        scanf("%*[^\n]");
        printf("Dato no válido, ingrese el número de nuevo:\n");
    }
    return a;
}

/* Nombre de la función: leerLinea_texto.
* Tipo de función: void.
* Parámetros: largo, de tipo size_t, buffer, de tipo char[]
* Dato de retorno: ninguno
* Descripción de la función: una linea de texto de largo "largo", y la guarda
* en buffer[]
*/

void leerLinea_texto(size_t largo, char buffer[]) {

    char tmp[largo];
    while (1) {
        if (fgets(tmp, largo, stdin)) {
            tmp[strcspn(tmp, "\n")] = 0;
            break;
        } else {
            printf("Error en función leerLinea_texto, cadena de texto no válida\n");
            printf("intentelo de nuevo:\n\n");
        }
    }

    strncpy(buffer, tmp, largo);
}

/* Nombre de la función: mostrarArbolBinario.
* Tipo de función: void
* Parámetros: raiz, de tipo arbolBin
* Dato de retorno: ninguno
* Descripción de la función: muestra un arbol binario
*/

void mostrarArbolBinario(ArbolBin raiz) {
	printf("\n");
	for(int i = 1; i <= 5 ; i++) {
		printf("Generacion: %i	", i);
		mostrarNivel(raiz, i);
		printf("|\n");
	}
}

void mostrarNivel(ArbolBin raiz, int nivel) {

	if(esNodoTerminal(raiz)) {
		return;
	}

	if(nivel == 1) {
		printf("%s - ", raiz.primero->dato.dato.nombre);
	} else if(nivel > 1) {
		mostrarNivel(hijoIzq(raiz), nivel-1);
		mostrarNivel(hijoDer(raiz), nivel-1);
	}	

}

/* Nombre de la función: buscarPorNombre.
* Tipo de función: void.
* Parámetros: n, de tipo arbolBin, buffer, de tipo &ArbolBin, nombre, de tipo char[]
* Dato de retorno: ninguno
* Descripción de la función: busca un nombre en el arbol que contenga n, y si lo encuentra
* guarda el nodo que lo contenga en buffer
*/

void buscarPorNombre(ArbolBin n, ArbolBin &buffer, const char nombre[sizeof(NODO_NULO.nombre)]){
	if(esNulo(n) || esNodoTerminal(n))
		return;
	buscarPorNombre(hijoIzq(n), buffer, nombre);
	buscarPorNombre(hijoDer(n), buffer, nombre);

	if(strncmp(nombre, n.primero->dato.dato.nombre, sizeof(NODO_NULO.nombre)) == 0) {
		printf("\nNombre encontrado:\n");
		mostrarDatos(n);
		
		buffer.primero = n.primero;
		
	}
}

/* Nombre de la función: buscarPadrePorNombre.
* Tipo de función: void.
* Parámetros: raiz, de tipo &ArbolBin
* Dato de retorno: ninguno
* Descripción de la función: busca el padre de un nodo con determinad nombre
*/

void buscarPadrePorNombre(ArbolBin &raiz) {
	char nombre[sizeof(NODO_NULO.nombre)] = {0};

	printf("Ingrese el nombre de la persona:\n");
	leerLinea_texto(sizeof(NODO_NULO.nombre), nombre);

	ArbolBin buffer;
	ArbolBin father;
	buffer.primero = new nodo;
	father.primero = new nodo;

	buscarPorNombre(raiz, buffer, nombre);
	if(strncmp(NODO_NULO.nombre, buffer.primero->dato.dato.nombre, sizeof(NODO_NULO.nombre)) == 0) {
		printf("\nNombre no encontrado en el arbol\n\n");
		return;
	}
	
	encontrarPadre(raiz, nombre, father);

	if(strncmp(NODO_NULO.nombre, father.primero->dato.dato.nombre, sizeof(NODO_NULO.nombre)) == 0) {
		printf("\nPadre no encontrado\n\n");
		return;
	} else
		printf("\nDatos del padre:\n");
		mostrarDatos(father);
}

/* Nombre de la función: encontrarPadre.
* Tipo de función: void.
* Parámetros: raiz, de tipo ArbolBin, nombre, de tipo char[], buffer, de tipo &ArbolBin
* Dato de retorno: ninguno
* Descripción de la función: busca el padre del nodo que tenga el nombre recibido
* como parámetro, y si lo encuentra, lo guarda en buffer
*/

void encontrarPadre(ArbolBin raiz, char nombre[sizeof(NODO_NULO.nombre)], ArbolBin &buffer) {

	if(esNulo(raiz) || esNodoTerminal(raiz))
		return;

	if(strncmp(nombre, (hijoIzq(raiz).primero->dato.dato.nombre), sizeof(NODO_NULO.nombre)) == 0) {
		buffer.primero->dato.dato = raiz.primero->dato.dato;
	} 
	if (strncmp(nombre, (hijoDer(raiz).primero->dato.dato.nombre), sizeof(NODO_NULO.nombre)) == 0) {
		buffer.primero->dato.dato = raiz.primero->dato.dato;
	}

	encontrarPadre(hijoIzq(raiz), nombre, buffer);
	encontrarPadre(hijoDer(raiz), nombre, buffer);

}

/* Nombre de la función: buscarHijosPorNombre.
* Tipo de función: void.
* Parámetros: raiz, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: lee una linea de texto desde teclado,
* y luego busca los hijos del nodo que contenga esa linea en el campo nombre
*/

void buscarHijosPorNombre(ArbolBin raiz) {
	char nombre[sizeof(NODO_NULO.nombre)] = {0};
	ArbolBin buffer;
	buffer.primero = new nodo;
	buffer.primero->next = new nodo;
	buffer.primero->dato.hijos.primero = new nodo;
	buffer.primero->dato.hijos.primero->next = new nodo;

	printf("\nIngrese el nombre de la persona:\n");
	leerLinea_texto(sizeof(NODO_NULO.nombre), nombre);

	buscarPorNombre(raiz, buffer, nombre);
	if(strncmp(buffer.primero->dato.dato.nombre, NODO_NULO.nombre, sizeof(NODO_NULO.nombre)) == 0) {
		printf("Nombre no encontrado\n");
		return;
	}
	printf("\nHijos:\n");
	if(existeHijoIzq(buffer))
		mostrarDatos(hijoIzq(buffer));
	if(existeHijoDer(buffer))
		mostrarDatos(hijoDer(buffer));
}

/* Nombre de la función: familiaresConVidaContador.
* Tipo de función: void.
* Parámetros: raiz, de tipo ArbolBin, contador, de tipo &int.
* Dato de retorno: ninguno
* Descripción de la función: recorre todo el arbol recursivamente buscando nodos que
* contengan "-" en su campo fecha_fallecimiento para contarlos como
* familiares con vida
*/

void familiaresConVidaContador(ArbolBin raiz, int &contador) {

	if(esNulo(raiz) || esNodoTerminal(raiz))
		return;
	familiaresConVidaContador(hijoIzq(raiz), contador);
	familiaresConVidaContador(hijoDer(raiz), contador);

	if(strncmp(raiz.primero->dato.dato.fecha_fallecimiento, "-", sizeof(NODO_NULO.fecha_fallecimiento)) == 0) {
		contador++;
	}
}

/* Nombre de la función: familiaresConVida.
* Tipo de función: void.
* Parámetros: raiz, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: se encarga de llamar a la funcion recursiva
* que cuenta los familiares con vida, y muestra el número por pantalla
*/

void familiaresConVida(ArbolBin &raiz) {
	int contador = 0;
	familiaresConVidaContador(raiz, contador);
	printf("\nCantidad de familiares con vida: %d\n", contador);
	
}

/* Nombre de la función: editarDatosPorNombre.
* Tipo de función: void.
* Parámetros: raiz, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: lee una linea de texto desde teclado
* y busca un nodo que contenga esa linea en su campo nombre
* para editarlo
*/

void editarDatosPorNombre(ArbolBin raiz) {
	char nombre[sizeof(NODO_NULO.nombre)];

	printf("\nIngrese el nombre del usuario a editar:\n");
	leerLinea_texto(sizeof(NODO_NULO.nombre), nombre);

	ArbolBin buffer;
	buffer.primero = new nodo;

	buscarPorNombre(raiz, buffer, nombre);
	if(strncmp(buffer.primero->dato.dato.nombre, NODO_NULO.nombre, sizeof(NODO_NULO.nombre)) == 0) {
		printf("\nNombre no encontrado\n");
		return;
	}
	int opcion = 0;

	printf("\nELija el dato a editar:\n\n");
	printf("1)Nombre\n");
	printf("2)Fecha de nacimiento\n");
	printf("3)Fecha de deceso\n");

	opcion = leerInt();
	getchar();
	char fecha[sizeof(NODO_NULO.fecha_nacimiento)] = {0};
	switch (opcion)
	{
	case 1:
		printf("\nIngrese el nuevo nombre:\n");
		leerLinea_texto(sizeof(NODO_NULO.nombre), nombre);
		strncpy(buffer.primero->dato.dato.nombre, nombre, sizeof(NODO_NULO.nombre));
		break;
	case 2:
		printf("\nIngrese la nueva fecha de nacimiento:\n");
		leerLinea_texto(sizeof(NODO_NULO.nombre), nombre);
		strncpy(buffer.primero->dato.dato.fecha_nacimiento, fecha, sizeof(NODO_NULO.nombre));
	case 3:
		printf("\nIngrese la nueva fecha de fallecimiento:\n");
		leerLinea_texto(sizeof(NODO_NULO.nombre), nombre);
		strncpy(buffer.primero->dato.dato.fecha_fallecimiento, fecha, sizeof(NODO_NULO.fecha_fallecimiento));
	default:
		printf("\nError\n");
		break;
	}
}

/* Nombre de la función: generacionPorNombre.
* Tipo de función: void.
* Parámetros: raiz, de tipo ArbolBin.
* Dato de retorno: ninguno
* Descripción de la función: lee una linea de texto desde teclado, y
* busca nodos que contengan esa linea en su campo nombre. Si lo encuentra
* muestra por pantalla la generacion de ese nodo
*/

void generacionPorNombre(ArbolBin raiz) {
	char nombre[sizeof(NODO_NULO.nombre)];
	ArbolBin buffer;
	buffer.primero = new nodo;

	printf("\nIngrese el nombre de la persona\n");
	leerLinea_texto(sizeof(NODO_NULO.nombre), nombre);

	buscarPorNombre(raiz, buffer, nombre);
	if(strncmp(buffer.primero->dato.dato.nombre, NODO_NULO.nombre, sizeof(NODO_NULO.nombre)) == 0) {
		printf("\nNombre no encontrado\n");
		return;
	}

	printf("\nGeneracion: %d\n", buffer.primero->dato.dato.generacion);	
}

//no funcionaaaaaaaaaaaaaaaaaaaaaaa
void buscarFamiliarMasLongevo(ArbolBin raiz, char buffer[sizeof(NODO_NULO.nombre)], int a) {
	if(esNulo(raiz) || esNodoTerminal(raiz))
		return;

	if(strncmp(hijoIzq(raiz).primero->dato.dato.fecha_fallecimiento, "-", sizeof(NODO_NULO.fecha_fallecimiento)) == 0)
		return;
	if(strncmp(hijoDer(raiz).primero->dato.dato.fecha_fallecimiento, "-", sizeof(NODO_NULO.fecha_fallecimiento)) == 0)
		return;

	int b = 0;
	int c = 0;
	int d = 0;

	int suma1 = 0;
	int suma2 = 0;

	buscarFamiliarMasLongevo(hijoIzq(raiz), buffer, a);
	buscarFamiliarMasLongevo(hijoDer(raiz), buffer, a);

	sscanf(hijoDer(raiz).primero->dato.dato.fecha_nacimiento, "%d-%d-%d", &b, &c, &d);
	suma1 = b + c + d;
	sscanf(hijoIzq(raiz).primero->dato.dato.fecha_nacimiento, "%d-%d-%d", &b, &c, &d);
	suma2 = b + c + d;

	if(suma1 < suma2) {
		strncpy(buffer, hijoDer(raiz).primero->dato.dato.nombre, sizeof(NODO_NULO.nombre));
	} else if(suma2 > suma1) {
		strncpy(buffer, hijoIzq(raiz).primero->dato.dato.nombre, sizeof(NODO_NULO.nombre));
	}

}

//no funcionaaaaaaaaaaaaaaaaaaaa
void familiarMasLongevo(ArbolBin raiz) {
	ArbolBin buffer;
	char nombre[sizeof(NODO_NULO.nombre)] = {0};
	buffer.primero = new nodo;

	buscarFamiliarMasLongevo(raiz, nombre, 3000);
	printf("%s", nombre);
}