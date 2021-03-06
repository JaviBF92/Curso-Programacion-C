#include "../includes/gestor_tarea.h"
#include <string.h>

struct gestor_tarea{
	
	struct list_head tareas;
	
	uint32_t num_tareas;
	
	uint32_t flags;
	
};

struct gestor_tarea *gestor_tarea_alloc(void){
	
	struct gestor_tarea *gestor;
	
	gestor = malloc(sizeof(struct gestor_tarea));
	
	if(gestor == NULL)
		return NULL;
	
	memset(gestor, 0, sizeof(struct gestor_tarea));
	
	INIT_LIST_HEAD(&gestor->tareas);
	
	gestor->flags |= (1 << GESTOR_TAREA_ATTR_NUM_TAREAS);
	
	return gestor;
	
	
}

void gestor_tarea_free(struct gestor_tarea *gestor){
	
	struct tarea *t1, *t2;
	
	list_for_each_entry_safe(t1, t2, &gestor->tareas, head){
		list_del(&t1->head);
		tarea_free(t1);
	}
	
	xfree(gestor);
	
}

/*void reordena_tareas(struct gestor_tarea *gestor, uint32_t pos){
	int i;
	
	for(i= pos; i < gestor->num_tareas; i++){
		gestor->tareas[i] = gestor->tareas[i+1];
	}
}*/

void gestor_tarea_attr_unset_tarea(struct gestor_tarea *gestor, uint32_t pos){

	int i = 0;
	struct tarea *t1, *t2;

	if(pos < 0 || pos > gestor->num_tareas)		//erroneo, cambiar
		return;
	
	list_for_each_entry_safe(t1, t2, &gestor->tareas, head){
		
		if(i == pos){
			list_del(&t1->head);
			tarea_free(t1);
			break;
		}
		i++;
	}
	
	gestor->num_tareas--;
	
}
/*
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
}*/

void gestor_tarea_attr_set_data(struct gestor_tarea *gestor, uint16_t attr, 
				const void *data){
	
	struct tarea *t;
	
	if(attr > GESTOR_TAREA_ATTR_MAX)
		return;
	
	switch(attr){
	case GESTOR_TAREA_ATTR_TAREAS:
		if(gestor->num_tareas >= 10){
			printf("No es posible introducir más tareas \n");
			break;
		}
		
		t = (struct tarea *)data;
		
		list_add(&t->head, &gestor->tareas);
		
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
	
	int i = 0;
	struct tarea *t;
	
	if(!(gestor->flags & (1 << attr)))
		return NULL;
	switch(attr){
	case GESTOR_TAREA_ATTR_TAREAS:
		list_for_each_entry(t, &gestor->tareas, head){
			if(i == pos)
				break;
			i++;
		}
		return t;

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
	
	int ret=0;
	struct tarea *t;
	
	list_for_each_entry(t, &gestor->tareas, head){
		ret += tarea_snprintf(buf + ret, size - ret, t);
	}
	
	return ret;
}