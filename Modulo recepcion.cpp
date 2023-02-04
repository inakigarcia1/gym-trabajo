/*
Algoritmos y Estructuras de Datos: TFI. Sistema de administración y gestión de gimnasio.
 ________  ________  _____ ______   ___  ________  ___  ________  ________            _____  ___  __    ________
|\   ____\|\   __  \|\   _ \  _   \|\  \|\   ____\|\  \|\   __  \|\   ___  \         / __  \|\  \|\  \ |\_____  \
\ \  \___|\ \  \|\  \ \  \\\__\ \  \ \  \ \  \___|\ \  \ \  \|\  \ \  \\ \  \       |\/_|\  \ \  \/  /|\|____|\ /_
 \ \  \    \ \  \\\  \ \  \\|__| \  \ \  \ \_____  \ \  \ \  \\\  \ \  \\ \  \      \|/ \ \  \ \   ___  \    \|\  \
  \ \  \____\ \  \\\  \ \  \    \ \  \ \  \|____|\  \ \  \ \  \\\  \ \  \\ \  \          \ \  \ \  \\ \  \  __\_\  \
   \ \_______\ \_______\ \__\    \ \__\ \__\____\_\  \ \__\ \_______\ \__\\ \__\          \ \__\ \__\\ \__\|\_______\
    \|_______|\|_______|\|__|     \|__|\|__|\_________\|__|\|_______|\|__| \|__|           \|__|\|__| \|__|\|_______|
                                           \|_________|

  ___     ___    ___    ____
 |__ \   / _ \  |__ \  |___ \
   ) | | | | |    ) |   __) |
  / /  | | | |   / /   |__ <
 / /_  | |_| |  / /_   ___) |
|____|  \___/  |____| |____/


   POR:

    ______      __   /\//               __  ___      __  __
   /  _/ /_  __/_/__//\/ ___  ____     /  |/  /___ _/ /_/_/___ ______
   / // __ \/ __ `/ __ \/ _ \/_  /    / /|_/ / __ `/ __/ / __ `/ ___/
 _/ // /_/ / /_/ / / / /  __/ / /_   / /  / / /_/ / /_/ / /_/ (__  )
/___/_.___/\__,_/_/ /_/\___/ /___/  /_/  /_/\__,_/\__/_/\__,_/____/
       __        __                     ______      __    __
      / /_  ____/_/_________  ____     /_  __/___  / /_  /_/___ ______
 __  / / / / / __ `/ ___/ _ \/_  /      / / / __ \/ __ \/ / __ `/ ___/
/ /_/ / /_/ / /_/ / /  /  __/ / /_     / / / /_/ / /_/ / / /_/ (__  )
\____/\__,_/\__,_/_/   \___/ /___/    /_/  \____/_.___/_/\__,_/____/
    __  __                          __         _____             __  _
   / / / /___ _____ ___  ____ _____/ /___ _   / ___/____ _____  / /_(_)___  ____
  / /_/ / __ `/ __ `__ \/ __ `/ __  / __ `/   \__ \/ __ `/ __ \/ __/ / __ \/ __ \
 / __  / /_/ / / / / / / /_/ / /_/ / /_/ /   ___/ / /_/ / / / / /_/ / / / / /_/ /
/_/ /_/\__,_/_/ /_/ /_/\__,_/\__,_/\__,_/   /____/\__,_/_/ /_/\__/_/_/ /_/\____/


   ______                __         ____ /\//       __   _
  / ____/___ ___________/_/___ _   /  _///\/ ____ _/ /__(_)
 / / __/ __ `/ ___/ ___/ / __ `/   / // __ \/ __ `/ //_/ /
/ /_/ / /_/ / /  / /__/ / /_/ /  _/ // / / / /_/ / ,< / /
\____/\__,_/_/   \___/_/\__,_/  /___/_/ /_/\__,_/_/|_/_/


*/

#include "datos.h"
using namespace std;

void menu (int &opcion, char nombre[10]);
void iniciarSesion(int &x, char nombre[10]);
void registrarSocios();
void registrarActividades();
void listado();
void fechaPagos();

