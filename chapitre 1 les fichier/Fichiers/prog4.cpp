#include<stdio.h>
main()
{
	char nomFichier[20];
	FILE *f;
	printf("Donnez le nom de fichier à créer:");
	scanf("%s",nomFichier);
	f=fopen(nomFichier,"w");
}
