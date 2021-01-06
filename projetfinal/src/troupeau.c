#ifdef HAVE_CONFIG_H
#include <config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"troupeau.h"
#include<gtk/gtk.h>

enum
{ 
	ETYPE,
	ERACE,
	EGENRE,
	EDATE,
	EMATRICULE,
	EETAT,
	EPOIDS,
	COLUMNS,
};



///////////////////////////////////////////////
void ajouter_troupeau(troupeau t)
{
FILE *f;
f = fopen("troupeau.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s \n",t.matricule,t.race,t.genre,t.date_naissance,t.etat,t.poids,t.type);
fclose(f);
}
}
///////////////////////////////////////////////
void afficher_troupeau(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char type[30];
	char race[30];
	char genre[30];
	char date[30];
	char poids[30];
	char matricule[30];
	char etat[30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("matricule", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("race", renderer, "text",ERACE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text",EGENRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text",EETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	  renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("poids", renderer, "text",EMATRICULE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",EPOIDS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 




	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("troupeau.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("troupeau.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s\n",type,race,genre,date,etat,matricule,poids)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ETYPE, type, ERACE, race,EPOIDS,poids,EDATE,date,EMATRICULE,matricule,EETAT,etat,EGENRE,genre, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}



}
///////////////////////////////////////////////
void supprimer_troupeau(troupeau t)
///////////////////////////////////////////////
{
troupeau t2;
FILE *f,*g;
	f=fopen("troupeau.txt","r");
	g=fopen("users2.txt","w");
	if( f==NULL  || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s \n",t2.type,t2.race,t2.etat,t2.date_naissance,t2.poids,t2.matricule,t2.genre)!=EOF)
		{
//			if (strcmp(t.type,t2.type)!=0 || strcmp(t.race,t2.race)!=0 || strcmp(t.date,t2.etat)!=0 || strcmp(t.genre,t2.date_naissance)!=0 || strcmp(t.poids,t2.poids)!=0|| strcmp(t.etat,t2.matricule)!=0|| strcmp(t.matricule,t2.genre)!=0)
 if (strcmp(t.type,t2.type)!=0)
	fprintf(g,"%s %s %s %s %s %s %s \n",t2.type,t2.race,t2.etat,t2.date_naissance,t2.poids,t2.matricule,t2.genre);
		}
		fclose(f);
		fclose(g);
	
remove("troupeau.txt");
rename("users2.txt","troupeau.txt");
	}



}


void changer_t (char achanger[50],char critere[50],char type[50]){      
troupeau t1;
FILE *fp, *temporaire;
temporaire=fopen ("Temporaire.txt","a");
fp=fopen ("troupeau.txt","r+");
while (fscanf(fp,"%s %s %s %s %s %s %s\n",t1.type,t1.race,
t1.etat,t1.date_naissance,
t1.matricule,t1.poids,t1.genre)!=EOF)
{
if (strcmp(t1.type,type)==0){
if(strcmp(critere,"type")==0)   
{       
strcpy(t1.genre,achanger);}
if(strcmp(critere,"race")==0)    
{      
strcpy(t1.race,achanger);     }
if(strcmp(critere,"etat")==0)    
{       
strcpy(t1.matricule,achanger);     }
if(strcmp(critere,"date")==0)    
{      
   strcpy(t1.date_naissance,achanger);}     
if(strcmp(critere,"matricule")==0)    
{    strcpy(t1.type,achanger);     }
if(strcmp(critere,"poids")==0)    
{      strcpy(t1.poids,achanger);    } 
}
if(strcmp(critere,"genre")==0)    
{      strcpy(t1.etat,achanger);    } 

fprintf(temporaire,"%s %s %s %s %s %s %s\n",t1.type,t1.race,
t1.etat,t1.date_naissance,
t1.matricule,t1.poids,t1.genre);
}
fclose(temporaire);
fclose(fp);
remove ("troupeau.txt");
rename ("Temporaire.txt","troupeau.txt");
}


void recherche_t(GtkWidget *liste,char mat[50])
{
        GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store;
        char type[30];
        char race[30];
        char genre[30];
        char date[30];
        char poids[30];
        char matricule[30];
	char etat[30];
        store=NULL;
        FILE *f;
        store=gtk_tree_view_get_model(liste);

        if (store==NULL)
        {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("race", renderer, "text",ERACE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("matricule", renderer, "text",EMATRICULE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("poids", renderer, "text",EPOIDS,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

       renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text",EETAT,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text",EGENRE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	}
        store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        f=fopen("troupeau.txt","r");
        if(f==NULL)
        {
                return;
        }
        else
        {
                f= fopen("troupeau.txt","a+");
                while(fscanf(f,"%s %s %s %s %s %s %s \n",type,race,etat,date,matricule,poids,genre)!=EOF)
                {if(strcmp(mat,type)==0){
                        gtk_list_store_append(store, &iter);
                        gtk_list_store_set(store,&iter, ETYPE, type, ERACE, race,   EETAT,etat,EDATE,date,EMATRICULE,matricule,EPOIDS,poids,EGENRE,genre,-1);

                }}
                fclose(f);
                gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
                g_object_unref (store);
        }


}
