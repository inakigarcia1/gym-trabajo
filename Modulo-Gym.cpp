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

// Funciones
void menu(int legajo);
void LoginEntrenador(int &legajo);
void Listado(int legajo);
void Registrar(int legajo);

main() {
	
	// Evitar estiramiento de la consola
	corregirConsola();
	
	int legajo = 0;
	
	// Titulo
	system("color 7");
	cout<<"\t\t\t    __  __   __      _       _          _______     ____  __ \n";
	Sleep(100);
	cout<<"\t\t\t   |  \\/  | /_/     | |     | |        / ____\\ \\   / /  \\/  |\n";
	Sleep(100);
	cout<<"\t\t\t   | \\  / | ___   __| |_   _| | ___   | |  __ \\ \\_/ /| \\  / |\n";
	Sleep(100);
	cout<<"\t\t\t   | |\\/| |/ _ \\ / _` | | | | |/ _ \\  | | |_ | \\   / | |\\/| |\n";
	Sleep(100);
	cout<<"\t\t\t   | |  | | (_) | (_| | |_| | | (_) | | |__| |  | |  | |  | |\n";
	Sleep(100);
	cout<<"\t\t\t   |_|  |_|\\___/ \\__,_|\\__,_|_|\\___/   \\_____|  |_|  |_|  |_|\n";
	Sleep(100);
	cout<<"\n\n\n";
	
	// Se llama a login y despues al menu principal
	LoginEntrenador(legajo);
	menu(legajo);

}

// Funcion menu principal. Muestra nombre de usuario y opciones
void menu(int legajo) {
	int ope=0;
	while(ope!=1 and ope!=4) {
		system("cls");
		
		// Color azul
		system("color 9");
		
		// Mostrar titulo y opciones de a poco
		cout<<"\t\t\t    __  __   __      _       _          _______     ____  __ \n";
		Sleep(100);
		cout<<"\t\t\t   |  \\/  | /_/     | |     | |        / ____\\ \\   / /  \\/  |\n";
		Sleep(100);
		cout<<"\t\t\t   | \\  / | ___   __| |_   _| | ___   | |  __ \\ \\_/ /| \\  / |\n";
		Sleep(100);
		cout<<"\t\t\t   | |\\/| |/ _ \\ / _` | | | | |/ _ \\  | | |_ | \\   / | |\\/| |\n";
		Sleep(100);
		cout<<"\t\t\t   | |  | | (_) | (_| | |_| | | (_) | | |__| |  | |  | |  | |\n";
		Sleep(100);
		cout<<"\t\t\t   |_|  |_|\\___/ \\__,_|\\__,_|_|\\___/   \\_____|  |_|  |_|  |_|\n";
		Sleep(100);
		cout<<"\n\n\n";
		
		// Mostrar nombre del entrenador segun legajo
		if(legajo == 91218) cout<<setw(62)<<"MARCELO GALLARDO";
		if(legajo == 24514) cout<<setw(62)<<"RAMON DIAZ";
		if(legajo == 61122) cout<<setw(62)<<"MARTIN DEMICHELIS";
		if(legajo == 26696) cout<<setw(62)<<"HERNAN CRESPO";
		if(legajo == 65723) cout<<setw(62)<<"PABLO AIMAR";
		
		// Opciones del menu
		Sleep(100);
		cout<<"\n\n\n";
		cout<<"\tElija una operacion"<<endl<<endl;
		Sleep(100);
		cout<<"\t\t1 - Ver listado de Socios y actividades que realizan."<<endl;
		Sleep(100);
		cout<<"\t\t2 - Registrar Rutinas."<<endl;
		Sleep(100);
		cout<<"\t\t3 - Cerrar la aplicacion."<<endl<<endl;
		Sleep(100);
		cout<<"==> ";
		Sleep(100);
		cin>>ope;
		printf("\n");
		
		// Bucle para seleccionar la opcion correcta
		while(ope!=4 and ope!=0) {
			switch(ope) {
				case 1:
					cout<<"Escogiste: Listado de socios y actividades. ";
					system("pause");
					system("cls");
					Listado(legajo);
					break;
				case 2:
					cout<<"Escogiste: Registrar rutinas. ";
					system("pause");
					system("cls");
					Registrar(legajo);
					break;
				case 3:
					ope=3;
					cout<<"Escogiste: Cerrar aplicacion. "<<endl;
					cout<<endl<<"Cerrando aplicacion";
					Sleep(800);
					printf(".");
					Sleep(800);
					printf(".");
					Sleep(800);
					printf(".");
					Sleep(800);
					exit(0);
					break;
				default:
					break;
			}
		}
	}
}

