#include "tarea.h"

enum{
	GESTOR_TAREA_ATTR_TAREAS,
	GESTOR_TAREA_ATTR_NUM_TAREAS,
	__GESTOR_TAREA_ATTR_MAX
};

#define GESTOR_TAREA_ATTR_MAX (__GESTOR_TAREA_ATTR_MAX - 1)

struct gestor_tarea;

struct gestor_tarea *gestor_tarea_alloc(void);
void gestor_tarea_free(struct gestor_tarea *);

void gestor_tarea_attr_unset_tarea(struct gestor_tarea *gestor, uint32_t pos);

void gestor_tarea_attr_set_str(struct gestor_tarea *gestor, uint16_t attr, const char *data);
void gestor_tarea_attr_set_tarea(struct gestor_tarea *gestor, uint16_t attr, struct tarea *t);

uint32_t gestor_tarea_alloc_attr_get_u32(struct gestor_tarea *gestor, uint16_t attr);

const char *gestor_tarea_attr_get_str(struct gestor_tarea *gestor, uint16_t attr);

struct tarea *gestor_tarea_attr_get_tarea(struct gestor_tarea *gestor, uint16_t attr, uint32_t pos);

int gestor_tarea_snprintf(char *buf, size_t size, struct gestor_tarea *ges);
