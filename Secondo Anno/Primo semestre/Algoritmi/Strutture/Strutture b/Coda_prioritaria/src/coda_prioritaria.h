#ifndef CODA_PRIORITARIA_H
#define CODA_PRIORITARIA_H

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::exception;
using std::string;
using std::to_string;


class NodoInvalido : public exception {
public:
    NodoInvalido(const string &message) : message_(message) {}

    const char *what() const throw() { return message_.c_str(); }

private:
    string message_;
};

template<class T>
class coda_prioritaria {
public:
    typedef T valore;

    coda_prioritaria() = default;

    coda_prioritaria(const coda_prioritaria<T> &p) = default; //Costruttore copia

    coda_prioritaria<T> &operator=(const coda_prioritaria<T> &p) = default;//Operatore di ugualianza

    coda_prioritaria(coda_prioritaria<T> &&p) = default; //Clona la coda

    coda_prioritaria<T> &operator=(coda_prioritaria<T> &&p) = default; //Operatore di ugualianza per la clonazione

    ~coda_prioritaria() = default;

    void crea();

    void inserisci(valore);

    valore min() const;				//Ritorna il valore minore

    void cancella_min();			//Cancella il valore minore

    int lunghezza() const;

    template<class T1>
    friend std::ostream &operator<<(std::ostream &os, const coda_prioritaria<T1> &pq);

protected:
    vector<valore> heap;

    void fix_up(int i);

    void fix_down(int i);

    int pos_heap_a_pos_vector(int i) const;

    valore leggi(int i) const;

    void scrivi(int i, valore x);

    void scambia(int i, int j);

    int genitore(int i) const;

    bool e_radice(int i) const;

    int radice() const;

    bool figlio_sinistro_esiste(int i) const;

    bool figlio_destro_esiste(int i) const;

    int figlio_sinistro(int i) const;

    int figlio_destro(int i) const;

    int ultima_foglia() const;

    void aggiungi_ultima_foglia(valore x);

    void cancella_ultima_foglia();
};


template<class T>
int coda_prioritaria<T>::lunghezza() const {
    return heap.size();
}

template<class T>
void coda_prioritaria<T>::fix_up(int i) {
    if (e_radice(i)) {
        return;
    }

    int p = genitore(i);
    if (leggi(i) < leggi(p)) {
        scambia(i, p);
        fix_up(p);
    }

}

template<class T>
void coda_prioritaria<T>::fix_down(int i) {
    if (!figlio_sinistro_esiste(i)) {
        return;
    }

    int min_child;
    if (figlio_destro_esiste(i)) {
        min_child = (leggi(figlio_sinistro(i)) < leggi(figlio_destro(i))) ? figlio_sinistro(i) : figlio_destro(i);
    } else {
        min_child = figlio_sinistro(i);
    }
    if (leggi(i) > leggi(min_child)) {
        scambia(i, min_child);
        fix_down(min_child);
    }
}

template<class T>
void coda_prioritaria<T>::inserisci(valore x) {
    aggiungi_ultima_foglia(x);
    fix_up(ultima_foglia());
}

template<class T>
typename coda_prioritaria<T>::valore coda_prioritaria<T>::min() const {
    return leggi(radice());
}

template<class T>
void coda_prioritaria<T>::cancella_min() {
    scambia(radice(), ultima_foglia());
    cancella_ultima_foglia();
    fix_down(radice());
}

template<class T>
void coda_prioritaria<T>::crea() {
    heap = vector<valore>();
}

template<class T>
bool coda_prioritaria<T>::e_radice(int i) const {
    return (i == radice());
}

template<class T>
int coda_prioritaria<T>::radice() const {
    return (1);
}

template<class T>
bool coda_prioritaria<T>::figlio_sinistro_esiste(int i) const {
    return 2 * i <= heap.size();
}

template<class T>
bool coda_prioritaria<T>::figlio_destro_esiste(int i) const {
    return 2 * i + 1 <= heap.size();
}


template<class T>
int coda_prioritaria<T>::pos_heap_a_pos_vector(int i) const {
    return (i - 1);
}

template<class T>
typename coda_prioritaria<T>::valore coda_prioritaria<T>::leggi(int i) const {
    return heap[pos_heap_a_pos_vector(i)];
}

template<class T>
void coda_prioritaria<T>::scrivi(int i, valore x) {
    heap[pos_heap_a_pos_vector(i)] = x;
}

template<class T>
void coda_prioritaria<T>::scambia(int i, int j) {
    valore temp = leggi(i);
    scrivi(i, leggi(j));
    scrivi(j, temp);
}

template<class T>
int coda_prioritaria<T>::genitore(int i) const {
    if (e_radice(i)) {
        throw NodoInvalido(to_string(i));
    }
    return (i / 2);
}

template<class T>
int coda_prioritaria<T>::figlio_sinistro(int i) const {
    if (!figlio_sinistro_esiste(i)) {
        throw NodoInvalido(to_string(i));
    }
    return (2 * i);
}

template<class T>
int coda_prioritaria<T>::figlio_destro(int i) const {
    if (!figlio_destro_esiste(i)) {
        throw NodoInvalido(to_string(i));
    }
    return (2 * i + 1);
}

template<class T>
int coda_prioritaria<T>::ultima_foglia() const {
    return heap.size();
}

template<class T>
void coda_prioritaria<T>::aggiungi_ultima_foglia(valore x) {
    heap.push_back(x);
}

template<class T>
void coda_prioritaria<T>::cancella_ultima_foglia() {
    heap.pop_back();
}

template<class T>
std::ostream &operator<<(std::ostream &os, const coda_prioritaria<T> &pq) {
    int i = 1;
    int j = 1;
    while (i <= pq.heap.size()) {
        os << pq.leggi(i);
        if (i == j) {
            os << std::endl;
            j = 2 * j + 1;
        } else {
            os << " ";
        }
        i++;
    }
    return os;
}

#endif //CODA_PRIORITARIA_H
