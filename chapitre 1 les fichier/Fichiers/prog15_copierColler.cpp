
#include<stdio.h>
//La fonction qui permer de réaliser copier/coller
void copierColler(char FichS[], char FichD[])
{
	FILE * fs; //descripteur de fichier source 
	FILE *fd; //descripteur de fichier destination
	char C;
	fs=fopen(FichS,"r");
	fd=fopen(FichD,"w");
	while ((C=fgetc(fs))!=EOF)
	{
		fprintf(fd,"%c",C);
	}
	fclose(fs);
	fclose(fd);
}
///PP
main()
{
	char fichiersrc[30],fichierdest[30];
	printf("Donnez le nom de fichier source:");
	scanf("%s",fichiersrc);
	printf("Donnez le nom de fichier destination:");
	scanf("%s",fichierdest);
	copierColler(fichiersrc, fichierdest);
	
}
