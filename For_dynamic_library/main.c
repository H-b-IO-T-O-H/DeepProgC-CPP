/* Многопоточный вариант*/
#include "../includes/arrays.h"

int main(int argc, char **argv) {
	
	t_data *arrays_info;
	int	fill_flag = 0;
	int size = 0;
	
	if (request_data(argc, argv, &size, &fill_flag))
		return 0;
	if (create_all_data_about_arrays(&arrays_info, USER_MODE, MULTI_THREADS, size, fill_flag) == ERROR_IN_MEM_ALLOC)
		return 0;
	if (fill_arrays_via_treads(arrays_info)) //ошибка в создании потока или же в его ожидании
	{
		free_all(&arrays_info, MULTI_THREADS);
		return 0;
	}
	if (compare_arrays_via_threads(arrays_info) == EQUAL)
		printf("\033[032mArrays are equal.\033[039m\n");
	else if (arrays_info->exit_flag == 0)
		printf("\033[031mArrays are not equal.\033[039m\n");
	free_all(&arrays_info, MULTI_THREADS);
	return 0;
}