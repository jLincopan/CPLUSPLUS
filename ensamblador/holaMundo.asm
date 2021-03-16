;Usando nasm como ensablador, linux x86_64

section .data
    texto db "Hola mundo!",10

section .text ;se le dice al "linker" que hay una función "_start"
    global _start

_start: ; si el compilador no encuentra _start, dará error. Es donde por convenio
        ; empiezan los programas

    mov rax, 1 ; Se usa la syscall con id 1, "sys_write"
    ;Cargando en memoria los parámetros de la llamada
    mov rdi, 1 ; Le especifica a "system_write" que escriba en stdout (standard output)
    mov rsi, texto ; Se le dice que esos son los datos a escribir
    mov rdx, 14 ; El tamaño en bites de los datos a escribit
    syscall ; Se hace la llamada, "system_write" toma los parámetros que encuentra
            ; en los registros

    mov rax, 60 ; Syscall id 60, "sys_exit", termina el proceso (creo)
    mov rdi, 0 ; Parámetro, esto equivale a sys_exit(0)
    syscall ; Se hace la llamada