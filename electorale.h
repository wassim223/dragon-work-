#ifndef ELECTORALE_H_INCLUDED
#define ELECTORALE_H_I
#include<stdio.h>
typedef struct {
int j ;
int m ;
int a ;
}Date;

typedef struct {
int id_liste;
int id_electeur1 ;
int id_electeur2 ;
int orientation ;
Date d;
}liste_electorale;
typedef struct {
int id_liste;
int choix;
}vote;
int ajouterlist(char *, liste_electorale );
int ajoutervote(char *,vote);
int modifierlist( char *, int, liste_electorale );
int supprimerlist(char *, int );
liste_electorale chercherlist(char *, int);


#endif // ELECTORALE_H_INCLUDED
