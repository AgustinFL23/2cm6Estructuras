#include<stdio.h>
#include "Librerias\cubeta.h"
int main(){
BMP imagen;
int RGB[3],RGBC[3];
abrir_imagen(&imagen, "ImagenA1.bmp");
seleccion(&imagen,1,1,RGB);
RGBC[0]=0;
RGBC[1]=0;
RGBC[2]=0;
cubeta(&imagen,RGB,1,1,RGBC);
printf("TER");
crear_imagen(&imagen, "ImagenB.bmp");
}
