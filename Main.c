#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "misordenamientos.h"

int main (int arg, char * args[]){
//Declarion de las variables
int n, inicio[6], Fin[6],aux;
int *a1,*a2,*a3,*a4,*a5, *a6;

//Arreglos dinamicos
n=atoi(args[1]);	//convertimos una cadena de texto en un entero en la pisicion 1 de args "n"
a1=malloc(sizeof(int)*n);
a2=malloc(sizeof(int)*n);
a3=malloc(sizeof(int)*n);
a4=malloc(sizeof(int)*n);
a5=malloc(sizeof(int)*n);
a6=malloc(sizeof(int)*n);

if(a1==null || a2==null || a3==null || a4==null || a5==null || a6==null)	//En caso que algun arreglo apunta a "null" inmediatamente matamos el programa
	exit (1);	
//fin de los arreglos dinamicos

//Asignacion de parametros
int i;
for(i=0;i<n;i++){
scanf("%d",&aux);
a1[i]=aux;
a2[i]=aux; 
a3[i]=aux;
a4[i]=aux;
a5[i]=aux;
a6[i]=aux;
}


//Compilacion de de Burbuja 
inicio[0]=clock();
Burbuja (a1,n);
Fin[0]=clock();
//Fin de la compilacion de Burbuja


//Compilacion de Insercion
inicio[1]=clock();
Insercion(a2,n);
Fin[1]=clock();
//Fin de la compilacion de Insercion


//Compilacion de Seleccion
inicio[2]=clock();
Seleccion (a3, n);
Fin[2]=clock();
//Fin de la compilacion de Seleccion


//Compilacion de Shell
inicio[3]=clock();
Shell(a4, n);
Fin[3]=clock();
//Fin de la compilacion de Shell


//Compilacion de MergeSort
inicio[4]=clock();
MergeSort (a5, 0, n-1);
Fin[4]=clock();
//Fin de la compilacion de MergSort


//Compilacion de Quicksort
inicio[5]=clock();
Quick(a6, 0, n-1);
Fin[5]=clock();
//Fin de la compilacion de Quicksort


	printf("%d,",n);//Imprime los "n´s numeros"
	
	//Imprime la cantidad de tiempo que se tardo cada ordenmaiento 
for(int i=0;i<6;i++){	//i < n, por los irdenamientos que tenemos registrados en este caso tenemos 6
		
		//Este apartado dividimos los n^2 de los log(n) para imprimir los tiempos en diferente formato
		//if(i<3)
		printf("%.10f segundos, ", (double)(Fin[i]-inicio[i])/CLOCKS_PER_SEC); //imprime tiempos con 10 decimales
	//	else{
	//		printf("%e segundos, ", (double)(Fin[i]-inicio[i])/CLOCKS_PER_SEC);//imprime los tiempos en formato exponencial
		
	//	}
	
	}
		printf("\n");
}
