# Tarea 4

**Importante: ** _Para ejecutar cada parte, sacar de su carpeta a la raiz de esta rama y ejecutar build.mk, y el ejecutable posteriormente_

## Parte 1: Eliminar malloc

Se sustituyó malloc usando memoria estrictamente estática, mediante el uso de un arreglo y demás herramientas.

## Parte 2: Impresión en Assembly de String

Con el uso del alojador de memoria Arena Lineal guardamos strings. Luego, se extraen y se imprimen en pantalla utilizando la función en Assembly (ASM) creada en tareas anteriores.

## Parte 3: Calculadora RPN

Se usó el alojador de memoria Arena Stack, y la lógica RPN (Reverse Polish Notation). El usuario debe ingresar primero los operandos y luego el operador (ej. ingresar X, ingresar Y, ingresar -).

Soporta la agrupación lógica, además el programa no sufre un "crasheo" por errores matemáticos(Ej. Si se intenta dividir por cero (X / 0)).
