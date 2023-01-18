#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <windows.h>

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
	int tipoDeUser;//1 si es administrador, 2 si es secretario/a.
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
	int actividad[3];
	int horario;
	int entrenador[5];
};

struct Turno{
	
	int nroEntrenador;
	fec fechaTurno;
	int nroSocio;
	int diaTurno;
};

void iniciarSesion(FILE*usuarios, Usuario usuario);
void menu(FILE*usuarios,  Usuario usuario);
void registrarUsuario(FILE *usuarios, Usuario usuario);

main(){
	
	Usuario usuario;
	FILE *usuarios;
	
	printf("\n\t -INICIAR SESION -\n\n");
	system("pause");
	system("cls");
	iniciarSesion(usuarios,usuario);
	//registrarUsuario(usuarios,usuario);
	
	
	
}

void iniciarSesion(FILE*usuarios, Usuario usuario){

	char user[10]; 
	char pass[10];
	int aux; //utilizado para mostrar el mensaje del inicio de sesion incorrecto (0 inicio de sesion correcto - 1 incorrecto).
	
	do{
		
	usuarios = fopen("Usuarios.dat", "rb");
		
    aux=0;
	
	printf(" \n- NOMBRE DE USUARIO: ");
	_flushall();gets(user);
	
		
	printf(" \n- CONTRASENA: ");
	_flushall();gets(pass);
	
	fread(&usuario,sizeof(Usuario),1,usuarios);
			    
    	while (!feof(usuarios)){
		
		if(strcmp(user,usuario.nombreUsuario)!=0 or strcmp(pass,usuario.contrasena)!=0){
		   aux=1;
		}
		   
	fread(&usuario,sizeof(Usuario),1,usuarios);
	}
	
	if(aux==1){
		printf( "\n EL NOMBRE DE USUARIO O CONTRASENA INGRESADOS SON INCORRECTOS, INTENTELO DE NUEVO.\n\n");
		system("pause");
		system("cls");
	}
	
    fclose(usuarios);
    }while(aux!=0);
    
}


void registrarUsuario(FILE *usuarios, Usuario usuario){
	
	int opcion;
	char user[10];
	char pass[10];
	int error0,errorA,errorB,errorC,errorD;//utilizado para mostrar los errores del nombre de usuario.
	int acMay;//utilizado para contar la cantidad de mayusculas.
	int acDig;//utilizado para contar la cantidad de digitos.
	
	printf("SELECCIONE UNA OPCION: ");
	printf("\n1) ADMINISTRADOR");
	printf("\n2) SECRETARIO/A");
	printf("\n\n  ----> ");
	scanf("%d",&opcion);
	
	while(opcion!=1 and opcion!=2){
		
	printf("\n ERROR - INTENTELO DE NUEVO.\n");
	system("pause");
	system("cls");
		
	printf("SELECCIONE UNA OPCION: ");
	printf("\n1) ADMINISTRADOR");
	printf("\n2) SECRETARIO/A");
	printf("\n\n  ----> ");
	scanf("%d",&opcion);
		
	}
	
	system("cls");
	printf("\n INGRESAR NOMBRE DE USUARIO:");
	_flushall();gets(user);
	
	do{
	
	error0=0;	
	errorA=0;
	errorB=0;
	errorC=0;
	errorD=0;
	acMay=0;
	acDig=0;
	
    if(strlen(user)<6 or strlen(user)>10){             //<---- Utilizado para controlar la cantidad maxima de caracteres.
    	error0=1;
	}
	
	FILE *usuarios = fopen("Usuarios.dat", "rb"); //<--- Utilizado para controlar si el nombre de usuario se encuentra en uso.
	fread(&usuario,sizeof(Usuario),1,usuarios);
			    
    	while (!feof(usuarios)){
		
		if(user==usuario.nombre){
		   errorA=1;
		}
		   
	fread(&usuario,sizeof(Usuario),1,usuarios);
	}
	fclose(usuarios);
	
	if(user[0]>=65 and user[0]<=90){                   //<---- Utilizado para controlar que la primera letra sea minuscula.
		errorB=1;
	}
   
    for(int i=1;i<10;i++){                              //<---- Utilizado para contar la cantidad de letras mayusculas.
    	if(user[i]>=65 and user[i]<=90){
    	acMay=acMay+1;
       }
   }
   
   if(acMay<2){
   	  errorC=1;
   }
   
    for(int i=1;i<10;i++){                              //<---- Utilizado para contar la cantidad de digitos.
    	if(user[i]>=48 and user[i]<=57){
    	acDig=acDig+1;
       }
   }
   
   if(acDig>3){
   	errorD=1;
   }
   
   
   if(error0=1){
   	printf("\033[0;31m");
   	printf("\n - Debe tener una cantidad minima de 6 caracteres y maxima de 10.\n");
   	printf("\033[0m");
   }else{
   	printf("\033[0;32m");
   	printf("\n - Debe tener una cantidad minima de 6 caracteres y maxima de 10.\n");
   	printf("\033[0m");
   }
   
   if(errorA=1){
   	printf("\033[0;31m");
   	printf("\n - El nombre de usuario ingresado ya se encuentra en uso.\n");
   	printf("\033[0m");
   	system("pause");
   	system("cls");
   }
   
   if(errorB=1){
   	printf("\033[0;31m");
   	printf("\n - Debe comenzar con una letra minúscula.\n");
   	printf("\033[0m");
   }else{
   	printf("\033[0;32m");
   	printf("\n - Debe comenzar con una letra minúscula.\n");
   	printf("\033[0m");
   }
   
   if(errorC=1){
   	printf("\033[0;31m");
   	printf("\n - Debe tener al menos 2 letras mayúsculas.\n");
   	printf("\033[0m");
   }else{
   	printf("\033[0;32m");
   	printf("\n - Debe tener al menos 2 letras mayúsculas.\n");
   	printf("\033[0m");
   }
   
    if(errorD=1){
    printf("\033[0;31m");
   	printf("\n - Debe tener como máximo 3 dígitos.\n");
   	printf("\033[0m");
   }else{
   	printf("\033[0;32m");
   	printf("\n - Debe tener como máximo 3 dígitos.\n");
   	printf("\033[0m");
   }
   	
   	printf("\n");
   	system("pause");
   	system("cls");
    
	        
	        
   }while(error0!=0 and errorA!=0 and errorB!=0 and errorC!=0 and errorD!=0);
   
}


   
	
	
	
	
	
	
