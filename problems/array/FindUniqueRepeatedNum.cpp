#include <stdio.h>

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

/*
 *	Array length: N
 *  All array items are positive integer numbers and all of them are < N-1
 	5 6 7 8 9 10 11 11 12 13 14 15
 */
int FindUniqueRepeatedNumInArray(int* pArr, int length)
{
	int start = *pArr;

	int sum1 = ((start+length-1) + start) * length / 2;
	int sum2 = 0;
	for (int i = 0; i < length; i++)
		sum2 += *(pArr + i);

	return end - (sum1-sum2);
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {5, 6, 7, 6/*, 9, 10, 11, 11, 12, 13, 14, 15*/};
	int arr_length = sizeof(arr)/sizeof(int);
	OutputArray(arr, arr_length);
	printf("The unique repeated number in array is: %d\n", FindUniqueRepeatedNumInArray(&arr[0], arr_length));

	return 0;
}
