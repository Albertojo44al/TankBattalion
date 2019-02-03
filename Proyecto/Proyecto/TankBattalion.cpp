//tenquer

#include<conio.h>
#include<windows.h>
#include<stdio.h>

int a, d, w, s, l;//teclas
int xt = 25, yt = 11;//cordenadas de tanque
int dire = 0, diref = 0;//dereccion de tanque
int xb = 0, yb = 0;//cordenadas de bala de tanque
int xbn = 0, ybn = 0;//cordenadas de bala de enemigo1
int falb = 0;//actibador de bala
int falbn = 0;//actibador de bala enemiga1
int xn = 8, yn = 18;//cordenadas de enemigo1
int diren = 0, direfn = 0;//direccion de enemigo1
int time = 0;//tienpo en mover enemigo
int xvi = 0;//mover aleatorio
int falbn2 = 0;//actibador de bala enemigo2
int xn2 = 45, yn2 = 4;//cordenadas de enemigo2
int xbn2 = 0, ybn2 = 0;//cordenadas de balas de enemigo2
int diren2 = 0, direfn2 = 0;//direccion de enemigo2
int tanques = 0;//tanques destruidos
int enemigos = 3;//tanques para destruir
int vidas = 5;
int velo = 0;//velocidad de enemigos
int level = 1;
int score = 0; // Puntuacion;

//menu de inicio
int xp, yp;
int sal = 1;
int tecla;
int pos = 1;
int move = 1, move2 = 0;

void gotoxy(int x, int y) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;
	SetConsoleCursorPosition(hcon, dwpos);
}
void Logo() {
	gotoxy(120, 15); printf(" ************       ******       ******      ***  ***    ***   ");
	gotoxy(120, 16); printf(" ************      ***  ***      *** ***     ***  ***   ***    ");
	gotoxy(120, 17); printf("     ***          ***    ***     ***  ***    ***  *******      ");
	gotoxy(120, 18); printf("     ***         ************    ***   ***   ***  *******      ");
	gotoxy(120, 19); printf("     ***        **************   ***    ***  ***  ***   ***    ");
	gotoxy(120, 20); printf("     ***       ***          ***  ***     *** ***  ***    ***   ");
	gotoxy(120, 21); printf("     ***      ***            *** ***      ******  ***     ***  ");

	gotoxy(115, 23); printf(" *********         ******       ************ ************ ***          ************ ");
	gotoxy(115, 24); printf(" ***    ***       ***  ***      ************ ************ ***          ************ ");
	gotoxy(115, 25); printf(" ***   ***       ***    ***         ***          ***      ***          ***          ");
	gotoxy(115, 26); printf(" ********       ************        ***          ***      ***          *********    ");
	gotoxy(115, 27); printf(" ***   ***     **************       ***          ***      ***          ***          ");
	gotoxy(115, 28); printf(" ***    ***   ***          ***      ***          ***      ************ ************ ");
	gotoxy(115, 29); printf(" *********   ***            ***     ***          ***      ************ ************ ");
}

void inicio() {
	Logo();
	level = 1;
	vidas = 5;
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
			pos = 3;
			move2 = 1;
		}
		if (tecla == ' ') {
			if (pos == 1) {
				sal = 2;
				vidas = 5;
			}
			else {
				if (pos = 3) {
					sal = 5;
				}
			}
		}
	} while (sal == 1);
	system("cls");

}


void nivel() {
	if (enemigos == tanques) {
		tanques = 0;
		level++;
		vidas++;
		if(level == 2 || level == 4)
			enemigos += 1;
	}
}

void borrar() {
	gotoxy(xt, yt - 1); printf("     ");
	gotoxy(xt, yt); printf("     ");
	gotoxy(xt, yt + 1); printf("     ");

}
void morir() {
	
		borrar();
		gotoxy(xt, yt - 1); printf("  *  ");
		gotoxy(xt, yt);     printf(" *** ");
		gotoxy(xt, yt + 1); printf("  *  ");
		Sleep(200);


		borrar();
		gotoxy(xt, yt - 1); printf("  ** ");
		gotoxy(xt, yt);     printf(" ****");
		gotoxy(xt, yt + 1); printf("  ** ");
		Sleep(200);


		borrar();
		gotoxy(xt, yt - 1); printf("* * *");
		gotoxy(xt, yt);     printf(" *** ");
		gotoxy(xt, yt + 1); printf("* * *");
		Sleep(200);

		borrar();
}

