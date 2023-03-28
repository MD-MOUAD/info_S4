/*******la structure File version dynamique********/
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
/////////////Creer une file vide
File * FileVide()
{
     File *F;
     F=(File*)malloc(sizeof(File));
     F->t=NULL;
     F->q=NULL;
     return F;
     
}
//////// Tester si F est vide
int EstVide(File *F)
{
    if (F->t==NULL)
      return 1;
    else
      return 0;
  
}
////////Enfiler(F,x):ajouter un element à la fin
File *Enfiler(File *F,int x)
{
     liste *c;
     c=(liste *)malloc(sizeof(liste));
     if(c!=NULL)
      {
      c->info=x;
      c->suiv=NULL;
       if  (EstVide(F)==0)
         {
          F->q->suiv=c;
          F->q=c;
         }
       else
        {
         F->t=c;
         F->q=c;
        }
    }
    return F;
}
////////Defiler(F):Supprimer le premier element 
File* Defiler(File *F)
{
liste *c;
if  (EstVide(F)==0) //F n'est pas vide
 {
   c=F->t;
   F->t=F->t->suiv;
   free(c);
 }
return F;
}
//////////SommetPile(P):retourne le premier element
int PremierElement(File *F)
{
if (EstVide(F)==0) 
      return F->t->info;
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
File *F;
F=FileVide();
F=Enfiler(F,1);
F=Enfiler(F,2);
F=Enfiler(F,3);
printf("Le premier element est %d\n",PremierElement(F));
F=Defiler(F);
printf("Le premier element est %d\n",PremierElement(F));
F=Defiler(F);
printf("Le premier element est %d\n",PremierElement(F));
F=Defiler(F);
printf("Le premier element est %d\n",PremierElement(F));
getch();
}
