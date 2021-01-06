#ifdef HAVE_CONFIG_H
#include <config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Ouvrier.h"
#include<gtk/gtk.h>

enum
{ 
	ENom,
	ECin,
	EDate_naissance,
	EUsername,
	ESpec,
	ENbre,
	EDate_recru,
	EGenre,
	COLUMNS,
};


void ajouter_ouvrier(ouvrier o)
{
FILE *f;
f = fopen("ouvrier.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s \n",o.nom,o.cin,o.date_naissance,o.username,o.spec,o.nbre,o.date_recru,o.genre);
fclose(f);
}
}


void afficher_ouvrier(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char cin[30];
	char date_naissance[30];
	char username[30];
	char spec[30];
	char nbre[2];
	char date_recru[30];
	char genre [30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text",EUsername,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENom,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECin,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",EDate_naissance,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Spécialité", renderer, "text",ESpec,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jours de Travail", renderer, "text",ENbre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de recrutement", renderer, "text",EDate_recru,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text",EGenre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  			  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("ouvrier.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("ouvrier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",nom,cin,date_naissance,username,spec,nbre,date_recru,genre)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENom,nom,ECin,cin,EDate_naissance,date_naissance,EUsername,username,ESpec,spec,ENbre,nbre,EDate_recru,date_recru,EGenre,genre,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}


void supprimer_ouvrier(ouvrier o)
{
ouvrier o2;
FILE *f,*g;
	f=fopen("ouvrier.txt","r");
	g=fopen("users2.txt","w");
	if( f==NULL  || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",o2.nom,o2.cin,o2.date_naissance,o2.username,o2.spec,o2.nbre,o2.date_recru,o2.genre)!=EOF)
		{
			if (strcmp(o.username,o2.username)!=0)
			fprintf(g,"%s %s %s %s %s %s %s %s \n",o2.nom,o2.cin,o2.date_naissance,o2.username,o2.spec,o2.nbre,o2.date_recru,o2.genre);
		}
		fclose(f);
		fclose(g);
remove("ouvrier.txt");
rename("users2.txt","ouvrier.txt");
	}
}


void create_date(Date D, char date[15])
{
char Jours[5];
char Mois[5];
char Annee[5];
char s[]="/";
sprintf(Jours,"%d",D.Jours);
sprintf(Mois,"%d",D.Mois);
sprintf(Annee,"%d",D.Annee);
strcpy(date,Jours);
strcat(date,s);
strcat(date,Mois);
strcat(date,s);
strcat(date,Annee);
}


void JoursdeTravail(char journee[15])
{
char Jours[100];
int a=0;
strcat(Jours,";");
strcat(Jours,journee);
a ++;
}

void recherche_id(GtkWidget *liste,char info[50])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char cin[30];
	char date_naissance[30];
	char username[30];
	char spec[30];
	char nbre[2];
	char date_recru[30];
	char genre [30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENom,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECin,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",EDate_naissance,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text",EUsername,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Spécialité", renderer, "text",ESpec,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jours de Travail", renderer, "text",ENbre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de recrutement", renderer, "text",EDate_recru,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text",EGenre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  			  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("ouvrier.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("ouvrier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,cin,date_naissance,username,spec,nbre,date_recru,genre)!=EOF)
		{if(strcmp(info,username)==0){
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENom,nom,ECin,cin,EDate_naissance,date_naissance,EUsername,username,ESpec,spec,ENbre,nbre,EDate_recru,date_recru,EGenre,genre,-1);
		}}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

void recherche_nom(GtkWidget *liste,char info[50])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char cin[30];
	char date_naissance[30];
	char username[30];
	char spec[30];
	char nbre[2];
	char date_recru[30];
	char genre [30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENom,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECin,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",EDate_naissance,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text",EUsername,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Spécialité", renderer, "text",ESpec,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jours de Travail", renderer, "text",ENbre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de recrutement", renderer, "text",EDate_recru,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text",EGenre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  			  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("ouvrier.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("ouvrier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,cin,date_naissance,username,spec,nbre,date_recru,genre)!=EOF)
		{if(strcmp(info,nom)==0){
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENom,nom,ECin,cin,EDate_naissance,date_naissance,EUsername,username,ESpec,spec,ENbre,nbre,EDate_recru,date_recru,EGenre,genre,-1);
		}}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

void recherche_cin(GtkWidget *liste,char info[50])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char cin[30];
	char date_naissance[30];
	char username[30];
	char spec[30];
	char nbre[2];
	char date_recru[30];
	char genre [30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENom,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECin,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",EDate_naissance,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text",EUsername,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Spécialité", renderer, "text",ESpec,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jours de Travail", renderer, "text",ENbre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de recrutement", renderer, "text",EDate_recru,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text",EGenre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  			  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("ouvrier.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("ouvrier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,cin,date_naissance,username,spec,nbre,date_recru,genre)!=EOF)
		{if(strcmp(info,cin)==0){
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENom,nom,ECin,cin,EDate_naissance,date_naissance,EUsername,username,ESpec,spec,ENbre,nbre,EDate_recru,date_recru,EGenre,genre,-1);
		}}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

