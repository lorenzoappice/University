#include "pila.h"
int main() {
    // Creiamo una istanza di MultipleStack con 3 pile
    MultipleStack multipleStack(3);

    // Testiamo l'inserimento (push) in una pila
    multipleStack.push(0, 10);
    multipleStack.push(0, 5);
    multipleStack.push(0, 8);
    multipleStack.push(1, 20);
    multipleStack.push(1, 2);
    multipleStack.push(1, 5);
    multipleStack.push(2, 30);
    multipleStack.push(2, 40);
    multipleStack.push(2, 50);

    // Testiamo la rimozione (pop) da una pila
    std::cout << "Pop from stack 0: " << multipleStack.pop(0) << std::endl;
    std::cout << "Pop from stack 1: " << multipleStack.pop(1) << std::endl;
    std::cout << "Pop from stack 2: " << multipleStack.pop(2) << std::endl;

    // Verifichiamo se una pila è vuota
    std::cout << "Is stack 0 empty? " << (multipleStack.isEmpty(0) ? "Yes" : "No") << std::endl;

    // Stampiamo lo stato delle pile
    multipleStack.stampaPile();

    return 0;
}