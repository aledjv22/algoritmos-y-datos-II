<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">TALLER - 14 de marzo 2024</p>

# Laboratorio 1: Arreglos, Archivos, Módulos
<p style="color:gray; font-size: 14px;">
    -Revisión 2024: Marco Rocchietti
</p>

## Objetivos
1. Familizarse con vocabulario informático: directorio, archivo, array, path, etc.
2. Reforzar cómo compilar programas con **gcc**.
3. Tener manejo de las instrucciones básicas del lenguaje de programación C.
4. Comenzar a manejar archivos como fuente de datos.
5. Tener manejo de **standard input** y **standard output**.
6. Tener nociones del manejo de parámetros a través de la función principal `main()`.
7. Trabajar con módulos en C.

## Ejercicio 1 - Lectura de archivos
En el directorio **ej1** se encuentra el archivo principal **main.c**, por otro lado los archivos de
entrada están en el directorio input que se encuentra un nivel arriba de **ej1**, ya que
todos los ejercicios utilizaran los mismos archivos de entrada. Cada archivo de la carpeta
**input** tiene un nombre con extensión ***in*** y contiene los datos de un arreglo que ha sido
guardado dentro de él. El arreglo (o *array*) se representa con su tamaño (*size*) y luego se
enumera cada uno de los elementos, separándolos con espacios. Por ejemplo, un array
cuyos elementos son **[1,2,3,4,5]** es representado en el archivo como:
```bash
5
1 2 3 4 5
```
El archivo principal es **main.c**, donde se va a programar el ejercicio. Para compilarlo:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o reader main.c
```
Se pide que el programa principal sea capaz de leer *arrays* de cualquiera de los archivos dentro del directrio **input** y que luego imprima por pantalla su contenido. Entonces por ejemplo al ejecutar el programa:
```bash
./reader ../input/example-easy.in
``` 
se le está indicando al programa **render** que lea el archivo **example-easy.in** que para encontrarlo debe primero subir un nivel (eso indica el **..** que se incluye en la ruta o *path*) y luego entrar en el directorio **input**. Al ejecutar se debe obtener la siguiente salida por pantalla:
```bash
[1, 2, 3, 4, 5]
```
Para ello se deben completar las definiciones de las funciones `array_from_file()`y la función `array_dump()`.
Se suguiere no esperar hasta el final para compilar, se puede ir compilando a medida que se completan las funcionalidades del programa.

> *💡Pueden ser de utilidad las funciones `fopen()`, `fscanf()`, `fclose()`... se pueden consultar las páginas del manual de referencia de linux, por ejemplo:* `$ man fopen`.

## Ejercicio 2 - Entrada Estándar
Modificar **main.c**  (no borrar el original!) para que el programa en lugar de leer un archivo de la carpeta **input**, lea el tamaño y cada uno de los miembros del *array* por teclado y luego los muestre por la pantalla. Se puede (y se sugiere fuertemente) reutilizar la función `array_from_file()` la cual puede pasar a llamarse `array_from_stdin()` donde el parámetro `filepath`ya no será necesario. Además tampoco serán necesarios los parámetros de la función `main()` puesto que el programa se ejecuta sin especificar ningún archivo de entrada.

> *💡Investigar sobre standard input:* `$ man stdin`.

> *💡Cuando se ejecute el programa, luego de ingresar los elementos presionar CTRL + D para enviar la señal de EOF(end of file) a la entrada estándar.*
