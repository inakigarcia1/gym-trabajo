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
};

struct Entrenador{
	char nombre[60];
	int dia[6];
	int nroEntrenador;
	char contrasena[10];
	int horario[6];
	int actividadd;
};

struct Socio{
	char nombre[60];
	char apellido[60];
	char domicilio[60];
	int dni;
	fec ingreso;
	float altura;
	float peso;
	int nroSocio;
	int edad;
	int telefono;
	int actividad;
	int horario;
	int entrenador;
};

struct Turno{
	int nroEntrenador;
	fec fechaTurno;
	int nroSocio;
	int diaTurno;
};

void registrarUsuario(FILE *usuarios);
void registrarEntrenadores(FILE *entrenadores);
void registrarSocio(FILE *socios);
void registrarTurnos(FILE *turnos);

main(){
	
	FILE *usuarios = fopen("Usuarios.dat", "w+b");
	FILE *entrenadores = fopen("Entrenadores.dat", "w+b");
	FILE *socios = fopen ("Socios.dat", "w+b");
	FILE *turnos = fopen("Turnos.dat", "w+b");
	
	registrarEntrenadores(entrenadores);
	registrarUsuario(usuarios);
	registrarSocio(socios);
	registrarTurnos(turnos);
	
	printf("\n\nDatos creados. ");
	fclose(usuarios);
	fclose(entrenadores);
	fclose(socios);
	fclose(turnos);
	system("pause");
}

void registrarUsuario(FILE *usuarios){
	Usuario usuario;
	
	char user[] = "ADMINS";
	char pass[] = "Admins123";
	char name[] = "Administrador";
	strcpy(usuario.nombreUsuario, user);
	strcpy(usuario.contrasena, pass);
	strcpy(usuario.nombre, name);
	
	fwrite(&usuario, sizeof(Usuario), 1, usuarios);
}

void registrarEntrenadores(FILE *entrenadores){
	Entrenador entrenador[6];
	
	char name[60];
	char pass[10];
	
	strcpy(name, "Marcelo Gallardo");
	strcpy(pass, "Creer18");
	int id = 91218;
	strcpy(entrenador[1].nombre, name);
	strcpy(entrenador[1].contrasena, pass);
	entrenador[1].nroEntrenador = id;
	entrenador[1].dia[0] = 1;
	entrenador[1].dia[1] = 5;
	entrenador[1].dia[2] = 6;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	
	_flushall();
	
	strcpy(name, "Ramon Diaz");
	strcpy(pass, "Campeon14");
	id = 24514;
	strcpy(entrenador[2].nombre, name);
	strcpy(entrenador[2].contrasena, pass);
	entrenador[2].nroEntrenador = id;
	entrenador[2].dia[0] = 2;
	entrenador[2].dia[1] = 4;
	entrenador[2].dia[2] = 6;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	
	_flushall();
	
	strcpy(name, "Martin Demichelis");
	strcpy(pass, "Chaubay22");
	id = 61122;
	strcpy(entrenador[3].nombre, name);
	strcpy(entrenador[3].contrasena, pass);
	entrenador[3].nroEntrenador = id;
	entrenador[3].dia[0] = 3;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	
	_flushall();
	
	strcpy(name, "Hernan Crespo");
	strcpy(pass, "Liber96");
	id = 26696;
	strcpy(entrenador[4].nombre, name);
	strcpy(entrenador[4].contrasena, pass);
	entrenador[4].nroEntrenador = id;
	entrenador[4].dia[0] = 2;
	entrenador[4].dia[1] = 4;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	
	_flushall();
	
	strcpy(name, "Pablo Aimar");
	strcpy(pass, "Payazo10");
	id = 65723;
	strcpy(entrenador[5].nombre, name);
	strcpy(entrenador[5].contrasena, pass);
	entrenador[5].nroEntrenador = id;
	entrenador[5].dia[0] = 1;
	entrenador[5].dia[1] = 5;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	_flushall();
}

void registrarSocio(FILE *socios){
	Socio socio;
	
	char name[] = "Juan Perez";
	char adress[] = "Av. Belgrano 1200";
	
	strcpy(socio.nombre, name);
	socio.dni = 25843567;
	strcpy(socio.domicilio, adress);
	socio.altura = 1.76;
	socio.peso = 78.9;
	socio.ingreso.dia = 17;
	socio.ingreso.mes = 02;
	socio.ingreso.anio = 1980;
	socio.nroSocio = 98765;
	socio.actividad = 2;
	socio.horario = 1;
	socio.entrenador = 3;
	
	
	fwrite(&socio, sizeof(Socio), 1, socios);
}

void registrarTurnos(FILE *turnos){
	Turno turno;
	
	turno.nroEntrenador = 91218;
	turno.nroSocio = 98765;
	turno.diaTurno = 5;
	turno.fechaTurno.dia = 20;
	turno.fechaTurno.mes = 01;
	turno.fechaTurno.anio = 2022;
	
	fwrite(&turno, sizeof(Turno), 1, turnos);
}
