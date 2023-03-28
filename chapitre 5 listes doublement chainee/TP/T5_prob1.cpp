//Correction TP 5 Prob1
#include<stdio.h>
#include<stdlib.h>
//Définir le type polyome=liste doublement chaînée
typedef struct cellule{
float coeff;
struct cellule *preced;
struct cellule *suiv;
}Polynome;
////Q1
int EstPolynomeNull(Polynome *P) 
{
	if (P==NULL)
		return 1;
	else
		return 0;
	
}
////Q2
//On programme d'abord la fonction ajoutFin()
Polynome *AdressDernier(Polynome *L)
{
	Polynome *p;
	while(L!=NULL)
	{
		p=L;
		L=L->suiv;
	}
	return p;
}
///Ajout fin
Polynome *AjoutFin(Polynome *L,float x)
{
	Polynome *c,*p;
	//Reservation
	c=(Polynome *)malloc(sizeof(Polynome));
	if(c!=NULL)
	{
		c->coeff=x;
		c->preced=NULL;
		c->suiv=NULL;
	}
	//branchement;
	p=AdressDernier(L);
	if (p==NULL)
	 L=c;
	else
	{
		p->suiv=c;
		c->preced=p;
	}
	return L;
}
////
//////////La fonction InsertDebut
Polynome *InsertDebut(Polynome  *L,float x)
{
Polynome  *c;
//Rerservation
c=(Polynome  *)malloc(sizeof(Polynome));
if(c!=NULL)
 {
  c->coeff=x;
  c->preced=NULL;
  c->suiv=NULL;
  if(L!=NULL)
   {
     c->suiv=L;
     L->preced=c;
     
   }
 L=c;
 }
return L;
}
///////////
Polynome * LitPolynome(Polynome *P)
{
	int d,i;
	float a;
	printf("Donnez le degré du polynôme:");
	scanf("%d",&d);
	for(i=0;i<=d;i++)
	{
		printf("Donnez le coefficient n%d:",i);
		scanf("%f",&a);
		P=AjoutFin(P,a);
	}
	return P;
}
/////Q4
int DegrePolynome(Polynome* P)
{
	int d=-1;
	while(P!=NULL)
	{
		d=d+1;
		P=P->suiv;
	}
	return d;
}
//Question 3
void AffichePolynome(Polynome *P)
{
Polynome *c;
c=P;
int i;
i=0;
printf("%.2fX^%d",c->coeff,i);
c=c->suiv;
i++;
while(c!=NULL)
{
  if (c->coeff<0)
   printf("%.2fX^%d",c->coeff,i);
  else
   printf("+%.2fX^%d",c->coeff,i);
  c=c->suiv;
  i++;
}
}
///Q5
float puiss(float x,int n)
{
	float p;
	int i;
	p=1;
	for(i=1;i<=n;i++)
		p=p*x;
	return p;
}
float evalPoly(Polynome *P, float a)
{
	float s=0;
	int i=0;
	while(P!=NULL)
	{
		s=s+P->coeff*puiss(a,i);
		i=i+1;
		P=P->suiv;
	}
	return s;
}
//Question 6 
Polynome * SommePolynome(Polynome *P1, Polynome *P2)
{
Polynome *A;
Polynome *P3=NULL;
int d1,d2;
d1=DegrePolynome(P1);
d2=DegrePolynome(P2);
if (d1>d2)
  {
    A=P1;
    while(A!=NULL)
     {
      P3=AjoutFin(P3,A->coeff);
      A=A->suiv;
     } 
    A=P3;
    while(P2!=NULL)
     {
       A->coeff=A->coeff+P2->coeff;
       A=A->suiv;
       P2=P2->suiv;
     }
  }
else 
{
   A=P2;
    while(A!=NULL)
     {
      P3=AjoutFin(P3,A->coeff);
      A=A->suiv;
     } 
    A=P3;
    while(P1!=NULL)
     {
       A->coeff=A->coeff+P1->coeff;
       A=A->suiv;
       P1=P1->suiv;
     }
 }
 return P3;
}
///Q6
Polynome * SommePolySol2(Polynome* P1,Polynome* P2)
{
	Polynome* P3;
	P3=NULL;
	while(P1!=NULL && P2!=NULL)
	{
		P3=AjoutFin(P3,P1->coeff+P2->coeff);
		P1=P1->suiv;
		P2=P2->suiv;
	}
	//le polynome P1 devient NULL
	while(P2!=NULL)
		{
			P3=AjoutFin(P3,P2->coeff);
			P2=P2->suiv;	
		}
	//Le polynome P2 devient null
	while(P1!=NULL)
		{
			P3=AjoutFin(P3,P1->coeff);
			P1=P1->suiv;	
		}
	return P3;	
	
}
////PP
main()
{
	Polynome *P1,*P2,*P3;
	P1=NULL;
	P2=NULL;
	P3=NULL;
	P1=LitPolynome(P1);
	P2=LitPolynome(P2);
	P3=SommePolynome(P1,P2);
	AffichePolynome(P1);
	printf("\n");
	AffichePolynome(P2);
	printf("\n");
	AffichePolynome(P3);
	printf("\n");
}
