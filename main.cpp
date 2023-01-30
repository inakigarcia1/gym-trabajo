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
	usuario.tipoDeUser = 2;
	
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
	socio.edad = 30;
	socio.telefono = 6721;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 6; j++){
			for(int k = 0; k < 3; k++){
				socio.actividadYTurno[i][j][k] = 0;
			}
		}
	}
	
	// POR DEFECTO, CADA NUEVO SOCIO TIENE TODO CERO (NO ASISTE). SOLO HACE FALTA MODIFICAR LOS DIAS QUE ASISTE.

	// Lunes turno 1
	socio.actividadYTurno[1][0][1] = 1; // Asiste, solo spinning
	
	// Miercoles turno 0
	socio.actividadYTurno[0][2][2] = 1; // Asiste, solo pilates
	
	// Viernes turno 0
	socio.actividadYTurno[0][4][0] = 1; // Asiste, solo zumba
	
	
	fwrite(&socio, sizeof(Socio), 1, socios);
}

void registrarTurnos(FILE *turnos){
	
	Turno turno;
	
	// Lunes turno 0
	turno.entrenadorYAct[0][0][0] = marcelo; // Zumba
	turno.entrenadorYAct[0][0][1] = martin; // Spinning
	turno.entrenadorYAct[0][0][2] = ramon; // Pilates
	
	// Lunes turno 1
	turno.entrenadorYAct[1][0][0] = pablo; // Zumba
	turno.entrenadorYAct[1][0][1] = hernan; // Spinning
	turno.entrenadorYAct[1][0][2] = marcelo; // Pilates
	
	// Martes turno 0
	turno.entrenadorYAct[0][1][0] = ramon; // Zumba
	turno.entrenadorYAct[0][1][1] = marcelo; // Spinning
	turno.entrenadorYAct[0][1][2] = martin; // Pilates
	
	// Martes turno 1
	turno.entrenadorYAct[1][1][0] = martin; // Zumba
	turno.entrenadorYAct[1][1][1] = pablo; // Spinning
	turno.entrenadorYAct[1][1][2] = hernan; // Pilates
	
	// Miercoles turno 0
	turno.entrenadorYAct[0][2][0] = martin; // Zumba
	turno.entrenadorYAct[0][2][1] = ramon; // Spinning
	turno.entrenadorYAct[0][2][2] = marcelo; // Pilates
	
	// Miercoles turno 1
	turno.entrenadorYAct[1][2][0] = marcelo; // Zumba
	turno.entrenadorYAct[1][2][1] = pablo; // Spinning
	turno.entrenadorYAct[1][2][2] = hernan; // Pilates
	
	// Jueves turno 0
	turno.entrenadorYAct[0][3][0] = marcelo; // Zumba
	turno.entrenadorYAct[0][3][1] = martin; // Spinning
	turno.entrenadorYAct[0][3][2] = ramon; // Pilates
	
	// Jueves turno 1
	turno.entrenadorYAct[1][3][0] = pablo; // Zumba
	turno.entrenadorYAct[1][3][1] = hernan; // Spinning
	turno.entrenadorYAct[1][3][2] = martin; // Pilates
	
	// Viernes turno 0
	turno.entrenadorYAct[0][4][0] = ramon; // Zumba
	turno.entrenadorYAct[0][4][1] = marcelo; // Spinning
	turno.entrenadorYAct[0][4][2] = martin; // Pilates
	
	// Viernes turno 1
	turno.entrenadorYAct[1][4][0] = marcelo; // Zumba
	turno.entrenadorYAct[1][4][1] = pablo; // Spinning
	turno.entrenadorYAct[1][4][2] = hernan; // Pilates
	
	// Sabado turno 0
	turno.entrenadorYAct[0][5][0] = martin; // Zumba
	turno.entrenadorYAct[0][5][1] = ramon; // Spinning
	turno.entrenadorYAct[0][5][2] = marcelo; // Pilates
	
	// Sabado turno 1
	turno.entrenadorYAct[1][5][0] = hernan; // Zumba
	turno.entrenadorYAct[1][5][1] = pablo; // Spinning
	turno.entrenadorYAct[1][5][2] = hernan; // Pilates
	
	fwrite(&turno, sizeof(Turno), 1, turnos);
}
