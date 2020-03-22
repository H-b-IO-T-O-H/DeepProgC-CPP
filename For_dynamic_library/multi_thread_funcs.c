#include "../includes/arrays.h"

void mark_borders(const int *distribution_array, int *start, int *end, int i, int size) //определяем границы диапазонов потока исходя из значений массива распределения distribution
{
	if (i != 0) { //наиболее вероятный исход в целях оптимизации помещен в прямую ветку
		*start = distribution_array[i] + 1;
		*end = *start - 1 + distribution_array[0];
	}
	else {
		*start = 0;
		*end = distribution_array[1];
	}
	if (*end == size)
		*end -= 1;
}

void *single_thrd_fill(void *arg)
{
	t_info *info = (t_info *)arg;
	int i = info->pos;
	int *arr_A =  info->arr_A;
	int *arr_B =  info->arr_B;
	int start;
	int end;
	
	mark_borders(info->distribution, &start, &end, i, info->size);
	if (info->fill_flag == 1) {
		for (i = start; i <= end; ++i) {
			arr_A[i] = i;//код в ветвях повторяется но один цикл будет работать быстрее, чем два последовательных
			arr_B[i] = i;
		}
	} else {
		for (i = start; i <= end; ++i) {
			arr_A[i] = i;
			arr_B[i] = info->size - i - 1;
		}
	}
	return NULL;
}

void *cmp_arrs(void *arg)
{
	t_info *info = (t_info *)arg;
	int i = info->pos;
	int *arr_A =  info->arr_A;
	int *arr_B =  info->arr_B;
	int start;
	int end;
	
	if (!info->exit_flag)
		return NULL;
	mark_borders(info->distribution, &start, &end, i, info->size);
	for (i = start; i <= end; ++i) {
		if (!info->exit_flag)
			return NULL;
		if (arr_A[i] != arr_B[info->size - i - 1])
		{
			info->exit_flag = 0;
			break ;
		}
	}
	return NULL;
}
