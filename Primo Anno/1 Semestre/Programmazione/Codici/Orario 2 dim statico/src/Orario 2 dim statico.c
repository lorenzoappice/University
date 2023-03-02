#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LEZIONE{
	char materia;
	char aula;
	float oraInizio;
	float oraFine;
};

struct ORARIO {
	int righe;
	int colonne;
	struct LEZIONE TABELLA [20][20];
};


int leggereRighe(struct ORARIO ORARIO1){
	return ORARIO1.righe;
}

struct ORARIO scrivereRighe(struct ORARIO ORARIO1, int nuovoValore){
	ORARIO1.righe = nuovoValore;
	return ORARIO1;
}

int leggereColonne(struct ORARIO ORARIO1){
	return ORARIO1.colonne;
}

struct ORARIO scrivereColonne(struct ORARIO ORARIO1, int nuovoValore){
	ORARIO1.colonne = nuovoValore;
	return ORARIO1;
}

struct LEZIONE leggereLezione(struct ORARIO ORARIO1, int ora, int giorno){
	return ORARIO1.TABELLA[ora][giorno];
}

struct ORARIO scrivereLezione(struct ORARIO ORARIO1, int ora, int giorno, struct LEZIONE NUOVA_LEZIONE){
	ORARIO1.TABELLA[ora][giorno] = NUOVA_LEZIONE;
	return ORARIO1;
}

struct ORARIO inserireLezione(struct ORARIO ORARIO1, int ora, int giorno, char materia, char aula, float oraInizio, float oraFine){
	struct LEZIONE NUOVA_LEZIONE;
	NUOVA_LEZIONE.materia = materia;
	NUOVA_LEZIONE.aula = aula;
	NUOVA_LEZIONE.oraInizio = oraInizio;
	NUOVA_LEZIONE.oraFine = oraFine;

	ORARIO1 = scrivereLezione(ORARIO1, ora, giorno, NUOVA_LEZIONE);
	return ORARIO1;
}

char leggereAula(struct LEZIONE LEZIONE1){
	return LEZIONE1.aula;
}

struct LEZIONE scrivereAula(struct LEZIONE LEZIONE1, char nuovaAula){
	LEZIONE1.aula = nuovaAula;
	return LEZIONE1;
}

char leggereMateria(struct LEZIONE LEZIONE1){
	return LEZIONE1.materia;
}

struct LEZIONE scrivereMateria(struct LEZIONE LEZIONE1, char nuovaMateria){
	LEZIONE1.materia = nuovaMateria;
	return LEZIONE1;
}

float leggereOraInizio(struct ORARIO ORARIO1, int ora, int giorno){
	return ORARIO1.TABELLA[ora][giorno].oraInizio;
}

struct LEZIONE scrivereOraInizio(struct LEZIONE LEZIONE1, float oraInizio){
	LEZIONE1.oraInizio = oraInizio;
	return LEZIONE1;
}

float leggereOraFine(struct LEZIONE LEZIONE1){
	return LEZIONE1.oraFine;
}

struct LEZIONE scrivereOraFine(struct LEZIONE LEZIONE1, float oraFine){
	LEZIONE1.oraFine = oraFine;
	return LEZIONE1;
}

struct ORARIO inserireVuoto(struct ORARIO ORARIO1, struct LEZIONE LEZIONE_VUOTO){
	int pos = 0;
	while (pos < leggereColonne(ORARIO1)){
		int pos2 = 0;
		while (pos2 < leggereRighe(ORARIO1)){
			ORARIO1.TABELLA[pos][pos2] = LEZIONE_VUOTO;
			pos2 = pos2 + 1;
		}
		pos = pos + 1;
	}

	return ORARIO1;
}


