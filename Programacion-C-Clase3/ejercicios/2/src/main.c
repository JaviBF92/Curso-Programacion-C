#include "../includes/concesionario.h"
#include <getopt.h>

int main(int argc, char *argv[])
{
	struct coche *c1;
	struct concesionario *con;
	char info[4000];
	char *argumento;
	int arg;

	int val, cont = 0, option_index = 0;
	
	static struct option long_options[] = {
		{"matricula", required_argument, 0, 'm'},
		{"id", required_argument, 0, 'i'},
		{"gama", required_argument, 0, 'g'},
		{"dueño", required_argument, 0, 'd'},
		{"help", optional_argument, 0, 'h'},
		{0}
	};
	
	c1 = curso_coche_alloc();

	con = curso_concesionario_alloc();
	
	val = 0;
	
	while(val != -1){
		
		val = getopt_long(argc, argv, "m:i:g:d:h", long_options, &option_index);
		
		cont++;
		switch(val){
			case 'm':
				argumento = optarg;
				printf("Matrícula: %s \n", argumento);
				curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MATRICULA, 
							 argumento);
				break;
			case 'i':
				arg = atoi(optarg);
				printf("ID: %d \n", arg);
				curso_coche_attr_set_u32(c1, 
							 CURSO_COCHE_ATTR_ID, 
							 arg);
				break;
			case 'g':
				argumento = optarg;
				printf("Gama: %s \n", argumento);
				curso_coche_attr_set_str(c1, 
							 CURSO_COCHE_ATTR_MARCA, 
							 argumento);
				break;
			case 'd':
				argumento = optarg;
				printf("Dueño: %s \n", argumento);
				curso_concesionario_attr_set_str(con,
							 CURSO_CONCESIONARIO_ATTR_DUENO, 
							 argumento);
				break;
			case 'h':
			default :
				printf("Recomendamos el uso de -m/-matricula,"\
				"-i/-id, -g/-gama, -d/-dueno \n");
				break;
		}
	}
	
	if(cont < 4){
		printf("No se han introducido todos los valores necesarios \n");
		return -1;
	}	

	curso_concesionario_attr_set_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE,
					   c1);

	curso_concesionario_snprintf(info, sizeof(info), con);
	printf("%s", info);

	curso_concesionario_free(con);
	return 0;
}
