#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "plante.h"
char choix[30];
int choix2;
void
on_button2_Ajout_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_fenetre_ajout ();
  gtk_widget_show (window1);
}


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

plante p;

GtkWidget *input1, *input2, *input3, *input5,*input6,*input7,*input8;
GtkWidget *fenetre_ajout;
int jour,mois,annee;
char sjour[10],smois[10],sannee[10],retour[50];;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

input1=lookup_widget(objet,"entry4");
input2=lookup_widget(objet,"entry2");
input3=lookup_widget(objet,"entry3");
input5=lookup_widget(objet,"entry5");
input6=lookup_widget(objet,"spinbutton1");
input7=lookup_widget(objet,"spinbutton2");
input8=lookup_widget(objet,"spinbutton3");
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
strcpy(retour,"");
if (choix2==1) strcpy(retour,"fertile");
if (choix2==2) strcpy(retour,"infertile");

sprintf(sjour,"%d",jour);
sprintf(smois,"%d",mois);
sprintf(sannee,"%d",annee);


strcat(sjour,"/");
strcat(sjour,smois);
strcat(sjour,"/");
strcat(sjour,sannee);


strcpy(p.ref,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.sol,retour);
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.famille,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.date_naissance,sjour);
strcpy(p.adresse,choix);
strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(input5)));
ajouter_plante(p);

}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_plante(treeview1);
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkTreeIter iter;
        gchar* nom;
        gchar* famille;
        gchar* date;
        gchar* adresse;
        gchar* ref;
	gchar* quantite;
	gchar* sol;
        plante p;

        GtkTreeModel *model = gtk_tree_view_get_model(treeview);
        if (gtk_tree_model_get_iter(model, &iter ,path))
        {

                gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &ref, 1,  &nom, 2, &famille ,3, &date,4,&adresse,5,&quantite,6,&sol,-1);

                strcpy(p.ref,ref);
                strcpy(p.nom,nom);
                strcpy(p.famille,famille);
                strcpy(p.date_naissance,date);
                strcpy(p.adresse,adresse);
                strcpy(p.quantite,quantite);
		strcpy(p.sol,sol);
                supprimer_plante(p);
                afficher_plante(treeview);
        }

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(choix,"simple");
}


void
on_vente_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(choix,"composee");

}


void
on_button4_modification_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Modification ();
  gtk_widget_show (window1);

}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
char cin[50],amodifier[50],critere[50];
GtkWidget *input1,*input2,*combo;
GtkWidget *sortie;
input1=lookup_widget(objet,"entry8");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry10");
strcpy(amodifier,gtk_entry_get_text(GTK_ENTRY(input2)));
combo=lookup_widget(objet,"comboboxentry5");
strcpy(critere,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
changer (amodifier,critere,cin);
sortie=lookup_widget(objet,"label18");
gtk_label_set_text(GTK_LABEL(sortie),amodifier);




}


void
on_button3_recherche_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
{
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *input1;
char ref[50];
input1=lookup_widget(objet,"entry7");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input1)));

fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");

recherche(treeview1,ref);
}

}


void
on_button5_recherche_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_recherche,*input1;
fenetre_recherche=create_Rechercher();
gtk_widget_show(fenetre_recherche);




}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2=1;

}



void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2=2;

}