void Puntuacion() {
	if (level == 1)
		score += 30;
	if (level == 2)
		score += 60;
	if (level == 3)
		score += 120;
	if (level == 4)
		score += 180;
	if (level == 5)
		score += 360;
}

//Borrar
void Borrar() {
	gotoxy(xt, yt); printf("    ");
	gotoxy(xt, yt + 1); printf("    ");

}

void borrarn() {
	gotoxy(xn, yn); printf("    ");
	gotoxy(xn, yn + 1); printf("    ");
}

void borrarn2() {
	gotoxy(xn2, yn2); printf("    ");
	gotoxy(xn2, yn2 + 1); printf("    ");
}
//Direccion de las balas
void checabala() {
	if (xb == xn && yb == yn +1|| xb == xn  && yb == yn  ||xb == xn +3 && yb == yn + 1 || xb == xn + 3 && yb == yn || xb == xn + 1 && yb == yn + 1 || xb == xn + 1 && yb == yn || xb == xn + 2 && yb == yn + 1 || xb == xn + 2 && yb == yn) {
		tanques++;
		Puntuacion();

		borrarn();
			xn = 10;
			yn = 18;
			xb = 0;
			yb = 0;
			gotoxy(xn, yn); printf("%c%c%c", 219,177,219);

		
	}
	if (xb == xn2 && yb == yn2+1 ||xb == xn2 && yb == yn2 ||xb == xn2 + 3 && yb == yn2 + 1 || xb == xn2 + 3 && yb == yn2  || xb == xn2 + 1 && yb == yn2 + 1 || xb == xn2 + 1 && yb == yn2  || xb  == xn2 + 2 && yb == yn2 + 1 || xb  == xn2 + 2 && yb == yn2) {
		tanques++;
		Puntuacion();
		
		borrarn2();
			xn2 = 45;
			yn2 = 18;
			xb = 0;
			yb = 0;
			gotoxy(xn2, yn2); printf("%c%c%c",219,177,219);
		
	}
	if (xb == xbn && yb == ybn) {
		gotoxy(xb, yb); printf(" ");
		xb = 0;
		yb = 0;
		xbn = 0;
		ybn = 0;
	}
	else {
		if (xb == xbn2 && yb == ybn2) {
			gotoxy(xb, yb); printf(" ");
			xb = 0;
			yb = 0;
			xbn2 = 0;
			ybn2 = 0;
		}
	}
	if (xbn == xt && ybn == yt+1 || xbn == xt  && ybn == yt  ||xbn == xt+1 && ybn == yt + 1 || xbn == xt+1 && ybn == yt || xbn == xt + 2 && ybn == yt + 1 || xbn == xt + 2 && ybn == yt  || xbn == xt + +3 && ybn == yt + 1|| xbn == xt + 3 && ybn == yt ) {
		morir();
		xt = 25;
		yt = 11;
		gotoxy(xt, yt); printf("%c%c%c",177,219,177);
		vidas--;
		xbn = 0;
		ybn = 0;
	}
	else {
		if (xbn2 == xt && ybn2 == yt +1|| xbn2 == xt && ybn2 == yt ||xbn2 == xt +3 && ybn2 == yt + 1 || xbn2 == xt +3 && ybn2 == yt || xbn2 == xt + 1 && ybn2 == yt + 1 || xbn2 == xt + 1 && ybn2 == yt || xbn2 == xt + 2 && ybn2 == yt + 1 || xbn2 == xt + 2 && ybn2 == yt) {
			morir();
			xt = 25;
			yt = 11;
			gotoxy(xt, yt); printf("%c%c%c", 177, 219, 177);

			vidas--;
			xbn2 = 0;
			ybn2 = 0;
		}
	}
}

void marcador() {
	gotoxy(96, 4); printf("TANQUES DESTRUIDOS");
	gotoxy(96, 5); printf("%02i/%02i", tanques, enemigos);
	gotoxy(96, 7); printf("VIDAS");
	gotoxy(95, 8); printf(" %02i", vidas);
	gotoxy(96, 10); printf("NIVEL");
	gotoxy(96, 11); printf("%02i", level);
	gotoxy(96, 13); printf("PUNTUACION");
	gotoxy(96, 14); printf("%02i", score);
}

