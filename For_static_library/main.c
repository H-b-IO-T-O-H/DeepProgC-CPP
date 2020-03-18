/*
Условие ИЗ №2:
В вашем распоряжении — два вектора из 100 млн. чисел каждый. Определите, является ли один из них точной копией другого, записанной в обратном порядке.
 Составьте наивный алгоритм решения задачи, а затем реализуйте параллельный алгоритм с использованием нескольких процессов с учетом оптимизации работы с кэш-памятью.
 */
#include "../includes/arrays.h"

int main(int argc, char **argv) {
	
	int	*array_A = NULL;
	int	*array_B = NULL;
	int	flag_fill = 0;
	int size = 0;
	
	if (request_data(argc, argv, &size, &flag_fill)) //пользователь ввел неверные данные для заполнения
		return 0;
	array_A = ft_fill_array(size, EQUAL);
	array_B = ft_fill_array(size, flag_fill);
	if (!array_A || !array_B) //не выделилась память под массивы
		return 0;
	if (compare_arrays(array_A, array_B, size) == EQUAL)
		printf("\033[032mArrays are equal.\033[039m\n");
	else
		printf("\033[031mArrays are not equal.\033[039m\n");
	free_all(array_A, array_B, NULL, NULL);
	return 0;
}
