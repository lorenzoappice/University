#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Vettore{
	int Dim;
	int *Valori;
};
struct Studente{
	char Nome[25];
	int Matricola;
	struct Vettore Voti;
};

//funzioni di accesso vettore

struct Vettore ScrivereValore(struct Vettore Vettore1, int Valore1,int pos1){
	Vettore1.Valori[pos1] = Valore1;
	return Vettore1;
}
struct Vettore ScrivereDimensione(struct Vettore Vettore1, int Dim1){
	Vettore1.Dim=Dim1;
	return Vettore1;
}
int LeggereValore(struct Vettore Vettore1,int pos1){
	int v=0;
	v= Vettore1.Valori[pos1];
    return v;
}
int LeggereDimensione(struct Vettore Vettore1){
	int d=0;
     d= Vettore1.Dim;
	return d;
}
struct Vettore AlMemValori(struct Vettore Vettore1, int pos){
	Vettore1.Valori = malloc(LeggereDimensione(Vettore1)*sizeof(struct Studente));
	return Vettore1;
};
//FUNZIONI DI ACCESSO

char *LeggereNome(struct Studente Studente1){
	char *Nome1;
	Nome1=malloc(25 * sizeof(char));
	strcpy(Nome1,Studente1.Nome);
	return Nome1;
}
struct Studente ScrivereNome(struct Studente Studente1, char NuovoNome[25]){
	strcpy(Studente1.Nome,NuovoNome);
	return Studente1;
}
int LeggereMatricola(struct Studente Studente1){
	int m=0;
	m= Studente1.Matricola;
	return m;
}
struct Studente ScrivereMatricola(struct Studente Studente1, int matricola){
	Studente1.Matricola=matricola;
	return Studente1;
}


//Funzioni utilitarie
struct Studente CercaMatricola(struct Studente Studente1, int matricola){
	FILE *fp = fopen("Studente.txt;","r");
	if(fp!=NULL)
	{
		printf("File aperto con successo\n");
	}
	else
	{
		printf("Errore apertura file");
	}
	return Studente1;
}
struct Studente CercaStudente(struct Studente Studente1, int Nome){
	FILE *fp = fopen("Studente.txt;","r");
	if(fp!=NULL)
	{
		printf("File aperto con successo\n");
	}
	else
	{
		printf("Errore apertura file");
	}
	return Studente1;
}
int MediaVoti(struct Studente Studente1,int *Voti1){
	FILE *fp = fopen("Studente.txt;","r");
	int Media;
	int pos=0;
	int dim;//da allocare la dimensione di Voti1
	if(fp!=NULL)
	{
		printf("File aperto con successo\n");
		while(pos<=dim)
		{
			Media=Media+Voti1[pos];
			pos=pos+1;
		}
		Media=Media/dim;
	}
	else
	{
		printf("Errore apertura file");
	}
	return Media;
}
int main(void) {
	int scelta;
	int gestione=1;
	struct Studente Studente1;
	char Nome[25];
	int Matricola;
		do
		{
		printf("File aperto con successo!\n");
		printf("Indicami la scelta che vuoi fare:\n");
		printf("1- Ricerca e media per nome studente.\n");
		printf("2- Ricerca e media per matricola studente.\n");
		printf("0- Exit.");
		scanf("%d",&scelta);
	    if(scelta == 1)
	    {
	    	system("cls");
	    	printf("Indicami il nome dello studente\n");
	    	scanf("%s",Nome);
	    	ScrivereNome(Studente1,Nome);
	    }
	    else if (scelta == 2)
	    {
	    	system("cls");
	    	printf("Indicami la matricola dello studente\n");
	    	scanf("%d",&Matricola);
	    	ScrivereMatricola(Studente1,Matricola);

	    }
	    else if (scelta==0)
	    {
	    	gestione=0;
	    }
	    else
	    {
	    	gestione=0;
	    }
		}while(gestione<0);
	system("pause");
	return EXIT_SUCCESS;
}
