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

struct fec{
	int dia;
	int mes;
	int anio;
};

struct Usuario{
	char nombreUsuario[10];
	char contrasena[10];
	char nombre[60];
	int tipoDeUser;
};

struct Entrenador{
	char nombre[60];
	int dia[6];
	int nroEntrenador;
	char contrasena[10];
	int horario[6];
	int actividad;
};

struct Socio{
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
};

struct Turno{
	horarios entrenadorYAct[2][6];
};

void corregirConsola(){
	
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

void login(){
	int ch;
	
	string user, pass;
	
	printf(" - Usuario: ");
	cin>>user;
	printf(" - Contrasena: ");
	
	ch = getch();
	
	while(ch != 13){
		pass.push_back(ch);
		cout<<'*';
		ch = getch();
	}
	
	if(user == "hola" and pass == "hola1") printf("Entraste.");
}

void error(){
	system("color 4");Sleep(500);
	system("color 9");Sleep(500);
	system("color 4");Sleep(500);
	system("color 9");
}

void correct(){
	system("color 2");Sleep(500);
	system("color 9");Sleep(500);
	system("color 2");Sleep(500);
	system("color 9");
}
