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
};

struct Socio{
	char nombre[60];
	char domicilio[60];
	int dni;
	fec nacimiento;
	float altura;
	float peso;
	int nroSocio;
};

struct Turno{
	int nroEntrenador;
	fec fechaTurno;
	int nroSocio;
	int diaTurno;
};

void menu (int opcion);
void iniciarSesion();
void registrarSocios();
int main(){
	iniciarSesion();
	int opcion;
	do{
		menu(opcion);
	}
	while(opcion!=5);
if(opcion==1){registrarSocios();}
	
	
	
	
	return 0;
}
void menu(int opcion){
cout<<"\n1.- Registrar Socios.\n";
cout<<"2.- Registrar Actividades de Socios.\n";
cout<<"3.- Listados de Socios.\n";
cout<<"4.- Listado de fechas de pagos.\n";
cout<<"5.- Cerrar la aplicación\n";
cout<<"Ingrese una opción: ";cin>>opcion;
if(opcion>5 || opcion<1){
	cout<<"No ingreso un numero valido, intente nuevamente: ";cin>>opcion;
}
}

void iniciarSesion(){
	FILE *arch;
	int exitoso=0,reintento;
	Usuario reg;
	char nombre[10];
	char contrasena[10];
	arch=fopen("Usuarios.dat","a+b");
	if(arch==NULL){exit(1);}
	else{
	cout<<"Digite el nombre de usuario: ";_flushall();cin.getline(nombre, 10, '\n');
	cout<<"Digite la contrasena: ";_flushall();cin.getline(contrasena, 10, '\n');
	rewind(arch);
	fread(&reg,sizeof(Usuario),1,arch);
	while(!feof(arch)){
		if(strcmp(nombre,reg.nombreUsuario)==0 && strcmp(contrasena,reg.contrasena)==0){
			cout<<"Inicio de sesion exitoso";
			exitoso=1;
			fread(&reg,sizeof(Usuario),1,arch);
		}
		else(fread(&reg,sizeof(Usuario),1,arch));
	}
	if(exitoso==0){cout<<"No se encontró dicho usuario. Desea reintentar el inicio de sesion? (1=si/0=no)";cin>>reintento;
		while(reintento > 1 || reintento < 0){cout<<"ERROR: no ingreso ninguna de las opciones, digite nuevamente: ";cin>>reintento;
		}
		if(reintento == 1){iniciarSesion();}
		if(reintento == 0){}
	}
	}
	fclose(arch);
}
void registrarSocios(){
	Socio reg;
	int n;
	/*Registro de socio. Para cada Socio se deberá registrar Nombre, Apellido DNI, Edad, peso,
Indicaciones médicas (Donde es posible registrar si el socio esta restringido para alguna
actividad), Altura Peso, Dirección, Teléfono, Fecha de ingreso.
*/
	FILE *arch;
	arch=fopen("Socios.dat","a+b");
	if(arch==NULL){exit(1);}
cout<<"Digite el numero de socios que desea registrar";cin>>n;
for(int i=0;i<n;i++){
	cout<<"Digite el nombre del socio #"<<i<<": ";_flushall();cin.getline(reg.nombre,60,'\n');
	cout<<"\nDigite el domicilio del socio #"<<i<<": ";_flushall();cin.getline(reg.domicilio,60,'\n');
	cout<<"\nDigite el dni del socio #"<<i<<": ";cin>>reg.dni;
	cout<<"\nDigite el dia de nacimiento del socio #"<<i<<": ";cin>>reg.nacimiento.dia;
	while(reg.nacimiento.dia>31||reg.nacimiento.dia<1){
		cout<<"\nERROR, intente nuevamente (recuerde que los meses tienen hasta 31 dias.): ";cin>>reg.nacimiento.dia;
	}
	cout<<"\nDigite el mes de nacimiento del socio #"<<i<<": ";cin>>reg.nacimiento.mes;
	while(reg.nacimiento.mes>12 || reg.nacimiento.mes<1){
		cout<<"\nNo ingreso un mes valido, intente nuevamente: ";cin>>reg.nacimiento.mes;
	}
	cout<<"\nDigite el anio de nacimiento del socio #"<<i<<": ";cin>>reg.nacimiento.anio;
	while(reg.nacimiento.anio>1900 || reg.nacimiento.anio>2023){
		cout<<"\nERROR. No ingreso un anio valido. intente nuevamente: ";cin>>reg.nacimiento.anio;
	}
	cout<<"\nDigite la altura del socio #"<<i<<": ";cin>>reg.altura;
	cout<<"\nDigite el peso del socio #"<<i<<": ";cin>>reg.peso;
	cout<<"\nDigite el nroSocio del socio #"<<i<<": ";cin>>reg.nroSocio;
	fwrite(&reg,sizeof(Socio),1,arch);
}

	
	
	
}
