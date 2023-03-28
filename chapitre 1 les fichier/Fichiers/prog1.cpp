#include<stdio.h>
main()
{
	int i,n;
	printf("Donnez un entier n:");
	scanf("%d",&n);
	for(i=0;i<=10;i++)
	  printf("%d*%d=%d\n",i,n,i*n);
}
