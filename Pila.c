#define RESET_COLOR    "\x1b[0m"
#define NEGRO_Letras       "\x1b[30m"
#define NEGRO_Fondo        "\x1b[40m"
#define ROJO_Letras      "\x1b[31m"
#define ROJO_Fondo     "\x1b[41m"
#define VERDE_Letras         "\x1b[32m"
#define VERDE_Fondo        "\x1b[42m"
#define AMARILLO_Letras  "\x1b[33m"
#define AMARILLO_Fondo  "\x1b[43m"
#define AZUL_Letras      "\x1b[34m"
#define AZUL_Fondo      "\x1b[44m"
#define MAGENTA_Letras   "\x1b[35m"
#define MAGENTA_Fondo  "\x1b[45m"
#define CYAN_Letras      "\x1b[36m"
#define CYAN_Fondo     "\x1b[46m"
#define BLANCO_Letras    "\x1b[37m"
#define BLANCO_Fondo   "\x1b[47m"
#include "Pilas2.h"
void Dibuja_cajas(int x1, int y1, int x2, int y2){
	char* cadena;
	int i=x2-x1;
	int j=y2-y1;
	MoverCursor( x1, y1 );
	cadena=malloc(sizeof(char)*(i+1));
	cadena[0]=201;
	for(i;i>0;i--){
		cadena[i]=205;
	}
	i=x2-x1;
	cadena[i]=187;
	cadena[i+1]='\0';
	system("color 30");
	printf("%s\n",cadena);
		cadena[0]=186;
		cadena[i]=186;
		i--;
		for(i;i>0;i--)
			cadena[i]=' ';
		j=y2-y1;
		for(i=1;i<j;i++){
			MoverCursor( x1, y1+i );
			printf("%s\n",cadena);
			EsperarMiliSeg(15);	
		}
			
	cadena[0]=200;
	i=x2-x1;
	for(i;i>0;i--){
		cadena[i]=205;
	}
	i=x2-x1;
	cadena[i]=188;
	cadena[i+1]='\0';
	MoverCursor( x1, y2 );
	printf("%s",cadena);
}

void Escribir_dentro(int tam, int altura,int x, int y, char* cadena){
	char* aux;
	int a=0,b,cont=1;
	aux=malloc(sizeof(char)*(tam+1));
	aux[tam]='\0';
	while(cont && (altura>a)){
		b=0;
		for(b;b<tam;b++){
			aux[b]=cadena[b+(a*(tam-1))];
			if(aux[b]=='\0'){
				cont=0;
				break;
			}
		}
		MoverCursor( x, y+a );
		printf("%s\n",aux);
		a++;
	};
}
