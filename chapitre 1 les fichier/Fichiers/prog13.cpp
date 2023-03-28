#include<stdio.h>
#include<conio.h>
main()
{
char nomfich[21]= "tableMulti6.txt" ;
char c;
FILE * f ;
f=fopen(nomfich,"r") ;
while ((c=fgetc(f))!=EOF)
{
printf("%c",c);
}
fclose(f);
}
