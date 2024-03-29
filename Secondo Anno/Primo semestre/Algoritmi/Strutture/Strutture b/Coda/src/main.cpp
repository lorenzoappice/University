#include <iostream>
#include "coda.h"
using namespace std;

int main ()
{
    coda<int> co;

    co.insert(1);
    co.insert(2);
    co.insert(3);
    co.insert(4);
    co.insert(5);
    co.insert(6);
    co.print();
    cout << "Dimensione : " << co.size() << endl;
    co.remove();
    co.print();
    cout << "Dimensione : " << co.size() << endl;
    co.insert(15);
    co.print();
    cout << "Dimensione : " << co.size() << endl;
    co.decrescente();
    co.print();
    cout << "Dimensione : " << co.size() << endl;
    co.crescente();
    co.print();
}
