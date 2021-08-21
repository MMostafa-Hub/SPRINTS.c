#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int8_t binarySearch(int low, int high, uint32_t  number, uint32_t *vec)
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
int main()
{
	uint32_t a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d", binarySearch(0, 9, 11, a));
}

