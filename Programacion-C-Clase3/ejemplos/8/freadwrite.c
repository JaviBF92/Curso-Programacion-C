#include <stdio.h>
#include <string.h>

int main()
{
	//faltan las comprobaciones de lectura, escritura, y comparar que el numero de caracteres introducidos en lectura y escritura son los mismos que los de la cadena cadena
	FILE *fp;
	char c[] = "ejemplo fwrite/fread";
	char buffer[20];
	fp = fopen("datos.dat", "w+");
	if (fp == NULL)
		return -1;
	
	if(1 != fwrite(c, strlen(c) + 1, 1, fp))
		return -1;

	rewind(fp);

	if(fread(buffer, strlen(c) + 1, 1, fp) != 1)
		return -1;
		
	printf("%s\n", buffer);

	
	if(!fclose(fp))
		return -1;
	
	return 0;
}
