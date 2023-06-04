#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#define TRUE	1
#define FALSE	0
#define TRUE	1
#define FALSE	0

typedef unsigned char boolean;
typedef struct elemento {
    int n;
} elemento;

typedef struct nodo {
    elemento e;
    struct nodo* siguiente;
} nodo;

typedef struct cola {
    int num_elem;
    nodo* frente;
    nodo* final;
} cola;

void Initialize(cola* c);
void Queue(cola* c, elemento e);
elemento Dequeue(cola* c);
int Empty(cola* c);
elemento Front(cola* c);
elemento Final(cola* c);
int Size(cola* c);
elemento Element(cola* c, int i);
void Destroy(cola* c);
void MoverCursor( int x, int y ); 	//Función para mover el cursor de escritura de pantalla, simulación de la función gotoxy() que se tenia en borland 3.0 en la libreria conio.h
void EsperarMiliSeg(int t);			//Función para esperar un tiempo en milisegundos, simulación de la función delay() que se tenia en borland 3.0 en la libreria conio.h
void BorrarPantalla(void);
