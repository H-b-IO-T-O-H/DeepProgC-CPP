#include "../includes/lists.h"

int compare_lists(t_list *list_A, t_list *list_B)
{
	t_list *elem_a = list_A;
	t_list *elem_b = list_B;
	
	while(elem_a && elem_b)
	{
		if (elem_a->data != elem_b->data)
			return 0;
		elem_a = elem_a->next;
		elem_b = elem_b->next;
	}
	if (elem_a || elem_b)
		return 0;
	return 1;
}