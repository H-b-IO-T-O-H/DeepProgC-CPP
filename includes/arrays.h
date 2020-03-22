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
#define TEST_MODE 1

#define SINGLE_TREAD 0
#define MULTI_THREADS 1

#define USER_ERROR 1
#define ERROR_IN_MEM_ALLOC -1

typedef struct	s_info {
	pthread_t *trds_arr;
	int *distribution;
	int *arr_A;
	int *arr_B;
	int size;
	int pos;
	short fill_flag;
	short exit_flag;
	short opt_trds_cnt;
	short test_mode;
}		t_info;

typedef struct	s_data {
	pthread_mutex_t	mutex;
	t_info		info;
}		t_data;

//single_thread_app
void ft_fill_array(int *arr, int size, int fill_flag);
int	compare_arrays(t_data* arrays_info);
//multi_thread_app
void	*cmp_arrs(void *arg);
void	*single_thrd_fill(void *arg);
void fill_arrays_via_treads(t_data *arrays_info);
int create_threads(t_data *data);
int		compare_arrays_via_threads(t_data* arrays_info);
int create_range_for_each_thread(int **distr_array, t_data *arrays_info);
//utils
int	*ft_create_array(int size);
void	ft_print_array(const int *arr, const int size);
void free_all(t_data **arrays_info, int type);
int 	request_data(int argc, char **argv, int *size, int *flag_fill);
int create_all_data_about_arrays(t_data **arrays_info, const int mode, const int type, int size, int fill_flag);
#endif //DZ_2_LISTS_H
