
#include "Mapa.h"
#include <iostream>
#include <conio.h>

void Bala::mover() {
	gotoxy(x, y); printf(" ");
	if (y > 4)y--;
	gotoxy(x, y); printf("%c", 254);
}