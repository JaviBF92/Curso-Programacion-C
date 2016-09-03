
#include "../include/concesionario.h"
#include <gtk/gtk.h>

struct concesionario *con;
int creado;
int coches;

void nueva_ventana(void);
void atras(GtkWidget *ventana);
void nueva_ventana_crear(GtkWidget *ventana);
void nueva_ventana_modificar(GtkWidget *ventana);
void nueva_ventana_eliminar(GtkWidget *ventana);
void nombra_concesionario(GtkButton *widget, gpointer data);
void ventanaElimina(GtkWidget *ventana);
void elimina_concesionario(GtkWidget *ventana);
void crea_coche(GtkButton *widget, gpointer data);
void modifica_coche(GtkButton *widget, gpointer data);
void elimina_coche(GtkButton *widget, gpointer data);


int main(int argc, char *argv[])
{
	
	
	gtk_init(&argc, &argv);
	
	con = curso_concesionario_alloc();
	
	if(con == NULL){
		printf("El concesionario no se ha creado correctamente");
		return -1;
	}
	
	creado = 0;
	coches = 0;
	
	nueva_ventana();
	
	gtk_main();
	
	return 0;
}

void nueva_ventana(){
	
	GtkWidget *ventana;
	GtkWidget *botonCrear;
	GtkWidget *botonModificar;
	GtkWidget *botonEliminar;
	GtkWidget *botonSalir;
	GtkWidget *etiqueta;
	GtkWidget *conjVert;
	GtkWidget *conjHoriz1;
	GtkWidget *conjHoriz2;

	ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title((GtkWindow *)ventana, "Administrador de "\
			     "concesionario");
	
	botonCrear = gtk_button_new_with_label("Crear");
	botonModificar = gtk_button_new_with_label("Modificar");
	botonEliminar = gtk_button_new_with_label("Eliminar");
	botonSalir = gtk_button_new_with_label("Salir");
	
	etiqueta = gtk_label_new("Bienvenido a la herramienta de gestión del"\
				  " concesionario");
	
	conjVert = gtk_vbox_new(FALSE, 8);
	conjHoriz1 = gtk_hbox_new(FALSE, 8);
	conjHoriz2 = gtk_hbox_new(FALSE, 8);
	
	gtk_box_pack_start((GtkBox *)conjVert, etiqueta, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVert, conjHoriz1, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjHoriz1, botonCrear, FALSE, FALSE, 32);
	gtk_box_pack_start((GtkBox *)conjHoriz1, botonModificar, FALSE, FALSE, 32);
	gtk_box_pack_start((GtkBox *)conjHoriz1, botonEliminar, FALSE, FALSE, 32);
	gtk_box_pack_start((GtkBox *)conjVert, conjHoriz2, FALSE, FALSE, 32);
	gtk_box_pack_start((GtkBox *)conjHoriz2, botonSalir, FALSE, FALSE, 32);

	gtk_container_add((GtkContainer *)ventana, conjVert);
	
	g_signal_connect_swapped((GObject *)botonCrear, "clicked", (GCallback) nueva_ventana_crear, ventana);

	g_signal_connect_swapped((GObject *)botonModificar, "clicked", (GCallback) nueva_ventana_modificar, ventana);
	
	g_signal_connect_swapped((GObject *)botonEliminar, "clicked", (GCallback) nueva_ventana_eliminar, ventana);
	
	g_signal_connect_swapped((GObject *)botonSalir, "clicked", (GCallback) gtk_main_quit, NULL);
	
	
	
	gtk_widget_show_all(ventana);
}

void atras(GtkWidget *ventana){
	
	gtk_widget_destroy((GtkWidget *)ventana);
	
	nueva_ventana();
	
	
}

