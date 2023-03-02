#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Lezione{
	char Materia[25];
	char Aula[10];
	float OraInizio;
	float OraFine;
};
struct Orario {
	int Righe;
	int Colonne;
	struct Lezione *Tabella[20];
};

int LeggereRighe(struct Orario Orario1){
	int r=0;
	r= Orario1.Righe;
	return r;
}
int LeggereColonne(struct Orario Orario1){
	int c=0;
	c= Orario1.Colonne;
	return c;
}
struct Orario AllocaRighe(struct Orario Orario1,int Righe1){
	int pos=0;
	while (pos<LeggereRighe(Orario1))
	{
		Orario1.Tabella[pos]=malloc(Righe1*sizeof(struct Lezione));
		pos=pos+1;
	}
	return Orario1;
};
struct Lezione LeggereLezione(struct Orario Orario1, int Giorno1, int Ora1){
	return Orario1.Tabella[Giorno1][Ora1];
}
char *LeggereAula(struct Lezione Lezione1){
	char *Aula1;
	Aula1=malloc(10 * sizeof(char));
	strcpy(Aula1,Lezione1.Aula);
	return Aula1;
}
char *LeggereMateria(struct Lezione Lezione1){
	char *Materia1;
	Materia1=malloc(25 * sizeof(char));
	strcpy(Materia1,Lezione1.Materia);
	return Materia1;
}
float LeggereOraInizio(struct Lezione Lezione1){
	float Oi=0;
	Oi= Lezione1.OraInizio;
	return Oi;
}
float LeggereOraFine(struct Lezione Lezione1){
	float Of=0;
	Of= Lezione1.OraFine;
	return Of;
}
//funzioni scrittura
struct Orario ScrivereColonne(struct Orario Orario1, int nuovoValore){
	Orario1.Colonne = nuovoValore;
	return Orario1;
}

struct Orario ScrivereRighe(struct Orario Orario1, int nuovoValore){
	Orario1.Righe = nuovoValore;
	return Orario1;
}
struct Orario ScrivereLezione(struct Orario Orario1, int Giorno1, int Ora1, struct Lezione Lezione1){
	Orario1.Tabella[Giorno1][Ora1] = Lezione1;
	return Orario1;
}
struct Lezione ScrivereAula(struct Lezione Lezione1, char nuovaAula[10]){
	strcpy(Lezione1.Aula,nuovaAula);
	return Lezione1;
}
struct Lezione ScrivereMateria(struct Lezione Lezione1, char nuovaMateria[25]){
	strcpy(Lezione1.Materia,nuovaMateria);
	return Lezione1;
}

struct Lezione ScrivereOraInizio(struct Lezione Lezione1, float OraInizio1){
	Lezione1.OraInizio = OraInizio1;
	return Lezione1;
}
struct Lezione ScrivereOraFine(struct Lezione Lezione1, float OraFine1){
	Lezione1.OraFine = OraFine1;
	return Lezione1;
}
struct Orario InserireLezione(struct Orario Orario1, int Giorno1,int Ora1, char Materia1[25], char Aula1[10], float OraInizio1, float OraFine1){
	struct Lezione Lezione1;
	Lezione1 = ScrivereMateria(Lezione1, Materia1);
	Lezione1 = ScrivereAula(Lezione1, Aula1);
	Lezione1 = ScrivereOraInizio(Lezione1,OraInizio1);
	Lezione1 = ScrivereOraFine(Lezione1,OraFine1);
	Orario1 = ScrivereLezione(Orario1,Giorno1,Ora1, Lezione1);
	return Orario1;
}
struct Orario InserireVuoto(struct Orario Orario1, struct Lezione Lezione1){
	int pos = 0;
	while (pos < LeggereColonne(Orario1))
	{
		int pos2 = 0;
		while (pos2 < LeggereRighe(Orario1))
		{
			Orario1.Tabella[pos][pos2] = Lezione1;
			pos2 = pos2 + 1;
		}
		pos = pos + 1;
	}
	return Orario1;
}


