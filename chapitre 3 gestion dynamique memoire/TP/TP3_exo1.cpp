////Correction TP3
///Exo1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	char *T[10], *tmp;
	int i;
	for(i=0;i<10;i++)
	{
		//Reservation
		T[i]=(char*)malloc(30);
		scanf("%s",T[i]);
	}
	//Affichage avant
	printf("avant l'inversion:\n");
	for(i=0;i<10;i++)
	 printf("%s\t",T[i]);
	//Inverser le tableau
	for(i=0;i<10/2;i++)
	{
		tmp=T[i];
		T[i]=T[10-i-1];
		T[10-i-1]=tmp;
	}
	///Affichage apres
	printf("\n apres l'inversion:\n");
	for(i=0;i<10;i++)
	 printf("%s\t",T[i]);
	
}
