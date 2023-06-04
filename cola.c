#include "cola.h"

void Initialize(cola* c)
{
    c->num_elem = 0;
    c->frente = NULL;
    c->final = NULL;
}

void Queue(cola* c, elemento e)
{
    nodo* aux;
    aux = malloc(sizeof(nodo));
    if (aux == NULL) {
        printf("ERROR: Queue (c,e) desbordamiento de cola");
        exit(1);
    }
    aux->e = e;
    aux->siguiente = NULL;
    if (c->num_elem > 0)
        c->final->siguiente = aux;
    c->final = aux;
    c->num_elem++;
    if (c->num_elem == 1)
        c->frente = c->final;
}

elemento Dequeue(cola* c)
{
    nodo* aux;
    elemento e; // Elemento a retornar 
    if (c->num_elem == 0) {
        printf("ERROR: Dequeue (c) subdesbordamiento de cola");
        exit(1);
    } else {
        e = c->frente->e;
        aux = c->frente;
        c->frente = c->frente->siguiente;
        free(aux);
        c->num_elem--;
        if (c->num_elem == 0)
            c->final = NULL;
    }
    // Retornar al elemento
    return e;
}

int Empty(cola* c)
{
    return (c->num_elem == 0) ? 1 : 0;
}

elemento Front(cola* c)
{
    elemento e;
    e = c->frente->e;
    return e;
}

elemento Final(cola* c)
{
    elemento e;
    e = c->final->e;
    return e;
}

int Size(cola* c)
{
    return c->num_elem;
}

elemento Element(cola* c, int i)
{
    elemento r;
    nodo* aux;
    int j;
    if (i > c->num_elem || i <= 0) {
        printf("ERROR: Element(c,i) i se encuentra fuera del rango");
        exit(1);
    }
    aux = c->frente;
    for (j = 1; j < i; j++) {
        aux = aux->siguiente;
    }
    r = aux->e;
    return r;
}

void Destroy(cola* c)
{
    nodo* aux;
    aux = c->frente;
    while (aux != NULL) {
        c->frente = aux->siguiente;
        free(aux);
        aux = c->frente;
    }
    c->num_elem = 0;
    c->frente = NULL;
    c->final = NULL;
}

//Función para mover el cursor de escritura de pantalla, simulación de la función gotoxy() que se tenia en borland 3.0 en la libreria conio.h
void MoverCursor( int x, int y ) 
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y }; 
	SetConsoleCursorPosition( hStdout, position );
	return;
};

//Función para esperar un tiempo en milisegundos, simulación de la función delay() que se tenia en borland 3.0 en la libreria conio.h
void EsperarMiliSeg(int t)
{
	Sleep(t);
	return;
}

//Función para borrar la pantalla de la consola, simulación de la función clrscr() que se tenia en borland 3.0 en la libreria conio.h
void BorrarPantalla(void)
{
	system("cls");
	return;
}
