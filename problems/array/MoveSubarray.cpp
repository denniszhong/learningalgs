#include <stdlib.h>
#include <stdio.h>

void ReverseArray(int arr[], int start, int end)
{
	if (start >= end) return;
	
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		
		start++;
		end--;
	}
}

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
 *  Move sub-array
 */
void MoveSubArray(int arr[], int length, int index)
{
	if (length <= 0 || index < 0 || index >= length)
	{
		printf_s("Array length invalid, or input parameters invalid...\n");
		return;
	}

	if (length == 1)
	{
		printf_s("Array contains just one item, skipping move operation...\n");
		return;
	}

	if (index == 0 || index == length - 1)
	{
		printf_s("Index located at top or tail, skipping move operation...\n");
		return;
	}

	printf_s("Before moving sub-array...\n");
	OutputArray(arr, length);
	
	ReverseArray(arr, 0, index);
	ReverseArray(arr, index + 1, length - 1);
	ReverseArray(arr, 0, length - 1);

	printf_s("After moving sub-array...\n");
	OutputArray(arr, length);
}

int main(void)
{
	int arr[1] = {0};
	
	int arr1[1] = {1};
	MoveSubArray(arr1, sizeof(arr1) / sizeof(int), 1);
	MoveSubArray(arr1, sizeof(arr1) / sizeof(int), 0);

	int arr2[2] = {1, 2};
	MoveSubArray(arr2, sizeof(arr2) / sizeof(int), 1);
	MoveSubArray(arr2, sizeof(arr2) / sizeof(int), 0);

	int arr3[11] = {1, 2, 3, 4, 6, 7, 8, 12, 13, 14, 15};
	MoveSubArray(arr3, sizeof(arr3) / sizeof(int), 3);
	MoveSubArray(arr3, sizeof(arr3) / sizeof(int), 15);

	return 0;
}