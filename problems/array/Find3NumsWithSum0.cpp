#include <stdio.h>
#include <stdlib.h>
//#include <algorithm>
//#include <xfunctional>


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

// Compare function used in qsort
int compare (const void * a, const void * b)
{
	return *((int*)a) - *((int*)b);
}

// -30,-5,6,8,10,25
bool FindThreeNumsWithSumZero(int arr[], int length, int* pNum1, int* pNum2, int* pNum3)
{
	// Use CRT library function qsort to perform a quick sort
	qsort(arr, length, sizeof(int), compare);
	
	// Or we can use a better c++ standard library function std::sort
	// Need include headers <algorithm> and <xfunctional> 
	//std::sort(arr, arr + length, std::less_equal<int>());

	int index = 0;
	while ((*pNum1 = arr[index]) < 0)
	{
		int head = index + 1;
		int tail = length - 1;
		if (FindTwoNumsWithSpecialSum(arr, length, -(*pNum1), pNum2, pNum3, *pNum1, true))
		{
			//*pNum1 = arr[index];
			return true;
		}

		index++;
	}

	return false;
}

void FindThreeNumsWithSumZero_Test_Internal(int arr[], int length, int* pNum1, int* pNum2, int* pNum3)
{
	printf("From ");
	OutputArray(arr, length);
	printf("Find 3 items sum as 0 :\n");

	if (FindThreeNumsWithSumZero(arr, length, pNum1, pNum2, pNum3))
	{
		printf("Found 3 numbers: %d + %d + %d = 0\n\n\n", *pNum1, *pNum2, *pNum3);
	}
	else
	{
		printf("No match found!\n\n\n");
	}
}

#define ARRAY_LENGTH(x)  sizeof(x)/sizeof(int)


int main()
{
	int num1 = 0, num2 = 0, num3 = 0;
	int length = 0;

	int arr[] = {56, 2, -32, 26, -8, 12, 17, -4, 46, 0, 4, 33, 3, 8, -4, -34, 77, -23, 16, 24, 35, 25, 48, 56, 91};
	FindThreeNumsWithSumZero_Test_Internal(arr, ARRAY_LENGTH(arr), &num1, &num2, &num3);
	
	// Try another array
	int arr2[] = {-33, -8, -4, 0, 4, 8, 16, 24, 25, 48, 56, 91};
	FindThreeNumsWithSumZero_Test_Internal(arr2, ARRAY_LENGTH(arr2), &num1, &num2, &num3);

	int arr3[] = {-328, -8, -4, 0, 4, 8, 16, 24, 25, 48, 56, 91};
	FindThreeNumsWithSumZero_Test_Internal(arr3, ARRAY_LENGTH(arr3), &num1, &num2, &num3);

	int arr4[] = {-8, -4, 0, 4, 8, 16, 24, 25, 48, 56, 91};
	FindThreeNumsWithSumZero_Test_Internal(arr4, ARRAY_LENGTH(arr4), &num1, &num2, &num3);

	int arr5[] = {-4, 0, 4, 8, 16, 24, 25, 48, 56, 91};
	FindThreeNumsWithSumZero_Test_Internal(arr5, ARRAY_LENGTH(arr5), &num1, &num2, &num3);

	int arr6[] = {0, 4, 8, 16, 24, 25, 48, 56, 91};
	FindThreeNumsWithSumZero_Test_Internal(arr6, ARRAY_LENGTH(arr6), &num1, &num2, &num3);

	int arr7[] = {4, 8, 16, 24, 25, 48, 56, 91};
	FindThreeNumsWithSumZero_Test_Internal(arr7, ARRAY_LENGTH(arr7), &num1, &num2, &num3);

	return 0;
}