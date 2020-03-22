#include "../includes/arrays.h"

int  *ft_create_array(int size)
{
	int *arr;
	
	if (!(arr = (int *)malloc(sizeof(int) * size)))
	{
		printf("\033[031mCan't allocate region for array!\033[039m\n");
		return NULL;
	}
	return (arr);
}

void ft_fill_array(int *arr, int size, int fill_flag)
{
	if (!arr)
		return ;
	if (fill_flag == 1) {
		for (int i = 0; i < size; ++i)
			arr[i] = i;
	}
	else {
		for (int i = 0; i < size; ++i)
			arr[i] = size - i - 1;
	}
}
