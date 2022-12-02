#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>


typedef struct
{
	char nom[200];
	char prenom[200];
	int jour;
	char mois[500];
	int annee;
	char CIN[1000];
	char num_tel[100];
	int id;
	char mdp[2000];
	char genre[100];
	int role;
	int num_bv;
	int vote;
	int nationalite_observateur;
} utilisateur;

typedef struct
{
    int id_election;
    char municipalite[100];
    int nb_conseiller;
    int population;
    int jour;
    char mois[50];
    int annee;
} election;


int ajouter(char filename[], election );
int modifier( char *, int, election );
int supprimer(char *, int );
election chercher(char *, int );
float agemoyen(char * utilisateur);
int nbe(char * utilisateur, int  id_bv);

#endif // ELECTION_H_INCLUDED
