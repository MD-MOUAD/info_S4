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
Dliste CreerListeVide()
{
	Dliste L;
	L.first=NULL;
	L.last=NULL;
}
///////////Tester si L est vide ou non
int EstVide(Dliste L)
{
	if(L.first==NULL)
		return 1;
	else
		return 0;
}

//////////AjoutDebut
Dliste AjoutDebut(Dliste L,int x)
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
		  	 	L.first=c;
		  		L.last=c;
		 	}
		 else
		 	{
			 	c->suiv=L.first;
			 	L.first=c;
			 }
		  }
	return L;
}


//////////AjoutFin
Dliste AjoutFin(Dliste L,int x)
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
		  	 	L.first=c;
		  		L.last=c;
		 	}
		else
		{
			L.last->suiv=c;
			c->prec=L.last;
			L.last=c;
		}
	}
	return L;
}
///
Dliste SupprimerDebut(Dliste L)
{
	Dcellule *c;
	if(EstVide(L))
	  return L;
	if (L.last==L.first)	
	{
		c=L.first;
		L.first=NULL;
		L.last=NULL;
		free(c);
	}
	else
	{	
		c=L.first;
		L.first=L.first->suiv;
		free(c);
	}
	return L;
}
/////
Dliste SupprimerFin(Dliste L)
{

	Dcellule *c;
    if(EstVide(L)==0)
    {
	 c=L.last;
	 L.last=L.last->prec;
    //Le cas ou L contient une seule cellule
    if( L.last==NULL)
        L.first=NULL;
    else
        L.last->suiv=NULL;
    free(c);
    }
    return L;
}

//Chercher l'adress d'un element x
Dcellule *ChercherAdresseEle(Dliste L,int x)
{
	Dcellule *p;
	p=L.first;
	while(p!=NULL)
	{
		if(p->info==x)
			return p;
		p=p->suiv;
	}
	return NULL;
}
/////SupprimerElement()
Dliste SupprimerElement(Dliste L,int x)
{
	Dcellule *p,*c;
	p=ChercherAdresseEle(L,x);
	if(p==NULL)
	{
		printf("%d n'existe pas",x);
		return L;
	}
	else
	{
		if(p->prec==NULL)
			L=SupprimerDebut(L);
		else
		   if(p->suiv==NULL)
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

///
void AfficherListe(Dliste L)
{
	Dcellule *p;
  	p=L.first;
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
  Dliste L;
  L=CreerListeVide();
  L=AjoutDebut(L,1);
  L=AjoutDebut(L,2);
  //L=AjoutDebut(L,3);
  AfficherListe(L);
  printf("\n");
  L=SupprimerFin(L);
  AfficherListe(L);
  /*  printf("\n");
  L=SupprimerDebut(L);
  AfficherListe(L);
    printf("\n");
  L=SupprimerDebut(L);
  AfficherListe(L);
    printf("\n");
  L=SupprimerDebut(L);
  AfficherListe(L);*/


}
