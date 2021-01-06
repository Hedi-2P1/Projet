#ifdef HAVE_CONFIG_H
#include <config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"capteur.h"
#include<gtk/gtk.h>

enum
{ 
	EIDENTIFIANT,
	EMARQUE,
	EDATE,
	ETYPE,
	EVALEUR,
	EMODE,
        ESENSIBILITE,
	COLUMNS,
};



///////////////////////////////////////////////
void ajouter_capteur(capteur c )
{
FILE *f;
f = fopen("capteur.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s \n",c.identifiant,c.marque,c.date,c.type,c.valeur,c.mode,c.sensibilite);
fclose(f);
}
}
///////////////////////////////////////////////
void ajouter_capteur_temp(capteur c )
{
FILE *f;
f = fopen("temperature.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s \n",c.identifiant,c.date,c.valeur);
fclose(f);
}
}
///////////////////////////////////////////////
void ajouter_capteur_hum(capteur c )
{
FILE *f;
f = fopen("humidite.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s \n",c.identifiant,c.date,c.valeur);
fclose(f);
}
}
///////////////////////////////////////////////
void afficher_capteur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char identifiant[30] ;
	char marque[30];
	char date[30];
	char type[30];
	char valeur[30];
	char mode[30];
	char sensibilite[30];     
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EIDENTIFIANT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("marque", renderer, "text",EMARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	  renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("valeur", renderer, "text",EVALEUR,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mode", renderer, "text",EMODE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("sensibilite", renderer, "text",ESENSIBILITE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 




	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("capteur.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("capteur.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s \n",identifiant,marque,date,type,valeur,mode,sensibilite)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EIDENTIFIANT, identifiant, EMARQUE,marque, 	EDATE,date,ETYPE,type,EVALEUR,valeur,EMODE,mode,ESENSIBILITE,sensibilite, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}





}
///////////////////////////////////////////////
void supprimer_capteur(capteur c)
///////////////////////////////////////////////
{
capteur c2;
FILE *f,*g;
	f=fopen("capteur.txt","r");
	g=fopen("users2.txt","w");
	if( f==NULL  || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s \n",c2.identifiant,c2.marque,c2.date,c2.type,c2.valeur,c2.mode,c2.sensibilite)!=EOF)
		{
			if (strcmp(c.identifiant,c2.identifiant)!=0 || strcmp(c.marque,c2.marque)!=0 || strcmp(c.date,c2.date)!=0 || strcmp(c.type,c2.type)!=0 || strcmp(c.valeur,c2.valeur)!=0|| strcmp(c.mode,c2.mode)!=0|| strcmp(c.sensibilite,c2.sensibilite)!=0)
			fprintf(g,"%s %s %s %s %s %s %s \n",c2.identifiant,c2.marque,c2.date,c2.type,c2.valeur,c2.mode,c2.sensibilite);
		}
		fclose(f);
		fclose(g);
	
remove("capteur.txt");
rename("users2.txt","capteur.txt");
	}



}


void changer_ca (char achanger[50],char critere[50],char identifiant[50]){      
capteur c1;
FILE *fp, *temporaire;
temporaire=fopen ("Temporaire.txt","a");
fp=fopen ("capteur.txt","r+");
while (fscanf(fp,"%s %s %s %s %s %s %s\n",c1.identifiant,c1.marque,c1.date,c1.type,c1.valeur,c1.mode,c1.sensibilite)!=EOF)
{
if (strcmp(c1.identifiant,identifiant)==0){
if(strcmp(critere,"identifiant")==0)   
{       
strcpy(c1.identifiant,achanger);}
if(strcmp(critere,"marque")==0)    
{      
strcpy(c1.marque,achanger);     }
if(strcmp(critere,"date")==0)    
{       
strcpy(c1.date,achanger);     }
if(strcmp(critere,"type")==0)    
{      
   strcpy(c1.type,achanger);}     
if(strcmp(critere,"valeur")==0)    
{    strcpy(c1.valeur,achanger);     }
if(strcmp(critere,"mode")==0)    
{      strcpy(c1.mode,achanger);    } 
}
if(strcmp(critere,"sensibilite")==0)    
{      strcpy(c1.sensibilite,achanger);    } 

fprintf(temporaire,"%s %s %s %s %s %s %s\n",c1.identifiant,c1.marque,c1.date,c1.type,c1.valeur,c1.mode,c1.sensibilite);
}
fclose(temporaire);
fclose(fp);
remove ("capteur.txt");
rename ("Temporaire.txt","capteur.txt");
}



void recherche_ca(GtkWidget *liste,char id[50])
{
        GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store;
        char identifiant[30];
	char marque[30];
	char date[30];
	char type[30];
	char valeur[30];
	char mode[30];
	char sensibilite[30];
        store=NULL;
        FILE *f;
        store=gtk_tree_view_get_model(liste);

        if (store==NULL)
        {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EIDENTIFIANT,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("marque", renderer, "text",EMARQUE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("valeur", renderer, "text",EVALEUR,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

       renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mode", renderer, "text",EMODE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("sensibilite", renderer, "text",ESENSIBILITE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	}
        store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        f=fopen("capteur.txt","r");
        if(f==NULL)
        {
                return;
        }
        else
        {
                f= fopen("capteur.txt","a+");
                while(fscanf(f,"%s %s %s %s %s %s %s \n",identifiant,marque,date,type,valeur,mode,sensibilite)!=EOF)
                {if(strcmp(id,identifiant)==0){
                        gtk_list_store_append(store, &iter);
                        gtk_list_store_set(store,&iter, EIDENTIFIANT, identifiant, EMARQUE,marque, 	EDATE,date,ETYPE,type,EVALEUR,valeur,EMODE,mode,ESENSIBILITE,sensibilite,-1);

                }}
                fclose(f);
                gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
                g_object_unref (store);
        }


}
