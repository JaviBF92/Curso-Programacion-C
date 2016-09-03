/* Realizar el ejercicio que hemos realizado con while pero usando
 * el bucle for
 */


/* Bibliotecas a incluir */
#include <stdio.h>

void main()
{
	/* Declaración de variables */
	int len;
	char cadena[4] = "yes";
	/* Código usando condicional while */
	for(len = 0; len < 4; len++){
		printf("%c",cadena[len]);
		if(cadena[len] == '\0'){
			printf("\n");
		}
	}
}
