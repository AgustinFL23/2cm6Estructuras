#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "cola.h"
#define TIEMPO_BASE      200        // Tiempo base en ms
#define TIEMPO_CLIENTE   4          // Tiempo base en ms * 2 = 400ms
#define TIEMPO_ATENCION  2
#define TIEMPO_BORRAR 8
#define ALTO 10
#define ANCHO 8

int ComprobarCajas(cola cajas[], int num_cajas, int* clientes_atendidos, int i);
void DibujaCaja(int num, int cliente);
int ColasVacias(cola cajas[], int num_cajas);

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

    cola cajas[num_cajas];

    for (int i = 0; i < num_cajas; i++) {
        Initialize(&cajas[i]);
    }

    srand(time(NULL));
    unsigned int cliente = 0;
    unsigned int tiempo = 0;

    BorrarPantalla();

    MoverCursor(1,1);
    printf("Bienvenido a %s", nombre_supermercado);

    while (clientes_atendidos < 100 || !ColasVacias(cajas, num_cajas)) {
        usleep(TIEMPO_BASE * 1000);  // Esperar el tiempo base en microsegundos
        tiempo++;                    // Incrementar el contador de tiempo

        if (tiempo % TIEMPO_ATENCION == 0) {
            for (int i = 0; i < num_cajas; i++) {
                int e = ComprobarCajas(cajas, num_cajas, &clientes_atendidos, i);
                DibujaCaja(i+1, e);
            }
        }

        if (tiempo % TIEMPO_CLIENTE == 0) {
            cliente++;                // Incrementar el número de clientes que se han formado
            elemento e;
            e.n = cliente;

            int numeroAleatorio = rand() % num_cajas;
            Queue(&cajas[numeroAleatorio], e);
            MoverCursor(50,24);
            printf("\nLlego el cliente: %d", e.n);

        }

        // Mostrar el número de clientes en cada cola
        for (int i = 0; i < num_cajas; i++) {
            MoverCursor(4,12+i);
            printf("\n%d clientes en cola %d", Size(&cajas[i]), i + 1);
        }
    }

        MoverCursor(1,1);
        printf("La tienda %s a cerrado", nombre_supermercado);

    return 0;
}

int ComprobarCajas(cola cajas[], int num_cajas, int* clientes_atendidos, int i) {
    elemento e;

    if (!Empty(&cajas[i])) 
    {
        e = Dequeue(&cajas[i]);
        MoverCursor(2,11);
        printf("\nAtendi a: %d", e.n);
        (*clientes_atendidos)++;
        return e.n;
    }

    else 
    {
        MoverCursor(2,10);
        printf("\nNo hay nadie por atender en la caja %d", i + 1);
        return 0;
    }
    
}

void DibujaCaja(int num, int cliente) {
    int columna, fila, i;

    // Recorrer cada columna
    for (columna = num + (num * 8), i = 0; i < ANCHO; columna++, i++) {
        // Recorrer cada fila
        for (fila = 2; fila < ALTO+1; fila++) {
            // Mover el cursor, dibujar un * y esperar TIEMPO_BASE milisegundos
            MoverCursor(columna, fila);
            printf("*");
            // EsperarMiliSeg(TIEMPO_BASE);
        }
    }

    MoverCursor(num + (num * 8) + 1, 2);
    if (cliente != 0)
        printf("A:%d", cliente);
    else
        printf("vacia");
}

int ColasVacias(cola cajas[], int num_cajas) {
    for (int i = 0; i < num_cajas; i++) {
        if (!Empty(&cajas[i])) {
            return 0;  // Al menos una cola no está vacía
        }
    }
    return 1;  // Todas las colas están vacías
}
