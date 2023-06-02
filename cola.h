#include<stdio.h>
#include<stdlib.h>

#include <string.h>
#define MAX_ELEMENT 1000
#define TRUE	1
#define FALSE	0




typedef unsigned char boolean;


typedef struct elemento
{
	int n;
} elemento;


typedef struct nodo
{
	elemento e;
	struct nodo *siguiente;
}nodo;


typedef struct {
    elemento elementos[MAX_ELEMENT];
    int frente;
    int final;
} cola;

void Initialize(cola * c);			//Inicializar cola (Initialize): Recibe una cola y la inicializa para su trabajo normal.
void Queue(cola * c, elemento e);	//Encolar (Queue): Recibe una cola y agrega un elemento al final de ella. 
elemento Dequeue(cola * c);			//Desencolar (Dequeue): Recibe una cola y remueve el elemento del frente retornándolo.
int Empty(cola * c);			//Es vacía (Empty): Recibe la cola y devuelve verdadero si esta esta vacía.
elemento Front(cola * c);			//Frente (Front): Recibe una cola y retorna el elemento del frente.	
elemento Final(cola * c);			//Final (Final): Recibe una cola y retorna el elemento del final.
elemento Element(cola *c, int i); 	// Recibe una cola y un número de elemento de 1 al tamaño de la cola y retorna el elemento de esa posición.
int Size(cola *c);					//Tamaño (Size): Retorna el tamaño de la cola 	
elemento Element(cola * c, int i);	//Recibe una cola y un número de elemento de 1 al tamaño de la cola y retorna el elemento de esa posición
void Destroy(cola * c);				//Eliminar cola (Destroy): Recibe una cola y la libera completamente.



void Initialize(cola* c) {
    c->frente = 0;
    c->final = -1;
}

// Función para verificar si la cola está vacía
int Empty(cola* c) {
    return c->frente > c->final;
}

// Función para verificar si la cola está llena
int Full(cola* c) {
    return c->final == MAX_ELEMENT - 1;
}

// Función para encolar un elemento
void Queue(cola* c, elemento e) {
    if (Full(c)) {
        printf("Error: La cola está llena.\n");
        return;
    }

    c->final++;
    c->elementos[c->final] = e;
}

// Función para desencolar un elemento
elemento Dequeue(cola* c) {
    if (Empty(c)) {
        printf("Error: La cola está vacía.\n");
        elemento e;
        e.n = 0;  // Valor por defecto en caso de error
        return e;
    }

    elemento e = c->elementos[c->frente];
    c->frente++;
    return e;
}

// Función para obtener el tamaño de la cola
int Size(cola* c) {
    return c->final - c->frente + 1;
}