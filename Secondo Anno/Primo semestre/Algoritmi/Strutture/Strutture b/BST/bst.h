#include <iostream>

// Definizione del tipo di chiave (KEY)
using KEY = int;

// Definizione del nodo del BST
struct NodoBST {
    KEY chiave;
    NodoBST* sinistro;
    NodoBST* destro;

    NodoBST(KEY k) : chiave(k), sinistro(nullptr), destro(nullptr) {}
};

// Definizione del BST
class BST {
private:
    NodoBST* radice;

    // Funzione di supporto per l'inserimento di una chiave nel BST
    NodoBST* inserisciNodo(NodoBST* radice, KEY chiave) {
        if (radice == nullptr) {
            return new NodoBST(chiave);
        }

        if (chiave < radice->chiave) {
            radice->sinistro = inserisciNodo(radice->sinistro, chiave);
        } else if (chiave > radice->chiave) {
            radice->destro = inserisciNodo(radice->destro, chiave);
        }

        return radice;
    }

    // Funzione di supporto per la cancellazione di una chiave nel BST
    NodoBST* cancellaNodo(NodoBST* radice, KEY chiave) {
        if (radice == nullptr) {
            return nullptr;
        }

        if (chiave < radice->chiave) {
            radice->sinistro = cancellaNodo(radice->sinistro, chiave);
        } else if (chiave > radice->chiave) {
            radice->destro = cancellaNodo(radice->destro, chiave);
        } else {
            // Nodo da cancellare trovato
            if (radice->sinistro == nullptr) {
                NodoBST* temp = radice->destro;
                delete radice;
                return temp;
            } else if (radice->destro == nullptr) {
                NodoBST* temp = radice->sinistro;
                delete radice;
                return temp;
            }

            // Nodo con due figli: Trova il successore in-order (minimo nel sottoalbero destro)
            NodoBST* temp = minimo(radice->destro);

            // Copia il valore del successore in-order nel nodo corrente
            radice->chiave = temp->chiave;

            // Cancella il successore in-order
            radice->destro = cancellaNodo(radice->destro, temp->chiave);
        }

        return radice;
    }

    // Funzione di supporto per la ricerca di una chiave nel BST
    NodoBST* cercaNodo(NodoBST* radice, KEY chiave) const {
        if (radice == nullptr || radice->chiave == chiave) {
            return radice;
        }

        if (chiave < radice->chiave) {
            return cercaNodo(radice->sinistro, chiave);
        }

        return cercaNodo(radice->destro, chiave);
    }

    // Funzione di supporto per trovare il nodo con la chiave minima nel BST
    NodoBST* minimo(NodoBST* radice) const {
        NodoBST* corrente = radice;
        while (corrente->sinistro != nullptr) {
            corrente = corrente->sinistro;
        }
        return corrente;
    }

    // Funzione di supporto per trovare il nodo con la chiave massima nel BST
    NodoBST* massimo(NodoBST* radice) const {
        NodoBST* corrente = radice;
        while (corrente->destro != nullptr) {
            corrente = corrente->destro;
        }
        return corrente;
    }

    // Funzione di supporto per trovare il predecessore di un nodo nel BST
    NodoBST* predecessore(NodoBST* radice, NodoBST* nodo) const {
        if (nodo->sinistro != nullptr) {
            return massimo(nodo->sinistro);
        }

        NodoBST* predecessore = nullptr;
        NodoBST* corrente = radice;

        while (corrente != nullptr) {
            if (nodo->chiave > corrente->chiave) {
                predecessore = corrente;
                corrente = corrente->destro;
            } else {
                corrente = corrente->sinistro;
            }
        }

        return predecessore;
    }

    // Funzione di supporto per trovare il successore di un nodo nel BST
    NodoBST* successore(NodoBST* radice, NodoBST* nodo) const {
        if (nodo->destro != nullptr) {
            return minimo(nodo->destro);
        }

        NodoBST* successore = nullptr;
        NodoBST* corrente = radice;

        while (corrente != nullptr) {
            if (nodo->chiave < corrente->chiave) {
                successore = corrente;
                corrente = corrente->sinistro;
            } else {
                corrente = corrente->destro;
            }
        }

        return successore;
    }

public:
    // Costruttore per creare un BST vuoto
    BST() : radice(nullptr) {}

    // Metodo per verificare se il BST è vuoto
    bool empty() const {
        return radice == nullptr;
    }

    // Metodo per inserire una chiave nel BST
    void insert(KEY chiave) {
        radice = inserisciNodo(radice, chiave);
    }

    // Metodo per cancellare una chiave nel BST
    void erase(KEY chiave) {
        radice = cancellaNodo(radice, chiave);
    }

    // Metodo per cercare una chiave nel BST e restituire il nodo corrispondente
    NodoBST* search(KEY chiave) const {
        return cercaNodo(radice, chiave);
    }

    // Metodo per trovare il nodo con la chiave minima nel BST
    NodoBST* minimum() const {
        return minimo(radice);
    }

    // Metodo per trovare il nodo con la chiave massima nel BST
    NodoBST* maximum() const {
        return massimo(radice);
    }

    // Metodo per trovare il predecessore di un nodo nel BST
    NodoBST* predecessor(NodoBST* nodo) const {
        return predecessore(radice, nodo);
    }

    // Metodo per trovare il successore di un nodo nel BST
    NodoBST* successor(NodoBST* nodo) const {
        return successore(radice, nodo);
    }
};

int main() {
    // Esempio di utilizzo del BST
    BST mioBST;

    mioBST
