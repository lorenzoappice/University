#ifndef ALBERO_BINARIO_H
#define ALBERO_BINARIO_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AlberoVuoto : public exception {
public:
    AlberoVuoto() : message_("AlberoVuoto") {}

    AlberoVuoto(const string &message) : message_(message) {}

    const char *what() const throw() { return message_.c_str(); }

private:
    string message_;
};

class NodoNonValido : public exception {
public:
    NodoNonValido() : message_("NodoNonValido") {}

    NodoNonValido(const string &message) : message_(message) {}

    const char *what() const throw() { return message_.c_str(); }

private:
    string message_;
};

class NodoEsiste : public exception {
public:
    NodoEsiste() : message_("NodoEsiste") {}

    NodoEsiste(const string &message) : message_(message) {}

    const char *what() const throw() { return message_.c_str(); }

private:
    string message_;
};

class RadiceEsiste : public exception {
public:
    RadiceEsiste() : message_("RadiceEsiste") {}

    RadiceEsiste(const string &message) : message_(message) {}

    const char *what() const throw() { return message_.c_str(); }

private:
    string message_;
};


template<class T>
class Albero_binario {
    static const int NIL = -1;

public:
    typedef T tipo_elem;
    typedef int nodo;

    struct Cella {
        nodo genitore;
        nodo sx;
        nodo dx;
        tipo_elem etichetta;
    };

    // costruttori e distruttori
    Albero_binario();

    Albero_binario(int dimensione);

    Albero_binario(const Albero_binario<T> &t);

    const Albero_binario<T> &operator=(const Albero_binario<T> &t);

    Albero_binario(Albero_binario<T> &&t);

    const Albero_binario<T> &operator=(Albero_binario<T> &&t);

    ~Albero_binario() = default;

    // operatori
    void crea();

    bool vuoto() const;				//Indica se l'albero � vuoto

    nodo radice() const; 			//Ritorna la radice

    nodo genitore(nodo n) const;	// Ritorna il genitore del nodo passato

    nodo sx(nodo n) const;			//Ritorna il figlio sinistro del nodo passato

    nodo dx(nodo n) const;			//Ritorna il figlio destro del nodo passato

    bool sx_vuoto(nodo n) const;	//Indica se il figlio sinistro � vuoto del nodo passato

    bool dx_vuoto(nodo n) const;	//Indica se il figlio destro � vuoto del nodo passato

    void cancella(nodo n);			//Cancella nodo e il suo sotto albero

    T leggi(nodo n) const;			//leggi nodo indicato

    void ins_radice();				//Inserisce lo spazio per creare la radice

    void ins_sx(nodo n);			//Inserisce sinistro

    void ins_dx(nodo n);			//Inserisce destro

    void scrivi(nodo n, tipo_elem v);//Scrive il valore nel nodo passato

    void print() const;

    int conta_nodi(const nodo n) const; 		//Conta i nodi dell'albero di n

  //  bool is_bst() const;		//Controlla se � un albero binario a ricerca(BST)

    void print_subtree(const nodo & n) const;//Stampa il sottoalbero del nodo compreso

    void previsita(const nodo & n) const;//Stampa il sotto albero in previsita(radice sx  dx)

    void postvisita(const nodo & n) const;//Stampa il sotto albero in postvisita(sx  dx  radice)

    void invisita(const nodo & n) const;//Stampa il sotto albero in invisita(sx radice desto)

protected:
    vector<Cella> spazio;
    int num_nodi;
    nodo nodo_radice;
    nodo nodo_vuoto;

    void controllo_albero_vuoto() const;

    void controllo_nodo(nodo n) const;

 //   bool is_bst(nodo n, tipo_elem min, tipo_elem max) const;

    nodo alloca_nodo();

};


template<class T>
Albero_binario<T>::Albero_binario() {
    spazio = vector<Cella>();
    crea();
}

template<class T>
Albero_binario<T>::Albero_binario(int dimensione) {
    spazio = vector<Cella>(dimensione);
    crea();
}

template<class T>
Albero_binario<T>::Albero_binario(const Albero_binario<T> &t) {
    spazio = t.spazio;
    nodo_radice = t.nodo_radice;
    nodo_vuoto = t.nodo_vuoto;
    num_nodi = t.num_nodi;
}

template<class T>
const Albero_binario<T> &Albero_binario<T>::operator=(const Albero_binario<T> &t) {
    if (this != &t) {
        spazio = t.spazio;
        nodo_radice = t.nodo_radice;
        nodo_vuoto = t.nodo_vuoto;
        num_nodi = t.num_nodi;
    }
    return *this;
}

