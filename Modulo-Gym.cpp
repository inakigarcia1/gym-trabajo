#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include"datos.h"
using namespace std;

void menu();
void LoginEntrenador();
void Listado();
void Registrar();

main(){
	system("color 7");
	cout<<"========================================="<<endl;
	cout<<"=============>|Bienvenido:|<============="<<endl;
	cout<<"========================================="<<endl;
	cout<<"==>";
	system("pause");
	LoginEntrenador();
	cout<<"====Accediendo al menu de operaciones===="<<endl<<endl;
	system("pause");
	menu();
	
}

void menu(){
	int ope=0;
	while(ope!=1 and ope!=4){
		system("cls");
		system("color 9");
		cout<<"==============================================================="<<endl;
		cout<<"==============================================================="<<endl;
		cout<<"====================>|Elija una operacion|<===================="<<endl;
		cout<<"==============================================================="<<endl;
		cout<<"==============================================================="<<endl;
		cout<<"===>|1 - Ver listado de Socios y actividades que realizan.|<==="<<endl;
		cout<<"==============================================================="<<endl;
		cout<<"============>|2 - Registrar Rutinas de Gimnasia.|<============="<<endl;
		cout<<"==============================================================="<<endl;
		cout<<"=================>|3 - Cerrar la aplicacion.|<================="<<endl;
		cout<<"==============================================================="<<endl;
		cout<<"==>";
		cin>>ope;
		while(ope!=4 and ope!=0){
			switch(ope){
				case 1:
					cout<<"Escogiste ===>Listado de socios y actividades.<==="<<endl;
					system("pause");
					system("cls");
					Listado();
				break;
				case 2:
					cout<<"Escogiste ==========>Registrar rutina.<==========="<<endl;
					system("pause");
					system("cls");
					Registrar();
				break;
				case 3:
					ope=3;
					system("color 4");
					cout<<"============>Finalizando actividades.<============"<<endl;
					cout<<endl<<"Cerrando aplicacion...";
					system("pause");
					system("cls");
					cout<<"Gracias."<<endl;;
					exit(0);
				break;
				default:
					break;
			}
		}
	}
}

void LoginEntrenador() {
	//variables
	system("color 6");
	Entrenador coach;
	int a=0, b=0,c=1, t;	//1==> para cuando encuentre el dato
	Entrenador ver;
	FILE *arch = fopen("Entrenadores.dat","rb"); //abro el archivo

	//EN PANTALLA//
	system("cls");
	cout<<"========>|INICIO DE SESION|<========"<<endl<<endl;
	
	while(b==0){	
		cout<<"<> Legajo de entrenador ==> ";
		cin>>coach.nroEntrenador;
		//Leo del archivo y guardo en ver(verificar)
		fread(&ver, sizeof(Entrenador), 1, arch);
		//Verifico legajo:
		while(!feof(arch) and a!=1) {
			if(coach.nroEntrenador==ver.nroEntrenador) {
				a=1;
			} else {
				fread(&ver, sizeof(Entrenador), 1, arch);
			}
		}
		if(a==1) {
			cout<<"El legajo fue encontrado con exito."<<endl;
			b=1;
		} else {
			cout<<"El legajo ingresado es incorrecto."<<endl;
			system("pause");
			system("cls");
			cout<<"===================================="<<endl;
			cout<<"====>|0-Salir de la aplicacion|<===="<<endl<<"===================================="<<endl<<"=====>|1-Intentar nuevamente.|<====="<<endl;
			cout<<"===================================="<<endl;
			cout<<"==>";
			cin>>t;
			if(t==1){
				LoginEntrenador();
			}
			else{
				system("cls");
				system("color 4");
				cout<<"Finalizando operaciones...";
				exit(0);
			}
		}
	}

	while(c==1){
		a=1;
		cout<<"Contrasenia ==> ";
		_flushall();
		gets(coach.contrasena);
		fread(&ver, sizeof(Entrenador), 1, arch);
		
		fseek(arch,0*sizeof(Entrenador), SEEK_SET);
		
		while(!feof(arch) and c==1) {
			a=strcmp(coach.contrasena,ver.contrasena);
			if(a==0) {
				system("color E");
				cout<<"Contrasenia correcta"<<endl;
				c=0;
			} else {
				fread(&ver, sizeof(Entrenador), 1, arch);
			}
		}
		if(c==1){
			system("color C");
			cout<<"Contrasenia incorrecta"<<endl;
			system("pause");
			system("cls");
			system("color 3");
			cout<<"===================================="<<endl;
			cout<<"====>|0-Salir de la aplicacion|<===="<<endl<<"===================================="<<endl<<"=====>|1-Intentar nuevamente.|<====="<<endl;
			cout<<"===================================="<<endl;
			cout<<"==>";
			cin>>t;
			if(t==1){
				c=1;
			}
			else{
				exit(0);
			}	
		}
	}
	
	fclose(arch);
	system("pause");
	system("cls");
}

