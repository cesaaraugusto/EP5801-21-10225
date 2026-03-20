bits 64
global asmprint

section .data
    newline db 0xA; 

section .text

asmprint:
    mov r8,rdi; respaldo string
    mov r9,rsi; respaldo longitud

    mov rax, 1; condicion 1 para imprimir
    mov rdi, 1; condicion 2 para imprimir
    mov rsi, r8; caracter a imprimir
    mov rdx, r9; cantidad a imprimir
    syscall; imprimir

    mov rax, 1; condicion 1 para imprimir
    mov rdi, 1; condicion 2 para imprimir
    mov rsi, newline; caracter a imprimir
    mov rdx, 1; cantidad a imprimir
    syscall; imprimir
    ret