void nueva_ventana_crear(GtkWidget *ventana){
	
	GtkWidget *window;
	
	GtkWidget *etiq_conc;
	GtkWidget *etiq_coch;
	GtkWidget *etiq_dueno;
	GtkWidget *etiq_matricula;
	GtkWidget *etiq_marca;
	GtkWidget *etiq_id;
	GtkWidget *mensaje;
	
	GtkWidget *entr_dueno;
	GtkWidget *entr_id;
	GtkWidget *entr_matricula;
	GtkWidget *entr_marca;
	
	GtkWidget *conjVertL1;
	GtkWidget *conjHorL2a;
	GtkWidget *conjHorL2b;
	GtkWidget *conjHorL2c;
	GtkWidget *conjHorL2d;
	GtkWidget *conjHorL2e;

	
	GtkWidget *boton_crear_conc;
	GtkWidget *boton_crear_coche;
	GtkWidget *boton_salir;
	
	struct coche *c1;
	const gchar *compruebaid;
	
	GObject **obj;
	
	gtk_widget_destroy((GtkWidget *)ventana);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title((GtkWindow *)window, "Crear");
	
	etiq_conc = gtk_label_new("Concesionario");
	etiq_coch = gtk_label_new("Coche");
	etiq_dueno = gtk_label_new("Dueño:");
	etiq_matricula = gtk_label_new("Matrícula:");
	etiq_marca = gtk_label_new("Marca:");
	etiq_id = gtk_label_new("ID:");
	mensaje = gtk_label_new("Ya hay uno creado");
	
	boton_crear_conc = gtk_button_new_with_label("Crear");
	boton_crear_coche = gtk_button_new_with_label("Crear");
	boton_salir = gtk_button_new_with_label("Atrás");
	
	conjVertL1 = gtk_vbox_new(TRUE, 8);
	conjHorL2a = gtk_hbox_new(FALSE, 520);
	conjHorL2b = gtk_hbox_new(FALSE, 8);
	conjHorL2c = gtk_hbox_new(FALSE, 570);
	conjHorL2d = gtk_hbox_new(FALSE,8);
	conjHorL2e = gtk_hbox_new(FALSE,8);
	
	entr_dueno = gtk_entry_new();
	entr_matricula = gtk_entry_new();
	entr_marca = gtk_entry_new();
	entr_id = gtk_entry_new();
	
	obj = calloc(1,5 * sizeof(GObject));
	
	obj[0] = (GObject *) window;
	obj[1] = (GObject *) entr_dueno;
	obj[2] = (GObject *) entr_id;
	obj[3] = (GObject *) entr_matricula;
	obj[4] = (GObject *) entr_marca;
	
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2a, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2b, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2c, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2d, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2e, FALSE, FALSE, 4);

	gtk_box_pack_start((GtkBox *)conjHorL2a, etiq_conc, FALSE, FALSE, 4);	
	
	if(creado == 1){
		gtk_box_pack_start((GtkBox *)conjHorL2b, mensaje, FALSE, FALSE, 4);	
	}else{
		gtk_box_pack_start((GtkBox *)conjHorL2a, boton_crear_conc, FALSE, FALSE, 4);
		gtk_box_pack_start((GtkBox *)conjHorL2b, etiq_dueno, FALSE, FALSE, 4);
		gtk_box_pack_start((GtkBox *)conjHorL2b, entr_dueno, FALSE, FALSE, 0);
	}

	
	gtk_box_pack_start((GtkBox *)conjHorL2c, etiq_coch, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjHorL2c, boton_crear_coche, FALSE, FALSE, 4);
	
	gtk_box_pack_start((GtkBox *)conjHorL2d, etiq_id, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjHorL2d, entr_id, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjHorL2d, etiq_matricula, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjHorL2d, entr_matricula, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjHorL2d, etiq_marca, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjHorL2d, entr_marca, FALSE, FALSE, 4);

	gtk_box_pack_start((GtkBox *)conjHorL2e, boton_salir, FALSE, FALSE, 4);
	
	gtk_container_add((GtkContainer *)window, conjVertL1);
	
	g_signal_connect_swapped((GObject *)boton_salir, "clicked", (GCallback) atras, window);
		
	g_signal_connect((GObject *)boton_crear_conc, "clicked", (GCallback) nombra_concesionario, (gpointer) obj);
	
	g_signal_connect((GObject *)boton_crear_coche, "clicked", (GCallback) crea_coche, (gpointer) obj);
	
	
	gtk_widget_show_all(window);

}

