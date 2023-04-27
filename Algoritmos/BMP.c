//*****************************************************************
//EDGARDO ADRIÁN FRANCO MARTÍNEZ 
//(C) Marzo 2023 Versión 2.0
//Lectura y tratamiento de imagenes BMP 
//Compilación: "gcc -o pruebaBMP pruebaBMP.c "
//Ejecución: "./pruebaBMP imagen.bmp"
//Observaciones: Hay un problema de padding con imagenes de ciertos tamaños 
//se recomienda en el futuro leer de fluido los pixeles en un solo arreglo dinámico.
//FUNCIONA CORRECTAMENTE EN MATRICES CUADRADAS
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************
#define IMAGEN_TRATADA	"tratada.bmp"		//Ruta y nombre del archivo de la imagen de salida BMP

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************
//Estructura para almacenar la imagen BMP en 256 valores de escala de gris
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

/*********************************************************************************************************
//PROGRAMA PRINCIPAL 
//*********************************************************************************************************/
int main (int argc, char* argv[])
{	
	int i,j; 				//Variables auxiliares para loops
	BMP img;				//Estructura de tipo imágen
	unsigned char pixel;	//Pixel
	
	//******************************************************************	
	//Si no se introdujo la ruta de la imagen BMP 
	//******************************************************************	
	char IMAGEN[45];
	
	//Si no se introduce correctamente el nombre del archivo
	if (argc!=2) 
	{
		printf("\nIndique el nombre del archivo BMP - Ejemplo: [user@equipo]$ %s imagen.bmp\n",argv[0]);
		exit(1);
	} 
	strcpy(IMAGEN,argv[1]);
	
	//*****************************************************************************************************************
	//1 Abrir la imágen BMP de 24 bits, almacenar su cabecera en img y colocar sus pixeles en el arreglo img.pixel[][]
	//*****************************************************************************************************************
	abrir_imagen(&img,IMAGEN);
	printf("\n*************************************************************************");
	printf("\nIMAGEN: %s",IMAGEN);
	printf("\n*************************************************************************");
	printf("\nDimensiones de la imágen:\tAlto=%d\tAncho=%d\n",img.alto,img.ancho);
	
	//***********************************************************************************
	//2 Tratamiento de los pixeles
	//***********************************************************************************
	//Ejemplo donde se entercambia el plano Rojo con el Azul de la mitad de la imagen
	for (i=0;i<img.alto;i++)
		for (j=0;j<img.ancho;j++)		
		{
			pixel=(img.pixelG[i][j]+img.pixelR[i][j]+img.pixelB[i][j])/3; 
			img.pixelR[i][j]=pixel;
			img.pixelB[i][j]=pixel;
			img.pixelG[i][j]=pixel;			
			
		}
		
	//*****************************************************************
	//3 Crear la imágen BMP a partir del arreglo img.pixel[][]
	//*****************************************************************
	crear_imagen(&img,IMAGEN_TRATADA);
	printf("\nImágen BMP tratada en el archivo: %s\n",IMAGEN_TRATADA);
	
	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//FUNCIONES 
//************************************************************************
//*************************************************************************************************************************************************
//Función para abrir la imagen, colocarla en escala de grisis en la estructura imagen imagen (Arreglo de bytes de alto*ancho  --- 1 Byte por pixel 0-255)
//Parametros de entrada: Referencia a un BMP (Estructura BMP), Referencia a la cadena ruta char ruta[]=char *ruta
//Parametro que devuelve: Ninguno
//*************************************************************************************************************************************************
void abrir_imagen(BMP *imagen, char *ruta)
{
	FILE *archivo;	//Puntero FILE para el archivo de imágen a abrir
	int i,j,k,resto;
	unsigned char R,B,G,var;
	
	//Abrir el archivo de imágen
	archivo = fopen( ruta, "rb+" );
	if(!archivo)
	{ 
		//Si la imágen no se encuentra en la ruta dada
		printf( "La imágen %s no se encontro\n",ruta);
		exit(1);
	}

	//Leer la cabecera de la imagen y almacenarla en la estructura global img
	fseek( archivo,0, SEEK_SET);
	fread(&imagen->bm,sizeof(char),2, archivo);
	fread(&imagen->tamano,sizeof(int),1, archivo);
	fread(&imagen->reservado,sizeof(int),1, archivo);	
	fread(&imagen->offset,sizeof(int),1, archivo);	
	fread(&imagen->tamanoMetadatos,sizeof(int),1, archivo);	
	fread(&imagen->alto,sizeof(int),1, archivo);	
	fread(&imagen->ancho,sizeof(int),1, archivo);	
	fread(&imagen->numeroPlanos,sizeof(short int),1, archivo);	
	fread(&imagen->profundidadColor,sizeof(short int),1, archivo);	
	fread(&imagen->tipoCompresion,sizeof(int),1, archivo);
	fread(&imagen->tamanoEstructura,sizeof(int),1, archivo);
	fread(&imagen->pxmh,sizeof(int),1, archivo);
	fread(&imagen->pxmv,sizeof(int),1, archivo);
	fread(&imagen->coloresUsados,sizeof(int),1, archivo);
	fread(&imagen->coloresImportantes,sizeof(int),1, archivo);	

	//Validar ciertos datos de la cabecera de la imágen	
	if (imagen->bm[0]!='B'||imagen->bm[1]!='M')	
	{
		printf ("La imagen debe ser un bitmap.\n"); 
		exit(1);
	}
	if (imagen->profundidadColor!= 24) 
	{
		printf ("La imagen debe ser de 24 bits.\n"); 
		exit(1);
	}
	
	//*********************************************************************************************************
	//Padding (Bytes necesarios para que el Pad row alcance a ser multiplo de 4 Bytes)
	//*********************************************************************************************************
	imagen->padding = (4 - (imagen->ancho * 3) % 4) % 4;

	//*********************************************************************************************************
	//Reservar memoria para el arreglo que tendra los planos RGB de la imagen (Arreglo de tamaño "img.ancho X img.alto")
	//*********************************************************************************************************
	imagen->pixelR=malloc(imagen->alto* sizeof(char *)); 
	imagen->pixelG=malloc(imagen->alto* sizeof(char *)); 
	imagen->pixelB=malloc(imagen->alto* sizeof(char *)); 
	for( i=0; i<imagen->alto; i++)
	{
		imagen->pixelR[i]=malloc (imagen->ancho* sizeof(char)); 
		imagen->pixelG[i]=malloc (imagen->ancho* sizeof(char)); 
		imagen->pixelB[i]=malloc (imagen->ancho* sizeof(char)); 
	}
		
	//*********************************************************************************************************
	//Colocar el cursor en el byte (offset) donde comienzan los datos de la imagen
	//*********************************************************************************************************
	fseek(archivo,imagen->offset, SEEK_SET);

	//*********************************************************************************************************
	//Algoritmo sobre la imágen a las matrices correspondientes
	//*********************************************************************************************************
	//Iterar a través de las filas de píxeles, teniendo en cuenta que los datos comienza en la esquina inferior izquierda de la imagen BMP
	for (i=imagen->alto-1;i>=0;i--)
	{
		for (j=0;j<imagen->ancho;j++)
		{  
			fread(&B,sizeof(char),1, archivo);  //Byte Blue del pixel
			fread(&G,sizeof(char),1, archivo);  //Byte Green del pixel
			fread(&R,sizeof(char),1, archivo);  //Byte Red del pixel
			imagen->pixelR[i][j]=R;
			imagen->pixelG[i][j]=G;
			imagen->pixelB[i][j]=B;
		}   
		
		//Padding (Bytes necesarios para que el Pad row alcance a ser multiplo de 4 Bytes)		
		for (k=1;k<=imagen->padding;k++)
		{
			fread(&var,sizeof(char),1, archivo);  //Leer los pixeles de relleno (Padding)
		}
	}
	//Cerrrar el archivo
	fclose(archivo);	
}

//****************************************************************************************************************************************************
//Función para crear una imagen BMP, a partir de la estructura imagen imagen (Arreglo de bytes de alto*ancho  --- 1 Byte por pixel 0-255)
//Parametros de entrada: Referencia a un BMP (Estructura BMP), Referencia a la cadena ruta char ruta[]=char *ruta
//Parametro que devuelve: Ninguno
//****************************************************************************************************************************************************
void crear_imagen(BMP *imagen, char ruta[])
{
	FILE *archivo;	//Puntero FILE para el archivo de imágen a abrir

	int i,j,k,resto;
	unsigned char var=0x00;

	//Abrir el archivo de imágen
	archivo = fopen( ruta, "wb+" );
	if(!archivo)
	{ 
		//Si la imágen no se encuentra en la ruta dada
		printf( "La imágen %s no se pudo crear\n",ruta);
		exit(1);
	}
	
	//Leer la cabecera de la imagen y almacenarla en la estructura global img
	fseek( archivo,0, SEEK_SET);
	fwrite(&imagen->bm,sizeof(char),2, archivo);
	fwrite(&imagen->tamano,sizeof(int),1, archivo);	
	fwrite(&imagen->reservado,sizeof(int),1, archivo);	
	fwrite(&imagen->offset,sizeof(int),1, archivo);	
	fwrite(&imagen->tamanoMetadatos,sizeof(int),1, archivo);	
	fwrite(&imagen->alto,sizeof(int),1, archivo);	
	fwrite(&imagen->ancho,sizeof(int),1, archivo);	
	fwrite(&imagen->numeroPlanos,sizeof(short int),1, archivo);	
	fwrite(&imagen->profundidadColor,sizeof(short int),1, archivo);	
	fwrite(&imagen->tipoCompresion,sizeof(int),1, archivo);
	fwrite(&imagen->tamanoEstructura,sizeof(int),1, archivo);
	fwrite(&imagen->pxmh,sizeof(int),1, archivo);
	fwrite(&imagen->pxmv,sizeof(int),1, archivo);
	fwrite(&imagen->coloresUsados,sizeof(int),1, archivo);
	fwrite(&imagen->coloresImportantes,sizeof(int),1, archivo);	
			
	//*********************************************************************************************************
	//Colocar el cursor en el byte (offset) donde comienzan los datos de la imagen
	//*********************************************************************************************************
	fseek(archivo,imagen->offset,SEEK_SET);

	//*********************************************************************************************************
	//Pasar la imágen del arreglo reservado en escala de grises a el archivo (Deben escribirse los valores BGR)
	//*********************************************************************************************************	
	//Iterar a través de las filas de píxeles, teniendo en cuenta que los datos comienza en la esquina inferior izquierda de la imagen BMP
	for (i=imagen->alto-1;i>=0;i--)
	{
		for (j=0;j<imagen->ancho;j++)
		{  
			//Ecribir los 3 bytes BGR al archivo BMP, en este caso todos se igualan al mismo valor (Valor del pixel en la matriz de la estructura imagen)
			fwrite(&imagen->pixelB[i][j],sizeof(char),1, archivo);  //Escribir el Byte Blue del pixel 
			fwrite(&imagen->pixelG[i][j],sizeof(char),1, archivo);  //Escribir el Byte Green del pixel
			fwrite(&imagen->pixelR[i][j],sizeof(char),1, archivo);  //Escribir el Byte Red del pixel
		}  
		
		//Padding (Bytes necesarios para que el Pad row alcance a ser multiplo de 4 Bytes)		
		for (k=1;k<=imagen->padding;k++)
			fwrite(&var,sizeof(char),1, archivo);  //Escribir los pixeles de relleno		
	}
	//Cerrrar el archivo
	fclose(archivo);
}
