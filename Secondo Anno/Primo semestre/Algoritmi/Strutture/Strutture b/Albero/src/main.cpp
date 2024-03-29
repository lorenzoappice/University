#include <iostream>
#include "Linked_tree.h"
using namespace std;

int main()
{
    Linked_tree<int> T;
    Nodeptr<int> *nodo = new Nodeptr<int>;
    Nodeptr<int> *temp;
    T.insRoot(nodo);
    T.scrivi_nodo(nodo, 5);

    cout << "La radice della foglia: " << T.foglia(nodo) << endl
         << "Valore radice: " << T.leggi_nodo(nodo) << endl;
    T.printchild(nodo);
    T.insFirst(nodo, 4);
    cout << "Primo figlio della radice: " << T.leggi_nodo(T.firstChild(nodo)) << endl;
    T.ins(nodo, 15);
    T.ins(nodo, 6);
    cout << "Figli della radice: ";
    T.printchild(nodo);
    cout << endl;
    temp = nodo->children.lettura(0);
    T.insFirst(temp, 8);
    T.ins(temp, 9);
    Nodeptr<int> *child_n2;
    child_n2 = T.getChild(temp, 1);
    T.insFirst(child_n2, 12);
    T.ins(child_n2, 11);
    T.ins(child_n2, 3);
    Nodeptr<int> *child_n3;
    child_n3 = nodo->children.lettura(nodo->children.size() - 1);
    T.insFirst(child_n3, 21);
    T.ins(child_n3, 20);
    cout << "Radice foglia: " << T.foglia(nodo) << endl;
    cout << "Foglia figlia: " << T.foglia(nodo->children.lettura(0)) << endl;
    temp = nodo->children.lettura(2);
    cout << T.leggi_nodo(temp) << endl;
    cout << "Ultimo fratello?: " << T.lastSibling(temp) << endl;
    cout << endl << "Pre ordine " << endl;
    T.preorder(nodo);
    cout << endl << "Post ordine " << endl;
    T.postorder(nodo);
    cout << endl << "Profondità massima dell'albero";
    int max = T.depth(nodo);
    cout << max << endl;
    T.ins(T.root(),1,75);
    T.preorder(T.root());
}
