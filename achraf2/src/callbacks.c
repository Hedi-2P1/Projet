#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "seche.h"

void
on_button1_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
{
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher(treeview1);
}
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkTreeIter iter;        
	gchar* id;	
	gchar* jour;
        gchar* mois;
        gchar* annee;
        gchar* value;
	seche s;

        GtkTreeModel *model = gtk_tree_view_get_model(treeview);
        if (gtk_tree_model_get_iter(model, &iter ,path))
        {

                gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&jour,2,&mois,3,&annee,4,&value,-1);
                afficher(treeview);
        }

}

