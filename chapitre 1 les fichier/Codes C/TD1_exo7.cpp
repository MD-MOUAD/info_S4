#include<stdio.h>
#include<conio.h>
////////Solution 1: on lit ligne par ligne
void copier_collerS1(char fsrc[],char fdest[])
{
char ligne[80];
FILE *f1,*f2;
f1=fopen(fsrc,"r");
f2=fopen(fdest,"w");
while (!feof(f1))
{
 fgets(ligne,80,f1);
 fprintf(f2,"%s",ligne);
}
fclose(f1);
fclose(f2);
}
////////Solution 2: on lit caracter par caractere
void copier_collerS2(char fsrc[],char fdest[])
{
char c;
FILE *f1,*f2;
f1=fopen(fsrc,"r");
f2=fopen(fdest,"w");
while ((c=fgetc(f1))!=EOF)
{
 fputc(c,f2);//fprintf(f2,"%c",c);
}
fclose(f1);
fclose(f2);
}
////////////
main()
{
 char nomFS[100],nomFD[100];
 printf("Donnez le fichier à ouvrir:");
 scanf("%s",nomFS);
 printf("Donnez le fichier destination:");
 scanf("%s",nomFD);
copier_collerS1(nomFS,nomFD);
getch();
}
