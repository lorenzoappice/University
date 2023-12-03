#include <iostream>
#include <string>
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

};