#include <iostream>
#include "matrice.h"


int main() {
    matrice matriceTest(6, 3);
    matriceTest.riempireMatrice();
    std::cout << "La matrice inserita:\n";
    matriceTest.stampareMatrice();

    double scalareGenerico = 4;
    matriceTest.prodottoScalare(scalareGenerico);
    std::cout << "\nLa matrice calcolata in prodotto scalare con " << scalareGenerico << ":\n";
    matriceTest.stampareMatrice();

    matrice matriceTrasposta = matriceTest.trasposta();
    std::cout << "\nLa matrice trasposta:\n";
    matriceTrasposta.stampareMatrice();

    matrice matriceProdotto(matriceTest.getRighe(), matriceTrasposta.getColonne());
    matriceProdotto.prodotto(matriceTest, matriceTrasposta);
    std::cout << "\nLa matrice prodotto e' la seguente:\n";
    matriceProdotto.stampareMatrice();

    return 0;
}


