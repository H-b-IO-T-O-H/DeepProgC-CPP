#include "../includes/lists.h"

void ft_free_list(t_list **begin)
{
	t_list *temp;
	
	if (!begin || !*begin)
		return ;
	while(*begin)
	{
		temp = (*begin)->next;
		free(*begin);
		*begin = temp;
	}
}
