#include "coda.h"
using namespace std;

/*Il tipo di dato dequeue (double ended queue) è una sequenza modificabile ad entrambi gli estremi,
 * in cui è possibile inserire un emlemento in testa o inserirlo in fondo, e cancellare un
 * elemento dalla testa o cancellarlo dal fondo. Si fornisca una realizzazione in C++ (operatori con tempo O(1)).*/
int main() {
    // Creazione di una coda di interi
    Coda<int> codaDiInteri;
    // Inserimento di alcuni elementi nella coda
    codaDiInteri.inserisciInCoda(10);
    codaDiInteri.inserisciInCoda(20);
    codaDiInteri.inserisciInCoda(-30);
    // Stampa della coda
    cout << "Coda di interi: ";
    codaDiInteri.stampaCoda();


    Coda<int> codaPositiva = codaDiInteri.CopiaPositivi(codaDiInteri);
    // Stampa della nuova coda
    cout << "Coda di interi positivi: ";
    codaPositiva.stampaCoda();

    // Rimozione di un elemento dalla coda
    codaDiInteri.rimuoviElementoCoda(20);

    // Stampa della coda dopo la rimozione
    cout << "Coda di interi dopo la rimozione: ";
    codaDiInteri.stampaCoda();

    // Calcolo della lunghezza della coda
    std::cout << "Lunghezza della coda: " << codaDiInteri.lunghezza() << std::endl;

    return 0;
}
