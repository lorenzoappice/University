#include <stdio.h>
#include <stdlib.h>
int InputN (int lunghezza);
int* InputVal (int Num[],int cont);
int* Stampa(int risultato[],int pos);
int*  RicercaCanc(int vettore[],int m);
int main(void)
{
	int n=0;
	n=InputN(n);
	int V1[n];
	InputVal(V1,n);
	RicercaCanc(V1,n);
	return 0;
}





//Funzione input lunghezza vettore
int  InputN (int lunghezza){

	printf("indicami la lunghezza del vettore: \n"); fflush(stdout);
	scanf("%d", &lunghezza);
	return lunghezza;
}
//Funzione input valori vettori
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
//Funzione stampa vettori
int* Stampa(int risultato[],int pos)
{
	int i=0;
    printf("\nVettore con gli elementi eliminati: ");
            while(i<pos)
            {
                printf("%d ", risultato[i]);
                i=i+1;
            }
	return risultato;
}
//Funzione ricerca e cancellazione (spostamento) degli elementi del vettore
int*  RicercaCanc(int vettore[],int m){
	int Pos=0;
	int x;
	     printf("\ninserisci un numero da eliminare nell'array:"); fflush(stdout);
	     scanf("%d", &x);
	     while(Pos<m)
	     {
	    	 if(x==vettore[Pos])
	    	 {
	    		 int i=Pos;
	    		 while(i<m-1)
	    		 {
	    			 vettore[i] = vettore[i + 1];
	    			 i=i+1;
	    		 }
	    		         //diminuisco dim array
	    		         m=m-1;
	    		         Stampa(vettore,m);
	    	 }
	    	 else
	    	 {
	          Pos=Pos+1;
	          printf("\nelemento non trovato");
	    	 }
	     }
	     return 0;
}
