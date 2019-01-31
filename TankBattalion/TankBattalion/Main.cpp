#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Mapa.h"


int main() {
	
	Mapa imprimir;
	
	imprimir.OcultarCursor();

	imprimir.MarcarMapa();
	
	imprimir.Marcador();
	imprimir.Mover();

	
	system("pause > null");
	return 0;
}