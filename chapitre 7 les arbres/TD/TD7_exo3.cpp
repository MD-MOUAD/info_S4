///Correction Td7
////exercice 3
#include<stdio.h>
#include<stdlib.h>
/* Définition du type noeud d’un arbre binaire */
typedef struct noeud{
char  info; /*le champ etiq peut avoir n’importe quel type*/
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

char ValRacine(Btree *A)
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
////
int char2int(char c)
{
	return c-'0';
}
////
int EstValide(Btree *A)
{
	if(A==NULL)
		return 1;
	if(A->info=='+'||A->info=='-'||A->info=='*'||A->info=='/')
	    if(A->fg==NULL ||A->fd ==NULL)
	     	return 0;
	    else
	    	return EstValide(A->fg) && EstValide(A->fd);
	else
		if(A->fg==NULL && A->fd ==NULL)
			return 1;
		else
			return 0;
}
////
float Eval(Btree *A)
{
	if(A==NULL)
	{
		printf("A est vide");
		exit(-1);
	}
	if(A->info=='+')
	 	return Eval(A->fg)+Eval(A->fd);
	if(A->info=='-')
	 	return Eval(A->fg)-Eval(A->fd);
	if(A->info=='*')
	 	return Eval(A->fg)*Eval(A->fd);
	if(A->info=='/')
	 	return 1.*Eval(A->fg)/Eval(A->fd);
	else
		return char2int(A->info);
}
////PP
main()
{
	Btree *A;
	A=ArbrVide();
	A=CreerFeuille('/');
	A->fg=CreerFeuille('5');
	A->fd=CreerFeuille('2');
	//A->fd->fg=CreerFeuille('5');
	//A->fd->fd=CreerFeuille('6');
	//printf("%d",EstValide(A));
	printf("la valeur de l'expression est %f",Eval(A));
}

