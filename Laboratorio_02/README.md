<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">TALLER - 21 de marzo 2024</p>

# Laboratorio 2: Ordenación
<p style="color:gray; font-size: 14px;">
    -Revisión 2024: Marco Rocchietti
</p>

## Objetivos
1. Introducir las cadenas en C.
2. Repaso de **typedef**.
3. Implementar el algoritmo de ordenación por inserción (*insertion-sort*).
4. Implementar el algoritmo de ordenación rápida (*quick-sort*).
5. Comparar desempeño de los algoritmos *selection-sort*, *insertion-sort* y *quick-sort* en distintos ejemplos.
6. Lectura y compresnsión del código entregado por la cátedra.
7. Trabajar con implementaciones opacas de fnciones leyendo su documentación.
8. Abstraer la noción de orden.
9. Usar procedimientos en C.
10. Uso de funciones locales en módulos en C.

## Ejercicio 0: Cadenas
Las cadenas en C se pueden pensar como arreglos de caracteres (más adelante veremos que también son punteros, pero por ahora… usamos arreglos). Los caracteres son valores del tipo `char` (que representa exactamente un caracter de *1 byte*), entonces para guardar un *string* en C se puede usar el siguiente arreglo:
```c
char cadena[5];
```
Es este ejemplo el arreglo `cadena` tiene capacidad para guardar un *string* de hasta 4 (cuatro) caracteres de longitud. Esto es así porque toda cadena en C **debe terminar con el caracter '\0'** por lo cual ya tenemos un lugar ocupado. Esta convención permite saber donde termina la cadena independientemente de la capacidad del arreglo. Entonces, se puede almacenar una **cadena** una palabra con longitud de entre uno y cuatro caracteres, pero incluso también se puede guardar una palabra vacía (en este caso **cadena[0] == '\0'**). Si queremos armar el *string* con la palabra "hola" podemos hacer:
```c
char cadena[5] = {'h', 'o', 'l', 'a', '\0'};
printf("cadena: %s\n", cadena);
```
Es muy importante no olvidarse de poner el **'\0'** final ya que de lo contrario **printf()** va a recorrer a **cadena[]** por fuera de su rango hasta que aparezca un **'\0'** y al acceder a memoria inválida se producirá eventualmente una **violación de segmento** (*segmentation fault*). Notar que no hay ningún problema en hacer
```c
char cadena[10]={'h', 'o', 'l', 'a', '\0'};
printf("cadena: %s\n", cadena);
```
ya que simplemente estamos usando cinco de los diez elementos del arreglo. Como el **'\0'** se encuentra en **cadena[4]**, la función **printf()** en el ejemplo anterior va a mostrar los caracteres que hay hasta esa posición (sin incluirla).

Otra forma más cómoda de armar el string con la palabra “hola” es hacer algo como:
```c
char cadena[10]="hola";
printf("cadena: %s\n", cadena);
```
En este caso el caracter **'\0'** se agrega implícitamente en el arreglo **cadena**. Para no tener que contar la
cantidad de caracteres que necesitamos se puede definir una cadena directamente haciendo:
```c
char cadena[]="hola mundo!";
printf("cadena: %s\n", cadena);
```
el contenido del array es el siguiente:

![cadena](https://i.ibb.co/c1X49md/Captura-desde-2024-03-22-23-40-17.png "cadena")

Cabe destacar que todas estas maneras de armar strings solo son válidas al momento de inicialización del arreglo. Si hacemos
```c
char cadena[]="hola mundo!";
cadena = "chau mundo!";
printf("cadena: %s\n", cadena);
```
El resultado va a ser un error de compilación. En este ejercicio vamos a trabajar con **cadenas guardadas en arreglos** que tienen un **tamaño fijo**. Vamos a definir un tipo para estas cadenas usando **typedef**. A modo de repaso, lo que hace **typedef** es dar un nombre nuevo a un tipo que ya existe en C. Entonces por ejemplo si queremos definir el tipo **natural** para los números positivos:
```c
typedef unsigned int natural;
```
de esta manera cuando declaremos una variable del tipo **natural** la variable va a ser equivalente a una variable del tipo **unsigned int**. La sintaxis entonces es:
```c
typedef <tipo-existente> <nuevo-tipo>;
```
Para definir el tipo nuevo **fixstring** hay que usar una sintaxis más extraña:
```c
#define FIXSTRING_MAX 100
typedef char fixtring [FIXSTRING_MAX];
```
Lo que se hace aquí es definir el tipo **fixstring** como el tipo de los arreglos de elementos de tipo **char** que tienen una capacidad de **FIXSTRING_MAX** elementos. O sea que si declaramos
```c
fixstring s;
```
es lo mismo que declarar
```c
char s[FIXSTRING_MAX];
```
Dentro de la carpeta **ej0** van a encontrar los archivos **fixstring.h**, **fixstring.c** y **main.c**. Deben implementar en **fixstring.c** las funciones:
```c
unsigned int fstring_length(fixstring s);
bool fstring_eq(fixstring s1, fixstring s2);
bool fstring_less_eq(fixstring s1, fixstring s2);
```
La función **fstring_length()** devuelve la longitud de la cadena guardada en el parámetro **s**, la función **fstring_eq()** indica si las cadenas s1 y s2 son iguales (contienen la misma cadena), mientras que **fstring_less_eq()** indica si la cadena guardada en s1 es menor o igual que la guardada en s2 en el sentido del orden alfabético. **No se permite usar librerías de C como string.h ni strings.h**. Una vez implementadas pueden probarlas compilando junto con **main.c**.