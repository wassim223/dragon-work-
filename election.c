#include<stdio.h>
#include"election.h"

int ajouter(char filename[], election E)
{
  FILE * f=fopen(filename,"a");
  if(f!=NULL)
  {
    fprintf(f,"%d %s %d %d %d %s %d\n",E.id_election,E.municipalite,E.nb_conseiller,E.population,E.jour,E.mois,E.annee);
    fclose(f);
    return 1;
  }
  else return 0;
}


int modifier(char *filename, int id_election, election nouv)
{
  int tr=0;
  election E;
  FILE * f=fopen(filename,"r");
  FILE * f2=fopen("nouv.txt","w");
  if (f!=NULL && f2!=NULL)
  {
     while (fscanf(f,"%d %s %d %d %d %s %d\n",&E.id_election,E.municipalite,&E.nb_conseiller,&E.population,&E.jour,E.mois,&E.annee)!=EOF)
     {
        if(E.id_election==id_election)
        {
           fprintf(f2,"%d %s %d %d %d %s %d\n",nouv.id_election,nouv.municipalite,nouv.nb_conseiller,nouv.population,nouv.jour,nouv.mois,nouv.annee);
           tr=1;
        }
        else 
           fprintf(f2,"%d %s %d %d %d %s %d\n",E.id_election,E.municipalite,E.nb_conseiller,E.population,E.jour,E.mois,E.annee);
     }
   }
   fclose(f);
   fclose(f2);
   remove(filename);
   rename("nouv.txt", filename);
   return tr;
}


int supprimer(char * filename, int id_election)
{
   int tr=0;
   election E;
   FILE * f=fopen(filename, "r");
   FILE * f2=fopen("nouv.txt","w");
   if(f!=NULL && f2!=NULL)
   {
      while(fscanf(f,"%d %s %d %d %d %s %d\n",&E.id_election,E.municipalite,&E.nb_conseiller,&E.population,&E.jour,E.mois,&E.annee)!=EOF)
      {
         if(E.id_election==id_election)
             tr=1;
         else 
             fprintf(f2,"%d %s %d %d %d %s %d\n",E.id_election,E.municipalite,E.nb_conseiller,E.population,E.jour,E.mois,E.annee); 
      }
   }
   fclose(f);
   fclose(f2);
   remove(filename);
   rename("nouv.txt", filename);
   return tr;
}


election chercher(char * filename, int id_election)
{
   election E;
   int tr;
   FILE * f=fopen(filename,"a");
   if(f!=NULL)
   {
      while(tr==0 && fscanf(f,"%d %s %d %d %d %s %d\n",E.id_election,E.municipalite,E.nb_conseiller,E.population,E.jour,E.mois,E.annee)!=EOF)
      {
         if(E.id_election==id_election)
             tr=1;
      }
   }
   fclose(f);
   if(tr==0)
      E.id_election=-1;
   return E;
}

float agemoyen(char * filename )
{
	utilisateur u;
	int nb_electeur=0;
	int total;
	float agemoy;
	FILE * f=fopen(filename,"r");
	total=0;
	if (f!=NULL)
	{
		while (fscanf(f,"%s %s %d %s %d  %s %s %d %s %s %d %d 				    %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv,&u.vote) !=EOF)
		{
			while (u.role==1)
			{
				total=total+(2022-u.annee);
				nb_electeur=nb_electeur+1;
			}
		}
	}
	agemoy=total/nb_electeur;
	fclose(f);
	return agemoy;
}


int nbe(char * filename , int  id_bv )
{
	utilisateur u;
	int i=0,nb_elec=0,n=0;
	int t[100];
	FILE *f=fopen(filename , "r");

	if(f!=NULL)
	{
		while (fscanf(f,"%s %s %d %s %d  %s %s %d %s %s %d %d 				    %d\n",u.nom,u.prenom,&u.jour,u.mois,&u.annee,u.CIN,u.num_tel,&u.id,u.mdp,u.genre,&u.role,&u.num_bv,&u.vote) !=EOF)
		{
			while (u.role==1)
			{
				t[i]=u.num_bv;
				i++;
				n++;
			}
		}
		
		for(i=0;i<n;i++)
		{
			if(t[i]==id_bv)
				nb_elec=nb_elec+1;
		}
	}
	fclose(f);
	
return nb_elec;
}










