#include<stdio.h>
#include "Librerias\cubeta.h"
int main(){
BMP imagen;
int RGB[3],RGBC[3],x,y;
abrir_imagen(&imagen,"ImagenA1.bmp");
imagen.pixelR[0][0]=(unsigned char)222;
for(x=0;x<imagen.ancho;x++){
	for(y=0;y<imagen.alto;y++){
		printf("%d %d %d   ",imagen.pixelR[x][y],imagen.pixelG[x][y],imagen.pixelB[x][y]);	
	}
	printf("\n");
}
seleccion(&imagen,1,1,RGB);
RGBC[0]=223;
RGBC[1]=223;
RGBC[2]=223;
cubeta(&imagen,RGB,1,1,RGBC);
crear_imagen(&imagen,"ImagenB.BMP");

/*
seleccion(&imagen,1,1,RGB);
printf("%d %d %d \n",RGB[0],RGB[1],RGB[2]);
printf("%d",imagen.ancho);
printf("%d\n",imagen.alto);
RGBC[0]=222;
RGBC[1]=222;
RGBC[2]=222;
printf("\n");
//cubeta(&imagen,RGB,1,1,RGBC);
imagen.pixelR[0][0]=(unsigned char)0;
imagen.pixelG[0][0]=(unsigned char)0;
imagen.pixelB[0][0]=(unsigned char)0;
printf("hola mundo");
crear_imagen(&imagen,"ImagenB.BMP");
printf("hola mundo");*/
}
