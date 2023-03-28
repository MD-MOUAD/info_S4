int nbrFeuille(Btree *A)
{
	
	if (A==NULL)
		return 0;
	if(A->fg==NULL && A->fd==NULL)
		return 1;
	else
	 	return nbrFeuille(A->fg)+nbrFeuille(A->fd);
}
////
int max(int a,int b)
{
	if (a>b)
		return a;
	else
		return b;
}
////
int Hauteur(Btree * A)
{
	if(A==NULL)
		return 0;
	else
		return 1+max(Hauteur(A->fg),Hauteur(A->fd));
}
