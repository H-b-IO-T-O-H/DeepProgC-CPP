#include "arrays.h"

int create_range_for_each_thread(t_data *arrays_info)
{
	int *distribution_array;
	
	arrays_info->info.opt_trds_cnt = get_nprocs() * 2;
	int step = arrays_info->info.size / arrays_info->info.opt_trds_cnt;// разбиваем весь диапазон на поддиапазоны
	distribution_array = (int *)malloc(sizeof(int) * arrays_info->info.opt_trds_cnt);
	if (!distribution_array)
	{
		printf("Error! Can't allocate region for distribution array.\n");
		return ERROR_IN_MEM_ALLOC;
	}
	distribution_array[0] = step;//в нулевом элементе содержится шаг, чтобы функция распределения могла выделить нужный диапазон под каждый поток
	distribution_array[1] = step + (arrays_info->info.size - step * arrays_info->info.opt_trds_cnt); //первый поток получает чуть больше работы из-за округления индексов при делении.
	int j = distribution_array[1];
	if (arrays_info->info.opt_trds_cnt <= 1 && arrays_info->info.test_mode != TEST_MODE)
		printf("Multi thread app will not get advantage on your system!\n");
	if (arrays_info->info.size < REQUIRED_SIZE && arrays_info->info.test_mode != TEST_MODE)
		printf("Multi thread app will be not so efficient. Array size too little!\n Single thread app recommended...\n");
	for (int i = 2; i < arrays_info->info.opt_trds_cnt; i++)
	{
		j += step;
		distribution_array[i] = j;
	}
	arrays_info->info.distribution = distribution_array;
	return arrays_info->info.opt_trds_cnt;
}