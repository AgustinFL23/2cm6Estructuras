// Inclusi�n de archivos de encabezado est�ndar
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "Pila_dinamica\pila_dinamica.h" //Inclucion de "Pila_dinamica" para utilizar una pila din�mica en el programa

//Declaraci�n de Funciones
void ConvertidorPostfijo(char expresion[]);  
int Prioridad(char c);
int ComprobarParentesis(char expresion[]);
void ConvertidorPostfijoNumeros(char expresion[]);
float AsignarValor(char letra);
float Operar(elemento op1, elemento op2, elemento operador) ;
int valores[26] = {0}; // Inicializar todos los valores a cero

//Funcion Principal
int main(){

    //Declaracion de variables
    char *expresion;
    expresion = (char*)malloc(100 * sizeof(char));

    // Entrada de datos  
    scanf("%s", expresion);
	// Comprobaci�n de los par�ntesis en la expresi�n matem�tica
    if (ComprobarParentesis(expresion)) {
        printf("Los parentesis estan balanceados.\n");
        
        // Convertir la expresi�n matem�tica infija en una expresi�n postfija
        printf("La expresion en Postfija es:\n");
        ConvertidorPostfijo(expresion);
        
        //Obtenemos resultado de la expresión
        ConvertidorPostfijoNumeros(expresion); 
    } 
    else 
    {
        printf("Los parentesis no estan balanceados.\n");
    }
    free(expresion);// Libera la memoria asignada para la expresi�n.
    return 0;

}
/* 
Esta funci�n recibe como p�rametros dos elementos operando y un elemento operador
Realiza la operaci�n indicada por el operador sobre los operandos y retorna el resultado
 */
float Operar(elemento op1, elemento op2, elemento operador) 
{
    float resultado;
    switch (operador.dato.caracter) {
        case '+':
            resultado = op1.dato.flotante + op2.dato.flotante;// se suman los operandos
            break;
        case '-':
            resultado = op1.dato.flotante - op2.dato.flotante;// se restan los operandos
            break;
        case '*':
            resultado = op1.dato.flotante * op2.dato.flotante;// se multiplican los operandos
            break;
        case '/':
            if (op2.dato.flotante == 0)  // se comprueba si se est� dividiendo por cero
			{
                printf("Error: División por cero.\n");
                resultado = 0;
            } else {
                resultado = op1.dato.flotante / op2.dato.flotante;// se dividen los operandos
            }
            break;
        case '^':
            resultado = pow(op1.dato.flotante, op2.dato.flotante);//se elevan a la potencia los operandos
            break;
        default:
            printf("Operador no válido.\n");//si el operador no es uno de los esperados, se imprime un mensaje de error
            resultado = 0;
            break;
    }
    return resultado;// retorna el resultado de la operaci�n
}

