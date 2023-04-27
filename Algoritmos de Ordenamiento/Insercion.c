#include<stdio.h>
#include<stdlib.h>
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
void Insercion(int [],int); Recibe: Arreglo, tamano del arreglo; No hay retorno de valor explicito
Obs: Guarda en una varibale temporal el valor minimo empezando a comparar desde el primer elemento
en la posicion 0, posteriormente recorre todo el arreglo haciendo comparaciones con el subarreglo formado
por los elementos ya ordenados e inserta el valor en su posicion ordenada, cuando el valor no encuentra 
mayores que el mismo.*/
void Insercion(int [],int);
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
	Insercion(A,n);
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

void Insercion(int A[],int n){
	int i,j,temp;
	for(i=0;i<=n-1;i++){ //Recorremos elementos del arreglo y almacenamos el valor de la posicion i en temp.
		j=i;
		temp=A[i];
		while((j>0) && (temp<A[j-1])){ //Desplaza los elementos mayores al elemento de posicion j, a la derecha.
			A[j]=A[j-1]; //Coloca el valor mayor en la posicion j
			j--; //Resta una posicion a j para el paso siguiente.
		}
		A[j] = temp; //Coloca el valor que estaba en la posicion j en el de la posicion j-1.
	}
}
