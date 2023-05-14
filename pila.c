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
int AsignarValor(char letra);
int Operar(int op1, int op2, char operador) ;


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

int Operar(int op1, int op2, char operador)
{
    int resultado;
    switch (operador) 
    {
        case '+':
            resultado = op1 + op2;
            break;
        case '-':
            resultado = op1 - op2;
            break;
        case '*':
            resultado = op1 * op2;
            break;
        case '/':
            resultado = op1 / op2;
            break;
        case '^':
            resultado = pow(op1, op2);
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

    
    for (i = 0; expresion[i] ; i++) {
        char c = expresion[i];
        if (isalpha(c)) {
            int valor = AsignarValor(c);
            push(&valores, valor);
        } 
        else if (c == '(') 
        {
            push(&ope, c);
        } else if (c == ')') 
        {
            while (Top(&ope) != '(') {
                char op = pop(&ope);
                int b = pop(&valores);
                int a = pop(&valores);
                int res = Operar(a, b, op);
                push(&valores, res);
            }
            pop(&ope);
        } 
        
        else {
            while (ope.tope > 0 && Prioridad(Top(&ope)) >= Prioridad(c)) {
                char op = pop(&ope);
                int b = pop(&valores);
                int a = pop(&valores);
                int res = Operar(a, b, op);
                push(&valores, res);
            }
            push(&ope, c);
        }
    }
    while (ope.tope > 0) {
        char op = pop(&ope);
        int b = pop(&valores);
        int a = pop(&valores);
        int res = Operar(a, b, op);
        push(&valores, res);
    }
    printf("\nEl resultado de la expresion es: %d\n", pop(&valores));
}

int AsignarValor(char letra) //listo
{
    int valor = 0; // Inicializar la variable con un valor por defecto

    if (letra >= 'A' && letra <= 'Z') 
    {
        printf("Ingrese el valor de la letra %c:\n", letra);
        scanf("%d", &valor);
    } 

    else 
    {
        printf("La letra %c no tiene un valor asignado.\n", letra);
    }

    return valor;
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

int ComprobarParentesis(char expresion[]) //listo
{
    pila p;
    p.tope = 0;
    int i;

    for (i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (c == '(') 
        {
            push(&p, c);
        } 
        else if (c == ')') 
        {
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

    for (i = 0; expresion[i] != '\0'; i++) {
        char c = expresion[i];
        if (isalpha(c)) {
            printf("%c", c);
        } 
        else if (c == '(') 
        {
            push(&ope, c);
        } 
        else if (c == ')') 
        {
            while (Top(&ope) != '(') 
            {
                printf("%c", pop(&ope));
            }
            pop(&ope);
        } 

        else {
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
