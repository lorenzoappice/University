#include <iostream>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* next;

    Nodo(T valore) : dato(valore), next(nullptr) {}

};
template <typename T>
class list {
private:
    Nodo<T> *testa;
public:
    list() : testa(nullptr) {}

    ~list() {
        Nodo<T> *corrente = testa;
        Nodo<T> *prossimo = nullptr;

        while (corrente != nullptr) {
            prossimo = corrente->next;
            delete corrente;
            corrente = prossimo;
        }
    }

    void inserisciInTesta(T valore) {
        Nodo<T>* nuovoNodo = new Nodo<T>(valore);
        nuovoNodo->next = testa;
        testa = nuovoNodo;
    }
    void rimuoviElemento(T valore) {
        Nodo<T>* corrente = testa;
        Nodo<T>* precedente = nullptr;

        while (corrente != nullptr && corrente->dato != valore) {
            precedente = corrente;
            corrente = corrente->next;
        }

        if (corrente != nullptr) {
            if (precedente != nullptr) {
                precedente->next = corrente->next;
            } else {
                testa = corrente->next;
            }
            delete corrente;
        }
    }

    void stampaLista() const {
        Nodo<T>* corrente = testa;
        while (corrente) {
            std::cout << corrente->dato << " ";
            corrente = corrente->next;
        }
        std::cout << std::endl;
    }

    bool operator!=(const list &secondaLista) const {
        Nodo<T> *corrente1 = testa;
        Nodo<T> *corrente2 = secondaLista.testa;

        while (corrente1 != nullptr && corrente2 != nullptr) {
            if (corrente1->dato != corrente2->dato) {
                return true;  // Le liste sono diverse
            }
            corrente1 = corrente1->next;
            corrente2 = corrente2->next;
        }
        // Se una lista è più lunga dell'altra, sono diverse
        return corrente1 != corrente2;
    }
};
