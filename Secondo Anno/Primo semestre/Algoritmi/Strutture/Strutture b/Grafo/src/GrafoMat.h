#ifndef GRAFOMAT_H
#define GRAFOMAT_H

#include "Grafo.h"

template<class P>
class InfoArco {
  public:
	  P peso;
	  bool vuoto;

	  InfoArco(){
		  vuoto = true;
	  }
};


template<class E, class P>
class InfoNodo {
  public:
	  E   etichetta;
	  bool vuoto;
	  InfoArco<P>* archi;

	  InfoNodo(){ // @suppress("Class members should be properly initialized")
		  vuoto = true;
	  }

	  ~InfoNodo(){
		  if (!vuoto)
			  delete [] archi;
	  }
};


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


template<class E, class P>
class GrafoMat : public Grafo<E, P, NodoG > {
  public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco_<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
		typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoMat(int);
    ~GrafoMat();

    bool vuoto() const;
    void insNodo(NodoG&);
    void insArco(Nodo, Nodo, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);
		//    bool esisteNodo(Nodo);
		//    bool esisteArco(Arco);
    ListaNodi Adiacenti(Nodo) const ;
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;
    void scriviEtichetta(Nodo, Etichetta) ;
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;

	bool findPath(Nodo, Nodo);		//stabilisce se esiste un path dal nodo S al nodo D, e in caso positivo lo stampa a video
	int OutDegree(Nodo);
	int inDegree(Nodo);
	double meanOutDegree();

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
	bool findPath(Nodo, int, bool,Nodo,bool[]);
};


template<class E, class P>
GrafoMat<E, P>::GrafoMat(int _dimensione){					//creazione del grafo con la relativa dimensione 
	dimensione = _dimensione;
	nodi = 0;
	archi = 0;
	matrice = new InfoNodo<E,P>[dimensione];
	for (int i=0; i<dimensione; i++)
		matrice[i].archi = new InfoArco<P>[dimensione];
}

template<class E, class P>
GrafoMat<E, P>::~GrafoMat() {
	delete [] matrice;
}

template<class E, class P>
bool GrafoMat<E, P>::vuoto() const {
	return (nodi == 0);
}

template<class E, class P>
void GrafoMat<E, P>::insNodo(Nodo& N) {
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
void GrafoMat<E, P>::insArco(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
	matrice[n1.getId()].archi[n2.getId()].vuoto = false;
	archi++;
}

template <class E, class P>
int GrafoMat<E, P>:: OutDegree(Nodo n){					//RESTITUISCE IL NUMERO DEGLI ARCHI USCENTI NEL NODO n
	int number = 0;
	for(int i=0; i<dimensione; i++){
		if(!matrice[n.getId()].archi[i].vuoto)
			number++;
	}
	return number;
}

template <class E, class P>
int GrafoMat<E, P>:: inDegree(Nodo n){					//RESTITUISCE IL NUMERO DEGLI ARCHI ENTRANTI NEL NODO n
	int number = 0;
	for(int i=0; i<dimensione; i++){
		if(!matrice[i].vuoto  &&  !matrice[i].archi[n.getId()].vuoto)
			number++;
	}
	return number;
}

template <class E, class P>
double GrafoMat<E, P>:: meanOutDegree(){
	int num;
	double media[numNodi()];
	for(int i=0; i<numNodi(); i++){
		media[i] = 0;
	}

	for(int i=0; i<numNodi(); i++){
	num = 0;
		for(int j=0; j<numNodi(); j++){
			if(!matrice[i].archi[j].vuoto)
				num++;
			media[i] = num / numNodi();
		}
	}

	for(int i=0; i<numNodi(); i++){
		cout<<"La media del numero degli archi uscenti del nodo "<<i+1<<" e': "<<media[i]<<endl;
	}
}

template<class E, class P>
void GrafoMat<E, P>::cancNodo(Nodo n) {
	// ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
	bool canc = true;
	int i;
	for (i=0; i < dimensione && canc; i++)
		if (!matrice[n.getId()].archi[i].vuoto)
			canc = false;
	for (i=0; i < dimensione && canc; i++)
		if (!matrice[i].vuoto && !matrice[i].archi[n.getId()].vuoto)
			canc = false;

	if (canc){
		delete matrice[n.getId()].archi;
		matrice[n.getId()].vuoto = true;
	}
}

template<class E, class P>
void GrafoMat<E, P>::cancArco(Nodo n1, Nodo n2){
	matrice[n1.getId()].archi[n2.getId()].vuoto = true;
	archi--;
}

template<class E, class P>
typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::Adiacenti(Nodo n) const{
	ListaNodi list;

	for (int i = 0; i < dimensione; i++) {
		if (!matrice[n.getId()].archi[i].vuoto) {
			list.insert(new NodoG(i), list.begin());
		}
	}
	return list;
}

template<class E, class P>
typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::list_nodi() const {
	ListaNodi list;
	for (int i = 0; i < dimensione; i++)
		if (!matrice[i].vuoto)
			list.insert(new NodoG(i), list.begin());
	return list;
}

template<class E, class P>
E GrafoMat<E, P>::leggiEtichetta(Nodo n) const {
	return matrice[n.getId()].etichetta;
}

template<class E, class P>
void GrafoMat<E, P>::scriviEtichetta(Nodo n, E etichetta) {
	matrice[n.getId()].etichetta = etichetta;
}

template<class E, class P>
P GrafoMat<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	return matrice[n1.getId()].archi[n2.getId()].peso;
}

template<class E, class P>
void GrafoMat<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
}

template<class E, class P>
bool GrafoMat<E,P>:: findPath(Nodo S, Nodo D){
	bool visitati[dimensione];
	for(int j=0;j<dimensione;j++){
		visitati[j]=false;
	}
	bool trovato=false;
	int id = D.getId();
	visitati[S.getId()]=true;
	for(int i=0; i<dimensione;i++){
		if(!matrice[S.getId()].archi[i].vuoto){
			if(visitati[i]==false){
				visitati[i]=true;
				if(i==id){
					trovato=true;
					cout<<leggiEtichetta(S)<<"-->"<<leggiEtichetta(i)<<endl;
					return trovato;
				}else{
					trovato=findPath(i,id,trovato,S,visitati);
					if(trovato==true){
						cout<<"<--"<<leggiEtichetta(S);
						return trovato;
					}
				}
			}
		}
	}
	return trovato;
}

template<class E, class P>
bool GrafoMat<E,P>:: findPath(Nodo S, int id, bool trovato, Nodo inizio, bool visitati[]){
	for(int i=0; i<dimensione;i++){
		if(!matrice[S.getId()].archi[i].vuoto){
			if(visitati[i]==false){
				visitati[i]=true;
				if(i==id){
					trovato=true;
					cout<<leggiEtichetta(id)<<"<--"<<leggiEtichetta(S);
					return trovato;
				}else{
					trovato=findPath(i,id,trovato,inizio,visitati);
					if(trovato==true){
						cout<<"<--"<<leggiEtichetta(S);
						return trovato;
					}
				}
			}
		}
	}
	return trovato;
}

#endif
