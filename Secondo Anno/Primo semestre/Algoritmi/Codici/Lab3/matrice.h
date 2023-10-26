#include <iostream>
matrice::matrice(int c, int r);
tipoelem leggimatrice(int i, int j);
void scrivimatrice(int i, int j, tipoelem valore);

class matrice {
    public:
        matrice(int,int); //costruttore
        tipoelem leggimatrice(int,int);
        void scrivimatrice(int,int,tipoelem);
        void prodottoScalare(double scalare);
    private:
        int righe;
        int colonne;
        tipoelem **elementi;

}

//costruttore
matrice::matrice(int c, int r) {
    colonne = c;
    righe = r;
    //allocazione dinamica della matrice
    int i;
    elementi = new tipoelem*[righe];
    for (i=0; i<righe; i++) {
        elementi[i] = new tipoelem[colonne];
    }
    //inizializzazione degli elementi
    for (i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++) {
            elementi[i][j] = i+j;
        }
    }
    //oppure
    /*
        for (i=0; i<righe; i++) {
            for (int j=0; j<colonne; j++) {
                scrivimatrice(i,j,i+j)
            }
        }
    */
}

tipoelem leggimatrice(int i, int j) {
    return elementi[i][j];
}

void scrivimatrice(int i, int j, tipoelem valore) {
    elementi[i][j] = valore;
}

