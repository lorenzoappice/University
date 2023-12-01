#ifndef ESERCITAZIONE_2023_10_13_MATRICE_H
#define ESERCITAZIONE_2023_10_13_MATRICE_H


typedef double tipoElemento;

class matrice {
public:
    matrice(int numeroRighe, int numeroColonne); /* costruttore */

    int getRighe() const;
    int getColonne() const;


    tipoElemento leggiMatrice(int riga, int colonna);
    void scriviMatrice(int riga, int colonna, tipoElemento elementoGenerico);

    void prodottoScalare(double scalare);
    matrice trasposta();
    void prodotto(matrice primaMatrice, matrice secondaMatrice);

    void stampareMatrice();
    void riempireMatrice();

    ~matrice();

private:
    int righe;
    int colonne;
    tipoElemento **elementi;

};


#endif //ESERCITAZIONE_2023_10_13_MATRICE_H