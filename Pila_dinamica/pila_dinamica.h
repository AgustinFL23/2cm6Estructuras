/*
LIBRERIA: Cabecera de la PILA DINÁMICA
AUTOR: Edgardo Adrián Franco Martínez (C) Noviembre 2022
VERSIÓN: 1.8

DESCRIPCIÓN: Pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa. En este caso la memoria 
no queda fija durante la compilación y se logrará este dinamismo 
a travez del modelo "nodo" el cuál se reservará dinamicamente logrando 
modelar una pila.
*/

//DEFINICIONES DE CONSTANTES
#define TRUE 1
#define FALSE 0

typedef struct elemento {
    //Lo que el usuario guste
    int tipo;
    union {
        int entero;
        float flotante;
        char caracter;
    } dato;
} elemento;

//Definir un nodo que será utilizado para almacenar una posición de la pila (Nodo), lo que incluira a un elemento y a un apuntador al nodo de debajo
typedef struct nodo
{
	elemento e;
	struct nodo *abajo;	
} nodo;

//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento" y una varieble para almacenar su tamaño)
typedef struct pila
{
	nodo * tope;
	int size;
} pila;

/*
Inicializar pila (Initialize): recibe<- pila (S); 
Initialize(S);
Efecto: Recibe una pila y la inicializa para su trabajo normal.
*/
void Initialize(pila *S);

/*
Empilar (Push): recibe<- pila (S); recibe<- elemento (e) 
Push(S,e);
Efecto: Recibe la pila y aumenta su tamaño, poniendo el elemento en la cima de la pila.
*/
void Push(pila *S,elemento e);

/*
Desempilar (Pop): recibe<- pila (S); retorna -> elemento
e=Pop(S);
Efecto: Recibe la pila, remueve el elemento tope y lo retorna.
Excepción: Si la pila esta vacía, produce error.
*/
elemento Pop(pila *S);

/*
Es vacía (Empty): recibe<- pila (S); retorna -> boolean
b=Empty(S);
Efecto: Recibe una pila y devuelve true si esta vacía y false en caso contrario.
*/
int Empty(pila *S);


/*
Tope pila (Top): recibe<- pila (S); retorna -> elemento
e=Top(S);
Efecto: Devuelve el elemento cima de la pila.
Excepción: Si la pila esta vacía produce error
*/
elemento Top(pila *S);


/*
Tamaño pila (Size): recibe<- pila (S); retorna -> tamaño de la pila (entero)
n=Size(S);
Efecto: Devuelve el número de elementos que contiene la pila (Altura de la pila).
*/
int Size(pila *S);

/*
Eliminar pila (Destroy): recibe<- pila (S)
Destroy(S);
Efecto: Recibe una pila y la libera completamente
*/
void Destroy(pila *S);
