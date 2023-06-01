#include<stdio.h>
//#include<Cola_din.h>
void proceso(); //.... Dibuja la caja y contiene info. Nombre del proceso, descripcion, tiempo real.
void next_proceso(elemento e); //Muestra informacion mas resumida. 
void C_Final(); //Comprueba la finalizacion del programa. Mete elemento vacios, representa un periodo de tiempo que paso, aumenta contador cada vez que se salte info. Aumenta uno e imprime que proceso fue. 
//Contenga 
void Comprueba_proceso(cola *c); //Comprueba la finalizacion de procesos.
void Orden_procesos();

typedef struct proceso{
	char* nom_proceso;
	char* descripcion;
	int time_steps; //Duracion de cada proceso entre unidad de tiempo.
	int tiempo_real;
}proceso;



/*
Dibujar una matriz y calcular el ancho y colocar la mayor cantidad que se pueda dentro
del cuadro de proceso (cuadrito de posibilidades). 
A ojo de buen cubero, caben 5 displays, queda un display en el medio. 
Hacer que quepan una cantidad impar de displays para que quedan 1 en medio. 


*/
