#include <iostream>

// Definizione della classe Nodo con template
template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* successivo;

    Nodo(T valore) : dato(valore), successivo(nullptr) {}
};

// Definizione della classe Lista con template
template <typename T>
class Lista {
private:
    Nodo<T>* testa;

public:
    // Costruttore
    Lista() : testa(nullptr) {}
    bool listavuota() const {
        return testa == nullptr;
    }
    tipoelem Leggilista(int posizione, Lista<T> lista) {
        Nodo<T>* corrente = testa;
        int i = 0;
        while (corrente != nullptr && i < posizione) {
            corrente = corrente->successivo;
            i++;
        }
        if (corrente != nullptr) {
            return corrente->dato;
        }
        return 0;
    }



    // Metodo per inserire un elemento in testa alla lista
    void inserisciInTesta(T valore) {
        Nodo<T>* nuovoNodo = new Nodo<T>(valore);
        nuovoNodo->successivo = testa;
        testa = nuovoNodo;
    }
    

    // Metodo per stampare la lista
    void stampaLista() const {
        Nodo<T>* corrente = testa;
        while (corrente) {
            std::cout << corrente->dato << " ";
            corrente = corrente->successivo;
        }
        std::cout << std::endl;
    }

    // Metodo per rimuovere un elemento dalla lista
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
            } else {
                testa = corrente->successivo;
            }
            delete corrente;
        }
    }

    // Distruttore per liberare la memoria
    ~Lista() {
        Nodo<T>* corrente = testa;
        Nodo<T>* prossimo = nullptr;

        while (corrente != nullptr) {
            prossimo = corrente->successivo;
            delete corrente;
            corrente = prossimo;
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

    void inverti() {
        Nodo<T>* corrente = testa;
        Nodo<T>* successivo = nullptr;
        Nodo<T>* precedente = nullptr;

        while (corrente != nullptr) {
            successivo = corrente->successivo;
            corrente->successivo = precedente;
            precedente = corrente;
            corrente = successivo;
        }
        testa = precedente;
    }

    // Restituisce il nodo in posizione index
    Nodo<T>* getNodeAtIndex(int index) const {
        Nodo<T>* current = testa;

        for (int i = 0; i < index && current; ++i) {
            current = current->successivo;
        }
        return current;
    }

    bool isPalindrome() const {
        int lun = lunghezza();
        Nodo<T>* inizio = testa;
        Nodo<T>* fine = getNodeAtIndex(lun - 1);

        for (int i = 0; i < lun / 2; ++i) {
            if (inizio->dato != fine->dato) {
                return false;
            }
            inizio = inizio->successivo;
            fine = getNodeAtIndex(lun - 2 - i);
        }
        return true;
    }
};