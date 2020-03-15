#include "../includes/lists.h"

t_list *ft_create_elem(int data)
{
	t_list *elem;
	
	elem = (t_list *)malloc(sizeof(t_list));
	if (elem) {
		elem->data = data;
		elem->next = NULL;
	}
	else
		printf("Can't create elem!\n");
	return (elem);
}

int ft_push_front(t_list **begin_list, int data)
{
	t_list *new_elem = NULL;
	static int pos = 0;
	
	if (!begin_list)
		return -1;
	++pos;
	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return 0;
	}
	new_elem = ft_create_elem(data);
	if (!new_elem)
		return (-1);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
	return 0;
}

void ft_fill_list(t_list **list, size_t size)
{
	for (int i = 0; i < size; ++i)
		if (!ft_push_front(list, i))
			{}
		else
		{
			printf("Error ! Can't create set size list!\n");
			return ;
		}
}
