#ifndef bandera
#define bandera
#include <stdio.h>

typedef struct palabra{
	char palabra[30];
	char descripcion[200];
}s;

typedef s* palabra;
typedef struct nodo
{
	struct nodo * hijo_izq;
	struct nodo * hijo_der;
	palabra palabra;
}nodo;

/*
Inicializar arbol
Recibe un nodo y lo devuelve para que sea tomado como un arbol vacio
*/
void Inicializar(nodo* nuevo);
/*
añadir palabra
Recibe un nodo que tomara como la raiz de su arbol, leera y creara una ejemplar de palabra
posteriormente insertar la palabra en el lugar que le corresponde 
siguiendo las reglas de un ABB (menores a la raiz a la izquierda y mayores a la derecha)
*/
void aniadir_palabra(nodo* raiz);
/*
Buscar palabra
Recibe un nodo y busca una palabra 
siguiendo las reglas de un ABB, se busca de forma recursiva y se retorna una palabra si se encuentra y un NULL sen caso contrario
*/
palabra buscar_palabra(nodo* raiz, char* palabra);

/*
Recorrer arbol
Recibe un nodo y un entero si el entero es 1 realiza un recorrido preorden del arbol
si es 2 realiza un recorrido in order 
si es 3 realiza un recorrido postorder
*/
int recorrer_arbol(nodo* raiz, int recorrido);
void modificar_descripcion(nodo* raiz, char* palabra_buscar, char* nueva_descripcion);
//void mostrar_informacion_arbol(nodo* raiz);

#include "ABB.c"
#endif
