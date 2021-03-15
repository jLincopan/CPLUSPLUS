from time import sleep

# variables globales (por mientras, cuando esté más completo el programa
# pienso quitarlas para solo usar variables locales)

# TODO: Hacer que la serpiente aparezca en un lugar aleatorio
ancho = 20
altura = 10

cuerpo_culebra = "[=]"
cabeza_culebra = "[>]"
espacio_vacio = "[ ]"

posicion_cabeza_x = 0
posicion_cabeza_y = 3
    
posicion_cola_x = 0
posicion_cola_y = 0

largo_culebra = posicion_cabeza_y - posicion_cola_y + 1
PANTALLA = []

#crea, llena y devuelve una matriz con los carácteres especificados en "caracter_inicial"
def crearMatriz(caracter_inicial, ancho, altura):
    matriz = []
    for i in range(altura):
        columna = []
        for j in range(ancho):
            columna.append(caracter_inicial)
        matriz.append(columna)
    return matriz

#llena la matriz que contiene la pantalla
def inicializarPantalla(ancho, altura):
    global PANTALLA
    PANTALLA = crearMatriz(espacio_vacio, ancho, altura)

def mostrarPantalla(PANTALLA):
    for i in range(altura):
        for j in range(ancho):
            print(PANTALLA[i][j], end="")
        print("")

# Llena las posiciones que debería ocupar la serpiente en la matriz
# que representa la pantalla, NO muestra la pantalla, solo cambia los
# carácteres dentro de esta para representar la serpiente
def dibujarCulebra(largo):
    global PANTALLA
    inicializarPantalla(ancho, altura) #reseteamos toda la pantalla

    #si la cabeza y la cola de la serpiente están en la misma columna
    if posicion_cabeza_y == posicion_cola_y:
        #si la cabeza está antes que la cola significa que vamos
        #de derecha a izquierda, por tanto retrocedemos

        if posicion_cabeza_x < posicion_cola_x:
            for i in range(largo-1):
                PANTALLA[posicion_cola_y][posicion_cola_x - i] = cuerpo_culebra
            PANTALLA[posicion_cabeza_y][posicion_cabeza_x] = cabeza_culebra

        #si la cabeza está después que la cola significa que vamos
        #de izquierda a derecha, por tanto avanzamos
        elif posicion_cabeza_x > posicion_cola_x:
            for i in range(largo-1):
                PANTALLA[posicion_cola_y][posicion_cola_x + i] = cuerpo_culebra
            PANTALLA[posicion_cabeza_y][posicion_cabeza_x] = cabeza_culebra

    #si la cabeza y la cola de la serpiente están en la misma fila
    elif posicion_cabeza_x == posicion_cola_x:
        #si la cabeza está arriba de la cola significa que vamos
        #de abajo hacia arriba, por tanto subimos

        if posicion_cabeza_y < posicion_cola_y:
            for i in range(largo-1):
                PANTALLA[posicion_cola_y-i][posicion_cola_x] = cuerpo_culebra
            PANTALLA[posicion_cabeza_y][posicion_cabeza_x] = cabeza_culebra

        #si la cabeza está abajo de la cola significa que vamos
        #de arriba hacia abajo, por tanto bajamos
        elif posicion_cabeza_y > posicion_cola_y:
            for i in range(largo-1):
                PANTALLA[posicion_cola_y+i][posicion_cola_x] = cuerpo_culebra
            PANTALLA[posicion_cabeza_y][posicion_cabeza_x] = cabeza_culebra

def derecha():
    global posicion_cabeza_x
    global posicion_cola_x
    posicion_cabeza_x+=1
    posicion_cola_x+=1
    

def izquierda():
    global posicion_cabeza_x
    global posicion_cola_x
    posicion_cabeza_x-=1
    posicion_cola_x-=1

def abajo():
    global posicion_cabeza_y
    global posicion_cola_y
    posicion_cabeza_y+=1
    posicion_cola_y+=1

def arriba():
    global posicion_cabeza_y
    global posicion_cola_y
    posicion_cabeza_y-=1
    posicion_cola_y-=1

def avanzar():
    
    # aquí vemos hacia dónde avanzar dependiendo de
    # la posición relativa de la cabeza de la serpiente
    # y su cola:

    if posicion_cabeza_y == posicion_cola_y:
        if posicion_cabeza_x < posicion_cola_x:
            izquierda()
        elif posicion_cabeza_x > posicion_cola_x:
            derecha()
    
    elif posicion_cabeza_x == posicion_cola_x:
        if posicion_cabeza_y < posicion_cola_y:
            arriba()
        elif posicion_cabeza_y > posicion_cola_y:
            abajo()
    dibujarCulebra(largo_culebra)

#función principal
def culebron():
    inicializarPantalla(ancho, altura)

    #bucle principal
    while 1:
        print("\033[H\033[J") #limpiamos la pantalla sin usar llamadas del sistema
        mostrarPantalla(PANTALLA)
        print()
        avanzar()
        sleep(0.250)
    
culebron()