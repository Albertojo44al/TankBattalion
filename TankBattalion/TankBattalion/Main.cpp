#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Mapa.h"


int main() {
	int nose = 1;
	Mapa imprimir;
	imprimir.gotoxy(10, 10); printf("%c%c",219,219);
	imprimir.gotoxy(10, 11); printf("%c%c >", 219, 219);
	imprimir.gotoxy(10, 12); printf("%c%c", 219, 219);


	imprimir.MarcarMapa();
	imprimir.Marcador();

	
	system("pause > null");
	return 0;
}