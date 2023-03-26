#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

void QuickSort (int *A, int p, int r);
int Pivot (int *A, int p, int r);
void Inter (int *A, int i, int j);

int main(int argc, char* argv[]) {
    clock_t t_inicio, t_final;
	double t_intervalo;
	
	int n,i;
	
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
    QuickSort(A, 0, n);
	t_final = clock();
	
	
    printf("Arreglo ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d \n", A[i]);
    }
    printf("\n");
    
    
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
	printf("\n\nTiempo medido: %.8f segundos.\n \n", t_intervalo);
    return 0;
}

void QuickSort (int *A, int p, int r){
	int j;
	if (p < r){
		j = Pivot(A, p, r);
		QuickSort(A, p, j-1);
		QuickSort(A, j+1, r);
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
