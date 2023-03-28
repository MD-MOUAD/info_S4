////***** TD1 ******////
/********************Question 1*************************/
#include<stdio.h>
main()
{FILE *f;
int i,n;
char nomFich[20]="suite.txt";
f=fopen(nomFich,"w");
printf("le fichier est bien cree");
//tranfert
for(i=1;i<=10;i++)
fprintf(f,"%d ",i);
fclose(f);
}
