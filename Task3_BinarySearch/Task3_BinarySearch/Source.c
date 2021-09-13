#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define doesNotExist  -1
#define Sorted  1
#define NotSorted  0

/*
Description: seacrh for a specific number inside vec --which it must be sorted-- using binary search algorithm
input param: low -> the index of the first element you want to search form 
			 high -> the index of the last element you want to search to 
			 number -> the element you want to find in vec
			 vec -> the array you want to search in
output param : none
return : return the index of the first occurence of number inside vec if FOUND
		 if not found it returns doesNotExist 
EX :vec = {1,2,3,4} 
	binarySearch(0,3,2,vec) -> returns : 1
	binarySearch(0,3,-1,vec) -> returns : -1 


	***PLEASE GIVE A FEEDBACK ON THE DOCUMENTATION STYLE****
*/
int8_t binarySearch(int low, int high, int32_t  number, uint32_t *vec)
{
	uint8_t mid = (uint8_t)((low + high) / 2);
	if (mid < low || high < mid)
		return doesNotExist;

	if (number == vec[mid])
		return mid;
	else if (number < vec[mid])
		return binarySearch(low, mid - 1, number, vec);
	else
		return binarySearch(mid + 1, high, number, vec);
}
/*
Description : swaps the values ofthe memory locations of xp and yp
input pararm : *xp : address of the first element 
			   *xy : address of the second element 
output paarm : none
return : none
EX :int x = 4;
	int y = 10;
	swap(&x,&y);
	printf("%d\n",x); // 10
	printf("%d\n",y); // 4

*/
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/*
Description : sorts the array
input pararm : *arr : the address of the first element of the array in memory
			   n : the size of the array 
output paarm : none
return : none
EX :uint32_t a[4] = {5,7,0,1};
	bubbleSort(a,4); // a = {0,1,5,7}
*/
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
/*
Description : checks if the array is sorted or not 
input pararm : *arr : the address of the first element of the array in memory
			   n : the size of the array
output paarm : none
return : returns 1 "Sorted" if arr is sorted
		 returns 0 "NotSorted" if arr is not sorted
*/
uint8_t isSorted(uint32_t* arr, uint8_t n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return NotSorted;
	}
	return Sorted;
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
		printf("sorting.....\n");
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
	free(a);

	if (ans == doesNotExist)
		printf("Not Found");
	else
	{
		printf("the number is found at index %d\n", ans);
	}

}

