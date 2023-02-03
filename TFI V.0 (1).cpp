#include "datos.h"

using namespace std;
typedef char semana[10];

bool iniciarSesion(FILE *usuarios, char user[10]);
void menu(int &opcion, char user[10]);
bool checkUser(FILE*usuarios, bool contrasenaValida);
bool checkPass(char contrasena[32]);
void registrarActividades(FILE *turnos);
void pagoEntrenador(FILE *socios, FILE *turnos);
void entrenadorMayorHs(FILE *turnos);
string dia(int numDia);
string obtenerNombre(int id);
int obtenerLegajo(int id);

main(){
	
	setlocale(LC_CTYPE,"Spanish"); // Habilitar caracteres del espa�ol
	corregirConsola(); // Evitar estiramiento de la consola
	
	FILE *usuarios;
	FILE *socios;
	FILE *turnos;
	FILE *aux;
	
	Usuario usuario;
	
	//Declaracion de variables
	char user[10];// Almacena nombre de usuario
	bool identificacion; // Identifica al usuario.
	int opcion; //  Utilizado para registrar la opcion del menu;
	int tipoDeUsuario;
	bool usuarioValido,contrasenaValida;
	
	//Inicio de sesion
	identificacion = iniciarSesion(usuarios,user);
	
	if(identificacion) {
		menu(opcion, user);
	}
	
	// Opciones del menu
	while(opcion!=5 && identificacion == true) {
	if(opcion==1){
	system("cls");
	printf("\n Seleccione una opcion: ");
    printf("\n1) Administrador");
    printf("\n2) Secretario/a");
	cout<<"==> ";
	scanf("%d",&tipoDeUsuario);
	
	while(tipoDeUsuario!=1 and tipoDeUsuario!=2){
		
	cout<<"No ingreso un numero valido, intente nuevamente.\n";
	system("pause");
	system("cls");
		
	printf("\n Seleccione una opcion: ");
    printf("\n1) Administrador");
    printf("\n2) Secretario/a");
	cout<<"==> ";
	scanf("%d",&tipoDeUsuario);
			
	}
		do{
		usuarioValido = checkUser(usuarios,contrasenaValida);
		}while(!usuarioValido);
			
		}
		if(opcion==2) {
			registrarActividades(turnos);
		}
		if(opcion==3) {
		 pagoEntrenador(socios,turnos);;
		}
		if(opcion==4) {
		 entrenadorMayorHs(turnos);;
		}
		menu(opcion, user);
	}
}



 void menu(int &opcion, char user[10]){
 	
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
	
	cout<<setw(58)<<user;

	Sleep(100);
	cout<<"\n\n\n";
	
	// Opciones del menu
	cout<<"\tElija una operacion"<<endl<<endl;
	
	Sleep(100);
	cout<<"\t\t1 - Registrar usuario de recepcion."<<endl;
	Sleep(100);
	cout<<"\t\t2 - Registrar actividades del gym."<<endl;
	Sleep(100);
	cout<<"\t\t3 - Calcular pago al entrenador."<<endl;
	Sleep(100);
	cout<<"\t\t4 - Entrenador con mayor carga horaria."<<endl;
	Sleep(100);
	cout<<"\t\t5 - Cerrar la aplicacion."<<endl<<endl;
	Sleep(100);
	cout<<"==> ";
	Sleep(100);
	
	cin>>opcion;
	
	// En caso de error:
	if(opcion>5 || opcion<1) {
		cout<<"No ingreso un numero valido, intente nuevamente.\n";
		cout<<"==> ";
		cin>>opcion;
	}
}


