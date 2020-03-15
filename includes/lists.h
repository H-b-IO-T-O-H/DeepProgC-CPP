#ifndef DZ_2_LISTS_H
#define DZ_2_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/sysinfo.h>

typedef struct	s_list
{
	int		data;
	struct	s_list *next;
}				t_list;

int		ft_push_front(t_list **begin_list, int data);
int 	compare_lists(t_list *list_A, t_list *list_B);
void 	ft_print_list(t_list *begin);
void 	ft_free_list(t_list **begin);
void 	ft_fill_list(t_list **list, size_t size);
void 	reverse_list(t_list **begin_list);

#endif //DZ_2_LISTS_H
