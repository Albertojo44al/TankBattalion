
#include<conio.h>
#include<windows.h>
#include<stdio.h>


//Primer player
int xt = 50, yt = 40;//cordenadas de tanque
int dire = 0, diref = 0;//dereccion de tanque
int xb = 0, yb = 0;//cordenadas de bala de tanque
int xbn = 0, ybn = 0;//cordenadas de bala de enemigo1
int falb = 0;//actibador de bala
 //Segundo Player
int xp2 = 50, yp2 = 40;//cordenadas de tanque
int direp2 = 0, direfp2 = 0;//dereccion de tanque
int xbp2 = 0, ybp2 = 0;//cordenadas de bala de tanque
int falbp2 = 0;//actibador de bala

//Enemigos
int falbn = 0;//actibador de bala enemiga1
int xn = 6, yn = 10;//cordenadas de enemigo1
int diren = 0, direfn = 0;//direccion de enemigo1
int time = 0;//tienpo en mover enemigo
int xvi = 0;//mover aleatorio
int falbn2 = 0;//actibador de bala enemigo2
int xn2 = 80, yn2 = 10;//cordenadas de enemigo2
int xbn2 = 0, ybn2 = 0;//cordenadas de balas de enemigo2
int diren2 = 0, direfn2 = 0;//direccion de enemigo2
int tanques = 0;//tanques destruidos
int enemigos = 3;//tanques para destruir
int velo = 0;//velocidad de enemigos

//Datos Partida
int vidas = 3;
int level = 1;
int score = 0; // Puntuacion;

//Tank master
int xmt = 50, ymt = 20; //cordenadas Master tank
int diremt = 0, direfmt = 0; // direccion master tank
int falbmt = 0; // activador bala master tank;
int xbmt, ybmt; // cordenadas de bala master tank;
int vmt; // vida master Tank
int velomt = 0;
int tankMaster = 0; //cantidad vencidos
bool ExisteTankMaster = false;


boolean pause = true; //Pausa

boolean mina = true; // Minas

int Stats[10][2];//Stadisticas


HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);// Cambiar Color 

//menu de inicio

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


void dibujar() {
	//Tanque 1
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); {
		gotoxy(xt, yt);   printf("%c%c%c", 177, 223, 177);
	}
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); {
		//Tanque 2
		gotoxy(xn, yn);   printf("%c%c%c", 177, 254, 177);

		//Tanque 3
		gotoxy(xn2, yn2); printf("%c%c%c", 177, 254, 177);
	}
}