void nueva_ventana_modificar(GtkWidget *ventana){
	
	GtkWidget *window;
	
	GtkWidget *etiq_conc;
	GtkWidget *etiq_coch;
	GtkWidget *etiq_dueno;
	GtkWidget *etiq_matricula;
	GtkWidget *etiq_marca;
	GtkWidget *mensaje_coche;
	GtkWidget *mensaje_concesionario;
	GtkWidget *entr_dueno;
	GtkWidget *entr_matricula;
	GtkWidget *entr_marca;
	
	GtkWidget *conjVertL1;
	GtkWidget *conjHorL2a;
	GtkWidget *conjHorL2b;
	GtkWidget *conjHorL2c;
	GtkWidget *conjHorL2ca;
	GtkWidget *conjHorL2d;
	GtkWidget *conjHorL2e;
	
	GtkWidget *combo;
	
	GtkWidget *boton_modif_conc;
	GtkWidget *boton_modif_coche;
	GtkWidget *boton_salir;
	
	GObject **obj;
	
	struct coche *c1;

	int i;
	int id;
	char *idchar;
	
	gtk_widget_destroy((GtkWidget *)ventana);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title((GtkWindow *)window, "Modificar");
	
	etiq_conc = gtk_label_new("Concesionario");
	
	etiq_coch = gtk_label_new("Coche");
	etiq_dueno = gtk_label_new("Dueño:");
	etiq_matricula = gtk_label_new("Matrícula:");
	etiq_marca = gtk_label_new("Marca:");
	mensaje_coche = gtk_label_new("No hay coches creados");
	mensaje_concesionario = gtk_label_new("No se ha creado el concesionario");
	
	boton_modif_conc = gtk_button_new_with_label("Modificar");
	boton_modif_coche = gtk_button_new_with_label("Modificar");
	boton_salir = gtk_button_new_with_label("Atrás");
	
	conjVertL1 = gtk_vbox_new(TRUE, 8);
	conjHorL2a = gtk_hbox_new(FALSE, 350);
	conjHorL2b = gtk_hbox_new(FALSE, 8);
	conjHorL2c = gtk_hbox_new(FALSE, 285);
	conjHorL2ca = gtk_hbox_new(FALSE, 8);
	conjHorL2d = gtk_hbox_new(FALSE,8);
	conjHorL2e = gtk_hbox_new(FALSE,8);
	
	entr_dueno = gtk_entry_new();
	entr_matricula = gtk_entry_new();
	entr_marca = gtk_entry_new();

	combo= gtk_combo_box_text_new();
	
	obj = calloc(1,5 * sizeof(GObject));
	
	obj[0] = (GObject *) window;
	obj[1] = (GObject *) entr_dueno;
	obj[2] = (GObject *) combo;
	obj[3] = (GObject *) entr_matricula;
	obj[4] = (GObject *) entr_marca;
	
	c1 = curso_coche_alloc();
	
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2a, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2b, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2c, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2d, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2e, FALSE, FALSE, 4);

	gtk_box_pack_start((GtkBox *)conjHorL2a, etiq_conc, FALSE, FALSE, 4);	
	
	
	if(creado == 0){
		
		gtk_box_pack_start((GtkBox *)conjHorL2b, mensaje_concesionario, FALSE, FALSE, 4);
		
	}else{
		
		gtk_entry_set_text((GtkEntry *)entr_dueno, curso_concesionario_attr_get_str(con,CURSO_CONCESIONARIO_ATTR_DUENO)); 
		
		gtk_box_pack_start((GtkBox *)conjHorL2a, boton_modif_conc, FALSE, FALSE, 4);
		
		gtk_box_pack_start((GtkBox *)conjHorL2b, etiq_dueno, FALSE, FALSE, 4);
		gtk_box_pack_start((GtkBox *)conjHorL2b, entr_dueno, FALSE, FALSE, 20);
	}
	
	gtk_box_pack_start((GtkBox *)conjHorL2c, conjHorL2ca, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjHorL2ca, etiq_coch, FALSE, FALSE, 4);
	
	if(coches ==0){
	
		gtk_box_pack_start((GtkBox *)conjHorL2d, mensaje_coche, FALSE, FALSE, 4);
		
	}else{
	
		for(i = 0; i < coches; i++){
			
			idchar = malloc(4);
			c1 = curso_concesionario_attr_get_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE, i);
			id = curso_coche_attr_get_u32(c1, CURSO_COCHE_ATTR_ID);
			snprintf(idchar, 4,"%d", id);
			
			gtk_combo_box_text_append_text((GtkComboBoxText *)combo, idchar);
			
		}
		
		gtk_box_pack_start((GtkBox *)conjHorL2ca, combo, FALSE, FALSE, 24);
		gtk_box_pack_start((GtkBox *)conjHorL2c, boton_modif_coche, FALSE, FALSE, 4);
	
		gtk_box_pack_start((GtkBox *)conjHorL2d, etiq_matricula, FALSE, FALSE, 4);
		gtk_box_pack_start((GtkBox *)conjHorL2d, entr_matricula, FALSE, FALSE, 4);
		gtk_box_pack_start((GtkBox *)conjHorL2d, etiq_marca, FALSE, FALSE, 4);
		gtk_box_pack_start((GtkBox *)conjHorL2d, entr_marca, FALSE, FALSE, 4);
		
	}

	gtk_box_pack_start((GtkBox *)conjHorL2e, boton_salir, FALSE, FALSE, 4);
	
	gtk_container_add((GtkContainer *)window, conjVertL1);
	
	g_signal_connect_swapped((GObject *)boton_salir, "clicked", (GCallback) atras, window);
	
	g_signal_connect((GObject *)boton_modif_conc, "clicked", (GCallback) nombra_concesionario, obj);
	
	g_signal_connect((GObject *)boton_modif_coche, "clicked", (GCallback) modifica_coche, obj);
	
	gtk_widget_show_all(window);
	
}

