#include "arrays.h"

int create_range_for_each_thread(t_data *arrays_info)
{
	t_for_thrd *trd_info;
	int j = 0;
	
	arrays_info->opt_trds_cnt = get_nprocs() * 2;
	if (!(arrays_info->trds_arr = (pthread_t *)malloc(sizeof(pthread_t) * arrays_info->opt_trds_cnt))) //создали массив потоков
		return  ERROR_IN_MEM_ALLOC;
	trd_info = (t_for_thrd *)malloc(sizeof(t_for_thrd) * arrays_info->opt_trds_cnt); //создали массив аргументов
	int step = arrays_info->size / arrays_info->opt_trds_cnt;// разбиваем весь диапазон на поддиапазоны
	if (!trd_info)
	{
		printf("Error! Can't allocate region for distribution array.\n");
		return ERROR_IN_MEM_ALLOC;
	}
	if (arrays_info->opt_trds_cnt <= 1 && arrays_info->test_mode != TEST_MODE)
		printf("Multi thread app will not get advantage on your system!\n");
	if (arrays_info->size < REQUIRED_SIZE && arrays_info->test_mode != TEST_MODE)
		printf("Multi thread app will be not so efficient. Array size too little!\n Single thread app recommended...\n");
	for (int i = 0; i < arrays_info->opt_trds_cnt; ++i)
	{
		trd_info[i].arr_A = arrays_info->arr_A;
		trd_info[i].arr_B = arrays_info->arr_B;
		trd_info[i].size = arrays_info->size;
		trd_info[i].fill_flag = arrays_info->fill_flag;
		trd_info[i].exit_flag = &arrays_info->exit_flag;
		if (i != 1)
			trd_info[i].start = j;
		else {
			trd_info[1].start = step + (arrays_info->size - step * arrays_info->opt_trds_cnt);
			trd_info[0].start = 0;
			trd_info[0].end = trd_info[1].start;
			j = trd_info[1].start;
		}
		j += step;
		trd_info[i].end = j;
	}
	arrays_info->trd_info = trd_info;
	return 0;
}