#include "datos.h"
using namespace std;

void menu (int &opcion, char nombre[10]);
void iniciarSesion(int &x, char nombre[10]);
void registrarSocios();
void registrarActividades();
void listado();
void fechaPagos();

int main() {
	setlocale(LC_CTYPE,"Spanish");
	corregirConsola();
	
	char nombre[10];

	int opcion = 0,x;

	system("color 7");
//	system("color 6");

	cout<<"\t\t    __  __           _       _         _____                          _   __        \n";
	Sleep(100);
	cout<<"\t\t   |  \\/  |         | |     | |       |  __ \\                        (_) /_/        \n";
	Sleep(100);
	cout<<"\t\t   | \\  / | ___   __| |_   _| | ___   | |__) |___  ___ ___ _ __   ___ _  ___  _ __  \n";
	Sleep(100);
	cout<<"\t\t   | |\\/| |/ _ \\ / _` | | | | |/ _ \\  |  _  // _ \\/ __/ _ \\ '_ \\ / __| |/ _ \\| '_ \\ \n";
	Sleep(100);
	cout<<"\t\t   | |  | | (_) | (_| | |_| | | (_) | | | \\ \\  __/ (_|  __/ |_) | (__| | (_) | | | |\n";
	Sleep(100);
	cout<<"\t\t   |_|  |_|\\___/ \\__,_|\\__,_|_|\\___/  |_|  \\_\\___|\\___\\___| .__/ \\___|_|\\___/|_| |_|\n";
	Sleep(100);
	cout<<"\t\t                                                          | |                       \n";
	Sleep(100);
	cout<<"\n\n\n";

	iniciarSesion(x, nombre);
	if(x==1) {
		menu(opcion, nombre);
	}
	while(opcion!=5 && x==1) {
		if(opcion==1) {
			registrarSocios();
		}
		if(opcion==2) {
			registrarActividades();
		}
		if(opcion==3) {
			listado();
		}
		if(opcion==4) {
			fechaPagos();
		}
//		system("pause");
		menu(opcion, nombre);
	}

	return 0;
}
void menu(int &opcion, char nombre[10]) {
	system("cls");
	system("color 6");

	cout<<"\t\t    __  __           _       _         _____                          _   __        \n";
	Sleep(100);
	cout<<"\t\t   |  \\/  |         | |     | |       |  __ \\                        (_) /_/        \n";
	Sleep(100);
	cout<<"\t\t   | \\  / | ___   __| |_   _| | ___   | |__) |___  ___ ___ _ __   ___ _  ___  _ __  \n";
	Sleep(100);
	cout<<"\t\t   | |\\/| |/ _ \\ / _` | | | | |/ _ \\  |  _  // _ \\/ __/ _ \\ '_ \\ / __| |/ _ \\| '_ \\ \n";
	Sleep(100);
	cout<<"\t\t   | |  | | (_) | (_| | |_| | | (_) | | | \\ \\  __/ (_|  __/ |_) | (__| | (_) | | | |\n";
	Sleep(100);
	cout<<"\t\t   |_|  |_|\\___/ \\__,_|\\__,_|_|\\___/  |_|  \\_\\___|\\___\\___| .__/ \\___|_|\\___/|_| |_|\n";
	Sleep(100);
	cout<<"\t\t                                                          | |                       \n";
	Sleep(100);
	cout<<"\n\n\n";
	
	cout<<setw(58)<<nombre;

	Sleep(100);
	cout<<"\n\n\n";
	
	cout<<"\tElija una operacion"<<endl<<endl;
	
	Sleep(100);
	cout<<"\t\t1 - Registrar socios."<<endl;
	Sleep(100);
	cout<<"\t\t2 - Registrar actividad de socio."<<endl;
	Sleep(100);
	cout<<"\t\t3 - Listado de socios."<<endl;
	Sleep(100);
	cout<<"\t\t4 - Listado de fechas de pago."<<endl;
	Sleep(100);
	cout<<"\t\t5 - Cerrar la aplicacion."<<endl<<endl;
	Sleep(100);
	cout<<"==> ";
	Sleep(100);
	
	cin>>opcion;
	if(opcion>5 || opcion<1) {
		cout<<"No ingreso un numero valido, intente nuevamente.\n";
		cout<<"==> ";
		cin>>opcion;
	}
}

