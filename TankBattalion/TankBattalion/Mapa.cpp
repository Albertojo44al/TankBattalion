#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Mapa.h"

using namespace std;
void Mapa::gotoxy(int x, int y) {
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

void Mapa::MarcarMapa() {
	//lineas horziontales
	for (int i = 2; i <= 95; i++) {
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 27); printf("%c", 205);
	}
	// lineas verticales
	for (int i = 4; i <= 26; i++) {
		gotoxy(2, i); printf("%c", 186);
		gotoxy(95, i); printf("%c", 186);
	}
	// esquinas
	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 27); printf("%c", 200);
	gotoxy(95, 3); printf("%c", 187);
	gotoxy(95, 27); printf("%c", 188);

}

void Mapa::Mover() {
	if (_kbhit()) {
		unsigned char tecla = _getch();

	}
}

void Mapa::Marcador() {
	gotoxy(97, 5); printf("TANQUES DESTRUIDOS");
	gotoxy(97, 6); printf("%02i/%02i", 0, 0);
	gotoxy(97, 8); printf("VIDAS");
	gotoxy(96, 9); printf(" %02i", 0);
	gotoxy(97, 11); printf("NIVEL");
	gotoxy(97, 12); printf("%02i", 0);
}

