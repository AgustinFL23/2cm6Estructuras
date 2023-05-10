#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM_MAX 1000

void evaluar(pila *S);
void ConvertidorPostfijo(char expresion[]);  
int Prioridad(char c);
int Busqueda(char valor);
int ComprobarParentesis(char expresion[]);
int evaluacion(char expresion[]);
int EsLetra(char c);
int AsignarValor(char letra);
int EvaluarExpresion(char expresion[]);

int main(){

    //Declaracion de variables
    char ex[TAM_MAX];

    //Recibimos la expresion   
    scanf("%s", ex);

    if (ComprobarParentesis(ex)) {
        
        printf("Los parentesis estan balanceados.\n");

        int resultado = EvaluarExpresion(ex);
        printf("El resultado es: %d\n", resultado);

        ConvertidorPostfijo(ex);

    } else {
        printf("Los parentesis no estan balanceados.\n");
    }

}

int Prioridad(char c) //listo
{
    switch(c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

int EsLetra(char c) 
{
    return isalpha(c) && c >= 'A' && c <= 'Z';
}

int AsignarValor(char letra) 
{
    int valor;
    printf("Ingrese valor para %c: ", letra);
    scanf("%d", &valor);
    return valor;
}

int ComprobarParentesis(char expresion[]) //listo
{
    pila p;
    p.tope = 0;
    int i;

    for (i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (c == '(') {
            push(&p, c);
        } else if (c == ')') {
            if (p.tope == 0 || pop(&p) != '(') {
                return 0;
            }
        }
    }
    return (p.tope == 0);
}

void ConvertidorPostfijo(char expresion[]) //listo
{
    pila ope;
    ope.tope = 0;
    int i;

    printf("La expresion posfija es: ");
    for (i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (isalpha(c)) {
            printf("%c", c);
        } else if (c == '(') {
            push(&ope, c);
        } else if (c == ')') {
            while (Top(&ope) != '(') {
                printf("%c", pop(&ope));
            }
            pop(&ope);
        } else {
            while (ope.tope > 0 && Prioridad(Top(&ope)) >= Prioridad(c)) {
                printf("%c", pop(&ope));
            }
            push(&ope, c);
        }
    }
    while (ope.tope > 0) {
        printf("%c", pop(&ope));
    }
    printf("\n");
}

void evaluar(pila *S)   //listo
{
    char p = pop(S);
    //  Aqui debería evaluarse el operador contra el contenido del stack.
    printf("%c", p);
}

int EvaluarExpresion(char expresion[])
{
    int i, op2=0, op1=0;
    int valor = 0;

    pila operandos;
    operandos.tope = 0;

    int valores[26] = {0}; // Inicializamos todos los valores a 0.
    
    for (i = 0; expresion[i] ; i++) {
        char c = expresion[i];
        if (EsLetra(c)) {   
            int index = c - 'A'; //
            if (valores[index] == 0) {
                valores[index] = AsignarValor(c);
            }
        }

        else if (c == '+') 
        {
             op2 = pop(&operandos);
             op1 = pop(&operandos);
            
            push(&operandos, op1 + op2);
            
        } 
        else if (c == '-') 
        {
             op2 = pop(&operandos);
             op1 = pop(&operandos);

            push(&operandos, op1 - op2);

        } 
        else if (c == '*') 
        {
             op2 = pop(&operandos);
             op1 = pop(&operandos);

            push(&operandos, op1 * op2);

        } 
        else if (c == '/') 
        {
             op2 = pop(&operandos);
             op1 = pop(&operandos);

            push(&operandos, op1 / op2);

        }
    }


    if (operandos.tope == 1) 
    {
        valor = pop(&operandos);
    } 

    else
    {
        printf("Error: la expresion es invalida.\n");
    }

    return valor;


 
}