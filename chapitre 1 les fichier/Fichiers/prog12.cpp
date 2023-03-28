#include<stdio.h>
#include<conio.h>
main()
{
char nomfich[21]= "tableMulti6.txt" ;
char ligne[100];
FILE * f ;
f=fopen(nomfich,"r") ;
fgets(ligne,3,f);
printf("%s",ligne);
fgets(ligne,3,f);
printf("%s",ligne);
fgets(ligne,3,f);
printf("%s",ligne);
fgets(ligne,3,f);
printf("%s",ligne);
fclose(f);
}
