#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int InputN(int num);
int* IntVal(int V[],int cont);
int main(void) {
	int n=0;
	n=InputN(n);
    int nummax[n];
    IntVal(nummax,n);
    int max=0;
    int posm=0;
            while(posm<n){
            if(max<nummax[posm]){
            max=nummax[posm];
            }
            posm=posm+1;
            }
            printf("Il valore più grande presente e':%d",max);
}

int InputN(int num){
	printf("Indicami la lunghezza del vettore: \n"); fflush(stdout);
	scanf("%d",&num);
	return num;
}

int* IntVal(int V[],int cont){
	int pos=0;
	while(pos<cont)
	{
	printf("Indicami il prossimo valore da inserire: \n"); fflush(stdout);
		scanf("%d",&V[pos]);
		pos=pos+1;
	}
	return V;
}
