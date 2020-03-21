#ifndef DZ_2_LISTS_H
#define DZ_2_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/sysinfo.h>

#define MAX_SIZE 300000000
#define REQUIRED_SIZE 10000
#define EQUAL 1
#define NOT_EQUAL 0
#define USER_MODE 0
#define USER_ERROR 1
#define ERROR_IN_MEM_ALLOC -1

typedef struct	s_info {
	int *arr_A;
	int *arr_B;
	int *distribution;
	int fill_flag;
	int exit_flag;
	int size;
	int pos;
	int test_mode;
}		t_info;

typedef struct	s_data {
	pthread_mutex_t	mutex;
	t_info		info;
}		t_data;

//single_thread_app
int	*ft_fill_array(int size, int fill_flag);
int	compare_arrays(const int *array_A,
		       const int *array_B, const int size);
//multi_thread_app
void	*cmp_arrs(void *arg);
void	*single_thrd_fill(void *arg);
void	fill_arrays_via_treads(pthread_t *trds, int opt_trds_cnt);
int	create_threads_and_cmp(int *array_A, int *array_B,	
			       int size, int fill_flag);
int	compare_arrays_via_threads(const int *array_A, const int *array_B,
				   pthread_t *trds, int opt_trds_cnt);
//utils
int	*ft_create_array(int size);
void	ft_print_array(const int *arr, const int size);
void	free_all(int *array_A, int *array_B,
		 int *distribution, pthread_mutex_t *mutex);
int 	request_data(int argc, char **argv, int *size, int *flag_fill);

#endif //DZ_2_LISTS_H
