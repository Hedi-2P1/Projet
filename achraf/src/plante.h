#include<gtk/gtk.h>


typedef struct 
{
char ref[30];
char nom[30];
char famille[30];
char date_naissance[30];
char adresse[30];
char quantite[30];
char sol[30]
}plante;

void ajouter_plante(plante p);
void afficher_plante(GtkWidget *liste);
void supprimer_plante(plante p);
void changer (char achanger[50],char critere[50],char cin[50]);
void recherche(GtkWidget *liste,char id[50]);

