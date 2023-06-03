#include <stdio.h>
#include <unistd.h>

#define ALTO_NUMERO 5
#define ANCHO_NUMERO 4

// Definir los caracteres '*' que forman cada número del 0 al 9
char numeros[10][ALTO_NUMERO][ANCHO_NUMERO] = {
    {
        "****",
        "*  *",
        "*  *",
        "*  *",
        "****"
    },
    {
        "   *",
        "   *",
        "   *",
        "   *",
        "   *"
    },
    {
        "****",
        "   *",
        "****",
        "*   ",
        "****"
    },
    {
        "****",
        "   *",
        "****",
        "   *",
        "****"
    },
    {
        "*  *",
        "*  *",
        "****",
        "   *",
        "   *"
    },
    {
        "****",
        "*   ",
        "****",
        "   *",
        "****"
    },
    {
        "****",
        "*   ",
        "****",
        "*  *",
        "****"
    },
    {
        "****",
        "   *",
        "   *",
        "   *",
        "   *"
    },
    {
        "****",
        "*  *",
        "****",
        "*  *",
        "****"
    },
    {
        "****",
        "*  *",
        "****",
        "   *",
        "****"
    }
};

void imprimirNumero(int num);

int main() {
    int segundos = 10;

    for (int i = segundos; i >= 0; i--) {
        imprimirNumero(i);

        // Pausa el programa durante 1 segundo
        sleep(1);
    }

    printf("Cronómetro finalizado.\n");

    return 0;
}

void imprimirNumero(int num) {
    int digitos[4];
    int contador = 0;

    // Extraer cada dígito del número
    do {
        digitos[contador] = num % 10;
        num /= 10;
        contador++;
    } while (num > 0);

    // Imprimir cada dígito en la consola
    for (int fila = 0; fila < ALTO_NUMERO; fila++) {
        for (int i = contador - 1; i >= 0; i--) {
            for (int columna = 0; columna < ANCHO_NUMERO; columna++) {
                printf("%c", numeros[digitos[i]][fila][columna]);
            }
            printf("  ");  // Espacio entre los dígitos
        }
        printf("\n");
    }
}

