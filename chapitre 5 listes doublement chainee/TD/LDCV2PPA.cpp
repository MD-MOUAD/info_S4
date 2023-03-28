/*******Liste doublement chainee********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/// D�finir le type liste
typedef struct cellule{
        int info;
        cellule * precedent;
        cellule * suivant;
        }liste;
/// Q1 D�finir le type Dliste
typedef struct {
        liste *debut;
        liste * fin;
        }Dliste;
///////////
Dliste * InitialierListe()
{ Dliste * L;
L=(Dliste*)malloc(sizeof(Dliste));
L->debut=NULL;
L->fin=NULL;
return L;
}
//////////
int EstVide(Dliste *L)
{
if(L->debut==NULL)
  return 1;
else
  return 0;
}
///////
void InsertDebut(Dliste *L,int x)
{
liste *c;
c=(liste*)malloc(sizeof(liste));
if(c!=NULL)
{
  c->info=x;
  c->precedent=NULL;
  c->suivant=NULL;
//branchement
 if (EstVide(L)==1)
  {
    L->debut=c;
    L->fin=c;
  }
else
 {
  c->suivant=L->debut;
  L->debut->precedent=c;
  L->debut=c;
 }
}
}
////////
void InsertFin(Dliste *L,int x)
{
liste *c;
c=(liste*)malloc(sizeof(liste));
if(c!=NULL)
{
  c->info=x;
  c->precedent=NULL;
  c->suivant=NULL;
//branchement
 if (EstVide(L)==1)
  {
    L->debut=c;
    L->fin=c;
  }
else
 {
  c->precedent=L->fin;
  L->fin->suivant=c;
  L->fin=c;
 }
}
}
/////////
void Afficher(Dliste L)
{
 liste *p;
 p=L.debut;
 while(p!=NULL)
  {
   printf("%d-->",p->info);
   p=p->suivant;
  }
  printf("NULL");
}
//////////SupprimerDebut
void SupprimerDebut(Dliste *L)
{
liste *c;
if (EstVide(L)==0)
  {
    c=L->debut;
    L->debut=L->debut->suivant;
    if (L->debut==NULL)//L contient une seule cellule
       L->fin=NULL;
    else
        L->debut->precedent=NULL;
    free(c);
}

}
////////Supprimer Fin
void SupprimerFin(Dliste *L)
{
liste *c;
if (EstVide(L)==0)
  {
    c=L->fin;
    L->fin=L->fin->precedent;
    if (L->fin==NULL)//L contient une seule cellule
       L->debut=NULL;
    else
        L->fin->suivant=NULL;
    free(c);
}

}
//////////
void SupprimerElement(Dliste *L,int x)
{
liste *p;
 if (EstVide(L)==0)
 {
   if (L->debut->info==x) 
     SupprimerDebut(L);
   else
     {
     p=L->debut;
     while(p!=NULL && p->info!=x)
      {
           p=p->suivant;
      }
      if(p!=NULL) //x existe dans L
        if(p==L->fin) //x dans la dernier cellule
         SupprimerFin(L);
        else
         {
          p->suivant->precedent=p->precedent;
          p->precedent->suivant=p->suivant;
          free(p);
         }
 }
}

}
/////////main()
main()
{ 
Dliste *L;
L=InitialierListe();
InsertDebut(L,4);  
InsertDebut(L,2);
InsertDebut(L,1);
Afficher(*L);
  getch();  
}


