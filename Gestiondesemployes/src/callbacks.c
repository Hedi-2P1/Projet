#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Ouvrier.h"


char genre[15];
char Newgenre[15];
ouvrier a;
int v=0;
int nb=0;
int verif;


void
on_buttonModif_o_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Modification_o ();
  gtk_widget_show (window1);
}


void
on_buttonSupp_o_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Suppression_o ();
  gtk_widget_show (window1);
}


void
on_buttonRec_o_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Recherche_o ();
  gtk_widget_show (window1);
}


void
on_buttonAjout_o_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Ajout_o ();
  gtk_widget_show (window1);
}


void
on_buttonControler_o_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Controle_o ();
  gtk_widget_show (window1);
}


void
on_buttonInscri_o_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
ouvrier o;
Date DN;
Date DR;
int T;
char specialite[50];
GtkWidget *inputNom, *inputCIN, *inputDNJ, *inputDNM, *inputDNA, *inputUser, *inputSpecial, *inputJT, *inputDRJ, *inputDRM, *inputDRA, *inputgenre;
GtkWidget *Window_Ajout_o;
Window_Ajout_o=lookup_widget(objet,"Ajout_o");
inputNom=lookup_widget(objet,"entryNom");
inputCIN=lookup_widget(objet,"entryCIN");
inputUser=lookup_widget(objet,"entryUser");

inputDNJ=lookup_widget(objet,"spinbuttonJJDN");
inputDNM=lookup_widget(objet,"spinbuttonMDN");
inputDNA=lookup_widget(objet,"spinbuttonADN");
DN.Jours=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(inputDNJ));
DN.Mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(inputDNM));
DN.Annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(inputDNA));
create_date(DN,o.date_naissance);

inputDRJ=lookup_widget(objet,"spinbuttonJRec");
inputDRM=lookup_widget(objet,"spinbuttonMRec");
inputDRA=lookup_widget(objet,"spinbuttonARec");
DR.Jours=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(inputDRJ));
DR.Mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(inputDRM));
DR.Annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(inputDRA));
create_date(DR,o.date_recru);

inputJT=lookup_widget(objet,"spinbuttonJT");
T=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(inputJT));
sprintf(o.nbre,"%d",T);

inputSpecial=lookup_widget(objet,"comboboxSpec");
strcpy(o.spec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(inputSpecial)));


strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(inputNom)));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(inputCIN)));
strcpy(o.username,gtk_entry_get_text(GTK_ENTRY(inputUser)));

strcpy(o.genre,genre);

ajouter_ouvrier(o);
}

void
on_radiobuttonH_o_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(genre,"Homme");
}


void
on_radiobuttonF_o_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(genre,"Femme");
}


void
on_buttonAfficher_o_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *treeview1;
window1=lookup_widget(objet,"Affichage_o");
window1=create_Affichage_o();
gtk_widget_show(window1);
treeview1=lookup_widget(window1,"treeview3");
afficher_ouvrier(treeview1);
}


void
on_checkbuttonLundi_o_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char jour[15];
strcpy (jour,"Lundi");
nb++;
JoursdeTravail(jour);
}


void
on_checkbuttonMardi_o_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char jour[15];
strcpy (jour,"Mardi");
nb++;
JoursdeTravail(jour);
}


void
on_checkbuttonMercredi_o_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char jour[15];
strcpy (jour,"Mercredi");
nb++;
JoursdeTravail(jour);
}


void
on_checkbuttonJeudi_o_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char jour[15];
strcpy (jour,"Jeudi");
nb++;
JoursdeTravail(jour);
}


void
on_checkbuttonVendredi_o_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char jour[15];
strcpy (jour,"Vendredi");
nb++;
JoursdeTravail(jour);
}


void
on_checkbuttonSamedi_o_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char jour[15];
strcpy (jour,"Samedi");
nb++;
JoursdeTravail(jour);
}


void
on_checkbuttonDimanche_o_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
char jour[15];
strcpy (jour,"Dimanche");
nb++;
JoursdeTravail(jour);
}


