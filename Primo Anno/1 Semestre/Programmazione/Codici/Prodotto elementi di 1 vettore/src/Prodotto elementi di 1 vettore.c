#include <stdio.h>
#include <stdlib.h>
int* InputVal (int Num[],int Posi);
int  InputN (int lunghezza);
int Prodotto(int V1[],int dim);
int main(void) {
	int N=0;
	N=InputN(N);
	int Vettore[N];
	InputVal(Vettore,N);
	int Risultato=Prodotto(Vettore,N);
	printf("Prodotto di tutti gli elementi presenti: %d", Risultato);
	return EXIT_SUCCESS;
}







//FUNZIONI

int Prodotto(int V1[],int dim){
	int Pos=0;
	int Prodotto=1;
	while(Pos< dim)
	{
		Prodotto = Prodotto * V1[Pos];
		Pos=Pos+1;
	}
	return Prodotto;
}



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
