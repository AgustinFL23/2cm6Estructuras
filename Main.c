#include <stdio.h>
#include <stdlib.h>
#include <tiempo.h>
#include misordenamientos.h

main (int arg, char[]* args){

Int n, inicio[6], fin[6],aux;
Int *a1,*a2,*a3,*a4,*a5;
n=atoi(args[1]);
a1=malloc(sizeof(int)*n);
a2=malloc(sizeof(int)*n);
a3=malloc(sizeof(int)*n);
a4=malloc(sizeof(int)*n);
a5=malloc(sizeof(int)*n):

for(int i=0;i<n;i++){
scanf("%d",&aux);
a1[i]=aux;
a2[i]=aux;
a3[i]=aux;
a4[i]=aux; 
a5[i]=aux;
}
inicio[0]=clock();
Burbuja ();
Fin[0]=clock();
inicio[1]=clock();
Inserción();
Fin[1]=clock();
inicio[2]=clock();
Selección ();
Fin[2]=clock();
inicio[3]=clock();
Shell();
Fin[3]=clock();
inicio[4]=clock();
Merge ();
Fin[4]=clock();
inicio[5]=clock();
Quick();
Fin[5]=clock();
printf("%d,"n);
for(int i=0;i<6;i++)
printf("%f segundos, ", fin[i]-inicio[i]/CLOCKS_PER_SECOND);
Printf("\n");
}
