#include "datos.h"
using namespace std;

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
		if(strcmp(nombre,reg.nombreUsuario)==0 && strcmp(contrasena,reg.contrasena)==0 && (reg.tipoDeUser==1 || reg.tipoDeUser==2)){
			cout<<"Inicio de sesion exitoso";
			exitoso=1;
			x=1;
			fread(&reg,sizeof(Usuario),1,arch);
		}
		else(fread(&reg,sizeof(Usuario),1,arch));
		
	}
	if(exitoso==0){cout<<"No se encontr? dicho usuario. Desea reintentar el inicio de sesion? (1=si/0=no)";cin>>reintento;
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
	int n,restring = 0,cantidadRest;
	/*Registro de socio. Para cada Socio se deber? registrar Nombre, Apellido DNI, Edad, peso,
Indicaciones m?dicas (Donde es posible registrar si el socio esta restringido para alguna
actividad), Altura Peso, Direcci?n, Tel?fono, Fecha de ingreso.
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
	cout<<"\nEsta restringido para alguna actividad ? (1 = SI;0 = NO)\n----> ";cin>>restring;
		while(restring > 1 || restring < 0){
			cout<<"No ingreso una opcion valida, intente nuevamente: ";cin>>restring;
		}
		if(restring == 1){
		cout<<"\nCuantas? (MAX 2.) \n------> ";cin>>cantidadRest;
		while(cantidadRest >2 || cantidadRest <1){
			cout<<"\nERROR. No selecciono una opcion valida, intente nuevamente: ";cin>>cantidadRest;
		}
	if(restring == 1){
		cout<<"Seleccion cuales: \n0) ZUMBA.\n1)SPINNING.\n2)PILATES.";
		for(int i=0;i<cantidadRest;i++){
			cout<<"\n-----> ";cin>>restring;
			reg.restringido[restring]=5;
		}
	}
	}
	fwrite(&reg,sizeof(Socio),1,arch);
}
fclose(arch);
}
void registrarActividades(){//Registro de actividad. Una vez registrado el socio, este podr? inscribirse en distintas actividades
							//pudiendo elegir el horario y entrenador.

	FILE *arch;
	FILE *arch2;
	FILE *arch3;
	arch=fopen("Socios.dat","r+b");
	arch2=fopen("Turnos.dat","a+b");
	arch3=fopen("Entrenadores.dat","a+b");
	Socio reg;
	Turno reg2;
	Entrenador reg3,copia3[100];
	int act,turno,x=0,trainer,socioEncontrado=0,cantPosicionesCopia3=0,numerosocio,actividad,legajoentrenador;
	if(arch==NULL)exit(1);
	cout<<"Digite el nroSocio del socio al cual desea inscribirlo a una actividad: ";cin>>numerosocio;
	system("cls");
	rewind(arch);
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)){
	if(numerosocio==reg.nroSocio){
		socioEncontrado=1;
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
		while(reg.restringido[act] == 5){
			cout<<"ERROR: El socio esta restringido medicamente para participar de esta actividad. \nSeleccione otra: ";cin>>act;
		}

				
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
		cout<<" ELIGE UN ENTRENADOR\n";
		rewind(arch3);
		fread(&reg3,sizeof(Entrenador),1,arch3);
			while(!feof(arch3)){
				copia3[cantPosicionesCopia3]=reg3;
				cantPosicionesCopia3++;
				fread(&reg3,sizeof(Entrenador),1,arch3);
			}
			int evitarRepetirNombres=0,entren[cantPosicionesCopia3],contadorEntrenadores=0,eleccionMinima=0;
			
			rewind(arch2);
			fread(&reg2,sizeof(Turno),1,arch2);
			while(!feof(arch2)){ 
			for(int i=0;i<cantPosicionesCopia3;i++){
				for(x=0;x<6;x++){
				if(reg2.entrenadorYAct[turno][x][act] == copia3[i].nroEntrenador){
					eleccionMinima=1;
				if(evitarRepetirNombres==0){
					contadorEntrenadores++;
				cout<<endl<<contadorEntrenadores<<"-"<<copia3[i].nombre<<" \t   ";entren[contadorEntrenadores]=copia3[i].nroEntrenador;}
				if(x==0)cout<<"Lunes;";
				if(x==1)cout<<"Martes;";
				if(x==2)cout<<"Miercoles;";
				if(x==3)cout<<"Jueves;";
				if(x==4)cout<<"Viernes;";
				if(x==5)cout<<"Sabado;";
				evitarRepetirNombres++;
				}
				}
				evitarRepetirNombres=0;
			}
			
				fread(&reg2,sizeof(Turno),1,arch2);
				}
				cout<<"\n------> ";
				cin>>trainer;
			while(trainer>contadorEntrenadores || trainer<eleccionMinima){
				cout<<"\nNo eligio un numero valido, intente nuevamente: ";cin>>trainer;}
				for(int i=0;i<6;i++){
					if(entren[trainer] == reg2.entrenadorYAct[turno][i][act]){
					
					reg.actividadYTurno[turno][i][act] = 1;
				}
			}
			
		fseek(arch,-(int)sizeof(Socio),SEEK_CUR);
		fwrite(&reg,sizeof(Socio),1,arch);
		break;
	}
	else{fread(&reg,sizeof(Socio),1,arch);}
	}
	if(socioEncontrado==0){
	cout<<"No se encontro ningun socio con ese nroSocio.";}
	fclose(arch3);
	fclose(arch2);
	fclose(arch);
}
//c) listado de participantes, de una actividad determinada, por horario y entrenador.
void listado(){
	int act,turno,trainer,existe=0,i=0,x=0,z=0,evitarRepetirNombre=0,cantPosicionesCopia3=0,personas=0,posEntrenador=0;
	FILE *arch;
	FILE *arch2;
	FILE *arch3;
	arch2=fopen("Turnos.dat","a+b");
	arch=fopen("Socios.dat","a+b");
	arch3=fopen("Entrenadores.dat","a+b");
	Turno reg2;
	Entrenador reg3,copia3[100];
	rewind(arch2);
	if(arch==NULL){exit(1);}
	Socio reg,copia1[100];
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
	cout<<" ELIGE UN ENTRENADOR\n";
		rewind(arch3);
		fread(&reg3,sizeof(Entrenador),1,arch3);
			while(!feof(arch3)){
				copia3[cantPosicionesCopia3]=reg3;
				cantPosicionesCopia3++;
				fread(&reg3,sizeof(Entrenador),1,arch3);
			}
		int entren[cantPosicionesCopia3],eleccionMinima=0;
		
		
		rewind(arch2);
		
		fread(&reg2,sizeof(Turno),1,arch2);
			while(!feof(arch2)){ 
			for(int i=0;i<cantPosicionesCopia3;i++){
				for(x=0;x<6;x++){
				if(reg2.entrenadorYAct[turno][x][act] == copia3[i].nroEntrenador){
					
				if(evitarRepetirNombre==0){
					eleccionMinima=1;
					posEntrenador++;
					cout<<posEntrenador<<"-"<<copia3[i].nombre<<"\n";entren[posEntrenador]=copia3[i].nroEntrenador;
				}
				
				evitarRepetirNombre++;}	
				}
				evitarRepetirNombre=0;
			}
			
				fread(&reg2,sizeof(Turno),1,arch2);
				}
				cout<<"------> ";
				cin>>trainer;
			
				z=0;
			while(trainer>posEntrenador || trainer<eleccionMinima){
				cout<<"\nNo eligio un numero valido, intente nuevamente: ";cin>>trainer;}
				system("cls");
				rewind(arch);
				fread(&reg,sizeof(Socio),1,arch);
				while(!feof(arch)){
				copia1[z]=reg;
				z++;
				fread(&reg,sizeof(Socio),1,arch);
				}
				evitarRepetirNombre=0;
				for(int a=0;a<6;a++){
					for(int i=0;i<=z;i++){
						if(copia1[a].actividadYTurno[turno][i][act] == 1 && evitarRepetirNombre==0){
							personas++;
							evitarRepetirNombre++;
							cout<<personas<<"-"<<copia1[a].apeNom<<endl;
						}
					}
					evitarRepetirNombre=0;
				}
				
	cout<<"La cantidad de socios es de: "<<personas<<endl;
	
fclose(arch);
fclose(arch2);
fclose(arch3);
	
}	
	

	
	
	
	
void fechaPagos(){
	system("cls");
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

