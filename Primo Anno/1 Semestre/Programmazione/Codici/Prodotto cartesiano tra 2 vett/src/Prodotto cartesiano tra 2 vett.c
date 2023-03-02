#include <stdio.h>
#include <stdlib.h>
int Inputcard (int num);
int* Inputval(int vettore[],int card);
int main(void) {
	int n=0;
	n= Inputcard(n);
	int i1[n];
	Inputval(i1,n);
	int m=0;
	m= Inputcard(m);
	int i2[m];
	Inputval(i2,m);


int pc[n*m];

int PC=0;
int I1=0;

while (I1<5){

	int I2=0;

	while (I2<5){

	pc[PC]= i1[I1];
	PC=PC+1;

	pc[PC]=i2[I2];
	I2=I2+1;

	PC=PC+1;

	}
	I1=I1+1;
}

PC=0;

while (PC<n*m){
printf ("%d ",pc[PC]);fflush(stdout);
PC=PC+1;
}
}

int Inputcard (int num){
	printf("Indicami la cardinalità");fflush(stdout);
	scanf("%d",&num);
	return num;
}
int* Inputval(int vettore[],int card){
	int pos=0;
	while(pos<card)
	{
	printf("Indicami il valore num: %d",pos);fflush(stdout);
	scanf("%d",&vettore[pos]);
	pos=pos+1;
	}
	return vettore;
}
