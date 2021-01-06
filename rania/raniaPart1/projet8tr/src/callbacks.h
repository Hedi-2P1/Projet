#include <gtk/gtk.h>


void
on_button2_Ajout_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_vente_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button4_modification_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button3_recherche_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_recherche_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
