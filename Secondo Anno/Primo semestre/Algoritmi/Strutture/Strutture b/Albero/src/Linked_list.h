#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include "Linear_list.h"
using namespace std;

template <class T>
class Linked_list;

template <class T>
class node
{
	public:
		T item;
		node *pred;//nodo precedente
		node *next;//nodo successivo
};


template <class T>
class Linked_list : public Linear_list<T,int>
{
public:
	typedef node<T>* nodeptr;
	typedef T valore;
	typedef int posizione;

	public:
		Linked_list();//costruttore
		~Linked_list(); // distruttore

		void creazione(); 								//Resetta totalmente la lista
		bool lista_vuota() const;						//Restituisce la lista vuota se ш vero
		valore lettura(int index) const;				//Legge l'elemento nella posizione scelta
		void inserimento(const valore &,posizione);		//Inserisce l'elemento passato nella posizione scelta
		void scrittura (const valore &,posizione); 		//Scrive l'elemento nella posizione passata
		posizione begin()const;							//Indica la posizione iniziale della lista
		bool ultima_posizione(posizione index) const;	//Indica la posizione finale della lista
		posizione next(posizione index) const;			//Restituisce la posizione successiva a quella indicata
		posizione precedente(posizione index) const;	//Restituisce la posizione precedente a quella indicata
		void eliminazione(posizione index);				//Cancella l'elemento della posizione indicata
		void elimina_tutto();							//Cancella tutti gli elementi della lista
		void scambia_elementi(posizione, posizione);	//Scambia 2 elementi di due posizioni scelte
		void print();							   		//Stampa la lista
		posizione ricerca(valore);				   	    //Ritorna la posizione dell'elemento indicato nella lista
		void ordinamento_decrescente();					//Riordina la lista dal maggiore al minore
		void ordinamento_crescente();					//Riordina la lista dal minore al maggiore
		posizione ricerca_posizione(const valore);	//Ritorna la posizione dell'elemento passato nella lista
		void cancella_elementi_uguali(Linked_list<T> &);//Cancella dalla lista tutti gli elementi uguali presenti nella lista passata (differenza)
		bool is_in(const valore);			   			//Ritorna se esiste l'elemento passato nella lista

		Linked_list<T> &operator=(const Linked_list<T> &); // operatore di copia
		bool operator==(const Linked_list<T> &) const;	   //verifica due liste per l'uguaglianza
		bool operator!=(const Linked_list<T> &) const;	   //verifica due liste per disuguaglianza

	private:
		nodeptr head;
        nodeptr tail;
		int length;
};

template <class T>
Linked_list<T>::Linked_list()
{
	creazione();
}

// distruttore
template <class T>
Linked_list<T>::~Linked_list()
{
	while (!lista_vuota())
	{
		eliminazione(0);
	}
}

//Indica se la lista ши vuota o no. True = vuota
template <class T>
bool Linked_list<T>::lista_vuota() const
{
	return length==0;
}
// ritorna la posizione dell'elemento passato nella lista
template <class T>
typename Linked_list<T>::posizione Linked_list<T>::ricerca_posizione(valore item)
{
	posizione pos = begin();
	while (!ultima_posizione(pos) && item != lettura(pos))
	{
		pos = next(pos);
	}
	if (item == lettura(pos))
		return pos;

	return NULL;
}


// indica se la posizione passata ш la fine della lista
template <class T>
bool Linked_list<T>::ultima_posizione(posizione pos)const
{
	return pos==length;
}
// Ritorna la posizione iniziale della lista
template <class T>
typename Linked_list<T>::posizione Linked_list<T>::begin() const
{
	return 0;
}

//Resetta la lista reinizializzando testa e coda.
template <class T>
void Linked_list<T>::creazione()
{
	head= new node<T>;
	tail= new node<T>;
	length=0;
    tail=NULL;
}

//Ritorna se esiste l'elemento passato nella lista
template <class T>
bool Linked_list<T>::is_in(const valore a)
{
	if (!lista_vuota())
	{
		posizione p = begin();
		while (!ultima_posizione(p))
		{
			if (lettura(p) == a)
				return true;
			p = next(p);
		}
		return false;
	}
	return false;
}

//Stampa la lista
template <class T>
void Linked_list<T>::print()
{
	if (!lista_vuota())
	{
		posizione p = begin();
		cout << '[';
		while (!ultima_posizione(p))
		{
			if (p != begin())
				cout << ", " << lettura(p);
			else
				cout << lettura(p);
			p = next(p);
		}
		cout << "]" << endl;
	}
}

//Inserisce l'elemento nella posizione indicata
template <class T>
void Linked_list<T>::inserimento(const valore &item ,posizione pos)
{
	nodeptr n = new node<T>;
	n->item=item;
	if (!lista_vuota())
	{
		nodeptr temp= new node<T>;
		temp=head;
		if (pos>=1)
		{
			for (int i=0; i<pos-1; i++)
			{
				temp=temp->next;
			}
			n->pred=temp;
			n->next=temp->next;
			temp->next=n;
		}
		else
		{
			head->pred=n;
			n->next=head;
			head=n;
		}
	}
	else
	{
		head->item=item;
	}
	length++;
}

