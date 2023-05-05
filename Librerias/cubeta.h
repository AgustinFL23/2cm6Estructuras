#include "BMP.h" // libreria que nos ayuda a manejar imagenes BMP
#include "tiempo.h"//libreria que nos permite medir tiempos
int cubeta (BMP* img,int*RGBO,int x,int y,int* RBGC) ; 
/*la funcion recibe un apuntador a una estructura BMP que es la imagen que vamos a manipular
un arreglo de enteros que incluye en los valores Rojo, Azul y verde  del color original en orden
Las coordenadas x,y en las que  vamos a intentar cambiar el color
un arreglo de enteros que incluye en los valores Rojo, Azul y verde  del color al que vamos a cambiar en orden*/