void iniciarSesion(int &x, char nombre[10]) {
	system("color 7");
	FILE *arch;
	int exitoso=0;
	Usuario reg;
//	char nombre[10];
	string contrasena;
	arch=fopen("Usuarios.dat","a+b");
	if(arch==NULL) {
		exit(1);
	} else {

		cout<<setw(62)<<"INICIO DE SESION"<<endl;
		Sleep(1500);
		cout<<setw(62)<<"\nPor motivos de seguridad, su contrasena no sera mostrada mientras escribe.\n\n";

		while(exitoso == 0) {

			cout<<" - Nombre de usuario: ";
			_flushall();
			cin.getline(nombre, 10, '\n');

			cout<<" - Contrasena: ";

			SetStdinEcho(false);
			_flushall();
			cin>>contrasena;
			SetStdinEcho(true);
			cout<<contrasena<<endl;

			rewind(arch);
			fread(&reg,sizeof(Usuario),1,arch);
			while(!feof(arch)) {
				if(strcmp(nombre,reg.nombreUsuario)==0 && contrasena == reg.contrasena && (reg.tipoDeUser==1 || reg.tipoDeUser==2)) {
					cout<<"\n\nUsuario encontrado.\n";
					printf("Bienvenido, %s. ", nombre);
					
					system("color 2");
					Sleep(500);
					system("color 7");
					Sleep(500);
					system("color 2");
					Sleep(500);
					system("color 7");
					
					exitoso=1;
					x=1;
					fread(&reg,sizeof(Usuario),1,arch);
					
					Sleep(1000);
					system("pause");
					
				} else(fread(&reg,sizeof(Usuario),1,arch));

			}
			if(exitoso==0) {
				printf("\n\n\tUsuario o contrasena incorrectos. Por favor, reintente.\n\n");
				system("color 4");
				Sleep(500);
				system("color 7");
				Sleep(500);
				system("color 4");
				Sleep(500);
				system("color 7");
				contrasena = "";
			}
			rewind(arch);
		}
	}
	fclose(arch);
}
void registrarSocios() {
	system("cls");
	system("color 6");
	Socio reg,copiaPrevia[100];
	int n,restring = 0,cantidadRest,posiciones=0,comprobante=1,j=0;
	/*Registro de socio. Para cada Socio se deber? registrar Nombre, Apellido DNI, Edad, peso,
	Indicaciones m?dicas (Donde es posible registrar si el socio esta restringido para alguna
	actividad), Altura Peso, Direcci?n, Tel?fono, Fecha de ingreso.
	*/
	FILE *arch;
	arch=fopen("Socios.dat","rb");
	fread(&reg,sizeof(Socio),1,arch);
		while(!feof(arch)){
			copiaPrevia[posiciones]=reg;
			posiciones++;
			fread(&reg,sizeof(Socio),1,arch);
		}
	if(arch==NULL) {
		exit(1);
	}
	fclose(arch);
	arch=fopen("Socios.dat","a+b");
	cout<<" - Digite la cantidad de socios que desea registrar: ";
	
	cin>>n;
	for(int i=0; i<n; i++) {
		system("cls");
		cout<<" - Digite el nombre del socio #"<<i<<": ";
		_flushall();
		cin.getline(reg.apeNom,60,'\n');
		cout<<"\n - Digite el domicilio del socio #"<<i<<": ";
		_flushall();
		cin.getline(reg.domicilio,60,'\n');
		cout<<"\n - Digite el dni del socio #"<<i<<": ";
		cin>>reg.dni;
		cout<<"\n - Digite la edad del socio #"<<i<<": ";
		cin>>reg.edad;
		cout<<"\n - Digite el dia de ingreso del socio #"<<i<<": ";
		cin>>reg.ingreso.dia;
		while(reg.ingreso.dia>31||reg.ingreso.dia<1) {
			cout<<"\n\tERROR, intente nuevamente (recuerde que los meses tienen hasta 31 dias): ";
			cin>>reg.ingreso.dia;
		}
		cout<<"\n - Digite el mes de ingreso del socio #"<<i<<": ";
		cin>>reg.ingreso.mes;
		while(reg.ingreso.mes>12 || reg.ingreso.mes<1) {
			cout<<"\n\tNo ingreso un mes valido, intente nuevamente: ";
			cin>>reg.ingreso.mes;
		}
		cout<<"\n - Digite el anio de ingreso del socio #"<<i<<": ";
		cin>>reg.ingreso.anio;
		while(reg.ingreso.anio<1900 || reg.ingreso.anio>2023) {
			cout<<"\n\tERROR. No ingreso un anio valido. intente nuevamente: ";
			cin>>reg.ingreso.anio;
		}
		cout<<"\n - Digite la altura del socio #"<<i<<": ";
		cin>>reg.altura;
		cout<<"\n - Digite el peso del socio #"<<i<<": ";
		cin>>reg.peso;
		cout<<"\n - Digite el nroSocio del socio #"<<i<<": ";
		cin>>reg.nroSocio;
		while(comprobante !=0){
			for(j=0;j<posiciones;j++){
				if(reg.nroSocio==copiaPrevia[i].nroSocio){
				cout<<"ERROR.Este numero de socio esta en uso, ingrese otro, por favor: ";cin>>reg.nroSocio;
				}
				else{comprobante=0;}
			}
		}
		cout<<"\n - Digite el telefono del socio #"<<i<<": ";
		cin>>reg.telefono;
		cout<<"\n - Esta restringido para alguna actividad ? (0: No, 1: Si)\n--> ";
		cin>>restring;
		while(restring > 1 || restring < 0) {
			cout<<"\n\tNo ingreso una opcion valida, intente nuevamente: \n--> ";
			cin>>restring;
		}
		if(restring == 1) {
			cout<<"\nCuantas? (Max. 2) \n--> ";
			cin>>cantidadRest;
			while(cantidadRest >2 || cantidadRest <1) {
				cout<<"\nERROR. No selecciono una opcion valida, intente nuevamente: ";
				cin>>cantidadRest;
			}
			if(restring == 1) {
				cout<<"\nSeleccione cuales:\n";

				cout<<"\t1) Zumba\n";
				cout<<"\t2) Spinning\n";
				cout<<"\t3) Pilates\n";
				
				for(int i=0; i<cantidadRest; i++) {
					cout<<"\n\n--> ";
					cin>>restring;
					reg.restringido[restring]=5;
				}
			}
		}
		fwrite(&reg,sizeof(Socio),1,arch);
	}
	
	printf("\n\nRegistro finalizado correctamente.\n\n");
	cout<<"\t* Subiendo a la base de datos";
	Sleep(800);
	printf(".");
	Sleep(800);
	printf(".");
	Sleep(800);
	printf(".");
	Sleep(800);
	
	printf("\n\nPresione una tecla para volver al menu...");
	getch();
	
	fclose(arch);
}
void registrarActividades() { //Registro de actividad. Una vez registrado el socio, este podr? inscribirse en distintas actividades
	//pudiendo elegir el horario y entrenador.
	system("cls");
	system("color 6");
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
	cout<<"Digite el nroSocio del socio al cual desea inscribirlo a una actividad: ";
	cin>>numerosocio;
	system("cls");
	rewind(arch);
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)) {
		if(numerosocio==reg.nroSocio) {
			socioEncontrado=1;
			cout<<"Seleccione una actividad: \n\t1) Zumba\n\t2) Spinning\n\t3) Pilates";
			cout<<"\n\n--> ";
			cin>>act;
			act -= 1;
			while(act>2 || act<0) {
				cout<<"\n\tNo eligio un numero valido, intente nuevamente.";
				cout<<"\n--> ";
				cin>>act;
				act -= 1;
			}
			while(reg.restringido[act] == 5) {
				cout<<"ERROR: El socio esta restringido medicamente para participar de esta actividad. Por favor, selecciona otra:\n";
				
				cout<<"\t1) Zumba\n";
				cout<<"\t2) Spinning\n";
				cout<<"\t3) Pilates";
				
				cout<<"\n\n--> ";
				cin>>act;
				act -= 1;
			}

			cout<<"\nSeleccione uno de nuestros turnos disponibles:\n";
			cout<<"1) 8hs - 16hs\n";
			cout<<"2) 16hs - 00hs";
			cout<<"\n\n--> ";
			cin>>turno;
			turno -= 1;
			while(turno>1 || turno<0) {
				cout<<"\n\tNo eligio un numero valido, intente nuevamente.";
				cout<<"\n--> ";
				cin>>turno;
				turno -= 1;
			}
			cout<<"\nSeleccione un entrenador:\n";
			rewind(arch3);
			fread(&reg3,sizeof(Entrenador),1,arch3);
			while(!feof(arch3)) {
				copia3[cantPosicionesCopia3]=reg3;
				cantPosicionesCopia3++;
				fread(&reg3,sizeof(Entrenador),1,arch3);
			}
			int evitarRepetirNombres=0,entren[cantPosicionesCopia3],contadorEntrenadores=0,eleccionMinima=0;

			rewind(arch2);
			fread(&reg2,sizeof(Turno),1,arch2);
			while(!feof(arch2)) {
				for(int i=0; i<=cantPosicionesCopia3; i++) {
					for(x=0; x<6; x++) {
						if(reg2.entrenadorYAct[turno][x][act] == copia3[i].nroEntrenador) {
							eleccionMinima=1;
							if(evitarRepetirNombres==0) {
								contadorEntrenadores++;
								cout<<endl<<"\t"<<contadorEntrenadores<<") "<<copia3[i].nombre<<": | ";
								entren[contadorEntrenadores]=copia3[i].nroEntrenador;
							}
							if(x==0)cout<<"Lunes | ";
							if(x==1)cout<<"Martes | ";
							if(x==2)cout<<"Miercoles | ";
							if(x==3)cout<<"Jueves | ";
							if(x==4)cout<<"Viernes | ";
							if(x==5)cout<<"Sabado | ";
							evitarRepetirNombres++;
						}
					}
					evitarRepetirNombres=0;
				}

				fread(&reg2,sizeof(Turno),1,arch2);
			}
			cout<<"\n\n--> ";
			cin>>trainer;
			while(trainer>contadorEntrenadores || trainer<eleccionMinima) {
				cout<<"\n\tNo eligio un numero valido, intente nuevamente.";
				cout<<"\n--> ";
				cin>>trainer;
			}
			for(int i=0; i<6; i++) {
				if(entren[trainer] == reg2.entrenadorYAct[turno][i][act]) {
					reg.actividadYTurno[turno][i][act] = 1;
				}
			}
			
			printf("\n\nActividad registrada correctamente. Presione una tecla para volver al menu...");
			getch();

			fseek(arch,-(int)sizeof(Socio),SEEK_CUR);
			fwrite(&reg,sizeof(Socio),1,arch);
			break;
		} else {
			fread(&reg,sizeof(Socio),1,arch);
		}
	}
	if(socioEncontrado==0) {
		cout<<"\nNo se encontro ningun socio con ese nroSocio.";
	}
	fclose(arch3);
	fclose(arch2);
	fclose(arch);
}
//c) listado de participantes, de una actividad determinada, por horario y entrenador.
void listado() {
	system("color 6");
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
	if(arch==NULL) exit(1);
	
	Socio reg,copia1[100];
	rewind(arch);
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)) {
		copia1[z]=reg;
		z++;
		fread(&reg,sizeof(Socio),1,arch);
	}
	fclose(arch);
	arch=fopen("Socios.dat","a+b");
	system("cls");
	cout<<"Selecciona una actividad:\n";
	cout<<"\t1) Zumba\n";
	cout<<"\t2) Spinning\n";
	cout<<"\t3) Pilates";
	cout<<"\n\n--> ";
	cin>>act;
	act -= 1;
	while(act>2 || act<0) {
		cout<<"No eligio un numero valido, intente nuevamente: ";
		cin>>act;
		act -= 1;
	}

	cout<<"\nSeleccione uno de nuestros turnos disponibles:\n";
	cout<<"1) 8hs - 16hs\n";
	cout<<"2) 16hs - 00hs";
	cout<<"\n\n--> ";
	cin>>turno;
	turno -= 1;
	while(turno>1 || turno<0) {
		cout<<"\n\tNo eligio un numero valido, intente nuevamente.";
		cout<<"\n--> ";
		cin>>turno;
		turno -= 1;
	}
	
	cout<<"\nSeleccione un entrenador:\n";
	rewind(arch3);
	fread(&reg3,sizeof(Entrenador),1,arch3);
	while(!feof(arch3)) {
		copia3[cantPosicionesCopia3]=reg3;
		cantPosicionesCopia3++;
		fread(&reg3,sizeof(Entrenador),1,arch3);
	}
	int entren[cantPosicionesCopia3],eleccionMinima=0;


	rewind(arch2);
	fread(&reg2,sizeof(Turno),1,arch2);
	while(!feof(arch2)) {
		for(int i=0; i<=cantPosicionesCopia3; i++) {
			for(x=0; x<6; x++) {
				if(reg2.entrenadorYAct[turno][x][act] == copia3[i].nroEntrenador) {

					if(evitarRepetirNombre==0) {
						eleccionMinima=1;
						posEntrenador++;
						cout<<"\t"<<posEntrenador<<") "<<copia3[i].nombre<<"\n";
						entren[posEntrenador]=copia3[i].nroEntrenador;
					}
					evitarRepetirNombre++;
				}
			}
			evitarRepetirNombre=0;
		}

		fread(&reg2,sizeof(Turno),1,arch2);
	}
	cout<<"--> ";
	cin>>trainer;


	while(trainer>posEntrenador || trainer<eleccionMinima) {
		cout<<"\nNo eligio un numero valido, intente nuevamente: ";
		cin>>trainer;
	}
	
	cout<<"\n\nLista:\n";
	rewind(arch);
	evitarRepetirNombre=0;
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)){

		for(int a=0; a<6; a++) {
			if((copia1[i].actividadYTurno[turno][a][act] == 1) && (evitarRepetirNombre==0)) {
				personas++;
				evitarRepetirNombre++;
				cout<<"\t"<<personas<<") "<<copia1[i].apeNom<<endl;
			}
			
		}
		i++;
	evitarRepetirNombre=0;
	fread(&reg,sizeof(Socio),1,arch);
}
	cout<<"\nLa cantidad de socios es de: "<<personas<<endl;

	cout<<"\nPresiona una tecla para volver al menu...";
	getch();

	fclose(arch2);
	fclose(arch3);
	fclose(arch);
}

