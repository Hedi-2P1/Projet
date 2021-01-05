#include<gtk/gtk.h>


typedef struct 
{
char nom[30];
char cin[30];
char date_naissance[30];
char username[30];
char spec[50];
char nbre[2];
char date_recru[30];
char genre [30];
}ouvrier;

typedef struct 
{
char username[30];
int JC;
int MC;
int AC;
int verif;
}controle;

typedef struct 
{
int Jours;
int Mois;
int Annee;
}Date;

void ajouter_ouvrier(ouvrier o);
void afficher_ouvrier(GtkWidget *liste);
void supprimer_ouvrier(ouvrier o);
void create_date(Date D,char date[15]);
void JoursdeTravail(char journee[15]);
void recherche_id(GtkWidget *liste,char info[50]);
void recherche_nom(GtkWidget *liste,char info[50]);
void recherche_cin(GtkWidget *liste,char info[50]);
void recherche_spec(GtkWidget *liste,char info[50]);
void recherche_jt(GtkWidget *liste,char info[50]);
void remplace(ouvrier o, ouvrier o1);
void ajouter_controle(controle c);
int verifier_controle(char user[30]);

