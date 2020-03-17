#include "../includes/arrays.h"

extern t_data data;

void mark_borders(int *start, int *end, int i) //определяем границы диапазонов потока исходя из значений массива распределения distribution
{
	int *distribution_array = data.info.distribution;
	
	if (i != 0) { //наиболее вероятный исход в целях оптимизации помещен в прямую ветку
		*start = distribution_array[i] + 1;
		*end = *start - 1 + distribution_array[0];
	}
	else {
		*start = 0;
		*end = distribution_array[1];
	}
	if (*end == data.info.size)
		*end -= 1;
}

void *single_thrd_fill(void *arg)
{
	int i = data.info.pos;
	pthread_mutex_unlock(&data.mutex);
	int *arr_A = data.info.arr_A;
	int *arr_B = data.info.arr_B;
	int start;
	int end;
	
	mark_borders(&start, &end, i);
	if (data.info.fill_flag == 1) {
		for (i = start; i <= end; ++i) {
			arr_A[i] = i;//код в ветвях повторяется но один цикл будет работать быстрее, чем два последовательных
			arr_B[i] = i;
		}
	} else {
		for (i = start; i <= end; ++i) {
			arr_A[i] = i;
			arr_B[i] = data.info.size - i - 1;
		}
	}
	return NULL;
}

void *cmp_arrs(void *arg)
{
	int i = data.info.pos;
	pthread_mutex_unlock(&data.mutex);
	int *arr_A = data.info.arr_A;
	int *arr_B = data.info.arr_B;
	int start;
	int end;
	
	if (!data.info.exit_flag)
		return NULL;
	mark_borders(&start, &end, i);
	for (i = start; i <= end; ++i) {
		if (!data.info.exit_flag)
			return NULL;
		if (arr_A[i] != arr_B[data.info.size - i - 1])
		{
			data.info.exit_flag = 0;
			break ;
		}
	}
	return NULL;
}
