/// TP N°4: liste simplement chaînée
/// On utilise une variable globale
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Définir le type livre 
typedef struct ouvrage{
	int num;
	char titre[20];
	char auteur[30];
	int annee_edition;
}livre;
///Définir le type liste
typedef struct cellule{
	livre info;
	struct cellule *suiv;
}liste;
//Déclartion d'une variable globale
liste *premier;
////Q1
int nombre()
{
liste *p;
int cpt;
cpt=0;
p=premier;
while(p!=NULL)
{
	cpt++;
	p=p->suiv;
}
return cpt;
}
////Q2
void  ajouter()
{
	livre A;
	liste *c,*p;
	//on saisit les informations de A
	A.num=0;
	printf("Donnez le titre:");
	gets(A.titre);
	rewind(stdin);
	printf("Donnez l'auteur:");
	gets(A.auteur);
	rewind(stdin);
	//on verifie que la date de l'édition < à la date de la 1ere cellule
	printf("Donnez l'annee edition");
	scanf("%d",&A.annee_edition);
	rewind(stdin);
	if(premier!=NULL)
	{
		while (A.annee_edition>premier->info.annee_edition)
		{
			printf("Donnez une autre annee edition inferieure:");
			scanf("%d",&A.annee_edition);
		}
	}
	//Réservation
	c=(liste*)malloc(sizeof(liste));
	if(c!=NULL)
	{
		c->info=A;
		c->suiv=NULL;
	}
	if(premier==NULL)
	{
		premier=c;
	}
	else
	{
		c->suiv=premier;
		premier=c;
	}
	//Mise à jour;
	p=premier;
	while(p!=NULL)
	{
		p->info.num=p->info.num+1;
		p=p->suiv;
	}
}
//Q3
void supprimer(int val)
{
	liste *c,*p;
	if(premier!=NULL)
	{
	if(premier->info.num==val)
		{
			c=premier;
			premier=premier->suiv;
			free(c);
			p=premier;
			//Mise à jour
			while(p!=NULL)
				{
					p->info.num=p->info.num-1;
					p=p->suiv;
				}
		}
	else
	{
		c=premier;
		while(c!=NULL && c->info.num!=val)
		{
			p=c;
			c=c->suiv;
		}
		if(c!=NULL)
		{
			p->suiv=c->suiv;
			free(c);
			//Mise à jour
			p=p->suiv;
			while(p!=NULL)
				{
					p->info.num=p->info.num-1;
					p=p->suiv;
				}
		}
		else
		 printf("ce livre n'existe pas");
		
	}
}
}
//Q4
void affiche1()
{
	liste *p;
	p=premier;
	while(p!=NULL)
	{
		printf("Num:%d Titre:%s Auteur :%s Annee:%d-->",p->info.num,p->info.titre,p->info.auteur,p->info.annee_edition);
		p=p->suiv;
	}
	printf("NULL");
}
//////////Q5
void affiche2()
{
	liste *p;
	p=premier;
	while(p!=NULL)
	{
	 if(p->info.annee_edition >=2000)
		printf("Num:%d Titre:%s Auteur :%s Annee:%d-->",p->info.num,p->info.titre,p->info.auteur,p->info.annee_edition);
	  p=p->suiv;
	}
	printf("NULL");
}
//Q6
void affiche3()
{
	liste *p;
	p=premier;
	while(p!=NULL)
	{
	 if(strcmp(p->info.auteur,"Amine Maalouf")==0)
		printf("Num:%d Titre:%s Auteur :%s Annee:%d-->",p->info.num,p->info.titre,p->info.auteur,p->info.annee_edition);
	  p=p->suiv;
	}
	printf("NULL");
}
//Q7
int recherche_livre(char *nom)
{
	liste *p;
	p=premier;
	while(p!=NULL)
	{
		if(strcmp(p->info.titre,nom)==0)
			return 1;
	  	p=p->suiv;
	}
	return -1;
}
//////Q8
int nombre_publication(char *aut)
{
	liste *p;
	int cpt=0;
	p=premier;
	while(p!=NULL)
	{
		if(strcmp(p->info.auteur,aut)==0)
			cpt=cpt+1;
	  	p=p->suiv;
	}
	return cpt;
}
//Q9
int numero(char *aut)
{
	liste *p;
	p=premier;
	while(p!=NULL && p->info.annee_edition!=2011)
	  	p=p->suiv;
	if (p!=NULL)
		return p->info.num;
	else
		return -1;
}
//PP
main()
{
	
	premier=NULL;
	affiche1();
	printf("\n");
	ajouter();
	affiche1();
	
	
}
