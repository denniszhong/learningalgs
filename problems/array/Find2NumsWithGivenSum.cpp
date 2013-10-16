//
// Compile:
// gcc Find2NumsWithGivenSum.cpp -o D:\temp\Find2NumsWithGivenSum.exe
//


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
	printf("Array: ");
	for (i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*
 *  Find two numbers in an INCREASING array whose sum equals the key specified.
 *  Return true if at least find one pair, false if no match pair found.
 *  e.g. 
		given an increasing array {-32, -4, 0, 4, 16, 24, 25, 48, 91}, 
		and given key 20, their are at least two pairs (-4, 24) and (4, 16).
		Find one.
 */
bool FindTwoNumsWithSpecialSum(int arr[], int arrLength, int key, int* pNum1, int* pNum2)
{
	int start = 0;
	int end = arrLength -1;

	while (start < end)
	{
		if (arr[start] + arr[end] > key)
		{
			end--;
		}
		else if (arr[start] + arr[end] < key)
		{
			start++;
		}
		else
		{
			*pNum1 = arr[start];
			*pNum2 = arr[end];
			return true;
		}
	}

	return false;
}

bool FindTwoNumsWithSpecialSum(int arr[], int length, int key, int* pNum1, int* pNum2, int except, bool needExcept = false)
{
	int start = 0;
	int end = length -1;

	while (start < end)
	{
		if (needExcept && arr[start] == except)
		{
			start++;
			continue;
		}

		if (needExcept && arr[end] == except)
		{
			end--;
			continue;
		}

		if (arr[start] + arr[end] > key)
		{
			end--;
		}
		else if (arr[start] + arr[end] < key)
		{
			start++;
		}
		else
		{
			*pNum1 = arr[start];
			*pNum2 = arr[end];
			return true;
		}
	}

	return false;
}


int main()
{
	int arr[] = {-32, -4, 0, 4, 16, 24, 25, 48, 56, 91};
	int length = sizeof(arr)/sizeof(int);
	int num1 = 0, num2 = 0;
	int key = 20;
	int skip = 0;

	printf("From the follow array\n");
	OutputArray(arr, length);
	printf("Find a pair items sum as %d :\n", key);

	if (FindTwoNumsWithSpecialSum(arr, length, key, &num1, &num2, skip))
	{
		printf("Found the pair: (%d, %d)\n", num1, num2);
	}
	else
	{
		printf("Didn't find!\n");
	}


	// Try with item we need skip...
	skip = -4;

	printf("\n\nFrom the follow array\n");
	OutputArray(arr, 10);
	printf("Find a pair items sum as %d :\n", key);

	if (FindTwoNumsWithSpecialSum(arr, sizeof(arr)/sizeof(int), key, &num1, &num2, skip, true))
	{
		printf("Found the pair: (%d, %d)\n", num1, num2);
	}
	else
	{
		printf("Didn't find!\n");
	}

	return 0;
}