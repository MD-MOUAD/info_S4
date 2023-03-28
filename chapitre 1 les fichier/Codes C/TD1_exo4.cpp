#include<stdio.h>
#include<conio.h>
#include<string.h>
////////////Q1
void Min2MajLigne(char src[],char dest[])
{
int i;
for (i=0;i<=strlen(src);i++)
{
 if (src[i]>='a' && src[i]<='z')
   dest[i]=src[i]+('A'-'a');
 else
   dest[i]=src[i];
}
}
///////////Q2
void Min2MajFichier(char Fsrc[],char Fdest[])
{
FILE *fs,*fd;
char ligneMin[100],ligneMaj[100];
fs=fopen(Fsrc,"r");
fd=fopen(Fdest,"w");
while(!feof(fs))
{
 fgets(ligneMin,100,fs);
 Min2MajLigne(ligneMin,ligneMaj);
 fprintf(fd,"%s", ligneMaj);
}
fclose(fs);
fclose(fd);
}
////////////
main()
{
 char nomFS[100],nomFD[100];
 printf("Donnez le fichier à ouvrir:");
 scanf("%s",nomFS);
 printf("Donnez le fichier destination:");
 scanf("%s",nomFD);
Min2MajFichier(nomFS,nomFD);
getch();
}
