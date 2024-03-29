//Universit� degli Studi di Bari
//facolt� di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389





//..............................................................................
//........... REALIZZAZIONE CODA CON PRIORITA' COME ALBERO BINARIO .............
//......................(realizzazione con puntatori)...........................
//..............................................................................



/*

Propriet� dell'albero binario Prioricoda
****************************************

Sia C una coda con priorit� i cui elementi
siano memorizzati in un albero bianario B, allora:

	1)	se k � il massimo livello delle foglie, allora B ha esattamente 2^k-1
     	nodi di livello minore di k;

   2)	tutte le sue foglie di livello massimo sono addossate a sinistra;

   3)	ogni nodo contiene un elemento di C che � maggiore di quello del padre.

*/




#include <stdlib.h>
#include <iostream.h>
#include "prioricoda.h"




//definizione degli operatori




void Prioricoda :: creaprioricoda()
   {
      P=NULL;
      ultimo=NULL;
   }




Prioricoda :: tipoelem  Prioricoda :: min()
	{
		return P->priority;
   }







void Prioricoda :: inserisci(tipoelem a)
	{
    	nodo temp;
      nodo newNodo;
		newNodo=new nodoBin;
   	newNodo->priority=a;
      newNodo->sinistro=NULL;
      newNodo->destro=NULL;

//fase 1: modifica della struttura
      if(P==NULL) //l'albero � vuoto
         P=newNodo; //inserisci l'elemento come radice
      else
    	 {
	    	if(ultimo==P) //l'albero ha solo la radice
          	{
     	  			P->sinistro=newNodo; //inserisci l'elemento come figlio sinistro
        	      newNodo->padre=P;
           	}
        	else
           	{
 					if(ultimo->padre->sinistro==ultimo)
                //se ultimo � un figlio sinistro allora
     					{  //inserisci l'elemento come suo fratello destro
                     ultimo->padre->destro=newNodo;
                     newNodo->padre=ultimo->padre;
                  }
           		else //altrimenti restano due casi da esaminare, allora
           			{
                     temp=ultimo;
           				while((temp->padre->destro==temp)&&(temp->padre!=P))
                 			//finch� temp � un figlio destro e non � figlio della radice
                 			temp=temp->padre; //risali

                 		if(temp->padre->destro==temp)
                     //il nodo corrente � ancora figlio destro	allora si �
                     //raggiunta la radice quindi passa al fratello sinistro
     	              	   temp=temp->padre->sinistro;
                  	else
   	              		temp=temp->padre->destro; //passa al fratello destro

                     while(temp->sinistro!=NULL) //nodo non � una foglia
                        temp=temp->sinistro;	//scendi a sinistra
                        //inserisci l'elemento come figlio sinistro
            			   newNodo->padre=temp;
	     						newNodo->padre->sinistro=newNodo;
   	   			}
             }
         }
      ultimo=newNodo; //aggiorna ultimo

//fase 2: aggiustamento degli elementi in base alla priorit�
      temp=ultimo;    //riutilizzo il nodo temp
      if(ultimo!=P)
         {
	      while(temp->priority < temp->padre->priority && temp!=P)
   	   //finch� la priorit� del nodo corrente � maggiore di quella del padre
      	//e non si raggiunta la radice
      		{
            	//scambia il contenuto di padre e figlio
	            //(scambio di valore senza variabile di appoggio)
   	         temp->priority = temp->priority + temp->padre->priority;
      	      temp->padre->priority = temp->priority - temp->padre->priority;
         	   temp->priority = temp->priority - temp->padre->priority;

	            //risali e ricontrolla
   	         temp=temp->padre;
      	   }
			}
      return;
   }









