#include "../include/buildings.h"

void check_user_input(int flag, short *data, short *test_flag) {
	if (!*test_flag) {
		flag == 1 ? printf("Input total building height:\n") : 0;
		flag == 2 ? printf("Input spire height:\n") : 0;
		flag == 3 ? printf("Input floors numb:\n") : 0;
		scanf("%1hd", data);
		while (getchar() != '\n');
	} else
		*data = *test_flag;
	if (*data <= 0) {
		printf("Error! Value can't be negative or more than 32767!\n");
		if (*test_flag) {
			printf("Erorr detected in test! Default variant 100\n");
			*test_flag = 100;
		}
		check_user_input(flag, data, test_flag);
	}
}

t_height *fill_for_test(t_height *elem, t_unit_test *test) {
	elem->purpose = purpose_variants(&test->purpose);
	elem->location = location_variants(&test->loc1, &test->loc2);
	check_user_input(1, &elem->tot_height, &test->total);
	check_user_input(2, &elem->spire_height, &test->spire);
	check_user_input(3, &elem->floors_nmb, &test->floors);
	elem->next = NULL;
	return (elem);
}

t_height *ft_create_elem(t_unit_test *test) {
	int for_loc_pur = 0;
	short for_height = 0;
	
	t_height *elem;
	elem = (t_height *) malloc(sizeof(t_height));
	if (!elem)
		return (NULL);
	if (test)
		return (fill_for_test(elem, test));
	elem->purpose = purpose_variants(&for_loc_pur);
	elem->location = location_variants(&for_loc_pur, &for_loc_pur);
	check_user_input(1, &elem->tot_height, &for_height);
	check_user_input(2, &elem->spire_height, &for_height);
	check_user_input(3, &elem->floors_nmb, &for_height);
	elem->next = NULL;
	return (elem);
}

int height_create_elem(t_height **begin, t_unit_test *test) {
	t_height *prev;
	t_height *curr;
	t_height *temp;
	
	if (!*begin) {
		*begin = ft_create_elem(test);
		if (!*begin)
			return (-1);
		return (0);
	}
	curr = ft_create_elem(test);
	if (!curr)
		return (-1);
	prev = *begin;
	temp = curr;
	while (prev) {
		if (curr->purpose < prev->purpose || (curr->purpose == prev->purpose && curr->location < prev->location)) {
			if (prev != *begin) {
				temp->next = curr;
				curr->next = prev;
			} else {
				temp = *begin;
				*begin = curr;
				curr->next = temp;
			}
			return (0);
		}
		if (!prev->next) {
			prev->next = curr;
			return (0);
		}
		temp = prev;
		prev = prev->next;
	}
	return (0);
}

void get_info_about_blds(t_building *build_list, t_unit_test *test) {
	static t_height *height = NULL;
	static char c = '0';
	
	if (height_create_elem(&height, test) == -1) {
		printf("Error! Can't allocate region for building № %d!\n", build_list->count);
		print_struct_and_free(build_list);
		return;
	}
	if (!test) {
		printf("Enter new building?\ny or n\n");
		scanf("%c", &c);
		while (getchar() != '\n');
	} else {
		c = test->build_add;
		if (c == 'y' && test->next) {
			test = test->next;
		}
	}
	if (c == 'y') {
		build_list->count++;
		get_info_about_blds(build_list, test);
	} else {
		build_list->height = height;
		height = NULL;
	}
}

t_building *create_build_list(t_unit_test *test) {
	t_building *build_list = NULL;
	
	build_list = (t_building *) malloc(sizeof(t_building));
	if (!build_list) {
		printf("Error! Can't allocate region for main buildings struct!\n");
		return (NULL);
	}
	build_list->count = 1;
	get_info_about_blds(build_list, test);
	return (build_list);
}