#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas/lista.h"
#include "pilas/pila.h"
#include "colas/cola.h"

int purga(Lista *l);


int
main(void)
{
    Lista miListaA,miListaB;
	Pila miPila;
	Cola miCola;
    tipoPosicion p;
    int i;
    tipoElemento v[]={45,32,67,90,25,45,50,60,32,50};
    int n =sizeof(v)/sizeof(tipoElemento);

    printf("Creando listaA vacía: %d\n", creaVacia(&miListaA));

    p = primero(&miListaA);
    for (i = 0; i < n; i++) {
        inserta(v[i],p,&miListaA);
        p = siguiente(p,&miListaA);
    }
    imprime(&miListaA);
    printf("Eliminando repetidos \n");
    purga(&miListaA);
    imprime(&miListaA);

    printf("Creando listaB vacía: %d\n", creaVacia(&miListaB));

    for (i = n-1; i >= 0; i--) {
        inserta(v[i],fin(&miListaB),&miListaB);
    }
    imprime(&miListaB);
    
	
	printf("\nAhora concateno: (%d)\n", concatena(&miListaA, &miListaB));
	imprime(&miListaA);
	imprime(&miListaB);
	
	
    anula(&miListaA);
    destruye(&miListaA);
    
    anula(&miListaB);
    destruye(&miListaB);
	
	printf("\n\nAhora con la pila: \n");
    printf("Creando la pila vacía: %d\n", pilaCreaVacia(&miPila));
    for (i = 0; i < 10; i++) {
        pilaInserta(&miPila, i);
    }
    
	while(!pilaVacia(&miPila)){
		printf("Extracción número: %d -> %d\n", i--, pilaSuprime(&miPila));
	}
	
	printf("\n\nAhora con la cola: \n"); //se ha realizado otra implemtacion para colas
    printf("Creando la cola vacía: %d\n", colaCreaVacia(&miCola));
    for (i = 0; i < 10; i++) {
        colaInserta(&miCola, i);
    }
    
	while(!colaVacia(&miCola)){
		printf("Extracción número: %d -> %d\n", i--, colaSuprime(&miCola));
	}
	
    
    return 0;
}

int
purga(Lista *l)
{
    tipoPosicion act, sig;
    
    act = primero(l);
    while (act != fin(l)) {
        sig = siguiente(act,l);
        while (sig != fin(l)) {
            if (recupera(act,l) == recupera(sig,l))
                suprime(sig, l);
            else
                sig = siguiente(sig,l);
        }
        act = siguiente(act,l);
    }
    return 0;
}


