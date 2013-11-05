
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

void OutputArray(int arr[], int length)
{
	int i = 0;
	printf("Array: ");
	for (i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void OutputArray2(int* pArr, int length)
{
	int i = 0;
	printf("Array: ");
	for (i = 0; i < length; i++)
	{
		printf("%d ", *pArr++);
	}
	printf("\n");
}

void RandomArrayWithSelfMalloc(int rangeMin, int rangeMax, int* pArr, int arrLength)
{
	pArr = (int*)malloc(sizeof(int) * arrLength);
	memset(pArr, 0, sizeof(int) * arrLength);

	// Seed the random-number generator with current time so that
    // the numbers will be different every time we run.
	srand( (unsigned)time(NULL) );

	for (int i = 0; i < arrLength; ++i)
	{
		int randNumber = (int)( (double)rand() / (double)RAND_MAX ) * rangeMax + rangeMin;
		*(pArr + i) = randNumber;
	}

	// TODO: How to use randomize() ?
}

// pArr is a pointer point to an array,
// the memory size of this array must be allocated by the caller.
void RandomArray(int rangeMin, int rangeMax, int* pArr, int arrLength)
{
	// Seed the random-number generator with current time so that
	// the numbers will be different every time we run.
	srand( (unsigned)time(NULL) );

	for (int i = 0; i < arrLength; ++i)
	{
		int randNumber = ( (double)rand() / (double)RAND_MAX ) * rangeMax + rangeMin;
		*(pArr + i) = randNumber;
	}

	// TODO: How to use randomize() ?
}

int main(int argc, char const *argv[])
{
	int* pArr = NULL;
	int arrLength = 10;

	pArr = (int*)malloc(sizeof(int) * arrLength);
	memset(pArr, 0, sizeof(int) * arrLength);
	RandomArray(2, 50, pArr, 10);
	OutputArray2(pArr, arrLength);
	return 0;
}