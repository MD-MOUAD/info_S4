//Application 1 d'une pile Exercice 2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Définir la strcure liste
typedef struct cellule{
	char info;
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
Pile Empiler(Pile P,char x)
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
int SommetPile(Pile P)
{
	if(EstPileVide(P)==0)
		return P->info;
	else
	{
		printf("la pile est vide");
		exit(-1);
	}
}
///la fonction parenthesage
int parenthesage(char *s)
{
	int L,i;
	Pile P;
	P=PileVide();
	L=strlen(s);
	for(i=0;i<L;i++)
	{
	
		if(s[i]=='(')
			P=Empiler(P,s[i]);
		if(s[i]==')')
			if (EstPileVide(P)==1)
				return 0;
			else
				P=Depiler(P);
	}
	if (EstPileVide(P)==1)
		return 1;
	else
		return 0;
}
//PP
main()
{
	char s[20];
	while(1)
	{
		printf("Donnez une chaîne:");
		scanf("%s",s);
		if(parenthesage(s)==1)
			printf("la chaine est valide\n");
		else
			printf("la chaine n'est pas valide\n");
	}
}
