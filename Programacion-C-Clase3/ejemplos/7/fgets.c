#include <stdio.h>
#include <stdlib.h>

void genera_mensaje(FILE *file)
{
	fputs("El mensaje a escribir es Alvaro", file);
	rewind(file);
}

int main (void)
{
	FILE *file = fopen("datos.dat", "a+");
	char *code;
	size_t n = 0;
	int c;

	if (file == NULL)
		return -1;

	genera_mensaje(file);

	code = malloc(100);	//se ha reservado más memoria de la que se usa
	
	if(code == NULL)	//se debería comprobar si malloc ha devuelto null
		return -1;
	
	while(fgets(code, 100, file)) {
		printf("%s\n", code);
	}

	free(code);
	if(!fclose(file))
		return -1;	//faltaba por cerrar el fichero, y hay que comprobar que se cierra también
	
	return 0;
}
