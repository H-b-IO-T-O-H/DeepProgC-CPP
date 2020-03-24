/*
Условие ИЗ №2:
В вашем распоряжении — два вектора из 100 млн. чисел каждый. Определите, является ли один из них точной копией другого, записанной в обратном порядке.
 Составьте наивный алгоритм решения задачи, а затем реализуйте параллельный алгоритм с использованием нескольких процессов с учетом оптимизации работы с кэш-памятью.
 */
#include "../includes/arrays.h"

int main(int argc, char **argv) {
	
	t_data *arrays_info;
	int	fill_flag = 0;
	int size = 0;
	
	if (request_data(argc, argv, &size, &fill_flag)) //пользователь ввел неверные данные для заполнения
		return 0;
	if (create_all_data_about_arrays(&arrays_info,  USER_MODE,  SINGLE_TREAD, size, fill_flag) == ERROR_IN_MEM_ALLOC)
		return 0;
	ft_fill_array(arrays_info->arr_A, size, EQUAL);
	ft_fill_array(arrays_info->arr_B, size, fill_flag);
	if (compare_arrays(arrays_info) == EQUAL)
		printf("\033[032mArrays are equal.\033[039m\n");
	else
		printf("\033[031mArrays are not equal.\033[039m\n");
	free_all(&arrays_info, SINGLE_TREAD);
	return 0;
}
