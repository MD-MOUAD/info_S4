/*******la structure Pile version 1********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/// Q1 D�finir le type liste
typedef struct cellule{
        int info;
        cellule * suiv;
        }liste;
//D�finir le type Pile
typedef liste *Pile;
/////////////Creer une pile vide
Pile PileVide()
{
 return NULL;
}
//////// Tester si P est vide
int EstVide(Pile P)
{
  if (P==NULL)
    return 1;
  else
   return 0;
}
////////Empiler(P,x):ajouter un element au debut
Pile Empiler(Pile P,int x)
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
Pile Depiler(Pile P)
{
     Pile c;
     if (EstVide(P)==0) 
     {
      c=P;
      P=P->suiv;
      free(c);
     }
 return P;
}
//////////SommetPile(P):retourne le premier element
int SommetPile(Pile P)
{
    if (EstVide(P)==0) 
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
Pile P;
P=PileVide();
P=Empiler(P,3);
P=Empiler(P,2);
P=Empiler(P,10);
P=Empiler(P,20);
printf("Le sommet est %d\n",SommetPile(P));
P=Depiler(P);
printf("Le sommet est %d\n",SommetPile(P));
P=Depiler(P);
printf("Le sommet est %d\n",SommetPile(P));
P=Depiler(P);
printf("Le sommet est %d\n",SommetPile(P));
P=Depiler(P);
printf("Le sommet est %d\n",SommetPile(P));
getch();
}
