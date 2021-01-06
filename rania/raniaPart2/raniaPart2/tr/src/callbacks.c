#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "troupeau.h"
#include <string.h>
#include <stdlib.h>















void
on_button_aff_clicked                   (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input ;

char mat[100];
input = lookup_widget(objet_graphique, "entry_mat_n") ;

strcpy(mat,gtk_entry_get_text(GTK_ENTRY(input)));

GtkWidget* output ;
output = lookup_widget(objet_graphique, "label_aff") ;

calcul(mat,output);
}