void Logo() {
	system("color 2");
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

void Logo2() {
	gotoxy(70, 5); printf("************ ************      ******       ************ ************ ");
	gotoxy(70, 6); printf("************ ************     ***  ***      ************ ************ ");
	gotoxy(70, 7); printf("***              ***         ***    ***         ***      ***          ");
	gotoxy(70, 8); printf("************     ***        ************        ***      ************ ");
	gotoxy(70, 9); printf("         ***     ***       **************       ***               *** ");
	gotoxy(70, 10);printf("************     ***      ***          ***      ***      ************ ");
	gotoxy(70, 11);printf("************     ***     ***            ***     ***      ************ ");
}

void inicio() {
	Logo();
	tankMaster = 0;
	level = 1;
	vidas = 3;
	tanques = 0;
	enemigos = 3;
	ExisteTankMaster = false;
	gotoxy(40, 20); printf("ARCADE");
	gotoxy(39, 22); printf("1P VS 2P");
	gotoxy(36, 24); printf(" ESTADISTICAS");
	gotoxy(40, 26); printf(" SALIR");
	gotoxy(38, 20); printf(">");
	sal = 1;


	do {
		tecla = _getch();
		if (tecla == 'w' && move2 == 0) {
			gotoxy(38, 20); printf(">");
			gotoxy(37, 22); printf(" ");
			gotoxy(35, 24); printf(" ");
			gotoxy(39, 26); printf(" ");
			pos = 1;
			move = 1;
		}
		else if (tecla == 's'&& move == 1 || tecla == 'w'&& move2 == 1) {
			gotoxy(38, 20); printf(" ");
			gotoxy(37, 22); printf(">");
			gotoxy(35, 24); printf(" ");
			gotoxy(39, 26); printf(" ");
			pos = 2;
			move = 2;
			move2 = 0;
		}
		else if (tecla == 's' && move == 2 || tecla == 'w' && move2 == 2) {
			gotoxy(38, 20); printf(" ");
			gotoxy(37, 22); printf(" ");
			gotoxy(35, 24); printf(">");
			gotoxy(39, 26); printf(" ");
			pos = 3;
			move2 = 1;
			move = 3;
		}
		else if (tecla == 's' && move == 3) {
			gotoxy(38, 20); printf(" ");
			gotoxy(37, 22); printf(" ");
			gotoxy(35, 24); printf(" ");
			gotoxy(39, 26); printf(">");
			pos = 4;
			move2 = 2;
		}
		if (tecla == ' ') {

			switch (pos) {
			case 1:
				sal = 2;
				vidas = 3;
				break;
			case 2:
				sal = 3;
				break;
			case 3:
				sal = 4;
				break;
			case 4:
				sal = 5;
				break;
			}
		}
	} while (sal == 1);
	system("cls");

}

void pintar() {
	level = 1;
	vidas = 3;
	int v = 3;
	system("color 3"); {
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

}
void nivel() {
	while (tankMaster == level)
	{
		tanques = 0;
		level++;
		if (level < 6)
		{
			gotoxy(40, 20); printf("NIVEL  %d", level);
			Sleep(1000);
			gotoxy(40, 20); printf("         ");
		}
		vidas++;
		if (level == 3 || level == 4) {
			enemigos += 1;
			break;
		}
	}
}

void borrar(int x, int y) {
	gotoxy(x, y); printf("     ");
	gotoxy(x, y + 1); printf("     ");

}

void morir(int x, int y) {
	
		borrar(x,y);
		gotoxy(x, y);     printf("  *  ");
		gotoxy(x, y + 1); printf("  *  ");
		Sleep(200);


		borrar(x,y);
		gotoxy(x, y);     printf("* * *");
		gotoxy(x, y + 1); printf("* * *");
		Sleep(200);


		borrar(x,y);

		gotoxy(x, y);     printf("*   *");
		gotoxy(x, y + 1); printf("*   *");
		Sleep(200);

		borrar(x,y);
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
void PuntuacionMasterTank() {
	if (level <= 2)
		score += 100;
	if (level > 2 && level <= 4)
		score += 250;
	if (level == 5)
		score += 500;
}

//Borrar
void Borrar() {
	gotoxy(xt, yt); printf("    ");
	gotoxy(xt, yt + 1); printf("    ");
}
void BorrarP2() {
	gotoxy(xp2, yp2); printf("    ");
	gotoxy(xp2, yp2 + 1); printf("    ");
}

void borrarn() {
	gotoxy(xn, yn); printf("    ");
	gotoxy(xn, yn + 1); printf("    ");
}

void borrarn2() {
	gotoxy(xn2, yn2); printf("    ");
	gotoxy(xn2, yn2 + 1); printf("    ");
}
void borrarmt() {
	gotoxy(xmt, ymt); printf("     ");
	gotoxy(xmt, ymt + 1); printf("     ");
}

//Minas
void minas(int x, int y) {
	gotoxy(x, y); printf("%c", 157);

	if (xt == x && yt == y || xt == x && yt + 1 == y || xt + 1 == x && yt == y || xt + 1 == x && yt + 1 == y || xt + 2 == x && yt == y || xt + 2 == x && yt + 1 == y || xt + 3 == x && yt == y || xt + 3 == x && yt + 1 == y) {
		morir(xt, yt);
		xt = 50;
		yt = 30;
		vidas--;
		gotoxy(xt, yt); printf("%c%c%c", 177, 223, 177);
	}
	if (xn == x && yn == y || xn == x && yn + 1 == y || xn + 1 == x && yn == y || xn + 1 == x && yn + 1 == y || xn + 2 == x && yn == y || xn + 2 == x && yn + 1 == y || xn + 3 == x && yn == y || xn + 3 == x && yn + 1 == y) {
		borrarn();
		tanques++;
		xn = 6;
		yn = 10;
		gotoxy(xn, yn); printf("%c%c%c", 177, 254, 177);

	}
	if (xn2 == x && yn2 == y || xn2 == x && yn2 + 1 == y || xn2 + 1 == x && yn2 == y || xn2 + 1 == x && yn2 + 1 == y || xn2 + 2 == x && yn2 == y || xn2 + 2 == x && yn2 + 1 == y || xn2 + 3 == x && yn2 == y || xn2 + 3 == x && yn2 + 1 == y) {
		borrarn2();
		tanques++;
		xn2 = 80;
		yn2 = 10;
		gotoxy(xn2, yn2); printf("%c%c%c", 177, 254, 177);
	}
}

//Direccion de las balas
void checabala() {
	//Validar contacto da enmigo 1
	if (xb == xn && yb == yn +1|| xb == xn  && yb == yn  ||xb == xn +3 && yb == yn + 1 || xb == xn + 3 && yb == yn || xb == xn + 1 && yb == yn + 1 || xb == xn + 1 && yb == yn || xb == xn + 2 && yb == yn + 1 || xb == xn + 2 && yb == yn) {
		tanques++;
		Puntuacion();
		
		borrarn();
			xn = 6;
			yn = 10;
			xb = 0;
			yb = 0;
			gotoxy(xn, yn); printf("%c%c%c", 177,254,177);

		
	}
	//Validar contacto a enemigo 2
	if (xb == xn2 && yb == yn2+1 ||xb == xn2 && yb == yn2 ||xb == xn2 + 3 && yb == yn2 + 1 || xb == xn2 + 3 && yb == yn2  || xb == xn2 + 1 && yb == yn2 + 1 || xb == xn2 + 1 && yb == yn2  || xb  == xn2 + 2 && yb == yn2 + 1 || xb  == xn2 + 2 && yb == yn2) {
		tanques++;
		Puntuacion();
		
		borrarn2();
			xn2 = 80;
			yn2 = 10;
			xb = 0;
			yb = 0;
			gotoxy(xn2, yn2); printf("%c%c%c", 177, 254, 177);
		
	}

	//Validar contacto a master Tank
	if (xb == xmt && yb == ymt + 1 || xb == xmt && yb == ymt || xb == xmt + 3 && yb == ymt + 1 || xb == xmt + 3 && yb == ymt || xb == xmt + 1 && yb == ymt + 1 || xb == xmt + 1 && yb == ymt || xb == xmt + 2 && yb == ymt + 1 || xb == xmt + 2 && yb == ymt) {			
		vmt--;
		borrarmt();
		xb = 0;
		yb = 0;
		if (vmt == 0) {
			morir(xmt, ymt);
			xmt = 50;
			ymt = 20;
			xbmt = 0;
			ybmt = 0;
			PuntuacionMasterTank();
			tankMaster++;
			ExisteTankMaster = false;
		}
	}

	//balas chocando
	if (xb == xbn && yb == ybn) {
		gotoxy(xb, yb); printf(" ");
		xb = 0;
		yb = 0;
		xbn = 0;
		ybn = 0;
	}	

	if (xb == xbn2 && yb == ybn2) {
		gotoxy(xb, yb); printf(" ");
		xb = 0;
		yb = 0;
		xbn2 = 0;
		ybn2 = 0;
	}

	if (xb == xbmt && yb == ybmt) {
		gotoxy(xb, yb); printf(" ");
		xb = 0;
		yb = 0;
		xbmt = 0;
		ybmt = 0;
	}

	//Validar contacto de enemigo
	if (xbn == xt && ybn == yt+1 || xbn == xt  && ybn == yt  ||xbn == xt+1 && ybn == yt + 1 || xbn == xt+1 && ybn == yt || xbn == xt + 2 && ybn == yt + 1 || xbn == xt + 2 && ybn == yt  || xbn == xt + +3 && ybn == yt + 1|| xbn == xt + 3 && ybn == yt ) {
		morir(xt,yt);
		xt = 50;
		yt = 40;
		gotoxy(xt, yt); printf("%c%c%c",177,223,177);
		vidas--;
		xbn = 0;
		ybn = 0;
	}
	if (xbn2 == xt && ybn2 == yt +1|| xbn2 == xt && ybn2 == yt ||xbn2 == xt +3 && ybn2 == yt + 1 || xbn2 == xt +3 && ybn2 == yt || xbn2 == xt + 1 && ybn2 == yt + 1 || xbn2 == xt + 1 && ybn2 == yt || xbn2 == xt + 2 && ybn2 == yt + 1 || xbn2 == xt + 2 && ybn2 == yt) {
		morir(xt,yt);
		xt = 50;
		yt = 40;
		gotoxy(xt, yt); printf("%c%c%c", 177, 223, 177);

		vidas--;
		xbn2 = 0;
		ybn2 = 0;
	}
	if (xbmt == xt && ybmt == yt + 1 || xbmt == xt && ybmt == yt || xbmt == xt + 3 && ybmt == yt + 1 || xbmt == xt + 3 && ybmt == yt || xbmt == xt + 1 && ybmt == yt + 1 || xbmt == xt + 1 && ybmt == yt || xbmt == xt + 2 && ybmt == yt + 1 || xbmt == xt + 2 && ybmt == yt) {
		morir(xt,yt);
		xt = 50;
		yt = 40;
		gotoxy(xt, yt); printf("%c%c%c", 177, 223, 177);

		vidas--;
		xbn2 = 0;
		ybn2 = 0;
	}
	
}

void movermt() {//Tanque enemigo2
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); {
		time++;
		if (time > 10) {
			time = 0;
			xvi = (rand() % 55) + 6;
		}
		velomt++;
		if (xvi > 30 && xvi < 40 && xmt < 90 && velomt == 5) {
			//borrar
			borrarmt();
			xmt++;
			diremt = 0;
			//dibujar
			gotoxy(xmt, ymt);     printf("%c%c%c>", 177,219, 177);
			
		}
		if (xvi > 20 && xvi < 30 && xmt > 4 && velomt == 5) {
			//borrar
			borrarmt();
			xmt--;
			diremt = 1;
			//dibujar
			gotoxy(xmt, ymt); printf("<%c%c%c", 177, 219, 177);
			
		}
		if (xvi > 10 && xvi < 19 && ymt < 40 && velomt == 5) {
			//borrar
			borrarmt();
			ymt++;
			diremt = 2;
			//dibujar
			gotoxy(xmt, ymt); printf("%c%c%c", 177, 219, 177);
			gotoxy(xmt, ymt + 1); printf(" v ");
		}
		if (xvi > 41 && xvi < 51 && ymt > 4 && velomt == 5) {
			//borrar
			borrarmt();
			ymt--;
			diremt = 3;
			//dibujar
			gotoxy(xmt, ymt); printf(" ^ ");
			gotoxy(xmt, ymt + 1); printf("%c%c%c", 177, 219, 177);
		}
		if (falbmt == 0) {
			if (diremt == 0) {
				xbmt = xmt + 5;
				ybmt = ymt + 1;
			}
			else {
				if (diremt == 1) {
					xbmt = xmt - 1;
					ybmt = ymt + 1;

				}
			}
			if (diremt == 2) {
				xbmt = xmt + 2;
				ybmt = ymt + 3;
			}
			else {
				if (diremt == 3) {
					xbmt = xmt + 2;
					ybmt = ymt - 1;
				}
			}
			falbmt = 1;
			direfmt = diremt;
		}
		if (velomt == 5) {
			velomt = 0;
		}
	}
}


void movern2() {//Tanque enemigo2
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); {
		velo++;
		if (xvi > 30 && xvi < 40 && xn2 < 90 && velo == 5) {
			//borrar
			borrarn2();
			xn2++;
			diren2 = 0;
			//dibujarw
			gotoxy(xn2, yn2); printf("%c%c%c>", 177, 254, 177);
		}
		if (xvi > 20 && xvi < 30 && xn2 > 4 && velo == 5) {
			//borrar
			borrarn2();
			xn2--;
			diren2 = 1;
			//dibujar
			gotoxy(xn2, yn2); printf("<%c%c%c", 177, 254, 177);
		}
		if (xvi > 10 && xvi < 19 && yn2 < 40 && velo == 5) {
			//borrar
			borrarn2();
			yn2++;
			diren2 = 2;
			//dibujar
			gotoxy(xn2, yn2); printf("%c%c%c", 177, 254, 177);
			gotoxy(xn2, yn2 + 1); printf(" v ");
		}
		if (xvi > 41 && xvi < 51 && yn2 > 4 && velo == 5) {
			//borrar
			borrarn2();
			yn2--;
			diren2 = 3;
			//dibujar
			gotoxy(xn2, yn2); printf(" ^ ");
			gotoxy(xn2, yn2 + 1); printf("%c%c%c", 177, 254, 177);
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
}



void balan() {
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); {
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
			gotoxy(xbn, ybn); printf("%c", 169);
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
}
void FinTanques() {
	gotoxy(xn, yn); printf("     ");
	gotoxy(xn, yn+1); printf("     ");

	gotoxy(xn2, yn2); printf("     ");
	gotoxy(xn2, yn2+1); printf("     ");

	gotoxy(xbn, ybn); printf(" ");
	gotoxy(xbn2, ybn2); printf(" ");

	
	xbn = 0;
	ybn = 0;
	xbn2 = 0;
	ybn2 = 0;

}

void balan2() {
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); {
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
			gotoxy(xbn2, ybn2); printf("%c", 169);
		}
		else {
			falbn2 = 0;
		}
	}
}
void balamt() {
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); {
		gotoxy(xbmt, ybmt); printf(" ");
		if (falbmt == 1 && xbmt < 93 && xbmt > 4 && ybmt > 4 && ybmt < 43) {
			if (direfmt == 0) {
				xbmt++;
			}
			else {
				if (direfmt == 1) {
					xbmt--;
				}
			}
			if (direfmt == 2) {
				ybmt++;
			}
			else {
				if (direfmt == 3) {
					ybmt--;
				}
			}
			gotoxy(xbmt, ybmt); printf("%c", 169);
		}
		else {
			falbmt = 0;
		}
	}
}


