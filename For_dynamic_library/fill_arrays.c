#include "../includes/arrays.h"

void fill_arrays_via_treads(t_data *arrays_info)
{
	for (int i = 0 ; i < arrays_info->info.opt_trds_cnt; ++i) //заполняем массив во все потоки
	{
		pthread_mutex_lock(&arrays_info->mutex);
		arrays_info->info.pos = i;
		pthread_create(&arrays_info->info.trds_arr[i], NULL, single_thrd_fill, (void *)&arrays_info->info);
		pthread_mutex_unlock(&arrays_info->mutex);
	}
	for (int i = 0 ; i < arrays_info->info.opt_trds_cnt; ++i)//ожидаем завершения всех потоков
		pthread_join(arrays_info->info.trds_arr[i], NULL);
}
