/*
Условие ИЗ №2:
В вашем распоряжении — два вектора из 100 млн. чисел каждый. Определите, является ли один из них точной копией другого, записанной в обратном порядке.
 Составьте наивный алгоритм решения задачи, а затем реализуйте параллельный алгоритм с использованием нескольких процессов с учетом оптимизации работы с кэш-памятью.
 */
#include "../includes/lists.h"

int main(int argc, char **argv) {
	
	t_list	*list_A = NULL;
	t_list	*list_B = NULL;
	int		flag_fill = 0;
	int		size_A = 0;
	int		size_B = 0;
	
	if (argc != 4 || (flag_fill = atoi(argv[3])) > 3 || (flag_fill < -1)) {
		printf("\033[031mError! Wrong number or values of arguments!\033[032m\nUsage:\033[039m./dz_2 size of list_A, size of list_B, fill flag. Max size of each list: ~ 100 000 000\n");
		printf("fill flag =  0 - list_A = [0; size_A], list_B = [0; size_B]\n");
		printf("fill flag = -1 - list_A = [0; size_A], list_B = [size_B; 0] - list B reversed\n");
		return 0;
	}
	ft_fill_list(&list_A, size_A);
	ft_fill_list(&list_B, size_B);
	if (compare_lists(list_A, list_B) == 1)
		printf("\033[032mLists are equal.\033[039m\n");
	else
		printf("\033[031mLists are not equal.\033[039m\n");
	ft_free_list(&list_A);
	ft_free_list(&list_B);
	return 0;
}
