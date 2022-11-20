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
int role; // 1 electeur 2 candidat 3 observateur //
int num_bv;
int vote;
int nationalite_observateur; //1=tunisien 2= etrangée //
} utilisateur ;

int ajouter (char filename[], utilisateur );
int modifier ( char * filename, int id , utilisateur );
int supprimer (char * filename, int id );
utilisateur chercher (char * filename , int id);
float TPE (char *filename);
void TPHF( char * filename);


#endif // UTILISATEUR_H_INCLUDED
