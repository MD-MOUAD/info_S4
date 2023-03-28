#include<stdio.h>
main()
{
	char nomFichier[20];
	FILE *f;
	int a,b;
	a=10;
	b=20;
	printf("Donnez le nom de fichier à créer:");
	scanf("%s",nomFichier);
	f=fopen(nomFichier,"w");
	//Transfert
	fprintf(f,"%d %d",a,b);
	fprintf(f,"Bonjour tout le monde");
	//fclose()
}
