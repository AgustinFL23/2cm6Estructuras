//*****************************************************************
//EDGARDO ADRIÁN FRANCO MARTINEZ 
//(C) Marzo 2023 Version 2.0
//Lectura y tratamiento de imagenes BMP 
//Compilacion: "gcc -o pruebaBMP pruebaBMP.c "
//Ejecucion: "./pruebaBMP imagen.bmp"
//Observaciones: Hay un problema de padding con imagenes de ciertos tamaños 
//se recomienda en el futuro leer de fluido los pixeles en un solo arreglo dinámico.
//FUNCIONA CORRECTAMENTE EN MATRICES CUADRADAS
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************

#include "cubeta.h" 
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************






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
	imagen->pixelR=malloc(imagen->ancho* sizeof(char *)); 
	imagen->pixelG=malloc(imagen->ancho* sizeof(char *)); 
	imagen->pixelB=malloc(imagen->ancho* sizeof(char *));
	for( i=0; i<imagen->ancho; i++){
		imagen->pixelR[i]=malloc (imagen->alto* sizeof(char)); 
		imagen->pixelG[i]=malloc (imagen->alto* sizeof(char)); 
		imagen->pixelB[i]=malloc (imagen->alto* sizeof(char)); 
	}
		
	//*********************************************************************************************************
	//Colocar el cursor en el byte (offset) donde comienzan los datos de la imagen
	//*********************************************************************************************************
	fseek(archivo,imagen->offset, SEEK_SET);

	//*********************************************************************************************************
	//Algoritmo sobre la imágen a las matrices correspondientes
	//*********************************************************************************************************
	//Iterar a través de las filas de píxeles, teniendo en cuenta que los datos comienza en la esquina inferior izquierda de la imagen BMP
	for (i=0;i<imagen->ancho;i++) //
	{
		for (j=imagen->alto-1;j>=0;j--)
		{  
			fread(&B,sizeof(char),1, archivo);  //Byte Blue del pixel
			fread(&G,sizeof(char),1, archivo);  //Byte Green del pixel
			fread(&R,sizeof(char),1, archivo);  //Byte Red del pixel
			imagen->pixelR[i][j]=R;
			imagen->pixelG[i][j]=G;
			imagen->pixelB[i][j]=B;
		}   
		
		//Padding (Bytes necesarios para que el Pad row alcance a ser multiplo de 4 Bytes)		
		fread(&var,sizeof(char),imagen->padding, archivo);  //Leer los pixeles de relleno (Padding)
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
	for(i=0;i<imagen->ancho;i++) //
	{ 
		for(j=imagen->alto-1;j>=0;j--)//
		{  
			fwrite(&imagen->pixelB[i][j],sizeof(char),1,archivo);  //Byte Blue del pixel
			fwrite(&imagen->pixelG[i][j],sizeof(char),1,archivo);  //Byte Green del pixel
			fwrite(&imagen->pixelR[i][j],sizeof(char),1,archivo);  //Byte Red del pixels			
		}   
		
		//Padding (Bytes necesarios para que el Pad row alcance a ser multiplo de 4 Bytes)		
		int k;
		for(k=0;k<imagen->padding;k++){
			fwrite(&var,sizeof(char),1,archivo);  //Leer los pixeles de relleno (Padding)	
		}
		
	}
	
	//Cerrrar el archivo
	fclose(archivo);
}
