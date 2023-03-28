/*******la structure Pile Version 2:Passage par adresse ********/
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
void Empiler(Pile *P,int x)
{
Pile c;
c=(Pile)malloc(sizeof(liste));
if(c!=NULL)
 {
  c->info=x;
  c->suiv=*P;
  *P=c;  
 }
}
////////Depiler(P):Supprimer le premier element 
void Depiler(Pile *P)
{
     Pile c;
     if (EstVide(*P)==0) 
     {
      c=*P;
      *P=(*P)->suiv;
      free(c);
     }
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
Empiler(&P,3);
Empiler(&P,2);
Empiler(&P,10);
Empiler(&P,20);
printf("Le sommet est %d\n",SommetPile(P));
Depiler(&P);
printf("Le sommet est %d\n",SommetPile(P));
Depiler(&P);
printf("Le sommet est %d\n",SommetPile(P));
Depiler(&P);
printf("Le sommet est %d\n",SommetPile(P));
Depiler(&P);
printf("Le sommet est %d\n",SommetPile(P));
getch();
}
