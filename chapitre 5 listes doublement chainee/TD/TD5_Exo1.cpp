#include<stdio.h>
#include<stdlib.h>
//Définir le type Dliste
//Q1
typedef struct cellule{
int info;
struct cellule * prec;
struct cellule *suiv;
}Dliste ;

//Q2
Dliste* initListe(Dliste *L)
{
	L=NULL;
	return L;
}
//Q3
Dliste* InsertDebut(Dliste *L, int x)
{
    Dliste *c;
    //Réservation
    c=(Dliste*)malloc(sizeof(Dliste));
    if(c!=NULL)
    {
        c->info=x;
        c->prec=NULL;
        c->suiv=NULL;
    //Branchement

     //si L est vide
     if(L==NULL)
     {
         L=c;
     }
     else
     {
         c->suiv=L;
         L->prec=c;
         L=c;
     }
    }
    return L;
}
///Q4
///////Adresse de la dernière cellule
Dliste *AddrDernCelluleS1(Dliste *L)
{
    Dliste *p=NULL;
    while (L!=NULL)
    {
        p=L;
        L=L->suiv;
    }
    return p;
}
//
Dliste* InsertFin(Dliste *L, int x)
{
    Dliste *c,*p;
    //Chercher l'adresse de la dernière cellule
    p=AddrDernCelluleS1(L);
    //Réservation
    c=(Dliste*)malloc(sizeof(Dliste));
    if(c!=NULL)
    {
        c->info=x;
        c->prec=NULL;
        c->suiv=NULL;
        //branchement
        if(p!=NULL) //L n'est pas vide
        {
            p->suiv=c;
            c->prec=p;
        }
        else
        {
            L=c;
        }
    }
    return L;
}
// Q5
Dliste* SupprimDebut(Dliste*L)
{
	Dliste *c;
	//Si L est vide
	if(L==NULL)
		return L;
	//Si L contient une seule cellule
	c=L;
	if(L->suiv==NULL)
		{L=NULL;}
	else //L contient plusieurs cellulles
	{
		L=L->suiv;
		L->prec=NULL;//L->suiv->prec=NULL et L=L->suiv;
	}
	free(c);
	return L;
}
////Q6
Dliste* SupprimFin(Dliste*L)
{
    Dliste *c;
    c=AddrDernCelluleS1(L);
    //Le cas ou L est NULL
    if(c==NULL)
        return L;
    //Le cas ou L contient une seule cellule
    if( c->prec==NULL)
    {
        L=NULL;
        free(c);
    }
    else
    {
        c->prec->suiv=NULL;
        free(c);
    }
    return L;
}
///Q7
//Chercher l'adress d'un element x
Dliste *ChercherAdresseEle(Dliste *L,int x)
{
Dliste *p;
p=L;
while(p!=NULL)
{
    if (p->info==x)
        return p;
    p=p->suiv;
}
///
Dliste* SupprimElement(Dliste*L, int x)
{
Dliste *p,*c;
p=ChercherAdresseEle(L,x);
if(p==NULL)
  {

    printf("%d n'existe pas dans L",x);
    return L;
  }
else
{
    if(p->prec==NULL) // x se trouve dans la 1ere cellule
        L=SupprimerDebutS1(L);
    else
        if(p->suiv==NULL)//x se trouve dans la derniere cellule
           L=SupprimerFin(L);
        else
        {
            c=p;
            p->prec->suiv=p->suiv;
            p->suiv->prec=p->prec;
            free(c);
        }
}
        return L;

}
//Q8
Dliste* SupprimerTout(Dliste*L)
{

 while (L!=NULL)
   L=SupprimDebut(L)
 return L;
}
//Solution 2
Dliste* Vider(Dliste *L) 
{ 
  Dliste *c;
while (L!=NULL)
 {
 //Si L contient une seule cellule
    c=L; 
  if(L->suiv==NULL)
      L=NULL;
 else //L contient plusieurs cellulles 
{ 
  L=L->suiv; 
  L->prec=NULL; 
}
free(c); 
}
return L;
 }
 ///Q9
 void AListe(Dliste * L)
 {
 	Dliste *p;
 	p=L;
 	while(p!=NULL)
 	{
 		printf("%d--->",p->info);
 		p=p->suiv;
 	}
 	printf("NULL")

 }
 /////Q10
int Existe(Dliste * L,int x)
{
	Dliste *p;
	p=L;
	while(p!=NULL && p->info!=x)
		p=p->suiv;
	if(p!=NULL)
		return 1;
	else
		return 0;
}