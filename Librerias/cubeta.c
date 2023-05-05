int cubeta (BMP* img,int*RGBO,int x,int y,int* RBGC) {
	if(img->pixelR[x][y]==RGBO[0]&img->pixelG[x][y]==RGBO[1]&img->pixelB[x][y]==RGBO[2]){ //Comprueba si el color del pixel actual es igual al que estamos buscando
		img->pixelR[x][y]=RGBC[0]; //si es asi le asigna los valores del nuevo color a la matriz
		img->pixelG[x][y]=RGBC[1];
		img->pixelB[x][y]=RGBC[2];
		cubeta(img,RGBO, x, y+1, RBGC); //se llama a si misma en la posicion de arriba
		cubeta(img,RGBO, x+1, y, RBGC); //se llama a si misma en la posicion de la derecha
		cubeta(img,RGBO, x, y-1, RBGC); //se llama a si misma en la posicion de abajo
		cubeta(img,RGBO, x-1, y, RBGC); //se llama a si misma en la posicion de la izquierda
	}
	return 1;
}
