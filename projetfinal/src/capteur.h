#include<gtk/gtk.h>


typedef struct 
{
char identifiant[30];
char marque[30];
char date[30];
char type[30];
char valeur[30];
char mode[30];
char sensibilite[30]
}capteur;

void ajouter_capteur(capteur c );
void afficher_capteur(GtkWidget *liste);
void supprimer_capteur(capteur c);
void changer_ca (char achanger[50],char critere[50],char cin[50]);
void recherche_ca(GtkWidget *liste,char id[50]);
void ajouter_capteur_temp(capteur c );
void ajouter_capteur_hum(capteur c );
