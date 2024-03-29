#ifndef CODA_H_
#define CODA_H_
#include <iostream>
using namespace std;


template <class T>
class coda;

template <class T>
class nodo
{
	friend class coda<T>;
	nodo *next;
	T value;
};

template <class T>
class coda
{
public:
	coda();
	~coda();

	bool empty();		  	//Indica se la coda è vuota o no
	int size();			  	//Ritorna quanti elementi sono presenti in coda
	void insert(const T); 	//Inserisce l'elemento passato in coda
	void remove();		  	//Rimuove l'elemento uscente della coda
	void elimina_tutto();	//Pulisce l'intera coda
	T lettura();			//Legge l'elemento uscente della coda
	void print();		  	//Stampa l'intera coda
	void decrescente();		//Riordina la coda dal più grande al più piccolo
	void crescente();	  	//Riordina la coda dal più piccolo al più grande


private:
	nodo<T> *head; // puntatore alla testa
	nodo<T> *tail; // puntatore alla coda
	int length;	   // size
};

//costruttore
template <class T>
coda<T>::coda()
{
	head = tail = NULL;
	length = 0;
}

//distruttore
template <class T>
coda<T>::~coda()
{
	while (!empty())
		remove();
}

//Indica se la coda Ã¨ vuota o no
template <class T>
bool coda<T>::empty()
{
	return (head == NULL);
}

//Ritorna quanti elementi sono presenti in coda
template <class T>
int coda<T>::size()
{
	return length;
}

//Inserisce l'elemento passato in coda
template <class T>
void coda<T>::insert(const T v)
{
	nodo<T> *temp = new nodo<T>();

	temp->value = v;
	if (empty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->next = NULL;
		temp->value = v;
		tail = temp;
	}
	length++;
}

//Rimuove l'elemento uscente della coda
template <class T>
void coda<T>::remove()
{
	nodo<T> *temp = head;
	head = head->next;
	delete temp;
	length--;
}

template <class T>
void coda<T>::elimina_tutto()
{
	while (!empty())
		remove();
}

//Legge l'elemento uscente della coda
template <class T>
T coda<T>::lettura()
{
	return (tail->value);
}

//Stampa l'intera coda
template <class T>
void coda<T>::print()
{
	nodo<T> *temp;
	temp = head;
	cout << "[";
	while (temp != NULL)
	{
		if (temp != head)
			cout << ", " << temp->value;
		else
			cout << temp->value;
		temp = temp->next;
	}
	cout << "]" << endl;
}
//Ordina in ordine decrescente la pila
template <class T>
void coda<T>::decrescente()
{
	nodo<T> *temp;
	T change;
	temp = head;
	for (int i = 0; i < length; i++)
	{
		temp = head;
		for (int j = 0; j < length - (i + 1); j++)
		{
			if (temp->value < temp->next->value)
			{
				change = temp->value;
				temp->value = temp->next->value;
				temp->next->value = change;
			}
			temp = temp->next;
		}
	}
}
//Ordina in ordine crescente la coda
template <class T>
void coda<T>::crescente()
{
	nodo<T> *temp;
	T change;
	temp = head;
	for (int i = 0; i < length; i++)
	{
		temp = head;
		for (int j = 0; j < length - (i + 1); j++)
		{
			if (temp->value > temp->next->value)
			{
				change = temp->value;
				temp->value = temp->next->value;
				temp->next->value = change;
			}
			temp = temp->next;
		}
	}
}

#endif //_QUEUE_
