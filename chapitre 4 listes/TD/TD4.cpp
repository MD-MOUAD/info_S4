#include<stdio.h>
#include<stdlib.h>
///Liste simplement chaînée
//Définir le type liste
typedef struct cellule{
	int info;
	struct cellule *suiv;
}liste;
////Exercice 2
////Q1
liste *AlloueCellule()
{
	liste *c;
	c=(liste *)malloc(sizeof(liste));
	return c;
}
////Q2
liste *CreerCellule(int val)
{
	liste *c;
	c=AlloueCellule();
	if(c!=NULL)
	{
		c->info=val;
		c->suiv=NULL;
	}
	return c;
}
///Exercice 3
//Q1 La fonction InsertDebut
liste *InserDebut(liste *L,int x)
{
	liste *c;
	//Reservation
	c=(liste *)malloc(sizeof(liste));
	if(c!=NULL)
	{
		c->info=x;
		c->suiv=NULL;
	}
	//branchement;
	c->suiv=L;
	L=c;
	return L;
}
//Q2 La fonction InsertSucc(Liste *L)
liste *InserSucc(liste *L)
{
	int x;
	printf("Donnez un entier x:");
	scanf("%d",&x);
	while (x!=0)
	{
		L=InserDebut(L,x);
		printf("Donnez un entier x:");
		scanf("%d",&x);
	}
	return L;
}

///////Exercice 4
//Q1
int Taille_it(liste * L)
{
	liste *p;
	int cpt=0;
	p=L;
	while(p!=NULL)
	{
		cpt++;
		p=p->suiv;
	}
	return cpt;
}
////Q2
int Taille_re(liste * L)
{
	if(L==NULL)
		return 0;
	else
	return 1+Taille_re(L->suiv);
}
///Q3 --->solution itérative
void AfficherListe_it(liste *L)
{
	liste *p;
	p=L;
	while(p!=NULL)
	{
		printf("%d--->",p->info);
		p=p->suiv;
	}
	printf("NULL");
	
}
////Q3 ---> Solution récursive 
void AfficherListe_re(liste *L)
{
	if(L==NULL)
	  printf("NULL");
	else
	{
		printf("%d--->",L->info);
		AfficherListe_re(L->suiv);
	}
	
}
////////Q4 ---> Solution récursive 
void AfficherListeInv_re(liste *L)
{
	if(L!=NULL)
	{
		AfficherListeInv_re(L->suiv);
		printf("%d--->",L->info);
	}
	
}
////////////Exercice 7
///Q1 solution itérative
int sommeElement_it(liste *L)
{
	liste *p;
	int s=0;
	p=L;
	while(p!=NULL)
	{
		s=s+p->info;
		p=p->suiv;
	}
	return s;
}
///Q1 solution récursive
int sommeElement_re(liste *L)
{
	if(L==NULL)

		return 0;
	else
	  return L->info+sommeElement_re(L->suiv);
}
/////Q2
float moyenne_liste(liste *L)
{
	float m;
	m=1.*sommeElement_it(L)/Taille_it(L);
}
/////Q3
int recherche_it(liste *L,int x)
{liste *p;
p=L;
while (p!=NULL && p->info!=x)
      p=p->suiv;
if (p!=NULL)
   return 1;
else
  return 0;
}
////
int recherche1_it(liste *L,int x)
{liste *p;
p=L;
while (p!=NULL )
{
   	if (p->info==x)
      return  1;
	p=p->suiv;
}
  return 0;
}
////Q3 solution récursive
int recherche_re(liste *L,int x)
{
	if(L==NULL)
 		 return 0;
 	if (L->info==x)
 		return 1;
 	else
 	  	return recherche_re(L->suiv,x);
}
/////Exercice 5
/////Q1 SupprimerDebut
liste *SupprimerDebut(liste *L)
{
	liste *c;
	if(L!=NULL)
	{
		c=L;
		L=L->suiv;
		free(c);
	}
	return L;
}
/////Q2 SupprimerFin
liste *SupprimerFin(liste *L)
{
	liste *c,*p;
	if (L!=NULL)
	{
		p=L;
		c=NULL; 
		//On cherche deux adresses:
		//C:adresse de la derniere cellule
		//p:adresse de l'avant derniere cellule
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
///Q3 Supprimer element
liste * SupprimerElement(liste *L, int x)
{
	liste *c,*p;
	if(L!=NULL)
	{
		if(L->info==x)
		{
			c=L;
			L=L->suiv;
			free(c);
		}
		else
		{
			c=L;
			p=NULL;
			while(c!=NULL && c->info!=x)
			{
				p=c;
				c=c->suiv;
			}
			//x n'existe pas dans L
			if(c==NULL)
			 	printf("%d n'existe pas",x);
			else
				{
				p->suiv=c->suiv;
				free(c);
				}
		}
	}
return L;
}
////Q4.
liste *SupprimerTout(liste *L,int x)
{
	while(recherche_it(L,x)==1)
	  L=SupprimerElement(L,x);
	return L;
}
///Exercice 6
void LibereListe(liste *L)
{
	liste *c;
	while(L!=NULL)
	{
		c=L;
		L=L->suiv;
		free(c);
	}
}
////PP
main()
{
	liste *L;
	L=NULL;
	L=InserSucc(L);
	
	//AfficherListe_it(L);
	//printf("\n");
	//printf("Solution itérative -->la liste L contient %d\n",Taille_it(L));
	//printf("Solution récursvie -->la liste L contient %d\n",Taille_re(L));
	AfficherListe_re(L);
	printf("\n");
	//AfficherListeInv_re(L);
	L=SupprimerTout(L,1);
	printf("\n");
	AfficherListe_re(L);
}
