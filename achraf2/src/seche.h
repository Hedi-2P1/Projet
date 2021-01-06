#include<gtk/gtk.h>

typedef struct 
{
char id;
char jour[30];
char mois[30];
char annee[30];
char value[30];
char max[30];
}seche;

void afficher(GtkWidget *liste);
