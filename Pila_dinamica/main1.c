#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "pila_dinamica.h"
void ConvertidorPostfijo(char expresion[]);  
int Prioridad(char c);
int ComprobarParentesis(char expresion[]);
void ConvertidorPostfijoNumeros(char expresion[]);
float AsignarValor(char letra);
float Operar(elemento op1, elemento op2, elemento operador) ;
int valores[26] = {0}; // Inicializar todos los valores a cero

int main(){

    //Declaracion de variables
    char *expresion;
    expresion = (char*)malloc(100 * sizeof(char));

    //Recibimos la expresion   
    scanf("%s", expresion);

    if (ComprobarParentesis(expresion)) {
        
        printf("Los parentesis estan balanceados.\n");
        printf("La expresion en Postfija es:\n");
        ConvertidorPostfijo(expresion);
        
        ConvertidorPostfijoNumeros(expresion); 

    } 

    else 
    {
        printf("Los parentesis no estan balanceados.\n");
    }
    free(expresion);
    return 0;

}

float Operar(elemento op1, elemento op2, elemento operador) 
{
    float resultado;
    switch (operador.dato.caracter) {
        case '+':
            resultado = op1.dato.flotante + op2.dato.flotante;
            break;
        case '-':
            resultado = op1.dato.flotante - op2.dato.flotante;
            break;
        case '*':
            resultado = op1.dato.flotante * op2.dato.flotante;
            break;
        case '/':
            if (op2.dato.flotante == 0) {
                printf("Error: División por cero.\n");
                resultado = 0;
            } else {
                resultado = op1.dato.flotante / op2.dato.flotante;
            }
            break;
        case '^':
            resultado = pow(op1.dato.flotante, op2.dato.flotante);
            break;
        default:
            printf("Operador no válido.\n");
            resultado = 0;
            break;
    }
    return resultado;
}

void ConvertidorPostfijoNumeros(char expresion[]) 
{
    pila valores;
    Initialize(&valores);
    pila ope;
    Initialize(&ope);
    int i;
    elemento valor, c;

    for (i = 0; expresion[i] ; i++) {
        c.dato.caracter = expresion[i];

        if (isalpha(c.dato.caracter)) {
            valor.dato.flotante = AsignarValor(c.dato.caracter);
            Push(&valores, valor);
        } else if (isdigit(c.dato.caracter) || c.dato.caracter == '.') { // Acepta números con decimales
            ungetc(c.dato.caracter, stdin);
            scanf("%lf", &valor.dato.flotante); // Utiliza el especificador de formato %lf para números reales
            Push(&valores, valor);
        } else if (c.dato.caracter == '(') {
            Push(&ope, c);
        } else if (c.dato.caracter == ')') {
            while (Top(&ope).dato.caracter != '(') {
                elemento op = Pop(&ope);
                elemento b = Pop(&valores);
                elemento a = Pop(&valores);
                elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
                Push(&valores, res);
            }
            Pop(&ope);
        } else {
            while (ope.tope > 0 && Prioridad(Top(&ope).dato.caracter) >= Prioridad(c.dato.caracter)) {
                elemento op = Pop(&ope);
                elemento b = Pop(&valores);
                elemento a = Pop(&valores);
                elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
                Push(&valores, res);
            }
            Push(&ope, c);
        }
    }
    while (ope.tope > 0) {
        elemento op = Pop(&ope);
        elemento b = Pop(&valores);
        elemento a = Pop(&valores);
        elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
        Push(&valores, res);
    }
    printf("\nEl resultado de la expresion es: %.2f\n", Pop(&valores).dato.flotante);
    Destroy(&valores);
    Destroy(&ope);
}

float AsignarValor(char letra) 
{
    int indice = letra - 'A';
    if (valores[indice] != 0) 
    {
        printf("La letra %c ya tiene asignado el valor.\n", letra);
        return valores[indice];
    } 
    else 
    {
        printf("Ingrese el valor de la letra %c:\n", letra);
        float valor;
        scanf("%f", &valor);
        valores[indice] = valor;
        return valor;
    }
}

int Prioridad(char c) //listo
{
    switch(c) {
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

int ComprobarParentesis(char expresion[]) 
{
    pila p;
    Initialize (&p);
    int i, a;
    elemento c;

    for (i = 0; expresion[i] != '\0'; i++) {
        c.tipo = 'c'; // indicamos que el tipo de dato de la estructura es un caracter
        c.dato.caracter = expresion[i];
        if (c.dato.caracter == '(') 
        {
            Push(&p, c);
        } 
        else if (c.dato.caracter == ')') 
        {
            if (Empty(&p) == 1 || Pop(&p).dato.caracter != '(') {
                Destroy(&p);
                return 0;
            }
        }
    }
    a = Empty(&p);
    Destroy(&p);
    return (a == 1);
}

void ConvertidorPostfijo(char expresion[])
{
    pila operador;
    Initialize (&operador);
    int i;
    elemento c;

    for (i = 0; expresion[i] != '\0'; i++) {
        c.dato.caracter = expresion[i];
        if (isalpha(c.dato.caracter)) {
            printf("%c", c.dato.caracter);
        } 
        else if (c.dato.caracter == '(') 
        {
            Push(&operador, c);
        } 
        else if (c.dato.caracter == ')') 
        {
            while (Top(&operador).dato.caracter != '(') 
            {
                printf("%c", Pop(&operador).dato.caracter);
            }
            Pop(&operador);
        } 
        else {
            while (operador.tope > 0 && Prioridad(Top(&operador).dato.caracter) >= Prioridad(c.dato.caracter)) {
                printf("%c", Pop(&operador).dato.caracter);
            }
            Push(&operador, c);
        }
    }
    while (operador.tope > 0) {
        printf("%c", Pop(&operador).dato.caracter);
    }
    printf("\n");
    Destroy(&operador);
}
