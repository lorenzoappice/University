#include <iostream>
#include "pila.h"
using namespace std;
int main()
{
    Pila<int> p;
    p.inPila(7);
    p.inPila(5);
    p.inPila(3);
    p.inPila(1);
    cout  <<  "testa: " << p.leggiPila() << endl;
    p.print();
    cout << endl;
    p.sortup();
    cout  <<  "Ordine decrescente: "  << endl;
    p.print();
    cout <<endl;
    p.sortdown();
    cout  <<  "Ordine crescente: " << endl;
    p.print();
    cout << endl;
    cout << "dimensione: " << p.size() << endl;
    p.fuoriPila();
    cout  << "\nCancellato primo elemento, testa: "  << p.leggiPila() << endl;
    p.print();
    cout << "dimensione: " << p.size() << endl;


}
