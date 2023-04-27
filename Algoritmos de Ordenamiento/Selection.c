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
void Selection(int [], int); Recibe: Arreglo, tamaño del arreglo; No hay retorno de valor explicito; 
Obs: En la primera iteracion recorre todo el arreglo y guarda el elemento mas chico, posteriormente
se repite el proceso (n-1) veces y en cada iteracion se busca el elementos mas chico hasta ordenar 
todos los minimos en su posicion.*/
void Seleccion(int [],int);
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
	Seleccion(A,n);
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

void Seleccion(int A[],int n){
	int k,p,i;
	for(k=0;k<n-1;k++){ //Recorrerá todo el arreglo y guardará el elemento de posicion k como el elemento mas chico antes de comparar. 
		p=k;
		//Compara el primer elemento no ordenado del elemento hasta encontrar el elemento mas chico no ordenado.
		for(i=k+1;i<n;i++)			
			if(A[i]<A[p])
				p=i;
		//Al encontrar el elemento mas chico, este se remplaza con la posicion almacenada en p.
		int temp = A[p];
		A[p] = A[k];
		A[k] = temp;
	}
		
			
}
