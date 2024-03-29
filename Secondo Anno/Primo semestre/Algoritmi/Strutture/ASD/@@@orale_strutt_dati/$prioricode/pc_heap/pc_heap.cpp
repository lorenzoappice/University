

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





#include <iostream.h>
#include <stdlib.h>
#include "pc_heap.h"




//definizione degli operatori



void Prioricoda :: creaprioricoda()
//l'indice i nell'heap corrisponde all'indice i-1
//(perch� in C++ il range degli indici parte da zero)
//il problema si potrebbe aggirare con un overloading
//dell'operatore di indicizzazione  []
//ad esempio ridefinendolo nella classe in questo modo:
/*
tipoelem Lista :: operator[](int p)
	{
   	return lista[p-1];
   }
*/
   {
      //pos i=0;  	//per la specifica
      ultimo=0; //per il C++
   }




Prioricoda :: tipoelem  Prioricoda :: min()
	{
      pos i=1;  		//per la specifica
		return P[i-1]; //per il C++
   }












void Prioricoda :: inserisci(tipoelem a)
//il controllo sull'appartenenza va effettuato attraverso un algoritmo di
// scansione dell'heap opportunamente progettato
//(considerando che l'heap � parzialmente ordinato)
//da sottoporre preliminarmente nel main.
	{
      pos corrente,padre;

   	if(ultimo==H)
      	cout<<"\n La coda � piena!";
      else
      	{

//1� fase
//inserimento nella opportuma locazione

            ultimo++;
            P[ultimo-1]=a;
            corrente=ultimo;

//fase 2:
//aggiustamento degli elementi in base alla priorit�

            if(corrente>1)
            	padre=corrente/2;

            while(corrente>1 && (P[corrente-1]<P[padre-1]))
      		//finch� la priorit� del nodo corrente � maggiore di quella
            //del padre e non si raggiunta la radice
      			{
            		//scambia il contenuto di padre e figlio
            		//(scambio di valore senza variabile di appoggio)
            		P[corrente-1] = P[corrente-1] + P[padre-1];
            		P[padre-1] = P[corrente-1] - P[padre-1];
            		P[corrente-1] = P[corrente-1] - P[padre-1];

            		//risali e ricontrolla
            		corrente=padre;
            		padre=corrente/2;
         		}
         }
   }



























void Prioricoda :: cancellamin()
	{
      pos corrente,figlio, radice=0;
      boolean scambio;

   	if(ultimo==0)
      	cout<<"\n La coda � vuota!";
      else
      	{
//1� fase
//rimozione dell'ultimo elemento (conservandone il valore nella radice)
            P[radice-1]=P[ultimo-1];  //salva il valore dell'ultima foglia in radice
                                  //la quale ha perso di significato
            ultimo--;         //il decremento di ultimo rimuove l'ultima foglia
            corrente=radice;
            scambio=true;
//fase 2:
//aggiustamento degli elementi in base alla priorit�

            while(corrente<=ultimo/2 && scambio)
      		//finch� il nodo corrente non � una foglia oppure  non sia
            //pi� necessario uno scambio con il figlio
      			{
                  //determino la posizione del figlio sinistro del nodo corrente
                  figlio=corrente*2;

                  if(figlio<ultimo) //controllo esistenza di entrambi i figli
                  	if(P[figlio-1]>P[figlio]) //in tal caso individua il minimo
                     	figlio++;

                  if(P[corrente-1]>P[figlio-1])
                  //se la priorit� del nodo corrente � maggiore del figlio
            		//scambia il contenuto di padre e figlio
            		//(scambio di valore senza variabile di appoggio)
                  	{
            				P[corrente-1] = P[corrente-1] + P[figlio-1];
		            		P[figlio-1] = P[corrente-1] - P[figlio-1];
      		      		P[corrente-1] = P[corrente-1] - P[figlio-1];

		            		//risali e ricontrolla
      		      		corrente=figlio;
                     }
                  else //se la priorit� del nodo corrente � minore del figlio
                     //lo scambio non � necessario e la funzione termina qui
                  	scambio=false;
         		}
         }
   }


//Specifica delle interfacce costrutttore e distruttore
Prioricoda :: Prioricoda()
	{
   	creaprioricoda();
   }


//definizione del distruttore
Prioricoda :: ~Prioricoda()
	{}
