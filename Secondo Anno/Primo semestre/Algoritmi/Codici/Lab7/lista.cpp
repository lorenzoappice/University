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
    //num_elements
    list<int> listap2;
    for (int i; i < 10; i++) {
        listap2.inserisciInTesta(i);
    }
    listap2.stampaLista();
    int num_ele= listap2.num_elements(2,7);
    cout << "il num di elementi da 2 a 7 sono:" << num_ele << endl;
    //exchange
    list<char> p1;
    p1.inserisciInTesta('1');
    p1.inserisciInTesta('2');
    p1.stampaLista();
    p1.exchange(0,1);
    p1.stampaLista();
    //move min e max
    list<int> move;
    move.inserisciInTesta(5);
    move.inserisciInTesta(3);
    move.inserisciInTesta(7);
    move.inserisciInTesta(2);
    move.inserisciInTesta(1);
    move.stampaLista();
    move.move_min_max();
    move.stampaLista();
    return 0;
}