bool iniciarSesion(FILE *usuarios, char user[10]){
	
	//Declaracion de variables
	Usuario usuario;
    system("color 7");
	char pass[10];
	bool usuarioValido = false; //Utilizado para mostrar el mensaje del inicio de sesion incorrecto (0 inicio de sesion correcto - 1 incorrecto).
	
	do{
		
		usuarios = fopen("Usuarios.dat", "rb");
	    
	    // Obtener nombre de usuario
		printf(" \n- Nombre de usuario: ");
		_flushall();gets(user);
		
		// Obtener contrasena
		printf(" \n- Contrasena: ");
		
		// Mostrar contrase�a oculta
		login(pass);
	
		fread(&usuario,sizeof(Usuario),1,usuarios);
		
    	while (!feof(usuarios)){
    		
			if((strcmp(user, usuario.nombreUsuario) == 0) and (strcmp(pass, usuario.contrasena) == 0)){
		   		
		   		// Si el usuario fue encontrado:
		   		usuarioValido = true;
				cout<<"\n\nUsuario encontrado.\n";
				printf("Bienvenido, %s. ", user);
					
				system("color 2");
				Sleep(500);
				system("color 7");
				Sleep(500);
				system("color 2");
				Sleep(500);
				system("color 7");
				
				return true;	
			}
		   
			fread(&usuario,sizeof(Usuario),1,usuarios);
		}
	
		rewind(usuarios);
		
		if(!usuarioValido){
			printf("\n\n\tUsuario o contrasena incorrectos. Por favor, reintente.\n\n");
			system("color 4");
			Sleep(500);
			system("color 7");
			Sleep(500);
			system("color 4");
			Sleep(500);
			system("color 7");
		}
		
	    fclose(usuarios);
	    
	} while(!usuarioValido);
    
}	


bool checkUser(FILE* usuarios,bool contrasenaValida){
		
	Usuario usuario;

	char nombreUsuario[10];
	char contrasena[32];
	
	
	printf("\n Ingresar nombre de usuario: ");
    _flushall();gets(nombreUsuario);
	
	
	usuarios = fopen("Usuarios.dat", "rb"); //<--- Utilizado para controlar si el nombre de usuario se encuentra en uso.
    
	fread(&usuario,sizeof(Usuario),1,usuarios);
			    
    	while (!feof(usuarios)){
		
		if(strcmp(nombreUsuario,usuario.nombreUsuario)==0){
			
		system("cls");	
	    printf("\033[0;31m");
        printf("\n - Nombre de usuario no disponible. \n");
        printf("\033[0m");
	    fclose(usuarios);
	    
		return false;
		
		}
		   
	fread(&usuario,sizeof(Usuario),1,usuarios);
	}
	fclose(usuarios);
	
	system("cls");
	
	printf("\n - ");
	puts(nombreUsuario);
	
	if(strlen( nombreUsuario)<6 or strlen( nombreUsuario)>10){
	    printf("\033[0;31m");
        printf("\n - Debe tener una cantidad minima de 6 caracteres y maxima de 10.\n");
        printf("\033[0m");
        
   }else{
   	    printf("\033[0;32m");
   	    printf("\n - Debe tener una cantidad minima de 6 caracteres y maxima de 10.\n");
   	    printf("\033[0m");
   }
		
		
	if(isupper(nombreUsuario[0])==1){
    	printf("\033[0;31m");
    	printf("\n - Debe comenzar con una letra minuscula.\n");
     	printf("\033[0m");
      	
   	}else{
   	    printf("\033[0;32m");
   	    printf("\n - Debe comenzar con una letra minuscula.\n");
     	printf("\033[0m");	
    }

	int c = 0;
	
	for(int i = 0; i < strlen(nombreUsuario); i++){
		
		if(isblank(nombreUsuario[i])) continue;
		
		if(isupper(nombreUsuario[i]))
			c++;
			
		if(c >= 2) break;
	}
	
	if(c < 2){
		printf("\033[0;31m");
   	    printf("\n - Debe tener al menos 2 letras mayusculas.\n");
   	    printf("\033[0m");
	   
	}else{
		printf("\033[0;32m");
   	    printf("\n - Debe tener al menos 2 letras mayusculas.\n");
   	    printf("\033[0m");
	}

	int a = 0;
	
	for(int i = 0; i < strlen(nombreUsuario); i++){
		
		if(isblank(nombreUsuario[i])) continue;
		
		if(isdigit(nombreUsuario[i]))
			a++;
			
	}
	
	if(a > 3){
		printf("\033[0;31m");
   	    printf("\n - Debe tener como maximo 3 digitos.\n");
       	printf("\033[0m");	
	
	}else{
		printf("\033[0;32m");
   	    printf("\n - Debe tener como maximo 3 digitos.\n");
   	    printf("\033[0m");	
		}
	
			
	for(int i = 0; i < strlen(nombreUsuario); i++){
			
		if(isdigit(nombreUsuario[i])) continue;
	
		if(isalpha(nombreUsuario[i])) continue;
		
		char a = char(168);
		char b = char(173);
		
		if(nombreUsuario[i] != '+'){
			if(nombreUsuario[i] != '-'){
				if(nombreUsuario[i] != '/'){
					if(nombreUsuario[i] != '*'){
						if(nombreUsuario[i] != '?'){
							if(nombreUsuario[i] != a){
								if(nombreUsuario[i] != '!'){
									if(nombreUsuario[i] != b){
										printf("\033[0;31m");
										printf("\n - Solo estan permitidos simbolos del conjunto (+, -, /,*,?,�,!,i).\n");
										printf("\033[0m");	
										return false;
									}
								}
							}
						}
					}
				}
			}
		}	
		
	}
	printf("\033[0;32m");
	printf("\n - Solo estan permitidos simbolos del conjunto (+, -, /,*,?,�,!,i).\n");
	printf("\033[0m");
	
	if(c < 2 or (strlen( nombreUsuario)<6 or strlen( nombreUsuario)>10) or isupper(nombreUsuario[0])==1 or a > 3){
		
	return false;
	
	}	
	
	system("cls");
	
	do{
	
    printf("\n Ingresar contrasena: ");
    _flushall();gets(contrasena);
    
    contrasenaValida = checkPass(contrasena); // invoca a la funcion "checkPass" para crear la contrase�a.
    
	
	}while(!contrasenaValida);
	
	if(contrasenaValida){
		return true;
	    printf("\n\n");
    	system("pause");
    	system("cls");
    	printf("\033[0;32m");
    	printf("\n - Contrasenia valida.\n");
    	printf("\033[0m");
	}
    

}
   
