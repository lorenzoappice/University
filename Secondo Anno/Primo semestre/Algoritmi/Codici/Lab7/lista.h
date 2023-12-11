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

    Nodo<T>* getNodeAtIndex(int index) const {
        Nodo<T>* current = testa;

        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }
        return current;
    }

    void clear() {


    }
    int num_elements(int pi,int pf) const {
        Nodo<T>* current = getNodeAtIndex(pi);
        int num_elements=0;
        for(int i = pi; i<pf && current; ++i) {
            current = current -> next ;
            num_elements++;
        }
        return num_elements+1;
    }
    void exchange(int p1,int p2) {
        Nodo<T>* elemp1 = getNodeAtIndex(p1);
        Nodo<T>* elemp2 = getNodeAtIndex(p2);
        T elemento1 = elemp1->dato;
        T elemento2 = elemp2->dato;
        elemp1->dato = elemento2;
        elemp2->dato = elemento1;
    }
    void move_min_max() {
        T min = find_min();
        T max = find_max();
        Nodo<T>* corrente = testa;
        Nodo<T>* precedente = nullptr;
        Nodo<T>* minNode = nullptr;
        Nodo<T>* maxNode = nullptr;

        while (corrente) {
            if (corrente->dato == min) {
                minNode = corrente;
            } else if (corrente->dato == max) {
                maxNode = corrente;
            }
            corrente = corrente->next;
        }
        // Spostamento del minimo all'inizio
        if (minNode && minNode != testa) {
            corrente = testa;
            while (corrente->next != minNode) {
                corrente = corrente->next;
            }
            corrente->next = minNode->next;
            minNode->next = testa;
            testa = minNode;
        }
        // Spostamento del massimo alla fine
        if (maxNode) {
            corrente = testa;
            while (corrente->next) {
                corrente = corrente->next;
            }
            if (maxNode != corrente) {
                precedente->next = maxNode->next;
                corrente->next = maxNode;
                maxNode->next = nullptr;
            }
        }
    }
    T find_min() const {
        Nodo<T>* corrente = testa;
        T min = corrente->dato;
        while (corrente) {
            if (corrente->dato >= min) {
                min = corrente->dato;
            }
            corrente = corrente->next;
        }
        return min;
    }

    T find_max() const {
        Nodo<T>* corrente = testa;
        T max= corrente->dato;
        while (corrente) {
            if (corrente->dato <= max) {
                max = corrente->dato;
            }
            corrente = corrente->next;
        }
        return max;
    }
};
