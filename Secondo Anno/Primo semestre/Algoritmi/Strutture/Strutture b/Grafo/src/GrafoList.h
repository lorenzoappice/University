#ifndef GRAFOLIST_H
#define GRAFOLIST_H

#include "Grafo.h"
#include "list_vector.h"

class NodoG{
  public:
    NodoG(int i){
      nodoId = i;
    }
    NodoG(){ // @suppress("Class members should be properly initialized")
    }
    int getId(){ return nodoId; }
    void setId(int id) {nodoId = id;}
  private:
    int nodoId;
};


template<class P>
class InfoArco {
  public:
    P peso;
    NodoG _to;
};


template<class E, class P>
class InfoNodo {
  public:
    E   etichetta;
    bool vuoto;
    List_vector<InfoArco<P>> archi;

    InfoNodo(){
      vuoto = true;
    }

    ~InfoNodo(){
	  }
};



template<class E, class P>
  class GrafoList : public Grafo<E, P, NodoG > {
 public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco_<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
    typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoList(int);
    ~GrafoList();

    bool vuoto() const;
    void insNodo(NodoG&);
    void insArco(Nodo, Nodo, Peso); 	//Inserisci nodo uscita,nodo entrante,peso arco
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);			//Inserisci i 2 nodi(uscente ed entrante) per cancellare arco
    ListaNodi Adiacenti(Nodo) const ;	//Tutti i nodi collegati al nodo passato tramite archi uscenti
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;//Legge valore nodo
    void scriviEtichetta(Nodo, Etichetta);//Scrive valore nodo
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;
    int numNodi(){
      return nodi;
    };
    int numArchi(){
      return archi;
    };


 private:
    InfoNodo<E,P>* matrice;
    int dimensione;
    int nodi;
    int archi;
};


template<class E, class P>
GrafoList<E, P>::GrafoList(int _dimensione){
  dimensione = _dimensione;
  nodi = 0;
  archi = 0;
  matrice = new InfoNodo<E,P>[dimensione];
  for (int i=0; i<dimensione; i++)
    matrice[i].archi.create();
}

template<class E, class P>
GrafoList<E, P>::~GrafoList() {
  delete [] matrice;
}

template<class E, class P>
bool GrafoList<E, P>::vuoto() const {
  return (nodi == 0);
}

template<class E, class P>
void GrafoList<E, P>::insNodo(Nodo& N) {
  int n = 0;
  if (nodi < dimensione){
    while (matrice[n].vuoto == false)
      n++;
    nodi++;
    matrice[n].vuoto = false;
  }
  N.setId(n);
}

template<class E, class P>
void GrafoList<E, P>::insArco(Nodo n1, Nodo n2, P peso) {
  InfoArco<P> I;
  I.peso = peso;
  I._to = n2;
  matrice[n1.getId()].archi.insert(I, matrice[n1.getId()].archi.begin());
//  RENDE IL GRAFO NON ORIENTATO

  InfoArco<P> IA;
    IA.peso = peso;
    IA._to = n1;
    matrice[n2.getId()].archi.insert(IA, matrice[n2.getId()].archi.begin());

  archi++;
}


template<class E, class P>
void GrafoList<E, P>::cancNodo(Nodo n) {
  // ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
  bool canc = true;
  int i;
  for (i=0; i < dimensione && canc; i++)
    if (!matrice[n.getId()].archi.empty())
    {
      canc = false;
    }
  ListaNodi list = list_nodi();
  int pos = list.begin();
  while(!list.end(pos))
  {
	  int pos2 = matrice[list.read(pos)->getId()].archi.begin();
	  while(!matrice[list.read(pos)->getId()].archi.end(pos2))
	  {
		  Nodo nodo = matrice[list.read(pos)->getId()].archi.read(pos2)._to;
		  if( nodo.getId() == n.getId())
		  {
		  	        canc = false;
		  }
		   pos2 = matrice[list.read(pos)->getId()].archi.next(pos2);
	  }

	  pos = list.next(pos);
  }

  if (canc){
    // la lista  matrice[n.getId()].archi è vuota;
    matrice[n.getId()].vuoto = true;
    nodi--;

  }
}

template<class E, class P>
void GrafoList<E, P>::cancArco(Nodo n1, Nodo n2){
	typename List_vector<InfoArco<P>>::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato)
	{
		matrice[n1.getId()].archi.erase(p);
		archi--;
	}
//RENDE GRAFO NON ORIENTATO

	typename List_vector<InfoArco<P>>::position p2;
	p2 = matrice[n2.getId()].archi.begin();
	 trovato = false;
	while (!matrice[n2.getId()].archi.end(p2) && !trovato){
		if (matrice[n2.getId()].archi.read(p2)._to.getId() == n1.getId())
			trovato = true;
		else
				p2 = matrice[n2.getId()].archi.next(p2);
	}
	if (trovato)
		matrice[n2.getId()].archi.erase(p2);


}

template<class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E, P>::Adiacenti(Nodo n) const{
  ListaNodi list;
  typename List_vector<InfoArco<P>>::position p;
	p = matrice[n.getId()].archi.begin();
  while (!matrice[n.getId()].archi.end(p)){
		list.insert(new NodoG(matrice[n.getId()].archi.read(p)._to), list.begin());
	  p = matrice[n.getId()].archi.next(p);
	}
  return list;

}

template<class E, class P>
typename GrafoList<E, P>::ListaNodi GrafoList<E,P>::list_nodi() const {
  ListaNodi list;
  for (int i = 0; i < dimensione; i++)
    if (!matrice[i].vuoto)
      list.insert(new NodoG(i), list.begin());
  return list;
}

template<class E, class P>
E GrafoList<E, P>::leggiEtichetta(Nodo n) const {
  return matrice[n.getId()].etichetta;
}

template<class E, class P>
void GrafoList<E, P>::scriviEtichetta(Nodo n, E etichetta) {
  matrice[n.getId()].etichetta = etichetta;
}

template<class E, class P>
P GrafoList<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	typename List_vector<InfoArco<P> >::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato)
		return matrice[n1.getId()].archi.read(p).peso;
	return p;
}

template<class E, class P>
void GrafoList<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	typename List_vector<InfoArco<P> >::position p;
	p = matrice[n1.getId()].archi.begin();
	bool trovato = false;
	while (!matrice[n1.getId()].archi.end(p) && !trovato){
		if (matrice[n1.getId()].archi.read(p)._to.getId() == n2.getId())
			trovato = true;
		else
				p = matrice[n1.getId()].archi.next(p);
	}
	if (trovato){
		InfoArco<P> I;
		I.peso = peso;
		I._to = n2;
		matrice[n1.getId()].archi.write(I,p);
	}
}

#endif
