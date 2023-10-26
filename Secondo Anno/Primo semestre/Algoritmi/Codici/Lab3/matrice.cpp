#include <iostream>
#include "matrice.h"

int main() {
    matrice m(3,3);
    double scalare = 2.5;
    prodottoScalare(scalare);


    return 0;
}

void prodottoScalare(double scalare) {
    for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++) {
            elementi[i][j] = elementi[i][j] * scalare;
        }
    }
}
matrice trasposta(matrice m) {
   matrice b(); 
   for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++) {
            b.scrivimatrice(j,i,m.leggimatrice(i,j));
        }
    }
    return b;
}

//prodottoscalare (double scalare) che moltiplica ogni elemento della matrice con uno scalare

