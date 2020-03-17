#include "../includes/arrays.h"

extern t_data data;

void fill_arrays_via_treads(pthread_t *trds, int opt_trds_cnt)
{
	for (int i = 0 ; i < opt_trds_cnt; ++i) //заполняем массив во все потоки
	{
		pthread_mutex_lock(&data.mutex);
		data.info.pos = i;
		pthread_create(&trds[i], NULL, single_thrd_fill, NULL);
	}
	for (int i = 0 ; i < opt_trds_cnt; ++i)//ожидаем завершения всех потоков
		pthread_join(trds[i], NULL);
}
