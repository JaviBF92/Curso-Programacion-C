#include "../includes/concesionario.h"
#include <getopt.h>
#include <string.h>

int separaAtributos(FILE *file, char *attr){
	
	char c = fgetc(file);
	int i = 0;
	int eof = 0;
	
	while(c != '\n' && c != '-' && c > 0){
		
		attr[i] = c;
		c = fgetc(file);
		i++;
	}
	attr[i] = '\0';
	
	if(c < 0)
		eof = -1;
	
	return eof;
	
}

int leeFichero(char *dir, struct concesionario *conc){
	
	FILE *file;
	struct coche *c1;
	char attr[50];
	int cond;
	int pos = 0;
	
	file = fopen(dir,"r");
	if(file == NULL){
		printf("No se ha podido abrir el archivo \n");
		return -1;
	}
	
	cond = separaAtributos(file, attr);
	curso_concesionario_attr_set_str(conc, CURSO_CONCESIONARIO_ATTR_DUENO, 
					 attr);
	while(cond != -1){
		
		switch(pos){
			case 0:
			c1 = curso_coche_alloc();	
			cond = separaAtributos(file, attr);
			curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MARCA, 
						 attr);
			pos++;
			break;
			case 1:
			cond = separaAtributos(file, attr);	
			curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MATRICULA, 
						 attr);
			pos++;
			break;
			case 2:
			cond = separaAtributos(file, attr);	
			curso_coche_attr_set_u32(c1, CURSO_COCHE_ATTR_ID, 
						 atoi(attr));
			curso_concesionario_attr_set_coche(conc, CURSO_CONCESIONARIO_ATTR_COCHE, c1);
			//curso_coche_free(c1);
			pos = 0;
			break;
			default:
			break;
		}		
	}
	//curso_coche_free(c1); fallo al liberar el coche, violacion de segmento
	rewind(file);
	
	if(fclose(file) == EOF){
		printf("No se pudo cerrar el fichero");
		return -1;
	}
	
	return 0;
	
}
/*
int escribeFichero(char *fichero, struct concesionario *conc){
	
	FILE *file;
	struct coche *c1;
	int pos;
	char contenido[300];
	file = fopen(fichero, "w+");
	
	if(file == NULL){
		printf("El fichero no se pudo abrir");
		return -1;
	}
	
	strcpy(contenido, curso_concesionario_attr_get_str(conc,CURSO_CONCESIONARIO_ATTR_DUENO));
	
	strcat(contenido, "\n");
	
	list_for_each_entry(c1, &conc->garaje, head){
		
		//strcat(contenido, curso_coche_attr_get_str(c1, CURSO_COCHE_ATTR_MARCA));
	
	}
	fwrite(contenido, strlen(contenido), 1, file);
	return 0;
	
}*/


int main(int argc, char *argv[])
{

	struct concesionario *con;
	char in[100] = "";
	char datos[500];
	char *out = "../ficheros/output.dat";

	
	int val, option_index = 0;
	
	static struct option long_options[] = {
		{"file", required_argument, 0, 'f'},
		{0}
	};
	
	con = curso_concesionario_alloc();

	
	while((val = getopt_long(argc, argv, "f:", long_options, &option_index)) != -1){
		switch(val){
			case 'f':
				strcpy(in, optarg);
				break;
			default:
				printf("El parámetro no se ha introducido"\
				"correctamente: -f fichero\n");
				break;
		}	
	}
	
	if(leeFichero(in, con) == -1){
		printf("El fichero no se ha leído correctamente \n");
		return -1;
	}

	curso_concesionario_snprintf(datos, sizeof(datos), con);
	printf("%s", datos);
	
	/*if(escribeFichero(out, con) == -1){
		printf("El fichero no se ha escrito correctamente");
		return -1;
	}*/
	
	curso_concesionario_free(con);
	
	return 0;
}