void ConvertidorPostfijoNumeros(char expresion[]) 
{
    pila valores;// Pila para almacenar los valores num�ricos de la expresi�n
    Initialize(&valores);// Inicia Pila Valores
    pila ope;// Pila para almacenar los operadores de la expresi�n
    Initialize(&ope);//Inicia Pila ope
    int i;
    elemento valor, c;//elementos  de la estructura

//Recorre el arreglo de caracteres de la expresi�n
    for (i = 0; expresion[i] ; i++) {
        c.dato.caracter = expresion[i];
//Si el caracter es una letra, obtiene su valor num�rico y lo almacena en la pila valores
        if (isalpha(c.dato.caracter)) {
            valor.dato.flotante = AsignarValor(c.dato.caracter);
            Push(&valores, valor);
        }
// Si el caracter es un n�mero o un punto, lee su valor num�rico y lo almacena en la pila valores
		else if (isdigit(c.dato.caracter) || c.dato.caracter == '.') { // Acepta números con decimales
            ungetc(c.dato.caracter, stdin);
            scanf("%lf", &valor.dato.flotante); // Utiliza el especificador de formato %lf para números reales
            Push(&valores, valor);
        } 
// Si el caracter es un par�ntesis de apertura, lo almacena en la pila ope
		else if (c.dato.caracter == '(') {
            Push(&ope, c);
        } 
// Si el caracter es un par�ntesis de cierre, desapila los operadores y valores de las pilas ope y valores, y los
// utiliza para realizar las operaciones correspondientes, hasta encontrar el par�ntesis de apertura correspondiente.
		else if (c.dato.caracter == ')') {
            while (Top(&ope).dato.caracter != '(') {
                elemento op = Pop(&ope);
                elemento b = Pop(&valores);
                elemento a = Pop(&valores);
                elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
                Push(&valores, res);
            }
            Pop(&ope);
        } 
// Si el caracter es un operador, desapila los operadores y valores de las pilas ope y valores, y 
//los utiliza para realizar las operaciones correspondientes, siempre y cuando la prioridad del operador
// sea menor o igual que la del operador en el tope de la pila ope. Luego, almacena el operador en la pila ope.
		else {
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
// Procesa los operadores y valores restantes de las pilas
    while (ope.tope > 0) {
        elemento op = Pop(&ope);
        elemento b = Pop(&valores);
        elemento a = Pop(&valores);
        elemento res = { .tipo = 'f', .dato.flotante = Operar(a, b, op) };
        Push(&valores, res);
    }
//Imprime el resultado
    printf("\nEl resultado de la expresion es: %.2f\n", Pop(&valores).dato.flotante);
    Destroy(&valores); // Destruye la pila valores
    Destroy(&ope); // Destruye la pila ope
}

/**

Asigna un valor a una letra dada y lo almacena en el arreglo global "valores".
Si la letra ya tiene asignado un valor, se imprime un mensaje y se retorna ese valor.
En caso contrario, se solicita al usuario ingresar el valor y se almacena en el arreglo "valores".
Parametros: letra Caracter que representa la letra a la que se le asignar� un valor.
Retorna: Valor asignado a la letra dada.
*/
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

/*

Retorna la prioridad de un operador dado.
Parametro: c Caracter que representa el operador.
Retorna: Prioridad del operador. Si el caracter no es un operador v�lido, retorna -1.
*/
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
/*
Comprueba si una expresi�n matem�tica tiene una cantidad adecuada de par�ntesis abiertos y cerrados.

Parametros: expresion Cadena de caracteres que representa la expresi�n matem�tica.
Retorna 1 si los par�ntesis est�n balanceados, 0 en caso contrario.
 */
int ComprobarParentesis(char expresion[]) 
{
	// Inicializa una pila din�mica para almacenar los par�ntesis abiertos.
    pila p;
    Initialize (&p);
    
    int i, a;
    elemento c;

    for (i = 0; expresion[i] != '\0'; i++) {
        c.tipo = 'c'; // indicamos que el tipo de dato de la estructura es un caracter
        c.dato.caracter = expresion[i];
         // Si el par�ntesis es de apertura, lo agrega a la pila.
        if (c.dato.caracter == '(') 
        {
            Push(&p, c);
        } 
        // Si el par�ntesis es de cierre, verifica si hay un par�ntesis de apertura en la pila.
        else if (c.dato.caracter == ')') 
        {
        	// Si no hay un par�ntesis correspondiente o la pila est� vac�a, la expresi�n es inv�lida.
            if (Empty(&p) == 1 || Pop(&p).dato.caracter != '(') {
                Destroy(&p);
                return 0;
            }
        }
    }
    // Verifica si la pila est� vac�a al final del recorrido de la expresi�n
    a = Empty(&p);
    Destroy(&p); // Destruye la pila p
    return (a == 1);
}
/* 
Convierte una expresi�n en notaci�n infija a notaci�n postfija utilizando una pila de operadores. 
Recibe como par�metro una cadena de caracteres que representa la expresi�n en notaci�n infija a convertir.

*/
void ConvertidorPostfijo(char expresion[])
{
//Se declara e inicializa una pila de operadores utilizando la funci�n Initialize.
    pila operador;
    Initialize (&operador);
    int i;
    elemento c;
// Recorre cada elemento de la expresi�n hasta que se llega al final de la cadena (\0).
    for (i = 0; expresion[i] != '\0'; i++) {
        c.dato.caracter = expresion[i];
//Si c es una letra del alfabeto, se imprime el caracter
        if (isalpha(c.dato.caracter)) {
            printf("%c", c.dato.caracter);
        } 
//Si c es un par�ntesis de apertura, se empuja c en la pila de operadores.
        else if (c.dato.caracter == '(') 
        {
            Push(&operador, c);
        }
// Si c es un par�ntesis de cierre, se van desapilando operadores de la pila e imprimiendo en la salida
// hasta encontrar el par�ntesis de apertura correspondiente.
        else if (c.dato.caracter == ')') 
        {
            while (Top(&operador).dato.caracter != '(') 
            {
                printf("%c", Pop(&operador).dato.caracter);
            }
            Pop(&operador);
        }
//Si c es un operador, se van desapilando operadores de la pila e imprimiendo en la salida est�ndar todos
//aquellos con mayor o igual prioridad que c, hasta encontrar un operador con menor prioridad o vaciar la pila.
// Finalmente, se empuja c en la pila de operadores.
        else {
            while (operador.tope > 0 && Prioridad(Top(&operador).dato.caracter) >= Prioridad(c.dato.caracter)) {
                printf("%c", Pop(&operador).dato.caracter);
            }
            Push(&operador, c);
        }
    }
//Se van desapilando y imprimiendo en la salida todos los operadores restantes de la pila
    while (operador.tope > 0) {
        printf("%c", Pop(&operador).dato.caracter);
    }
    printf("\n");
    Destroy(&operador);// Destruye la pila operador
}
