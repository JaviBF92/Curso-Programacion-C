 
#include "utils.h"

int cuenta_numero_letras(char cadena[], char letra){
	int i = 0;
	int count = 0;
	while(cadena[i] != '\0'){
		if(cadena[i] == letra)
			count++;
		i++;
	}
	return count;
}

int compara_cadena(char *cadena1, char *cadena2){
	int res = 0;
	if(strcmp(cadena1, cadena2) == 0)
		res= 1;
	return res;
}

int tipo_de_letra(char letra){
	
	switch(letra){
		case 'a':
			return 1;
			break;
		case 'c':
			return 2;
			break;
		case 'e': 
			return 3;
			break;
		default:
			return 0;
			break;
	}
	
}

int primera_letra(char cadena[], char letra){
	int i = 0;
	int res = -1;
	while(cadena[i] != '\0'){
		if(cadena[i] != letra){
			i++;
			continue;
		}
		res = i;
		i++;
		break;
		
	}
	return res;
}

int cambia_letras(char cadena[], char letraoriginal, char letracambiar){
	int i = 0;
	while(cadena[i] != '\0'){
		if(cadena[i] == letraoriginal)
			cadena[i] = letracambiar;
		i++;
	}
	return 1;
}

int suma_numeros(int n, int m){
	return n+m;
}

int resta_numeros(int n, int m){
	return n-m;
}

int multiplica_numeros(int n, int m){
	return n*m;
}