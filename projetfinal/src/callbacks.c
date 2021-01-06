#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Ouvrier.h"
#include "plante.h"
#include "troupeau.h"
#include "capteur.h"

char genre[15];
char Newgenre[15];
ouvrier a;
int v=0;
int nb=0;
int verif;
char choix[30];
int choix2;
char choix_t[30];
int choix2_t;
char choix_ca[30];
int choix2_ca;

void
on_button_proprio_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *propri__taire ;
  propri__taire = create_propri__taire ();
  gtk_widget_show (propri__taire);

}


void
on_button_employ___clicked             (GtkButton       *button,
                                        gpointer         user_data)
{ GtkWidget *employ__ ;
  employ__ = create_employ__ ();
  gtk_widget_show (employ__);

}


void
on_button_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin ;
  admin = create_admin ();
  gtk_widget_show (admin);

}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout,*login,*mdp;
char login1[20],mdp1[20];
login = lookup_widget (button,"entry1");
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
mdp = lookup_widget (button,"entry2");
strcpy(mdp1,gtk_entry_get_text(GTK_ENTRY(mdp)));
if ((strcmp(login1,"admin")==0)&&(strcmp(mdp1,"admin")==0))
{
  ajout = create_ajout ();
  gtk_widget_show (ajout);

}

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f =NULL;
GtkWidget *login , *pw,*windowAuth;
char login1[20];
char passw[20];
login = lookup_widget (button,"entry3");
pw=lookup_widget(button,"entry4");
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
f=fopen("employé.txt","a+");
if (f!=NULL){

fprintf(f,"%s %s \n",login1,passw);

fclose(f);
}
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Achraf_1 ;
  Achraf_1 = create_Gestion_des_plantes_p ();
  gtk_widget_show (Achraf_1);
}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Moetez_1 ;
  Moetez_1 = create_Moetez_1 ();
  gtk_widget_show (Moetez_1);
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Hedi_1 ;
  Hedi_1 = create_Interface_o ();
  gtk_widget_show (Hedi_1);

}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Souhir_1 ;
  Souhir_1 = create_Gestion_des_capteurs_ca ();
  gtk_widget_show (Souhir_1);
}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Rania_1 ;
  Rania_1 = create_Gestion_des_troupeaux_t ();
  gtk_widget_show (Rania_1);
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion,*login,*password ;
char log[30],Pw[30];
int trouve =-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
login = lookup_widget (button,"entry5");
password=lookup_widget(button,"entry6");
strcpy(log,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(Pw,gtk_entry_get_text(GTK_ENTRY(password)));
f=fopen("employé.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;
}
fclose(f);
}
if (trouve==1){
  gestion = create_Gestion ();
  gtk_widget_show (gestion);
}
}


void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *partie2,*login,*mdp;
char login1[20],mdp1[20];
login = lookup_widget (button,"entry7");
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
mdp = lookup_widget (button,"entry8");
strcpy(mdp1,gtk_entry_get_text(GTK_ENTRY(mdp)));
if ((strcmp(login1,"proprio")==0)&&(strcmp(mdp1,"proprio")==0))
{
  partie2 = create_partie2 ();
  gtk_widget_show (partie2);}
}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Achraf_2 ;
  Achraf_2 = create_Achraf_2 ();
  gtk_widget_show (Achraf_2);

}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Moetez_2 ;
  Moetez_2 = create_Moetez_2 ();
  gtk_widget_show (Moetez_2);
}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Hedi_2 ;
  Hedi_2 = create_Hedi_2 ();
  gtk_widget_show (Hedi_2);
}


void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Souhir_2 ;
  Souhir_2 = create_Souhir_2 ();
  gtk_widget_show (Souhir_2);

}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Rania_2 ;
  Rania_2 = create_Rania_2 ();
  gtk_widget_show (Rania_2);

}


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
on_buttonAfficher_o_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *treeview1;
window1=lookup_widget(objet,"Affichage_o");
window1=create_Affichage_o();
gtk_widget_show(window1);
treeview1=lookup_widget(window1,"treeview3_o");
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
on_buttonModifier_o_clicked              (GtkWidget       *objet,
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
on_buttonRecherche_o_clicked             (GtkWidget       *objet,
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

treeview=lookup_widget(window1,"treeview5_o");

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
on_buttonFull_Modif_o_clicked            (GtkWidget       *objet,
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
on_buttonFinalDelete_o_clicked           (GtkWidget       *objet,
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
on_buttonGestion_o_clicked               (GtkWidget       *objet,
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
on_buttonGestion1_o_clicked            (GtkWidget       *objet,
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
on_afficher_p_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_afficher=lookup_widget(objet,"fenetre_afficher_p");
fenetre_afficher=create_fenetre_afficher_p();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1_p");

afficher_plante(treeview1);
}


void
on_ajouteer_p_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_fenetre_ajout_p ();
  gtk_widget_show (window1);
}


void
on_button4_modification_p_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Modification_p ();
  gtk_widget_show (window1);
}


void
on_button5_recherche_p_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_recherche,*input1;
fenetre_recherche=create_Rechercher_p();
gtk_widget_show(fenetre_recherche);
}


void
on_radiobutton1_p_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2=1;
}


void
on_radiobutton2_p_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2=2;
}


