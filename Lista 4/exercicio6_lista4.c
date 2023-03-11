#include <stdio.h>

void main()
{
	int A[3][5], soma_linha[3], i, j;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 5; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		soma_linha[i] = 0;
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 5; j++)
		{
			soma_linha[i] += A[i][j];
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		printf("%d ", soma_linha[i]);
	}
}
