#include<stdio.h>
main()
{
	char nomFichier[20];
	FILE *f;
	int n,i;
	printf("Donnez un entier n:");
	scanf("%d",&n);
	printf("Donnez le nom de fichier à créer:");
	scanf("%s",nomFichier);
	f=fopen(nomFichier,"w");
	//Transfert
	for(i=1;i<=10;i++)
		fprintf(f,"%d*%d=%d\n",i,n,i*n);
}
