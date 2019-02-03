#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Mapa.h"
#include <list>

using namespace std;

int main() {

	list<Bala*> B;
	list<Bala*>::iterator it;

	bool gameOver = false;
	Mapa M;
	Mapa Tanque1(10, 10, 3);

	M.OcultarCursor();
	while (M.sal != 5) {
		M.MarcarMapa();
		M.Inicio();
		while (M.sal == 2)
		{
			Tanque1.Pintar('q');
			M.MarcarMapa();

			while (!gameOver)
			{
				if (_kbhit) {
					unsigned char tecla = _getch();
					if (tecla == ' ')
						B.push_back(new Bala(M.X() + 2, M.Y() - 1));
				}

				for (it = B.begin(); it != B.end; it++) {
					(*it)->mover;
				}

				Tanque1.morir();
				Tanque1.Mover();
				Tanque1.Marcador();
			}
		}
	}
	return 0;
}