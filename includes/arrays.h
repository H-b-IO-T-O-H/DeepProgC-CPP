#ifndef DZ_2_LISTS_H
#define DZ_2_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/sysinfo.h>

int		*ft_create_array(int size);
int		*ft_fill_array(int size, int fill_flag);
int 	compare_arrays(const int *array_A, const int size_A,
						const int *array_B, const int size_B);
void	ft_print_array(const int *arr, const int size);

#endif //DZ_2_LISTS_H
