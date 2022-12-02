#include <stdio.h>
#include <string.h>
#include"election.h"


int main()
{
    float age;
    int nb1;
    int x;
    election E1={12,"ariena",12,1200,12,"november",2022} , E2={11,"ariena",12,1200,12,"november",2022};
     x=ajouter("election.txt", E1);
    
    if(x==1)
        printf("\najout d'election avec succés");
    else printf("\nechec ajout");
       
  /*  x=modifier("election.txt",12,E2 );

    if(x==1)
        printf("\nModification d'election avec succés");
    else printf("\nechec Modification");
        x=supprimer("election.txt",12 );
    if(x==1)
        printf("\nSuppression de point avec succés");
    else printf("\nechec Suppression");
    E1=chercher("election.txt",12 );
    if(E1.id_election==-1)
        printf("trouvable");
    else printf("introuver");*/

	int id_bv=1;
    age=agemoyen("utilisateur.txt");
    printf("l'age moyen des electeurs est %f",age);
    nb1=nbe("utilisateur.txt", id_bv);
    printf("le nombre des electeurs dans le b.v %d est %d",id_bv,nb1); 


    return 0;
}