struct ORARIO inserireOrario(struct ORARIO ORARIO1){
	char materia;
	char aula;
	float oraInizio;
	float oraFine;
	int pos = 0;
	while (pos < leggereColonne(ORARIO1)){
		int pos2 = 0;
		while (pos2 < leggereRighe(ORARIO1)){
			printf("Giorno %d ora %d, prego inserire orario!\n", pos, pos2);

			printf("Per inserire una lezione vuota inserire n al primo campo (materia) \n");

			printf("Prego inserire la materia (singola lettera): \n");

			scanf(" %c", &materia);

			printf("Prego inserire l'aula (singola lettera): \n");

			scanf(" %c", &aula);

			printf("Prego inserire l'ora di inizio: \n");

			scanf("%f", &oraInizio);

			printf("Prego inserire l'ora di fine: \n");

			scanf("%f", &oraFine);

			if (materia == 'n'){
				ORARIO1 = inserireLezione(ORARIO1, pos,pos2, 'n','n',0.0,0.0);
			} else {
				ORARIO1 = inserireLezione(ORARIO1, pos,pos2, materia,aula,oraInizio,oraFine);
			}

			pos2 = pos2 + 1;
		}
		pos = pos + 1;
	}
	return ORARIO1;
}


struct ORARIO modificareOrario(struct ORARIO ORARIO1){
	int ora;
	int giorno;
	char aula;
	char materia;
	float oraInizio;
	float oraFine;
	struct LEZIONE LEZIONE_MODIFICATA;

	printf("In quale giorno vuoi cambiare l'orario?: ");

	scanf("%d", &giorno);

	printf("In quale colonna vuoi cambiare l'orario?: ");

	scanf("%d", &ora);

	printf("Giorno %d ora %d, prego inserire orario!\n", giorno,ora);

	printf("Prego inserire la materia (singola lettera): \n");

	scanf(" %c", &materia);

	printf("Prego inserire l'aula (singola lettera): \n");

	scanf(" %c", &aula);

	printf("Prego inserire l'ora di inizio: \n");

	scanf("%f", &oraInizio);

	printf("Prego inserire l'ora di fine: \n");

	scanf("%f", &oraFine);

	LEZIONE_MODIFICATA.aula = aula;
	LEZIONE_MODIFICATA.materia = materia;
	LEZIONE_MODIFICATA.oraInizio = oraInizio;
	LEZIONE_MODIFICATA.oraFine = oraFine;

	ORARIO1 = scrivereLezione(ORARIO1,ora,giorno,LEZIONE_MODIFICATA);

	return ORARIO1;
}

struct ORARIO cancellareLezione(struct ORARIO ORARIO1) {
	struct LEZIONE LEZIONE_VUOTO;
	LEZIONE_VUOTO.materia = 'n';
	LEZIONE_VUOTO.aula = 'n';
	LEZIONE_VUOTO.oraInizio = 0.0;
	LEZIONE_VUOTO.oraFine = 0.0;
	int ora;
	int giorno;

	printf("In quale giorno vuoi eliminare l'orario?: ");

	scanf("%d", &giorno);

	printf("In quale ora vuoi eliminare l'orario?: ");

	scanf("%d", &ora);


	ORARIO1 = scrivereLezione(ORARIO1,ora,giorno,LEZIONE_VUOTO);

	return ORARIO1;
}

void stampaLezione(struct LEZIONE LEZIONE1){
	// Stampo ogni dato dalla LEZIONE ricevuta in parametro
	printf("--- \n");
	printf("Aula: ");
	printf("%c\n", LEZIONE1.aula);
	printf("--- \n");
	printf("Materia: ");
	printf("%c\n", LEZIONE1.materia);
	printf("--- \n");
	printf("Ora Inizio: ");
	printf("%.2f\n", LEZIONE1.oraInizio);
	printf("--- \n");
	printf("Ora Fine: ");
	printf("%.2f\n", LEZIONE1.oraFine);
}


void consultareOrarioPerGiorno(struct ORARIO ORARIO1){
	int giorno;
	int pos = 0;
	struct LEZIONE LEZIONI_DEL_GIORNO [5];

	printf("Inserire giorno: ");

	scanf("%d", &giorno);


	while (pos < leggereRighe(ORARIO1)){
		printf("%d",pos);
		LEZIONI_DEL_GIORNO[pos] = leggereLezione(ORARIO1,pos,giorno);
		stampaLezione(LEZIONI_DEL_GIORNO[pos]);
		pos = pos + 1;
	}
}

void consultareOrarioPerOra(struct ORARIO ORARIO1){
	int ora;
	int pos = 0;
	struct LEZIONE LEZIONI_DELL_ORA [9];

	printf("Inserire ora: ");

	scanf("%d", &ora);

	while (pos < leggereColonne(ORARIO1)){
		LEZIONI_DELL_ORA[pos] = leggereLezione(ORARIO1,pos,ora);
		stampaLezione(LEZIONI_DELL_ORA[pos]);
		pos = pos + 1;
	}
}

