#ifndef TANKBATTALION
#define TANKBATTALION



#include <iostream>
#include <conio.h>
#include <Windows.h>


class General {
public:
	void inicio();
	void logo();
};

class Tank {
public:

	void mover();
	void movern();
	void movern2();
	void bala();
	void balan();
	void balan2();
	void checabala();
	void dibujar();
};

class Mapa {
public:


	void nivel();
	void Puntuacion();
	void pintar();
	void marcador();
	

};

#endif // !TANKBATTALION
