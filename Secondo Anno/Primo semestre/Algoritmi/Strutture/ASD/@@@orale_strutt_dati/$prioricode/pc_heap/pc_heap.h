//Universit� degli Studi di Bari
//facolt� di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389


//..............................................................................
//........... REALIZZAZIONE CODA CON PRIORITA' COME ALBERO BINARIO .............
//..........................(realizzazione con Heap)............................
//..............................................................................
/*

Propriet� dell'Heap Prioricoda
****************************************

Sia C una coda con priorit� i cui elementi siano idealmente disposti
in un albero binario B con le propriet� per cui:

	1)	se k � il massimo livello delle foglie, allora B ha esattamente 2^k-1
     	nodi di livello minore di k;

   2)	tutte le sue foglie di livello massimo sono addossate a sinistra;

   3)	ogni nodo contiene un elemento di C che � maggiore di quello del padre.

allora essa pu� essere rappresentata come un vettore H (detto heap)
secondo le seguenti regole costruttive:

	1)	H[1] (primo elemento del vettore) � la radice dell'albero B;

   2)	sia H[i] l'i-esimo nodo di B,
   	allora H[2i] e H[2i+1] rappresentano rispettivamente il
      figlio sinistro ed il figlio destro di H[i];

da cui si deduce che se H ha n elementi, allora non esiste figlio
sinistro (o destro) di H[i] se e solo se 2i>n (o 2i+1 > n ossia 2i > n-1)

*/


#ifndef PC_HEAP_H
#define PC_HEAP_H
#define H 100 			//dimensione del vettore

class Prioricoda
	{
		public:
			typedef bool boolean;
 			typedef int tipoelem;
			typedef int pos;

//Specifica delle interfacce
			void     creaprioricoda();
         void     inserisci(tipoelem);
         tipoelem min();
         void     cancellamin();


//costruttori e distruttori
		   Prioricoda();
		  ~Prioricoda();

 		private:
 			tipoelem P[H];
         pos ultimo;
	};

#endif
