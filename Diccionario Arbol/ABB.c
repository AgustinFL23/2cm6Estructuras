#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
/*
Crear palabra
Regresa una palabra completamente con sus campos llenos
*/
palabra crear_palabra(){
	palabra nueva;
	nueva = malloc(sizeof(s)*1);
	fgets(nueva->palabra,30,stdin);//funcion para leer maximo 29 y guardar en nueva->palabra
	fgets(nueva->descripcion,200,stdin);//funcion para leer maximmo 199 y guardar en nueva->descripcion
	return nueva;
}

void Inicializar(nodo* nuevo){
	nuevo->hijo_izq=NULL;
	nuevo->hijo_der=NULL;
	nuevo->palabra=NULL;
}

void a_p_r(nodo* raiz, palabra aniadir){
	if (strcmp(raiz->palabra->palabra,aniadir->palabra)>0)
	{
		if (raiz->hijo_izq!=NULL)
			a_p_r(raiz->hijo_izq,aniadir);
		else{
			nodo* nuevo;
			nuevo=malloc(sizeof(nodo)*1);
			Inicializar(nuevo);
			nuevo->palabra=aniadir;
			raiz->hijo_izq=nuevo;
		}
	}
	else{
		if (raiz->hijo_der!=NULL)
			a_p_r(raiz->hijo_der,aniadir);
		else{
			nodo* nuevo;
			nuevo=malloc(sizeof(nodo)*1);
			Inicializar(nuevo);
			nuevo->palabra=aniadir;
			raiz->hijo_der=nuevo;
		}	
	}
}

void aniadir_palabra(nodo* raiz){
	palabra nueva=crear_palabra();
	if(raiz->palabra==NULL){
		raiz->palabra=nueva;
	}
	else if(buscar_palabra(raiz,nueva->palabra)!=NULL)
		printf("La palabra ya ha sido añadida antes\n");
	else{
		a_p_r(raiz,nueva);
	}
}

palabra buscar_palabra(nodo* raiz, char* buscar){
	palabra nuevo=NULL;
	if (strcmp(raiz->palabra->palabra,buscar)==0)
		nuevo=raiz->palabra;
	else if (strcmp(raiz->palabra->palabra,buscar)>0)
	{
		if (raiz->hijo_izq!=NULL)
			nuevo=buscar_palabra(raiz->hijo_izq, buscar);
		
	}
	else{
		if (raiz->hijo_der!=NULL)
			nuevo=buscar_palabra(raiz->hijo_der, buscar);
	}
return nuevo;
}

int recorrer_arbol(nodo* raiz, int recorrido){
	switch(recorrido){
		case 1:
			printf("%s\n",raiz->palabra->palabra);
			printf("%s\n",raiz->palabra->descripcion);
			if(raiz->hijo_izq!=NULL)
				recorrer_arbol(raiz->hijo_izq,recorrido);
			if(raiz->hijo_der!=NULL)
			recorrer_arbol(raiz->hijo_der,recorrido);
		break;
		case 2:
			if(raiz->hijo_izq!=NULL)
				recorrer_arbol(raiz->hijo_izq,recorrido);
			printf("%s\n",raiz->palabra->palabra);
			printf("%s\n",raiz->palabra->descripcion);
			if(raiz->hijo_der!=NULL)
				recorrer_arbol(raiz->hijo_der,recorrido);
		break;
		case 3:
			if(raiz->hijo_izq!=NULL)
				recorrer_arbol(raiz->hijo_izq,recorrido);
			if(raiz->hijo_der!=NULL)
				recorrer_arbol(raiz->hijo_der,recorrido);
			printf("%s\n",raiz->palabra->palabra);
			printf("%s\n",raiz->palabra->descripcion);
		break;
		default:
			printf("Entrada no valida\n Introduzca 1 para realizar un recorrido pre order\n Introduzca 2 para realizar un recorrido in order\n Introduzca 3 para realizar un recorrido post order \n");
	}
}