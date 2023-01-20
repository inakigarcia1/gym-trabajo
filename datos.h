#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

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
	int actividad[3];
	char rutina[1000];
};

struct Turno{
	int entrenador;
	int horario[2];
	int nroSocio;
	int diaTurno[6];
};
