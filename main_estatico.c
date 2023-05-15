#include "pila_estatica\pila.h"
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

float Operar(elemento op1, elemento op2, elemento operador) //listo
{
    float resultado;    
    switch (operador.dato.caracter) // según el operador recibido, se realiza la operación correspondiente
    {
        case '+':
            resultado = op1.dato.flotante + op2.dato.flotante; // suma de los operandos
            break;
        case '-':
            resultado = op1.dato.flotante - op2.dato.flotante; // resta de los operandos
            break;
        case '*':
            resultado = op1.dato.flotante * op2.dato.flotante; // multiplicación de los operandos
            break;
        case '/':
            if (op2.dato.flotante == 0) 
            {   // se verifica si se intenta dividir por cero
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
    return resultado; // se devuelve el resultado de la operación
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

        if (isalpha(c.dato.caracter)) 
        {
            valor.dato.flotante = AsignarValor(c.dato.caracter);
            push(&valores, valor);
        } 
        else if (isdigit(c.dato.caracter) || c.dato.caracter == '.') // Acepta números con decimales
        { 
            // Devolver el caracter a la entrada para que pueda ser leído por scanf
            ungetc(c.dato.caracter, stdin);
            scanf("%lf", &valor.dato.flotante); // Utiliza el especificador de formato %lf para números reales
            push(&valores, valor); // Agregar a la pila de valores
        } 
        else if (c.dato.caracter == '(') 
        {
            push(&ope, c);
        }
        // Si es un paréntesis de cierre
        else if (c.dato.caracter == ')') 
        {
            // Mientras que el operador en la cima de la pila no sea un paréntesis de apertura
            while (Top(&ope).dato.caracter != '(') 
            {
                elemento op = pop(&ope);    // Extraer el operador de la pila de operadores
                elemento b = pop(&valores); // Extraer el segundo operando de la pila de valores
                elemento a = pop(&valores); // Extraer el primer operando de la pila de valore
                elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };  // Realizar la operación correspondiente y crear un nuevo elemento con el resultado
                push(&valores, res);    // Agregar el resultado a la pila de valores
            }

            pop(&ope);  // Eliminar el paréntesis de apertura de la pila de operadores
        }
        else 
        {   
        // Mientras que haya operadores en la pila de operadores y la prioridad del operador en la cima de la pila sea mayor o igual que la del operador actual
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
    while (ope.tope > 0) //mientras nuestra pila no este vacia
    {
        elemento op = pop(&ope);
        elemento b = pop(&valores);
        elemento a = pop(&valores);
        // Realizar la operación correspondiente y crear un nuevo elemento con el resultado
        elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
        push(&valores, res);
    }
    printf("\nEl resultado de la expresion es: %.2f\n", pop(&valores).dato.flotante);
}

float AsignarValor(char letra) 
{
    int indice = letra - 'A';   //obtenemos el indice de lla variable en el arreglo valores
    if (valores[indice] != 0)   //si la variable ya tiene asignado un valor
    {
        printf("La letra %c ya tiene asignado un valor \n", letra);
        return valores[indice];
    } 
    else 
    {
        printf("Ingrese el valor de la letra %c:\n", letra);
        float valor;
        scanf("%f", &valor);    //guardamos el valor tipo flotante en la letra
        valores[indice] = valor;    //lo guardamos en el arreglo
        return valor;
    }
}

int Prioridad(char c) //listo
{
    switch(c) {
        case '^':
            return 3;   //Maypr prioridad
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;   //Menor prioridad
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
        c.dato.caracter = expresion[i]; //guardamos el caracter en la estructura
        if (c.dato.caracter == '(') //si es un parentesis de apertura se guarda en la pila
        {
            push(&p, c);
        } 
        else if (c.dato.caracter == ')') //si es un parentesis de cerradura
        {
            if (p.tope == 0 || pop(&p).dato.caracter != '(') //si no encontramos el parentesis correspondiente al de apertura o nuestro pila esta vacia retornamos 0 y nuestra expresion no esta balanceada
            {
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
        if (isalpha(c.dato.caracter)) // Si el caracter es una letra, simplemente lo imprime
        {
            printf("%c", c.dato.caracter);
        } 
        // Si el caracter es un paréntesis abierto, lo agrega a la pila de operadores
        else if (c.dato.caracter == '(') 
        {
            push(&ope, c);
        } 
        // Si el caracter es un paréntesis cerrado, desapila operadores hasta encontrar el paréntesis abierto
        // e imprime los operadores desapilados
        else if (c.dato.caracter == ')') 
        {
            while (Top(&ope).dato.caracter != '(') 
            {
                printf("%c", pop(&ope).dato.caracter);
            }
            pop(&ope);
        } 
        // Si el caracter es un operador, desapila operadores con igual o mayor prioridad
        // y los imprime. Luego agrega el operador actual a la pila de operadores.
        else {
            while (ope.tope > 0 && Prioridad(Top(&ope).dato.caracter) >= Prioridad(c.dato.caracter)) {
                printf("%c", pop(&ope).dato.caracter);
            }
            push(&ope, c);
        }
    }
    // Desapila y imprime todos los operadores restantes en la pila de operadores
    while (ope.tope > 0) 
    {
        printf("%c", pop(&ope).dato.caracter);
    }
    printf("\n");
}