void
on_buttonModifier_o_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
ouvrier o2;
FILE *f,*g;
int a=0;
char id[15], Modif[100], champ[50], Msg[100];
GtkWidget *inputId, *inputModif, *inputChamp;
GtkWidget *OutputMsg;
inputId=lookup_widget(objet,"entryid");
inputModif=lookup_widget(objet,"entryModif");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(inputId)));
strcpy(Modif,gtk_entry_get_text(GTK_ENTRY(inputModif)));
inputChamp=lookup_widget(objet,"comboboxChampModif");
strcpy(champ,gtk_combo_box_get_active_text(GTK_COMBO_BOX(inputChamp)));
	f=fopen("ouvrier.txt","r");
	g=fopen("users2.txt","w");
	if( f==NULL  || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",o2.nom,o2.cin,o2.date_naissance,o2.username,o2.spec,o2.nbre,o2.date_recru,o2.genre)!=EOF)
		{
			if (strcmp(id,o2.username)==0) 
			{
			a=1;			
			if (strcmp(champ,"Nom")==0) strcpy(o2.nom,Modif);
				else if (strcmp(champ,"Identifiant")==0) strcpy(o2.username,Modif);
					else if (strcmp(champ,"Specialite")==0) strcpy(o2.spec,Modif);
						else if (strcmp(champ,"Nombre de jours")==0) strcpy(o2.nbre,Modif);
			}
fprintf(g,"%s %s %s %s %s %s %s %s \n",o2.nom,o2.cin,o2.date_naissance,o2.username,o2.spec,o2.nbre,o2.date_recru,o2.genre);
		}
		fclose(f);
		fclose(g);
remove("ouvrier.txt");
rename("users2.txt","ouvrier.txt");
	}
OutputMsg = lookup_widget(objet,"labelResultat");
strcpy(Msg,"Le ");
strcat(Msg,champ);
strcat(Msg," de l'utilisateur ");
strcat(Msg,id);
if  (a==1)
strcat(Msg," a éte modifié avec succés");
else strcat(Msg," n'a pas éte modifié");
gtk_label_set_text(GTK_LABEL(OutputMsg),Msg);
}





void
on_buttonRecherche_o_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *inputInfo, *inputChamp;
char info[50], Champ[50];
GtkWidget *window1;

window1 = create_Resultat_o ();
gtk_widget_show (window1);

inputChamp=lookup_widget(objet,"comboboxentryChamp");
strcpy(Champ,gtk_combo_box_get_active_text(GTK_COMBO_BOX(inputChamp)));

inputInfo=lookup_widget(objet,"entryInfo");
strcpy(info,gtk_entry_get_text(GTK_ENTRY(inputInfo)));

treeview=lookup_widget(window1,"treeview5");

if (strcmp(Champ,"Identifiant")==0)
recherche_id(treeview,info);
	else if (strcmp(Champ,"Nom")==0)
	recherche_nom(treeview,info);
		else if (strcmp(Champ,"CIN")==0)
		recherche_cin(treeview,info);
			else if (strcmp(Champ,"Spécialité")==0)
			recherche_spec(treeview,info);
				else recherche_jt(treeview,info);
}


void
on_treeview6_o_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkButton *button;
gchar *nom, *cin, *Date_naissance, *username, *spec, *nbre, *date_recru, *genre;
GtkTreeIter iter;
GtkTreeModel *Model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(Model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(Model), &iter, 0,&nom,1,&cin,2,&Date_naissance,3,&username,4,&spec,5,&nbre,6,&date_recru,7,&genre,-1);
}
strcpy(a.nom,nom);
strcpy(a.cin,cin);
strcpy(a.date_naissance,Date_naissance);
strcpy(a.username,username);
strcpy(a.spec,spec);
strcpy(a.nbre,nbre);
strcpy(a.date_recru,date_recru);
strcpy(a.genre,genre);
}


