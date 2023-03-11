#include <stdio.h>

void main()
{
	int array[10], i, count, biggestNumber;
	
	biggestNumber = 0;
	count = 0;
	
	for(i = 1; i <= 10; i++)
	{
		printf("Enter a number: \n");
		scanf("%d", &array[i]);
		
		if(array[i] > biggestNumber)	
		{
			biggestNumber = array[i];
	 	}
	}
	
	for(i = 1; i <= 10; i++)
	{
		if(array[i] == biggestNumber)
		{
			count++;
		}
	}
	
	printf("Biggest Number: %d \n", biggestNumber);
	printf("Count: %d \n", count);
}
