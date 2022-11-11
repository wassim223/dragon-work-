#include <stdio.h>
#include <string.h>
#include"electorale.h"

int main()
{
vote v1={10,1} ;
liste_electorale l1= {10,11,12,1,22,12,2022},l2= {00,11,22,2,23,12,2022},l3;
int x,y,z,k ,nb;
x =ajouterlist("liste.txt", l1);

if(x==1)
printf("\najout de liste avec succés");
else printf("\nechec ajout");
k =ajoutervote("vote.txt", v1);

if(k==1)
printf("\najout de vote avec succés");
else printf("\nechec ajout");

y=modifierlist("liste.txt",10, l2);
if(y==1)
printf("\nModification de liste avec succés");
else printf("\nechec Modification");
/*z=supprimerlist("liste.txt",1 );
if(z==1)
printf("\nSuppression de liste avec succés");
else printf("\nechec Suppression");
l3=chercherlist("liste.txt",00 );
if(l3.id_election==-1)
printf("introuvable");*/
return 0;
}
