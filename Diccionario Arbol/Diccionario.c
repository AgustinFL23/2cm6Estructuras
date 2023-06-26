#include "ABB.h"
int main(){
    nodo diccionario;
    Inicializar(&diccionario);
    int opc;
    do
    {    
    printf("\t MENU \t\n");
    printf("1.- Cargar un archivo de definiciones\n");
    printf("2.- Agregar una palabra y su definicion\n");
    printf("3.- Buscar una palabra\n");
    printf("4.- Modificar una definicion\n");
    printf("5.- Eliminar una palabra\n");
    printf("6.- Recorridos\n");
    printf("7.- Estadisticas del ABB\n");
    printf("8.- Salir\n");

    printf("Ingrese una opcion:\n");
    scanf("%d", &opc);

    fflush(stdin);

    switch (opc)
    {
    case 1:
        
        break;

    case 2:

        printf("Ingresa la palabra y su definicion:\n");
        aniadir_palabra(&diccionario);

        break;
    case 3:
        char Buscar_palabra[30];
        printf("¿Que palabra deseas buscar?\n");
        fgets(Buscar_palabra,30,stdin);
        palabra buscada = buscar_palabra(&diccionario, Buscar_palabra);
        if (buscada!=NULL)
        {
            printf("%s\n %s", buscada->palabra, buscada->descripcion);
        }
        else
        {
            printf("Palabra no encontrada");
        }
        break;

    case 4:
        
        char nueva_descripcion[200];
        char palabra_buscar[30];
        printf("Ingrese la palabra que deasea modificar:\n");
        fgets(palabra_buscar,30,stdin);
        printf("Ingresa la nueva descripcion: \n");
        fgets(nueva_descripcion, 200, stdin);
        modificar_descripcion(&diccionario, palabra_buscar, nueva_descripcion);
        break;

    case 5:
        
        break;

    case 6:
        int recorrido;
        printf("Recorridos disponibles:\n");
        printf("1. Pre Orden\n");
        printf("2. In order\n");
        printf("3. Post order\n");
        printf("Ingrese el tipo de recorrido: ");
        scanf("%d", &recorrido);
        getchar(); // Consumir el carácter de nueva línea después de la entrada numérica
        recorrer_arbol(&diccionario, recorrido); 
        break;

    case 7:
        mostrar_informacion_arbol(&diccionario);
        break;

    case 8:
        printf("Hasta la proximaaa");
        break;
    
    default:
    printf("Opcion invalida.");

        break;
    } 
    
    } while (opc!=8);
    
    return 0;
}
