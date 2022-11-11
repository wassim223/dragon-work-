#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include<stdio.h>

typedef struct
{
char nom[200] ;
char prenom [200] ;
int jour ;
char mois[500] ;
int annee ;
char CIN [1000] ;
char num_tel[1000];

int id;
char mdp[2000];
char genre [100];
int role;
int num_bv;
} utilisateur ;

int ajouter(char filename[], utilisateur );
int modifier( char * filename, int id , utilisateur );
int supprimer(char * filename, int id );
utilisateur chercher(char * filename , int id);


#endif // UTILISATEUR_H_INCLUDED
