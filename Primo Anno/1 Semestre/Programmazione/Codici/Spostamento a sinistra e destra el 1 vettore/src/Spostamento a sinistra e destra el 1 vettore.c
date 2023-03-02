#include <stdio.h>
#include <stdlib.h>
int InputN (int lunghezza);
int* InputVal (int Num[],int cont);
int*  Spostamento(int vettore[],int m);
int* Stampa(int risultato[],int pos);

int main(void) {
	int n=0;
	n=InputN(n);
	int V1[n];
	InputVal(V1,n);
	Spostamento(V1,n);
	Stampa(V1,n);
	return EXIT_SUCCESS;
}









int*  Spostamento(int vettore[],int m){
	int Pos;
	int x;
	int i=0;
	     printf("\nInserisci la direzione (destra=0) || (sinistra=qualsiasi)"); fflush(stdout);
	     scanf("%d", &x);
	     if(x==0)//verso destra
	     {
	    	 Pos=0;
	    	 while(Pos<m)
	    	 {
	    		 i = vettore[Pos+1];
	    		 vettore[Pos+1] = vettore[Pos];
	    		 vettore[Pos]=i;
	    		 Pos=Pos+1;
	    	 }
	     }
	    	 else//verso sinistra
	    	 {
	    		 Pos=m;
	    		 while(Pos>1)
	    		 {
	    			 i = vettore[Pos-1];
	    			 vettore[Pos-1] = vettore[Pos];
	    			 vettore[Pos]=i;
	    			 Pos=Pos-1;
	    		 }
	    	 }
	     return vettore;
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
	int i=0;
	while(i<pos)
	{
		printf("%d",risultato[i]);
		i=i+1;
	}
	return risultato;
}
