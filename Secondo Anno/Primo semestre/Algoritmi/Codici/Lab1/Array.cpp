#include <iostream>
int greaterthan (int A[],int k,int size);
bool member (int A[],int k,int size);
int *largest (int A[],int k,int size);
void remove (int A[],int k,int size);
int trovarePrimaOccorrenza(int A[], int size, int k);
void rimuovereElemento(int A[], int size, int posizioneElemento);
void stampaArray(int A[],int size);
int ordering (int B[],int size);
int massimo(int primoValore, int secondoValore);
void reverse (int A[],int size);
int find (int A[], int size, int k);


int main () {
    int k=6;
    int A[] = {1,6,4,9,5};
    int B[] = {5,4,3,2,1};
    int sizeB = sizeof(B) / sizeof(B[0]);
    int size = sizeof(A) / sizeof(A[0]);
    std::cout << "Gli elementi maggiori di k sono:" << greaterthan(A,k,size) << std::endl;
    std::cout << "Il valore k e' presente nell'array? ";
    if (member(A,k,size)) {
        std::cout << "Si" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    int *posizione = largest(A,k,size);
    std::cout << "Il valore piu' grande dell'array e': " << *posizione << std::endl;
    std::cout << " che si trova in posizione: " << posizione - A << std::endl;
    remove(A,k,size);
    std::cout <<"L'array con k rimosso e': ";
    stampaArray(A,size);
    std::cout << "L'array B e' ordinato in modo: ";
    switch (ordering(B,sizeB)) {
        case 1 :
            std::cout << "crescente" << std::endl;
            break;
        case 2 :
            std::cout << "decrescente" << std::endl;
            break;
        case 3 :
            std::cout << "costante" << std::endl;
            break;
        default:
            std::cout << "non ordinato" << std::endl;
            break;
    }
    reverse(A,size);
    std::cout << "La posizione di k e': " << find(A,size,k) << std::endl;
    return 0;
}
//puntatore è la sottrazione iniziale dell'array
int greaterthan (int A[],int k,int size) {
    int i =0;
    int elementiMaggiori = 0;
    for(i=0;i<size;i++) {
        if(A[i]>k) {
            elementiMaggiori++;
        }
    }
    return elementiMaggiori;
}

bool member (int A[],int k,int size) {
    bool trovato = false; 
    for (int i = 0; i<size;i++) {
        if(A[i]==k) {
            trovato = true;
            break;
        }
    }
    return trovato;
}

int *largest (int A[],int k,int size) {
    int *posizione = 0;
    for (int i=0;i<size;i++) {
        if(A[i]>k) {
            posizione = &A[i];
        }
    }

    return posizione;
}

void remove (int A[],int k,int size) {
    int posizioneElemento = trovarePrimaOccorrenza(A, size, k);
    if(posizioneElemento != -1) {
        rimuovereElemento(A, size, posizioneElemento);
    }
    
        return;
}

int trovarePrimaOccorrenza(int A[], int size, int k) {
    for(int indiceA = 0; indiceA < size; indiceA++)
        if(A[indiceA] == k)
            return indiceA;
    return -1;
}
void rimuovereElemento(int A[], int size, int posizioneElemento) {
    int indiceA;
    for(indiceA = posizioneElemento; indiceA < (size - 1); indiceA++)
        A[indiceA] = A[indiceA + 1];
    A[indiceA] = 0;
    return;
}

void stampaArray(int A[],int size) {
    for(int i=0;i<size;i++) {
        std::cout << A[i];
    }
    std::cout << std::endl;
    return;
}
int ordering (int B[],int sizeB) {
    int andamentoSupposto = 3;
    if(sizeB > 1) {
        andamentoSupposto = massimo(B[0], B[1]);
        for(int indiceA = 1; indiceA < sizeB - 1; indiceA++) {
            int andamentoReale = massimo(B[indiceA], B[indiceA + 1]);
            if(andamentoSupposto != andamentoReale)
                if(andamentoSupposto != 3 && andamentoReale != 3)
                    return 0;
                else if(andamentoSupposto == 3)
                    andamentoSupposto = andamentoReale;
        }
    }
    return andamentoSupposto;
}

int massimo(int primoValore, int secondoValore) {
    if (primoValore < secondoValore)
        return 1;
    else if (primoValore > secondoValore)
        return 2;
    else
        return 3;
}
void reverse(int A[], int size) {
	int contenitore;
	int* arrayInvertito = new int[size];
	for (int i = 0; i < size; i++)	{
		arrayInvertito[i] = A[size - 1 - i];
	}
    stampaArray(arrayInvertito,size);
    return;
}
int find (int A[], int size, int k) {
    //find: funzione ricorsiva che ha in input un array A di elementi ordinati e stabilisce l'appartenenza di un elemento k.
}

//chain: ha in input un intero k ed alloca dinamicamente una catena circolare di k celle (valore, next) e restituisce il puntatore ad una delle celle allocate. Dato il puntatore restituito dalla funzione chain, implementare la funzione clear che dealloca tutte le celle della catena.
