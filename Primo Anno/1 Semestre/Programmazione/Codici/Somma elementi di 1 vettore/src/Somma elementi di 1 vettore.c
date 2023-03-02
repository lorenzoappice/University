#include <stdio.h>
#include <stdlib.h>
int  InputN (int lunghezza);
int* InputVal (int Num[],int cont);
int Somma(int S[],int card);
int main(void)
{
	int n=0;
	n=InputN(n);
	int numeri[n];
	InputVal(numeri,n);
	int Risultato=Somma(numeri,n);
    printf("Somma degli elementi: %d",Risultato);
	return EXIT_SUCCESS;
}





//FUNZIONI

int  InputN (int lunghezza){

	printf("indicami la lunghezza del vettore: \n"); fflush(stdout);
	scanf("%d", &lunghezza);
	return lunghezza;
}


int* InputVal (int Num[],int cont){
	int Posi=0;
	while(Posi<cont)
		{
			printf("indicami il prossimo valore: \n"); fflush(stdout);
			scanf("%d", &Num[Posi]);
			Posi=Posi+1;
		}
	return Num;
}

int Somma(int S[],int card)
{
	int posmax=card;
	int posn=0;
	int somma=0;
	while(posn<posmax)
	{
		somma=somma+S[posn];
		        posn=posn+1;
		}
	return somma;
}
