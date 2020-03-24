#include "arrays.h"

int create_all_data_about_arrays(t_data **arrays_info, const int mode, const int type, const int size, const int fill_flag)
{
	*arrays_info = (t_data *)malloc(sizeof(t_data));
	if (!*arrays_info)
	{
		printf("Error! can't allocate memory for data struct!");
		return ERROR_IN_MEM_ALLOC;
	}
	(*arrays_info)->arr_A = ft_create_array(size);
	(*arrays_info)->arr_B = ft_create_array(size);
	if (!(*arrays_info)->arr_A || !(*arrays_info)->arr_B) //не выделилась память под массивы
		return ERROR_IN_MEM_ALLOC;
	(*arrays_info)->test_mode = mode;
	(*arrays_info)->trds_arr = NULL;
	(*arrays_info)->trd_info = NULL;
	(*arrays_info)->exit_flag = 0;
	(*arrays_info)->size = size;
	(*arrays_info)->opt_trds_cnt = 0;
	(*arrays_info)->fill_flag = fill_flag;
	if (type == MULTI_THREADS)
		return create_range_for_each_thread(*arrays_info);//создали распределенные участки для каждого потока в виде массива структур
	return 0;
}