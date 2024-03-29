#include <iostream>

#include "Albero_binario.h"
using namespace std;

int main() {
	Albero_binario<int> albero;
	Albero_binario<int>::nodo nodo;

	albero.crea();
	albero.ins_radice();
	albero.scrivi(albero.radice(), 1);
	albero.ins_dx(albero.radice());
	albero.scrivi(albero.dx(albero.radice()),2);
	nodo = albero.dx(albero.radice());
	albero.ins_sx(nodo);
	albero.scrivi(albero.sx(nodo),4);
	albero.print();
	cout << endl;
	nodo= albero.radice();
	albero.previsita(nodo);
	cout << endl;
	albero.postvisita(nodo);
	cout << endl;
	albero.invisita(nodo);
	cout << endl;
	albero.print_subtree(albero.dx(nodo));
	return 0;
}
