#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "cola.h"

#define TIEMPO_BASE      200        // Tiempo base en ms
#define TIEMPO_CLIENTE   2          // Tiempo base en ms * 2 = 400ms
#define TIEMPO_ATENCION  4

void ComprobarCajas(cola *caja[], int num_cajas, int* clientes_atendidos);

int main() {
    char nombre_supermercado[100];
    int num_cajas;
    int clientes_atendidos = 0;

    printf("Ingrese el nombre del supermercado (sin espacios): ");
    scanf("%s", nombre_supermercado);

    printf("Ingrese el numero de cajas disponibles: ");
    scanf("%d", &num_cajas);

    if (num_cajas <= 0 || num_cajas > 10) {
        printf("El número de cajeros debe ser mayor que 0 y menor o igual a 10.\n");
        return 1;
    }

    cola caja[num_cajas];
    for (int i = 0; i < num_cajas; i++) {
        Initialize(&caja[i]);
    }

    srand(time(NULL));
    unsigned int cliente = 0;
    unsigned int tiempo = 0;

    while (clientes_atendidos <= 20) {
        usleep(TIEMPO_BASE * 1000);  // Esperar el tiempo base en microsegundos
        tiempo++;                    // Incrementar el contador de tiempo

        if (tiempo % TIEMPO_ATENCION == 0) {
            ComprobarCajas(caja, num_cajas, &clientes_atendidos);
        }

        if (tiempo % TIEMPO_CLIENTE == 0) {
            cliente++;                // Incrementar el número de clientes que se han formado
            elemento e;
            e.n = cliente;

            int numeroAleatorio = (rand() % num_cajas);
            Queue(&caja[numeroAleatorio], e);  // Encolar al nuevo cliente

            printf("\nLlego el cliente: %d", e.n);
        }

        // Mostrar el número de clientes en cada cola
        for (int i = 0; i < num_cajas; i++) {
            printf("\n%d clientes en cola %d", Size(&caja[i]), i + 1);
        }
    }

    return 0;
}

void ComprobarCajas(cola *caja[], int num_cajas, int* clientes_atendidos) {
    for (int i = 0; i < num_cajas; i++) {
        elemento e;

        if (!Empty(&caja[i])) {
            e = Dequeue(&caja[i]);
            printf("\nAtendí a: %d", e.n);
            (*clientes_atendidos)++;
        } else {
            printf("\nNo hay nadie por atender en la caja %d", i + 1);
        }
    }
}



/*int CajasVacias(cola *c[10], int n, int i)
{
    int x;
    if (!Empty(&c[i]))
    {
     return x++;    
    }
    else
    {
        printf("\nNo hay nadie por atender en la caja %d", i + 1);
    }    
}*/