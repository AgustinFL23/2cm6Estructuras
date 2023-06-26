#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Crear palabra
Regresa una palabra completamente con sus campos llenos
*/
palabra crear_palabra(){
	fflush(stdin);
	palabra nueva;
	nueva = malloc(sizeof(s)*1);
	printf("Ingresa la palabra:\n");
	fgets(nueva->palabra,30,stdin);//funcion para leer maximo 29 y guardar en nueva->palabra
	printf("Ingrese la descripcion: \n");
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

void modificar_descripcion(nodo* raiz, char* palabra_buscar, char* nueva_descripcion) {
    palabra p = buscar_palabra(raiz, palabra_buscar);
    if (p != NULL) {
        strncpy(p->descripcion, nueva_descripcion, sizeof(p->descripcion));
        printf("La descripción de la palabra '%s' ha sido modificada.\n", palabra_buscar);
    } else {
        printf("La palabra '%s' no se encontró en el árbol.\n", palabra_buscar);
    }
}

int obtener_altura(nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int altura_izq = obtener_altura(raiz->hijo_izq);
        int altura_der = obtener_altura(raiz->hijo_der);
        return 1 + (altura_izq > altura_der ? altura_izq : altura_der);
    }
}

int contar_palabras(nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int cantidad_izq = contar_palabras(raiz->hijo_izq);
        int cantidad_der = contar_palabras(raiz->hijo_der);
        return 1 + cantidad_izq + cantidad_der;
    }
}

void buscar_palabra_profunda(nodo* raiz, palabra* palabra_profunda, int orden_actual, int* orden_max) {
    if (raiz != NULL) {
        if (orden_actual > *orden_max) {
            *orden_max = orden_actual;
            *palabra_profunda = raiz->palabra;
        }
        buscar_palabra_profunda(raiz->hijo_izq, palabra_profunda, orden_actual + 1, orden_max);
        buscar_palabra_profunda(raiz->hijo_der, palabra_profunda, orden_actual + 1, orden_max);
    }
}

void mostrar_informacion_arbol(nodo* raiz) {
    int altura = obtener_altura(raiz);
    int cantidad_palabras = contar_palabras(raiz);
    palabra palabra_profunda = NULL;
    int orden_max = 0;

    buscar_palabra_profunda(raiz, &palabra_profunda, 1, &orden_max);

    printf("Altura del árbol: %d\n", altura);
    printf("Cantidad de palabras: %d\n", cantidad_palabras);
    if (palabra_profunda != NULL) {
        printf("Palabra más profunda: %s (Orden de búsqueda máximo: %d)\n", palabra_profunda->palabra, orden_max);
    } else {
        printf("No hay palabras en el árbol.\n");
    }
}
