#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


typedef char dia[10];

struct Entrenador{
	char nombre[60];
	int dia[6];
	int nroEntrenador;
	char contrasena[10];
};

struct Usuario{
	char nombreUsuario[10];
	char contrasena[10];
	char nombre[60];
};

main(){
//	FILE *arch = fopen("Entrenadores.dat", "rb");
//	
//	Entrenador entrenador;
//	
//	fread(&entrenador, sizeof(Entrenador), 1, arch);
//	while(!feof(arch)){
//		printf("Nombre: %s\n", entrenador.nombre);
//		printf("Dias disponibles:\n");
//		printf("\t* %d\n", entrenador.dia[0]);
//		printf("\t* %d\n", entrenador.dia[1]);
//		printf("\t* %d\n", entrenador.dia[2]);
//		printf("Legajo nro: %d\n", entrenador.nroEntrenador);
//		printf("Contrasena: %s", entrenador.contrasena);
//		printf("\n\n-----------------------------------------------------\n\n");
//		
//		fread(&entrenador, sizeof(Entrenador), 1, arch);
//	}

//	FILE *arch1 = fopen("Usuarios.dat", "rb");
//	
//	Usuario usuario;
//	
//	fread(&usuario, sizeof(Usuario), 1, arch1);
//	while(!feof(arch1)){
//		printf("Nombre de usuario: %s\n", usuario.nombreUsuario);
//		printf("Contrasena: %s\n", usuario.contrasena);
//		printf("Nombre completo: %s\n", usuario.nombre);
//		
//		fread(&usuario, sizeof(Usuario), 1, arch1);
//	}
}