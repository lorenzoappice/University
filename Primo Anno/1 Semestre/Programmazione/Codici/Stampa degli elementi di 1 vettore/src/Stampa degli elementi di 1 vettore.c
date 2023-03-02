int InputN (int lunghezza);
int* InputVal (int Num[],int cont);
int* Stampa(int risultato[],int pos);
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n=0;
	n=InputN(n);
	int V1[n];
	InputVal(V1,n);
	Stampa(V1,n);
	return EXIT_SUCCESS;
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
int* Stampa(int risultato[],int pos)
{
	int i;
	for(i=0;i<pos;i++)
	{
		printf("%d\n",risultato[i]);
	}
	return risultato;
}

