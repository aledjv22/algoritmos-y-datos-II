<h1 align="center" style="font-weight:bold;">Algoritmos y Estructuras de Datos II</h1>
<p align="center" style="color:gray; font-size: 20px; font-weight:bold;">TALLER - 18 de abril 2024</p>

# Laboratorio 3: Matrices
<p style="color:gray; font-size: 14px;">
    -Revisión 2024: Marco Rocchietti
</p>

## Objetivos
1. Comenzar a trabajar con punteros en C.
2. Simular variables de salida con punteros.
3. Comprender uso de punteros para mayor desempeño.
4. Administración de memoria dinámica (`malloc()`, `calloc()`, `free()`).
5. Llevar a lenguaje C los conceptos de TAD estudiados en el Teórico-Práctico.
6. Comprender conceptos de encapsulamiento vs acoplamiento.
7. Comprender concepto de implementación opaca.

## Preliminares: Punteros 101
El objetivo del primer ejercicio es adquirir un entrenamiento básico y comprender el funcionamiento de punteros en C.
Un puntero es un tipo de variable especial que guarda una dirección de memoria. En C se denotan los punteros usando el símbolo **`*`**. Es decir que una variable **p** declarada como **`int *p;`** es del tipo *<ul>puntero a int</ul>*.
Para el manejo de punteros contamos con dos operadores unarios básicos, el operador de referenciación y el de desreferenciación. 

### Operación de referenciación (&)
Este operador obtiene la <ul>dirección de memoria</ul> de una variable. También se lo conoce como operador de dirección (*address operator*). Si se tiene una variable entera **`x`** declarada como **`int x=3;`** entonces la expresión **`&x`** retornará la dirección de memoria donde está alojado el contenido de la variable **`x`**.
![](https://i.ibb.co/FHft3Kt/Captura-desde-2024-04-24-23-51-43.png)

### Operación de desreferenciación (*)
Obtiene el **valor** de lo apuntado por el puntero. También se lo conoce como el operador de indirección (indirection operator). Se lo puede pensar como una operación de inspección ya que accede al valor alojado en una dirección de memoria. Si se tiene una variable de tipo **`int*`** llamada **`p`**, entonces la expresión **`*p`** retornará el valor entero que se aloja en la dirección de memoria que contiene **`p`**. En el ejemplo de más arriba **`*p`** devuelve **3**.
Además si se utiliza **`*p`** del lado izquierdo de una asignación:
```c
*p = <expresión>;
```

la asignación escribirá el resultado de la expresión en la dirección de memoria apuntada por **`p`**, por lo que se cambia el valor contenido en esa dirección de memoria (sin modificar a **`p`**, que seguirá apuntando al mismo lugar). Por ejemplo, si se hace la asignación
```c
int x=3;
int *p;
p = &x;
*p = 10;
```

entonces sucede que
![](https://i.ibb.co/NpTSgyM/Captura-desde-2024-04-24-23-56-35.png)

Notar que se cambió el valor de la variable **`x`** de manera indirecta usando el puntero **`p`**.
Cabe aclarar que cuando se declara la variable de tipo puntero **`int *p;`** el símbolo **`*`** no actúa como operador sino que simplemente indica que la variable **`p`** se declara como puntero.
Para pensar: ¿Qué valor tendrá la variable y luego de ejecutar el siguiente código?
```c
int x = 3;
int y = 10;
y = *(&x);
```

En el [Laboratorio 1](../Laboratorio_01/) se utilizaba la función **`fscanf()`** ¿Qué parámetros tomaba dicha función y cuál era el tipo de cada uno?

### Constante nula de punteros (NULL)
Siempre es buena idea dar un valor inicial a las variables apenas se declaran. Para punteros existe en C la constante **`NULL`** que representa una dirección de memoria nula, en la cual no se puede leer ni escribir. Esta constante es una macro definida en los headers de **[stdlib.h](https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm)** como la dirección de memoria `0`.
Recordar que si no se inicializa una variable esta puede contener cualquier valor, en el caso de enteros podría ser un número muy grande y extraño (o quizás un inofensivo 4) y en el caso de punteros puede tener asignada una dirección de memoria que en caso de querer escribir o leer de ella generaría problemas. Por ejemplo en el siguiente programa:
```c
int *p;
*p = 3;
```

es fácil imaginar que esto podría generar que el programa termine con un error (violación de segmento - *segmentation fault*) pero podría ser peor. Puede suceder que por azar en **`p`** se encuentre la dirección de memoria de otra variable del programa y la modifiquemos, generando un **BUG** muy difícil de rastrear.
En esta otra versión:
```c
int *p=NULL;
*p = 3;
```

el programa siempre va a fallar, y eso es bueno.
Claramente los ejemplos de arriba son errores que saltan a la vista pero sirven para ilustrar situaciones en la que no es tan obvio que se usa un puntero sin inicializar, pero el efecto es el mismo.