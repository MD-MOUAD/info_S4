//Implémentation d'une liste doublement chaînée en utilisant deux poiteurs
//L est un variable statique
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//Définir le type Dcellule
typedef struct cellule{
        int info;
        struct cellule *suiv;
        struct cellule *prec;
        }Dcellule;
//Défirnir le type Dliste
typedef struct liste{
        Dcellule * first;
        Dcellule *last;
        }Dliste;
//////////Creer une liste vide
void CreerListeVide(Dliste *L)
{
	L->first=NULL;
	L->last=NULL;
}
///////////Tester si L est vide ou non
int EstVide(Dliste *L)
{
	if(L->first==NULL)
		return 1;
	else
		return 0;
}

//////////AjoutDebut
void AjoutDebut(Dliste *L,int x)
{
	Dcellule * c;
	c=(Dcellule *)malloc(sizeof(Dcellule));
	if(c!=NULL)
	{
		c->info=x;
		c->prec=NULL;
		c->suiv=NULL;
		//branchement
		if(EstVide(L)==1)
		   {
		  	 	L->first=c;
		  		L->last=c;
		 	}
		 else
		 	{
			 	c->suiv=L->first;
			 	L->first=c;
			 }
		  }
}


//////////AjoutFin
void AjoutFin(Dliste *L,int x)
{
	Dcellule * c;
	c=(Dcellule *)malloc(sizeof(Dcellule));
	if(c!=NULL)
	{
		c->info=x;
		c->prec=NULL;
		c->suiv=NULL;
		//branchement
		if(EstVide(L)==1)
		   {
		  	 	L->first=c;
		  		L->last=c;
		 	}
		else
		{
			L->last->suiv=c;
			c->prec=L->last;
			L->last=c;
		}
	}
}
///
void SupprimerDebut(Dliste *L)
{
	Dcellule *c;
	if(EstVide(L)==0)
	{

	if (L->last==L->first)	
	{
		c=L->first;
		L->first=NULL;
		L->last=NULL;
		free(c);
	}
	else
	{	
		c=L->first;
		L->first=L->first->suiv;
		free(c);
	}
	
	}
}
/////
void SupprimerFin(Dliste *L)
{

	Dcellule *c;
    if(EstVide(L)==0)
    {
	 c=L->last;
	 L->last=L->last->prec;
    //Le cas ou L contient une seule cellule
    if( L->last==NULL)
        L->first=NULL;
    else
        L->last->suiv=NULL;
    free(c);
	}
}

//Chercher l'adress d'un element x
Dcellule *ChercherAdresseEle(Dliste *L,int x)
{
	Dcellule *p;
	p=L->first;
	while(p!=NULL)
	{
		if(p->info==x)
			return p;
		p=p->suiv;
	}
	return NULL;
}
/////SupprimerElement()
void SupprimerElement(Dliste *L,int x)
{
	Dcellule *p,*c;
	p=ChercherAdresseEle(L,x);
	if(p==NULL)
	{
		printf("%d n'existe pas",x);
		exit(-1);
	}
	else
	{
		if(p->prec==NULL)
			SupprimerDebut(L);
		else
		   if(p->suiv==NULL)
		   	SupprimerFin(L);
		   	else
		   	{
		   		c=p;
            	p->prec->suiv=p->suiv;
            	p->suiv->prec=p->prec;
            	free(c);
			}
	}
}

///
void AfficherListe(Dliste *L)
{
	Dcellule *p;
  	p=L->first;
  	while(p!=NULL)
  	{
   		 printf("%d-->",p->info);
    	p=p->suiv;
  	}
  printf("NULL");
}
////////////
main()
{
  Dliste *L;
 L=(Dliste *)malloc(sizeof(Dliste));
 CreerListeVide(L);
AfficherListe(L);
AjoutDebut(L,2);
AjoutDebut(L,1);
printf("\n");
AfficherListe(L);
SupprimerFin(L);
printf("\n");
AfficherListe(L);

}
