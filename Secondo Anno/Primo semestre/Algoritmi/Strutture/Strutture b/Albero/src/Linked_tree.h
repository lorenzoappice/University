#include "Linked_list.h"
#include "Albero.h"
using namespace std;
template <class I>
class Nodeptr
{
public:
    I item;
    Nodeptr *parent;
    Linked_list<Nodeptr *> children;
};

template <class I>
class Linked_tree : public Albero<I, Nodeptr<I> *>
{

public:
    typedef Nodeptr<I> *Node;
    typedef I tipo;
    typedef typename Linked_list<I>::posizione lista_posizione;

    Linked_tree();  // costruttore
    ~Linked_tree(); // distruttore

    void create();                            // inizializza l'albero
    void insRoot(Node);                       // inserisce il nodo della radice
    Node root() const;                        // return del nodo dell'albero
    Node parent(Node) const;                  // return del genitore del nodo passato
    bool foglia(Node) const;                  // indica se il nodo ши una foglia oppure no (se ha figli o no)
    bool empty() const;                       // indica se l'albero non ha radice, ovvero ├и vuoto
    void scrivi_nodo(Node, tipo);          	  // sovrascrive il nodo passato con il valore passato
    tipo leggi_nodo(Node) const;           	  // legge il valore del nodo passato
    Node firstChild(Node) const;              // ritorna il primo figlio del nodo
    Node getChild(Node, lista_posizione) const; // ritorna il figlio in posizione lista_posizione
    bool lastSibling(Node) const;             // indica se il nodo passato ш l'ultimo dei figli del nodo padre
    Node nextSibling(Node) const;             // ritorna il figlio del padre successivo del nodo passato(il fratello)
    void removeSubTree(Node);                 // cancella l'albero del nodo passato compreso il nodo
    int get_nodes() const;                    // indica il numero totale di nodi dell'albero
    void printchild(Node);                    // stampa tutti i figli di una radice
    int num_children(Node);                   // ritorna il numero di figli di un nodo
    void insFirst(Node n, tipo elem); 		  // inserisce un nuovo figlio in prima posizione al nodo passato
    void ins(Node n, tipo elem);      		  // inserisce un nuovo figlio in ultima posizione al nodo passato
    void ins(Node n, lista_posizione pos, tipo elem);//Inserisce un nuovo figlio in una posizione passata
    void insFirstSubTree(Node, Albero<I, Node> &); // inserisce un albero come primo figlio del nodo passato
    void insSubTree(Node, Albero<I, Node> &);      // inserisce un albero come ultimo figlio del nodo passato
private:
    Node Root;
    int num_nodes;
};

// costruttore dell'albero
template <class I>
Linked_tree<I>::Linked_tree()
{
    num_nodes = 0;
    create();
}

// distruttore dell'albero
template <class I>
Linked_tree<I>::~Linked_tree()
{
    num_nodes = 0;
    delete Root;
    Root = NULL;
}

// inizializza la radice
template <class I>
void Linked_tree<I>::create()
{
    Root = new Nodeptr<I>;
    Root = NULL;
}

// indica se l'albero ш vuoto
template <class I>
bool Linked_tree<I>::empty() const
{
    return Root == NULL;
}

// inserisce il nodo in radice
template <class I>
void Linked_tree<I>::insRoot(Node n)
{
    if (empty())
    {
        Root = n;
        Root->parent = NULL;
        num_nodes = 1;
    }
}

// ritorna la radice dell'albero
template <class I>
typename Linked_tree<I>::Node Linked_tree<I>::root() const
{
    return Root;
}

// ritorna il nodo che ha come figlio il nodo passato
template <class I>
typename Linked_tree<I>::Node Linked_tree<I>::parent(Node n) const
{
    return n->parent;
}

// ritorna se il nodo passato ш una foglia o no
template <class I>
bool Linked_tree<I>::foglia(Node n) const
{
    return n->children.lista_vuota();
}

// inserisce il valore passato come ultimo figlio del nodo passato
template <class I>
void Linked_tree<I>::ins(Node n, tipo elem)
{
    Node child = new Nodeptr<I>;
    child->item = elem;
    child->parent = n;
    n->children.inserimento(child, n->children.size());
    this->num_nodes++;
}

