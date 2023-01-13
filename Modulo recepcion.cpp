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
	char apeNom[60];
	int dia[6];
	int nroEntrenador;
	char contrasena[10];
	int horario[6];
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
};

struct Turno{
	int entrenador;
	int horario[2];
	int nroSocio;
	int diaTurno[6];
	
};

void menu (int &opcion);
void iniciarSesion(int &x);
void registrarSocios();
void registrarActividades();
void listado();
void fechaPagos();
int main(){
	int opcion,x;
	iniciarSesion(x);
	if(x==1){menu(opcion);}
	while(opcion!=5 && x==1){
		if(opcion==1){registrarSocios();}
		if(opcion==2){registrarActividades();}
		if(opcion==3){listado();}
		if(opcion==4){fechaPagos();}
		system("pause");
		menu(opcion);}
	
	return 0;
}
void menu(int &opcion){
system("cls");
	cout<<"============================================================================\n";
	cout<<"====================| ELIGE UNA OPERACION              |====================\n";
	cout<<"====================|  1- REGISTRAR SOCIOS             |====================\n";
	cout<<"====================|  2- REGISTRAR ACTIVIDAD DE SOCIO |====================\n";
	cout<<"====================|  3- LISTADO DE SOCIOS            |====================\n";
	cout<<"====================|  4- LISTADO DE FECHA DE PAGOS    |====================\n";
	cout<<"====================|  5- Salir	                       |====================\n";
	cout<<"============================================================================\n";
	cout<<"==========================================================================> ";
	cin>>opcion;
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
cout<<"Digite el numero de socios que desea registrar: ";cin>>n;
for(int i=0;i<n;i++){
	cout<<"Digite el nombre del socio #"<<i<<": ";_flushall();cin.getline(reg.apeNom,60,'\n');
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
	while(reg.ingreso.anio<1900 || reg.ingreso.anio>2023){
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
void registrarActividades(){//Registro de actividad. Una vez registrado el socio, este podrá inscribirse en distintas actividades
							//pudiendo elegir el horario y entrenador.

	FILE *arch;
	FILE *arch2;
	FILE *arch3;
	arch=fopen("Socios.dat","a+b");
	arch2=fopen("Turnos.dat","a+b");
	arch3=fopen("Entrenadores.dat","a+b");
	Socio reg;
	Turno reg2;
	Entrenador reg3;
	int act,turno,x=0,trainer,z=0;
	if(arch==NULL)exit(1);
	int numerosocio,actividad,legajoentrenador;
	cout<<"Digite el nroSocio del socio al cual desea inscribirlo a una actividad: ";cin>>numerosocio;
	system("cls");
	rewind(arch);
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)){
	if(numerosocio==reg.nroSocio){
		z=1;
		reg2.nroSocio=numerosocio;
		cout<<"=================================================================\n";
		cout<<"====================|  ELIGE UNA ACTIVIDAD |====================\n";
		cout<<"====================| 0- ZUMBA             |====================\n";
		cout<<"====================| 1- SPINNING          |====================\n";
		cout<<"====================| 2- PILATES           |====================\n";
		cout<<"================================================================\n";
		cout<<"================================================================> ";
		cin>>act;
			while(act>2 || act<0){
				cout<<"No eligio un numero valido, intente nuevamente: ";cin>>act;}
				reg.actividad[act]=act;
				system("cls");
		cout<<"==============================================================\n";
		cout<<"====================|  ELIGE UN HORARIO  |====================\n";
		cout<<"====================| 0- 8-16  hs        |====================\n";
		cout<<"====================| 1- 16-00 hs        |====================\n";
		cout<<"=============================================================\n";
		cout<<"=============================================================> ";
		cin>>turno;
			while(turno>1 || turno<0){
				cout<<"No eligio un numero valido, intente nuevamente: ";cin>>turno;}
				reg2.horario[turno]=turno;
				system("cls");
		cout<<"============================================================================\n";
		cout<<"====================|     ELIGE UN ENTRENADOR   |==================\n";
		fread(&reg3,sizeof(Entrenador),1,arch3);
			while(!feof(arch3)){x++;cout<<"====================|"<<x<<"-"<<reg3.apeNom<<"       \t|====================\n";
				fread(&reg3,sizeof(Entrenador),1,arch3);}
				cout<<"==========================================================================> ";
				cin>>trainer;
			while(trainer>5 || trainer<1){
				cout<<"\nNo eligio un numero valido, intente nuevamente: ";cin>>trainer;}
				reg2.entrenador=trainer;
				fwrite(&reg2,sizeof(Turno),1,arch2);
	}
	fread(&reg,sizeof(Socio),1,arch);
	}
	if(z==0){
	cout<<"No se encontro ningun socio con ese nroSocio.";}
	fclose(arch3);
	fclose(arch2);
	fclose(arch);
}
//c) listado de participantes, de una actividad determinada, por horario y entrenador.
void listado(){
	int act,turno,trainer,existe=0,i=0,x=0;
	FILE *arch;
	FILE *arch2;
	FILE *arch3;
	arch2=fopen("Turnos.dat","a+b");
	arch=fopen("Socios.dat","a+b");
	arch3=fopen("Entrenadores.dat","a+b");
	Turno reg2;
	Entrenador reg3;
	rewind(arch);
	rewind(arch2);
	if(arch==NULL){exit(1);}
	Socio reg;
	system("cls");
	cout<<"=================================================================\n";
	cout<<"====================|  ELIGE UNA ACTIVIDAD |====================\n";
	cout<<"====================| 0- ZUMBA             |====================\n";
	cout<<"====================| 1- SPINNING          |====================\n";
	cout<<"====================| 2- PILATES           |====================\n";
	cout<<"================================================================\n";
	cout<<"================================================================> ";
	cin>>act;
	while(act>2 || act<0){
	cout<<"No eligio un numero valido, intente nuevamente: ";cin>>act;}
	system("cls");
	cout<<"==============================================================\n";
	cout<<"====================|  ELIGE UN HORARIO  |====================\n";
	cout<<"====================| 0- 8-16  hs        |====================\n";
	cout<<"====================| 1- 16-00 hs        |====================\n";
	cout<<"=============================================================\n";
	cout<<"=============================================================> ";
	cin>>turno;
	while(turno>1 || turno<0){
	cout<<"No eligio un numero valido, intente nuevamente: ";cin>>turno;}
	system("cls");
	cout<<"============================================================================\n";
	cout<<"====================|     ELIGE UN ENTRENADOR   |==================\n";
	fread(&reg3,sizeof(Entrenador),1,arch3);
	while(!feof(arch3)){x++;cout<<"====================|"<<x<<"-"<<reg3.apeNom<<"       \t|====================\n";
	fread(&reg3,sizeof(Entrenador),1,arch3);}
	cout<<"==========================================================================> ";
	cin>>trainer;
	while(trainer>5 || trainer<1){
	cout<<"\nNo eligio un numero valido, intente nuevamente: ";cin>>trainer;}
	fread(&reg,sizeof(Socio),1,arch);
	fread(&reg2,sizeof(Turno),1,arch2);
	while(!feof(arch) || !feof(arch2)){
		if(reg.actividad[act]==act){
			if(reg2.horario[turno]==turno){
				if(reg2.entrenador==trainer){
					i++;
					printf("%s,%d",reg.apeNom,reg.nroSocio);
				}
			}
		}
	fread(&reg,sizeof(Socio),1,arch);
	fread(&reg2,sizeof(Turno),1,arch2);
	}
	cout<<"\nLa cantidad de participantes que practican la actividad, en ese horario y con ese entrenador es de: "<<i<<endl;
		
	
	
fclose(arch);
fclose(arch2);
fclose(arch3);
	
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

