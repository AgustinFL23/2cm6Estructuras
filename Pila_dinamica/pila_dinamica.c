/*
IMPLEMENTACIONES DE LA LIBRERIA DE LA PILA DINÁMICA (pila_din.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Noviembre 2022
VERSIÓN: 1.8

DESCRIPCIÓN: Pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa. En este caso la memoria 
no queda fija durante la compilación.

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc pila_din.c -c
*/

//LIBRERAS
#include <stdlib.h>
#include <stdio.h>
#include "pila_dinamica.h"

/*
Inicializar pila (Initialize): recibe<- pila (s); 
Initialize(s);
Efecto: Recibe una pila y la inicializa para su trabajo normal.
*/
void Initialize(pila *s)
{
	s->size=0;
	(*s).tope=NULL;
	return;
}

/*
Empilar (Push): recibe<- pila (s); recibe<- elemento (e) 
Push(s,e);
Efecto: Recibe la pila y aumenta su tamaño, poniendo el elemento en la cima de la pila.
*/
void Push(pila *s,elemento e)
{
	nodo *aux;
	
	aux=malloc(sizeof(nodo));
	
	if(aux!=NULL)
	{
		s->size++;
		aux->e=e;
		aux->abajo=s->tope;
		s->tope=aux;
	}
	else //Desbordamiento de pila
	{
		printf("\nERROR Push(s,e):\"Desbordamiento de pila\"");
		exit(1);	
	}
	return;
}

/*
Desempilar (Pop): recibe<- pila (s); retorna -> elemento
e=Pop(s);
Efecto: Recibe la pila, remueve el elemento tope y lo retorna.
Excepción: si la pila esta vacía, produce error.
*/
elemento Pop(pila *s)
{
	elemento r;
	nodo* aux;
	if(s->tope!=NULL)
	{
		r=s->tope->e;
		aux=s->tope;
		s->tope=s->tope->abajo; //s->tope=aux->abajo
		free(aux);
		s->size--;
	}
	else //Subdesbordamiento de la pila
	{
		printf("\nERROR e=Pop(s):\"Subdesbordamiento de pila\"");
		exit(1);			
	}
	
	return r;
}

/*
Es vacía (Empty): recibe<- pila (s); retorna -> boolean
b=Empty(s);
Efecto: Recibe una pila y devuelve true si esta vacía y false en caso contrario.
*/
int Empty(pila *s)
{
	int r;
	if(s->tope!=NULL)
		r=FALSE;
	else
		r=TRUE;
	
	return r;
}


/*
Tope pila (Top): recibe<- pila (s); retorna -> elemento
e=Top(s);
Efecto: Devuelve el elemento cima de la pila.
Excepción: si la pila esta vacía produce error
*/
elemento Top(pila *s)
{
	elemento r;
	if(s->tope!=NULL)
	{
		r=s->tope->e;
	}
	else //Subdesbordamiento de la pila
	{
		printf("\nERROR e=Top(s):\"Subdesbordamiento de pila\"");
		exit(1);			
	}
	
	return r;
}


/*
Tamaño pila (size): recibe<- pila (s); retorna -> tamaño de la pila (entero)
n=size(s);
Efecto: Devuelve el número de elementos que contiene la pila (Altura de la pila).
*/
int Size(pila *s)
{
	int r=s->size;
	/*int r=0;
	nodo *aux;
	aux=s->tope;
	while(aux!=NULL)
	{
		r++;
		aux=aux->abajo;
	}
*/
	return r;
}

/*
Eliminar pila (Destroy): recibe<- pila (s)
Destroy(s);
Efecto: Recibe una pila y la libera completamente
*/
void Destroy(pila *s)
{
	nodo *aux;
	if(s->tope!=NULL)
	{
		do
		{
			aux=s->tope->abajo;
			free(s->tope);
			s->tope=aux;	
		}while(aux!=NULL);
	}
	s->size=0;
	return;
}