void consultareOrarioPerMateria(struct ORARIO ORARIO1){
	char materia;
	int pos = 0;
	int pos2 = 0;
	struct LEZIONE LEZIONE_LETTA;
	struct LEZIONE LEZIONI_DI_MATERIA [15];

	printf("Inserire materia: ");

	scanf(" %c", &materia);

	while (pos2 < leggereColonne(ORARIO1)){
		int pos3 = 0;
		while (pos3 < leggereRighe(ORARIO1)){
			LEZIONE_LETTA = leggereLezione(ORARIO1,pos2,pos3);
			if (materia == leggereMateria(LEZIONE_LETTA)){
				LEZIONI_DI_MATERIA[pos] = LEZIONE_LETTA;
				stampaLezione(LEZIONI_DI_MATERIA[pos]);
				pos = pos + 1;
			}
			pos3 = pos3 + 1;
		}
		pos2 = pos2 + 1;
	}

}


void stampaOrario(struct ORARIO ORARIO1){
	// Stampo ogni dato dall' ORARIO ricevuto in parametro
	int pos = 0;
	while (pos < leggereColonne(ORARIO1))
	{
	int pos2 = 0;
		while (pos2 < leggereRighe(ORARIO1))
		{
			printf("Giorno %d ora %d \n", pos , pos2);
			printf("--- \n");
			printf("Materia: ");
			printf("%c\n",ORARIO1.TABELLA[pos][pos2].materia);
			printf("--- \n");
			printf("Aula: ");
			printf("%c\n",ORARIO1.TABELLA[pos][pos2].aula);
			printf("--- \n");
			printf("Ora Inizio: ");
			printf("%.2f\n",ORARIO1.TABELLA[pos][pos2].oraInizio);
			printf("--- \n");
			printf("Ora Fine: ");
			printf("%.2f\n",ORARIO1.TABELLA[pos][pos2].oraFine);
			printf("--- \n");
			pos2 = pos2 + 1;
		}
		pos = pos + 1;
	}
}


int main(void) {
	int righe;
	int colonne;

	printf("Quante colonne avra\' questo orario?: ");

	scanf("%d", &colonne);

	printf("Quante righe avra\' questo orario?: ");

	scanf("%d", &righe);


	struct ORARIO ORARIO1;
	ORARIO1.righe = righe;
	ORARIO1.colonne = colonne;

	// Inserisco l'orario in base alle righe e alle colonne inserite dall'utente;
	ORARIO1 = inserireOrario(ORARIO1);

	system("cls");

	stampaOrario(ORARIO1);


	int continuoGestione = 1;
	int numeroScelto;

	printf("Orario completato con successo! Ora puoi scegliere tra le seguenti opzioni: \n");

	// Chiedo all'utente cosa vuole fare dopo l'inserimento dell'orario
	do {
		printf("--------------------------------------- \n");

		printf("Modificare Orario (1) \n");

		printf("Cancellare Lezione (2) \n");

		printf("Consultare orario per giorno (3) \n");

		printf("Consultare orario per ora (4) \n");

		printf("Consultare orario per materia (5) \n");

		printf("Ristampare orario (6) \n");

		printf("Uscire (7) \n");

		printf("Inserire il numero di quello che desideri fare: \n");

		scanf("%d", &numeroScelto);


		if (numeroScelto == 1){
			system("cls");
			ORARIO1 = modificareOrario(ORARIO1);
		} else if (numeroScelto == 2){
			system("cls");
			ORARIO1 = cancellareLezione(ORARIO1);
		} else if (numeroScelto == 3){
			system("cls");
			consultareOrarioPerGiorno(ORARIO1);
		} else if (numeroScelto == 4){
			system("cls");
			consultareOrarioPerOra(ORARIO1);
		} else if (numeroScelto == 5) {
			system("cls");
			consultareOrarioPerMateria(ORARIO1);
		} else if (numeroScelto == 6){
			system("cls");
			stampaOrario(ORARIO1);
		} else if (numeroScelto == 7) {
			continuoGestione = 0;
		} else {
			continuoGestione = 0;
		}
	} while (continuoGestione > 0);

	system("pause");
	return 0;
}

