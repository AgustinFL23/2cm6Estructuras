#include<stdio.h>
#include "Librerias\cubeta.h"
int main(){
BMP imagen;
int RGB[3],RGBC[3],x,y;
abrir_imagen(&imagen, "ImagenA1.bmp");
seleccion(&imagen,0,0,RGB);
printf("%d %d %d \n",RGB[0],RGB[1],RGB[2] );
printf("%d",imagen.ancho);
printf("%d\n",imagen.alto);
RGBC[0]=111;
RGBC[1]=111;
RGBC[2]=111;
cubeta(&imagen,RGB,0,0,RGBC);
for (x=0;x<imagen.ancho;x++){
	for(y=0;y<imagen.alto;y++)
		printf("%d %d %d |", imagen.pixelR[x][y], imagen.pixelG[x][y], imagen.pixelB[x][y]);
	printf("\n");
}

}
