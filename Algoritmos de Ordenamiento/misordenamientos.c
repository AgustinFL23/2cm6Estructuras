#include <stdio.h>
#include <math.h>
void Burbuja(int *A, int n);
void Insercion(int *A,int n);
void Quick(int *A,int p,int r);
void Seleccion(int *A,int n);
void MergeSort(int *A,int p,int r);
void Shell(int *A,int n);

//DEFINICION DE LA FUNCION BURBUJA
void Burbuja(int *A, int n){
	int i,j,temp;
	//Recorrera todo el arreglo. Ayuda a que los elementos mas grandes se coloquen en las ultimas posiciones. 
	for(i=0;i<n-1;i++)
		//Recorrera el arreglo, pero por cada iteracion, quitara una posicion por recorrer (asi evita comparar los elementos mas grandes ya ordenados).
		for(j=0;j<(n-1)-i;j++)
			if(A[j]>A[j+1]){
				//Este proceso intercambia los valores del arreglo. 
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
}
//FIN DE ORDENAMIENTO BURBUJA


//DEFINICION DE LA FUNCION INSERCION
void Insercion(int *A,int n){
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
//FIN DE ORDENAMIENTO INSERCION


//DEFINICION DE LA FUNCION SELECCION
void Seleccion(int *A,int n){
	
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
//FIN DE ORDENAMIENTO SELECCION


//DEFINICION DE LA FUNCION QUICKSORT
void Quick(int *A,int p,int r){
		int j;
		if (p < r){
		j = Pivot(A, p, r);
		Quick(A, p, j-1);
		Quick(A, j+1, r);
	}
}

int Pivot (int *A, int p, int r){
	int piv, i, j;
	piv = A[p]; i=p; j=r;
	while (i<j){
		while(A[i]<= piv && i<r)
			i++;
		while(A[j]>piv)
			j--;
		if (i<j)
			Inter(A, i, j);
	}
	Inter(A, p, j);
	return j;
}
void Inter(int *A, int i, int j) {
    int temp;
    temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}
//FIN DE ORDENAMIENTO QUICKSORT


//DEFINICION DE LA FUNCION SHELL
void Shell(int *A,int n){
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
//FIN DE ORDENAMIENTO SHELL


//DEFINICION DE LA FUNCION MERGESORT
void MergeSort(int *A, int p, int r){
	int q;
	if (p < r){
		q = (int) floor((p+r)/2);
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Merge(A, p, q, r);
	}
}

void Merge(int *A, int p, int q, int r) {
    int l, i, j;
    l = r - p + 1; 
	i = p; 
	j = q + 1;
	
    int *C;
	C = malloc (l* sizeof(int));
	if (!C)
		exit(1);

    int k;
    for (k = 0; k < l; k++) {
        if (i <= q && j <= r) {
            if (A[i] < A[j]) {
                C[k] = A[i];
                i++;
            } else {
                C[k] = A[j];
                j++;
            }
        } else if (i <= q) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = A[j];
            j++;
        }
    }
    k = p;
    for (i = 0; i < l; i++) {
        A[k] = C[i];
        k++;
    }
}
//FIN DE ORDENAMIENTO MERGESORT
