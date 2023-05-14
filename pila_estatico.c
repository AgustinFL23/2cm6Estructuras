#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define TAM_MAX 1000

void ConvertidorPostfijo(char expresion[]);  
int Prioridad(char c);
int ComprobarParentesis(char expresion[]);
void ConvertidorPostfijoNumeros(char expresion[]);
float AsignarValor(char letra);
float Operar(elemento op1, elemento op2, elemento operador) ;
int valores[26] = {0}; // Inicializar todos los valores a cero

int main(){

    //Declaracion de variables
    char ex[TAM_MAX];

    //Recibimos la expresion   
    scanf("%s", ex);

    if (ComprobarParentesis(ex)) {
        
        printf("Los parentesis estan balanceados.\n");
        printf("La expresion en Postfija es:\n");
        ConvertidorPostfijo(ex);
        
        ConvertidorPostfijoNumeros(ex); 

    } 

    else 
    {
        printf("Los parentesis no estan balanceados.\n");
    }

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
    valores.tope = 0;
    pila ope;
    ope.tope = 0;
    int i;
    elemento valor, c;

    for (i = 0; expresion[i] ; i++) {
        c.dato.caracter = expresion[i];

        if (isalpha(c.dato.caracter)) {
            valor.dato.flotante = AsignarValor(c.dato.caracter);
            push(&valores, valor);
        } else if (isdigit(c.dato.caracter) || c.dato.caracter == '.') { // Acepta números con decimales
            ungetc(c.dato.caracter, stdin);
            scanf("%lf", &valor.dato.flotante); // Utiliza el especificador de formato %lf para números reales
            push(&valores, valor);
        } else if (c.dato.caracter == '(') {
            push(&ope, c);
        } else if (c.dato.caracter == ')') {
            while (Top(&ope).dato.caracter != '(') {
                elemento op = pop(&ope);
                elemento b = pop(&valores);
                elemento a = pop(&valores);
                elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
                push(&valores, res);
            }
            pop(&ope);
        } else {
            while (ope.tope > 0 && Prioridad(Top(&ope).dato.caracter) >= Prioridad(c.dato.caracter)) {
                elemento op = pop(&ope);
                elemento b = pop(&valores);
                elemento a = pop(&valores);
                elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
                push(&valores, res);
            }
            push(&ope, c);
        }
    }
    while (ope.tope > 0) {
        elemento op = pop(&ope);
        elemento b = pop(&valores);
        elemento a = pop(&valores);
        elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
        push(&valores, res);
    }
    printf("\nEl resultado de la expresion es: %.2f\n", pop(&valores).dato.flotante);
}

float AsignarValor(char letra) 
{
    int indice = letra - 'A';
    if (valores[indice] != 0) 
    {
        printf("La letra %c ya tiene asignado el valor %.2f.\n", letra, valores[indice]);
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
    p.tope = 0;
    int i;
    elemento c;

    for (i = 0; expresion[i] != '\0'; i++) {
        c.tipo = 'c'; // indicamos que el tipo de dato de la estructura es un caracter
        c.dato.caracter = expresion[i];
        if (c.dato.caracter == '(') 
        {
            push(&p, c);
        } 
        else if (c.dato.caracter == ')') 
        {
            if (p.tope == 0 || pop(&p).dato.caracter != '(') {
                return 0;
            }
        }
    }
    return (p.tope == 0);
}

void ConvertidorPostfijo(char expresion[])
{
    pila ope;
    ope.tope = 0;
    int i;
    elemento c;

    for (i = 0; expresion[i] != '\0'; i++) {
        c.dato.caracter = expresion[i];
        if (isalpha(c.dato.caracter)) {
            printf("%c", c.dato.caracter);
        } 
        else if (c.dato.caracter == '(') 
        {
            push(&ope, c);
        } 
        else if (c.dato.caracter == ')') 
        {
            while (Top(&ope).dato.caracter != '(') 
            {
                printf("%c", pop(&ope).dato.caracter);
            }
            pop(&ope);
        } 
        else {
            while (ope.tope > 0 && Prioridad(Top(&ope).dato.caracter) >= Prioridad(c.dato.caracter)) {
                printf("%c", pop(&ope).dato.caracter);
            }
            push(&ope, c);
        }
    }
    while (ope.tope > 0) {
        printf("%c", pop(&ope).dato.caracter);
    }
    printf("\n");
}
