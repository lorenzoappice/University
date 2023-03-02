#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char separatori[]={' ', ',', ';', '.',':', '\n', '\t', '\0'};  // caratteri separatori

int Separatore(char c)
{
	int esito;
	int i;

	esito=0;
	i=0;
	while ((separatori[i]!='\0') && (esito==0))
		{
		if (c==separatori[i]) esito=1;
		i=i+1;
		}

	return esito;
}
int ContareParole(char * s)
{
	int nparole;
	int parolacompletata;
	int i;

	nparole=0;
	parolacompletata=1;
	i=0;
	while (s[i]!='\0')
		{
		if ((Separatore(s[i])==1) && (parolacompletata=1)) nparole=nparole+1;
		else if (Separatore(s[i])==0) parolacompletata=0;
		i=i+1;
		}

	return nparole;
	void LeggereDaFile(char * s)
	{
		FILE * filetesto;
		int i;
		char c;

		filetesto=fopen("FileTesto.txt", "r");
		if (filetesto!=NULL)
			{
			i=0;
			while ((c=fgetc(filetesto))!=EOF)
				{
				s[i]=c;
				i=i+1;
				}
			s[i]='\0';
			}
		else s[0]='\0';

		return;
	}
int main(void) {
	int nparole;
	char testo[100];
	LeggereDaFile(testo);
	nparole=ContareParole(testo);
	printf("\n numero parole = %d", nparole);
}
	return EXIT_SUCCESS;
}