template<class T>
Albero_binario<T>::Albero_binario(Albero_binario<T> &&t) {
    spazio = t.spazio;
    nodo_radice = t.nodo_radice;
    nodo_vuoto = t.nodo_vuoto;
    num_nodi = t.num_nodi;
}

template<class T>
const Albero_binario<T> &Albero_binario<T>::operator=(Albero_binario<T> &&t) {
    if (this != &t) {
        spazio = t.spazio;
        nodo_radice = t.nodo_radice;
        nodo_vuoto = t.nodo_vuoto;
        num_nodi = t.num_nodi;
    }
    return *this;
}


template<class T>
void Albero_binario<T>::crea() {
    nodo_radice = NIL;
    nodo_vuoto = 0;
    num_nodi = 0;
}

template<class T>
bool Albero_binario<T>::vuoto() const {
    return (num_nodi == 0);
}

template<class T>
void Albero_binario<T>::controllo_albero_vuoto() const {
    if (vuoto()) {
        throw AlberoVuoto();
    }
}

template<class T>
void Albero_binario<T>::controllo_nodo(nodo n) const {
    if (n == NIL) {
        throw NodoNonValido();
    }
}

template<class T>
typename Albero_binario<T>::nodo Albero_binario<T>::alloca_nodo() {
    if (nodo_vuoto + 1 > spazio.size()) {
        spazio.push_back(Cella({NIL, nodo_vuoto + 1, NIL}));
    }

    nodo m = nodo_vuoto;
    nodo_vuoto = spazio[nodo_vuoto].sx;
    num_nodi++;

    spazio[m].sx = NIL;
    spazio[m].dx = NIL;
    spazio[m].genitore = NIL;

    return m;
}


template<class T>
typename Albero_binario<T>::nodo Albero_binario<T>::radice() const {
    controllo_albero_vuoto();

    return (nodo_radice);
}



template<class T>
typename Albero_binario<T>::nodo Albero_binario<T>::genitore(Albero_binario::nodo n) const {
    controllo_albero_vuoto();
    controllo_nodo(n);

    return spazio[n].genitore;
}

template<class T>
typename Albero_binario<T>::nodo Albero_binario<T>::sx(Albero_binario::nodo n) const {
    controllo_albero_vuoto();
    controllo_nodo(n);

    return spazio[n].sx;
}

template<class T>
typename Albero_binario<T>::nodo Albero_binario<T>::dx(Albero_binario::nodo n) const {
    controllo_albero_vuoto();
    controllo_nodo(n);

    return spazio[n].dx;
}

template<class T>
bool Albero_binario<T>::sx_vuoto(Albero_binario::nodo n) const {
    controllo_albero_vuoto();
    controllo_nodo(n);

    return (spazio[n].sx == NIL);
}

template<class T>
bool Albero_binario<T>::dx_vuoto(Albero_binario::nodo n) const {
    controllo_albero_vuoto();
    controllo_nodo(n);

    return (spazio[n].dx == NIL);
}


template<class T>
T Albero_binario<T>::leggi(Albero_binario::nodo n) const {
    controllo_albero_vuoto();
    controllo_nodo(n);

    return (spazio[n].etichetta);
}

template<class T>
void Albero_binario<T>::scrivi(Albero_binario::nodo n, tipo_elem v) {
    controllo_albero_vuoto();
    controllo_nodo(n);

    spazio[n].etichetta = v;
}

template<class T>
void Albero_binario<T>::ins_radice() {
    if (!vuoto()) {
        throw RadiceEsiste();
    }

    nodo_radice = alloca_nodo();
}

template<class T>
void Albero_binario<T>::ins_sx(Albero_binario::nodo n) {
    controllo_albero_vuoto();
    controllo_nodo(n);

    if (!sx_vuoto(n)) {
        throw NodoEsiste();
    }

    nodo m = alloca_nodo();
    spazio[n].sx = m;
    spazio[m].genitore = n;
}

template<class T>
void Albero_binario<T>::ins_dx(Albero_binario::nodo n) {
    controllo_albero_vuoto();
    controllo_nodo(n);

    if (!dx_vuoto(n)) {
        throw NodoEsiste();
    }

    nodo m = alloca_nodo();
    spazio[n].dx = m;
    spazio[m].genitore = n;

}