//Scrive l'elemento nella posizione indicata
template <class T>
void Linked_list<T>::scrittura(const valore &item ,posizione pos)
{
	nodeptr temp= new node<T>;
	temp=head;
	for (int i=0; i<pos; i++)
	{
		temp=temp->next;
	}
	temp->item=item;

}

//Legge l'elemento nella posizione passata
template <class T>
typename Linked_list<T>::valore Linked_list<T>::lettura(int index) const
{
	nodeptr temp= new node<T>;

	int i=0;
	if (i==index)
	{
		return head->item;
	}else{
		temp=head;
		while (i<index)
		{
			temp=temp->next;
			i++;
		}
		return temp->item;
	}
}

// cancella dalla lista tutti gli elementi uguali presenti nella lista passata (differenza)
template <class T>
void Linked_list<T>::cancella_elementi_uguali(Linked_list<T> &L)
{
	if (!lista_vuota())
	{
		posizione p = begin();
		while (!ultima_posizione(p))
		{
			if (L.is_in(lettura(p)))
			{
				eliminazione(p);
			}
			p = next(p);
		}
	}
}

//Ritorna la posizione successiva a quella indicata
template <class T>
typename Linked_list<T>::posizione Linked_list<T>::next(posizione pos) const
{
	return pos+1;
}

//Ritorna la posizione precedente a quella passata
template <class T>
typename Linked_list<T>::posizione Linked_list<T>::precedente(posizione pos) const
{
	return pos-1;
}

// scambia 2 elementi di due posizioni scelte
template <class T>
void Linked_list<T>::scambia_elementi(posizione pos1, posizione pos2)
{
	if (!lista_vuota())
	{
		if (lettura(pos1) == lettura(pos2))
			return;
		valore temp = lettura(pos1);
		scrittura(lettura(pos2), pos1);
		scrittura(temp, pos2);
	}
}



//Elimina l'elemento nella posizione passata
template <class T>
void Linked_list<T>::eliminazione(posizione pos)
{
	if (pos >= 1)
		{
			nodeptr temp = new node<T>;
			temp = head;
			for (int i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = temp->next->next;
			temp->next->pred = temp;
		}
		else
		{
			head=head->next;
		}
		length--;
	}

//Pulisce la lista eliminando tutti gli elementi
template <class T>
void Linked_list<T>::elimina_tutto()
{
	while (!lista_vuota())
		eliminazione(begin());
}

// ritorna la posizione nella lista dell'elemento passato
template <class T>
typename Linked_list<T>::posizione Linked_list<T>::ricerca(valore item)
{
	posizione pos = begin();
	while (ultima_posizione(pos) || item != lettura(pos))
	{
		pos = next(pos);
	}
	if (item == lettura(pos))
		return pos;

	return -1;
}

//Ordinamento da maggiore a minore
template <class T>
void Linked_list<T>::ordinamento_decrescente()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - (i + 1); j++)
		{
			if (lettura(i).size() < lettura(next(i)).size())
			{
				valore s = lettura(i);
				scrittura(lettura(next(i)), i);
				scrittura(s, next(i));
			}
		}
	}
}

//Ordinamento da minore a maggiore
template <class T>
void Linked_list<T>::ordinamento_crescente()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - (i + 1); j++)
		{
			if (lettura(i).size() > lettura(next(i)).size())
			{
				valore s = lettura(i);
				scrittura(lettura(next(i)), i);
				scrittura(s, next(i));
			}
		}
	}
}

//Operatore di copia
template <class T>
Linked_list<T> &Linked_list<T>::operator=(const Linked_list<T> &L)
{
	if (this != &L)
	{
		length = 0;

		head = new node<T>;
		head->next = head;
		head->next = head;

		if (!L.empty())
		{
			posizione p = L.begin();
			for (int i = 0; i < L.size(); i++)
			{
				inserimento(L.lettura(p), this->size());
				p = L.next(p);
			}
		}
	}
	return *this;
}

//Operatore di ugualianza
template <class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const
{
	if (L.size() != length)
		return false;
	posizione p, pL;
	p = begin();
	pL = L.begin();
	while (!ultima_posizione(p))
	{
		if (lettura(p) != L.lettura(p))
			return false;
		p = next(p);
		pL = L.next(p);
	}
	return true;
}

//Operatore di disugualianza
template <class T>
bool Linked_list<T>::operator!=(const Linked_list<T> &L) const
{
	if (L.size() != length)
		return true;
	posizione p, pL;
	p = begin();
	pL = L.begin();
	while (!ultima_posizione(p))
	{
		if (lettura(p) != L.lettura(p))
			return true;
		p = next(p);
		pL = L.next(p);
	}
	return false;
}

#endif //_LIST_H
