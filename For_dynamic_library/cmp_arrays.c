#include "../includes/arrays.h"

int compare_arrays_via_threads(t_data *arrays_info)
{
	arrays_info->info.exit_flag = EQUAL;
	for (int i = 0 ; i < arrays_info->info.opt_trds_cnt; ++i)
	{
		pthread_mutex_lock(&arrays_info->mutex);
		arrays_info->info.pos = i;
		pthread_create(&arrays_info->info.trds_arr[i], NULL, cmp_arrs, (void *)&arrays_info->info);
		pthread_mutex_unlock(&arrays_info->mutex);
	}
	for (int i = 0 ; i < arrays_info->info.opt_trds_cnt; ++i)//ожидаем завершения всех потоков
		pthread_join(arrays_info->info.trds_arr[i], NULL);
	return arrays_info->info.exit_flag;
}
