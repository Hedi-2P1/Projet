#include<gtk/gtk.h>


typedef struct 
{
char type[30];
char race[30];
char etat[30];
char date_naissance[30];
char matricule[30];
char poids[30];
char genre[30]
}troupeau;

void ajouter_troupeau(troupeau t);
void afficher_troupeau(GtkWidget *liste);
void supprimer_troupeau(troupeau t);
void changer_t (char achanger[50],char critere[50],char type[50]);
void recherche_t(GtkWidget *liste,char mat[50]);

