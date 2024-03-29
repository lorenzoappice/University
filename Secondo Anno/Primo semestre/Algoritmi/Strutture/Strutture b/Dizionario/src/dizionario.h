#ifndef _DIZIONARIO_H
#define _DIZIONARIO_H

template <class K, class E>
struct mypair
{
    // data member
    K first;
    E second;

    // methods
    mypair() {}
    mypair(mypair<K, E> &the_pair)
    {
        first = the_pair.first;
        second = the_pair.second;
    }
};

template <class K, class E>
class dizionario
{

public:

    virtual ~dizionario() {}
    virtual void create() = 0;						 	//Creazione dizionario vuoto
    virtual bool empty() const = 0;					 	//Controlla se il dizionario è vuoto e restituisce true se è vuoto
    virtual int size() const = 0;					 	//Riporta il numero di coppie presenti nel dizionario
    virtual mypair<K, E> *ricerca(const K &k) const = 0;//Restituisce la coppia con la chiave
    virtual void inserimento(mypair<K, E> &p) = 0;		//Inserisce la coppia p nel dizionario
    virtual void eliminazione(const K &k) = 0;		 	//Cancella la coppia con la chiave k
    virtual void modifica(const K &k, const E &e) = 0;  //Modifica il valore della coppia con la chiave k in e
};

#endif
