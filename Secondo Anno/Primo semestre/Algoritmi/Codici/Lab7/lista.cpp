#include "lista.h"
using namespace std;
int main() {
    // prima parte
    list<char> Lista1;
    list<char> Lista2;
    Lista1.inserisciInTesta('A');
    Lista2.inserisciInTesta('A');
    if (Lista1 != Lista2) {
        cout << "La lista e' diversa" <<endl;
    }
    else {
        cout << "La lista e' uguale" <<endl;
    }
    //seconda parte

    return 0;
}