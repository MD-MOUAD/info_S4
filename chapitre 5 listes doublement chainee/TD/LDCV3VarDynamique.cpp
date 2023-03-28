/*******Liste doublement chainee********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/// Définir le type liste
typedef struct cellule{
        int info;
        cellule * precedent;
        cellule * suivant;
        }liste;
/// Q1 Définir le type Dliste
typedef struct {
        liste *debut;
        liste * fin;
        }Dliste;
///////////
Dliste  *InitialierListe()
{ Dliste *L;
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
Dliste *InsertDebut(Dliste *L,int x)
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
return L;
}
////////
Dliste *InsertFin(Dliste *L,int x)
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
return L;
}
/////////
void Afficher(Dliste *L)
{
 liste *p;
 p=L->debut;
 while(p!=NULL)
  {
   printf("%d-->",p->info);
   p=p->suivant;
  }
  printf("NULL");
}
//////////SupprimerDebut
Dliste * SupprimerDebut(Dliste *L)
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
return L;
}
////////Supprimer Fin
Dliste *SupprimerFin(Dliste *L)
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
return L;
}
//////////
Dliste * SupprimerElement(Dliste *L,int x)
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
return L;
}
/////////main()
main()
{ 
Dliste *L;
L=InitialierListe();
//L=InsertDebut(L,4);  
//L=InsertDebut(L,2);
//L=InsertDebut(L,1);
L=InsertFin(L,1);  
L=InsertFin(L,2);  
L=InsertFin(L,10);  
L=InsertFin(L,100); 
L=InsertFin(L,200);   
Afficher(L);
printf("\n");
L=SupprimerElement(L,200);
Afficher(L);
  getch();  
}


