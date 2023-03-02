#include <stdio.h>
#include <stdlib.h>
float* Input(float v1[5]);
int main(void) {
	float v[5];
	Input(v);
	if (v[0] == v[1]) {
		if (v[2] == v[3]) {
			if (v[0] == v[4]) {
				printf("Tutte le monete sono vere");
			} else {
				printf("La moneta falsa è la 5.");
			}
		} else {
			if (v[2] == v[0]) {
				printf("La moneta falsa è la 4.");
			} else {
				printf("La moneta falsa è la 3.");
			}
		}
	} else {
		if (v[0] == v[4]) {
			printf("La moneta falsa è la 2");
		} else {
			printf("La moneta falsa è la 1");
		}
	}
	return EXIT_SUCCESS;
}

float* Input(float v1[5]) {
	int i = 0;
	while (i < 5) {
		printf("Indicami la moneta numero %d \n", i + 1);
		fflush(stdout);
		scanf("%f", &v1[i]);
		i = i + 1;
	}
	return v1;
}

