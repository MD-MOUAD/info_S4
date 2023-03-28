/*******la structure File version Variable globale********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/// Q1 Définir le type liste
typedef struct cellule{
        int info;
        cellule * suiv;
        }liste;
//Définir le type File
typedef struct t_File{
        liste *t;
        liste *q;
        }File;
/////Declarer une variable golable statique
File F;
/////////////Creer une file vide
File FileVide()
{
     F.t=NULL;
     F.q=NULL;
     return F;
     
}
//////// Tester si F est vide
int EstVide()
{
    if (F.t==NULL)
      return 1;
    else
      return 0;
  
}
////////Enfiler(F,x):ajouter un element à la fin
void Enfiler(int x)
{
     liste *c;
     c=(liste *)malloc(sizeof(liste));
     if(c!=NULL)
      {
      c->info=x;
      c->suiv=NULL;
       if  (EstVide()==0)
         {
          F.q->suiv=c;
          F.q=c;
         }
       else
        {
         F.t=c;
         F.q=c;
        }
    }

}
////////Defiler(F):Supprimer le premier element 
void Defiler()
{
liste *c;
if  (EstVide()==0) //F n'est pas vide
 {
   c=F.t;
   F.t=F.t->suiv;
   free(c);
 }

}
//////////SommetPile(P):retourne le premier element
int PremierElement()
{
if (EstVide()==0) 
      return F.t->info;
    else
     {
      printf("La File est vide");
      getchar();
      exit(-1);
     }
    }
/////////main()
main()
{
F=FileVide();
Enfiler(1);
Enfiler(2);
Enfiler(3);
printf("Le premier element est %d\n",PremierElement());
Defiler();
printf("Le premier element est %d\n",PremierElement());
Defiler();
printf("Le premier element est %d\n",PremierElement());
Defiler();
printf("Le premier element est %d\n",PremierElement());
getch();
}
