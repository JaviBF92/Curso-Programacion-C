#include "gestor_tarea.h"
#include <string.h>

struct gestor_tarea{
	struct tarea *tareas[10];
	uint32_t num_tareas;
	
	uint32_t flags;
	
};

struct gestor_tarea *gestor_tarea_alloc(void){
	return (struct gestor_tarea *)malloc(sizeof(struct gestor_tarea));
}

void gestor_tarea_free(struct gestor_tarea *gestor){
	int i;
	
	for(i = 0; i< gestor->num_tareas; i++){
		tarea_free(gestor->tareas[i]);
	}
	xfree(gestor);
}

void reordena_tareas(struct gestor_tarea *gestor, uint32_t pos){
	int i;
	
	for(i= pos; i < gestor->num_tareas; i++){
		gestor->tareas[i] = gestor->tareas[i+1];
	}
}

void gestor_tarea_attr_unset_tarea(struct gestor_tarea *gestor, uint32_t pos){
	if(pos < 0 || pos > gestor->num_tareas)	//corrección
		return;
	gestor->num_tareas--;
	tarea_free(gestor->tareas[pos]);
	
	reordena_tareas(gestor, pos);
	
}

void ordena_tareas(struct gestor_tarea *gestor, uint16_t n){
	int i, j;
	struct tarea *t;
	
	for(i = 1; i < n; i++){
		for(j = 0; j < n - i; j++){
			if(tarea_attr_get_u32(gestor->tareas[j], 
				TAREA_ATTR_PRIORIDAD) > 
				tarea_attr_get_u32(gestor->tareas[j + 1], 
						   TAREA_ATTR_PRIORIDAD)){
				
				t = gestor->tareas[j];
				gestor->tareas[j] = gestor->tareas[j + 1];
				gestor->tareas[j + 1] = t;
			}
		}
	}
}

void gestor_tarea_attr_set_data(struct gestor_tarea *gestor, uint16_t attr, 
				const void *data){
	
	if(attr > GESTOR_TAREA_ATTR_MAX)
		return;
	
	switch(attr){
	case GESTOR_TAREA_ATTR_TAREAS:
		if(gestor->num_tareas >= 10){
			printf("No es posible introducir más tareas \n");
			break;
		}
		gestor->tareas[gestor->num_tareas] = (struct tarea *)data;
		gestor->num_tareas++;
		break;
		
		ordena_tareas(gestor, gestor->num_tareas);
	}
	
	gestor->flags |= (1 << attr);
}

void gestor_tarea_attr_set_str(struct gestor_tarea *gestor, uint16_t attr, 
			       const char *data){
	gestor_tarea_attr_set_data(gestor, attr, data);
}

void gestor_tarea_attr_set_tarea(struct gestor_tarea *gestor, uint16_t attr, 
				 struct tarea *t){
	gestor_tarea_attr_set_data(gestor, attr, t);
}

const void *gestor_tarea_attr_get_data(struct gestor_tarea *gestor, 
				       uint16_t attr, uint32_t pos){
	if(!(gestor->flags & (1 << attr)))
		return NULL;
	switch(attr){
	case GESTOR_TAREA_ATTR_TAREAS:
		return gestor->tareas[pos];
	case GESTOR_TAREA_ATTR_NUM_TAREAS:
		return &gestor->num_tareas;
	}
	
	return NULL;
}

uint32_t gestor_tarea_alloc_attr_get_u32(struct gestor_tarea *gestor, 
					 uint16_t attr){
	const void *ret = gestor_tarea_attr_get_data(gestor, attr, 0);
	return ret == NULL ? 0 : *((uint32_t *)ret);
}

const char *gestor_tarea_attr_get_str(struct gestor_tarea *gestor, 
				      uint16_t attr){
	return gestor_tarea_attr_get_data(gestor, attr, 0);
}

struct tarea *gestor_tarea_attr_get_tarea(struct gestor_tarea *gestor, 
					  uint16_t attr, uint32_t pos){
	return (struct tarea *)gestor_tarea_attr_get_data(gestor, attr, pos);
}

int gestor_tarea_snprintf(char *buf, size_t size, struct gestor_tarea *gestor){
	int i, ret=0;
	
	for(i = 0; i < gestor->num_tareas; i++){
	ret += tarea_snprintf(buf + ret, size - ret, gestor->tareas[i]);
	}
	return ret;
}