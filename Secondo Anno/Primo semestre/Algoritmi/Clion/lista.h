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
        Nodo<T>* corrente = testa;
        Nodo<T>* prossimo = nullptr;
        while (corrente) {
            prossimo = corrente->next;
            delete corrente;
            corrente = prossimo;
        }
        testa = nullptr;
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


    void toglicomune(list &secondaLista) {
        Nodo<T> *corrente1 = testa;
        Nodo<T> *precedente1 = nullptr;
        Nodo<T> *corrente2 = secondaLista.testa;
        Nodo<T> *successivo1 = nullptr;

        while (corrente1 && corrente2) {
            successivo1 = corrente1->next;
            if (corrente1->dato == corrente2->dato) {
                // Elemento comune trovato, rimuovilo dalla lista
                if (precedente1) {
                    precedente1->next = successivo1;
                    delete corrente1;
                    corrente1 = successivo1;
                } else {
                    // Elemento comune è in testa, aggiorna la testa
                    testa = successivo1;
                    delete corrente1;
                    corrente1 = successivo1;
                }
            } else {
                precedente1 = corrente1;
                corrente1 = successivo1;
            }
            // Avanza nella seconda lista solo se non c'è stato un match
            if (corrente1 && corrente1->dato != corrente2->dato) {
                corrente2 = corrente2->next;
            }
        }
    }
    void insertionSort() {
        if (!testa || !testa->next) {
            // La lista è vuota o contiene un solo elemento, già ordinata
            return;
        }

        Nodo<T>* corrente = testa->next;

        while (corrente) {
            Nodo<T>* successivo = corrente->next;

            // Trova la posizione corretta all'interno della lista ordinata
            Nodo<T>* temp = testa;
            Nodo<T>* precedente = nullptr;

            while (temp != corrente && corrente->dato > temp->dato) {
                precedente = temp;
                temp = temp->next;
            }

            // Se la posizione corretta è diversa dalla posizione corrente
            if (precedente != corrente) {
                // Scambia i dati tra i nodi
                T tempDato = corrente->dato;
                corrente->dato = precedente->dato;
                precedente->dato = tempDato;
            }

            corrente = successivo;
        }
    }

};
