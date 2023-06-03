//Linea de Compilacion gcc ColaProcesador.c -o 
//Recibe por argumentos la cantidad de Procesos que se van a hacer y luego pide en orden el nombre, su descripcion, su id y el tiempo que estara en procesamiento
#include <stdio.h>
#include <stdlib.h>
#include "Pilas2.h"
#include "TADColaDin.h"
int main(int argc, char const *argv[])
{	system("cls");
	char *cadena;
	cola Terminados,SinTerminar;
	elemento *auxiliar;
	elemento auxiliar1;
	int i,taux;
	cadena=malloc(2400*sizeof(char));
	for (i=0 ;i <2399; i++)
		cadena[i]=' ';
	cadena[2399]='\0';
	Initialize(&Terminados);
	Initialize(&SinTerminar);
	for (i=0 ;i < atoi(argv[1]); i++){
		auxiliar=malloc(sizeof(elemento)*1);
		fflush( stdin );
		fgets(auxiliar->Nombre,45,stdin);
		fgets(auxiliar->Actividad,200,stdin);
		fgets(auxiliar->ID,45,stdin);
		fflush( stdin );
		scanf("%d",&taux);
		auxiliar->tiempo=taux;
		auxiliar->procesamiento=0;
		Queue(&SinTerminar,*auxiliar);	
	}
	Dibuja_cajas(0, 0, 80, 28);
	Dibuja_cajas(81, 0, 119, 28);
	while(!Empty(&SinTerminar)){
		Escribir_dentro(35, 26,83,2,cadena);
		auxiliar1=Dequeue(&SinTerminar);
		auxiliar1.tiempo--;
		if(auxiliar1.tiempo>0){
			auxiliar1.procesamiento+=Size(&SinTerminar);
			auxiliar1.procesamiento++;
			Queue(&SinTerminar,auxiliar1);
		}
		else{
			auxiliar1.procesamiento+=Size(&SinTerminar);
			auxiliar1.procesamiento++;
			Queue(&Terminados,auxiliar1);
		}
		auxiliar1=Front(&SinTerminar);
		Escribir_dentro(35, 3,83,2,auxiliar1.Nombre);
		Escribir_dentro(35, 15,83,5,auxiliar1.Actividad);
		Escribir_dentro(35, 3,83,20,auxiliar1.Actividad);
		MoverCursor( 83, 23 );
		printf("SIGUIENTE");
		EsperarMiliSeg(2500);

	}
	
	Escribir_dentro(35, 30,83,2,cadena);
	MoverCursor( 0, 28 );
	return 0;
}