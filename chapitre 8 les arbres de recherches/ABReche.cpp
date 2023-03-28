#include<stdio.h>
#include<stdlib.h>
/* Définition du type noeud d’un arbre binaire de recherche */
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
Btree *InsertFeuille(Btree *A, int e)
{
 if(EstVide(A)==1)
    A=CreerFeuille(e);
 else
    if( e<=ValRacine(A))
       A->fg=InsertFeuille(A->fg, e);
    else
        A->fd=InsertFeuille(A->fd, e);
return A;
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
///
Btree * Tab2Abr(int T[],int N)
{
	Btree *A=NULL;
	int i;
	for(i=0;i<N;i++)
	  A=InsertFeuille(A, T[i]);
	return A;
}
///////////////
int Recherche(Btree *A,int x)
{
	if(A==NULL)
		return 0;
	if(A->info==x)
		return 1;
	if(x<=A->info)
	  	return Recherche(A->fg,x);
	else
	   	return Recherche(A->fd,x);
}
/////////////////GRD
void ParcoursInfixe(Btree *A)
{
	if (A!=NULL)
	{
		ParcoursInfixe(A->fg);
		printf("%d\n",A->info);
		ParcoursInfixe(A->fd);
	}
}
///PP
main()
{
	Btree *A;
	int T[]={5,2,3,9,10,7,6,8};
	A=Tab2Abr(T,8);
	ParcoursInfixe(A);
}
