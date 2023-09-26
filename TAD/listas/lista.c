#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"



int
creaVacia(Lista *l) //crea una lista perparada para usarse. Si el puntero de tipo lista es null devuelve -2. Si se produce un fallo en la reserva de memoria del nodo ficticio devuelve -1.
{
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int
vacia(Lista *l) //devuelve 1 si la lista esta vacia y un 0 si no lo esta. Si la lista que recibe no es valida devuelve -1
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int
destruye(Lista *l) //libera el nodo ficticio de una lista vacia y pone raiz e ultimo a null. Si la lista que recibe no es valida devuelve -1. Si la lista no etsva vacia devuelve -2
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void
imprime(Lista *l) //imprime el contenido de todos los elementos de la lista. Si la lista no ees valida no hace nada.
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
        printf("%d valores en la lista\n",posicion-1);
    }
}

tipoPosicion
anterior(tipoPosicion p, Lista *l) //devuelve la posicion del elemento anterior a p. Si p apunta al primer elemento (nodo ficticio), entonces devolvera la dirrecion del nodo ficticio.
{                                  //Si la lista no es valida o la posicion es null la funcion devuelve NULL
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}


tipoPosicion //devuelve la posicion del primer elemento de la lista (aunque la lista este vacia). Si la lista recibida no es valida devuelve null
primero(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return NULL;
    }
    else {
        return l->raiz;
    }   
}



tipoPosicion //devuelve la posicion siguiente al ultimo elemento de la lista (aunque la lista este vacia). Si la lista recibida no es valida devuelve null
fin(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return NULL;
    }
    else {
        return l->ultimo;
    }   
}




int
inserta(tipoElemento x, tipoPosicion p, Lista *l) //inserta un nuevo nodo con el elemento indicado en la posicion p. Si la lista no es valida o la posicion no es valida devuelve -1.
{
    tipoCelda *nuevo;
    nuevo = (tipoCelda *) malloc(sizeof(tipoCelda));
    if (nuevo == NULL) {
        return -2;
    }
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return -1;
    }
    else {       
        nuevo->elemento = x;
        nuevo->sig = p->sig;
        p->sig = nuevo;
        if (p == l->ultimo) {
            l->ultimo = l->ultimo->sig;
        }
        
    }              
}


int
suprime (tipoPosicion p, Lista *l) //elimina el nodo situado en la posicion p. Si la lista no es valida o la posicion no es valida devuelve -1.
{
    tipoCelda *suprimir;
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return -1;
    }
    else {   
        if (p->sig == l->ultimo) {
            l->ultimo = p;
        }
        suprimir = p->sig;   
        p->sig = suprimir->sig;
        free(suprimir);
    }                 
}



tipoPosicion
siguiente(tipoPosicion p,Lista *l) //devuelve la posicion siguiente a la posicion p. Si la lista no es valida o la posicion no es valida devuelve null.
{
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if(p == l->ultimo) {
        return fin(l);
    }
    else {
        return p->sig;
    }   
}




tipoPosicion
localiza (tipoElemento x, Lista *l) //devuelve la posicion de la celda que contenga el elemento x. Si la lista no es valida devuelve null.
{
    tipoCelda *tmp;
    if (l == NULL || l->raiz == NULL) {
        return NULL;
    }
    else {
        tmp = l->raiz;
        while (tmp->sig != NULL || tmp->elemento != x) {
           tmp = tmp->sig;
        }
	return tmp;
    }
}



tipoElemento
recupera(tipoPosicion p, Lista *l)
{
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return -1;
    } 
    else if (p == l->ultimo) {
        return -2;
    }    
    else {
        return p->sig->elemento;
    }
}


int
anula(Lista *l)
{
    tipoCelda *anterior, *suprimir;
    if (l == NULL || l->raiz == NULL) {
        return -1;
    } 
    anterior = l->raiz;
    while (anterior->sig != NULL) { //(tambien se podria haber usado un bucle con la operacion destruye
        suprimir = anterior->sig;   
        anterior->sig = suprimir->sig;
        free(suprimir);
    }      
    l->ultimo = l->raiz;
    return 0;  
}

int
concatena(Lista *lA, Lista *lB)
{
    if (lA == NULL || lA->raiz == NULL || lB == NULL || lB->raiz == NULL) {
        return -1;
    } 
    else {
        lA->ultimo->sig = lB->raiz->sig;
        lA->ultimo = lB->ultimo;
        lB->ultimo = lB->raiz;
        lB->raiz->sig = NULL;
        return 0;
    }
}



