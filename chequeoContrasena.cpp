#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

bool checkPass(char contrasena[10]);

main(){
	
	char contrasena[] = "aBuel123";
	bool contrasenaValida = checkPass(contrasena);
	
	if(contrasenaValida)
		printf("La contrasenia es valida.");
	else
		printf("La constrasenia no es valida.");
	
}

bool checkPass(char contrasena[10]){

	int mayus = 0;
	int minus = 0;
	int nums = 0;
	
	for(int i = 0; i < strlen(contrasena); i++){
		
		if(isblank(contrasena[i])) return false;
		
		if(isalpha(contrasena[i])) continue;
		
		if(isdigit(contrasena[i])) continue;
		
		return false;
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
	
	if(mayus == 0 or minus == 0 or nums == 0) return false;
	
	if(strlen(contrasena) < 6) return false;
	
	int c = 0;
	
	for(int i = 0; i < strlen(contrasena); i++){
		
		if(isdigit(contrasena[i])){
			if(c >= 3) return false;
			c++;
		}
		else
			c = 0;
	}
	
	int posicion = 0;
	int letraActual = 0;
	int letraSgte = 0;
	int pos1 = 0;
	int pos2 = 0;
	
	for(int i = 0; i < strlen(contrasena); i++){
		
		if(isalpha(contrasena[i])){
			
			letraActual = tolower(contrasena[i]);
			letraSgte = tolower(contrasena[i + 1]);
			
			pos1 = letraActual - 'a' + 1;
			pos2 = letraSgte - 'a' + 1;
				
			if(pos2 == pos1 + 1) return false;
			
		}
	}
	return true;
}