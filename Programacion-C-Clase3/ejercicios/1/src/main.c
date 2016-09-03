#include "../includes/gestor_tarea.h"
#include <assert.h>

int main(void){
	
	struct tarea *t1, *t2;
	struct gestor_tarea *gestor;
	char info[1000];
	
	t1 = tarea_alloc();
	
	tarea_attr_set_string(t1, TAREA_ATTR_NOMBRE_TAREA, "TAREA 1");	assert(strcmp(tarea_attr_get_string(t1,TAREA_ATTR_NOMBRE_TAREA),
		      "TAREA 1") == 0); 
	
	
	tarea_attr_set_string(t1, TAREA_ATTR_DESC_TAREA, 
			      "Descripcion tarea 1");
	assert(strcmp(tarea_attr_get_string(t1, TAREA_ATTR_DESC_TAREA), 
		      "Descripcion tarea 1") == 0);
	
	tarea_attr_set_u32(t1, TAREA_ATTR_ID, 0);
	assert(tarea_attr_get_u32(t1, TAREA_ATTR_ID) == 0);
	
	tarea_attr_set_string(t1, TAREA_ATTR_USUARIO, "Javi");
	assert(strcmp(tarea_attr_get_string(t1, TAREA_ATTR_USUARIO), 
		      "Javi") == 0);
	
	tarea_attr_set_u32(t1, TAREA_ATTR_PRIORIDAD, 0);
	assert(tarea_attr_get_u32(t1, TAREA_ATTR_PRIORIDAD) == 0);
	
	t2 = tarea_alloc();
	
	tarea_attr_set_string(t2, TAREA_ATTR_NOMBRE_TAREA, "TAREA 2");	assert(strcmp(tarea_attr_get_string(t2,TAREA_ATTR_NOMBRE_TAREA),
		      "TAREA 2") == 0);
	
	tarea_attr_set_string(t2, TAREA_ATTR_DESC_TAREA, 
			      "Descripcion tarea 2");
	assert(strcmp(tarea_attr_get_string(t2, TAREA_ATTR_DESC_TAREA), 
		      "Descripcion tarea 2") == 0);
	
	tarea_attr_set_u32(t2, TAREA_ATTR_ID, 1);
	assert(tarea_attr_get_u32(t2, TAREA_ATTR_ID) == 1);
	
	tarea_attr_set_string(t2, TAREA_ATTR_USUARIO, "Javier");
	assert(strcmp(tarea_attr_get_string(t2, TAREA_ATTR_USUARIO), 
		      "Javier") == 0);
	
	tarea_attr_set_u32(t2, TAREA_ATTR_PRIORIDAD, 0);
	assert(tarea_attr_get_u32(t2, TAREA_ATTR_PRIORIDAD) == 0);
	
	gestor = gestor_tarea_alloc();
	
	gestor_tarea_attr_set_tarea(gestor, GESTOR_TAREA_ATTR_TAREAS, t1);
	
	gestor_tarea_attr_set_tarea(gestor, GESTOR_TAREA_ATTR_TAREAS, t2);
	
	gestor_tarea_snprintf(info, sizeof(info), gestor);
	printf("%s \n", info);
	
	gestor_tarea_free(gestor);
	
	return 0;
	
}