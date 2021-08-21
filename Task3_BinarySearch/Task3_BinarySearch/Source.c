#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int8_t binarySearch(int low, int high, int32_t  number, uint32_t *vec)
{
	uint8_t mid = (uint8_t)((low + high) / 2);
	if (mid < low || high < mid)
		return -1;

	if (number == vec[mid])
		return mid;
	else if (number < vec[mid])
		return binarySearch(low, mid - 1, number, vec);
	else
		return binarySearch(mid + 1, high, number, vec);
}
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(uint32_t* arr, uint32_t n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
uint8_t isSorted(uint32_t* arr, uint8_t n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}
int main()
{
	printf("Enter the length of the array:\n");
	int n; scanf("%d", &n);
	uint32_t *a = malloc(n * sizeof(uint32_t));

	printf("Enter the array elements:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	if (!isSorted(a, n))
	{
		printf("the array is not sorted\n");
		bubbleSort(a, n);
		for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	else
	{
		printf("the array is sorted\n");
	}


	printf("Enter the number you want so search for:\n");
	int32_t number; scanf("%d", &number);

	int8_t ans = binarySearch(0, n - 1, number, a);
	if (ans == -1)
		printf("Not Found");
	else
	{
		printf("the number is found at index %d\n", ans);
	}

}

