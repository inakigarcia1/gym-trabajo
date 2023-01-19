#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

bool checkUser(char nombreUsuario[10]);

main(){
	
	char nombreUsuario[] = "adMiNs*";
	bool usuarioValido = checkUser(nombreUsuario);
	
	if(usuarioValido)
		printf("El usuario es valido.");
	else
		printf("El usuario no es valido.");
	
}

bool checkUser(char nombreUsuario[10]){
	
	if(isupper(nombreUsuario[0])) return false;

	
	int c = 0;
	
	for(int i = 0; i < strlen(nombreUsuario); i++){
		
		if(isblank(nombreUsuario[i])) continue;
		
		if(isupper(nombreUsuario[i]))
			c++;
			
		if(c >= 2) break;
	}
	
	if(c < 2) return false;

	c = 0;
	
	for(int i = 0; i < strlen(nombreUsuario); i++){
		
		if(isblank(nombreUsuario[i])) continue;
		
		if(isdigit(nombreUsuario[i]))
			c++;
			
		if(c > 3) return false;
	}
	
	c = 0;
	
	for(int i = 0; i < strlen(nombreUsuario); i++){
		
		if(isblank(nombreUsuario[i])) continue;
		
		c++;
	}
	
	if(c < 6) return false;
			
	for(int i = 0; i < strlen(nombreUsuario); i++){
		
		if(isblank(nombreUsuario[i])) continue;
		
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
	return true;
}