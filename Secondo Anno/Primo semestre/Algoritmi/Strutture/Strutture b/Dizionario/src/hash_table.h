#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include "dizionario.h"

using namespace std;

template <class T>
class _hash
{
public:
    size_t operator()(const T the_key) const;
};
template<>
class _hash<string>
{
public:
    size_t operator()(const string the_key) const
    {
        unsigned long hash_value = 0;
        int length = (int)the_key.length();
        for (int i = 0; i < length; i++)
            hash_value = 5 * hash_value + the_key.at(i);
        return size_t(hash_value);
    }
};

template <>
class _hash<int>
{
public:
    size_t operator()(const int the_key) const
    {
       
        return size_t(the_key);
    }
};

template <class K, class E>
struct mypair;

template <class K, class E>
class hash_table : public dizionario<K, E>
{
public:
   
    hash_table(int); //Costruttore
    bool empty() const
    {
        return (dsize == 0);
    };
    int size() const
    {
        return dsize;
    };
    void eliminazione(const K &k);
    void modifica(const K &k, const E &e);
    void create(){};
    int search(const K &) const;				//Ritorna l'intero (il numero di Bucket)
    mypair<K, E> *ricerca(const K &) const;		//Ritorna la singola coppia del Bucket
    void inserimento(mypair<K, E> &);
    void printValue();
    void printKey();
    void printPair();

private:
    mypair<K, E> **table; // tabella hash
    _hash<K> hashm;       // Associa il tipo K a un numero intero non negativo
    int dsize;            // Numero di coppie del dizionario
    int divisor;          // Divisore di funzione hash
};

template <class K, class E>
hash_table<K, E>::hash_table(int the_divisor)
{
    divisor = the_divisor;
    dsize = 0;

    table = new mypair<K, E> *[divisor];
    for (int i = 0; i < divisor; i++)
        table[i] = NULL;
}

template <class K, class E>
int hash_table<K, E>::search(const K &the_key) const
{
    int i = (int)hashm(the_key) % divisor; // the home bucket
    int j = i;
    do
    {
        if (table[j] == NULL || table[j]->first == the_key)
            return j;
        j = (j + 1) % divisor; // the next bucket
    } while (j != i);

    return j; // La tabella è piena
}

template <class K, class E>
mypair<K, E> *hash_table<K, E>::ricerca(const K &the_key) const
{
    // Cerca nella tabella
    int b = search(the_key);
    // Vedere se è stata trovata una corrispondenza al tavolo b
    if (table[b] == NULL || table[b]->first != the_key)
        return NULL; // nessuna corrispondenza
    return table[b]; // coppia corrispondente
}

template <class K, class E>
void hash_table<K, E>::inserimento(mypair<K, E> &the_pair)
{
    // cerca nella tabella un elemento corrispondente
    int b = search(the_pair.first);
    // controlla se l'elemento corrispondente è stato trovato
    if (table[b] == NULL)
    {
        // nessun elemento corrispondente e tabella non piena
        table[b] = new mypair<K, E>(the_pair);
        dsize++;
    }
    else
    {
        // controlla ID duplicato o tabella piena
        if (table[b]->first == the_pair.first)
            // duplica, cambia tabella[b]->secondo
            table[b]->second = the_pair.second;
    }
}

template <class K, class E>
void hash_table<K, E>::eliminazione(const K &k)
{
    //cerca nella tabella un elemento corrispondente
    int b = search(k);
    //controlla se l'elemento corrispondente è stato trovato
    if (table[b] != NULL && table[b]->first == k)
    {
        // eliminare l'elemento
        table[b] = NULL;
        dsize--;
    }
    return;
}

template <class K, class E>
void hash_table<K, E>::modifica(const K &k, const E &e)
{
    // cerca nella tabella un elemento corrispondente
    int b = search(k);
    // controlla se l'elemento corrispondente è stato trovato
    if (table[b] != NULL && table[b]->first == k)
        // cambia elemento
        table[b]->second = e;
    return;
}

template <class K, class E>
void hash_table<K, E>::printValue()
{
    cout << "Values: ";
    bool x = false;
    cout << "[";
    for (int i = 0; i < divisor; i++)
    {
        if(table[i] != NULL){
            if(x){
                cout << ", ";
            }
            x = true;
            cout << table[i]->second;
        }
    }
    cout << "]" << endl;
    return;
}

template <class K, class E>
void hash_table<K, E>::printKey()
{
    cout << "Keys: ";
    bool x = false;
    cout << "[";
    for (int i = 0; i < divisor; i++)
    {
        if (table[i] != NULL)
        {
            if (x)
            {
                cout << ", ";
            }
            x = true;
            cout << table[i]->first;
        }
    }
    cout << "]" << endl;
    return;
}

template <class K, class E>
void hash_table<K, E>::printPair()
{
    cout << "Pairs:" << endl;
    for (int i = 0; i < divisor; i++)
    {
        if (table[i] != NULL)
        {
            cout << "[" << table[i]->first << ", " << table[i]->second << "]" << endl;
        }
    }
    return;
}

#endif