void movern2() {//Tanque enemigo2
	velo++;
	if (xvi > 30 && xvi < 40 && xn2 < 90 && velo == 5) {
		//borrar
		borrarn2();
		xn2++;
		diren2 = 0;
		//dibujarw
		gotoxy(xn2, yn2); printf("%c%c%c>", 219, 177, 219);
	}
	if (xvi > 20 && xvi < 30 && xn2 > 4 && velo == 5) {
		//borrar
		borrarn2();
		xn2--;
		diren2 = 1;
		//dibujar
		gotoxy(xn2, yn2); printf("<%c%c%c", 219, 177, 219);
	}
	if (xvi > 10 && xvi < 19 && yn2 < 40 && velo == 5) {
		//borrar
		borrarn2();
		yn2++;
		diren2 = 2;
		//dibujar
		gotoxy(xn2, yn2); printf("%c%c%c", 219, 177, 219);
		gotoxy(xn2, yn2 + 1); printf(" v ");
	}
	if (xvi > 41 && xvi < 51 && yn2 > 4 && velo == 5) {
		//borrar
		borrarn2();
		yn2--;
		diren2 = 3;
		//dibujar
		gotoxy(xn2, yn2); printf(" ^ ");
		gotoxy(xn2, yn2+1); printf("%c%c%c", 219, 177, 219);
	}
	if (falbn2 == 0) {
		if (diren2 == 0) {
			xbn2 = xn2 + 5;
			ybn2 = yn2 + 1;
		}
		else {
			if (diren2 == 1) {
				xbn2 = xn2 - 1;
				ybn2 = yn2 + 1;

			}
		}
		if (diren == 2) {
			xbn2 = xn2 + 2;
			ybn2 = yn2 + 3;
		}
		else {
			if (diren2 == 3) {
				xbn2 = xn2 + 2;
				ybn2 = yn2 - 1;
			}
		}
		falbn2 = 1;
		direfn2 = diren2;
	}
	if (velo == 5) {
		velo = 0;
	}
}

void divut() {
	//Tanque 1
	gotoxy(xt, yt);   printf("%c%c%c", 177,219,177);
	
	//Tanque 2
	gotoxy(xn, yn);   printf("%c%c%c", 219, 177, 219);
	
	//Tanque 3
	gotoxy(xn2, yn2); printf("%c%c%c", 219, 177, 219);
	
}

void balan() {
	gotoxy(xbn, ybn); printf(" ");
	if (falbn == 1 && xbn < 93 && xbn > 4 && ybn > 4 && ybn < 43) {
		if (direfn == 0) {
			xbn--;
		}
		else {
			if (direfn == 1) {
				xbn++;
			}
		}
		if (direfn == 2) {
			ybn--;
		}
		else {
			if (direfn == 3) {
				ybn--;
			}
		}
		gotoxy(xbn, ybn); printf("%c",169);
	}
	else {
		falbn = 0;
	}
	if (xbn == xbn2 && ybn - 1 == ybn2 || xbn == xbn2 && ybn + 1 == ybn2 || xbn == xbn2 && ybn == ybn2) {
		gotoxy(xbn, ybn); printf(" ");
		xbn = 0;
		ybn = 0;
		xbn2 = 0;
		ybn2 = 0;
	}
}

void balan2() {
	gotoxy(xbn2, ybn2); printf(" ");
	if (falbn2 == 1 && xbn2 < 93 && xbn2 > 4 && ybn2 > 4 && ybn2 < 43) {
		if (direfn2 == 0) {
			xbn2++;
		}
		else {
			if (direfn2 == 1) {
				xbn2--;
			}
		}
		if (direfn2 == 2) {
			ybn2++;
		}
		else {
			if (direfn2 == 3) {
				ybn2--;
			}
		}
		gotoxy(xbn2, ybn2); printf("%c",169);
	}
	else {
		falbn2 = 0;
	}
}