void Prioricoda :: cancellamin()
	{
    	nodo temp,corrente;
      tipoelem store;


//fase 1:
//modifica della struttura

   	if(P!=NULL) //l'albero non � vuoto
        	if(ultimo==P) //l'albero ha solo la radice
				{
               temp=P;
               P=ultimo=NULL;
            	delete temp;
            	return;
            }
         else
         	{
               //memorizza il contenuto dell'ultima foglia
               //per reinserirlo successivamente
      			store=ultimo->priority;
              	temp=corrente=ultimo;

					if(ultimo->padre->destro==ultimo) //ultimo � un figlio destro
               	//il nuovo ultimo sar� il fratello sinistro
               	{
                  	ultimo=ultimo->padre->sinistro; //aggiorna ultimo
                     ultimo->padre->destro=NULL;
     						delete temp; //cancella l'ex ultimo
               	}
            	else  //se non � figlio destro
              		{
              			while((corrente->padre->sinistro==corrente)&&(corrente->padre!=P))
                  		//finch� nodo � figlio sinistro e non � figlio della radice
                    		corrente=corrente->padre; //risali
                  	if(corrente->padre->sinistro==corrente) //nodo corrente � ancora figlio sinistro
                     	//allora si � raggiunta la radice e quindi
                        {
                     		if(corrente->padre->destro==NULL) //se la radice non ha figlio destro
										//allora il nuovo ultimo � la radice stessa
                        		corrente=P;
                     		else
                     			//passa al fratello destro
                    				corrente=P->destro;
                        }
                  	else
                    	  	corrente=corrente->padre->sinistro; //passa al fratello sinistro

                     while(corrente->destro!=NULL) //nodo non � una foglia
         			      corrente=corrente->destro;	//scendi a destra

							ultimo->padre->sinistro=NULL;
           				ultimo=corrente;   //aggiorna ultimo
                  	delete temp; //cancella l'ex ultimo
               	}
      		}








//fase 2:
//aggiustamento degli elementi in base alla priorit�

      temp=P;  //riutilizzo il nodo temp partendo dalla radice che
      			//non � pi� significativa

      boolean trovato=false;
      nodo minore;
      //messa a true quando sar� individuata la collocazione
      //per il valore della priorit� del nodo cancellato

      while(!trovato)
      //finch� non sar� individuata la collocazione
      //per il valore della priorit� del nodo cancellato
      	{
         	if(temp->destro!=NULL) //sono presenti entrambi i figli
            	{
                  //scegli il figlio con priorit� minore
               	if(temp->destro->priority < temp->sinistro->priority)
               		minore=temp->destro;
               	else
               		minore=temp->sinistro;
                  if(minore->priority < store)
                  //se tale priorit� � minore di quella del nodo cancellato
                  	{
                     //scrivi il contenuto del figlio scelto nel nodo attuale
                  		temp->priority=minore->priority;
                     //e passa al figlio prescelto
                        temp=minore;
                     }
                  else
                  	{
								//scrivi il contenuto del nodo cancellato
                     	//nella posizione temp
                  		temp->priority=store;
          					//trovata locazione del contenuto del nodo cancellato
                     	trovato=true;
                     }
               }
            else
            	if(temp->sinistro!=NULL) // ha solo il figlio sinistro
			  			if(temp->sinistro->priority < store)
                 	//la priorit� del figlio sinistro �
                 	//minore di quella del nodo cancellato
							{
								//scrivi il contenuto del figlio sinistro in temp
                       	temp->priority=temp->sinistro->priority;
								//passa al figlio sinistro
                       	temp=temp->sinistro;
							}
                  else
                  	{
								//scrivi il contenuto del nodo cancellato
                     	//nella posizione temp
                  		temp->priority=store;
          					//trovata locazione del contenuto del nodo cancellato
                     	trovato=true;
                     }
               else
               	{
							//scrivi il contenuto del nodo cancellato
                     //nella posizione temp
                  	temp->priority=store;
          				//trovata l'allocazione del contenuto del nodo cancellato
                  	trovato=true;
                  }
         }
		return;
   }






//Specifica delle interfacce costrutttore e distruttore
Prioricoda :: Prioricoda()
	{
   	creaprioricoda();
   }




//definizione del distruttore
Prioricoda :: ~Prioricoda()
	{
      while(P!=NULL)
			cancellamin();
   }
