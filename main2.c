#include "doubly_linked_list.h"
#include "libpushswap.h"

int main(void)
{
	int arr[] = {31, 2, 10, 0, 1, 4, 5, 6};
	int arrsize = 8;

	int median = get_median(arr, arrsize);
	printf("median %i\n", median);
	int movement = to_traverse(arr, arrsize, median);
	printf("movement %i\n", movement);
}