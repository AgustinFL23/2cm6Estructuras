#include<stdio.h>
#include <stdlib.h>
/*
void leer_a(int [], int); Recibe: Arreglo, tamano del arreglo; No hay retorno de valor explicito; 
Obs: Recorre cada posicion del arreglo y hace 
una lectura de cada valor. */
void leer_arreglo(int [], int);

/*
void imp_a(int [],int); Recibe: Arreglo, tamano del arreglo; No hay retorno de valor explicito; 
Obs: Recorre cada posicion del arreglo y hace 
una impresion de cada valor con saltos de linea. */
void imp_array(int [],int);

/*
void Burbuja(int [], int); Recibe: Arreglo, tamaño del arreglo; No hay retorno de valor explicito; 
Obs: Recorre todo el arreglo (n-1) veces, en cada iteracion compara a pares el elemento en posicion i
y el elemento (i+1) hasta ordenar todo el arreglo .*/
void Burbuja(int [], int);
int main(){
	
	int n;
	scanf("%d",&n);
	int *A;
	A = malloc(n*sizeof(int));
	if(!A)
		exit(1);
	leer_arreglo(A,n);
	printf("Array original: ");
	imp_array(A,n);
	printf("Array ordenado: ");
	Burbuja(A,n);
	imp_array(A,n);
	
	return 0;
}

void leer_arreglo(int arr[], int longitud) {
    int i;
    for (i = 0; i < longitud; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void imp_array(int arr[], int longitud) {
    int i;
    for (i = 0; i < longitud; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Burbuja(int A[], int n){
	int i,j,temp;
	//Recorrerá todo el arreglo. Ayuda a que los elementos más grandes se coloquen en las ultimas posiciones. 
	for(i=0;i<n-1;i++)
		//Recorrerá el arreglo, pero por cada iteración, quitará una posición por recorrer (así evita comparar los elementos más grandes ya ordenados).
		for(j=0;j<(n-1)-i;j++)
			if(A[j]>A[j+1]){
				//Este proceso intercambia los valores del arreglo. 
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
}
