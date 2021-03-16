#!/bin/bash

#script simple para probar los programas
#en ensamblador porque me da flojera escribir
#los comandos una y otra vez

#sintaxis: ./probar.sh "nombre del archivo ensablador"
nasm -f elf64 $1 && ld holaMundo.o && ./a.out