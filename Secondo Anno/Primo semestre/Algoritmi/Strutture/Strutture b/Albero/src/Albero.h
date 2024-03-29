#ifndef ALBERO_H
#define ALBERO_H
#include <functional>

template<class I, class N>
	class Albero { // @suppress("Class has a virtual method and non-virtual destructor")
 public:
	typedef I item;
	typedef N node;
	
	virtual void create () = 0;
	virtual bool empty () const = 0;
	virtual void insRoot (node) = 0;
	virtual node root () const = 0;
	virtual node parent (node) const = 0;
	virtual bool foglia (node) const = 0;
	virtual node firstChild (node) const = 0;
	virtual bool lastSibling (node) const = 0;
	virtual node nextSibling (node) const = 0;
	virtual void removeSubTree (node) = 0;
	virtual void scrivi_nodo (node, item) = 0;
	virtual item leggi_nodo (node) const = 0;


	virtual void insFirstSubTree (node, Albero<I,N>&) = 0;
	virtual void insSubTree (node, Albero &) = 0;

	void preorder(node);		//Stampa tutto l'albero del nodo a riferiemento prima il padre e poi i figli
	void postorder(node);		//Stampa tutto l'albero del nodo a riferimento prima i figli e poi il padre
	int depth(node);			//Lunghezza albero

};

template<class I, class N>
void Albero<I,N>::preorder(node n)
{
	node c;
	std::cout <<leggi_nodo(n)<<" ";
	if(!foglia(n))
	{
		c=firstChild(n);
		while(!lastSibling(c))
		{
			preorder(c);
			c=nextSibling(c);
		}
		preorder(c);
	}
}

template<class I, class N>
void Albero<I,N>::postorder(node n)
{
	node c;
	if(!foglia(n))
	{
		c=firstChild(n);
		while(!lastSibling(c))
		{
			postorder(c);
			c=nextSibling(c);
		}

		postorder(c);
	}
	std::cout <<leggi_nodo(n)<<" ";

}

template<class I, class N>
int Albero<I,N>::depth(node n)
{
	node v;
	int max;
	int corr;
	if(foglia(n))
	{
		max=0;
		return max;
	}else{
		v=firstChild(n);
		max=depth(v);
		while (!lastSibling(v))
		{
			v=nextSibling(v);
			corr=depth(v);
			if(max<=corr)
			{
				max=corr;
			}
		}
		return max+1;
	}
}

#endif
