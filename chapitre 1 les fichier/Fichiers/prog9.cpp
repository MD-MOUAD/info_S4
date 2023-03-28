#include<stdio.h>
#include<conio.h>
main()
{
char nomfich[21]= "tableMulti6.txt" ;
int n,i,r ;
char c1,c2;
FILE * sortie ;
sortie=fopen(nomfich,"r") ;
while(!feof(sortie))
{
fscanf(sortie,"%d%c%d%c%d\n",&n,&c1,&i,&c2,&r);
printf("%d%c%d%c%d\n",n,c1,i,c2,r);
}
fclose(sortie);
}
