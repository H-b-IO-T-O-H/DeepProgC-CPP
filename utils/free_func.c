#include "../includes/arrays.h"

void free_all(t_data **arrays_info, int type)
{
	if ((*arrays_info)->arr_A)
		free((*arrays_info)->arr_A);
	if ((*arrays_info)->arr_B)
		free((*arrays_info)->arr_B);
	if (type == MULTI_THREADS) {
		
		if ((*arrays_info)->trd_info)
			free((*arrays_info)->trd_info);
		if ((*arrays_info)->trds_arr)
			free((*arrays_info)->trds_arr);
	}
	free(*arrays_info);
}