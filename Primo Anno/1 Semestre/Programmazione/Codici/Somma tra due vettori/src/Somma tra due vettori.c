#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int lunghezza(int n1);
int* RiempioV (int vettore1[], int c1);
int* Stampa(int risultato[],int pos);

int main(void) {
	int n=0;//cardinalità v1
	int m=0;//cardinalità v2
	int V1[n]; //v1 da sommare
	int V2[m]; //v2 da sommare
    n=lunghezza(n);
    m=lunghezza(m);
    RiempioV(V1,n);
    RiempioV(V2,m);
	int Pos=0;
	if (n<m)
	{
		int VS[n];
		while (Pos < n)
		{
			VS[Pos]=V1[Pos]+V2[Pos];
			Pos=Pos+1;
		}
		 Stampa(VS,n);
	}
	else
	{
		int VS[m];
		while (Pos < m)
		{
			VS[Pos]=V1[Pos]+V2[Pos];
			Pos=Pos+1;
		}
		 Stampa(VS,m);
	}
	return EXIT_SUCCESS;
}



//FUNZIONI

int lunghezza(int n1){
     printf("Indicami la cardinalità del Vettore: \n"); fflush (stdout);
      scanf("%d",&n1);
	return n1;
}
int* RiempioV(int vettore1[],int c1){
    int pos=0;
    while(pos<c1)
    {
    	printf("Indicami il valore numero: %d \n",pos); fflush(stdout);
    	scanf("%d",&vettore1[pos]);
    	pos=pos+1;
    }
	return vettore1;
}

int* Stampa(int risultato[],int pos)
{
	int i;
	for(i=0;i<pos;i++)
	{
		printf("%d\n",risultato[i]);
	}
	return risultato;
}
