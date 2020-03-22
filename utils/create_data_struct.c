#include "arrays.h"

int create_all_data_about_arrays(t_data **arrays_info, const int mode, const int type, const int size, const int fill_flag)
{
	*arrays_info = (t_data *)malloc(sizeof(t_data));
	if (!*arrays_info)
	{
		printf("Error! can't allocate memory for data struct!");
		return ERROR_IN_MEM_ALLOC;
	}
	(*arrays_info)->info.arr_A = ft_create_array(size);
	(*arrays_info)->info.arr_B = ft_create_array(size);
	if (!(*arrays_info)->info.arr_A || !(*arrays_info)->info.arr_B) //не выделилась память под массивы
		return ERROR_IN_MEM_ALLOC;
	(*arrays_info)->info.test_mode = mode;
	(*arrays_info)->info.trds_arr = NULL;
	(*arrays_info)->info.distribution = NULL;
	(*arrays_info)->info.pos = 0;
	(*arrays_info)->info.exit_flag = 0;
	(*arrays_info)->info.size = size;
	(*arrays_info)->info.opt_trds_cnt = 0;
	(*arrays_info)->info.fill_flag = fill_flag;
	if (type == MULTI_THREADS)
	{
		pthread_mutex_init(&(*arrays_info)->mutex, NULL);
		if (((*arrays_info)->info.opt_trds_cnt  = create_range_for_each_thread(&(*arrays_info)->info.distribution, *arrays_info)) == ERROR_IN_MEM_ALLOC)//создали распределенные участки для каждого потока, которые указаны в виде индексов в массиве distribution
			return ERROR_IN_MEM_ALLOC;
		if (!((*arrays_info)->info.trds_arr = (pthread_t *)malloc(sizeof(pthread_t) * (*arrays_info)->info.opt_trds_cnt))) //создали массив потоков
			return  ERROR_IN_MEM_ALLOC;
	}
	return 1;
}