#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"utilisateur.h"


int main()
{
    utilisateur u1= {"wassim","ferchichi",3,"sep",19,"14320","22747",1,"wass","1",1,1}, u2= {"wassff","fereeechichi",3,"sep",19,"14320","22747",1,"wass","1",1,1},u3 ;

    /*int x=ajouter("utilisateur.txt",u1);
    if(x==1)
        printf(" ajout d utilisateur avec succés");
    else printf("echec ajout"); */

     int x=modifier("utilisateur.txt",1,u2 );
     if(x==1)
        printf("Modification d utilisateur avec succés");
    else printf("echec Modification"); 

   /*x=supprimer("utilisateur.txt",1);
    if(x==1)
        printf("Suppression d utilisateur avec succés");
    else printf("echec Suppression"); 

   u3=chercher("utilisateur.txt",3 );
   if(u3.id==-1)
        printf("introuvable"); 
	else printf ("exist");*/
    
return 0; 
}
