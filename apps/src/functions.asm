bits 64
global asmprint

section .data
    newline db 0xA; 

section .text

asmprint:
    mov r10, 0; contador
    mov r8,rdi; respaldo string
    mov r9,rsi; respaldo longitud

.bucle:
    cmp r10, r9; comparar longitud con 0
    je .finbucle; si longitud es 0, salir del bucle

    mov rax, 1; condicion 1 para imprimir
    mov rdi, 1; condicion 2 para imprimir
    mov rsi, r8; caracter a imprimir
    mov rdx, 1; cantidad a imprimir
    syscall; imprimir

    inc r10; incrementar contador
    add r8, rdx; mover al siguiente caracter
    jmp .bucle; repetir bucle

.finbucle:
    mov rax, 1; condicion 1 para imprimir
    mov rdi, 1; condicion 2 para imprimir
    mov rsi, newline; caracter a imprimir
    mov rdx, 1; cantidad a imprimir
    syscall; imprimir
    ret