void movern() {//Tanque enemigo 1
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); {
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
			gotoxy(xn, yn); printf("<%c%c%c", 177, 254, 177);

		}
		if (xvi > 20 && xvi < 30 && xn < 90 && velo == 5) {
			//borrar
			borrarn();
			xn++;
			diren = 1;
			//dibujar
			gotoxy(xn, yn); printf("%c%c%c>", 177, 254, 177);
		}
		if (xvi > 10 && xvi < 19 && yn > 4 && velo == 5) {
			//borrar
			borrarn();
			yn--;
			diren = 2;
			//dibujar
			gotoxy(xn, yn); printf(" ^ ");
			gotoxy(xn, yn + 1); printf("%c%c%c", 177, 254, 177);

		}
		if (xvi > 41 && xvi < 51 && yn < 40 && velo == 5) {
			//borrar
			borrarn();
			yn++;
			diren = 3;
			//dibujar
			gotoxy(xn, yn); printf("%c%c%c", 177, 254, 177);
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
}

void bala() {
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); {
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
			gotoxy(xb, yb); printf("%c", 169);
		}
		else {
			falb = 0;
		}
	}
}



void mover() {
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); {
		if (_kbhit()) {
			unsigned char tecla = _getch();
			if (tecla == 'a' && xt > 4 ) {
				//borrar
				Borrar();
				xt--;
				dire = 1;
				//dibujar
				gotoxy(xt, yt); printf("<%c%c%c", 177, 223, 177);

			}
			else {
				if (tecla == 'd' && xt < 88 ) {
					Borrar();
					xt++;
					dire = 0;
					//dibujar
					gotoxy(xt, yt); printf("%c%c%c>", 177, 223, 177);

				}
			}

			if (tecla == 'w' && yt > 5) {
				Borrar();
				yt--;
				dire = 2;
				//dibujar
				gotoxy(xt, yt); printf(" ^ ");
				gotoxy(xt, yt + 1); printf("%c%c%c", 177, 223, 177);
			}
			else {
				if (tecla == 's' && yt < 43 ) {
					Borrar();
					yt++;
					dire = 3;
					//dibujar
					gotoxy(xt, yt); printf("%c%c%c", 177, 223, 177);
					gotoxy(xt, yt + 1); printf(" v ");
				}
			}
			if (tecla == 'p') {
				if (pause) {
				gotoxy(40, 20); printf("PAUSA");
				Sleep(5000);
				gotoxy(40, 20); printf("     ");
				}
			}
			if (tecla == '1') {
				sal = 1;
				vidas = -1;
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
}
void moverP2() {
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); {
		if (_kbhit) {
			unsigned char tecla2 = _getch();
			if (tecla2 == 'j' && xp2 > 4) {
				//borrar
				BorrarP2();
				xp2--;
				direp2 = 1;
				//dibujar
				gotoxy(xp2, yp2); printf("<%c%c%c", 177, 223, 177);

			}
			else {
				if (tecla2 == 'l' && xp2 < 88) {
					BorrarP2();
					xp2++;
					direp2 = 0;
					//dibujar
					gotoxy(xp2, yp2); printf("%c%c%c>", 177, 223, 177);

				}
			}

			if (tecla2 == 'i' && yp2 > 5) {
				BorrarP2();
				yp2--;
				direp2 = 2;
				//dibujar
				gotoxy(xp2, yp2); printf(" ^ ");
				gotoxy(xp2, yp2 + 1); printf("%c%c%c", 177, 223, 177);
			}
			else {
				if (tecla2 == 'k' && yp2 < 43) {
					BorrarP2();
					yp2++;
					direp2 = 3;
					//dibujar
					gotoxy(xp2, yp2); printf("%c%c%c", 177, 223, 177);
					gotoxy(xp2, yp2 + 1); printf(" v ");
				}
			}
			if (tecla2 == '0' && falbp2 == 0) {
				if (direp2 == 0) {
					xbp2 = xp2 + 5;
					ybp2 = yp2 + 1;
				}
				else {
					if (direp2 == 1) {
						xbp2 = xp2 - 1;
						ybp2 = yp2 + 1;
					}
				}
				if (direp2 == 2) {
					xbp2 = xp2 + 2;
					ybp2 = yp2 - 1;
				}
				else {
					if (direp2 == 3) {
						xbp2 = xp2 + 2;
						ybp2 = yp2 + 3;
					}
				}
				falbp2 = 1;
				direfp2 = direp2;
			}
		}
	}
}

void balaP2(){
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); {
		gotoxy(xbp2, ybp2); printf(" ");
		if (falbp2 == 1 && xbp2 < 93 && xbp2 > 4 && ybp2 > 4 && ybp2 < 43) {
			if (direfp2 == 0) {
				xbp2++;
			}
			else {
				if (direfp2 == 1) {
					xbp2--;
				}
			}
			if (direfp2 == 2) {
				ybp2--;
			}
			else {
				if (direfp2 == 3) {
					ybp2++;
				}
			}
			gotoxy(xbp2, ybp2); printf("%c", 169);
		}
		else {
			falbp2 = 0;
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


void OcultarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon, &cci);
	system("cls");
}

void RellenarStats() {
	for (int i = 0; i < 10; i++) {

		Stats[i][0] = i + 1;
		Stats[i][1] = 0;
	}
}
bool AgregarStats( int puntuacion) {
	for (int i = 0; i < 10; i++) { 

		if (Stats[i][1] == 0) {
			Stats[i][1] = puntuacion;
			return true;
		}
	}
	return false;
}

void ImprimirStats() {
	for (int horizotal = 0; horizotal < 30; horizotal++) {
		gotoxy(90 + horizotal, 15); printf("%c", 205);
		gotoxy(90 + horizotal, 35); printf("%c", 205);
		gotoxy(91, 18); printf("Posicion");
		gotoxy(112, 18); printf("Score");
	}
	for (int i = 0; i < 10; i++) {
		gotoxy(95, 20 + i); printf("%d \t\t  %d \n", Stats[i][0], Stats[i][1]);
	}
}


int main() {
	
	OcultarCursor();
	system("color 3");
	RellenarStats();
	while (sal != 5) {
		system("cls");
		
		inicio();
		Logo();
		
		while (sal == 2) {
			dibujar(); //dibuja el mapa
			pintar(); //pinta los tanques
			
			while (vidas > 0) {
				
				minas(15, 15);
				minas(45, 20);
				minas(27, 6);
				minas(60, 35);
				minas(12, 26);
				minas(80, 7);
				
				nivel(); //verifica el nivel
				checabala();
				marcador();
				xvi -= 3;
				if (tanques != enemigos || level == tankMaster) {	//verifica la cantidad de enemigos				
					movern();
					movern2();
					balan();
					balan2();
					vmt = 3;
				}
				if (tanques == enemigos) { // aparicion de master tank
					
					FinTanques(); // borrar los tanques enemigos excepto el  master
					ExisteTankMaster = true;
						
				}
				if(ExisteTankMaster)
				{
					movermt();
					balamt();
				}
				mover();
				bala();
				checabala();
				Sleep(40);
				if (vidas == 0 || level ==6) {
					AgregarStats(score);
					sal = 1;
					score = 0;
					tanques = 0;
					enemigos = 0;
					vidas = 0;
					gotoxy(40, 20); printf("GAME OVER");
					Sleep(1000);
					gotoxy(40, 20); printf("          ");
				}

			}
		}
		//Dos players
		while (sal == 3) {
			pintar();
			while (sal == 3) {
				checabala();
				mover();
				bala();
				moverP2();
				balaP2();
				
			}
		}

		//Estadistias
		while (sal == 4) {
			system("cls");
			while (sal == 4) {
				Logo2();
				 ImprimirStats();
				if (_kbhit()) {
					unsigned char tecla = _getch();
					if (tecla == '1') {
						sal = 1;
					}
				}
			}
		}
	}
}