#include<stdio.h>
main()
{FILE *f;
int i,n;
char nomFich[20];
printf("Donnez le nom de fichier a creer:");
scanf("%s",nomFich);
f=fopen(nomFich,"w");
printf("le fichier est bien cree");
printf("donnez un entier n");
scanf("%d",&n);
//tranfert
for(i=0;i<=10;i++)
fprintf(f,"%d*%d=%d\n",i,n,i*n);
fclose(f);
}
