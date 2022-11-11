#include "utilisateur.h"
#include<stdio.h>

int ajouter(char  filename[], utilisateur u)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %s %d %s %s %d %s %s %d %d\n",u.nom,u.prenom,u.jour,u.mois,u.annee,u.CIN,u.num_tel,u.id,u.mdp,u.genre,u.role,u.num_bv);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, utilisateur nouv )
{
   
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f==NULL || f2==NULL)
	return 0 ;
    {
        while(fscanf(f,"%s %s %d %s %d %s %s %d %s %s %d %d\n",nouv.nom,nouv.prenom,&nouv.jour,nouv.mois,&nouv.annee,nouv.CIN,nouv.num_tel,&nouv.id,nouv.mdp,nouv.genre,&nouv.role,&nouv.num_bv) !=EOF)
        {
            if(u.id== id)
            {
                 fprintf(f2,"%s %s %d %s %d %s %s %d %s %s %d %d\n",nouv.nom,nouv.prenom,nouv.jour,nouv.mois,nouv.annee,nouv.CIN,nouv.num_tel,nouv.id,nouv.mdp,nouv.genre,nouv.role,nouv.num_bv);
                
            }
            else
                fprintf(f2,"%s %s %d %s %d %s %s %d %s %s %d %d\n",u.nom,u.prenom,u.jour,u.mois,u.annee,u.CIN,u.num_tel,u.id,u.mdp,u.genre,u.role,u.num_bv);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return 1;

}
int supprimer(char * filename, int id)
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d %s %s %d %s %s %d %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv) !=EOF)
        {
            if(u.id==id)
                tr=1;
            else
               fprintf(f2,"%s %s %d %s %d  %s %s %d %s %s %d %d\n",u.nom,u.prenom,u.jour,u.mois,u.annee,u.CIN,u.num_tel,u.id,u.mdp,u.genre,u.role,u.num_bv);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
utilisateur chercher(char * filename, int id)
{
    utilisateur u ;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %d %s %d  %s %s %d %s %s %d %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv) !=EOF)
        {
            if(id=u.id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.id=-1;
    return u;

}

