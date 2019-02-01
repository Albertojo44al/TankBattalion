#include <Windows.h>
#include <iostream>



class Mapa {
	
	int x, y;//cordenadas tanque 1
	int vidas;//vidas tanque 1
	int x2, y2;//cordenadas tanque 2
	int vidas2;// vidas tanque 2
public:
	int pos = 1, sal = 1, tecla;
	class Mapa(int _x, int _y, int _vidas): x(_x),y(_y),vidas(_vidas){}
	class Mapa(){}
	void gotoxy(int, int);
	
	//Tanque
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
};