void recherche_spec(GtkWidget *liste,char info[50])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char cin[30];
	char date_naissance[30];
	char username[30];
	char spec[30];
	char nbre[2];
	char date_recru[30];
	char genre [30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENom,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECin,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",EDate_naissance,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text",EUsername,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Spécialité", renderer, "text",ESpec,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jours de Travail", renderer, "text",ENbre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de recrutement", renderer, "text",EDate_recru,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text",EGenre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  			  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("ouvrier.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("ouvrier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,cin,date_naissance,username,spec,nbre,date_recru,genre)!=EOF)
		{if(strcmp(info,spec)==0){
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENom,nom,ECin,cin,EDate_naissance,date_naissance,EUsername,username,ESpec,spec,ENbre,nbre,EDate_recru,date_recru,EGenre,genre,-1);
		}}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

void recherche_jt(GtkWidget *liste,char info[50])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
	char cin[30];
	char date_naissance[30];
	char username[30];
	char spec[30];
	char nbre[2];
	char date_recru[30];
	char genre [30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENom,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECin,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",EDate_naissance,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text",EUsername,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Spécialité", renderer, "text",ESpec,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jours de Travail", renderer, "text",ENbre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date de recrutement", renderer, "text",EDate_recru,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text",EGenre,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  			  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("ouvrier.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("ouvrier.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,cin,date_naissance,username,spec,nbre,date_recru,genre)!=EOF)
		{if(strcmp(info,nbre)==0){
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENom,nom,ECin,cin,EDate_naissance,date_naissance,EUsername,username,ESpec,spec,ENbre,nbre,EDate_recru,date_recru,EGenre,genre,-1);
		}}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

void remplace(ouvrier o, ouvrier o1)
{
ouvrier o2;
FILE *f,*g;
	f=fopen("ouvrier.txt","r");
	g=fopen("users2.txt","w");
	if( f==NULL  || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",o2.nom,o2.cin,o2.date_naissance,o2.username,o2.spec,o2.nbre,o2.date_recru,o2.genre)!=EOF)
		{
			if (strcmp(o.username,o2.username)==0)
			fprintf(g,"%s %s %s %s %s %s %s %s \n",o1.nom,o1.cin,o1.date_naissance,o1.username,o1.spec,o1.nbre,o1.date_recru,o1.genre);
			else fprintf(g,"%s %s %s %s %s %s %s %s \n",o2.nom,o2.cin,o2.date_naissance,o2.username,o2.spec,o2.nbre,o2.date_recru,o2.genre);
		}
		fclose(f);
		fclose(g);
remove("ouvrier.txt");
rename("users2.txt","ouvrier.txt");
	}
}

void ajouter_controle(controle c)
{
FILE *f;
f = fopen("controle.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %d %d %d %d \n",c.username,c.JC,c.MC,c.AC,c.verif);
fclose(f);
}
}

int verifier_controle(char user[30])
{
ouvrier o2;
FILE *f;
int test=0;
	f=fopen("ouvrier.txt","r");
	if(f==NULL)
		return;
	else
	{
		while ((fscanf(f,"%s %s %s %s %s %s %s %s \n",o2.nom,o2.cin,o2.date_naissance,o2.username,o2.spec,o2.nbre,o2.date_recru,o2.genre)!=EOF) && (test==0))
		{
			if (strcmp(user,o2.username)==0)
		test=1;
		}
		fclose(f);
	}
return (test);
}
