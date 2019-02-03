#include <Windows.h>
#include <iostream>

//Clases Generales
void gotoxy(int, int);


class Mapa {

	int x, y;//cordenadas tanque 1
	int vidas;//vidas tanque 1
	int x2, y2;//cordenadas tanque 2
	int vidas2;// vidas tanque 2

	int move = 1, move2 = 0; // Extras para el menu 
public:
	int pos = 1, sal = 1, tecla;//Inicio
	class Mapa(int _x, int _y, int _vidas) : x(_x), y(_y), vidas(_vidas) {}
	class Mapa() {}
	

	//Tanque
	int X();
	int Y();
	void Pintar(char);
	void borrar();
	void Mover();
	void Mover2Player();
	void Vidas();
	void morir();
	//Mapa
	void Marcador();
	void OcultarCursor();
	void MarcarMapa();

	//Inicio
	void Inicio();
	void Logo();
};


class Bala {
	int x, y;
public:
	Bala(int _x, int _y): x(_x), y(_y){}
	void mover();

};