template<class T>
void Albero_binario<T>::cancella(Albero_binario::nodo n) {
    controllo_albero_vuoto();
    controllo_nodo(n);

    if (!sx_vuoto(n)) {
        cancella(sx(n));
    }
    if (!dx_vuoto(n)) {
        cancella(dx(n));
    }

    if (n == nodo_radice) {
        nodo_radice = NIL;
    } else {
        nodo p = genitore(n);
        if (sx(p) == n) {
            spazio[p].sx = NIL;
        } else {
            spazio[p].dx = NIL;
        }
    }

    spazio[n].sx = nodo_vuoto;
    nodo_vuoto = n;
    num_nodi--;
}

template<class T>
void Albero_binario<T>::print() const {
    if (!vuoto()) {
        print_subtree(radice());
    } else {
        cout << "[]" << endl;
    }
    cout << endl;
}

template<class T>
void Albero_binario<T>::print_subtree(const nodo & n) const {

    cout << "[" << leggi(n) << ", ";
    if (!sx_vuoto(n)) {
        print_subtree(sx(n));
    } else {
        cout << "NULL";
    }
    cout << ", ";
    if (!dx_vuoto(n)) {
        print_subtree(dx(n));
    } else {
        cout << "NULL";
    }
    cout << " ]";
}

template<class T>
void Albero_binario<T>::previsita(const nodo & n) const {

	 cout << leggi(n) << " ";
	    if (!sx_vuoto(n)) {
	        previsita(sx(n));
	    }
	    cout << " ";
	    if (!dx_vuoto(n)) {
	        previsita(dx(n));
	    }
}

template<class T>
int Albero_binario<T>::conta_nodi(const nodo n)const
	{
		int i = 0;
		if (!sx_vuoto(n)) {
			 i += conta_nodi(sx(n));
		}
		i++;
		if (!dx_vuoto(n)) {
			i += conta_nodi(dx(n));
		}
		return i;
	}

template<class T>
void Albero_binario<T>::postvisita(const nodo & n) const {


	    if (!sx_vuoto(n)) {
	        postvisita(sx(n));
	    }
	    cout << " ";
	    if (!dx_vuoto(n)) {
	        postvisita(dx(n));
	    }
		cout << leggi(n) << " ";
}

template<class T>
void Albero_binario<T>::invisita(const nodo & n) const {

	    if (!sx_vuoto(n)) {
	        invisita(sx(n));
	    }
		cout << " " << leggi(n) << " ";
	    if (!dx_vuoto(n)) {
	        invisita(dx(n));
	    }

}



template<class T>
ostream &operator<<(ostream &out, const Albero_binario<T> &t) {
    t.print();
    return out;
}
//TODO: finire la funzione
/*
template<class T>
bool Albero_binario<T>::is_bst() const
{
	if(vuoto())
		return true;
	tipo_elem min;
	nodo n = radice();
	while(!sx_vuoto(n))
		n = sx(n);
	min = leggi(n);

	tipo_elem max;
	 n = radice();
	while(!dx_vuoto(n))
		n = dx(n);
	max = leggi(n);
	return is_bst(n,min,max);
}

template<class T>
bool Albero_binario<T>::is_bst(nodo n, tipo_elem min, tipo_elem max) const
{
	if(sx_vuoto(n) && dx_vuoto(n))
		return true;
	if(!sx_vuoto(n) && leggi(n)< leggi(sx(n)))
		return false;
	if(!dx_vuoto(n) && leggi(n)> leggi(dx(n)))
			return false;
	return(is_bst(sx(n),min,leggi(n)-1) && is_bst(dx(n),leggi(n)+1,max));
}
*/

int conta_foglie_allivello(const nodo &n, int k) const {
    if (n == NIL) {
        return 0;
    }

    if (k == 0) {
        // Se siamo al livello desiderato, verificare se il nodo corrente è una foglia
        if (sx_vuoto(n) && dx_vuoto(n)) {
            return 1; // Il nodo corrente è una foglia al livello k
        } else {
            return 0; // Il nodo corrente non è una foglia al livello k
        }
    } else {
        // Se non siamo ancora al livello desiderato, contare ricorsivamente nelle sottoalberi
        int foglie_sx = conta_foglie_allivello(sx(n), k - 1);
        int foglie_dx = conta_foglie_allivello(dx(n), k - 1);
        return foglie_sx + foglie_dx;
    }
}

#endif //ALBERO_BINARIO_H
