#include<stdio.h>
#include <stdlib.h>
int trovaMaggiore(int vettore[], int n)
{
    int count = 1, tempCount;
    int temp = 0,i = 0,j = 0;
    int maggiore = vettore[0];
    for (i = 0; i < n; i++)
    {
        temp = vettore[i];
        tempCount = 0;
        for (j = 0; j < n; j++)
        {
            if (temp == vettore[j])
                tempCount++;
        }
        if (tempCount > count)
        {
            maggiore = temp;
            count = tempCount;
        }
    }
    return maggiore;
}
int trovaMinore(int vettore[], int n)
{
    int count = 1, tempCount;
    int temp = 0,i = 0,j = 0;
    int minore = vettore[0];
    for (i = 0; i < n; i++)
    {
        temp = vettore[i];
        tempCount = 0;
        for (j = 0; j < n; j++)
        {
            if (temp != vettore[j])
                tempCount++;
        }
if (tempCount > count)
        {
            minore = temp;
            count = tempCount;
        }
    }
    return minore;
}
int *CaricaVettore(int vettore[], int n) {
	int i;
	for (i = 0; i < n; i++){
		printf("Inserisci i valore da inserire nel vettore: "); fflush(stdout);

		scanf("%d", &vettore[i]);
	}

	return vettore;
}

int StampaPlusMin (maggiore, minore){
	printf("Il numero presente piu' volte e': %d \n", maggiore); fflush(stdout);
	printf("Quello meno volte e'%d \n", minore);

}
#define n 15

int main()
{
	int maggiore;
	int minore;
	int vettore [n];
	CaricaVettore(vettore,n);
	maggiore = trovaMaggiore(vettore, n);
	minore = trovaMinore(vettore,n);
	StampaPlusMin(maggiore,minore);

    system("pause");
    return 0;
}
