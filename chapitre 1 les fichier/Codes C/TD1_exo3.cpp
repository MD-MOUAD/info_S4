#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
///////////Q1
void alea(char nomFich[])
{
int nl,a,i,j;
nl=rand()%15;
FILE *f;
f=fopen(nomFich,"w");
for (i=1;i<=nl;i++)
  {
    for(j=1;j<=5;j++)
      {
       a=rand()%20;
       fprintf(f,"%d",a);
       fprintf(f," ");
      } 
      fprintf(f,"\n");
   }
}
//////////
void SommeLigneSol1(char FichSr[],char FichDs[])
{
int a,s,i;
FILE *fs,*fd;
fs=fopen(FichSr,"r");
fd=fopen(FichDs,"w");
while(!feof(fs))
{
s=0;
for (i=0;i<5;i++)
 {
   //transfert de Disque dur ---> RAM
   fscanf(fs,"%d",&a);
   s=s+a;
 }
 fscanf(fs,"\n");
 //Transfert de RAM --->Disque dur
fprintf(fd,"%d\n",s);
}
 fclose(fs);
  fclose(fd);
}
///////////
/////////
int charToint(char *s)
{
int i,n;
n=0;
for (i=0;i<strlen(s);i++)
 n=n*10+(s[i]-'0');
return n;
}
///////////
int SommeLigne(char ch[])
{
 int i,j,s;
 s=0;
 char ss[10];
 i=0;
 while (i<strlen(ch))
   {
     j=0;
     while(ch[i+j]!=' ' && i+j<strlen(ch))
         {
         ss[j]=ch[i+j];
          j=j+1;
         }
     ss[j]='\0';
     //printf("%s\n",ss);
     s=s+charToint(ss);
     i=i+j+1;
  }
 return s;
}
//////////
void SommeLigneSol2(char FichSr[],char FichDs[])
{
FILE *fs,*fd;
fs=fopen(FichSr,"r");
fd=fopen(FichDs,"w");
char ligne[80];
int a;
while (!feof(fs))
{
fgets(ligne,80,fs);
ligne[strlen(ligne)-1]='\0';
a=SommeLigne(ligne);
//printf("%s\n",ligne);
//printf("%d\n",a);
fprintf(fd,"%d\n",a);
}
fclose(fs);
fclose(fd);
}
//////////
main()
{
//alea("alea.txt");
//SommeLigneSol1("alea.txt","somme.txt");
//printf("%d",SommeLigne("11 14 5"));
SommeLigneSol2("alea.txt","somme1.txt");
getch();
}
