#include<stdio.h>
main()
{
	char nomFichier[20];
	FILE *f;
	printf("Donnez le nom de fichier � cr�er:");
	scanf("%s",nomFichier);
	f=fopen(nomFichier,"w");
}
