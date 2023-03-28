/******* TP5 Prob1:Liste doublement chainee********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
///////Definir le type monome
typedef struct momone_elem{
        float coef;
        int deg;
        }monome;
/// Q1 Définir le type polynome
typedef struct cellule{
        monome pval;
        cellule * precedent;
        cellule * suivant;
        }Polynome;
//Question 1 
int EstPolynomeNul(Polynome *P)
{
  if (P==NULL)
    return 1;
  else
    return 0;
}
//////////La fonction InsertDebut
Polynome *InsertDebut(Polynome  *L,monome x)
{
Polynome  *c;
//Rerservation
c=(Polynome  *)malloc(sizeof(Polynome));
if(c!=NULL)
 {
  c->pval=x;
  c->precedent=NULL;
  c->suivant=NULL;
  if(L!=NULL)
   {
     c->suivant=L;
     L->precedent=c;
     
   }
 L=c;
 }
return L;
}
//Question 2
Polynome * LitPolynome(Polynome *P)
{
int nb,i;
monome m;
printf("combien de monomes:");
scanf("%d",&nb);
for(i=1;i<=nb;i++)
 {
  printf("Donnez coeff:");
  scanf("%f",&m.coef);
  printf("Donnez le degre:");
  scanf("%d",&m.deg);
  P=InsertDebut(P,m);
 }
 return P;
}
//Question 3
void AffichePolynome(Polynome *P)
{
Polynome *c;
c=P;
printf("%.2fX^%d",c->pval.coef,c->pval.deg);
c=c->suivant;
while(c!=NULL)
{
  if (c->pval.coef<0)
   printf("%.2fX^%d",c->pval.coef,c->pval.deg);
  else
   printf("+%.2fX^%d",c->pval.coef,c->pval.deg);
  c=c->suivant;
}
}
//Question 4 
int DegrePoly(Polynome* P)
{
	Polynome* c;
	c=P;
	while (c->suiv!=NULL)
	 c=c->suiv;
	return c->pval.deg;
}
///Question 
float evalPoly(Polynome *P, float a)
{
	float s=0;
	while(P!=NULL)
	{
		s=s+P->pval.coef*pow(a,p->pval.deg);
		P=P->suiv;
	}
	return s;
}
///on retourne l'adresse de monome de degré d
Polynome*  existe(Polynome * P, int d)
{
	Polynome *c;
	c=P;
	while(c!=NULL)
		{
		 	if(c->pval.deg==d)
				return c;
			c=c->suiv;
	   }
	   return NULL;
}
////
Polynome * add_monome(Polynome * p, monome m)
////
Polynome * add(Polynome* P1,Polynome* P2)
{
	Polynome *P3,*c,*ad;
	P3=NULL;
	c=P1;
	//On copie P1 dans P3
	while (c!=NULL)
	{
		P3=AjoutFin(P3,c->pval);
		c=c->suiv;
	}
	//on ajoute P2 à P3
	c=P2;
	//On copie P1 dans P3
	while (c!=NULL)
	{
		ad= existe(P3, c->pval.deg);
		if(ad!=NULL)
			ad->pval.coeff=ad->pval.coeff+c->pval.coeff;*
		else
		P3=add_monome(P3, c->pval);
		c=c->suiv;
	}
	return P3;
	
}
////
////PP
main()
{
	 Polynome *P1;
      P1=NULL;
      P1=LitPolynome(P1);
      AffichePolynome(P1);
      printf("\n P1(2)=%f",EvalPolynome(P1,2));
}