void nueva_ventana_eliminar(GtkWidget *ventana){
	
	GtkWidget *window;
	
	GtkWidget *etiq_conc;
	GtkWidget *etiq_coch;
	GtkWidget *etiq_nombredueno;
	GtkWidget *mensaje_coche;
	GtkWidget *mensaje_concesionario;
	
	GtkWidget *conjVertL1;
	GtkWidget *conjHorL2a;
	GtkWidget *conjHorL2b;
	GtkWidget *conjHorL2c;
	GtkWidget *conjHorL2d;
	GtkWidget *conjHorL2e;

	GtkWidget *combo;	
	
	GtkWidget *boton_elim_conc;
	GtkWidget *boton_elim_coche;
	GtkWidget *boton_salir;
	
	GObject **obj;	
	
	const char *dueno;
	
	int i;
	int id;
	char *idchar;
	struct coche *c1;
	
	gtk_widget_destroy((GtkWidget *)ventana);
	
	c1 = curso_coche_alloc();
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title((GtkWindow *)window, "Eliminar");
	
	etiq_conc = gtk_label_new("Concesionario");
	etiq_coch = gtk_label_new("Coche");
	mensaje_coche = gtk_label_new("No hay coches creados");
	mensaje_concesionario = gtk_label_new("No se ha creado el concesionario");
	
	boton_elim_conc = gtk_button_new_with_label("Eliminar");
	boton_elim_coche = gtk_button_new_with_label("Eliminar");
	boton_salir = gtk_button_new_with_label("Atrás");
	
	conjVertL1 = gtk_vbox_new(TRUE, 8);
	conjHorL2a = gtk_hbox_new(FALSE, 256);
	conjHorL2b = gtk_hbox_new(FALSE, 8);
	conjHorL2c = gtk_hbox_new(FALSE, 307);
	conjHorL2d = gtk_hbox_new(FALSE,8);
	conjHorL2e = gtk_hbox_new(FALSE,8);
	
	combo= gtk_combo_box_text_new();

	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2a, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2b, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2c, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2d, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)conjVertL1, conjHorL2e, FALSE, FALSE, 4);

	gtk_box_pack_start((GtkBox *)conjHorL2a, etiq_conc, FALSE, FALSE, 4);
	
	obj = calloc(1,2 * sizeof(GObject));
	
	obj[0] = (GObject *) window;
	obj[1] = (GObject *) combo;
	
	if(creado == 0){

		gtk_box_pack_start((GtkBox *)conjHorL2b, mensaje_concesionario, FALSE, FALSE, 4);
		
	}else{
		
		dueno = curso_concesionario_attr_get_str(con, CURSO_CONCESIONARIO_ATTR_DUENO);
		etiq_nombredueno = gtk_label_new(dueno);

		
		gtk_box_pack_start((GtkBox *)conjHorL2a, boton_elim_conc, FALSE, FALSE, 4);

		gtk_box_pack_start((GtkBox *)conjHorL2b, etiq_nombredueno, FALSE, FALSE, 4);		
		
	}

	gtk_box_pack_start((GtkBox *)conjHorL2c, etiq_coch, FALSE, FALSE, 4);
	
	if(coches == 0){
		
		gtk_box_pack_start((GtkBox *)conjHorL2d, mensaje_coche, FALSE, FALSE, 4);
		
	}else{
			
		for(i = 0; i < coches; i++){
			
			idchar = malloc(4);
			c1 = curso_concesionario_attr_get_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE, i);
			id = curso_coche_attr_get_u32(c1, CURSO_COCHE_ATTR_ID);
			snprintf(idchar, 4,"%d", id);
			
			gtk_combo_box_text_append_text((GtkComboBoxText *)combo, idchar);
			
		}
		
		gtk_box_pack_start((GtkBox *)conjHorL2c, boton_elim_coche, FALSE, FALSE, 4);
	
		gtk_box_pack_start((GtkBox *)conjHorL2d, combo, FALSE, FALSE, 4);

	}
	
	gtk_box_pack_start((GtkBox *)conjHorL2e, boton_salir, FALSE, FALSE, 4);
	
	gtk_container_add((GtkContainer *)window, conjVertL1);
	
	g_signal_connect_swapped((GObject *)boton_salir, "clicked", (GCallback) atras, window);
	
	g_signal_connect_swapped((GObject *)boton_elim_conc, "clicked", (GCallback) ventanaElimina, window);
	
	g_signal_connect((GObject *)boton_elim_coche, "clicked", (GCallback) elimina_coche, obj);
	
	gtk_widget_show_all(window);
	
}

