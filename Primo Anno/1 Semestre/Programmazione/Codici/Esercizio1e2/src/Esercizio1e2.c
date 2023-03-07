#include <stdio.h>
#include <stdlib.h>
void StampaValori(int vettore[],int n, int k);
int InputN(int n);
void Divisibile(int a, int b);

int main(void) {
	int N=0;
	int K=0;
	int Val=1;
	N=InputN(N);
	K=InputN(K);
	int *V=calloc(N,sizeof(int));
	int Pos=0;
	while(Pos<N)
	{
		V[Pos]=Val*K;
		Val=Val+1;
		Pos=Pos+1;
	}
	StampaValori(V,N,K);
	Divisibile(N,K);
	system("pause");
	return EXIT_SUCCESS;
}
//FUNZIONI SOTTO!!

void StampaValori(int vettore[],int n, int k)
{
	int pos=0;
	printf("Multipli di %d :",k);
	while(pos<n)
	{
		printf(" %d ",vettore[pos]);
		pos=pos+1;
	}
	return;
}
int InputN(int n)
{
	while (n==0)
	{
	printf("Indicami il valore di N, Poi il valore di K:");fflush(stdout);
    scanf(" %d",&n);
	}
 	return n;
}
void Divisibile(int a, int b)
{
	int r=a;
	while(b<=r)
	{
		r=r-b;
	}
	if(r==0)
	{
		printf("\n Il numero è divisibile");
	}
	else
	{
		printf("\n Il numero non è divisibile");
	}
	return;
}