void LoginEntrenador(int &legajo) {
	
	// Variables
	Entrenador entrenador;
	legajo = 0;
	string contrasena;

	bool correctUser = false;
	bool correctPass = false;

	FILE *arch = fopen("Entrenadores.dat","rb"); // Abrir archivo

	// Datos en pantalla
	cout<<setw(62)<<"INICIO DE SESION"<<endl;
	Sleep(1500);
	cout<<setw(62)<<"\nPor motivos de seguridad, su contrasena no sera mostrada mientras escribe.\n\n";

	// Bucle para iniciar sesion
	while(!correctUser or !correctPass) {

		cout<<" - Legajo de entrenador: ";
		cin>>legajo;

		cout<<" - Contrasena: ";

		SetStdinEcho(false);
		_flushall();
		cin>>contrasena;
		SetStdinEcho(true);
		cout<<contrasena<<endl;

		//Leo del archivo y guardo en entrenador
		fread(&entrenador, sizeof(Entrenador), 1, arch);

		//Verifico
		while(!feof(arch)) {

			correctUser = false;
			correctPass = false;

			if(legajo==entrenador.nroEntrenador) { // Si el legajo coincide con uno del archivo, verifico su contraseña
				correctUser = true;

				if(contrasena == entrenador.contrasena) { // Si la contraseña también coresponde, se rompe el bucle
					correctPass = true;
					break;
				}

			}

			fread(&entrenador, sizeof(Entrenador), 1, arch);

		}

		// Si no fueron encontrados el usuario y/o la contraseña, repito el bucle
		if(!correctUser or !correctPass) {
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

	cout<<"\n\nUsuario encontrado.\n";

	// Mensaje de bienvenida al entrenador correspondiente
	if(legajo == 91218) cout<<"Bienvenido, Marcelo. ";
	if(legajo == 24514) cout<<"Bienvenido, Ramon. ";
	if(legajo == 61122) cout<<"Bienvenido, Martin. ";
	if(legajo == 26696) cout<<"Bienvenido, Hernan. ";
	if(legajo == 65723) cout<<"Bienvenido, Pablo. ";

	system("color 2");
	Sleep(500);
	system("color 7");
	Sleep(500);
	system("color 2");
	Sleep(500);
	system("color 7");

	fclose(arch);
	Sleep(1000);
	system("pause");
}

void Listado(int legajo) {
	
	// Varibales
	Socio socio;
	int c=1, op;
	char act1[]="Zumba", act2[]="Pila", act3[]="Spinning";
	
	FILE *arch = fopen("Socios.dat", "r+b");
	system("color 9");
	cout<<"-------------Socios:-------------"<<endl<<endl;
	
	fread(&socio, sizeof(Socio), 1, arch);

	// Se recorre el archivo para mostrar las actividades y sus horarios
	while(!feof(arch)) {
		cout<<" Socio numero "<<c<<":"<<endl<<endl;
		cout<<" - Apellido y nombre: "<<socio.apeNom<<endl;
		cout<<" - Fecha de ingreso: "<<socio.ingreso.dia<<"/"<<socio.ingreso.mes<<"/"<<socio.ingreso.anio<<endl;
		cout<<" - Telefono de contacto: "<<socio.telefono<<endl;
		cout<<" - Actividades programadas: "<<endl<<endl;
		for(int i=0; i<2; i++) {
			for(int j=0; j<6; j++) {
				for(int k=0; k<3; k++) {
					if(socio.actividadYTurno[i][j][k]==1) {
						cout<<"\t* ";
						// Comprobar actividad
						if(k==0) {
							cout<<"Zumba -";
						}
						if(k==1) {
							cout<<"Spinning -";
						}
						if(k==2) {
							cout<<"Pilates -";
						}
						// Comprobar dia
						switch(j) {
							case 0:
								cout<<" Los lunes";
								break;
							case 1:
								cout<<" Los martes";
								break;
							case 2:
								cout<<" Los miercoles";
								break;
							case 3:
								cout<<" Los jueves";
								break;
							case 4:
								cout<<" Los viernes";
								break;
							case 5:
								cout<<" Los sabados";
								break;
							default:
								break;
						}
						// Horario
						if(i==0) {
							cout<<" - 1er turno (8hs - 16hs).";
						} else {
							cout<<" - 2do turno (16hs - 00hs).";
						}
						cout<<endl<<endl;
					}
				}
			}
		}
		cout<<endl;
		cout<<"---------------------------------"<<endl<<endl;
		c++;

		fread(&socio, sizeof(Socio), 1, arch);
	}
	cout<<"Presione una tecla para volver al menu...";
	getch();
	fclose(arch);
	menu(legajo);
}

void Registrar(int legajo) {
	system("color 9");

	FILE *arch = fopen("Socios.dat", "rb");
	
	// Variables
	int numsocio = 0;
	int sp = 32; // Codigo ASCII del caracter "espacio"
	int words = 0;
	char rutina[10000];
	Socio socio;
	int letra = 0;
	bool encontrado = false;


	cout<<" - Numero de Socio a buscar: ";
	cin>>numsocio;
	printf("\n");

	fseek(arch,0*sizeof(Socio), SEEK_SET);

	fread(&socio, sizeof(Socio), 1, arch);

	// Recorro el archivo
	while(!feof(arch)) {

		if(numsocio==socio.nroSocio) { // Verifico numero de socio
			system("color 9");
			cout<<"\tSocio encontrado."<<endl;
			system("color 2");
			Sleep(500);
			system("color 9");
			Sleep(500);
			system("color 2");
			Sleep(500);
			system("color 9");
			encontrado = true; // Socio encontrado
			break; // Salir del bucle
		} else fread(&socio, sizeof(Socio), 1, arch);

	}
	rewind(arch);

	// Si no se encontro el nroSocio:
	if(!encontrado) {
		system("color 9");
		cout<<"Datos de socio incorrectos. ";
		error();
		cout<<"Presione una tecla para volver al menu...";
		getch();
		menu(legajo); // Volver al menu
	}

	system("color 9");
	cout<<"\n\tPor favor, ingresar por teclado una rutina de gimnasia, recordar que la misma no debe superar las 380 palabras."<<endl<<endl;
	cout<<"\tRutina: ";
	
	// Leer rutina
	_flushall();
	gets(rutina);
	
	printf("\n\n");

	words=0;
	system("color 9");
	cout<<"\tVerificando";
	Sleep(800);
	printf(".");
	Sleep(800);
	printf(".");
	Sleep(800);
	printf(".");
	Sleep(800);
	printf("\n\n");

	// Recorro la rutina caracter por caracter para comprobar que no sobrepase las 380 palabras
	for(int i = 0; i < strlen(rutina); i++) {

		letra = rutina[i]; // "Letra" almacena el codigo ASCII del caracter en la posicion "i" de la rutina

		if(letra == sp) words++; // Si el codigo ASCII es igual al del caracter de espacio en blanco, entonces aumenta en 1 la cantidad de palabras
	}

	// Si se cumple la restriccion:
	if(words<=380) {
		system("color 9");
		cout<<"\tLa rutina ingresada cumple con las restricciones."<<endl;
		correct();
		cout<<"\t* Subiendo a la base de datos";
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");
		Sleep(800);
		printf(".");
		Sleep(800);

		// Subiendo al archivo
		strcpy(socio.rutina, rutina);
		fwrite(&socio, sizeof(Socio), 1, arch);

		printf("\n\n");
		cout<<"Datos subidos correctamente. Presione una tecla para volver al menu...";
		getch();
		
	// Si no se cumple:
	} else {
		system("color 9");
		cout<<"\tLa rutina detallada no cumple con los requisitos de extension. Por favor, ingrese una rutina valida."<<endl<<endl;
		error();
		cout<<"\tRutina: ";
		_flushall();
		gets(rutina); // Leo nuevamente la rutina
		printf("\n\n");
	}
	fclose(arch);
	menu(legajo);
}