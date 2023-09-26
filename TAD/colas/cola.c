#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c)
{
    c->frente = NULL;      
    c->fondo = NULL; 
    return 0;
}

int colaVacia(Cola *c)
{
    if (c->frente == NULL && c->fondo == NULL) {
        return 1;
    }
    else {
        return 0;
    }       
}

int colaInserta(Cola *c,tipoElemento elemento)
{
    tipoCelda *nuevo;
    nuevo = (tipoCelda *)malloc(sizeof(tipoCelda));
    if (nuevo == NULL) {
        return -1;
    }
    else {
        if (colaVacia(c) == 1) {
            c->frente = nuevo;
            nuevo->elemento = elemento;
            nuevo->sig = NULL;
            c->fondo = nuevo;
        }
        else {
            nuevo->elemento = elemento;
            nuevo->sig = NULL;
            c->fondo->sig = nuevo;
            c->fondo = nuevo;
        }
        return 0;
    }         
}

tipoElemento colaSuprime(Cola *c)
{
    tipoCelda *suprimir;
    tipoElemento elemento;
    if (colaVacia(c) == 1) {
        return 0;
    }
    if (c->frente == c->fondo) { //si solo queda un nodo (se cumple que el frente y el fondo son iguales) antes de eliminarlo ponemos fondo a null
        c->fondo = NULL;
    }
    suprimir = c->frente;
    elemento = suprimir->elemento;
    c->frente = suprimir->sig;
    free(suprimir);
    return elemento;      
}
