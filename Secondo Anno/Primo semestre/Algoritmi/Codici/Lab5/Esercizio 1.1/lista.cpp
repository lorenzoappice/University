#include "lista.h"
using namespace std;
int main() {
    Lista<char> listaChar; // Cambiato il tipo di lista a char

    // INSERISCI
    listaChar.inserisciInTesta('A');
    listaChar.inserisciInTesta('B');
    listaChar.inserisciInTesta('C');
    cout << "Lista di caratteri: ";
    listaChar.stampaLista();

    // LUNGHEZZA
    int dim = listaChar.lunghezza();
    cout << "Dimensione: " << dim << endl;

    // INVERTI
    listaChar.inverti();
    cout << "Invertita: ";
    listaChar.stampaLista();

    // PALINDROMA
    if (listaChar.isPalindrome()) {
        cout << "La lista e' un palindromo." << endl;
    } else {
        cout << "La lista non e' un palindromo." << endl;
    }

    // RIMUOVI
    listaChar.rimuoviElemento('A');
    cout << "Lista di caratteri dopo la rimozione: ";
    listaChar.stampaLista();

    return 0;
}



