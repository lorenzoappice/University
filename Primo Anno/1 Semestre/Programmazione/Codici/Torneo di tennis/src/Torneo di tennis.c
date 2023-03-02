#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int InputN (int numero);

int main(void) {
    int N;
    int Giocatori[100];
    int Vincitori[100];
    int pos;
    int posv;
    int Vp;
    int turno=0;
    int logaritmo;
    InputN(N);
    printf("%d", N);
    logaritmo = log(N);
    printf("%d", logaritmo);
    while(turno<=logaritmo)
    {
        pos=0;
        posv=0;
        while(pos<N)
        {
            if(Giocatori[pos]>Giocatori[pos+1])
            {
                Vp=pos;
            }
            else
            {
                Vp=pos+1;
                Vincitori[pos]=Giocatori[pos-1];
                posv=posv+1;
                pos=pos+2;
            }
        }
    }
    return EXIT_SUCCESS;
}

int InputN (int numero){
    printf("Indicami il numero dei giocatori (potenza di 2):\n"); fflush(stdout);
    scanf("%d",&numero);

    return numero;
}