void
on_checkbutton1_p_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(choix,"simple");
}


void
on_vente_p_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(choix,"composee");
}


void
on_ajouter_p_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
plante p;

GtkWidget *input1, *input2, *input3, *input5,*input6,*input7,*input8;
GtkWidget *fenetre_ajout;
int jour,mois,annee;
char sjour[10],smois[10],sannee[10],retour[50];;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout_p");

input1=lookup_widget(objet,"entry4_p");
input2=lookup_widget(objet,"entry2_p");
input3=lookup_widget(objet,"entry3_p");
input5=lookup_widget(objet,"entry5_p");
input6=lookup_widget(objet,"spinbutton1_p");
input7=lookup_widget(objet,"spinbutton2_p");
input8=lookup_widget(objet,"spinbutton3_p");
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
on_button3_recherche_p_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *input1;
char ref[50];
input1=lookup_widget(objet,"entry7_p");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input1)));

fenetre_afficher=lookup_widget(objet,"fenetre_afficher_p");
fenetre_afficher=create_fenetre_afficher_p();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1_p");

recherche(treeview1,ref);
}


void
on_button4_p_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
char cin[50],amodifier[50],critere[50];
GtkWidget *input1,*input2,*combo;
GtkWidget *sortie;
input1=lookup_widget(objet,"entry8_p");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry10_p");
strcpy(amodifier,gtk_entry_get_text(GTK_ENTRY(input2)));
combo=lookup_widget(objet,"comboboxentry5_p");
strcpy(critere,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
changer (amodifier,critere,cin);
sortie=lookup_widget(objet,"label18_p");
gtk_label_set_text(GTK_LABEL(sortie),amodifier);
}


void
on_treeview1_p_row_activated           (GtkTreeView     *treeview,
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
on_afficher_t_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_afficher=lookup_widget(objet,"fenetre_afficher_t");
fenetre_afficher=create_fenetre_afficher_t();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1_t");

afficher_troupeau(treeview1);
}


void
on_ajouteer_t_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_fenetre_ajout_t ();
  gtk_widget_show (window1);
}


void
on_button4_modification_t_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Modification_t ();
  gtk_widget_show (window1);
}


void
on_button5_recherche_t_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_recherche,*input1;
fenetre_recherche=create_Rechercher_t();
gtk_widget_show(fenetre_recherche);
}


void
on_radiobutton1_t_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2_t=1;
}


void
on_radiobutton2_t_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2_t=2;
}


void
on_checkbutton1_t_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(choix_t,"bon");
}


void
on_vente_t_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(choix_t,"mauvais");
}


void
on_ajouter_t_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2, *input3, *input5,*input6,*input7,*input8;
GtkWidget *fenetre_ajout;
int jour,mois,annee;
char sjour[10],smois[10],sannee[10],retour[50];
troupeau t;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout_t");

input1=lookup_widget(objet,"entry4_t");
input2=lookup_widget(objet,"entry2_t");
input3=lookup_widget(objet,"entry3_t");
input5=lookup_widget(objet,"entry5_t");
input6=lookup_widget(objet,"spinbutton1_t");
input7=lookup_widget(objet,"spinbutton2_t");
input8=lookup_widget(objet,"spinbutton3_t");
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
strcpy(retour,"");
if (choix2_t==1) strcpy(retour,"male");
if (choix2_t==2) strcpy(retour,"femelle");

sprintf(sjour,"%d",jour);
sprintf(smois,"%d",mois);
sprintf(sannee,"%d",annee);

strcat(sjour,"/");
strcat(sjour,smois);
strcat(sjour,"/");
strcat(sjour,sannee);


strcpy(t.matricule,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(t.genre,retour);
strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(t.race,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(t.date_naissance,sjour);
strcpy(t.etat,choix_t);
strcpy(t.poids,gtk_entry_get_text(GTK_ENTRY(input5)));
ajouter_troupeau(t);
}


void
on_button3_recherche_t_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *input1;
char mat[50];
input1=lookup_widget(objet,"entry7_t");
strcpy(mat,gtk_entry_get_text(GTK_ENTRY(input1)));

fenetre_afficher=lookup_widget(objet,"fenetre_afficher_t");
fenetre_afficher=create_fenetre_afficher_t();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1_t");

recherche_t(treeview1,mat);
}


