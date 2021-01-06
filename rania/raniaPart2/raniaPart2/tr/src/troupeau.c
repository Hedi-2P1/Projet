#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "troupeau.h"
#include "interface.h"
#include "support.h"




















int calcul(char type[]);
{int p;
p=0;
troupeau t;
FILE *f=NULL;
f=fopen("troupeaux.txt","r");
while(fscanf(f,"%s %s %s %s %s %s ",t.type,t.race,t.poids,t.genre,t.etat,t.matricule)!=EOF)
{
if(strcmp(t.type,mat)==0)
{p++;
}

}

fclose(f);
char str[100]="";
sprintf(str,"%d",p);

gtk_label_set_text(GTK_LABEL(output),str);


}