void nombra_concesionario(GtkButton *widget, gpointer data){
	
	GObject **obj;
	const gchar *dueno;
	GtkWidget *entr_dueno2;
	
	obj = (GObject **)data;
	entr_dueno2 = (GtkWidget *)obj[1];
	
	dueno = gtk_entry_get_text((GtkEntry *)entr_dueno2);
	
	curso_concesionario_attr_set_str(con, CURSO_CONCESIONARIO_ATTR_DUENO, dueno);

	creado = 1;
	
	gtk_widget_destroy((GtkWidget *)obj[0]);
	nueva_ventana();
	
}

void ventanaElimina(GtkWidget *ventana){
	
	GtkWidget *window;
	GtkWidget *etiq;
	GtkWidget *botonSi;
	GtkWidget *botonNo;
	GtkWidget *vbox;
	
	gtk_widget_destroy((GtkWidget *)ventana);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title((GtkWindow *)window, "Confirmación");
	
	etiq = gtk_label_new("Al eliminar el concesionario \ntambién se eliminarán \ntodos los coches guardados \n¿Estás seguro?");
	
	botonSi = gtk_button_new_with_label("Eliminar");
	botonNo = gtk_button_new_with_label("Atrás");
	
	vbox = gtk_vbox_new(false, 8);
	
	gtk_box_pack_start((GtkBox *)vbox, etiq, FALSE, FALSE, 4);	
	gtk_box_pack_start((GtkBox *)vbox, botonSi, FALSE, FALSE, 4);
	gtk_box_pack_start((GtkBox *)vbox, botonNo, FALSE, FALSE, 4);
	
	gtk_container_add((GtkContainer *)window, vbox);
	
	g_signal_connect_swapped((GObject *)botonSi, "clicked", (GCallback) elimina_concesionario, window);
	g_signal_connect_swapped((GObject *)botonNo, "clicked", (GCallback) nueva_ventana_eliminar, window);
	
	gtk_widget_show_all(window);
	
}

void elimina_concesionario(GtkWidget *ventana){
	
	gtk_widget_destroy((GtkWidget *)ventana);
	
	curso_concesionario_free(con);
	
	con = curso_concesionario_alloc();
	
	creado = 0;
	coches = 0;
	
	if(con == NULL){
		printf("El concesionario no se ha creado correctamente");
		return ;
	}
	
	nueva_ventana();
	
}

