////Implémentation d'un arbre binaire de recherche
#include<stdio.h>
#include<stdlib.h>
//////deux variables
int T[100];
int i=0;
////////////////
/* Définition du type noeud d’un arbre binaire */
typedef struct noeud{
int  info; /*le champ etiq peut avoir n’importe quel type*/
struct noeud *fg ; /*pointeur contenant l’adresse du ABG*/
struct noeud *fd ; /*pointeur contenant l’adresse du ABD*/
}BRtree ;
//// Primitives
BRtree * ArbrVide()
{
	BRtree *A;
	A=NULL;
	return A;
}
//////
int EstVide(BRtree *A)
{
	if(A==NULL)
		return 1;
	else
		return 0;
}
////////////////////
BRtree *CreerFeuille(int e)
{
	BRtree *c;
	c=(BRtree*)malloc(sizeof(BRtree));
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
BRtree *InsertFeuille(BRtree *A,int x)
{
	if(A==NULL)
		return CreerFeuille(x);
	if(x<=A->info)
		A->fg=InsertFeuille(A->fg,x);
	else
		A->fd=InsertFeuille(A->fd,x);
}
////
BRtree *Tab2Abr(int T[],int N)
{
  	int i;
  	BRtree *A;
  	A=NULL;
  	for (i=0;i<N;i++)
   		A=InsertFeuille(A,T[i]);
   	return A;
  
}
/////
void Abr2Tab(BRtree *A)
{
  	if (A!=NULL)
	{
		Abr2Tab(A->fg);
		T[i]=A->info;
		i=i+1;
		Abr2Tab(A->fd);
	}
}
/////////////////
void ParcoursInfixe(BRtree *A)
{
	if (A!=NULL)
	{
		ParcoursInfixe(A->fg);
		printf("%d\n",A->info);
		ParcoursInfixe(A->fd);
	}
}
//////////////
void AffichageDecroissant(BRtree *A)
{
	if (A!=NULL)
	{
		ParcoursInfixe(A->fd);
		printf("%d\n",A->info);
		ParcoursInfixe(A->fg);
	}
}
//////////////////////////
int RechercheElt(BRtree *A,int x)
{
	if(A==NULL)
		return 0;
	if(x==A->info) 
		return 1;
	if(x<A->info)
		return RechercheElt(A->fg,x);
	else
		return RechercheElt(A->fd,x);
}
////
int EstABR(BRtree *A)
{
		int j;
		Abr2Tab(A);
		for(j=0;j<i-1;j++)
		  if(T[j]>T[j+1])
		  	return 0;
		return 1;
}
int MinABR_Re(BRtree * A)
{
	if(A==NULL)
	{
		printf("Arbre vide");
		exit(-1);
	}
	if(A->fg==NULL)
		return A->info;
	else
		return MinABR_Re(A->fg);
}
///
int MinABR_it(BRtree * A)
{
	if(A==NULL)
	{
		printf("Arbre vide");
		exit(-1);
	}
	while (A->fg!=NULL)
		A=A->fg;
	return A->info;
}
///PP
main()
{
	int j;
	BRtree *A;
	int T1[]={8,2,1,5,7,6,11,3};
	A=Tab2Abr(T1,8);
	//ParcoursInfixe(A);
	//Abr2Tab(A);
	//for(j=0;j<i;j++)
	//	printf("%d\n",T[j]);
	//printf("le min est %d",MinABR_it(A));
	AffichageDecroissant(A);
	
	}
