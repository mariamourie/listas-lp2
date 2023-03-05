#ifndef __UTILS__
#define __UTILS__
#define N 10
#include <stdio.h>


typedef struct {
	int x, y, z;
} tpPonto;

typedef struct {
	tpPonto ponto;
	char rotulo;
} tpFigura;

void preenche(FILE *file, tpFigura *desenho) {
	int i;
	file = fopen("desenho.dat", "ab");
	
	if (file != NULL) {
		for (i = 0; i < N; i++) {
			printf("X: \n");
			scanf("%d", &desenho[i].ponto.x);
			fwrite(&desenho[i].ponto.x, sizeof(int), 1, file);
			printf("Y: \n");
			scanf("%d", &desenho[i].ponto.y);
			fwrite(&desenho[i].ponto.y, sizeof(int), 1, file);
			printf("Z: \n");
			scanf("%d", &desenho[i].ponto.z);
			fwrite(&desenho[i].ponto.z, sizeof(int), 1, file);
			printf("Rotulo: \n");
			scanf(" %c", &desenho[i].rotulo);
			fwrite(&desenho[i].rotulo, sizeof(char), 1, file);
		}
	}
	fclose(file);
}

void imprime(FILE *file, tpFigura *desenho) {
	int i;
	file = fopen("desenho.dat", "rb");
	
	if (file != NULL) {
		for (i = 0; i < N; i++) {
			fread(&desenho[i].ponto.x, sizeof(int), 1, file);
			fread(&desenho[i].ponto.y, sizeof(int), 1, file);
			fread(&desenho[i].ponto.z, sizeof(int), 1, file);
			fread(&desenho[i].rotulo, sizeof(char), 1, file);
			printf("Ponto %c: x = %d, y = %d, z = %d \n", desenho[i].rotulo, desenho[i].ponto.x, desenho[i].ponto.y, desenho[i].ponto.z);
		}
	}
	fclose(file);
}

void apaga(FILE *file, tpFigura *desenho, char letra) {
	int i;
	file = fopen("desenho.dat", "wb");
	
	if (file != NULL) {
		for (i = 0; i < N; i++) {
			if (desenho[i].rotulo == letra) {
				desenho[i].rotulo = '#';
			}
			fwrite(&desenho[i].ponto.x, sizeof(int), 1, file);
			fwrite(&desenho[i].ponto.y, sizeof(int), 1, file);
			fwrite(&desenho[i].ponto.z, sizeof(int), 1, file);
			fwrite(&desenho[i].rotulo, sizeof(char), 1, file);
		}
	}
	fclose(file);
}

#endif
