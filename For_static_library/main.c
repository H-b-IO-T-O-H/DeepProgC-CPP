/*
Условие ИЗ №2:
В вашем распоряжении — два вектора из 100 млн. чисел каждый. Определите, является ли один из них точной копией другого, записанной в обратном порядке.
 Составьте наивный алгоритм решения задачи, а затем реализуйте параллельный алгоритм с использованием нескольких процессов с учетом оптимизации работы с кэш-памятью.
 */
#include "../includes/arrays.h"

int main(int argc, char **argv) {
	
	int 	*array_A;
	int		*array_B;
	int		flag_fill = 0;
	int		size_A = 100000000;
	int		size_B = 100000000;
	
	/*if (argc != 4 || (flag_fill = atoi(argv[3])) != 0 && (flag_fill != -1)) {
		printf("\033[031mError! Wrong number or values of arguments!\033[032m\nUsage:\033[039m./dz_2 size of array_A, size of array_B, fill flag. Max size of each array: ~ 100 000 000\n");
		printf("fill flag =  0 - array_A = [0; size_A], array_B = [0; size_B]\n");
		printf("fill flag = -1 - array_A = [0; size_A], array_B = [size_B; 0] - array B reversed\n");
		return 0;
	}*/
	array_A = ft_fill_array(size_A, flag_fill);
	array_B = ft_fill_array(size_B, flag_fill - 1);
	//ft_print_array(array_A, size_A);
	//ft_print_array(array_B, size_B);
	if (compare_arrays(array_A, size_A, array_B, size_B) == 1)
		printf("\033[032mArrays are equal.\033[039m\n");
	else
		printf("\033[031mArrays are not equal.\033[039m\n");
	free(array_A);
	free(array_B);
	return 0;
}
