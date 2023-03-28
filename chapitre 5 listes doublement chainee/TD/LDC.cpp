/*******Liste doublement chainee********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/// Q1 Définir le type Dliste
typedef struct cellule{
        int info;
        cellule * precedent;
        cellule * suivant;
        }Dliste;
//Protoype
//////O0 :chercher l'adresse de la derniere cellule
Dliste *adresseDernier(Dliste *L)
{Dliste * p,*t;
 p=NULL;
 t=L;
 while(t!=NULL)
  {
   p=t;
   t=t->suivant;
 }
return p;
}
////////////Q2
Dliste * iniListe()
{
Dliste *L;
L=NULL;
return L;
}
///////Q3
Dliste *InsertDebut(Dliste *L,int x)
{
Dliste *c;
//Réservation
c=(Dliste *) malloc(sizeof(Dliste));
if(c!=NULL)
 {
   c->info=x;
   c->precedent=NULL;
   c->suivant=NULL;
//Branchement
 if(L!=NULL)
  {
   c->suivant=L;
   L->precedent=c;
  }
 
 L=c;
}
return L;
}
///////Q4
Dliste *InsertFin(Dliste *L,int x)
{
Dliste *c,*p,*t;
//Réservation
c=(Dliste *) malloc(sizeof(Dliste));
if(c!=NULL)
 {
   c->info=x;
   c->precedent=NULL;
   c->suivant=NULL;
//chercher l'adresse de la derniere cellule
 p=NULL;
 t=L;
 while(t!=NULL)
  {
   p=t;
   t=t->suivant;
 }
 if(p==NULL) //liste vide
   L=c;
 else
   {
    p->suivant=c;
    c->precedent=p;
  }
}
return L;
}
///////////Q5
Dliste *SupprimDebut(Dliste *L)
{
 Dliste *c;
 if(L!=NULL)
  {
   c=L;
   L->precedent=NULL;
   L=L->suivant;
   free(c);
  }
 return L;
}
//////////Q6
Dliste *SupprimFin(Dliste *L)
{
 Dliste *c;
 c=adresseDernier(L);
 if(c==NULL)
   return L;
   
 else
   if (c->precedent==NULL) //liste contient 1 cellule
       {
         L=NULL;
        free(c);
        }
   else
    {
     c->precedent->suivant=NULL;
     free(c);
     }
 return L;
}
/////////Chercher adresse d'un element x
Dliste * chercherAdresseEl(Dliste *L,int x)
{
Dliste *p;
p=L;
while(p!=NULL)
 {
  if(p->info==x)
    return p;
  p=p->suivant;
 }
return NULL;
}
////////////Q7
Dliste *SupprimerELement(Dliste *L,int x)
{
Dliste *p,*c;
p=chercherAdresseEl(L,x);
if (p==NULL)
 {
  printf("%d n'existe pas");
  return L;
 }
else
  if(p->precedent==NULL) //x se trouve dans 1 cellule
    L=SupprimDebut(L);
  else
    if (p->suivant==NULL) //x se trouve dans last cel
      L=SupprimFin(L);
    else
  {
  c=p;
  p->precedent->suivant=p->suivant;
  p->suivant->precedent=p->precedent;
  free(c);
}
return L;

}
/////////Q9
void AffListe(Dliste *L)
{
 Dliste *p;
 p=L;
 while(p!=NULL)
  {
   printf("%d->",p->info);
   p=p->suivant;
  }
  printf("NULL");
}
///////
void AffListeCHAR(Dliste *L)
{
 Dliste *p;
 p=adresseDernier(L);
 while(p!=NULL)
  {
   printf("%d->",p->info);
   p=p->precedent;
  }
  printf("NULL");
}

/////////main()
main()
{ 
Dliste *L;
L=iniListe();
//L=InsertDebut(L,4);  
//L=InsertDebut(L,2);
//L=InsertDebut(L,1);
L=InsertFin(L,1);
L=InsertFin(L,2);
L=InsertFin(L,3);
AffListe(L);
printf("\n");
L=SupprimerELement(L,3);
//L=SupprimFin(L);
AffListe(L);
/*printf("\n");
L=SupprimDebut(L);
AffListe(L);
printf("\n");
L=SupprimDebut(L);
AffListe(L);*/
//AffListeCHAR(L);
  getch();  
}
///////


