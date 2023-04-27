gcc misordenamientos.h misordenamientos.c -c
gcc main.c misordenamientos.c -o Main
Main.exe 500<numeros1M.txt >>Salidas/salida.csv
Main.exe 1000 <numeros1M.txt >>Salidas/salida.csv
Main.exe 5000 <numeros1M.txt >>Salidas/salida.csv
Main.exe 10000 <numeros1M.txt >>Salidas/salida.csv
Main.exe 50000 <numeros1M.txt >>Salidas/salida.csv
Main.exe 100000 <numeros1M.txt >>Salidas/salida.csv
Main.exe 200000 <numeros1M.txt >>Salidas/salida.csv
Main.exe 500000 <numeros1M.txt >>Salidas/salida.csv
Main.exe 750000<numeros1M.txt >>Salidas/salida.csv
Main.exe 1000000 <numeros1M.txt >>Salidas/salida.csv

