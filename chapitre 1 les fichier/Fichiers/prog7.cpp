#include<stdio.h>
main()
{
	FILE *f;
	int a,b;
	f=fopen("test1.txt","r");
	//Transfert de disque vers la RAM
	fscanf(f,"%d",&a);
	fscanf(f,"%d",&b);
	printf("a=%d b=%d",a,b);
}
