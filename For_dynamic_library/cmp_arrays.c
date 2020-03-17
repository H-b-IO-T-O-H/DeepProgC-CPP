#include "../includes/arrays.h"

extern t_data data;

int compare_arrays_via_threads(const int *array_A, const int *array_B, pthread_t *trds, int opt_trds_cnt)
{
	data.info.exit_flag = 1;
	for (int i = 0 ; i < opt_trds_cnt; ++i)
	{
		pthread_mutex_lock(&data.mutex);
		data.info.pos = i;
		pthread_create(&trds[i], NULL, cmp_arrs, NULL);
	}
	for (int i = 0 ; i < opt_trds_cnt; ++i)//ожидаем завершения всех потоков
		pthread_join(trds[i], NULL);
	return data.info.exit_flag;
}
