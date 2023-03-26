#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

void MergeSort (int *A, int p, int r);
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
	if (p < r){
		q = (int) floor((p+r)/2);
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Merge(A, p, q, r);
	}
}

void Merge(int *A, int p, int q, int r) {
    int l, i, j;
    l = r - p + 1; i = p; j = q + 1;
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