void movern() {//Tanque enemigo 1
	int posi = 0;//para donde moverme 
	time++;
	if (time > 10) {
		time = 0;
		xvi = (rand() % 70) + 6;
	}
	velo++;
	if (xvi > 30 && xvi < 40 && xn > 5 && velo == 5) {
		//borrar
		borrarn();
		xn--;
		diren = 0;
		//dibujar
		gotoxy(xn, yn); printf("<%c%c%c", 219,177,219);
		
	}
	if (xvi > 20 && xvi < 30 && xn < 90 && velo == 5) {
		//borrar
		borrarn();
		xn++;
		diren = 1;
		//dibujar
		gotoxy(xn, yn); printf("%c%c%c>", 219, 177, 219);
	}
	if (xvi > 10 && xvi < 19 && yn > 4 && velo == 5) {
		//borrar
		borrarn();
		yn--;
		diren = 2;
		//dibujar
		gotoxy(xn, yn); printf(" ^ ");
		gotoxy(xn, yn+1); printf("%c%c%c", 219, 177, 219);
		
	}
	if (xvi > 41 && xvi < 51 && yn < 40 && velo == 5) {
		//borrar
		borrarn();
		yn++;
		diren = 3;
		//dibujar
		gotoxy(xn, yn ); printf("%c%c%c", 219, 177, 219);
		gotoxy(xn, yn + 1); printf(" v ");
	}
	if (falbn == 0) {
		if (diren == 0) {
			xbn = xn - 2;
			ybn = yn + 1;
		}
		else {
			if (diren == 1) {
				xbn = xn + 5;
				ybn = yn + 1;

			}
		}
		if (diren == 2) {
			xbn = xn + 2;
			ybn = yn - 1;
		}
		else {
			if (diren == 3) {
				xbn = xn + 2;
				ybn = yn + 3;
			}
		}
		falbn = 1;
		direfn = diren;
	}
	if (velo == 5) {
		velo = 0;
	}
}

void bala() {

	gotoxy(xb, yb); printf(" ");
	if (falb == 1 && xb < 93 && xb > 4 && yb > 4 && yb < 43) {
		if (diref == 0) {
			xb++;
		}
		else {
			if (diref == 1) {
				xb--;
			}
		}
		if (diref == 2) {
			yb--;
		}
		else {
			if (diref == 3) {
				yb++;
			}
		}
		gotoxy(xb, yb); printf("%c",169);
	}
	else {
		falb = 0;
	}
}



void mover() {
	if (_kbhit()) {
		unsigned char tecla = _getch();
		if (tecla == 'a' && xt > 4) {
			//borrar
			Borrar();
			xt--;
			dire = 1;
			//dibujar
			gotoxy(xt, yt); printf("<%c%c%c",177,219,177);
			
		}
		else {
			if (tecla == 'd' && xt < 89) {
				Borrar();
				xt++;
				dire = 0;
				//dibujar
				gotoxy(xt, yt); printf("%c%c%c>", 177,219,177);
				
			}
		}

		if (tecla == 'w' && yt > 4) {
			Borrar();
			yt--;
			dire = 2;
			//dibujar
			gotoxy(xt, yt); printf(" ^ ");
			gotoxy(xt, yt + 1); printf("%c%c%c",177,219,177);
		}
		else {
			if (tecla == 's' && yt < 43) {
				Borrar();
				yt++;
				dire = 3;
				//dibujar
				gotoxy(xt, yt); printf("%c%c%c", 177, 219, 177);
				gotoxy(xt, yt + 1); printf(" v ");
			}
		}
		if (tecla == ' ' && falb == 0) {
			if (dire == 0) {
				xb = xt + 5;
				yb = yt + 1;
			}
			else {
				if (dire == 1) {
					xb = xt - 1;
					yb = yt + 1;
				}
			}
			if (dire == 2) {
				xb = xt + 2;
				yb = yt - 1;
			}
			else {
				if (dire == 3) {
					xb = xt + 2;
					yb = yt + 3;
				}
			}
			falb = 1;
			diref = dire;
		}
	}//fin if
}

void pintar() {
	int v = 3;

	for (int i = 2; i < 95; i++) {
		v++;
		//pintar horizontal
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 45); printf("%c", 205);
		//pintar vertical
		if (v < 45) {
			gotoxy(2, v); printf("%c", 186);
			gotoxy(94, v); printf("%c", 186);
		}
	}
	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 45); printf("%c", 200);
	gotoxy(94, 3); printf("%c", 187);
	gotoxy(94, 45); printf("%c", 188);
}
void OcultarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon, &cci);
	system("cls");
}

int main() {
	OcultarCursor();
	system("color 0a");
	while (sal != 5) {
		system("cls");
		
		inicio();
		Logo();
		while (sal == 2) {
			divut();
			pintar();
			while (vidas > 0) {
				nivel();
				checabala();
				marcador();
				xvi -= 3;
				movern();
				movern2();
				mover();
				balan();
				balan2();
				bala();
				Sleep(40);
				if (vidas == 0 || level ==6) {
					sal = 1;
					score = 0;
					tanques = 0;
					enemigos = 0;
					vidas = 0;
				}

			}
		}
	}
}