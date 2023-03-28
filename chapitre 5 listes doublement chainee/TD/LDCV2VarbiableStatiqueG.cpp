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
//////Definir une varaible globale statique
Dliste L;
///////////
void InitialierListe()
{ L.debut=NULL;
L.fin=NULL;
}
//////////
int EstVide()
{
if(L.debut==NULL)
  return 1;
else
  return 0;
}
///////
void InsertDebut(int x)
{
liste *c;
c=(liste*)malloc(sizeof(liste));
if(c!=NULL)
{
  c->info=x;
  c->precedent=NULL;
  c->suivant=NULL;
//branchement
 if (EstVide()==1)
  {
    L.debut=c;
    L.fin=c;
  }
else
 {
  c->suivant=L.debut;
  L.debut->precedent=c;
  L.debut=c;
 }
}
}
////////
void InsertFin(int x)
{
liste *c;
c=(liste*)malloc(sizeof(liste));
if(c!=NULL)
{
  c->info=x;
  c->precedent=NULL;
  c->suivant=NULL;
//branchement
 if (EstVide()==1)
  {
    L.debut=c;
    L.fin=c;
  }
else
 {
  c->precedent=L.fin;
  L.fin->suivant=c;
  L.fin=c;
 }
}
}
/////////
void Afficher()
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
void SupprimerDebut()
{
liste *c;
if (EstVide()==0)
  {
    c=L.debut;
    L.debut=L.debut->suivant;
    if (L.debut==NULL)//L contient une seule cellule
       L.fin=NULL;
    else
        L.debut->precedent=NULL;
    free(c);
}
}
////////Supprimer Fin
void SupprimerFin()
{
liste *c;
if (EstVide()==0)
  {
    c=L.fin;
    L.fin=L.fin->precedent;
    if (L.fin==NULL)//L contient une seule cellule
       L.debut=NULL;
    else
        L.fin->suivant=NULL;
    free(c);
}
}
//////////
void SupprimerElement(int x)
{
liste *p;
 if (EstVide()==0)
 {
   if (L.debut->info==x) 
     SupprimerDebut();
   else
     {
     p=L.debut;
     while(p!=NULL && p->info!=x)
      {
           p=p->suivant;
      }
      if(p!=NULL) //x existe dans L
        if(p==L.fin) //x dans la dernier cellule
          SupprimerFin();
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
InitialierListe();
InsertFin(1);  
InsertFin(2);  
InsertFin(10);   
Afficher();
printf("\n");
  getch();  
}


