/*******TD N 5 Exo 2********/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/// Q1 Définir le type liste
typedef struct cellule{
        char info;
        cellule * suiv;
        }liste;
//Définir le type Pile
typedef liste *Pile;
/////////////Creer une pile vide
Pile PileVide()
{
 return NULL;
}
//////// Tester si P est vide
int EstVide(Pile P)
{
  if (P==NULL)
    return 1;
  else
   return 0;
}
////////Empiler(P,x):ajouter un element au debut
Pile Empiler(Pile P,char x)
{
Pile c;
c=(Pile)malloc(sizeof(liste));
if(c!=NULL)
 {
  c->info=x;
  c->suiv=P;
  P=c;  
 }
 return P;
}
////////Depiler(P):Supprimer le premier element 
Pile Depiler(Pile P)
{
     Pile c;
     if (EstVide(P)==0) 
     {
      c=P;
      P=P->suiv;
      free(c);
     }
 return P;
}
//////////SommetPile(P):retourne le premier element
int SommetPile(Pile P)
{
    if (EstVide(P)==0) 
      return P->info;
    else
     {
      printf("La pile est vide");
      getchar();
      exit(-1);
     }
}
////////
int parenthesage(char *s)
{
Pile P;
P=PileVide();
int i=0;
 while( s[i]!='\0')
  {
   if (s[i]=='(')
     P=Empiler(P,s[i]);
   else
     if (s[i]==')')
        if (EstVide(P)==1)
           return 0;
        else
            P=Depiler(P);
   i=i+1  ;
   }
if (EstVide(P)==1)
 return 1;
else
 return 0;
}
/////////main()
main()
{
char ch[20];
while(1)
{
printf("Donnez une chaine:");
scanf("%s",ch);
if (parenthesage(ch))
 printf("%s est valide",ch);
else
printf("%s n'est pas valide",ch);
}
getch();
}
