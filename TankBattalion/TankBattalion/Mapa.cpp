#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Mapa.h"

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27


using namespace std;

void gotoxy(int x, int y) {
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}
int Mapa:: X(){
	return this->y;
}
int Mapa::Y() {
	return this->y;
}

void Mapa::MarcarMapa() {
	//lineas horziontales
	for (int i = 2; i <= 110; i++) {
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 44); printf("%c", 205);
	}
	// lineas verticales
	for (int i = 4; i <= 43; i++) {
		gotoxy(2, i); printf("%c", 186);
		gotoxy(110, i); printf("%c", 186);
	}
	// esquinas
	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 44); printf("%c", 200);
	gotoxy(110, 3); printf("%c", 187);
	gotoxy(110, 44); printf("%c", 188);

}

void Mapa::Pintar(char tecla) {
	switch (tecla) {
	case 'a':
		gotoxy(x, y); printf("<%c%c%c", 177, 219, 177);
		break;
	case 'd':
		gotoxy(x, y); printf("%c%c%c>", 177, 219, 177);
		break;
	case 's':
		gotoxy(x + 1, y + 1); printf("v");
		gotoxy(x, y); printf("%c%c%c", 177, 219, 177);
		break;
	case 'w':
		gotoxy(x, y); printf("%c%c%c", 177, 219, 177);
		gotoxy(x + 1, y - 1); printf("^");
		break;
	default:
		gotoxy(x, y); printf("%c%c%c", 177, 219, 177);
		break;
	}
}

void Mapa::borrar() {
	gotoxy(x - 1, y + 1); printf("      ");
	gotoxy(x - 1, y);     printf("      ");
	gotoxy(x - 1, y - 1); printf("      ");
}

void Mapa::OcultarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon, &cci);
}
void Mapa::Mover() {

	if (_kbhit()) {
		unsigned char tecla = _getch();
		borrar();
		if (tecla == 'a') {
			Pintar(tecla);
			if (x > 4)
				x--;
		}
		else if (tecla == 'd') {
			Pintar(tecla);
			if ((x + 4) < 109)
				x++;
		}
		else if (tecla == 's') {
			Pintar(tecla);
			if ((y + 1) < 43)
				y++;

		}
		else if (tecla == 'w') {
			Pintar(tecla);
			if ((y - 1) > 4)
				y--;
		}
		else if (tecla == 'e') {
			vidas--;
			Pintar(tecla);
		}
		else {
			Pintar(tecla);
		}
	}
	Sleep(40);
}
void Mapa::Mover2Player() {

	if (_kbhit()) {
		unsigned char tecla2 = _getch();
		borrar();
		if (tecla2 == IZQUIERDA) {
			x--;
			gotoxy(x, y); printf("<%c%c%c", 177, 219, 177);
		}
		if (tecla2 == DERECHA) {
			x++;
			gotoxy(x, y); printf("%c%c%c>", 177, 219, 177);
		}
		if (tecla2 == ABAJO) {
			y++;
			gotoxy(x + 1, y + 1); printf("v");
			gotoxy(x, y); printf("%c%c%c", 177, 219, 177);
		}
		if (tecla2 == ARRIBA) {
			y--;
			gotoxy(x, y); printf("%c%c%c", 177, 219, 177);
			gotoxy(x + 1, y - 1); printf("^");
		}

	}
	Sleep(40);
}


void Mapa::Vidas() {
	gotoxy(112, 8); printf("VIDAS");

	for (int i = 0; i < vidas; i++) {
		gotoxy(112 + i, 9); printf("%c ", 155);
	}
}

void Mapa::morir() {
	if (vidas == 0) {
		borrar();
		gotoxy(x, y - 1); printf("  *  ");
		gotoxy(x, y);     printf(" *** ");
		gotoxy(x, y + 1); printf("  *  ");
		Sleep(200);


		borrar();
		gotoxy(x, y - 1); printf("  ** ");
		gotoxy(x, y);     printf(" ****");
		gotoxy(x, y + 1); printf("  ** ");
		Sleep(200);


		borrar();
		gotoxy(x, y - 1); printf("* * *");
		gotoxy(x, y);     printf(" *** ");
		gotoxy(x, y + 1); printf("* * *");
		Sleep(200);

		borrar();
		Pintar('a');
		vidas = 3;

	}
}
void Mapa::Marcador() {
	gotoxy(112, 5); printf("TANQUES DESTRUIDOS");
	gotoxy(112, 6); printf("%02i/%02i", 0, 0);
	Vidas();
	gotoxy(112, 11); printf("NIVEL");
	gotoxy(112, 12); printf("%02i", 0);
}
void Mapa::Inicio() {

	gotoxy(40, 20); printf("INICIAR");
	gotoxy(36, 22); printf(" ESTADISTICAS");
	gotoxy(40, 24); printf(" SALIR");
	gotoxy(38, 20); printf(">");
	sal = 1;


	do {
		tecla = _getch();
		if (tecla == 'w' && move2 == 0) {
			gotoxy(38, 20); printf(">");
			gotoxy(35, 22); printf(" ");
			gotoxy(39, 24); printf(" ");
			pos = 1;
			move = 1;
		}
		else if (tecla == 's'&& move == 1 || tecla == 'w'&& move2 == 1) {
			gotoxy(38, 20); printf(" ");
			gotoxy(35, 22); printf(">");
			gotoxy(39, 24); printf(" ");
			pos = 2;
			move = 2;
			move2 = 0;
		}
		else if (tecla == 's' && move == 2) {
			gotoxy(38, 20); printf(" ");
			gotoxy(35, 22); printf(" ");
			gotoxy(39, 24); printf(">");
			pos = 2;
			move2 = 1;
		}
		if (tecla == ' ') {
			if (pos == 1) {
				sal = 2;
				vidas = 5;
			}
			else {
				if (pos = 2) {
					sal = 5;
				}
			}
		}
	} while (sal == 1);
	system("cls");

}
