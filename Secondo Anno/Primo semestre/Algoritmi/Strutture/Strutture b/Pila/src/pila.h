#ifndef PilaPT_H
#define PilaPT_H

#include <iostream>
#include <stdio.h>

using namespace std;

template <class T>
class Pila;

template <class T>
class cella
{
	friend class Pila<T>;
	T e;//elemento di tipo T
	cella<T> *prev;
};

template <class Type>
class Pila
{
public:
	typedef Type tipoelem;
	Pila();
	~Pila();
	void creaPila();
	bool pila_vuota() const;	 //Restituisce vero se la pila è vuota
	tipoelem leggiPila() const;  //Legge il primo elemento da sopra cioè l'ultimo inserito
	void fuoriPila();			 //elimina elemento da sopra
	void inPila(tipoelem);		 //inserisce l'elemento da sopra
	void print();
	int size();					 //dimensione pila
	void sortup();				 //Ordina la pila in ordine decrescente
	void sortdown();			 //Ordine la pila in ordine crescente

private:
	cella<Type> *testa;
};

//Costruttore della pila
template <class Type>
Pila<Type>::Pila()
{
	testa = NULL;
}

//Distruttore della pila
template <class Type>
Pila<Type>::~Pila()
{
	while (!pila_vuota())
		fuoriPila();
};

//Resetta la pila
template <class Type>
void Pila<Type>::creaPila()
{
	testa = NULL;
}

//Indica se la pila è vuota o no. True = vuota
template <class Type>
bool Pila<Type>::pila_vuota() const
{
	return testa == NULL;
}

//Ritorno dell'elemento in cima alla pila,l'ultimo inserito
template <class Type>
Type Pila<Type>::leggiPila() const
{
	return testa->e;
}

//Cancella l'ultimo elemento della pila inserito. Non viene ritornato come output
template <class Type>
void Pila<Type>::fuoriPila()
{
	if (!pila_vuota())
	{
		cella<Type> *temp = testa;
		testa = testa->prev;
		delete temp;
	}
}

//Inserisce l'elemento passato in cima alla pila
template <class Type>
void Pila<Type>::inPila(tipoelem el)
{
	cella<Type> *temp = new cella<Type>();
	temp->e = el;
	temp->prev = testa;
	testa = temp;
}

//Stampa l'intera pila. Se è vuota stampa "Pila vuota"
template <class Type>
void Pila<Type>::print()
{
	if (pila_vuota())
	{
		cout << "Pila vuota";
	}
	else
	{
		cella<Type> *temp = testa;
		while (temp != NULL)
		{
			cout << "  " << temp->e << endl;
			temp = temp->prev;
		}
	}
}

template <class Type>
int Pila<Type>::size()
{
	if (!pila_vuota())
	{
		int i;
		cella<Type> *temp = testa;
		for (i = 0; temp != NULL; i++)
		{
			temp = temp->prev;
		}
		return i;
	}
	return 0;
}

//Ordinamento decrescente (in cima il più grande)
template <class Type>
void Pila<Type>::sortup()
{
	if (!pila_vuota())
	{
		for (int i = 0; i < size() - 1; i++)
		{
			cella<Type> *temp = testa;
			for (int j = 0; j < size() - (1 + i); j++)
			{
				tipoelem elem;
				if (temp->e < temp->prev->e)
				{
					elem = temp->e;
					temp->e = temp->prev->e;
					temp->prev->e = elem;
				}
				temp = temp->prev;
			}
		}
	}
}

//Ordinamento decrescente (più piccolo in cima)
template <class Type>
void Pila<Type>::sortdown()
{
	if (!pila_vuota())
	{
		for (int i = 0; i < size() - 1; i++)
		{
			cella<Type> *temp = testa;
			for (int j = 0; j < size() - (1 + i); j++)
			{
				tipoelem elem;
				if (temp->e > temp->prev->e)
				{
					elem = temp->e;
					temp->e = temp->prev->e;
					temp->prev->e = elem;
				}
				temp = temp->prev;
			}
		}
	}
}

#endif // _PilaVT_H

