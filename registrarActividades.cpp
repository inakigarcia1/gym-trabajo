#include "datos.h"

using namespace std;

void registrarActividades(FILE *turnos);
string dia(int numDia);
string obtenerNombre(int id);
int obtenerLegajo(int id);

main() {

	FILE *turnos = fopen("Turnos.dat", "r+b");

	registrarActividades(turnos);
}

void registrarActividades(FILE *turnos) {

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

	for(int i = 0; i < 6; i++) {
		diasDisponibles[i] = 0;
		diasElegidos[i] = 0;
		listaDias[i] = 0;
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
				if(turno.entrenadorYAct[i][j][actividadElegida] == 0) {
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
	}

	int contador = 0;
	int numDia = 0;

	for(int i = 0; i < 6; i++) {
		if(diasDisponibles[i] == 1) {
			listaDias[contador] = i;
			contador++;
		}
	}

	for(int i = 0; i < cantidadDias; i++) {
		diaDisponible = dia(listaDias[i]);
		cout<<"\t"<< i + 1 <<") " << diaDisponible << endl;
	}

	int op = 0;
	cantidadDias = 0;

	cout<<"\n\nSelecione una opcion:\n";
	cout<<"\t1) Registrar actividad con dicho entrenador en todos los dias disponibles\n";
	cout<<"\t2) Seleccionar dia/s especificos\n";
	cout<<"- : ";
	cin>>op;

	op -= 1;

	if(op == 0) {
		for(int i = 0; i < 2; i++) {
			for (int j = 0; j < 6; j++) {
				if(i == turnoElegido) {
					if(turno.entrenadorYAct[i][j][actividadElegida] == 0) {
						for(int k = 0; k < 3; k++)
							if(turno.entrenadorYAct[i][j][k] == legajoElegido) turnoValido = false;
						if(turnoValido) {
							turno.entrenadorYAct[i][j][actividadElegida] = legajoElegido;
						}
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
					if(turno.entrenadorYAct[i][j][actividadElegida] == 0) {
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
		}

		fwrite(&turno, sizeof(Turno), 1, turnos);
		cout<<"\nTurno/s registrado/s correctamente.";

	}

}

string dia(int numDia) {
	if(numDia == 0) return "Lunes";
	if(numDia == 1) return "Martes";
	if(numDia == 2) return "Miercoles";
	if(numDia == 3) return "Jueves";
	if(numDia == 4) return "Viernes";
	if(numDia == 5) return "Sabado";
}

string obtenerNombre(int id) {
	if(id == 0) return "Marcelo Gallardo";
	if(id == 1) return "Ramon Diaz";
	if(id == 2) return "Martin Demichelis";
	if(id == 3) return "Hernan Crespo";
	if(id == 4) return "Pablo Aimar";
}

int obtenerLegajo(int id) {
	if(id == 0) return marcelo;
	if(id == 1) return ramon;
	if(id == 2) return martin;
	if(id == 3) return hernan;
	if(id == 4) return pablo;
}