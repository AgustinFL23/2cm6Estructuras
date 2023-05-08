#ifndef _cubeta
#define _cubeta

//*****************************************************************
//DEFINICION DE LA ESTRUCTURA BMP
//*****************************************************************
typedef struct BMP
{
	char bm[2];					//(2 Bytes) BM (Tipo de archivo)
	int tamano;					//(4 Bytes) Tamaño del archivo en bytes
	int reservado;				//(4 Bytes) Reservado
	int offset;					//(4 Bytes) offset, distancia en bytes entre la img y los píxeles
	int tamanoMetadatos;		//(4 Bytes) Tamaño de Metadatos (tamaño de esta estructura = 40)
	int alto;					//(4 Bytes) Ancho (numero de píxeles horizontales)
	int ancho;					//(4 Bytes) Alto (numero de pixeles verticales)
	short int numeroPlanos;		//(2 Bytes) Numero de planos de color
	short int profundidadColor;	//(2 Bytes) Profundidad de color (debe ser 24 para nuestro caso)
	int tipoCompresion;			//(4 Bytes) Tipo de compresión (Vale 0, ya que el bmp es descomprimido)
	int tamanoEstructura;		//(4 Bytes) Tamaño de la estructura Imagen (Paleta)
	int pxmh;					//(4 Bytes) Píxeles por metro horizontal
	int pxmv;					//(4 Bytes) Píxeles por metro vertical
	int coloresUsados;			//(4 Bytes) Cantidad de colores usados 
	int coloresImportantes;		//(4 Bytes) Cantidad de colores importantes
	
	int padding;				//Bytes necesarios para que el Pad row alcance a ser multiplo de 4 Bytes
	unsigned char **pixelR; 	//Puntero a los pixeles del plano R (Rojo)
	unsigned char **pixelG; 	//Puntero a los pixeles del plano G (Verde)
	unsigned char **pixelB; 	//Puntero a los pixeles del plano B (Azul)
}BMP;

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void abrir_imagen(BMP *imagen, char ruta[]);		//Función para abrir la imagen BMP
void crear_imagen(BMP *imagen, char ruta[]);	//Función para crear una imagen BMP
int seleccion (BMP* img,int x,int y,int* RGBO); //nos da el color del pixel 
void cubeta (BMP* img,int*RGBO,int x,int y,int* RGBC);
/*la funcion recibe un apuntador a una estructura BMP que es la imagen que vamos a manipular
un arreglo de enteros que incluye en los valores Rojo, Azul y verde  del color original en orden
Las coordenadas x,y en las que  vamos a intentar cambiar el color
un arreglo de enteros que incluye en los valores Rojo, Azul y verde  del color al que vamos a cambiar en orden*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cubeta.c"
#include "BMP.c"
#endif