void crea_coche(GtkButton *widget, gpointer data){
	
	GObject **obj;
	const gchar *id;
	const gchar *matr;
	const gchar *marca;
	GtkWidget *entr_id2;
	GtkWidget *entr_matricula2;
	GtkWidget *entr_marca2;
	struct coche *c1;
	char buf[100];
	
	c1 = curso_coche_alloc();
	
	obj = (GObject **)data;
	entr_id2 = (GtkWidget *)obj[2];
	entr_matricula2 = (GtkWidget *)obj[3];
	entr_marca2 = (GtkWidget *)obj[4];
	
	id = gtk_entry_get_text((GtkEntry *)entr_id2);
	matr = gtk_entry_get_text((GtkEntry *)entr_matricula2);
	marca = gtk_entry_get_text((GtkEntry *)entr_marca2);
	
	curso_coche_attr_set_u32(c1, CURSO_COCHE_ATTR_ID, atoi(id));
	curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MATRICULA, matr);
	curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MARCA, marca);
	
	coches++;
	
	curso_concesionario_attr_set_coche(con,CURSO_CONCESIONARIO_ATTR_COCHE, c1);
	
	curso_coche_snprintf(buf, 100, c1);
	printf("%s \n", buf);
	
	gtk_widget_destroy((GtkWidget *)obj[0]);
	nueva_ventana();
	
}

void modifica_coche(GtkButton *widget, gpointer data){
	
	GObject **obj;
	const gchar *id;
	const gchar *matr;
	const gchar *marca;
	int numid;
	int idfor;
	int i;
	GtkWidget *combo;
	GtkWidget *entr_matricula2;
	GtkWidget *entr_marca2;
	struct coche *c1;
	struct coche *c2;
	
	c1 = curso_coche_alloc();
	c2 = curso_coche_alloc(); 
	
	obj = (GObject **)data;
	
	char buf[100];
	
	combo = (GtkWidget *)obj[2];
	entr_matricula2 = (GtkWidget *)obj[3];
	entr_marca2 = (GtkWidget *)obj[4];
	
	id = gtk_combo_box_text_get_active_text((GtkComboBoxText *) combo);
	matr = gtk_entry_get_text((GtkEntry *)entr_matricula2);
	marca = gtk_entry_get_text((GtkEntry *)entr_marca2);
	
	if( id != NULL){
		
		numid = atoi(id);
		
		for(i = 0; i < coches; i++){
			
			c1 = curso_concesionario_attr_get_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE, i);
			
			idfor = curso_coche_attr_get_u32(c1, CURSO_COCHE_ATTR_ID);
			
			if(idfor == numid)
				break;
			
		}
		
		curso_concesionario_attr_unset_coche(con, i);
		
		curso_coche_attr_set_u32(c2, CURSO_COCHE_ATTR_ID, numid);
		curso_coche_attr_set_str(c2, CURSO_COCHE_ATTR_MATRICULA, matr);
		curso_coche_attr_set_str(c2, CURSO_COCHE_ATTR_MARCA, marca);
		
		curso_concesionario_attr_set_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE, c2);
		
		curso_coche_snprintf(buf, 100, c1);
		printf("%s \n", buf);
		
		gtk_widget_destroy((GtkWidget *)obj[0]);
		nueva_ventana();
		
	}
	
}

void elimina_coche(GtkButton *widget, gpointer data){
	
	GObject **obj;
	
	GtkWidget *combo;
	
	const gchar *id;
	int numid;
	int i;
	int idfor;
	struct coche *c1;

	obj = (GObject **)data;
	
	combo = (GtkWidget *)obj[1];
	
	c1 = curso_coche_alloc();
	
	id = gtk_combo_box_text_get_active_text((GtkComboBoxText *) combo);
	
	if(id != NULL){
		
		numid = atoi(id);
		
		for(i = 0; i < coches; i++){
			
			c1 = curso_concesionario_attr_get_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE, i);
			
			idfor = curso_coche_attr_get_u32(c1, CURSO_COCHE_ATTR_ID);
			
			if(idfor == numid)
				break;
			
		}
		
		curso_concesionario_attr_unset_coche(con, i);
		
		coches--;
		
		gtk_widget_destroy((GtkWidget *)obj[0]);
		nueva_ventana();
		
	}
	
}