#include<stdio.h>
main()
{
	char nomFichier[20]="test1.txt";
	FILE *f;
	int a;
	f=fopen(nomFichier,"r");
	while (!feof(f))
		{
			fscanf(f,"%d",&a);
			printf("%d\n",a);
			
		}
}
