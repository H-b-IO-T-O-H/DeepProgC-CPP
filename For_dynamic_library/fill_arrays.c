#include "../includes/arrays.h"

int fill_arrays_via_treads(t_data *arrays_info)
{
	t_for_thrd *trd_info = arrays_info->trd_info;
	
	for (int i = 0 ; i < arrays_info->opt_trds_cnt; ++i)//заполняем массив во все потоки
		if (pthread_create(&arrays_info->trds_arr[i], NULL, single_thrd_fill, (void *) &trd_info[i]) != 0)
		{
			printf("Error in Threads creation! Abort...\n");
			return (arrays_info->exit_flag = ERROR_THREADS_CREATE);
		}
	for (int i = 0 ; i < arrays_info->opt_trds_cnt; ++i)//ожидаем завершения всех потоков
		if (pthread_join(arrays_info->trds_arr[i], NULL) != 0)
		{
			printf("Error in Threads join! Abort...\n");
			return (arrays_info->exit_flag = ERROR_THREADS_JOIN);
		}
	return 0;
}
