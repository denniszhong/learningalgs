#include <stdio.h>



void OutputArray(int arr[], int length)
{
	int i = 0;
	printf_s("Array: ");
	for (i = 0; i < length; i++)
	{
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
}


/*
 *	Given an unordered array and key, split the array, put all items which
 *  less than the key to left part of the array, and all items which greater than
 *  the key to right part of the array.
 *
 *  E.g. For given:
 *      Key: 20
 *      Array: -4, 34, 25, 18, -23, 1, 19, 57, 12, 6, 39
 *      Return: -4, -23, 18, 1, 19, 12, 6, || 34, 25, 57, 39
 */
bool SplitArrayWithKey(int* pArr, int length, int key)
{
	int head = 0;
	int tail = length - 1;

	while (head < tail)
	{
		while (pArr[head] < key)
		{
			head++;
		}

		while (pArr[tail] >= key)
		{
			tail--;
		}

		int temp = pArr[head];
		pArr[head] = pArr[tail];
		pArr[tail] = temp;

		head++;
		tail--;
	}

	return true;
}

int main()
{
	int arr[] = {-4, 34, 20, 25, 18, -23, 1, 19, 57, 12, 20, 6, 39};
	int length = sizeof(arr) / sizeof (int);

	OutputArray(arr, length);
	SplitArrayWithKey(arr, length, 20);
	OutputArray(arr, length);

	return 0;
}