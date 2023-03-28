//Application 2 d'une pile Problème 1:evaluation d'une expression arithmétique
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Définir la strcure liste
typedef struct cellule{
	char *info;
	struct cellule *suiv;
}liste;
//Définir la strcuture Pile
typedef liste * Pile;
///Les primitives
Pile PileVide()
{
	Pile P;
	P=NULL;
	return P;
}
///////
int EstPileVide(Pile P)
{if (P==NULL)
  return 1;
else
  return 0;
}
/////
Pile Empiler(Pile P,char *x)
{
	Pile c;
	c=(Pile)malloc(sizeof(liste));
	if(c!=NULL)
	{
		strcpy(c->info,x);
		c->suiv=P;
		P=c;
	}
	return P;
}
////
Pile Depiler(Pile P)
{
	Pile c;
	if(EstPileVide(P)==0)
	 {
	 	c=P;
	 	P=P->suiv;
	 	free(c);
	 }
	 return P;
}
////
char * SommetPile(Pile P)
{
	if(EstPileVide(P)==0)
		return P->info;
	else
	{
		printf("la pile est vide");
		exit(-1);
	}
}
//
int convertir(char c)
{
	return c-'0';
}
///
int chaineVersEntier(char *s)
{
	int d=0,i,L,n;
	L=strlen(s);
	for(i=0;i<L;i++)
		{
		n=s[i]-'0';
		d=d*10+n;
		}
	return d;

}
int nbrchiffres(int n)
{	int cpt=0;
	while (n!=0)
		{
		cpt=cpt+1;
		n=n/10;
		}
	return cpt;
}
void EntierVersChaine(int n,char *s)
{
	int r,i,nb;
	i=0;
	nb=nbrchiffres(n);
	while (n!=0)
		{
		r=n%10;
		s[nb-i-1]=r+'0';
		i=i+1;
		n=n/10;
		}
	s[i]='\0';
}
int EstOperateur(char *op)
{
	if(strcmp(op,"+")==0)
		return 1;
	if(strcmp(op,"-")==0)
		return 1;
	if(strcmp(op,"*")==0)
		return 1;
	if(strcmp(op,"/")==0)
		return 1;
	else
		return 0;
}
int evalop(int v1,int v2, char *op)
{
	if(strcmp(op,"+")==0)
		return v1+ v2;
	if(strcmp(op,"-")==0)
		return v1- v2;
	if(strcmp(op,"*")==0)
		return v1* v2;
	if(strcmp(op,"/")==0)
		return v1/ v2;
}
////
float Eval(char *T[], int N)
{
Pile P;
P=PileVide();
int i,v1,v2,res;
char sres[20];
for(i=N-1;i>=0;i--)
{
	if (EstOperateur(T[i])==0)
	{
		P=Empiler(P,T[i]);
	}
	else
	{
		v1=chaineVersEntier(SommetPile(P));
		P=Depiler(P);
		v2=chaineVersEntier(SommetPile(P));
		P=Depiler(P);
		res=evalop(v1,v2, T[i]);
		EntierVersChaine(res,sres);
		P=Empiler(P,sres);
	}
}
res=chaineVersEntier(SommetPile(P));
return res;
}
//PP
main()
{
	char *T[]={"+","4","2"};
	printf("%d",Eval(T,3));
}
