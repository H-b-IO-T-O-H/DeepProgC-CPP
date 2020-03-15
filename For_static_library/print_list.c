#include "../includes/lists.h"

void ft_print_list(t_list *begin)
{
	t_list	*temp = begin;
	size_t	i = 0;
	
	if (!begin)
		return ;
	printf("indices: ");
	while(temp)
	{
		printf(" %zu", i++);
		temp = temp->next;
	}
	printf("\nelements:");
	while(begin)
	{
		printf(" %d", begin->data);
		begin = begin->next;
	}
	printf("\n");
}
