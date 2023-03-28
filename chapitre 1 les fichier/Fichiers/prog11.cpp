#include<stdio.h>
#include<conio.h>
main()
{
char nomfich[21]= "tableMulti6.txt" ;
char ligne[100];
FILE * f ;
f=fopen(nomfich,"r") ;
while(!feof(f))
{
fgets(ligne,80,f);
printf("%s",ligne);
}
fclose(f);
}
