#include "utils.h"
#include <assert.h>

static int test1(void){
	
	char cadena[20] = "Good news everyone!";
	char cadena2[20] = "Good news everyone!";
	char letra = 'e';
	
	//printf("%d", cuenta_numero_letras(cadena, letra));
	assert(cuenta_numero_letras(cadena, letra) == 4);
	assert(compara_cadena(cadena, cadena2) == 1);
	assert(tipo_de_letra(letra) == 3);
	
	
}

static int test2(void){
	
	char cadena[20] = "Good news everyone!";
	char letra = 'e';
	int n = 3;
	int m = 5;
	
	assert(primera_letra(cadena, letra) == 6);
	assert(suma_numeros(n, m) == 8);
}

static int test3(void){
	
	int n = 3;
	int m = 5;
	
	assert(resta_numeros(n, m) == -2);
	assert(multiplica_numeros(n, m) == 15);
}

void main(void){
	test1();
	test2();
	test3();
	
}