void Listado(){
	Socio socio;
	int c=1, op;
	char act1[]="Zumba", act2[]="Pila", act3[]="Spinning";
	FILE *arch = fopen("Socios.dat", "r+b");
	system("color 2");
	cout<<"-------------Socios:-------------"<<endl;
	fread(&socio, sizeof(Socio), 1, arch);
	
	while(!feof(arch)){
		cout<<"Socio numero "<<c<<":"<<endl;
		cout<<"Apellido y nombre:"<<socio.apeNom<<endl;
		cout<<"Fecha de ingreso:"<<socio.ingreso.dia<<"/"<<socio.ingreso.mes<<"/"<<socio.ingreso.anio<<endl;
		cout<<"Telefono de contacto:"<<socio.telefono<<endl;
		cout<<"Actividades programadas:"<<endl;
		for(int i=0;i<2;i++){
			for(int j=0;j<6;j++){
				for(int k=0;k<3;k++){
					if(socio.actividadYTurno[i][j][k]==1){
						cout<<"==>";
						//ACTIVIDAD
						if(k==0){
							cout<<"Zumba -";
						}
						if(k==1){
							cout<<"Spinning -";
						}
						if(k==2){
							cout<<"Pilates -";
						}
						//DIA
						switch(j){
							case 0:
								cout<<" Los Lunes";
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
						//HORARIO
						if(i==0){
							cout<<" - Primer turno.";
						}
						else{
							cout<<" - Segundo turno.";
						}
						cout<<endl;
					}
				}
			}
		}
		cout<<endl<<endl;
		cout<<"---------------------------------"<<endl;
		c++;
		
		fread(&socio, sizeof(Socio), 1, arch);
	}
	system("pause");
	system("cls");
	system("color 3");
	cout<<"0-Volver al menu."<<endl<<"1-Ver lista nuevamente."<<endl<<"==>";
	cin>>op;
	if(op==1){
		Listado();
	}
	else{
		menu();
		fclose(arch);
	}
}	

void Registrar(){
	system("color 2");
	
	FILE *arch = fopen("Socios.dat", "rb");
	int numsocio, b, ans=1, sp=32, words;
	char rutina[1001];
	Socio socio;

	while(ans==1){	
		b=0;			
		cout<<"Numero de Socio:"<<endl<<"==>";
		scanf("%d", &numsocio);	
		fseek(arch,0*sizeof(Socio), SEEK_SET);
	
		fread(&socio, sizeof(Socio), 1, arch);
	
		while(!feof(arch) and b!=1){
			
			if(numsocio==socio.nroSocio){
				system("color E");
				cout<<"Socio encontrado."<<endl;
				b=1;
				ans=0;
			}
			else{
				fread(&socio, sizeof(Socio), 1, arch);
			}
		}
		if(b==0){
			system("color C");
			cout<<"Datos de socio incorrectos."<<endl;
			system("pause");
			system("cls");
			system("color 3");
			cout<<"¿Que desea hacer?"<<endl;
			cout<<"0-Regresar al menu."<<endl<<"1-Ingresar datos nuevamente."<<endl<<"==>";
			cin>>ans;
			system("cls");
			if(ans==0){
				system("pause");
				system("cls");
				menu();
			}
		}
	}
	if(b==1){
	
		system("color D");
		cout<<"Ingresar por teclado una rutina de gimnasia."<<endl;
		cout<<"Recordar que la misma no debe superar las 380 palabras."<<endl;
		cout<<"                           ||                          "<<endl;
		cout<<"                           ||                          "<<endl;
		cout<<"                          \\  /                         "<<endl;
		cout<<"                           \\/                          "<<endl;
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"-------------------------Rutina:-----------------------"<<endl;
		cout<<"==>";
		ans=1;
		
		_flushall();
		gets(rutina);
		
		while(ans!=0){
			words=0;
			system("cls");
			system("color D");
			cout<<"Verificando..."<<endl;
			
			for(int i=0;i<1001;i++){
				
				if(rutina[i]!='\0'){
					if(rutina[i]==sp){
						words++;
					}
				}
				else{
					i=1000;
				}
			//	cout<<i<<"-"<<words<<endl;
			}
			
			if(words<3){
				system("color E");
				cout<<"La rutina ingresada cumple con las restricciones."<<endl;
				ans=0;
				cout<<"---------Subiendo a la base de datos---------"<<endl<<endl;
				system("pause");
				system("cls");
				//Subiendo al archivo
				strcpy(socio.rutina,rutina);
				system("color 6");
				cout<<"===>DATOS SUBIDOS CORRECTAMENTE.<==="<<endl<<endl<<endl;
				system("pause");
			}
			else{
				system("color C");
				cout<<"La rutina detallada no cumple con los requisitos de extension."<<endl;
				cout<<"Favor de ingresar una rutina valida."<<endl;
				cout<<"==>";
				_flushall();
				scanf("%s", rutina);
			}
		}
		system("color 3");
		cout<<"0-Volver al menu."<<endl<<"1-Registrar otra rutina."<<endl<<"==>";
		cin>>ans;
		if(ans==0){
			menu();
		}
		else{
		 	menu();
		 	fclose(arch);
		}
	}
}










