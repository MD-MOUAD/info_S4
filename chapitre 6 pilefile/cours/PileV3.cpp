/*******la structure Pile version 3 variable globale********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/// Q1 Définir le type liste
typedef struct cellule{
        int info;
        cellule * suiv;
        }liste;
//Définir le type Pile
typedef liste *Pile;
/////////Définir une variable globale
Pile P;
/////////////Creer une pile vide
Pile PileVide()
{
 return NULL;
}
//////// Tester si P est vide
int EstVide()
{
  if (P==NULL)
    return 1;
  else
   return 0;
}
////////Empiler(P,x):ajouter un element au debut
Pile Empiler(int x)
{
Pile c;
c=(Pile)malloc(sizeof(liste));
if(c!=NULL)
 {
  c->info=x;
  c->suiv=P;
  P=c;  
 }
 return P;
}
////////Depiler(P):Supprimer le premier element 
Pile Depiler()
{
     Pile c;
     if (EstVide()==0) 
     {
      c=P;
      P=P->suiv;
      free(c);
     }
 return P;
}
//////////SommetPile(P):retourne le premier element
int SommetPile()
{
    if (EstVide()==0) 
      return P->info;
    else
     {
      printf("La pile est vide");
      getchar();
      exit(-1);
     }
}
/////////main()
main()
{
P=PileVide();
P=Empiler(3);
P=Empiler(2);
P=Empiler(10);
P=Empiler(20);
printf("Le sommet est %d\n",SommetPile());
P=Depiler();
printf("Le sommet est %d\n",SommetPile());
P=Depiler();
printf("Le sommet est %d\n",SommetPile());
P=Depiler();
printf("Le sommet est %d\n",SommetPile());
P=Depiler();
printf("Le sommet est %d\n",SommetPile());
getch();
}
