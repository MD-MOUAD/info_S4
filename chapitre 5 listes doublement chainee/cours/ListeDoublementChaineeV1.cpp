#include<stdio.h>
#include<stdlib.h>
///Liste doublement chaînée
//Définir le type liste
typedef struct cellule{
	int info;
	struct cellule *prec;
	struct cellule *suiv;
}Dliste;
////////La fonction AjoutDebut
Dliste *AjoutDebut(Dliste *L,int x)
{
	Dliste *c;
	//Reservation
	c=(Dliste *)malloc(sizeof(Dliste));
	if(c!=NULL)
	{
		c->info=x;
		c->prec=NULL;
		c->suiv=NULL;
	}
	//branchement;
	if(L==NULL)
	{
		L=c;
	}
	else
	{
	
		c->suiv=L;
		L->prec=c;
		L=c;
	}
	return L;
}
////Fonction AdressDernier
Dliste *AdressDernier(Dliste *L)
{
	Dliste *p;
	while(L!=NULL)
	{
		p=L;
		L=L->suiv;
	}
	return p;
}
///Ajout fin
Dliste *AjoutFin(Dliste *L,int x)
{
	Dliste *c,*p;
	//Reservation
	c=(Dliste *)malloc(sizeof(Dliste));
	if(c!=NULL)
	{
		c->info=x;
		c->prec=NULL;
		c->suiv=NULL;
	}
	//branchement;
	p=AdressDernier(L);
	if (p==NULL)
	 L=c;
	else
	{
		p->suiv=c;
		c->prec=p;
	}
	return L;
}
///SupprimerDebut
Dliste *SupprimerDebut(Dliste *L)
{
	Dliste *c;
	if(L!=NULL)
	{
		//Le cas ou L contient une seule cellule
		if(L->suiv==NULL)
			{
				c=L;
				free(c);
				L=NULL;
			}
		else
			{
				c=L;
				L=L->suiv;
				L->prec=NULL;
				free(c);
			}
	return L;
	}
}
///La fonction AfficherListe
void AfficherListe(Dliste *L)
{
	Dliste *p;
	p=L;
	while(p!=NULL)
	{
		printf("%d--->",p->info);
		p=p->suiv;
	}
	printf("NULL");
	
}


////PP
main()
{
	
	Dliste *L;
	L=NULL;
	//L=AjoutDebut(L,1);
	//L=AjoutDebut(L,2);
	L=AjoutFin(L,1);
	L=AjoutFin(L,2);
	AfficherListe(L);
	printf("\n");
	L=SupprimerDebut(L);
	AfficherListe(L);
	printf("\n");
	L=SupprimerDebut(L);
	AfficherListe(L);
}
