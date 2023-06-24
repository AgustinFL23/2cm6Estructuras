#include "ABB.h"
int main(){
    nodo diccionario;
    Inicializar(&diccionario);
    aniadir_palabra(&diccionario);
    aniadir_palabra(&diccionario);
    aniadir_palabra(&diccionario);
    recorrer_arbol(&diccionario, 1);
    printf("____________________________\n");
    recorrer_arbol(&diccionario, 2);
    printf("____________________________\n");
    recorrer_arbol(&diccionario, 3);
return 0;
}