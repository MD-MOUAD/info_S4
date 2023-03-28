#include<stdio.h>
main()
{
FILE *f;
char op1,op2;
int i,n,res;
char nomFich[20];
printf("Donnez le nom de fichier a ouvrir:");
scanf("%s",nomFich);
f=fopen(nomFich,"r");
while(!feof(f))
{
fscanf(f,"%d%c%d%c%d\n",&i,&op1,&n,&op2,&res);
printf("%d%c%d%c%d\n",i,op1,n,op2,res);
}
fclose(f);
}
