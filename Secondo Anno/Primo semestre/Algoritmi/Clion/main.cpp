#include "studente.h"
using namespace std;

int main () {
    studente s;
    char * n;
    char * c;
    int k = 2;
    studente corso [k];
    int mat;
    int e;
    int val = 0;
    for (int i=0;i<k;i++) {
        while (val != 0) {
            cout << "Inserisci il nome dello studente:" << endl;
            cin >> n;
            val = setNome(&s,n);
        }
        while (val != 0) {
            cout << "Inserisci il Cognome dello studente:" << endl;
            cin >> c;
            val = setCognome(&s,c);
        }
        while (val != 0) {
            cout << "inserisci la matricola dello studente:" << endl;
            cin >> mat;
            val = setMatricola(&s,mat);
        }
        while (val !=0) {
            cout << "inserisci l'eta dello studente:" << endl;
            cin >> e;
            val = setEta(&s,e);
        }
        corso[i] = s;
    }
    for (int i=0;i<k;i++) {
        cout << "Nome: " << getNome(&corso[i]) << endl;
        cout << "Cognome: " << getCognome(&corso[i]) << endl;
        cout << "Matricola: " << getMatricola(&corso[i]) << endl;
        cout << "Eta: " << getEta(&corso[i]) << endl;
    }
    return 0;
}