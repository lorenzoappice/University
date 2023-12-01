#include <iostream>
#include <iomanip>
#include "matrice.h"

tipoElemento calcolareValoreMatrice(matrice primaMatrice, matrice secondaMatrice, int rigaMatrice, int colonnaMatrice);

int matrice::getRighe() const {
    return righe;
}

int matrice::getColonne() const {
    return colonne;
}

matrice::matrice(int numeroRighe, int numeroColonne) {
    righe = numeroRighe;
    colonne = numeroColonne;
    elementi = new tipoElemento* [righe];
    for(int i = 0; i < righe; i++)
        elementi[i] = new tipoElemento [colonne];
}

matrice::~matrice() {
    for(int i = 0; i < righe; i++)
        delete[] elementi[i];
    delete[] elementi;
}

tipoElemento matrice::leggiMatrice(int riga, int colonna) {
    return elementi[riga][colonna];
}

void matrice::scriviMatrice(int riga, int colonna, tipoElemento elementoGenerico) {
    elementi[riga][colonna] = elementoGenerico;
}

void matrice::prodottoScalare(tipoElemento scalare) {
    for(int i_riga = 0; i_riga < this->getRighe(); i_riga++)
        for(int i_colonna = 0; i_colonna < this->getColonne(); i_colonna++)
            this->scriviMatrice(i_riga, i_colonna, (this->leggiMatrice(i_riga, i_colonna) * scalare));
}

matrice matrice::trasposta() {
    matrice matriceTrasposta(this->getColonne(), this->getRighe());
    for(int i_righe = 0; i_righe < this->getRighe(); i_righe++)
        for (int i_colonne = 0; i_colonne < this->getColonne(); i_colonne++)
            matriceTrasposta.scriviMatrice(i_colonne, i_righe, this->leggiMatrice(i_righe, i_colonne));
    return matriceTrasposta;
}

void matrice::prodotto(matrice primaMatrice, matrice secondaMatrice) {
    if(primaMatrice.getColonne() == secondaMatrice.getRighe()) {
        for(int i_righe = 0; i_righe < this->getRighe(); i_righe++)
            for(int i_colonne = 0; i_colonne < this->getColonne(); i_colonne++)
                this->scriviMatrice(i_righe, i_colonne, calcolareValoreMatrice(primaMatrice, secondaMatrice, i_righe, i_colonne));
    }
}

tipoElemento calcolareValoreMatrice(matrice primaMatrice, matrice secondaMatrice, int rigaMatrice, int colonnaMatrice) {
    tipoElemento valore = 0;
    for(int i_spostamento = 0; i_spostamento < primaMatrice.getColonne(); i_spostamento++)
        valore = valore + (primaMatrice.leggiMatrice(rigaMatrice, i_spostamento) * secondaMatrice.leggiMatrice(i_spostamento, colonnaMatrice));
    return valore;
}

void matrice::stampareMatrice() {
    for(int i_righe = 0; i_righe < this->getRighe(); std::cout << '\n', i_righe++)
        for(int i_colonne = 0; i_colonne < this->getColonne(); i_colonne++)
            std::cout << std::setw(5) /*<< std::setfill('0')*/ << this->leggiMatrice(i_righe, i_colonne) << "  ";
}

void matrice::riempireMatrice() {
    tipoElemento valoreGenerico = 0;
    for(int i_riga = 0; i_riga < this->getRighe(); i_riga++)
        for(int i_colonna = 0; i_colonna < this->getColonne(); this->scriviMatrice(i_riga, i_colonna, valoreGenerico), valoreGenerico++, i_colonna++);
}