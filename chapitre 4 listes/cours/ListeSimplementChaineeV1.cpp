#include<stdio.h>
#include<stdlib.h>
///Liste simplement chaînée
//Définir le type liste
typedef struct cellule{
	int info;
	struct cellule *suiv;
}liste;
////////La fonction AjoutDebut
liste *AjoutDebut(liste *L,int x)
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
////Ajout Fin
liste *AjoutFin(liste *L,int x)
{
	liste *c,*p;
	//Reservation
	c=(liste *)malloc(sizeof(liste));
	if(c!=NULL)
	{
		c->info=x;
		c->suiv=NULL;
	}
	if (L==NULL)
		L=c;
	else
	{
		//on cherche l'adresse de la dernière cellule
		p=L;
		while(p->suiv!=NULL)
			p=p->suiv;
		//branchement;
		p->suiv=c;
	}
	return L;
}
////Fonction AdressDernier
liste *AdressDernier(liste *L)
{
	liste *p;
	while(L!=NULL)
	{
		p=L;
		L=L->suiv;
	}
	return p;
}
////////////////////////Ajout Fin
liste *AjoutFin_Sol2(liste *L,int x)
{
	liste *c,*p;
	//Reservation
	c=(liste *)malloc(sizeof(liste));
	if(c!=NULL)
	{
		c->info=x;
		c->suiv=NULL;
	}
	p=AdressDernier(L);
	if (p==NULL)
	  L=c;
	else
	   p->suiv=c;
	return L;
}
///La fonction AfficherListe
void AfficherListe(liste *L)
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
///
///La fonction AfficherListe
void Afficher2(liste *L)
{
	liste *p;
	p=L;
	while(p!=NULL)
	{
		printf("(%d,%p)--->",p->info,p);
		p=p->suiv;
	}
	printf("NULL");
	
}
///La fonction AfficherListe
void Afficher3(liste *L)
{
	liste *p;
	p=L;
	while(p!=NULL)
	{
		printf("(%x,%x)--->",&p->info,&p->suiv);
		p=p->suiv;
	}
	printf("NULL");
	
}
/////SupprimerDebut
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
/////SupprimerFin
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
///Supprimer element
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
///////////////////
liste *InverserListe(liste *L)
{
	liste *I,*p;
	p=L;
	I=NULL;
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
	liste *L;
	L=NULL;
	liste *I;
	//L=AjoutDebut(L,1);
	//L=AjoutDebut(L,3);
	//L=AjoutDebut(L,10);
	//	L=AjoutDebut(L,5);
	//AfficherListe(L);
	//Afficher2(L);
	//Afficher3(L);
	L=AjoutFin_Sol2(L,1);
	L=AjoutFin_Sol2(L,2);
	L=AjoutFin_Sol2(L,3);
	L=AjoutFin_Sol2(L,4);
	L=AjoutFin_Sol2(L,5);
	AfficherListe(L);
	//printf("\n");
	//L=SupprimerDebut(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerDebut(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerDebut(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerDebut(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerFin(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerFin(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerFin(L);
	//AfficherListe(L);
	//printf("\n");
	//L=SupprimerFin(L);
	//AfficherListe(L);
	printf("\n");
	//L= SupprimerElement(L,3);
	I=InverserListe(L);
	AfficherListe(I);
}