int main() {

	setlocale(LC_CTYPE,"Spanish"); // Habilitar caracteres del español
	corregirConsola(); // Evitar estiramiento de la consola

	// Almacena nombre de usuario
	char nombre[10];

	int opcion = 0,x;

	system("color 7");
//	system("color 6");

	// Titulo
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

	// Inicio de sesion
	iniciarSesion(x, nombre);


	if(x==1) {
		menu(opcion, nombre);
	}

	// Opciones del menu
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
		menu(opcion, nombre);
	}

	return 0;
}
void menu(int &opcion, char nombre[10]) {
	system("cls");
	system("color 6");

	// Titulo
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

	// Opciones del menu
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

	leer(opcion, 9999);

	// En caso de error:
	while(opcion>5 || opcion<1) {
		cout<<"No ingreso un numero valido, intente nuevamente.\n";
		cout<<"==> ";
		leer(opcion, 9999);
	}
}

// Funcion iniciar sesion
void iniciarSesion(int &x, char nombre[10]) {

	// Variables
	system("color 7");
	FILE *arch;
	int exitoso=0;
	Usuario reg;
	char contrasena[32]; // Almacena la contraseña
	arch=fopen("Usuarios.dat","a+b");
	if(arch==NULL) {
		exit(1);
	} else {

		cout<<setw(62)<<"INICIO DE SESION"<<endl;
		Sleep(1500);
		printf("\n\n");

		while(exitoso == 0) {

			// Obtener nombre de usuario
			cout<<" - Nombre de usuario: ";
			_flushall();
			cin.getline(nombre, 10, '\n');

			// Obtener contraseña
			cout<<" - Contrasena: ";

			// Mostrar contraseña oculta
			login(contrasena);

			// Recorrer archivo para buscar el usuario
			rewind(arch);
			fread(&reg,sizeof(Usuario),1,arch);
			while(!feof(arch)) {
				if(strcmp(nombre,reg.nombreUsuario)==0 && (strcmp(contrasena, reg.contrasena) == 0) && (reg.tipoDeUser==1 || reg.tipoDeUser==2)) {

					// Si el usuario fue encontrado:
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

			// Si no se encontró el usuario:
			if(exitoso==0) {
				printf("\n\n\tUsuario o contrasena incorrectos. Por favor, reintente.\n\n");
				system("color 4");
				Sleep(500);
				system("color 7");
				Sleep(500);
				system("color 4");
				Sleep(500);
				system("color 7");
			}
			rewind(arch);
		}
	}
	fclose(arch);
}

// Funcion para registrar socios
void registrarSocios() {

	// Variables
	system("cls");
	system("color 6");
	Socio reg,copiaPrevia[100];
	int n,restring = 0,cantidadRest,posiciones=0,comprobante=1,j=0;
	FILE *arch;
	arch=fopen("Socios.dat","rb");
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)) {
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

	// Solicitar datos del socio
	leer(n, -1);

	while(n <= 0) {
		cout<<"\n\nError, ingrese un numero valido.\n\n";
		cout<<" - Digite la cantidad de socios que desea registrar: ";
		leer(n, -1);
	}

	for(int i=0; i<n; i++) {
		system("cls");
		cout<<" - Digite el nombre del socio #"<<i<<": ";
		_flushall();
		cin.getline(reg.apeNom,60,'\n');
		cout<<"\n - Digite el domicilio del socio #"<<i<<": ";
		_flushall();
		cin.getline(reg.domicilio,60,'\n');
		cout<<"\n - Digite el DNI del socio #"<<i<<": ";
		leer(reg.dni, -1);

		while(reg.dni < 0) {
			cout<<"\n\nError, ingrese un numero valido.\n\n";
			cout<<"\n - Digite el DNI del socio #"<<i<<": ";
			leer(reg.dni, -1);
		}

		cout<<"\n - Digite la edad del socio #"<<i<<": ";
		leer(reg.edad, 1);

		while(reg.edad < 13 or reg.edad > 70) {
			cout<<"\n\nError, ingrese un numero valido. Recuerde que la edad minima es 13 y la maxima 70.\n\n";
			cout<<"\n - Digite la edad del socio #"<<i<<": ";
			leer(reg.edad, 1);
		}

		cout<<"\n - Digite el dia de ingreso del socio #"<<i<<": ";
		leer(reg.ingreso.dia, 50);

		while(reg.ingreso.dia>31||reg.ingreso.dia<1) {
			cout<<"\n\tERROR, intente nuevamente (recuerde que los meses tienen hasta 31 dias): ";
			leer(reg.ingreso.dia, 50);
		}
		cout<<"\n - Digite el mes de ingreso del socio #"<<i<<": ";
		leer(reg.ingreso.mes, 50);
		while(reg.ingreso.mes>12 || reg.ingreso.mes<1) {
			cout<<"\n\tNo ingreso un mes valido, intente nuevamente: ";
			leer(reg.ingreso.mes, 50);
		}
		cout<<"\n - Digite el anio de ingreso del socio #"<<i<<": ";
		leer(reg.ingreso.anio, 9999);
		while(reg.ingreso.anio < 1900 || reg.ingreso.anio > 2023) {
			cout<<"\n\tERROR. No ingreso un anio valido. Intente nuevamente: ";
			leer(reg.ingreso.anio, 9999);
		}
		cout<<"\n - Digite la altura del socio #"<<i<<" (En Mts.): ";
		leerF(reg.altura, 999.6);

		while(reg.altura < 0 or reg.altura > 2.5) {
			cout<<"\nError, ingrese un numero valido.\n\n";
			cout<<" - Digite la altura del socio #"<<i<<" (En Mts.): ";
			leerF(reg.altura, 999.6);
		}

		cout<<"\n - Digite el peso del socio #"<<i<<" (En Kgs.): ";
		leerF(reg.peso, 999.6);

		while(reg.peso < 0 or reg.peso > 350) {
			cout<<"\nError, ingrese un numero valido.\n\n";
			cout<<" - Digite el peso del socio #"<<i<<" (En Kgs): ";
			leerF(reg.peso, 999.6);
		}

		cout<<"\n - Digite el nroSocio del socio #"<<i<<": ";
		
		leer(reg.nroSocio, -1);
		
		while(reg.nroSocio <= 0){
			cout<<"\nError, ingrese un numero valido.\n\n";
			cout<<" - Digite el nroSocio del socio #"<<i<<": ";
			leer(reg.nroSocio, -1);
		}
		
		while(comprobante != 0) {
			for(j = 0; j < posiciones; j++) {
				if(reg.nroSocio == copiaPrevia[i].nroSocio) {
					cout<<"ERROR.Este numero de socio esta en uso, ingrese otro, por favor: ";
					leer(reg.nroSocio, -1);
				} else comprobante=0;
			}
		}
		cout<<"\n - Digite el telefono del socio #"<<i<<": ";
		leer(reg.telefono, 999);
		
		while(reg.telefono < 0 or reg.telefono > 999999999) {
			cout<<"\n\nError, ingrese un numero valido.\n\n";
			cout<<" - Digite el telefono del socio #"<<i<<": ";
			leer(reg.telefono, 9999);
		}
		
		cout<<"\n - Esta restringido para alguna actividad ? (0: No, 1: Si)\n--> ";
		leer(restring, 50);
		while(restring > 1 || restring < 0) {
			cout<<"\n\tNo ingreso una opcion valida, intente nuevamente: \n--> ";
			leer(restring, 50);
		}
		if(restring == 1) {
			cout<<"\nCuantas? (Max. 2) \n--> ";
			leer(cantidadRest, 50);
			while(cantidadRest >2 || cantidadRest <1) {
				cout<<"\nERROR. No selecciono una opcion valida, intente nuevamente: ";
				leer(cantidadRest, 50);
			}
			if(restring == 1) {
				cout<<"\nSeleccione cuales:\n";

				cout<<"\t1) Zumba\n";
				cout<<"\t2) Spinning\n";
				cout<<"\t3) Pilates\n";

				for(int i = 0; i < cantidadRest; i++) {
					cout<<"\n\n--> ";
					leer(restring, 50);
					restring -= 1;
					
					while(restring != 0 and restring != 1 and restring != 2){
						cout<<"\nERROR. No selecciono una opcion valida, intente nuevamente: ";
						leer(restring, 50);
						restring -= 1;
					}
					
					reg.restringido[restring] = 5;
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

// Funcion para registrar actividades
void registrarActividades() {
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
	leer(numerosocio, -8989);
	system("cls");
	rewind(arch);
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)) {

		// Comprobar si el numero de socio existe
		if(numerosocio==reg.nroSocio) {
			socioEncontrado=1;
			cout<<"Seleccione una actividad: \n\t1) Zumba\n\t2) Spinning\n\t3) Pilates";
			cout<<"\n\n--> ";
			leer(act, 99);
			act -= 1;
			while(act>2 || act<0) {
				cout<<"\n\tNo eligio un numero valido, intente nuevamente.";
				cout<<"\n--> ";
				leer(act, 99);
				act -= 1;
			}
			while(reg.restringido[act] == 5) {
				cout<<"ERROR: El socio esta restringido medicamente para participar de esta actividad. Por favor, selecciona otra:\n";

				cout<<"\t1) Zumba\n";
				cout<<"\t2) Spinning\n";
				cout<<"\t3) Pilates";

				cout<<"\n\n--> ";
				leer(act, 99);
				act -= 1;
			}

			// Solicitar eleccion de turnos
			cout<<"\nSeleccione uno de nuestros turnos disponibles:\n";
			cout<<"1) 8hs - 16hs\n";
			cout<<"2) 16hs - 00hs";
			cout<<"\n\n--> ";
			leer(turno, 99);
			turno -= 1;
			while(turno>1 || turno<0) {
				cout<<"\n\tNo eligio un numero valido, intente nuevamente.";
				cout<<"\n--> ";
				leer(turno, 99);
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
			int evitarRepetirNombres=0,entren[cantPosicionesCopia3],contadorEntrenadores=0,eleccionMinima=0,UsuarioYaRegistradoParaTodo=1;

			// Recorrer archivo para conocer los dias disponibles de los entrenadores
			rewind(arch2);
			fread(&reg2,sizeof(Turno),1,arch2);
			while(!feof(arch2)) {
				for(int i=0; i<=cantPosicionesCopia3; i++) {
					for(x=0; x<6; x++) {
						if(reg2.entrenadorYAct[turno][x][act] == copia3[i].nroEntrenador && reg2.entrenadorYAct[turno][x][act]!=0){
							if(evitarRepetirNombres==0) {
								eleccionMinima=1;
								if(reg.actividadYTurno[turno][i][act] != 1){
								UsuarioYaRegistradoParaTodo=0;
								contadorEntrenadores++;
								cout<<endl<<"\t"<<contadorEntrenadores<<") "<<copia3[i].nombre<<": | ";
								entren[contadorEntrenadores]=copia3[i].nroEntrenador;
							
							if(x==0)cout<<"Lunes | ";
							if(x==1)cout<<"Martes | ";
							if(x==2)cout<<"Miercoles | ";
							if(x==3)cout<<"Jueves | ";
							if(x==4)cout<<"Viernes | ";
							if(x==5)cout<<"Sabado | ";
							evitarRepetirNombres++;
								}
							}
						}
					}
					evitarRepetirNombres=0;
				}
				fread(&reg2,sizeof(Turno),1,arch2);
			}
			// Solicitar entrenador
			if(UsuarioYaRegistradoParaTodo == 1 && eleccionMinima ==1){
			
			system("cls");
			cout<<"Este Socio ya se encuentra inscripto con todos los profesores de esta actividad.";
			cout<<"\n\nPresione una tecla para volver al menu...";
			getch();
			break;}
			
			if(eleccionMinima == 0){
			system("cls");
			cout<<"No se ha registrado ningun entrenador.";
			cout<<"\n\nPresione una tecla para volver al menu...";
			getch();
			break;}
			else{cout<<"\n--> ";
			leer(trainer, 99);}
			while(trainer>contadorEntrenadores || trainer<eleccionMinima) {
				cout<<"\n\tNo eligio un numero valido, intente nuevamente.";
				cout<<"\n--> ";
				leer(trainer, 99);
			}

			// Guardar la informacion en la matriz
			for(int i=0; i<6; i++) {
				if(entren[trainer] == reg2.entrenadorYAct[turno][i][act]) {
					reg.actividadYTurno[turno][i][act] = 1;
				}
			}

			printf("\n\nActividad registrada correctamente. Presione una tecla para volver al menu...");
			getch();

			// Guardar la matriz en el archivo
			fseek(arch,-(int)sizeof(Socio),SEEK_CUR);
			fwrite(&reg,sizeof(Socio),1,arch);
			break;
		} else {
			fread(&reg,sizeof(Socio),1,arch); // Si el nroSocio no existe, se avanza con el siguiente
		}
	}

	// En caso de no encontrar el socio:
	if(socioEncontrado==0) {
		cout<<"No se encontro ningun socio con ese nroSocio. ";
		system("pause");
	}
	fclose(arch3);
	fclose(arch2);
	fclose(arch);
}

// Listado de participantes, de una actividad determinada, por horario y entrenador
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
	leer(act, 99);
	act -= 1;
	while(act>2 || act<0) {
		cout<<"No eligio un numero valido, intente nuevamente: ";
		leer(act, 99);
		act -= 1;
	}

	// Solicitar eleccion de turno
	cout<<"\nSeleccione uno de nuestros turnos disponibles:\n";
	cout<<"1) 8hs - 16hs\n";
	cout<<"2) 16hs - 00hs";
	cout<<"\n\n--> ";
	leer(turno, 99);
	turno -= 1;
	while(turno>1 || turno<0) {
		cout<<"\n\tNo eligio un numero valido, intente nuevamente.";
		cout<<"\n--> ";
		leer(turno, 99);
		turno -= 1;
	}

	rewind(arch3);
	fread(&reg3,sizeof(Entrenador),1,arch3);
	while(!feof(arch3)) {
		copia3[cantPosicionesCopia3]=reg3;
		cantPosicionesCopia3++;
		fread(&reg3,sizeof(Entrenador),1,arch3);
	}
	int entren[cantPosicionesCopia3],eleccionMinima=0;

	// Mostrar entrenadores
	rewind(arch2);
	fread(&reg2,sizeof(Turno),1,arch2);
	while(!feof(arch2)) {
		for(int i=0; i<=cantPosicionesCopia3; i++) {
			for(x=0; x<6; x++) {
				if(reg2.entrenadorYAct[turno][x][act] == copia3[i].nroEntrenador) {

					if(evitarRepetirNombre==0 && reg2.entrenadorYAct[turno][x][act]!=0) {
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
	if(eleccionMinima == 0){
	system("cls");
	cout<<"No se ha registrado ningun entrenador.";
	cout<<"\n\nPresione una tecla para volver al menu...";
	getch();
	}
	else{cout<<"\n--> ";
	leer(trainer, 99);}

	while(trainer>posEntrenador || trainer<eleccionMinima) {
		cout<<"\nNo eligio un numero valido, intente nuevamente: ";
		leer(trainer, 99);
	}
	
	// Listar socios
	if(eleccionMinima != 0){
	cout<<"\n\nLista: ";
	rewind(arch);
	evitarRepetirNombre=0;
	fread(&reg,sizeof(Socio),1,arch);
	while(!feof(arch)) {

		for(int a=0; a<6; a++) {
			if((copia1[i].actividadYTurno[turno][a][act] == 1) && (evitarRepetirNombre==0)) {
				personas++;
				evitarRepetirNombre++;
				cout<<"\t"<<personas<<") "<<copia1[i].apeNom<<endl;
			}

		}
		
		if(personas == 0) cout<<"No se encontraron socios con las caracteristicas buscadas.";
		else cout<<"\n";
		
		i++;
		evitarRepetirNombre=0;
		fread(&reg,sizeof(Socio),1,arch);
	}
	cout<<"\nLa cantidad de socios es de: "<<personas<<endl;
	
	cout<<"\nPresiona una tecla para volver al menu...";
	getch();
	}
	fclose(arch2);
	fclose(arch3);
	fclose(arch);
}

// Funcion para listar fechas de pago
void fechaPagos() {
	system("cls");
	system("color 6");
	FILE *arch;
	int dia,mes,anio;
	arch = fopen("Socios.dat","a+b");
	Socio reg;
	if(arch==NULL) {
		exit(1);
	}

	// Solicitar fecha de hoy
	cout<<" - Digite el dia de la fecha de hoy: ";
	leer(dia, 99);
	while(dia<1 || dia>31) {
		cout<<"Error, no ingreso un dia valido. Intente nuevamente: ";
		leer(dia, 99);
	}
	cout<<"\n - Digite el mes de la fecha de hoy: ";
	leer(mes, 99);
	while(mes<1 || mes>12) {
		cout<<"Error, no ingreso un mes valido. Intente nuevamente: : ";
		leer(mes, 99);
	}
	cout<<"\n - Digite el anio de la fecha de hoy: ";
	leer(anio, 99999);
	while(anio<1900 || anio>2023) {
		cout<<"\nError, no ingreso un anio valido. Intente nuevamente: ";
		leer(anio, 99999);
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

	// Listado de fechas de pago
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

