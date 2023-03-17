#include<stdio.h>
#include<stdlib.h>
void leer_arreglo(int [], int);
void imp_array(int [],int);
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
