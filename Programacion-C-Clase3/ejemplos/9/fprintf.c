#include <stdio.h>
#include <stdlib.h>

void genera_mensaje(FILE *file)
{
	int linea = 0;

	while (linea < 6) {
		if(fprintf(file, "Linea %d: Mensaje de prueba\n", linea) == -1)
			printf("La línea %d no se ha escrito correctamente", 
			       linea);
		linea++;
	}
	rewind(file);
}

int main (void)	//hay que cerrar el fichero, comprobar que se ha cerrado bien y comprobar que fprintf no devuelva -1, y comprobar el malloc
{
	FILE *file = fopen("datos.dat", "a+");
	char *code;
	size_t n = 0;
	int c;

	if (file == NULL)
		return -1;

	genera_mensaje(file);

	code = malloc(100);	//se reservaba más tamaño del que se usa
	
	if(code == NULL)
		return -1;
	
	while(fgets(code, 100, file)) {
		printf("%s", code);
	}

	free(code);
	
	if(!fclose(file))
		return -1;
	
	return 0;
}
