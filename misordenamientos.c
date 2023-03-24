#include <stdio.h>
void Burbuja(int *A, int n);
void Insercion(int *A,int n);
void QuickSort(int *A,int p,int r);
void Seleccion(int *A,int n);
void MergeSort(int *A,int p,int r);

void Burbuja(int *A, int n){
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