void
on_button4_t_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
char mat[50],amodifier[50],critere[50];
GtkWidget *input1,*input2,*combo;
GtkWidget *sortie;
input1=lookup_widget(objet,"entry8_t");
strcpy(mat,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry10_t");
strcpy(amodifier,gtk_entry_get_text(GTK_ENTRY(input2)));
combo=lookup_widget(objet,"comboboxentry5_t");
strcpy(critere,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
changer_t (amodifier,critere,mat);
sortie=lookup_widget(objet,"label18_t");
gtk_label_set_text(GTK_LABEL(sortie),amodifier);
}


void
on_treeview1_t_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
        gchar* type;
        gchar* race;
        gchar* date;
        gchar* poids;
        gchar* etat;
 gchar* matricule;
gchar* genre;
        troupeau t;

        GtkTreeModel *model = gtk_tree_view_get_model(treeview);
        if (gtk_tree_model_get_iter(model, &iter ,path))
        {

                gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &type, 1,  &race, 2, &date ,3, &poids,4,&etat,5,&matricule,6,&genre,-1);

                strcpy(t.type,type);
                strcpy(t.race,race);
                strcpy(t.poids,poids);
          strcpy(t.date_naissance,date);
                strcpy(t.matricule,matricule);
                strcpy(t.etat,etat);
                strcpy(t.genre,genre);
                supprimer_troupeau(t);
                afficher_troupeau(treeview);
        }
}


void
on_afficher_ca_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_afficher=lookup_widget(objet,"fenetre_afficher_ca");
fenetre_afficher=create_fenetre_afficher_ca();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1_ca");

afficher_capteur(treeview1);
}


void
on_ajouteer_ca_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_fenetre_ajout_ca ();
  gtk_widget_show (window1);
}


void
on_button4_modification_ca_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Modification_ca ();
  gtk_widget_show (window1);
}


void
on_button5_recherche_ca_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_recherche,*input1;
fenetre_recherche=create_Rechercher_ca();
gtk_widget_show(fenetre_recherche);
}


void
on_radiobutton1_ca_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2_ca=1;
}


void
on_radiobutton2_ca_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2_ca=2;
}


void
on_checkbutton1_ca_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
strcpy(choix_ca,"actif");
}


void
on_vente_ca_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(choix_ca,"passif");
}


void
on_ajouter_ca_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur c;

GtkWidget *input1, *input2, *input3, *input5,*input6,*input7,*input8;
GtkWidget *fenetre_ajout;
int jour,mois,annee;
char sjour[10],smois[10],sannee[10],retour[50];;
fenetre_ajout=lookup_widget(objet,"fenetre_ajout_ca");

input1=lookup_widget(objet,"entry2_ca");
input2=lookup_widget(objet,"entry3_ca");
input3=lookup_widget(objet,"entry4_ca");
input5=lookup_widget(objet,"entry5_ca");
input6=lookup_widget(objet,"spinbutton1_ca");
input7=lookup_widget(objet,"spinbutton2_ca");

input8=lookup_widget(objet,"spinbutton3_ca");
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
strcpy(retour,"");
if (choix2_ca==1) strcpy(retour,"temperature");
if (choix2_ca==2) strcpy(retour,"humidite");

sprintf(sjour,"%d",jour);
sprintf(smois,"%d",mois);
sprintf(sannee,"%d",annee);


strcat(sjour,"/");
strcat(sjour,smois);
strcat(sjour,"/");
strcat(sjour,sannee);

strcat(sjour,"/");
strcat(sjour,smois);
strcat(sjour,"/");
strcat(sjour,sannee);


strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.type,retour);
strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.date,sjour);
strcpy(c.mode,choix_ca);
strcpy(c.sensibilite,gtk_entry_get_text(GTK_ENTRY(input5)));
ajouter_capteur(c);
if (choix2_ca==1) ajouter_capteur_temp(c);
if (choix2_ca==2) ajouter_capteur_hum(c);
}


void
on_button3_recherche_ca_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *input1;
char identifiant[50];
input1=lookup_widget(objet,"entry7_ca");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));

fenetre_afficher=lookup_widget(objet,"fenetre_afficher_ca");
fenetre_afficher=create_fenetre_afficher_ca();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1_ca");

recherche_ca(treeview1,identifiant);
}


void
on_button4_ca_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
char identifiant[50],amodifier[50],critere[50];
GtkWidget *input1,*input2,*combo;
GtkWidget *sortie;
input1=lookup_widget(objet,"entry8_ca");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"entry10_ca");
strcpy(amodifier,gtk_entry_get_text(GTK_ENTRY(input2)));
combo=lookup_widget(objet,"comboboxentry5_ca");
strcpy(critere,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
changer_ca (amodifier,critere,identifiant);
sortie=lookup_widget(objet,"label18_ca");
gtk_label_set_text(GTK_LABEL(sortie),amodifier);

}


void
on_treeview1_ca_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
        gchar* identifiant;
        gchar* marque;
        gchar* date;
        gchar* type;
        gchar* valeur;
        gchar* mode;
        gchar* sensibilite;
        capteur c;

        GtkTreeModel *model = gtk_tree_view_get_model(treeview);
        if (gtk_tree_model_get_iter(model, &iter ,path))
        {

                gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiant, 1,  &marque, 2, &date ,3, &type,4,&valeur,5,&mode,6,&sensibilite,-1);

                strcpy(c.identifiant,identifiant);
                strcpy(c.marque,marque);
                strcpy(c.date,date);
           strcpy(c.type,type);
                strcpy(c.valeur,valeur);
                strcpy(c.mode,mode);
                strcpy(c.sensibilite,sensibilite);
                supprimer_capteur(c);
                afficher_capteur(treeview);
        }
}

