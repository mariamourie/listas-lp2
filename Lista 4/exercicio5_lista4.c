#include <stdio.h>

void main()
{
	int i, j;
	float M[4][5], Dobro[4][5], Soma[4][5];
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			printf("Enter a number: \n");
			scanf("%f", &M[i][j]);
			
			Dobro[i][j] = 2 * M[i][j];
			Soma[i][j] = M[i][j] + Dobro[i][j];
		}
	}
	
	printf(" \n Matriz dobro: \n");
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			printf("%.0f ", Dobro[i][j]);
		}
		printf("\n");
	}
	
	printf("Matriz soma: \n");
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			printf("%.0f ", Soma[i][j]);
		}
		printf("\n");
	}
}
