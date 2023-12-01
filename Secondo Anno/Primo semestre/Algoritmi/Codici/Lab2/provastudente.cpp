#include "studente.h"
using namespace std;

int main () {
    studente s;
    string n;  // Utilizzare std::string invece di array di caratteri
    string c;  // Utilizzare std::string invece di array di caratteri
    int k = 2;
    studente corso[k];
    int mat;
    int e;
    int val = 0;
    int i = 0;
    while (i < k) {
        cout << "Inserisci il nome dello studente:" << endl;
        cin >> n;
        setNome(&s, n);

        cout << "Inserisci il Cognome dello studente:" << endl;
        cin >> c;
        setCognome(&s, c);

        cout << "Inserisci la matricola dello studente:" << endl;
        cin >> mat;
        setMatricola(&s, mat);

        cout << "Inserisci l'eta dello studente:" << endl;
        cin >> e;
        setEta(&s, e);
        corso[i] = s;
        i++;
    }

    for (int j = 0; j < k; j++) {
        cout << "Nome: " << getNome(&corso[j]) << endl;
        cout << "Cognome: " << getCognome(&corso[j]) << endl;
        cout << "Matricola: " << getMatricola(&corso[j]) << endl;
        cout << "Eta: " << getEta(&corso[j]) << endl;
    }
    return 0;
}
