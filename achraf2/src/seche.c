#ifdef HAVE_CONFIG_H
#include <config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seche.h"
#include<gtk/gtk.h>

enum
{ 
	EID,
	EJOUR,
	EMOIS,
	EANNEE,
	EMAX,
	COLUMNS,
};



void afficher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store;
        char id[30];
        char jour[30];
        char mois[30];
        char annee[30];
        char value[30];
	char max[30];
	char j[30];
	char m[30];
	char a[30];
	char i[30];

        store=NULL;
        FILE *f;
        store=gtk_tree_view_get_model(liste);

        if (store==NULL)
        {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

       renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("max", renderer, "text",EMAX,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);








	}
store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f= fopen("temperature.txt","a+");
if (f)
{ 		 
fscanf(f,"%s %s %s %s %s",id,jour,mois,annee,max);
		while(fscanf(f,"%s %s %s %s %s",id,jour,mois,annee,value)!=EOF)
                {
			if( atof(max) < atof(value) )
		{
		strcpy(max,value);
		strcpy(j,jour);
		strcpy(m,mois);
		strcpy(a,annee);
		strcpy(i,id);
                }
	}


gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,EID,i,EJOUR,j,EMOIS,m,EANNEE,a,EMAX,max,-1);
                fclose(f);
                gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
                g_object_unref (store);
        }

}

