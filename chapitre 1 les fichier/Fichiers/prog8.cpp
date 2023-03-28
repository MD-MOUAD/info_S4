#include<stdio.h>
main()
{
	char nomFichier[20];
	FILE *f;
	int a,b,c,i;
	char op1,op2;
	printf("Donnez le nom de fichier à ouvrir:");
	scanf("%s",nomFichier);
	f=fopen(nomFichier,"r");
	for(i=1;i<=10;i++)
		{
			fscanf(f,"%d%c%d%c%d",&a,&op1,&b,&op2,&c);
			printf("%d%c%d%c%d\n",a,op1,b,op2,c);
			
		}
}