bool checkPass(char contrasena[31]){
	 
	 system("cls");
	if(strlen(contrasena)<6 or strlen(contrasena)>32){
		
		printf("\033[0;31m");
        printf("\n - Debe tener una cantidad minima de 6 caracteres y maxima de 32.\n");
        printf("\033[0m");
				
	}else{
		
   	    printf("\033[0;32m");
   	    printf("\n - Debe tener una cantidad minima de 6 caracteres y maxima de 32.\n");
   	    printf("\033[0m");
   }

	int mayus = 0;
	int minus = 0;
	int nums = 0;
	bool error;
	error= true;
	
	for(int i = 0; i < strlen(contrasena); i++){
		
		if(isblank(contrasena[i])) error=false;
	
		if(isalpha(contrasena[i])) continue;
		
		if(isdigit(contrasena[i])) continue;
		
		error=false;	
		
	}
	
	if(error==false){
		printf("\033[0;31m");
        printf("\n - Debe tener solamente caracteres alfanumericos.\n");
        printf("\033[0m");
	}else{
		printf("\033[0;32m");
        printf("\n - Debe tener solamente caracteres alfanumericos.\n");
        printf("\033[0m");
	}
		
	for(int i = 0; i < strlen(contrasena); i++){
		
		if(isalpha(contrasena[i])){
			if(isupper(contrasena[i]))
				mayus++;
			else
				minus++;
		}
		
		if(isdigit(contrasena[i])) nums++;
	}
	
	if(mayus == 0 or minus == 0 or nums == 0){
			printf("\033[0;31m");
            printf("\n - Debe contener al menos una letra mayuscula, una letra minuscula y un numero.\n");
            printf("\033[0m");
	}else{
		  printf("\033[0;32m");
          printf("\n - Debe contener al menos una letra mayuscula, una letra minuscula y un numero.\n");
          printf("\033[0m");
	}
	
	int c = 0;
	
	for(int i = 0; i < strlen(contrasena); i++){
		
		if(isdigit(contrasena[i])){
			c++;
			if(c>3){
			printf("\033[0;31m");
            printf("\n - No debe tener mas de 3 caracteres numericos consecutivos.\n");
            printf("\033[0m");
			}
		}
		else
			c = 0;
	}
	 if(c<=3){
		    printf("\033[0;32m");
            printf("\n - No debe tener mas de 3 caracteres numericos consecutivos.\n");
            printf("\033[0m");
	}
	 
	int posicion = 0;
	int letraActual = 0;
	int letraSgte = 0;
	int pos1 = 0;
	int pos2 = 0;
	int aux=0;
	
	for(int i = 0; i < strlen(contrasena); i++){
		
		if(isalpha(contrasena[i])){
			
			letraActual = tolower(contrasena[i]);
			letraSgte = tolower(contrasena[i + 1]);
			
			pos1 = letraActual - 'a' + 1;
			pos2 = letraSgte - 'a' + 1;
				
			if(pos2 == pos1 + 1){
				
			aux=1;
			
			}	
		}
	}
	
	if(aux==1){
			printf("\033[0;31m");
            printf("\n - No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas\n");
            printf("\033[0m");		 
	}else{
		 printf("\033[0;32m");
         printf("\n - No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas\n");
         printf("\033[0m");
	}
	
	if(strlen(contrasena)<6 or strlen(contrasena)>32 or mayus == 0 or minus == 0 or nums == 0 or error==false or c >3 or aux==1){
	return false;
    }
	return true;
}

