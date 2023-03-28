////Correction TP3
///Problème 1: allocation statique de la mémoire
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//définir le type individu
typedef struct Personne{
	char nom[16];
	int annee_naissance;
	char tel[20];
}individu;
//Définir le type annuaire
typedef struct Carnet{
	individu P[100];
	int n;
}annuaire;
///Q1
individu saisir_individu()
{
	individu I;
	printf("Votre nom svp:");
	scanf("%s",I.nom);
	rewind(stdin);
	printf("Votre annee de naissance svp:");
	scanf("%d",&I.annee_naissance);
	printf("Votre numéro de tel svp:");
	scanf("%s",I.tel);
	return I;
}
///un autre prototype
void saisir_individu1(individu *I)
{

	printf("Votre nom svp:");
	scanf("%s",I->nom);
	printf("Votre annee de naissance svp:");
	scanf("%d",&I->annee_naissance);
	printf("Votre numéro de tel svp:");
	scanf("%s",I->tel);
}
//Q2
int identique(individu m1, individu m2)
{
	if(strcmp(m1.nom,m2.nom)==0 && m1.annee_naissance==m2.annee_naissance)
	  return 1;
	else 
	  return 0;
}
//Q3 Passage par valeur
void ajouter_personne(individu I, annuaire A)
{
 if (A.n<100)
 {
 	A.P[A.n]=I;
 	A.n=A.n+1;
 }
 else
  printf("l'annuaire est plein'");
}
///Q4 passage par adresse
void ajouter_personne1(individu I, annuaire *A)
{
 if (A->n<100)
 {
 	A->P[A->n]=I;
 	A->n=A->n+1;
 }
 else
  printf("l'annuaire est plein'");
}
//Q5
void afficher_individu(individu I)
{
	printf("Nom:%s Année de naissance:%d Tél:%s\n",I.nom,I.annee_naissance,I.tel);
}
//Q6
void afficher_annuaire(annuaire A)
{
	int i;
	if( A.n==0)
	 	printf("l'annuaire est vide");
	else
	 {
	 	for(i=0;i<A.n;i++)
	 	   afficher_individu(A.P[i]);
	 }
}
///Q7
int position(individu m, annuaire A)
{int i;
	for(i=0;i<A.n;i++)
 		if (identique(m, A.P[i])==1) 
    		return i;
	return -1;
}
///Q8
char  *chercher_nom(char *T,annuaire A)
{
	int i;
	for(i=0;i<A.n;i++)
		if (strcmp(T,A.P[i].tel)==0)
			return A.P[i].nom;
	return NULL;
}
///Q9
char  *chercher_tel(char *name,annuaire A)
{
	int i;
	for(i=0;i<A.n;i++)
		if (strcmp(name,A.P[i].nom)==0)
			return A.P[i].tel;
	return NULL;
}
///Q9 on affiche tous les numéros de la perosonne name
void chercher_tel_all(char *name,annuaire A)
{
	int i;
	for(i=0;i<A.n;i++)
		if (strcmp(name,A.P[i].nom)==0)
			printf("%s",A.P[i].tel);
}
///Q10
void supprimer_personne(annuaire *A, int p)
{
	int i;
	if (p>=0 && p<A->n)
	{
		for(i=p;i<A->n-1;i++)
		   A->P[i]=A->P[i+1];
		A->n=A->n-1;
	}
	else
	  printf("position invalide");
}
////Q11
/*void trier_annuaire(annuaire *A)
{
	int i,posmin,j;
	individu c;
	for(i=0;i<A->n;i++)
	{
		posmin=i;
		for(j=i+1;j<A->n;j++)
			if(strcmp(A->P[j]->nom,A->P[i]->nom)==0)
			    posmin=j;
		//permutation
		c=A->P[i];
		A->P[i]=A->P[j];
		A->P[j]=c;
}*/
//PP
main()
{
	annuaire A;
	individu P1, P2,P3;
	//Initialisation
	A.n=0;
	P1=saisir_individu();
	//P2=saisir_individu();
	//saisir_individu1(&P3);
	//afficher_individu(P1);
	//afficher_individu(P3);
	afficher_annuaire(A);
	printf("\n");
	//ajouter_personne(P1,A);
	ajouter_personne1(P1, &A);
	afficher_annuaire(A);
}
