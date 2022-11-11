#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
typedef struct
{
    char texte [100];
    char type [100];
    int id,nbv,numl ;
} reclamation;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec su$
int ajouter(char *, reclamation );
int modifier( char *, int, reclamation );
int supprimer(char *, int );
reclamation  chercher(char *, int);

#endif // POINT_H_INCLUDED
