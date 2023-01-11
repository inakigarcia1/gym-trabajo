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

void menu (int &opcion);
void iniciarSesion(int &x);
void registrarSocios();
void registrarActividades();
void fechaPagos();
int main(){
	int opcion,x;
	iniciarSesion(x);
	if(x==1){menu(opcion);}
	while(opcion!=5 && x==1){
		if(opcion==1){registrarSocios();}
		if(opcion==2){registrarSocios();}
		if(opcion==3){registrarSocios();}
		if(opcion==4){fechaPagos();
		system("pause");
		menu(opcion);}
	}
	return 0;
}
void menu(int &opcion){
system("cls");
cout<<"1.- Registrar Socios.\n";
cout<<"2.- Registrar Actividades de Socios.\n";
cout<<"3.- Listados de Socios.\n";
cout<<"4.- Listado de fechas de pagos.\n";
cout<<"5.- Cerrar la aplicación\n";
cout<<"Ingrese una opción: ";cin>>opcion;
if(opcion>5 || opcion<1){
	cout<<"No ingreso un numero valido, intente nuevamente: ";cin>>opcion;
}
}

void iniciarSesion(int &x){
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
			x=1;
			fread(&reg,sizeof(Usuario),1,arch);
		}
		else(fread(&reg,sizeof(Usuario),1,arch));
		
	}
	if(exitoso==0){cout<<"No se encontró dicho usuario. Desea reintentar el inicio de sesion? (1=si/0=no)";cin>>reintento;
		while(reintento > 1 || reintento < 0){cout<<"ERROR: no ingreso ninguna de las opciones, digite nuevamente: ";cin>>reintento;
		}
		if(reintento == 1){iniciarSesion(x);}
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
	cout<<"Digite el apellido del socio #"<<i<<": ";_flushall();cin.getline(reg.apellido,60,'\n');
	cout<<"\nDigite el domicilio del socio #"<<i<<": ";_flushall();cin.getline(reg.domicilio,60,'\n');
	cout<<"\nDigite el dni del socio #"<<i<<": ";cin>>reg.dni;
	cout<<"\nDigite la edad del socio #"<<i<<": ";cin>>reg.edad;
	cout<<"\nDigite el dia de ingreso del socio #"<<i<<": ";cin>>reg.ingreso.dia;
	while(reg.ingreso.dia>31||reg.ingreso.dia<1){
		cout<<"\nERROR, intente nuevamente (recuerde que los meses tienen hasta 31 dias.): ";cin>>reg.ingreso.dia;
	}
	cout<<"\nDigite el mes de ingreso del socio #"<<i<<": ";cin>>reg.ingreso.mes;
	while(reg.ingreso.mes>12 || reg.ingreso.mes<1){
		cout<<"\nNo ingreso un mes valido, intente nuevamente: ";cin>>reg.ingreso.mes;
	}
	cout<<"\nDigite el anio de ingreso del socio #"<<i<<": ";cin>>reg.ingreso.anio;
	while(reg.ingreso.anio>1900 || reg.ingreso.anio>2023){
		cout<<"\nERROR. No ingreso un anio valido. intente nuevamente: ";cin>>reg.ingreso.anio;
	}
	cout<<"\nDigite la altura del socio #"<<i<<": ";cin>>reg.altura;
	cout<<"\nDigite el peso del socio #"<<i<<": ";cin>>reg.peso;
	cout<<"\nDigite el nroSocio del socio #"<<i<<": ";cin>>reg.nroSocio;
	cout<<"\nDigite el telefono del socio #"<<i<<": ";cin>>reg.telefono;
	fwrite(&reg,sizeof(Socio),1,arch);
}
fclose(arch);
}
void registrarActividades(){
	FILE *arch;
	arch=fopen("Socios.dat","a+b");
	if(arch==NULL)exit(1);
	Socio reg;
	int numerosocio,actividad,legajoentrenador;
	cout<<"Digite el nroSocio del socio al cual desea inscribirlo a una actividad: ";cin>>numerosocio;
	rewind(arch);
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)){
		if(numerosocio==reg.nroSocio){
			cout<<"\nA cual actividad desea inscribirse.\n0.Zumba.\n1.Spinning.\n2.Pilates.\n";cin>>actividad;
			while(actividad<0 || actividad >2){
				cout<<"ERROR. no ingreso un numero valido, intente nuevamente: ";cin>>actividad;
			}
			reg.actividad[actividad]=1;
			cout<<"ingrese el legajo del entrenador que desee contratar: ";cin>>legajoentrenador;
			
			
		}
	}
	
	
	
	
	
	
	
	
	fclose(arch);
}
	
	
	
	
	
	
	
	
	
	
void fechaPagos(){
		FILE *arch;
		int dia,mes,anio;
		arch=fopen("Socios.dat","a+b");
		Socio reg;
		if(arch==NULL){exit(1);}
		cout<<"Digite el dia de la fecha de hoy: ";cin>>dia;
		while(dia<1 || dia>31){cout<<"ERROR, digite nuevamente el dia: ";cin>>dia;}
		cout<<"\nDigite el mes de la fecha de hoy: ";cin>>mes;
		while(mes<1 || mes>12){cout<<"ERROR, digite nuevamente el mes: ";cin>>mes;}
		cout<<"\nDigite el anio de la fecha de hoy: ";cin>>anio;
		while(anio<1900 || anio>2023){
		cout<<"\nERROR. No ingreso un anio valido. intente nuevamente: ";cin>>anio;}
		rewind(arch);
		fread(&reg,sizeof(Socio),1,arch);
		cout<<"nroSocio \t Fecha en la que debe pagar";
		while(!feof(arch)){
			if(dia>reg.ingreso.dia){
				if(mes==12){
					cout<<"\n"<<reg.nroSocio<<"\t\t"<<reg.ingreso.dia<<"/"<<1<<"/"<<reg.ingreso.anio+1<<endl;}
				else{cout<<"\n"<<reg.nroSocio<<"\t\t"<<reg.ingreso.dia<<"/"<<mes+1<<"/"<<anio<<endl;}
				
			}
			else{cout<<"\n"<<reg.nroSocio<<"\t\t"<<reg.ingreso.dia<<"/"<<mes<<"/"<<anio<<endl;}
			fread(&reg,sizeof(Socio),1,arch);
		}
	
	fclose(arch);
}

