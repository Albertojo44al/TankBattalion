#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Mapa.h"


int main() {
	
	Mapa imprimir;
	Mapa Tanque1(10, 10, 3);
	
	imprimir.OcultarCursor();
	bool gameOver = false;
	imprimir.Inicio();
	while (imprimir.sal==2)
	{	
		Tanque1.Pintar('q');
		imprimir.MarcarMapa();
	
		while (!gameOver) 
		{
			Tanque1.morir();
			Tanque1.Mover();
			Tanque1.Marcador();
		}
	}
	
	system("pause > null");
	return 0;
}