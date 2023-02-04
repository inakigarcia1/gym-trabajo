#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#include <conio.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>

using namespace std;

typedef int horarios[3];

int marcelo = 91218;
int ramon = 24514;
int martin = 61122;
int hernan = 26696;
int pablo = 65723;

struct fec {
	int dia;
	int mes;
	int anio;
};

struct Usuario {
	char nombreUsuario[1000];
	char contrasena[1000];
	char nombre[60];
	int tipoDeUser;
};

struct Entrenador {
	char nombre[60];
	int nroEntrenador;
	char contrasena[1000];
};

struct Socio {
	char apeNom[60];
	char domicilio[60];
	int dni;
	fec ingreso;
	float altura;
	float peso;
	int nroSocio;
	int edad;
	int telefono;
	horarios actividadYTurno[2][6];
	char rutina[10000];
	int restringido[3];
};

struct Turno {
	horarios entrenadorYAct[2][6];
};

void corregirConsola() {

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

//	 // get handle to the console window
//    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // retrieve screen buffer info
//    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
//    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
//
//    // current window size
//    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
//    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;
//
//    // current screen buffer size
//    short scrBufferWidth = scrBufferInfo.dwSize.X;
//    short scrBufferHeight = scrBufferInfo.dwSize.Y;
//
//    // to remove the scrollbar, make sure the window height matches the screen buffer height
//    COORD newSize;
//    newSize.X = scrBufferWidth;
//    newSize.Y = winHeight;
//
//    // set the new screen buffer dimensions
//    int Status = SetConsoleScreenBufferSize(hOut, newSize);
//    if (Status == 0)
//    {
//        exit(Status);
//    }
//
//	ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);

}

void login(char contrasena[32]) {

	char a;

	for(int i = 0;;) {

		a = getch();

		if(isdigit(a) or isalpha(a)) {

			contrasena[i] = a;
			++i;
			cout<<"*";

		}

		if(a == '\b' and i >= 1) {

			cout<<"\b \b";
			--i;

		}

		if(a == '\r') {
			contrasena[i]='\0';
			break;
		}

	}
}

void error() {
	system("color 4");
	Sleep(500);
	system("color 9");
	Sleep(500);
	system("color 4");
	Sleep(500);
	system("color 9");
}

void correct() {
	system("color 2");
	Sleep(500);
	system("color 9");
	Sleep(500);
	system("color 2");
	Sleep(500);
	system("color 9");
}

enum IN {
	IN_BACK = 8,
	IN_RET = 13

};

string dia(int numDia) {
	if(numDia == 0) return "Lunes";
	if(numDia == 1) return "Martes";
	if(numDia == 2) return "Miercoles";
	if(numDia == 3) return "Jueves";
	if(numDia == 4) return "Viernes";
	if(numDia == 5) return "Sabado";
}

string obtenerNombre(int id) {
	if(id == 0) return "Marcelo Gallardo";
	if(id == 1) return "Ramon Diaz";
	if(id == 2) return "Martin Demichelis";
	if(id == 3) return "Hernan Crespo";
	if(id == 4) return "Pablo Aimar";
}

int obtenerLegajo(int id) {
	if(id == 0) return marcelo;
	if(id == 1) return ramon;
	if(id == 2) return martin;
	if(id == 3) return hernan;
	if(id == 4) return pablo;
}

string showName(int id){
	if(id == marcelo) return "Marcelo Gallardo";
	if(id == ramon) return "Ramon Diaz";
	if(id == martin) return "Martin Demichelis";
	if(id == hernan) return "Hernan Crespo";
	if(id == pablo) return "Pablo Aimar";
}

void leer(int &op, int valor){
	
	if(scanf("%d", &op) != 1){
		op = valor;
		_flushall();
	}
}

void leerF(float &op, float valor){
	
	if(scanf("%f", &op) != 1){
		op = valor;
		_flushall();
	}
}