//
template <class I>
void Linked_tree<I>::ins(Node n,lista_posizione pos, tipo elem)
{
    Node child = new Nodeptr<I>;
    child->item = elem;
    child->parent = n;
    n->children.inserimento(child, pos);
    this->num_nodes++;
}

// inserisce il valore passato come primo figlio del nodo passato
template <class I>
void Linked_tree<I>::insFirst(Node n, tipo elem)
{
    Node child = new Nodeptr<I>;
    child->item = elem;
    child->parent = n;
    // child->next_sibling=n->children.read(n->children.begin());
    n->children.inserimento(child, n->children.begin());
    this->num_nodes++;
}

// legge il valore del nodo passato
template <class I>
typename Linked_tree<I>::tipo Linked_tree<I>::leggi_nodo(Node n) const
{
    return n->item;
}

// riscrive il valore del nodo passato
template <class I>
void Linked_tree<I>::scrivi_nodo(Node n, tipo elem)
{
    n->item = elem;
}

// stampa tutti i figli di un nodo. Non stampa i sottoalberi, solo i figli diretti
template <class I>
void Linked_tree<I>::printchild(Node n)
{
    if (!foglia(n))
    {
        lista_posizione pos = n->children.begin();
        cout << "[";
        while (!n->children.ultima_posizione(pos))
        {
            if (!pos == n->children.begin())
            {
                cout << ", " << leggi_nodo(n->children.lettura(pos));
            }
            else
            {
                cout << leggi_nodo(n->children.lettura(pos));
            }
            pos = n->children.next(pos);
        }
        cout << "]";
    }
    else
    {
        cout << "Nothing here! " << endl;
    }
}

// ritorna il nodo del primo figlio del nodo passato
template <class I>
typename Linked_tree<I>::Node Linked_tree<I>::firstChild(Node n) const
{
    return n->children.lettura(n->children.begin());
}

// ritorna il figlio del nodo passato nella posizione passata come parametro
template <class I>
typename Linked_tree<I>::Node Linked_tree<I>::getChild(Node n, lista_posizione pos) const
{
    if (n->children.size() > pos)
    {
        return n->children.lettura(pos);
    }
    return NULL;
}

// indica se il nodo passato ├и l'ultimo dei figli del nodo padre
template <class I>
bool Linked_tree<I>::lastSibling(Node n) const
{
    Node p = parent(n);
    Node n2 = new Nodeptr<I>;
    n2 = p->children.lettura(p->children.size() - 1);
    return n == n2;
}

// ritorna il numero di figli del nodo n
template <class I>
int Linked_tree<I>::num_children(Node n)
{
    int c = 0;
    if (!foglia(n))
    {
        lista_posizione pos = n->children.begin();
        while (!n->children.ultima_posizione(pos))
        {
            c++;
            pos = n->children.next(pos);
        }
    }
    return c;
}

// ritorna il nodo successivo a quello passato
template <class I>
typename Linked_tree<I>::Node Linked_tree<I>::nextSibling(Node n) const
{

    if (!lastSibling(n))
    {
        Node p = parent(n);
        lista_posizione pos = p->children.begin();
        while (!p->children.ultima_posizione(pos))
        {
            if (p->children.lettura(pos) == n)
            {
                return p->children.lettura(p->children.next(pos));
            }
            pos = p->children.next(pos);
        }
    }

        return NULL;

}

// elimina l'albero che ha come radice il nodo passato
template <class I>
void Linked_tree<I>::removeSubTree(Node n)
{
    delete n;
}

// ritorna il numero di nodi presenti nell'albero totale
template <class I>
int Linked_tree<I>::get_nodes() const
{
    return num_nodes;
}

// inserisce un albero come primo figlio del nodo passato
template <class I>
void Linked_tree<I>::insFirstSubTree(Node n, Albero<I, Node> &Albero)
{
    n->children.inserimento(Albero.root(), n->children.begin());
}

// inserisce un albero come ultimo figlio del nodo passato
template <class I>
void Linked_tree<I>::insSubTree(Node n, Albero<I, Node> &Albero)
{
    n->children.inserimento(Albero.root(), n->children.size() - 1);
}
