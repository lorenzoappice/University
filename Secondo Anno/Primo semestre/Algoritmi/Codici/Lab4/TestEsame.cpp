#include "esame.h"
#include <iostream>
#include <string>

int main() {
    string nome;
    int voto;

    cout << "Dimmi il nome dell'esame:" << endl;
    cin >> nome;

    esame mioEsame(nome);

    cout << "Dimmi il voto sostenuto in: " << nome << endl;
    cin >> voto;
    mioEsame.setVoto(voto);

    cout << "nome esame: " << mioEsame.getEsame() << endl;
    cout << "voto conseguito: " << mioEsame.getVoto() << endl;
    cout << "e' stato sostenuto l'esame? " << (mioEsame.isSostenuto()? "Si":"No")<< endl;
    return 0;
}