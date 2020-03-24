#include "../includes/arrays.h"

int compare_arrays(t_data* arrays_info)
{
	for (int i = 0; i < arrays_info->size; ++i)
		if (arrays_info->arr_A[i] !=arrays_info->arr_B[arrays_info->size - i - 1])
			return NOT_EQUAL;
	return EQUAL;
}