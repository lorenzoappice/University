#include <iostream>
#include "coda_prioritaria.h"
using namespace std;

int main() {

	coda_prioritaria<int> coda;
	coda.inserisci(0);
	coda.inserisci(1);
	coda.inserisci(2);
	coda.inserisci(3);
	cout << "Coda:" << endl << coda << endl;
	coda.cancella_min();
	coda.inserisci(11);
	coda.inserisci(5);
	coda.cancella_min();
	cout<< "Coda:" << endl << coda << endl;
	cout << "Lunghezza coda:" << coda.lunghezza()<< endl;
	cout << "Cancella:" << coda.min() << endl;
	cout << "Coda:" << endl << coda << endl;
//	coda_prioritaria<int> ciao(coda);//COSTRUTTORE COPIA CHE APPUNTO COPIA LA CODA

	return 0;
}
