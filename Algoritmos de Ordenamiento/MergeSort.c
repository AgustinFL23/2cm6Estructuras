#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

/*
void MergeSort(int *, int, int); Recibe: Direccion de memoria a la que apunta el arreglo, 
posicion inicial del array(P=0) y posicion final del array (r=n-1); No hay retorno de valor explicito; 
Obs: Divide al arreglo en dos, la primera llamada recursiva ordena (con la llamada de merge) 
desde la posicion inicial hasta el aproximado a la mitad del arreglo, divide el arreglo en subarreglos 
hasta llegar al minimo de elementos en un subarreglo (elementos = 1). 
La segunda llamada recursiva repite el procedimiento de la primera llamda recursiva, pero esta ordena
el arreglo de la mitad hasta la posicion final. */
void MergeSort (int *A, int p, int r);
	
/*
void Merge(int [], int, int, int); Recibe: Direccion de memoria a la que apunta el arreglo, 
posicion inicial del array(p), mitad definida en la funcion MergeSort llamada q y posicion final 
del array (r); No hay retorno de valor explicito; 
Obs: Declara un arreglo auxiliar con memria dinamica, posteriormente mezcla dos subarreglos ordenados
en uno solo, para este procedimiento de mezcla, compara los elementos de ambos subarreglos y le asigna
valores al arreglo auxiliar, hace una nueva comparacion en el arreglo auxiliar para asignarle los valores 
menores en el arreglo original y ordenar la mezcla de un arreglo formado por dos subarreglos ya ordenados 
finalmente. Este proceso se repite no de manera recursiva directamente, pero cada que MergeSort hace una recursion
esta funcion es llamada indirectamente para mezlcar dos subarreglos ordenados.*/
void Merge (int *A, int p, int q, int r);


int main(int argc, char* argv[]) {
	clock_t t_inicio, t_final;
	int n,i;
	double t_intervalo;
	
	if (argc!=2) 
	{
		printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	
	n=atoi(argv[1]);
	
    int *A;
	A = malloc (n* sizeof(int));
	if (!A)
		exit(1);
		
	for (i = 0; i < n; i++) 
        scanf("%d", &A[i]);
	
	t_inicio = clock();
    MergeSort(A, 0, n-1);
	t_final = clock();
	
	t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
	
    printf("Arreglo ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d \n", A[i]);
    }
    printf("\n");
    
	printf("\n\nTiempo medido: %.8f segundos.\n\n", t_intervalo);
    return 0;
}

    
    
void MergeSort(int *A, int p, int r){
	int q, s;
	//Paso recursivo del MergeSort para para las llamadas recursivas. 
	if (p < r){
		q = (int) floor((p+r)/2); //Representa la mitad aproximada del arreglo.
		//Llamadas recursivas hasta tener un subarreglo de 1 elemento.
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		//Mezcla de dos subarreglos ya ordenados
		Merge(A, p, q, r);
	}
}

void Merge(int *A, int p, int q, int r) {
    int l, i, j;
    l = r - p + 1; i = p; j = q + 1;
    //Arreglo auxiliar con memoria dinamica
	int *C;
	C = malloc (l* sizeof(int));
	if (!C)
		exit(1);
    int k;
    //Se itera la variable que recorre al arreglo auxiliar hasta que sea menor al final-inicio+1.
    for (k = 0; k < l; k++) {
    //En estas condiciones se verficia que elementos son menores para asignarlos al arreglo auxiliar.
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
    //Devuelve los valores ya almacenados en c, al arreglo a de forma ordenada.
    for (i = 0; i < l; i++) {
        A[k] = C[i];
        k++;
    }
}
