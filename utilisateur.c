#include "utilisateur.h"
#include<stdio.h>
#include<string.h>

int ajouter(char  filename[], utilisateur u)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %s %d %s %s %d %s %s %d %d %d \n",u.nom,u.prenom,u.jour,u.mois,u.annee,u.CIN,u.num_tel,u.id,u.mdp,u.genre,u.role,u.num_bv,u.vote);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, utilisateur nouv )
{
   int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
	
    {
        while(fscanf(f,"%s %s %d %s %d  %s %s %d %s %s %d %d %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv,&u.vote) !=EOF)
        {
            if(u.id== id)
            {
                 fprintf(f2,"%s %s %d %s %d  %s %s %d %s %s %d %d %d\n",nouv.nom,nouv.prenom,nouv.jour,nouv.mois,nouv.annee,nouv.CIN,nouv.num_tel,nouv.id,nouv.mdp,nouv.genre,nouv.role,nouv.num_bv,nouv.vote);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %d %s %d  %s %s %d %s %s %d %d %d\n",u.nom,u.prenom,u.jour,u.mois,u.annee,u.CIN,u.num_tel,u.id,u.mdp,u.genre,u.role,u.num_bv,u.vote);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename , int id)
{
    int tr=0;
    utilisateur u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %s %d  %s %s %d %s %s %d %d %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv,&u.vote) !=EOF)
        {
            if(u.id==id)
                tr=1;
            else
               fprintf(f2,"%s %s %d %s %d  %s %s %d %s %s %d %d %d\n",u.nom,u.prenom,u.jour,u.mois,u.annee,u.CIN,u.num_tel,u.id,u.mdp,u.genre,u.role,u.num_bv,u.vote);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
utilisateur chercher(char * filename , int id)
{
    utilisateur u ;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %d %s %d  %s %s %d %s %s %d %d %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv,&u.vote) !=EOF)
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

float TPE (char *filename)
{	
	float tpe;
	int se=0;
	int vote=0;
	utilisateur u ;

	FILE *f=fopen(filename,"r");
	if (f!=NULL)
	{
		while (fscanf(f,"%s %s %d %s %d  %s %s %d %s %s %d %d %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv,&u.vote) !=EOF)
		{ 
			if(u.role!=0)
			{se++;}
			
			if (u.vote!=-1)
			{vote++;}
		}
			tpe=vote/se;
	}
	fclose(f);

	return tpe;
}

void TPHF( char * filename)
{
	float tphf;
	int fe=0;
	int ho=0;
	int vote=0;
	float hov;
	float fev;
	utilisateur u ;

	FILE *f=fopen(filename,"r");
	FILE *f2=fopen("stat.txt","a");
	if (f!=NULL)
	{
		while (fscanf(f,"%s %s %d %s %d  %s %s %d %s %s %d %d %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv,&u.vote) !=EOF)
		{ 
			if(strcmp(u.genre,"f")==0)
			{fe++;}
			if (strcmp(u.genre,"h")==0)
			{ho++;}
			if (u.vote!=-1)
			{vote++;}
		}
			
	
		hov=(float) ho/vote;
		fev=(float) fe/vote;

	printf(" nombre des femmes est : %d  nombre hommes est : %d \n nombre de vote est : %d  \n nb hommes/ nbvotes est : %f \n nb femmes/nb votes est : %f \n ",fe,ho,vote,hov,fev);
	
	fprintf(f2," nombre des femmes est : %d  nombre hommes est : %d \n nombre de vote est : %d  \n nb hommes/ nbvotes est : %f \n nb femmes/nb votes est : %f \n ",fe,ho,vote,hov,fev);
			
	}
	fclose(f);
	fclose(f2);


}




















