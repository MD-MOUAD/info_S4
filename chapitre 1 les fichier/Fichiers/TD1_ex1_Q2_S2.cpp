////***** TD1 ******////
/********************Question 2 Solution 2*************************/
#include<stdio.h>
main()
{FILE *f;
int i;
char nomFich[20]="suite.txt";
f=fopen(nomFich,"r");
//tranfert de disque vers la RAM
while (!feof(f))
{

fscanf(f,"%d",&i);
printf("%d",i);
}
}