struct Orario InserireOrario(struct Orario Orario1){
	char Materia1[25];
	char Aula1[10];
	float OraInizio1;
	float OraFine1;
	int pos = 0;
	while (pos < LeggereColonne(Orario1))
	{
		int pos2 = 0;
		while (pos2 < LeggereRighe(Orario1))
		{
			printf("Giorno %d ora %d,inserisci l'orario!\n", pos, pos2);
			printf("Se non hai lezione inserisci '-' a materia.\n");
			printf("Indicami la materia: \n");
			scanf("%s",Materia1);
			if(!strcmp(Materia1, "-"))
			{
				Orario1 = InserireLezione(Orario1,pos,pos2,"-","-",0.0,0.0);
			}
			else
			{
				printf("Indicami l'aula: \n");
			    scanf("%s",Aula1);
			    printf("Indicami l'ora di inizio: \n");
			    scanf("%f", &OraInizio1);
			    printf("Indicami l'ora di fine: \n");
			    scanf("%f", &OraFine1);
			    Orario1 = InserireLezione(Orario1,pos,pos2,Materia1,Aula1,OraInizio1,OraFine1);
			}
			pos2 = pos2 + 1;
		}
		pos = pos + 1;
	}
	return Orario1;
}


struct Orario ModificareOrario(struct Orario Orario1){
	int Ora1;
	int Giorno1;
	char Aula1[10];
	char Materia1[25];
	float OraInizio1;
	float OraFine1;
	struct Lezione Lezionemod1;
	printf("Indicami in quale giorno vuoi cambiare l'orario: ");
	scanf("%d", &Giorno1);
	printf("Indicami in quale ora vuoi cambiare l'orario: ");
	scanf("%d", &Ora1);
	printf("Giorno %d ora %d,insersci l' orario nuovo!\n", Giorno1,Ora1);
	printf("Indicami la materia nuova, '-' se non hai lezione: \n");
	scanf("%s", Materia1);
	if(!strcmp(Materia1, "-"))
	{
		Orario1 = InserireLezione(Orario1,Giorno1,Ora1,"-","-",0.0,0.0);
	}
	else
	{
		printf("Indicami l'aula nuova: \n");
			scanf("%s", Aula1);
			printf("Indicami l'ora di inizio nuovo: \n");
			scanf("%f", &OraInizio1);
			printf("Indicami l'ora di fine nuova: \n");
			scanf("%f", &OraFine1);
			Lezionemod1 = ScrivereAula(Lezionemod1,Aula1);
			Lezionemod1 = ScrivereMateria(Lezionemod1,Materia1);
			Lezionemod1 = ScrivereOraInizio(Lezionemod1,OraInizio1);
			Lezionemod1 = ScrivereOraFine(Lezionemod1,OraFine1);
			Orario1 = ScrivereLezione(Orario1,Giorno1,Ora1,Lezionemod1);
	}
	return Orario1;
}

struct Orario CancellareLezione(struct Orario Orario1) {
	struct Lezione LezioneVuoto1;
	LezioneVuoto1 = ScrivereAula(LezioneVuoto1,"-");
	LezioneVuoto1 = ScrivereMateria(LezioneVuoto1,"-");
	LezioneVuoto1 = ScrivereOraInizio(LezioneVuoto1,0.00);
	LezioneVuoto1 = ScrivereOraFine(LezioneVuoto1,0.00);
	int Ora;
	int Giorno;
	printf("Indicami in quale giorno vuoi eliminare l'orario: ");
	scanf("%d", &Giorno);
	printf("Indicami in quale ora vuoi eliminare l'orario: ");
	scanf("%d", &Ora);
	Orario1 = ScrivereLezione(Orario1,Giorno,Ora,LezioneVuoto1);
	return Orario1;
}

void StampaLezione(struct Lezione Lezione1){
	printf("--- \n");
	printf("Aula: ");
	printf("%s\n", LeggereAula(Lezione1));
	printf("--- \n");
	printf("Materia: ");
	printf("%s\n", LeggereMateria(Lezione1));
	printf("--- \n");
	printf("Ora Inizio: ");
	printf("%.2f\n", LeggereOraInizio(Lezione1));
	printf("--- \n");
	printf("Ora Fine: ");
	printf("%.2f\n", LeggereOraFine(Lezione1));
}

void ConsultareOrarioPerGiorno(struct Orario Orario1){
	int Giorno;
	int pos = 0;
	struct Lezione LezioneGiorno [5];
	printf("Indicami il giorno da consultare: ");
	scanf("%d", &Giorno);
	while (pos < LeggereRighe(Orario1))
	{
		LezioneGiorno[pos] = LeggereLezione(Orario1,Giorno,pos);
		StampaLezione(LezioneGiorno[pos]);
		pos = pos + 1;
	}
}

