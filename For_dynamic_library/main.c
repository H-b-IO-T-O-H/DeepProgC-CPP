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
	fill_arrays_via_treads(arrays_info);
	if (compare_arrays_via_threads(arrays_info) == EQUAL)
		printf("\033[032mArrays are equal.\033[039m\n");
	else
		printf("\033[031mArrays are not equal.\033[039m\n");
	free_all(&arrays_info, MULTI_THREADS);
	return 0;
}