#include "../includes/arrays.h"

void *single_thrd_fill(void *arg)
{
	t_for_thrd *info = (t_for_thrd *)arg;
	int *arr_A =  info->arr_A;
	int *arr_B =  info->arr_B;
	int start = info->start;
	int end = info->end;
	
	if (info->fill_flag == 1) {
		for (int i = start; i < end; ++i) {
			arr_A[i] = i;//код в ветвях повторяется но один цикл будет работать быстрее, чем два последовательных
			arr_B[i] = i;
		}
	} else {
		for (int i = start; i < end; ++i) {
			arr_A[i] = i;
			arr_B[i] = info->size - i - 1;
		}
	}
	return NULL;
}

void *cmp_arrs(void *arg)
{
	t_for_thrd *info = (t_for_thrd *)arg;
	int *arr_A =  info->arr_A;
	int *arr_B =  info->arr_B;
	
	if (*info->exit_flag == 0)//если в других потоках обнаружили, что листы не равны
		return NULL;
	for (int i = info->start; i < info->end; ++i) {
		if (*info->exit_flag == 0)
			return NULL;
		if (arr_A[i] != arr_B[info->size - i - 1])
		{
			*info->exit_flag = 0;
			break ;
		}
	}
	return NULL;
}
