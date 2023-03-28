#include<stdio.h>
#include<conio.h>
#include<string.h>
///////////Q2
void Min2MajFichier(char Fsrc[],char Fdest[])
{
FILE *fs,*fd;
char cmin,cmaj;
fs=fopen(Fsrc,"r");
fd=fopen(Fdest,"w");
cmin=fgetc(fs);
while(cmin!=EOF)
{
 if (cmin>='a' && cmin<='z')
   cmaj=cmin-32;
 else
   cmaj=cmin;
 fprintf(fd,"%c", cmaj);
 cmin=fgetc(fs);
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
