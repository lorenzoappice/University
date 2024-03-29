#include <iostream>
#include <string>
// Definizione della classe Nodo con template
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* successivo;
    Nodo(T valore) : dato(valore), successivo(nullptr) {}
};

template <typename T>
class Coda {
private:
    Nodo<T>* testa;
    Nodo<T>* coda;
public:
    Coda() : testa(nullptr), coda(nullptr) {}
    ~Coda() {
        Nodo<T>* corrente = testa;
        Nodo<T>* prossimo = nullptr;
        while (corrente != nullptr) {
            prossimo = corrente->successivo;
            delete corrente;
            corrente = prossimo;
        }
        coda = nullptr;
    }


    void inserisciInCoda(T valore) {
        Nodo<T>* nuovoNodo = new Nodo<T>(valore);
        if (coda == nullptr) {
            testa = nuovoNodo;
            coda = nuovoNodo;
        } else {
            coda->successivo = nuovoNodo;
            coda = nuovoNodo;
        }
    }


    void stampaCoda() const {
        Nodo<T>* corrente = testa;
        while (corrente) {
            std::cout << corrente->dato << " ";
            corrente = corrente->successivo;
        }
    std::cout << std::endl;
}

    void rimuoviElemento(T valore) {
        Nodo<T>* corrente = testa;
        Nodo<T>* precedente = nullptr;
        while (corrente != nullptr && corrente->dato != valore) {
            precedente = corrente;
            corrente = corrente->successivo;
    }
        if (corrente != nullptr) {
            if (precedente != nullptr) {
                precedente->successivo = corrente->successivo;
            }
            else {
                testa = corrente->successivo;
            }
            delete corrente;
        }
    }
    int lunghezza() const {
        int dim = 0;
        Nodo<T>* corrente = testa;
        while (corrente != nullptr) {
            dim++;
            corrente = corrente->successivo;
        }
    return dim;
    }

    Coda CopiaPositivi(const Coda& a) {
        Coda b;
        Nodo<T>* corrente = a.testa;

        while(corrente != nullptr) {
            if(corrente->dato >= 0) {
                b.inserisciInCoda(corrente->dato);
            }
            corrente = corrente->successivo;
        }
        return b;
    }


};
/*Implementare un algoritmo che data una coda di interi ne costruisca un'altra
 * ottenuta dalla prima considerando solo i valori positivi.*/