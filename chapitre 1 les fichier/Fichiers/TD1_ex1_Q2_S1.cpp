////***** TD1 ******////
/********************Question 2 Solution 1*************************/
#include<stdio.h>
main()
{FILE *f;
int i;
char nomFich[20]="suite.txt";
f=fopen(nomFich,"r");
//tranfert de disque vers la RAM
for(i=1;i<=10;i++)
{

fscanf(f,"%d",&i);
printf("%d",i);
}
}
