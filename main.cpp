#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "datos.h"

using namespace std;

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
	
	strcpy(user, "ADMONS");
	strcpy(pass, "Admins123");
	strcpy(name, "Admonostrador");
	strcpy(usuario.nombreUsuario, user);
	strcpy(usuario.contrasena, pass);
	strcpy(usuario.nombre, name);
	
	fwrite(&usuario, sizeof(Usuario), 1, usuarios);
}

void registrarEntrenadores(FILE *entrenadores){
	Entrenador entrenador;
	
	char name[60];
	char pass[10];
	
	strcpy(name, "Marcelo Gallardo");
	strcpy(pass, "Creer18");
	int id = 91218;
	strcpy(entrenador.nombre, name);
	strcpy(entrenador.contrasena, pass);
	entrenador.nroEntrenador = id;
	entrenador.dia[0] = 1;
	entrenador.dia[1] = 5;
	entrenador.dia[2] = 6;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	
	_flushall();
	
	strcpy(name, "Ramon Diaz");
	strcpy(pass, "Campeon14");
	id = 24514;
	strcpy(entrenador.nombre, name);
	strcpy(entrenador.contrasena, pass);
	entrenador.nroEntrenador = id;
	entrenador.dia[0] = 2;
	entrenador.dia[1] = 4;
	entrenador.dia[2] = 6;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	
	_flushall();
	
	strcpy(name, "Martin Demichelis");
	strcpy(pass, "Chaubay22");
	id = 61122;
	strcpy(entrenador.nombre, name);
	strcpy(entrenador.contrasena, pass);
	entrenador.nroEntrenador = id;
	entrenador.dia[0] = 3;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	
	_flushall();
	
	strcpy(name, "Hernan Crespo");
	strcpy(pass, "Liber96");
	id = 26696;
	strcpy(entrenador.nombre, name);
	strcpy(entrenador.contrasena, pass);
	entrenador.nroEntrenador = id;
	entrenador.dia[0] = 2;
	entrenador.dia[1] = 4;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	
	_flushall();
	
	strcpy(name, "Pablo Aimar");
	strcpy(pass, "Payazo10");
	id = 65723;
	strcpy(entrenador.nombre, name);
	strcpy(entrenador.contrasena, pass);
	entrenador.nroEntrenador = id;
	entrenador.dia[0] = 1;
	entrenador.dia[1] = 5;
	
	fwrite(&entrenador, sizeof(Entrenador), 1, entrenadores);
	_flushall();
}

void registrarSocio(FILE *socios){
	Socio socio;
	
	char name[] = "Juan Perez";
	char adress[] = "Av. Belgrano 1200";
	
	strcpy(socio.apeNom, name);
	socio.dni = 25843567;
	strcpy(socio.domicilio, adress);
	socio.altura = 1.76;
	socio.peso = 78.9;
	socio.ingreso.dia = 17;
	socio.ingreso.mes = 02;
	socio.ingreso.anio = 1980;
	socio.nroSocio = 98765;
	socio.actividad[1] = 1;
	
	fwrite(&socio, sizeof(Socio), 1, socios);
}

void registrarTurnos(FILE *turnos){
	Turno turno;
	
	turno.entrenador = 1;
	turno.nroSocio = 98765;
	turno.diaTurno[5] = 5;
	turno.horario[1] = 1;
	
	fwrite(&turno, sizeof(Turno), 1, turnos);
	}