void
on_buttonFull_Modif_o_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
GtkTreeModel     *model;
GtkTreeIter iter;
gchar* cin;
GtkButton *button;
GtkWidget *treeview1;
GtkWidget *window1;
GtkWidget *entryNewNom1, *entryNewCIN1, *entryNewUser1, *entryNewJT1, *entryNewJJ1, *entryNewMM1, *entryNewAAAA1, *entryNewDRJJ1, *entryNewDRMM1, *entryNewDRAAAA1, *entryNewSpecial1, *entryH1, *entryF1;
ouvrier o1;
Date NewDN,NewDR;
int T;

entryNewNom1=lookup_widget(objet,"entryNewNom");
entryNewCIN1=lookup_widget(objet,"entryNewCIN");
entryNewUser1=lookup_widget(objet,"entryNewUser");
entryNewJT1=lookup_widget(objet,"spinbuttonNewJT");
entryNewJJ1=lookup_widget(objet,"spinbuttonNewJJ");
entryNewMM1=lookup_widget(objet,"spinbuttonNewMM");
entryNewAAAA1=lookup_widget(objet,"spinbuttonNewAAAA");
entryNewDRJJ1=lookup_widget(objet,"spinbuttonNewDRJJ");
entryNewDRMM1=lookup_widget(objet,"spinbuttonNewDRMM");
entryNewDRAAAA1=lookup_widget(objet,"spinbuttonNewDRAAAA");
entryNewSpecial1=lookup_widget(objet,"comboboxNewSpec");

NewDN.Jours=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryNewJJ1));
NewDN.Mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryNewMM1));
NewDN.Annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryNewAAAA1));
create_date(NewDN,o1.date_naissance);

NewDR.Jours=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryNewDRJJ1));
NewDR.Mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryNewDRMM1));
NewDR.Annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryNewDRAAAA1));
create_date(NewDR,o1.date_recru);

T=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryNewJT1));
sprintf(o1.nbre,"%d",T);

strcpy(o1.spec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryNewSpecial1)));

strcpy(o1.nom,gtk_entry_get_text(GTK_ENTRY(entryNewNom1)));
strcpy(o1.cin,gtk_entry_get_text(GTK_ENTRY(entryNewCIN1)));
strcpy(o1.username,gtk_entry_get_text(GTK_ENTRY(entryNewUser1)));
strcpy(o1.genre,Newgenre);

remplace(a,o1);

window1=lookup_widget(objet,"Gestion_des_ouvriers_o");
treeview1=lookup_widget(window1,"treeview6_o");
afficher_ouvrier(treeview1);

gtk_entry_set_text(GTK_ENTRY(entryNewNom1),"");
gtk_entry_set_text(GTK_ENTRY(entryNewCIN1),"");
gtk_entry_set_text(GTK_ENTRY(entryNewUser1),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewJT1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewJJ1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewMM1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewAAAA1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewDRJJ1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewDRMM1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewDRAAAA1),0);
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (entryH1), FALSE);
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (entryF1), FALSE);
gtk_combo_box_set_active (GTK_COMBO_BOX (entryNewSpecial1),-1);
}


void
on_buttonFinalDelete_o_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *window1;
if (v==1)
supprimer_ouvrier(a);
window1=lookup_widget(objet,"Gestion_des_ouvriers_o");
treeview1=lookup_widget(window1,"treeview6_o");
afficher_ouvrier(treeview1);
}


void
on_checkbuttonDelete_o_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
v=1;
}





void
on_buttonGestion_o_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *treeview1;
window3=lookup_widget(objet,"Gestion_des_ouvriers_o");
window3=create_Gestion_des_ouvriers_o();
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview6_o");
afficher_ouvrier(treeview1);
}


void
on_radiobuttonNewH_o_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(Newgenre,"Homme");
}


void
on_radiobuttonNewF_o_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
strcpy(Newgenre,"Femme");
}


