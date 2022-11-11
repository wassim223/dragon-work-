#include <stdio.h>
#include <string.h>
#include"reclamation.h"

int main()
{
    reclamation r1= {"choix multiple de vote ", "faute",122,2,1},r2= {"influence d'agent bureau ", "grave",233,3,2},r3;
    int x=ajouter("reclamation.txt", r1);
    /*
    if(x==1)
        printf("\najout de reclamation avec succés");
    else printf("\nechec ajout");
        */
    x=modifier("reclamation.txt",1,r2 );

    if(x==1)
        printf("\nModification de reclamation avec succés");
    else printf("\nechec Modification");
    x=supprimer("reclamation.txt",1 );
    if(x==1)
        printf("\nSuppression de reclamation avec succés");
    else printf("\nechec Suppression");
    r3=chercher("reclamation.txt",3 );
    if(r3.id==-1)
        printf("introuvable");
    return 0;
}
