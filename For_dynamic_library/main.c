/* Многопоточный вариант*/
#include "../includes/arrays.h"

t_data data = {PTHREAD_MUTEX_INITIALIZER,
				 NULL, NULL,NULL,
				 0,0, 0 , 0,
				 0};

int main(int argc, char **argv) {
	
	int	*array_A = NULL;
	int	*array_B = NULL;
	int	fill_flag = 0;
	int res = 0;
	int size = 0;
	
	data.info.test_mode = 0;
	if (request_data(argc, argv, &size, &fill_flag))
		return 0;
	array_A = ft_create_array(size);
	array_B = ft_create_array(size);
	if (!array_A || !array_B) //не выделилась память под массивы
		return 0;
	if ((res = create_threads_and_cmp(array_A, array_B, size, fill_flag)) == 1)
		printf("\033[032mArrays are equal.\033[039m\n");
	else if (res == 0)
		printf("\033[031mArrays are not equal.\033[039m\n");
	free_all(array_A, array_B, data.info.distribution, &data.mutex);
	return 0;
}