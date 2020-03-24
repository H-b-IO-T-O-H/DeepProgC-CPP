#include "../includes/arrays.h"

void ft_print_array(const int *arr, const int size)
{
	printf("index, arr[i]\n");
	for (int i = 0; i < size; ++i)
		printf("%5d | %d\n", i, arr[i]);
	printf("\n");
}
