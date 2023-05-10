#define TRUE 1
#include <stdio.h>
#include<stdlib.h>
#define FALSE 0
#define MAX_EXPRE 1000

typedef char boolean;

//Esta estructura nos permite guardar el elemento deseado

//estructura de nuestra pila
typedef struct pila{
    int tope;
    char lista[1000];
} pila;


void inicializacion(pila *S); //inicializa la pila
void push(pila *S, char eval); //Coloca elementos en la pila
int pop(pila *S); //Quita elemtos de la pila
boolean Empty(pila S); //Comprueba que si la pila esta vacia
int Top(pila *S); //Devuelve el elemento de la cima de la pila

//Por referencia (), hacemos una modificacion dentro de la pila
//por apuntador, solamente ocupamos los elementos que tienen sin mosificar la pila

boolean Empty(pila S) //Comprueba si nuestra pila esta vacia
{
    if(S.tope == -1)//si nuestra pila esta vacia es verdadero
        return 1;
    return 0;
}

void push(pila *S, char val) //ingresamos elementos en nuestra pila
{
    if (S->tope<MAX_EXPRE) //-1
    {
        S->lista[S->tope] = val; //Nuestra pila se dirije a nuestra lista en el elemeto[ en el primero lugar (0) ], le asignamos el lugar al elemento 
        S->tope++; //tope +1, esto para evitar sobreescribir elementos
    }
    else
    {
        printf("\nERROR Push(s,e):\"Desbordamiento de pila\"");
		exit(1);	
    }    
}

int pop(pila *S) //Eliminar elementos de nuestra lista y retorna el ultimo elemento guardado en la pila
{
        int aux;
        aux = S->lista[S->tope-1]; //Nuestro auxiliar se dirige a la posicion donde se encuentra el ultimo elemento guardado
        S->tope--;
        return aux;
    
}

int Top(pila *S) //solo nos devuelve el elemento que esta en el tope de nuestra pila
{
    if (Empty(*S)==1)
    {
        printf("La pila ya esta vacia");
        return -1;
    }
    else
    {
        return S->lista[S->tope-1]; //retornamos el ultimo valor ingresado
    }
}