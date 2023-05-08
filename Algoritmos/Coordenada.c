#include <stdio.h>
#include <stdlib.h>

void transformarCoordenada(char coordenada[], int *x, int *y) {
    int i = 1; // empezar en el Indice 1 para saltar el paréntesis de apertura
    int numero = 0;
    while(coordenada[i] != ',') { // leer el primer número hasta encontrar la coma
        numero = numero * 10 + (coordenada[i] - '0'); // convertir el caracter en su valor numérico y agregarlo al número
        i++;
    }
    *x = numero; // asignar el valor numérico a la variable x
    i++; // avanzar al siguiente caracter (después de la coma)
    numero = 0;
    while(coordenada[i] != ')') { // leer el segundo número hasta encontrar el paréntesis de cierre
        numero = numero * 10 + (coordenada[i] - '0'); // convertir el caracter en su valor numérico y agregarlo al número
        i++;
    }
    *y = numero; // asignar el valor numérico a la variable y
}

int main() {
    //char coordenada[] = "(15,32)";
    char coordenada[];
    
    
    
    for(i=0;coordenada[i]=='\0';i++){
    	scanf();
	}
	scanf();
    int x, y;
    transformarCoordenada(coordenada, &x, &y);
    printf("Coordenada transformada: (%d,%d)\n", x, y);
    return 0;
}
