#ifndef _LISTALIN_H
#define _LISTALIN_H

#include <iostream>
#include <ostream>

using std::cout;
using std::endl;
using std::ostream;

//classe astratta listaLineare
template< class T, class P >
class Linear_list // @suppress("Class has a virtual method and non-virtual destructor")
{
 public:
	typedef T valore;
	typedef P posizione;

	// operazioni
	virtual void creazione() = 0;
	virtual bool lista_vuota() const = 0; // Ritorna vero se la lista è vuota
	virtual valore lettura(posizione) const = 0;
	virtual void scrittura(const valore& x, posizione p) = 0; // Scrive un elemento in una posizione
	virtual posizione begin() const = 0;  //Punta all'inizione dell'elenco restituendo la posizione
	virtual bool ultima_posizione(posizione) const = 0; // Punta alla fine dell'elenco restituendo la posizione dell'ultimo elemento
	virtual posizione next(posizione) const = 0; // Restituisce la posizione successiva
	virtual posizione precedente(posizione) const = 0; // Restituisce la posizione precedente
	virtual void inserimento(const valore&, posizione) = 0; // Inserisce un elemento in una posizione
	virtual void eliminazione(posizione pos) = 0; // Elimina un elemento in una posizione precisa

// funzioni di servizio
	template <typename T1, typename P1>
	friend ostream &operator<<(ostream &, const Linear_list<T1, P1> &);

// Altre funzioni di servizio implementabili

// ritorna la dimensione della lista
    int size() const
    {
      posizione p = begin();
      int c = 0;
      while (!ultima_posizione(p))
      {
    	  c++;
    	  p = next(p);
      }
      return c;
    }

// Elimina tutti gli elementi della lista
	virtual void clear(){
      while(!lista_vuota())
        eliminazione(begin());
    }
};

// Sovraccaricamento della lista
template< class T, class P >
ostream &operator<<(ostream &os, const Linear_list<T,P> &l)
{
	typename Linear_list<T,P>::posizione p;
	p = l.begin();
	os << "[";
	while (!l.ultima_posizione(p)){
		if (p != l.begin())
			os << ", " << l.lettura(p);
		else
			os << l.lettura(p);
		p = l.next(p);
	}
	os << "]" << endl;
	return os;
}

#endif // _LISTALIN_H
