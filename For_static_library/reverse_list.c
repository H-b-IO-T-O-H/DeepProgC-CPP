#include "../includes/lists.h"

void reverse_list(t_list **begin_list)
{
	t_list *elem, *temp, *next;
	
	elem = *begin_list;
	while(elem->next)
	{
		next = elem->next;
		temp = next->next;
		next->next = *begin_list;
		elem->next = temp;
		*begin_list = next;
	}
}