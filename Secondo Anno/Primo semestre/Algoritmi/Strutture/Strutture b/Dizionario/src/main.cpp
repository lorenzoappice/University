#include <iostream>
#include <string>

#include "hash_table.h"

using namespace std;

int main(){


    hash_table<string, int> table(10);//10 è il numero dei bucket
    mypair<string, int> pair;
    string k;
    int num;
    k = "numero11";
    num = 11;
    pair.first = k;
    pair.second = num;
    table.inserimento(pair);
    cout << "Inserendo la prima coppia size= " << table.size() << endl;
    cout << "Bucket= " << table.search(k) << "   Numero inserito: " << table.ricerca(k)->second << endl;
    cout << endl;
    table.printKey();
    table.printValue();
    cout << endl;
    table.printPair();
    cout << endl;

    k = "numero26";
    num = 26;
    pair.first = k;
    pair.second  = num;
    table.inserimento(pair);
    cout << "Inserendo la seconda coppia size= " << table.size() << endl;
    cout << "Search= " << table.search(k) << "   Numero inserito: " << table.ricerca(k)->second << endl;

    cout << endl;
    table.printKey();
    table.printValue();
    cout << endl;
    table.printPair();
    cout << endl;

    k = "numero10";
    num = 10;
    pair.first = k;
    pair.second = num;
    table.inserimento(pair);
    cout << "Inserendo la terza coppia size= " << table.size() << endl;
    cout << "Search= " << table.search(k) << "   Numero inserito: " << table.ricerca(k)->second << endl;

    cout << endl;
    table.printKey();
    table.printValue();
    cout << endl;
    table.printPair();
    cout << endl;

    k = "numero10";
    num = 10;
    cout << "Trovato? : " << (table.ricerca(k) != NULL) << endl;
    if (table.ricerca(k) != NULL)
    {
        table.eliminazione(k);
        cout << "Trovato? : " << (table.ricerca(k) != NULL) << endl;
        cout << "Togliendo la prima coppia size= " << table.size() << endl;
        cout << "Search= NULL   Numero inserito: NULL" << endl;
    }

    cout << endl;
    table.printKey();
    table.printValue();
    cout << endl;
    table.printPair();
    cout << endl;

    k = "numero11";
    num = 60;
    table.modifica(k, num);
    cout << "Modificando la prima coppia size= " << table.size() << endl;
    cout << "Search= " << table.search(k) << "   Numero inserito: " << table.ricerca(k)->second << endl;

    cout << endl;
    table.printKey();
    table.printValue();
    cout << endl;
    table.printPair();
    cout << endl;
    //_hash<string> K;

    //cout << (int)K("numero11")%10 << " " << (int)K("numero26")%10 << endl;

    return 0;
}
