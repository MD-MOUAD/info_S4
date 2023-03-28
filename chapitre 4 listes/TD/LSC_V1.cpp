#include<stdio.h>
#include<stdlib.h>
///Liste simplement chaînée
//Définir le type liste
typedef struct cellule{
	int info;
	struct cellule *suiv;
}liste;
//Ajout debut
liste *AjoutDebut(liste *L,int x)
{
liste *C;
//Réservation 
C=(liste*)malloc(sizeof(liste));
if(C!=NULL)
{
	C->info=x;
	C->suiv=NULL;
	//Branchement
	C->suiv=L;
	L=C;
}
return L;
}
//Adresse de la dernière cellule
liste * LastCellule(liste *L)
{
	liste *p=NULL;
	while(L!=NULL)
	{
		p=L;
		L=L->suiv;
	}
	return p;
}
//AjoutFin
liste *AjoutFin(liste *L,int x)
{
	liste *C,*p;
//Réservation 
C=(liste*)malloc(sizeof(liste));
if(C!=NULL)
{
	C->info=x;
	C->suiv=NULL;
//Branchement
p=LastCellule(L);
if(p==NULL)
  L=C;
else
  p->suiv=C;
}
return L;
}
//AjoutFin1: 2eme solution
liste *AjoutFin1(liste *L,int x)
{
	liste *C,*p;
//Réservation 
C=(liste*)malloc(sizeof(liste));
if(C!=NULL)
{
	C->info=x;
	C->suiv=NULL;
}
//On cherche l'adresse de la dernière cellule
if(L!=NULL)
{
p=L;
while(p->suiv!=NULL)
  p=p->suiv;
p->suiv=C;
}
else
{
	L=C;
}
return L;
}
//SupprimerDebut(liste *L)
liste *SupprimerDebut(liste *L)
{
	liste *p;
	if(L!=NULL)
	{
		p=L;
		L=L->suiv;
		free(p);
	}
	return L;
}
//SupprimerFin()
liste * SupprimerFin(liste *L)
{
	liste *c,*p;
	//Cas 1: L est vide
	if (L==NULL)
	   return L;
	//Cas 2: L contient une seule cellule
	if (L->suiv==NULL)
		{
	     free(L);
	     return NULL;
	   }
	//Cas 3: L contient plusieurs cellules
	p=L;
	while(p->suiv!=NULL)
	{
		c=p;
		p=p->suiv;
	}
	free(p);
	c->suiv=NULL;
	return L;
}
/////////SupprimerFin
liste *SupprimerFin1(liste *L)
{   liste *c,*p;
	if (L!=NULL)
	{ 	p=L;
		c=NULL; 
		//On cherche deux adresses:
		//p:adresse de la derniere cellule
		//c:adresse de l'avant derniere cellule
		while (p->suiv!=NULL)
		{
			c=p;
			p=p->suiv;
		}
		//la liste contient une seule cellule
		if(c==NULL)
				{
               	free(p);
               	L=NULL;
           		}
    	else
        	{
            	free(p);
            	c->suiv=NULL;  
        	}
	}
	return L;
}
///Supprimer element
liste * SupprimerElement(liste *L, int x)
{
    liste *c,*p;
	if (L!=NULL)
	{    //x se trouve dans la première cellule
		if (L->info==x)
		{
			c=L;
			L=L->suiv;
			free(c);
		}
		else
		{   // x peut être au milieu ou non
			c=L;
			while(c!=NULL && c->info!=x)
			{
				p=c;
				c=c->suiv;
			}
			if(c!=NULL)
			{
				p->suiv=c->suiv;
				free(c);
		    }
		    else 
		     printf("%d n'existe pas\n",x);
		   
			}
			
   } 
   return L;
}

//Afficher la liste
void AfficherListe(liste *L)
{
	liste *p;
	p=L;
	while(p!=NULL)
	{
		printf("%d->",p->info);
		p=p->suiv;
	}
	printf("NULL");
}
//////
int recherche(liste *L, int x)
{
	liste *p;
	p=L;
	while (p!=NULL)
	{
		if (p->info==x)
		   return 1;
		p=p->suiv;
	}
	return 0;
	
}
///
int sommeElt(liste *L)
{
	int s;
	liste *p;
	s=0;
	p=L;
	while(p!=NULL)
	{
		s=s+p->info;
		p=p->suiv;
	}
	return s;
}
/////
int TailleListe(liste *L)
{
	int cpt=0;
	while(L!=NULL)
	{
		cpt=cpt+1;
		L=L->suiv;
	}
	return cpt;
}
//////////////
float MoyenneListe(liste *L)
{
	float m;
	m=1.*sommeElt(L)/TailleListe(L);
	return m;
}
///
int ProduitListe(liste *L)
{
	int p=1;
	while(L!=NULL)
	{
		p=p*L->info;
		L=L->suiv;
	}
	return p;
}
//////////////
liste * Inverser(liste *L)
{
	liste *I,*p;
	p=L;
	while(p!=NULL)
	{
		I=AjoutDebut(I,p->info);
		p=p->suiv;
	}
	return I;
}
////PP
main()
{
	liste *L=NULL,*I=NULL;
	//L=AjoutDebut(L,5);
	//L=AjoutDebut(L,3);
	//L=AjoutDebut(L,1);
	//L=AjoutFin(L,1);
	//L=AjoutFin(L,2);
	//L=AjoutFin(L,3);
	L=AjoutFin1(L,1);
	L=AjoutFin1(L,2);
	L=AjoutFin1(L,3);
	AfficherListe(L);
	I=Inverser(L);
	printf("\n");
	AfficherListe(I);
	//L=SupprimerElement(L,4);
	//L=SupprimerFin(L);
	//L=SupprimerDebut(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerDebut(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerDebut(L);
	//AfficherListe(L);
}
