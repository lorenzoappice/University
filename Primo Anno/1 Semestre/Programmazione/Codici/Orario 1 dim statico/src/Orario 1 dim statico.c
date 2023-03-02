#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define larghezza 20
#define altezza 20
struct LEZIONE{
	char materia;
	char aula;
	float oraInizio;
	float oraFine;
};
struct ORARIO {
	int righe;
	int colonne;
	struct LEZIONE TABELLA [larghezza * altezza];
};

//funzioni di accesso
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
	return ORARIO1.TABELLA[leggereColonne(ORARIO1) * ora + giorno];
}
struct ORARIO scrivereLezione(struct ORARIO ORARIO1, int ora, int giorno, struct LEZIONE NUOVA_LEZIONE){
	ORARIO1.TABELLA[leggereColonne(ORARIO1) * ora + giorno] = NUOVA_LEZIONE;
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
float leggereOraInizio(struct LEZIONE LEZIONE1){
	return LEZIONE1.oraInizio;
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


//funzioni utente:
struct ORARIO inserireLezione(struct ORARIO ORARIO1, int ora, int giorno, char materia, char aula, float oraInizio, float oraFine){
	struct LEZIONE NUOVA_LEZIONE;
	NUOVA_LEZIONE = scrivereMateria(NUOVA_LEZIONE, materia);
	NUOVA_LEZIONE = scrivereAula(NUOVA_LEZIONE, aula);
	NUOVA_LEZIONE = scrivereOraInizio(NUOVA_LEZIONE,oraInizio);
	NUOVA_LEZIONE = scrivereOraFine(NUOVA_LEZIONE,oraFine);
	ORARIO1 = scrivereLezione(ORARIO1, ora, giorno, NUOVA_LEZIONE);
	return ORARIO1;
}
struct ORARIO inserireVuoto(struct ORARIO ORARIO1, struct LEZIONE LEZIONE_VUOTO){
	int pos = 0;
	while (pos < leggereColonne(ORARIO1)){
		int pos2 = 0;
		while (pos2 < leggereRighe(ORARIO1)){
			scrivereLezione(ORARIO1, pos2, pos, LEZIONE_VUOTO);
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
	while (pos < leggereColonne(ORARIO1))
	{
		int pos2 = 0;
		while (pos2 < leggereRighe(ORARIO1))
		{
			printf("Giorno %d ora %d, prego inserire orario!\n", pos, pos2);
			printf("Se non hai lezione, inserire: - a materia \n");
			printf("Indicami la materia: \n");
			scanf(" %c", &materia);
			if (materia == '-')
			{
				ORARIO1 = inserireLezione(ORARIO1, pos2,pos, '-','-',0.0,0.0);
			}
			else
			{
				printf("Indicami l'aula: \n");
				 scanf(" %c", &aula);
				printf("Indicami l'ora di inizio: \n");
				 scanf("%f", &oraInizio);
                printf("Indicami l'ora di fine: \n");
                 scanf("%f", &oraFine);
                 ORARIO1 = inserireLezione(ORARIO1, pos2,pos, materia,aula,oraInizio,oraFine);
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
	printf("Indicami in quale giorno vuoi cambiare l'orario?: ");
	 scanf("%d", &giorno);
	printf("Indicami in quale colonna vuoi cambiare l'orario?: ");
	 scanf("%d", &ora);
	printf("Giorno %d ora %d, inserisci la lezione nuova!\n", giorno,ora);
	printf("Indicami la materia: \n");
	 scanf(" %c", &materia);
	printf("Indicami l'aula: \n");
	 scanf(" %c", &aula);
	printf("Indicami l'ora di inizio: \n");
	 scanf("%f", &oraInizio);
	printf("Indicami l'ora di fine: \n");
	 scanf("%f", &oraFine);
	LEZIONE_MODIFICATA = scrivereMateria(LEZIONE_MODIFICATA,materia);
	LEZIONE_MODIFICATA = scrivereAula(LEZIONE_MODIFICATA,aula);
	LEZIONE_MODIFICATA = scrivereOraInizio(LEZIONE_MODIFICATA, oraInizio);
	LEZIONE_MODIFICATA = scrivereOraFine(LEZIONE_MODIFICATA, oraFine);
	ORARIO1 = scrivereLezione(ORARIO1,ora,giorno,LEZIONE_MODIFICATA);
	return ORARIO1;
}

struct ORARIO cancellareLezione(struct ORARIO ORARIO1) {
	struct LEZIONE LEZIONE_VUOTO;
	LEZIONE_VUOTO = scrivereMateria(LEZIONE_VUOTO, '-');
	LEZIONE_VUOTO = scrivereAula(LEZIONE_VUOTO, '-');
	LEZIONE_VUOTO = scrivereOraInizio(LEZIONE_VUOTO, 0.0);
	LEZIONE_VUOTO = scrivereOraFine(LEZIONE_VUOTO, 0.0);
	int ora;
	int giorno;
	printf("Indicami in quale giorno vuoi eliminare l'orario?: ");
	 scanf("%d", &giorno);
	printf("Indicami in quale ora vuoi eliminare l'orario?: ");
	 scanf("%d", &ora);
	ORARIO1 = scrivereLezione(ORARIO1,ora,giorno,LEZIONE_VUOTO);
	return ORARIO1;
}

void stampaLezione(struct LEZIONE LEZIONE1){
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
	while (pos < leggereRighe(ORARIO1))
	{
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
	while (pos < leggereColonne(ORARIO1))
	{
		LEZIONI_DELL_ORA[pos] = leggereLezione(ORARIO1,ora,pos);
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
	while (pos2 < leggereColonne(ORARIO1))
	{
		int pos3 = 0;
		while (pos3 < leggereRighe(ORARIO1))
		{
			LEZIONE_LETTA = leggereLezione(ORARIO1,pos2,pos3);
			if (materia == leggereMateria(LEZIONE_LETTA))
			{
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
	int pos = 0;
	while (pos < leggereColonne(ORARIO1))
	{
	int pos2 = 0;
		while (pos2 < leggereRighe(ORARIO1))
		{
			printf("Giorno %d ora %d \n", pos , pos2);
			printf("--- \n");
			printf("Materia: ");
			printf("%c\n",ORARIO1.TABELLA[leggereColonne(ORARIO1) * pos2 + pos].materia);
			printf("--- \n");
			printf("Aula: ");
			printf("%c\n",ORARIO1.TABELLA[leggereColonne(ORARIO1) * pos2 + pos].aula);
			printf("--- \n");
			printf("Ora Inizio: ");
			printf("%.2f\n",ORARIO1.TABELLA[leggereColonne(ORARIO1) * pos2 + pos].oraInizio);
			printf("--- \n");
			printf("Ora Fine: ");
			printf("%.2f\n",ORARIO1.TABELLA[leggereColonne(ORARIO1) * pos2 + pos].oraFine);
			printf("--- \n");
			pos2 = pos2 + 1;
		}
		pos = pos + 1;
	}
}


int main(void) {
	int righe,colonne;
	printf("Indicami le righe: ");
	  scanf("%d", &colonne);
	printf("Indicami le colonne: ");
	  scanf("%d", &righe);
	struct ORARIO ORARIO1;
	ORARIO1= scrivereRighe(ORARIO1, righe);
	ORARIO1= scrivereColonne(ORARIO1, colonne);
	ORARIO1= inserireOrario(ORARIO1);
	system("cls");
	stampaOrario(ORARIO1);
	int continuoGestione = 1;
	int numeroScelto;
	printf("Orario inserito,indicami cosa vuoi fare: \n");
	do
	{
		printf("--------------------------------------- \n");
		printf("(1) Modifica Orario  \n");
		printf("(2)Cancella Lezione  \n");
		printf("(3)Consulta orario per giorno  \n");
		printf("(4) Consulta orario per ora  \n");
		printf("(5)Consulta orario per materia  \n");
		printf("(6) Stampa Orario  \n");
		printf("(7)Exit\n");
		 scanf("%d", &numeroScelto);
		if (numeroScelto == 1)
		{
			system("cls");
			ORARIO1 = modificareOrario(ORARIO1);
		}
		else if (numeroScelto == 2)
		{
			system("cls");
			ORARIO1 = cancellareLezione(ORARIO1);
		}
		else if (numeroScelto == 3)
		{
			system("cls");
			consultareOrarioPerGiorno(ORARIO1);
		}
		else if (numeroScelto == 4)
		{
			system("cls");
			consultareOrarioPerOra(ORARIO1);
		}
		else if (numeroScelto == 5)
		{
			system("cls");
			consultareOrarioPerMateria(ORARIO1);
		}
		else if (numeroScelto == 6)
		{
			system("cls");
			stampaOrario(ORARIO1);
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

