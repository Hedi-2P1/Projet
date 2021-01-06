#ifdef HAVE_CONFIG_H
#include <config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"plante.h"
#include<gtk/gtk.h>

enum
{ 
	EREF,
	ENOM,
	EFAMILLE,
	EDATE,
	EADRESSE,
	EQUANTITE,
	ESOL,
	COLUMNS,
};



///////////////////////////////////////////////
void ajouter_plante(plante p)
{
FILE *f;
f = fopen("plante.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s \n",p.ref,p.nom,p.famille,p.date_naissance,p.adresse,p.quantite,p.sol);

fclose(f);
}
}
///////////////////////////////////////////////
void afficher_plante(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char ref[30];
	char nom[30];
	char famille[30];
	char date[30];
	char adresse[30];
	char quantite[30];
	char sol[30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ref", renderer, "text",EREF,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("famille", renderer, "text",EFAMILLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	  renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",EQUANTITE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("feuille", renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("sol", renderer, "text",ESOL,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 




	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("plante.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("plante.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s \n",ref,nom,famille,date,adresse,quantite,sol)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EREF, ref, ENOM, nom, 	EFAMILLE,famille,EDATE,date,EADRESSE,adresse,EQUANTITE,quantite,ESOL,sol, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}





}
///////////////////////////////////////////////
void supprimer_plante(plante p)
///////////////////////////////////////////////
{
plante p2;
FILE *f,*g;
	f=fopen("plante.txt","r");
	g=fopen("users2.txt","w");
	if( f==NULL  || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s \n",p2.ref,p2.nom,p2.famille,p2.date_naissance,p2.adresse,p2.quantite,p2.sol)!=EOF)
		{
			if (strcmp(p.ref,p2.ref)!=0 || strcmp(p.nom,p2.nom)!=0 || strcmp(p.famille,p2.famille)!=0 || strcmp(p.date_naissance,p2.date_naissance)!=0 || strcmp(p.adresse,p2.adresse)!=0|| strcmp(p.quantite,p2.quantite)!=0|| strcmp(p.sol,p2.sol)!=0)
			fprintf(g,"%s %s %s %s %s %s %s \n",p2.ref,p2.nom,p2.famille,p2.date_naissance,p2.adresse,p2.quantite,p2.sol);
		}
		fclose(f);
		fclose(g);
	
remove("plante.txt");
rename("users2.txt","plante.txt");
	}



}


void changer (char achanger[50],char critere[50],char ref[50]){      
plante p1;
FILE *fp, *temporaire;
temporaire=fopen ("Temporaire.txt","a");
fp=fopen ("plante.txt","r+");
while (fscanf(fp,"%s %s %s %s %s %s %s\n",p1.ref,p1.nom,
p1.famille,p1.date_naissance,
p1.adresse,p1.famille,p1.sol)!=EOF)
{
if (strcmp(p1.ref,ref)==0){
if(strcmp(critere,"ref")==0)   
{       
strcpy(p1.ref,achanger);}
if(strcmp(critere,"nom")==0)    
{      
strcpy(p1.nom,achanger);     }
if(strcmp(critere,"famille")==0)    
{       
strcpy(p1.famille,achanger);     }
if(strcmp(critere,"date")==0)    
{      
   strcpy(p1.date_naissance,achanger);}     
if(strcmp(critere,"feuille")==0)    
{    strcpy(p1.adresse,achanger);     }
if(strcmp(critere,"famille")==0)    
{      strcpy(p1.famille,achanger);    } 
}
if(strcmp(critere,"sol")==0)    
{      strcpy(p1.sol,achanger);    } 

fprintf(temporaire,"%s %s %s %s %s %s %s\n",p1.ref,p1.nom,
p1.famille,p1.date_naissance,
p1.adresse,p1.famille,p1.sol);
}
fclose(temporaire);
fclose(fp);
remove ("plante.txt");
rename ("Temporaire.txt","plante.txt");
}



void recherche(GtkWidget *liste,char id[50])
{
        GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store;
        char ref[30];
        char nom[30];
        char famille[30];
        char date[30];
        char adresse[30];
        char quantite[30];
	char sol[30];
        store=NULL;
        FILE *f;
        store=gtk_tree_view_get_model(liste);

        if (store==NULL)
        {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ref", renderer, "text",EREF,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("famille", renderer, "text",EFAMILLE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",EQUANTITE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

       renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("adrese", renderer, "text",EADRESSE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("sol", renderer, "text",ESOL,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	}
        store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        f=fopen("plante.txt","r");
        if(f==NULL)
        {
                return;
        }
        else
        {
                f= fopen("plante.txt","a+");
                while(fscanf(f,"%s %s %s %s %s %s %s \n",ref,nom,famille,date,adresse,quantite,sol)!=EOF)
                {if(strcmp(id,ref)==0){
                        gtk_list_store_append(store, &iter);
                        gtk_list_store_set(store,&iter, EREF, ref, ENOM, nom,   EFAMILLE,famille,EDATE,date,EADRESSE,adresse,EFAMILLE,famille,ESOL,sol,-1);

                }}
                fclose(f);
                gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
                g_object_unref (store);
        }


}
