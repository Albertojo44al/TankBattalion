#include <windows.h>
#include <iostream>
#include <conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

void gotoxy(int x, int y) {
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}
void pintar() {
	//lineas horziontales
	for (int i = 2; i <= 95; i++) {
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 27); printf("%c", 205);
	}
	// lineas verticales
	for (int i = 4; i <= 26; i++){
		gotoxy(2, i); printf("%c", 186);
		gotoxy(95, i); printf("%c", 186);
	}
	// esquinas
	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 27); printf("%c", 200);
	gotoxy(95, 3); printf("%c", 187);
	gotoxy(95, 27); printf("%c", 188);

}

int main(){

	pintar();
	_getch();
	return 0;
}