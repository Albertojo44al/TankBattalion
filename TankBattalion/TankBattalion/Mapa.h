#include <Windows.h>
#include <iostream>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

class Mapa {
public:
	void gotoxy(int, int);
	void MarcarMapa();
	void Mover();
	void Marcador();
};