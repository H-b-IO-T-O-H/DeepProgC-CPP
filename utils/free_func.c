#include "../includes/arrays.h"

void free_all(t_data **arrays_info, int type)
{
	if ((*arrays_info)->info.arr_A)
		free((*arrays_info)->info.arr_A);
	if ((*arrays_info)->info.arr_B)
		free((*arrays_info)->info.arr_B);
	if (type == MULTI_THREADS) {
		if ((*arrays_info)->info.distribution)
			free((*arrays_info)->info.distribution);
		if ((*arrays_info)->info.trds_arr)
			free((*arrays_info)->info.trds_arr);
		pthread_mutex_destroy(&(*arrays_info)->mutex);
	}
	free(*arrays_info);
}