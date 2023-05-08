#include "cubeta.h"

void cubeta (BMP* img,int*RGBO,int x,int y,int*RGBC){
	if(x<img->ancho && x>=0){
		if (y<img->alto && y>=0){
			
			if(img->pixelR[x][y]==RGBO[0] && img->pixelG[x][y]==RGBO[1] && img->pixelB[x][y]==RGBO[2]){ //gComprueba si el color del pixel actual es igual al que estamos buscando				
				printf("%d %d \n",x,y);
				img->pixelR[x][y]=(unsigned char)RGBC[0]; //si es asi le asigna los valores del nuevo color a la matriz
				img->pixelG[x][y]=(unsigned char)RGBC[1];
				img->pixelB[x][y]=(unsigned char)RGBC[2];
					if(x<img->ancho && x>=0)
						if (y-1<img->alto && y-1>=0)
							//cubeta(img,RGBO, x, y-1, RGBC); // arriba
				if(x+1<img->ancho && x+1>=0)
						if (y<img->alto && y>=0)
							//cubeta(img,RGBO, x+1, y, RGBC); //derecha
			if(x<img->ancho && x>=0)
						if (y+1<img->alto && y+1>=0)
							//cubeta(img,RGBO, x, y+1, RGBC); //abajo
				//if(x-1<img->ancho && x-1>=0)
				//		if (y<img->alto && y>=0)
							cubeta(img,RGBO, x-1, y, RGBC); //izquierda
			}
		}
	}
}



int seleccion (BMP* img,int x,int y,int* RGBO) {
	RGBO[0]=img->pixelR[x][y]; //selecciona el color del pixel indicado
	RGBO[1]=img->pixelG[x][y];
	RGBO[2]=img->pixelB[x][y];
	return 1;
}
