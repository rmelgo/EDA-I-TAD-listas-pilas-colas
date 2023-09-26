#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"



int pilaCreaVacia(Pila *p)
{
    *p = NULL;
    return 0;
}

int pilaVacia(Pila *p)
{
   if (*p == NULL) {
       return 1;
   }
   else {
       return 0;
   }    
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
    tipoCelda * nuevo;
    nuevo = (tipoCelda *)malloc(sizeof(tipoCelda));
    nuevo->elemento = elemento;
    if (nuevo == NULL) {
        return -1;
    }
    nuevo->sig = *p;
    *p = nuevo;
    return 0;
}

tipoElemento pilaSuprime(Pila *p)
{
    tipoElemento elemento;
    tipoCelda * suprimir;
    if (pilaVacia(p) == 1) {
        return 0;
    }
    else {
        suprimir = *p;
        elemento = suprimir->elemento;
        *p = suprimir->sig;
        free(suprimir);
        return elemento;
    }
}
