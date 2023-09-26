# Tipos abstractos de datos (TAD) en C

# - Introducción

Proyecto realizado en la asignatura de Estructuras de Datos y Algortimos I del grado de Ingenieria Informática de la Universidad de Salamanca. El enunciado del proyecto se encuentra subido en el repositorio en un archivo pdf llamado *entregaTAD2020.pdf*.  
  
El principal objetivo de este proyecto es la implementación de los tipos abstractos de datos lista, pila y cola en el lenguaje C. De esta manera, podemos utilizar esta implementación de manera sencilla en otros programas que en C que requieran del uso de listas, pilas o colas.

# - Comentarios sobre el material adjuntado

La carpeta principal **TAD** cuenta con 3 subcarpetas llamadas ***listas***, ***colas*** y ***pilas***. Cada una de estas subcarpetas contiene un fichero .c con la implementacion del TAD correspdiente y un fichero .h de cabecera que define las funciones creadas.  

Adicionalmente, se incluye un fichero llamado *pruebaLista.c* que contiene un codigo para probar la correcta implementación de los TAD lista, pila y cola.  

También se incluye un fichero *makefile* que contiene las directivas necesarias para compilar dicho fichero incluyendo las implementacion de los 3 TAD.

Por último, se adjunta un fichero de texto llamado *Resultados.txt* que contiene los resultados esperados para el programa simepore y cuando el TAD este correctamente implementado.

# - Comentarios sobre la ejecución

Para probar la correcta implementación de los TAD, se requerirá de una distribución del Sistema Operativo **GNU/Linux**.    

Para compilar el fichero de pruebas, se utilizará el siguiente comando:

```make```

Este comando generará un ejecutable llamado *./pruebaLista* a partir del fichero *pruebaLista.c* y las implementaciones de los TAD.

Para ejecutar el programa, bastará con introducir el siguiente comando por la terminal:

```./pruebaLista```

# - Ejemplo de ejecución

En las siguientes imagenes, se muestra un ejemplo del uso y funcionamiento del programa:    

![Ejemplo ejecucion menu 1](https://github.com/rmelgo/scripts-menus-unix/assets/145989723/0eec2d0f-43cb-4f2c-a6d5-42fb2bdd63e5)
![Ejemplo ejecucion menu 2](https://github.com/rmelgo/scripts-menus-unix/assets/145989723/096b6ddc-86ae-40d6-be77-1fa83c1c3330)
