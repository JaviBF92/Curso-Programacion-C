#include "tarea.h"
#include <assert.h>

int main(void){
	
	struct tarea *t;
	char info[250];
	
	t = tarea_alloc();
	
	/*Pruebas set y get*/
	
	tarea_attr_set_string(t, TAREA_ATTR_NOMBRE_TAREA, "Tarea 1");
	assert(strcmp(tarea_attr_get_string(t,TAREA_ATTR_NOMBRE_TAREA),
		      "Tarea 1") == 0); 
	
	tarea_attr_set_string(t, TAREA_ATTR_DESC_TAREA, 
			      "Descripción tarea 1.");
	assert(strcmp(tarea_attr_get_string(t, TAREA_ATTR_DESC_TAREA), 
		      "Descripción tarea 1.") == 0);
	
	tarea_attr_set_u32(t, TAREA_ATTR_ID, 1);
	//Mal acceso a memoria:
	/*assert(tarea_attr_get_u32(t, TAREA_ATTR_ID) == 1);*/

	tarea_attr_set_string(t, TAREA_ATTR_USUARIO, "Javi Boza");
	assert(strcmp(tarea_attr_get_string(t, TAREA_ATTR_USUARIO), 
		      "Javi Boza") == 0);
	
	tarea_attr_set_u32(t, TAREA_ATTR_PRIORIDAD, 0);
	assert(tarea_attr_get_u32(t, TAREA_ATTR_PRIORIDAD) == 0);
	
	/*Prueba print*/
	tarea_snprintf(info, sizeof(info), t);
	printf("los valores de la tarea son: %s\n", info);
	
	/*Prueba free*/
	tarea_free(t);
	
	return 0;
	
}
