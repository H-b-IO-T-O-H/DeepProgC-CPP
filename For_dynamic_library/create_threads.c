#include "../includes/arrays.h"

extern t_data data;

int create_range_for_each_thread(int **distr_array)
{
	int opt_trds_cnt = get_nprocs() * 2 - 1; // -1 так как один поток на main по дефолту
	int step = data.info.size / opt_trds_cnt;// разбиваем весь диапазон на поддиапазоны
	int *distribution_array;
	
	distribution_array = (int *)malloc(sizeof(int) * opt_trds_cnt);
	if (!distribution_array)
	{
		printf("Error! Can't allocate region for distribution array.\n");
		return (-1);
	}
	distribution_array[0] = step;//в нулевом элементе содержится шаг, чтобы функция распределения могла выделить нужный диапазон под каждый поток
	distribution_array[1] = step + (data.info.size - step * opt_trds_cnt); //первый поток получает чуть больше работы из-за округления индексов при делении.
	int j = distribution_array[1];
	if (opt_trds_cnt <= 1)
		printf("Multi thread app will not get advantage on your system!\n");
	if (data.info.size < 1000 && !data.info.test_mode)
		printf("Multi thread app will be not so efficient. Array size too little!\n Single thread app recommended...\n");
	for (int i = 2; i < opt_trds_cnt; i++)
	{
		j += step;
		distribution_array[i] = j;
	}
	*distr_array = distribution_array;
	return opt_trds_cnt;
}

int create_threads_and_cmp(int *array_A, int *array_B, int size, int fill_flag)
{
	int opt_trds_cnt;
	
	data.info.size = size;
	data.info.fill_flag = fill_flag;
	data.info.arr_A = array_A;
	data.info.arr_B = array_B;
	opt_trds_cnt = create_range_for_each_thread(&data.info.distribution);//создали распределенные участки для каждого потока, которые указаны в виде индексов в массиве distribution
	if (opt_trds_cnt == -1)
		return (-1);
	pthread_t trds[opt_trds_cnt]; //благодаря указанию участков нет нужды в использовании мьютексы, т.к. все потоки работают в своем адресном пространстве
	fill_arrays_via_treads(trds, opt_trds_cnt);
	if (data.info.test_mode != 0) //нужно для проверки функциональности приложения в режиме тестирования
		array_A[data.info.test_mode] = -1;
	return compare_arrays_via_threads(array_A, array_B, trds, opt_trds_cnt);
}
