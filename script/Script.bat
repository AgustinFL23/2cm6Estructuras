gcc Pila_dinamica\pila_dinamica.c Pila_dinamica\pila_dinamica.h -c
gcc pila_estatica\pila.c pila_estatica\pila.h -c
gcc main_din.c Pila_dinamica\pila_dinamica.c -o main_din.exe
gcc main_estatico.c pila_estatica\pila.c -o main_est.exe

