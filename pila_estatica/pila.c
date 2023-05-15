#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define TRUE 1
#define FALSE 0
#define TAM_MAX 1000


boolean Empty(pila S)
{
    if (S.tope == -1)
        return TRUE;
    return FALSE;
}

void push(pila *S, elemento val)
{
    if (S->tope < TAM_MAX - 1) {
        S->tope++;
        S->lista[S->tope] = val;
    } else {
        printf("\nERROR Push(s,e):Desbordamiento de pila");
        exit(1);
    }
}

elemento pop(pila *S)
{
    elemento aux;
    if (Empty(*S)) {
        printf("La pila ya esta vacia");
        aux.tipo = ' ';
    } else {
        aux = S->lista[S->tope];
        S->tope--;
    }
    return aux;
}

elemento Top(pila *S)
{
    if (Empty(*S)) {
        printf("La pila ya esta vacia");
        elemento aux;
        aux.tipo = ' ';
        return aux;
    } else {
        return S->lista[S->tope];
    }
}