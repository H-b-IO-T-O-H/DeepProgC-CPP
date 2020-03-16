#include "../includes/arrays.h"

int *ft_create_array(int size)
{
	int *arr;
	
	if (!(arr = (int *)malloc(sizeof(int) * size)))
	{
		printf("\033[031mCan't allocate region for array!\033[039m\n");
		return NULL;
	}
	return (arr);
}

int *ft_fill_array(int size, int fill_flag)
{
	int *arr = NULL;
	
	arr = ft_create_array(size);
	if (!arr)
		return NULL;
	if (fill_flag == 0) {
		for (int i = 0; i < size; ++i)
			arr[i] = i;
	}
	else {
		for (int i = 0; i < size; ++i)
			arr[i] = size - i - 1;
	}
	return arr;
}