void registrarActividades(FILE *turnos) {
	
    turnos = fopen ("Turnos.dat", "r+b");

	Turno turno;

	fread(&turno, sizeof(Turno), 1, turnos);


	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 6; j++) {
			for(int k = 0; k < 3; k++) {
				printf(" [%d] ", turno.entrenadorYAct[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}


	rewind(turnos);

	int actividadElegida = 0;
	int turnoElegido = 0;
	int entrenadorElegido = 0;
	int cantidadDias = 0;
	int diaElegido = 0;
	bool turnoValido = true;

	int diasDisponibles[6];
	int diasElegidos[6];
	int listaDias[6];
	int diasOcupados [6];

	for(int i = 0; i < 6; i++) {
		diasDisponibles[i] = 0;
		diasElegidos[i] = 0;
		listaDias[i] = 0;
		diasOcupados[i] = 0;
	}

	cout<<"Elija la actividad a registrar:\n";
	cout<<"1) Zumba\n";
	cout<<"2) Spinning\n";
	cout<<"3) Pilates\n";
	cout<<"- : ";
	cin>>actividadElegida;

	actividadElegida -= 1;

	printf("\n");

	cout<<"Turnos disponibles:\n";
	cout<<"1) 8hs - 16hs\n";
	cout<<"2) 16hs - 00hs\n";
	cout<<"- : ";
	cin>>turnoElegido;

	turnoElegido -= 1;

	string actividad = "";

	if(actividadElegida == 0) actividad = "Zumba";
	if(actividadElegida == 1) actividad = "Spinning";
	if(actividadElegida == 2) actividad = "Pilates";

	cout<<"\n\nElija un entrenador para comprobar disponibilidad:\n";
	cout<<"\t1) Marcelo Gallardo\n";
	cout<<"\t2) Ramon Diaz\n";
	cout<<"\t3) Martin Demichelis\n";
	cout<<"\t4) Hernan Crespo\n";
	cout<<"\t5) Pablo Aimar\n";
	cout<<"- : ";
	cin>>entrenadorElegido;

	system("cls");

	entrenadorElegido -= 1;

	int legajoElegido = obtenerLegajo(entrenadorElegido);
	string nombre = obtenerNombre(entrenadorElegido);

	if(turnoElegido == 0) cout<<"Dias disponibles para "<< actividad <<" con " << nombre <<" de 8hs a 16hs:\n";
	if(turnoElegido == 1) cout<<"Dias disponibles para "<< actividad <<" con " << nombre <<" de 16hs a 00hs:\n";

	string diaDisponible = "";

	for(int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if(i == turnoElegido) {

				if(turno.entrenadorYAct[i][j][actividadElegida] != 0) diasOcupados[j] = 1;

				for(int k = 0; k < 3; k++) {
					if(turno.entrenadorYAct[i][j][k] == legajoElegido) {
						turnoValido = false;
						break;
					}
					turnoValido = true;
				}
				if(turnoValido) {
					cantidadDias++;
					diasDisponibles[j] = 1;
				}

			}
		}
	}

	int contador = 0;
	int numDia = 0;
	bool ocupado = false;

	for(int i = 0; i < 6; i++) {
		if(diasDisponibles[i] == 1) {
			listaDias[contador] = i;
			contador++;
		}
	}

	for(int i = 0; i < cantidadDias; i++) {

		if(diasOcupados[listaDias[i]] == 1)
			ocupado = true;

		else ocupado = false;

		diaDisponible = dia(listaDias[i]);

		if(!ocupado)
			cout<<"\t"<< i + 1 <<") " << diaDisponible << endl;
		else
			cout<<"\t"<< i + 1 <<") " << diaDisponible << " (ocupado)" << endl;
	}

	int op = 0;
	cantidadDias = 0;

	cout<<"\n\nSelecione una opcion (Los dias ocupados por otro entrenador y/o actividad, seran reemplazados):\n";
	cout<<"\t1) Registrar actividad con dicho entrenador en todos los dias disponibles\n";
	cout<<"\t2) Seleccionar dia/s especificos\n";
	cout<<"- : ";
	cin>>op;

	op -= 1;

	if(op == 0) {
		for(int i = 0; i < 2; i++) {
			for (int j = 0; j < 6; j++) {
				if(i == turnoElegido) {
					for(int k = 0; k < 3; k++) {
						if(turno.entrenadorYAct[i][j][k] == legajoElegido) {
							turnoValido = false;
							break;
						}
						turnoValido = true;
					}
					if(turnoValido) {
						turno.entrenadorYAct[i][j][actividadElegida] = legajoElegido;
					}

				}
			}
		}

		fwrite(&turno, sizeof(Turno), 1, turnos);
		cout<<"\nTurno/s registrado/s correctamente.";
	}

	if(op == 1) {
		cout<<"\nCuantos dias desea elegir? --> ";
		cin>>cantidadDias;
		cout<<"En base a la lista mostrada previamente, seleccione el dia deseado segun su respectiva enumeracion.\n";

		for(int i = 0; i < cantidadDias; i++) {
			printf("Dia seleccionado (%d de %d): ", i + 1, cantidadDias);
			cin>>diaElegido;
			diaElegido -= 1;

			diaElegido = listaDias[diaElegido];

			if(diasDisponibles[diaElegido] == 0) {
				cout<<"Error, ha seleccionado un dia no disponible. Presione una tecla para reintentar...";
				getch();
				cantidadDias++;
				i--;
			} else diasElegidos[diaElegido] = 1;
		}

		for(int i = 0; i < 2; i++) {
			for (int j = 0; j < 6; j++) {
				if(diasElegidos[j] == 0) continue;
				if(i == turnoElegido) {
					for(int k = 0; k < 3; k++) {
						if(turno.entrenadorYAct[i][j][k] == legajoElegido) {
							turnoValido = false;
							break;
						}
						turnoValido = true;
					}
					if(turnoValido) {
						turno.entrenadorYAct[i][j][actividadElegida] = legajoElegido;
					}

				}
			}
		}

		fwrite(&turno, sizeof(Turno), 1, turnos);
		cout<<"\nTurno/s registrado/s correctamente.";
	}
     fclose(turnos);
}

void pagoEntrenador(FILE *socios,FILE *turnos){
	
	Turno turno;
	Socio socio;
	
	float price = 0;
	float finalPrice;
	int entrenadorElegido = 0;
    int auxHs = 0;
    int auxDias = 0;
    int alumnos = 0;
    
	printf("Ingrese el monto por alumno: ");
	scanf("%f",&price);
	
    cout<<"\n\nIngrese el entrenador para calcular el pago: \n";
	cout<<"\t1) Marcelo Gallardo\n";
	cout<<"\t2) Ramon Diaz\n";
	cout<<"\t3) Martin Demichelis\n";
	cout<<"\t4) Hernan Crespo\n";
	cout<<"\t5) Pablo Aimar\n";
	cout<<"- : ";
	cin>>entrenadorElegido;

	system("cls");

	entrenadorElegido -= 1;
	
	int legajoElegido = obtenerLegajo(entrenadorElegido);
	string nombre = obtenerNombre(entrenadorElegido);
	
	socios = fopen ("Socios.dat", "rb");
	turnos = fopen ("Turnos.dat", "rb");
	
	fread(&socio, sizeof(Socio), 1, socios);
	while(!feof(socios)){
	
		for(int i = 0; i < 2; i++){
		    for(int j = 0; j < 6; j++){
			for(int k = 0; k < 3; k++){
			
			if(socio.actividadYTurno[i][j][k]==1){
			printf("mesi");
			fread(&turno, sizeof(Turno), 1, turnos);
		while(!feof(turnos)){
		       
				if(turno.entrenadorYAct[i][j][k] == legajoElegido){
				   alumnos++;
				
			
		
	}

		fread(&turno, sizeof(Turno), 1, turnos);
	}
	rewind(turnos);
}
}
}
}

fread(&socio, sizeof(Socio), 1, socios);
}
		
	fclose(turnos);
	fclose(socios);
		finalPrice = (float)alumnos*price;
		
			printf("El monto a pagar es de $ %.2f",finalPrice);
	
	system("pause");
	system("cls");	
}
	


void entrenadorMayorHs(FILE *turnos){
	Turno turno;
	turnos = fopen ("Turnos.dat","rb");
	int auxMarcelo = 0 , auxPablo = 0, auxHernan = 0, auxRamon = 0, auxMartin = 0;
	
	fread(&turno, sizeof(Turno), 1, turnos);
	while(!feof(turnos)){
		for(int i=0;i<2;i++){
			for(int j=0;j<6;j++){
				for(int k=0;k<3;k++){
					if(turno.entrenadorYAct[i][j][k] == marcelo) auxMarcelo++;
					if(turno.entrenadorYAct[i][j][k] == ramon) auxRamon++;
					if(turno.entrenadorYAct[i][j][k] == martin) auxMartin++;	
					if(turno.entrenadorYAct[i][j][k] == hernan) auxHernan++;
					if(turno.entrenadorYAct[i][j][k] == pablo) auxPablo++;
				}
			}
		}
		
	fread(&turno, sizeof(Turno), 1, turnos);
	}
	
	if(auxMarcelo == 0 and auxRamon == 0 and auxMartin == 0 and auxHernan == 0 and auxPablo == 0){
		printf(" 1111111 ");
	}else{
		
	if(auxMarcelo>=auxRamon and auxMarcelo>=auxMartin and auxMarcelo>=auxHernan and auxMarcelo>=auxPablo){
	printf(" Marcelo Gallardo ");
	auxMarcelo++;
	}
	
	if(auxRamon>=auxMarcelo and auxRamon>=auxMartin and auxRamon>=auxHernan and auxRamon>=auxPablo){
	printf("Ramon ");
	auxRamon++;
	}
	
	if(auxMartin>=auxMarcelo and auxMartin>=auxRamon and auxMartin>=auxHernan and auxMartin>=auxPablo){
	printf(" Martin  ");
	auxMartin++;
	}
	
	if(auxHernan>=auxMarcelo and auxHernan>=auxMartin and auxHernan>=auxRamon and auxHernan>=auxPablo){
	printf(" Hernan ");
	auxHernan++;
	}
	
	if(auxPablo>=auxMarcelo and auxPablo>=auxMartin and auxPablo>=auxHernan and auxPablo>=auxRamon){
	printf(" Pablo ");
	auxPablo++;
	}
    }
    
	fclose(turnos);
	system("pause");
	system("cls");
}




	
	
	
	
	
	