void fechaPagos() {
	system("cls");
	system("color 6");
	FILE *arch;
	int dia,mes,anio;
	arch=fopen("Socios.dat","a+b");
	Socio reg;
	if(arch==NULL) {
		exit(1);
	}
	cout<<" - Digite el dia de la fecha de hoy: ";
	cin>>dia;
	while(dia<1 || dia>31) {
		cout<<"Error, no ingreso un dia valido. Intente nuevamente: ";
		cin>>dia;
	}
	cout<<"\n - Digite el mes de la fecha de hoy: ";
	cin>>mes;
	while(mes<1 || mes>12) {
		cout<<"Error, no ingreso un mes valido. Intente nuevamente: : ";
		cin>>mes;
	}
	cout<<"\n - Digite el anio de la fecha de hoy: ";
	cin>>anio;
	while(anio<1900 || anio>2023) {
		cout<<"\nError, no ingreso un anio valido. Intente nuevamente: ";
		cin>>anio;
	}
	
	printf("\n");
	
	rewind(arch);
	fread(&reg,sizeof(Socio),1,arch);
	
	cout<<"\t* Analizando datos";
	Sleep(800);
	printf(".");
	Sleep(800);
	printf(".");
	Sleep(800);
	printf(".");
	Sleep(800);
	
	printf("\n\n");
	
	cout<<"nroSocio \t Fecha en la que debe pagar\n";
	cout<<"----------\t-------------------------------\n";
	while(!feof(arch)) {
		if(dia>reg.ingreso.dia) {
			if(mes==12) {
				cout<<"\n"<<reg.nroSocio<<"\t\t"<<reg.ingreso.dia<<"/"<<1<<"/"<<reg.ingreso.anio+1<<endl;
			} else {
				cout<<"\n"<<reg.nroSocio<<"\t\t"<<reg.ingreso.dia<<"/"<<mes+1<<"/"<<anio<<endl;
			}

		} else {
			cout<<"\n"<<reg.nroSocio<<"\t\t"<<reg.ingreso.dia<<"/"<<mes<<"/"<<anio<<endl;
		}
		fread(&reg,sizeof(Socio),1,arch);
	}

	cout<<"\n\nPresione una tecla para volver al menu...";
	getch();
		
	fclose(arch);
}

