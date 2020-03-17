#include "../includes/arrays.h"

void free_all(int *array_A, int *array_B, int *distribution, pthread_mutex_t *mutex)
{
	if (array_A)
		free(array_A);
	if (array_B)
		free(array_B);
	if (distribution)
		free(distribution);
	if (mutex)
		pthread_mutex_destroy(mutex);
}