void
on_button_Confirm_Modif_o_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryNewNom, *entryNewCIN, *entryNewUser, *entryNewJT, *entryNewJJ, *entryNewMM, *entryNewAAAA, *entryNewDRJJ, *entryNewDRMM, *entryNewDRAAAA, *entryH, *entryF, *entryNewSpec;
Date DN;
Date DR;
int nbre,j;

entryNewNom=lookup_widget(button,"entryNewNom");
entryNewCIN=lookup_widget(button,"entryNewCIN");
entryNewUser=lookup_widget(button,"entryNewUser");
entryNewJT=lookup_widget(button,"spinbuttonNewJT");
entryNewJJ=lookup_widget(button,"spinbuttonNewJJ");
entryNewMM=lookup_widget(button,"spinbuttonNewMM");
entryNewAAAA=lookup_widget(button,"spinbuttonNewAAAA");
entryNewDRJJ=lookup_widget(button,"spinbuttonNewDRJJ");
entryNewDRMM=lookup_widget(button,"spinbuttonNewDRMM");
entryNewDRAAAA=lookup_widget(button,"spinbuttonNewDRAAAA");
entryH=lookup_widget(button,"radiobuttonNewH");
entryF=lookup_widget(button,"radiobuttonNewF");
entryNewSpec=lookup_widget(button,"comboboxNewSpec");

gtk_entry_set_text(GTK_ENTRY(entryNewNom),a.nom);
gtk_entry_set_text(GTK_ENTRY(entryNewCIN),a.cin);
gtk_entry_set_text(GTK_ENTRY(entryNewUser),a.username);

if (strcmp(a.spec,"Agriculture")==0)
j=0;
	else if (strcmp(a.spec,"Troupeaux")==0)
	j=1;
		else if (strcmp(a.spec,"Equipements_agricoles")==0)
		j=2;
			else if (strcmp(a.spec,"Capteurs")==0)
			j=3;
				else if (strcmp(a.spec,"Ressources")==0)
				j=4;
					else j=5; 
gtk_combo_box_set_active (GTK_COMBO_BOX (entryNewSpec),j);

nbre=atoi(a.nbre);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewJT),nbre);

sscanf(a.date_naissance,"%d/%d/%d",&DN.Jours,&DN.Mois,&DN.Annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewJJ),DN.Jours);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewMM),DN.Mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewAAAA),DN.Annee);

sscanf(a.date_recru,"%d/%d/%d",&DR.Jours,&DR.Mois,&DR.Annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewDRJJ),DR.Jours);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewDRMM),DR.Mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryNewDRAAAA),DR.Annee);

if (strcmp(a.genre,"Homme")==0)
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (entryH), TRUE);
else   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (entryF), TRUE);
}


void
on_buttonSupprimmer_o_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryId;
ouvrier o;
entryId=lookup_widget(button,"entryId");
strcpy(o.username,gtk_entry_get_text(GTK_ENTRY(entryId)));
supprimer_ouvrier(o);
}


void
on_radiobuttonOui_o_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
verif=0;
}


void
on_radiobuttonNon_o_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
verif=1;
}


void
on_envoi_o_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryid, *entryJC, *entryMC, *entryAC;
controle c;
int i=0;


entryid=lookup_widget(button,"entryid");
entryJC=lookup_widget(button,"spinbuttonJC");
entryMC=lookup_widget(button,"spinbuttonMC");
entryAC=lookup_widget(button,"spinbuttonMA");

strcpy(c.username,gtk_entry_get_text(GTK_ENTRY(entryid)));
c.JC=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryJC));
c.MC=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryMC));
c.AC=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(entryAC));
c.verif=verif;

i=verifier_controle(c.username);
if (i==1)
ajouter_controle(c);

gtk_entry_set_text(GTK_ENTRY(entryid),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryJC),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryMC),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryAC),0);

}





void
on_buttonGestion1_o_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window3;
GtkWidget *treeview1;
window3=lookup_widget(objet,"Gestion_des_ouvriers_o");
window3=create_Gestion_des_ouvriers_o();
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview6_o");
afficher_ouvrier(treeview1);
}

