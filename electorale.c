#include<stdio.h>
#include"electorale.h"
#include<string.h>


int ajouterlist(char * filename,liste_electorale l ){
FILE * f=fopen(filename,"a");
if(f!=NULL)
{
fprintf(f,"%d %d %d,%d %d %d  %d\n",l.id_liste,l.id_electeur1,l.id_electeur2,l.orientation,l.d.j,l.d.m,l.d.a);
fclose(f);
return 1;
}
else return 0;

}
int ajoutervote(char * filename2,vote v){
FILE * f=fopen(filename2,"a");
if(f!=NULL)
{
fprintf(f,"%d %d\n",v.id_liste,v.choix);
fclose(f);
return 1;
}
else return 0;
}

int modifierlist( char * filename, int id_e_m, liste_electorale lnv )
{
int tr=0;
liste_electorale l;
FILE * f=fopen(filename, "r");
FILE * f2=fopen("nouv.txt", "w");
if(f!=NULL && f2!=NULL)
{
while(fscanf(f,"%d %d %d,%d %d %d %d\n",&l.id_liste,&l.id_electeur1,&l.id_electeur2,&l.orientation,&l.d.j,&l.d.m,&l.d.a)!=EOF)
{
if(l.id_liste== id_e_m)
{
fprintf(f2,"%d %d %d,%d %d %d %d\n",lnv.id_liste,lnv.id_electeur1,lnv.id_electeur2,lnv.orientation,l.d.j,lnv.d.m,lnv.d.a);
tr=1;
}
else
fprintf(f2,"%d %d %d,%d %d %d %d\n",l.id_liste,l.id_electeur1,l.id_electeur2,l.orientation,l.d.j,l.d.m,l.d.a);

}
}
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt", filename);
return tr;

}
int supprimerlist(char * filename, int id_e_s)
{
int tr=0;
liste_electorale l;
FILE * f=fopen(filename, "r");
FILE * f2=fopen("nouv.txt", "w");
if(f!=NULL && f2!=NULL)
{
while(fscanf(f,"%d %d %d,%d %d %d %d\n",&l.id_liste,&l.id_electeur1,&l.id_electeur2,&l.orientation,&l.d.j,&l.d.m,&l.d.a)!=EOF)
{
if(l.id_liste== id_e_s)
tr=1;
else
fprintf(f2,"%d %d %d,%d %d %d %d\n",l.id_liste,l.id_electeur1,l.id_electeur2,l.orientation,l.d.j,l.d.m,l.d.a);
}
}
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt", filename);
return tr;
}
liste_electorale chercherlist(char * filename, int id_rch)
{
liste_electorale l;
int tr;
FILE * f=fopen(filename, "r");
if(f!=NULL)
{
while(tr==0&& fscanf(f,"%d %d %d,%d %d %d %d\n",&l.id_liste,&l.id_electeur1,&l.id_electeur2,&l.orientation,&l.d.j,&l.d.m,&l.d.a)!=EOF)
{
if(l.id_liste== id_rch)
tr=1;
}
}
fclose(f);
if(tr==0)
l.id_liste=-1;
return l;

}