void ConsultareOrarioPerOra(struct Orario Orario1){
	int Ora;
	int pos = 0;
	struct Lezione LezioneOra [9];
	printf("Indicami l' ora da consultare: ");
	scanf("%d", &Ora);
	while (pos < LeggereColonne(Orario1))
	{
		LezioneOra[pos] = LeggereLezione(Orario1,pos,Ora);
		StampaLezione(LezioneOra[pos]);
		pos = pos + 1;
	}
}

void ConsultareOrarioPerMateria(struct Orario Orario1){
	char Materia[25];
	int pos = 0;
	int pos2 = 0;
	struct Lezione LezioneLetta1;
	struct Lezione LezioneMateria1 [15];
	printf("Indicami la materia da consultare: ");
	scanf("%s", Materia);
	while (pos2 < LeggereColonne(Orario1))
	{
		int pos3 = 0;
		while (pos3 < LeggereRighe(Orario1))
		{
			LezioneLetta1 = LeggereLezione(Orario1,pos2,pos3);
			if (!strcmp(Materia,LeggereMateria(LezioneLetta1)))
			{
				LezioneMateria1[pos] = LezioneLetta1;
				StampaLezione(LezioneMateria1[pos]);
				pos = pos + 1;
			}
			pos3 = pos3 + 1;
		}
		pos2 = pos2 + 1;
	}
}


void StampaOrario(struct Orario Orario1){
	int pos = 0;
	while (pos < LeggereColonne(Orario1))
	{
	int pos2 = 0;
		while (pos2 < LeggereRighe(Orario1))
		{
			printf("Giorno %d ora %d \n", pos , pos2);
			printf("--- \n");
			printf("Materia: ");
			printf("%s\n",LeggereMateria(LeggereLezione(Orario1,pos,pos2)));
			printf("--- \n");
			printf("Aula: ");
			printf("%s\n",LeggereAula(LeggereLezione(Orario1,pos,pos2)));
			printf("--- \n");
			printf("Ora Inizio: ");
			printf("%.2f\n",LeggereOraInizio(LeggereLezione(Orario1,pos,pos2)));
			printf("--- \n");
			printf("Ora Fine: ");
			printf("%.2f\n",LeggereOraFine(LeggereLezione(Orario1,pos,pos2)));
			printf("--- \n");
			pos2 = pos2 + 1;
		}
		pos = pos + 1;
	}
}


int main(void) {
	int Righe;
	int Colonne;
	printf("Indicami le colonne dell'orario: ");
	scanf("%d", &Colonne);
	printf("Indicami le righe dell'orario: ");
	scanf("%d", &Righe);
	struct Orario Orario1;
	Orario1= ScrivereRighe(Orario1,Righe);
	Orario1= ScrivereColonne(Orario1,Colonne);
	Orario1= AllocaRighe(Orario1,Righe);
	Orario1= InserireOrario(Orario1);
	system("cls");
	StampaOrario(Orario1);
	int continuoGestione = 1;
	int numeroScelto;
	printf("Inserimento effetuato.\n");
	do {
		printf("-Scegli tra le seguenti opzioni:  \n");
		printf("1: Modificare Orario\n");
		printf("2: Cancellare Lezione\n");
		printf("3: Consultare orario per giorno\n");
		printf("4: Consultare orario per ora\n");
		printf("5: Consultare orario per materia\n");
		printf("6: Ristampare orario\n");
		printf("7: Esci\n");
		printf("Inserire scelta: \n");
		scanf("%d", &numeroScelto);
		if (numeroScelto == 1){

			system("cls");
			Orario1 = ModificareOrario(Orario1);
		}
		else if (numeroScelto == 2)
		{
			system("cls");
			Orario1 = CancellareLezione(Orario1);
		}
		else if (numeroScelto == 3)
		{
			system("cls");
			ConsultareOrarioPerGiorno(Orario1);
		}
		else if (numeroScelto == 4)
		{
			system("cls");
			ConsultareOrarioPerOra(Orario1);
		}
		else if (numeroScelto == 5)
		{
			system("cls");
			ConsultareOrarioPerMateria(Orario1);
		}
		else if (numeroScelto == 6)
		{
			system("cls");
			StampaOrario(Orario1);
		}
		else if (numeroScelto == 7)
		{
			continuoGestione = 0;
		}
		else
		{
			continuoGestione = 0;
		}
	} while (continuoGestione > 0);

	system("pause");
	return 0;
}

