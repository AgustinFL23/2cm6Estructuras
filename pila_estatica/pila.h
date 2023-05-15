#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define TAM_MAX 1000

typedef char boolean;

typedef struct elemento {
    int tipo;
    union {
        int entero;
        float flotante;
        char caracter;
    } dato;
} elemento;

typedef struct pila {
    int tope;
    elemento lista[TAM_MAX];
} pila;

void push(pila *S, elemento val);
elemento pop(pila *S);
boolean Empty(pila S);
elemento Top(pila *S);