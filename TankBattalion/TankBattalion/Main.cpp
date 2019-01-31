#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Mapa.h"


int main() {
	int nose = 1;
	Mapa imprimir;
	
	imprimir.OcultarCursor();

	imprimir.MarcarMapa();
	
	imprimir.Marcador();
	imprimir.Mover();

	
	system("pause > null");
	return 0;
}