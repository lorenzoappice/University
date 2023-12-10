#include <iostream>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* successivo;

    Nodo(T valore) : dato(valore), successivo(nullptr) {}
};

template <typename T>
class Pila {
private:
    Nodo<T>* testa;

public:
    Pila() : testa(nullptr) {}

    ~Pila() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Operatore inPila modificato
    bool inPila(const T& valore) const {
        Nodo<T>* corrente = testa;
        while (corrente != nullptr) {
            if (corrente->dato == valore) {
                return true;
            }
            corrente = corrente->successivo;
        }
        return false;
    }

    void push(const T& valore) {
        if (!inPila(valore)) {
            Nodo<T>* nuovoNodo = new Nodo<T>(valore);
            nuovoNodo->successivo = testa;
            testa = nuovoNodo;
        }
        else {
            std::cout << "Elemento duplicato: " << valore << ". Non aggiunto alla pila." << std::endl;
        }
    }

    T pop() {
        if (!isEmpty()) {
            Nodo<T>* nodoRimosso = testa;
            T valoreRimosso = nodoRimosso->dato;
            testa = testa->successivo;
            delete nodoRimosso;
            return valoreRimosso;
        } else {
            std::cerr << "La pila è vuota. Impossibile eseguire pop()." << std::endl;
            // Ritorno un valore di default per il tipo T in caso di errore
            return T();
        }
    }

    T top() const {
        if (!isEmpty()) {
            return testa->dato;
        } else {
            std::cerr << "La pila è vuota. Impossibile ottenere l'elemento in testa." << std::endl;
            // Ritorno un valore di default per il tipo T in caso di errore
            return T();
        }
    }

    bool isEmpty() const {
        return testa == nullptr;
    }

    int size() const {
        int count = 0;
        Nodo<T>* corrente = testa;
        while (corrente != nullptr) {
            count++;
            corrente = corrente->successivo;
        }
        return count;
    }

    void stampaPila() const {
        Nodo<T>* corrente = testa;
        while (corrente) {
            std::cout << corrente->dato << " ";
            corrente = corrente->successivo;
        }
        std::cout << std::endl;
    }
};

class MultipleStack {
private:
    Pila<int>* pile; // Array di pile
    int n; // Numero di pile

public:
    MultipleStack(int numPile) : n(numPile) {
        pile = new Pila<int>[n];
    }

    ~MultipleStack() {
        delete[] pile;
    }

    void push(int stackIndex, int value) {
        if (stackIndex < 0 || stackIndex >= n) {
            std::cerr << "Invalid stack index" << std::endl;
            return;
        }

        pile[stackIndex].push(value);
    }

    int pop(int stackIndex) {
        if (stackIndex < 0 || stackIndex >= n || pile[stackIndex].isEmpty()) {
            std::cerr << "Invalid stack index or stack is empty" << std::endl;
            return -1; // Return a special value to indicate an error
        }
        return pile[stackIndex].pop();
    }

    bool isEmpty(int stackIndex) const {
        return stackIndex >= 0 && stackIndex < n && pile[stackIndex].isEmpty();
    }

    void stampaPile() const {
        for (int i = 0; i < n; ++i) {
            std::cout << "Pila " << i << ": ";
            pile[i].stampaPila();
        }
    }
};
