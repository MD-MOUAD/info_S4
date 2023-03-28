#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct etudiant{
        char nom[20];
        int age;
        float note;
        }student;
////On utilise un fichier texte
////////////Q1 
void creer_fichier(char nomFich[])
{
FILE *f;
student E;
int i,N;
f=fopen(nomFich,"w");
printf("Donnez le nombre des etudiants:");
scanf("%d",&N);
for (i=1;i<=N;i++)
 {
  printf("Votre nom svp:");
  scanf("%s",E.nom);
  printf("Votre age svp:");
  scanf("%d",&E.age);
  printf("Votre note svp:");
  scanf("%f",&E.note);
  //transfert de  RAM -->disque dur
  fprintf(f,"%s %d %f\n",E.nom,E.age,E.note);
}
  printf("Le fichier a ete bien cree");
fclose(f);
}
/////////////Q2
void lire_fichier(char nomFich[])
{
FILE *f;
student E;
f=fopen(nomFich,"r");
while(!feof(f))
 {
 //transfert de  disque dur--->RAM
  fscanf(f,"%s %d %f\n",E.nom,&E.age,&E.note);
  printf("%s %d %f\n",E.nom,E.age,E.note);
}
fclose(f);
}
///PP
main()
{
char nomFichier[10];
printf("Donnez le nom de fichier à creer");
scanf("%s",nomFichier);
creer_fichier(nomFichier);
printf("Donnez le nom de fichier à ouvrir");
scanf("%s",nomFichier);
lire_fichier(nomFichier);
getch();

}
