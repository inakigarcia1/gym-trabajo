#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef int semanal[2] = {0, 0};
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
	semanal actividadYTurno[2][6];
	char rutina[1000];
};

struct Turno{
	horarios entrenadorYAct[2][6];
};
