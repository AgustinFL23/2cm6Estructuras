#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
void leer_a(int [], int); Recibe: Arreglo, tamaño del arreglo; No hay retorno de valor explicito; 
Obs: Recorre cada posicion del arreglo y hace 
una lectura de cada valor. */
void leer_a(int [], int);
/*
void imp_a(int [],int); Recibe: Arreglo, tamaño del arreglo; No hay retorno de valor explicito; 
Obs: Recorre cada posicion del arreglo y hace 
una impresion de cada valor con saltos de linea. */
void imp_a(int [],int);
/*
void Shell(int [], int); Recibe: Arreglo, tamaño del arreglo; No hay retorno de valor explicito; 
Obs: Compara los elementos separados por un 
espacio de varias posiciones, los pasos siguientes
son con tamaños de espacio cada vez más pequeños. 
El ultimo paso del ordenamiento es un ordenamiento 
por insercion con la garantía de que todos los elementos
queden ordenados.*/
void Shell(int [],int);
int main(){
	
	//Memoria dinamica para el arreglo
	int n;
	scanf("%d",&n);
	int *A;
	A = malloc(n*sizeof(int));
	if(!A)
		exit(1);
		
	//Lectura de entradas
	leer_a(A,n);
	
	//Impresion del arreglo ordenado
	printf("Arreglo original: ");
	imp_a(A,n);
	printf("Arreglo ordenado: ");
	Shell(A,n);
	imp_a(A,n);
	
	return 0;
}

void leer_a(int A[], int n) {
    int i;
    for (i=0;i<n;i++) {
        printf("Valor %d: ",i+1);
        scanf("%d",&A[i]);
    }
}

void imp_a(int A[], int n) {
    int i;
    for (i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}

void Shell(int A[],int n){
	int k = trunc(n/2);
	int b,i,temp;
	while(k>=1){
		b=1;
		while(b!=0){
			b=0;
			for(i=k;i<=n-1;i++){
				if(A[i-k]>A[i]){
					temp=A[i];
					A[i]=A[i-k];
					A[i-k]=temp;
					b=b+1;
				}
			}
		}
		k=trunc(k/2);
	}
}
