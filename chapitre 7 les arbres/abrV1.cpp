#include<stdio.h>
#include<stdlib.h>
/* Définition du type noeud d’un arbre binaire */
typedef struct noeud{
int  info; /*le champ etiq peut avoir n’importe quel type*/
struct noeud *fg ; /*pointeur contenant l’adresse du ABG*/
struct noeud *fd ; /*pointeur contenant l’adresse du ABD*/
}Btree ;
//// Primitives
Btree * ArbrVide()
{
	Btree *A;
	A=NULL;
	return A;
}
//////
int EstVide(Btree *A)
{
	if(A==NULL)
		return 1;
	else
		return 0;
}
Btree *FilsGauche(Btree *A)
{
	if (A==NULL)
		{
		printf("l'arbre est vide");
		exit(-1);
		}
	else
		return A->fg;
}
Btree*FilsDroit(Btree *A)
{
	if (A==NULL)
		{
		printf("l'arbre est vide");
		exit(-1);
		}
	else
		return A->fd;
}

int ValRacine(Btree *A)
{
		if (A==NULL)
		{
		printf("l'arbre est vide");
		exit(-1);
		}
	else
		return A->info;
}
////////////////////////
Btree *CreerNoeud(int e,Btree *g,Btree *d)
{
	Btree *c;
	c=(Btree*)malloc(sizeof(Btree));
	if(c!=NULL)
	{
		c->info=e;
		c->fg=g;
		c->fd=d;
	}
	return c;
}
////////////////////
Btree *CreerFeuille(int e)
{
	Btree *c;
	c=(Btree*)malloc(sizeof(Btree));
	if(c!=NULL)
	{
		c->info=e;
		c->fg=NULL;
		c->fd=NULL;
	}
	return c;
}
////
////////////////////
Btree *CreerFeuille_Sol2(int e)
{
	return CreerNoeud(e,NULL,NULL);
}
////
int EstFeuille(Btree *A)
{
	if(A==NULL)
		return 0;
	if(A->fg==NULL && A->fd==NULL)
		return 1;
	else
		return 0;
}
///////////////////////
void ParcoursPrefixe(Btree *A)
{
	if (A!=NULL)
	{
		printf("%d\n",A->info);
		ParcoursPrefixe(A->fg);
		ParcoursPrefixe(A->fd);
	}
}
///
void ParcoursInfixe(Btree *A)
{
	if (A!=NULL)
	{
		ParcoursInfixe(A->fg);
		printf("%d\n",A->info);
		ParcoursInfixe(A->fd);
	}
}
////
void ParcoursPostfixe(Btree *A)
{
	if (A!=NULL)
	{
		ParcoursPostfixe(A->fg);
		ParcoursPostfixe(A->fd);
		printf("%d\n",A->info);
	}
}
//////
int Recherche(Btree *A,int x)
{
	if(A==NULL)
		return 0;
	if(A->info==x)
		return 1;
	if(Recherche(A->fg,x)==1)
		return 1;
	else
		return Recherche(A->fd,x);
}
/////
int RechercheS2(Btree *A,int x)
{
	if(A==NULL)
		return 0;
	if(A->info==x)
		return 1;
	return Recherche(A->fg,x)or Recherche(A->fd,x);
}
///PP
main()
{
	Btree *A,*B,*C;
	A=ArbrVide();
	A=CreerFeuille(1);
	A->fg=CreerFeuille(2);
	A->fd=CreerFeuille(3);
	A->fg->fg=CreerFeuille(4);
	B=ArbrVide();
	B=CreerFeuille(5);
	B->fg=CreerFeuille(6);
	B->fd=CreerFeuille(7);
	//ParcoursPrefixe(A);
	//ParcoursInfixe(A);
	//ParcoursPostfixe(A);
	C=CreerNoeud(0,A,B);
	//ParcoursPrefixe(C);
	printf("%d",RechercheS2(C,5));
}
