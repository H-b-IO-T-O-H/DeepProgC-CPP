#include "../include/buildings.h"

t_unit_test test1 = {
		.purpose = 1,
		.loc1 = 1,
		.loc2 = 1,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
		.next = NULL
};

t_height ans1 = {
		.purpose = '1',
		.location = 'a',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test2 = {
		.purpose = 2,
		.loc1 = 2,
		.loc2 = 1,
		.floors = 1,
		.spire = 2,
		.total = 3,
		.build_add = 'n',
		.next = &test1
};

t_height ans2 = {
		.purpose = '2',
		.location = 'b',
		.floors_nmb = 1,
		.spire_height = 2,
		.tot_height = 3,
};

t_unit_test test3 = {
		.purpose = 3,
		.loc1 = 4,
		.loc2 = 1,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
		.next = &test2
};

t_height ans3 = {
		.purpose = '3',
		.location = 'c',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test4 = {
		.purpose = 4,
		.loc1 = 5,
		.loc2 = 1,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
		.next = &test3
};

t_height ans4 = {
		.purpose = '4',
		.location = 'd',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test5 = {
		.purpose = 5,
		.loc1 = 3,
		.loc2 = 1,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
		.next = &test4
};

t_height ans5 = {
		.purpose = '5',
		.location = 'e',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};


t_unit_test test6 = {
		.purpose = 6,
		.loc1 = 1,
		.loc2 = 2,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
		.next = &test5
};

t_height ans6 = {
		.purpose = '6',
		.location = 'f',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test7 = {
		.purpose = 1,
		.loc1 = 2,
		.loc2 = 2,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
		.next = &test6
};

t_height ans7 = {
		.purpose = '1',
		.location = 'g',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test8 = {
		.purpose = 1,
		.loc1 = 4,
		.loc2 = 2,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
		.next = &test7
};

t_height ans8 = {
		.purpose = '1',
		.location = 'h',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test9 = {
		.purpose = 1,
		.loc1 = 5,
		.loc2 = 2,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
		.next = &test8
};

t_height ans9 = {
		.purpose = '1',
		.location = 'i',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};


t_unit_test test10 = {
		.purpose = 1,
		.loc1 = 3,
		.loc2 = 2,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans10 = {
		.purpose = '1',
		.location = 'j',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test11 = {
		.purpose = 1,
		.loc1 = 1,
		.loc2 = 3,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans11 = {
		.purpose = '1',
		.location = 'k',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test12 = {
		.purpose = 1,
		.loc1 = 2,
		.loc2 = 3,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans12 = {
		.purpose = '1',
		.location = 'l',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test13 = {
		.purpose = 1,
		.loc1 = 4,
		.loc2 = 3,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans13 = {
		.purpose = '1',
		.location = 'm',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test14 = {
		.purpose = 1,
		.loc1 = 5,
		.loc2 = 3,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans14 = {
		.purpose = '1',
		.location = 'n',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test15 = {
		.purpose = 1,
		.loc1 = 3,
		.loc2 = 3,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans15 = {
		.purpose = '1',
		.location = 'o',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test16 = {
		.purpose = 1,
		.loc1 = 1,
		.loc2 = 4,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans16 = {
		.purpose = '1',
		.location = 'p',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test17 = {
		.purpose = 1,
		.loc1 = 2,
		.loc2 = 4,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans17 = {
		.purpose = '1',
		.location = 'q',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test18 = {
		.purpose = 1,
		.loc1 = 4,
		.loc2 = 4,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans18 = {
		.purpose = '1',
		.location = 'r',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test19 = {
		.purpose = 1,
		.loc1 = 5,
		.loc2 = 4,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans19 = {
		.purpose = '1',
		.location = 's',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test20 = {
		.purpose = 1,
		.loc1 = 3,
		.loc2 = 4,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans20 = {
		.purpose = '1',
		.location = 't',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test21 = {
		.purpose = 1,
		.loc1 = 2,
		.loc2 = 5,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans21 = {
		.purpose = '1',
		.location = 'u',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test22 = {
		.purpose = 1,
		.loc1 = 3,
		.loc2 = 5,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans22 = {
		.purpose = '1',
		.location = 'v',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test23 = {
		.purpose = 1,
		.loc1 = 3,
		.loc2 = 6,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans23 = {
		.purpose = '1',
		.location = 'w',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test_with_error1 = {
		.purpose = 1,
		.loc1 = 1,
		.loc2 = 1,
		.floors = -1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans_e_1 = {
		.purpose = '1',
		.location = 'a',
		.floors_nmb = 100,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test_with_error2 = {
		.purpose = 1,
		.loc1 = 1,
		.loc2 = 1,
		.floors = 1,
		.spire = -1,
		.total = 1,
		.build_add = 'n',
};

t_height ans_e_2 = {
		.purpose = '1',
		.location = 'a',
		.floors_nmb = 1,
		.spire_height = 100,
		.tot_height = 1,
};

t_unit_test test_with_error3 = {
		.purpose = 1,
		.loc1 = 1,
		.loc2 = 1,
		.floors = 1,
		.spire = 1,
		.total = -1,
		.build_add = 'n',
};

t_height ans_e_3 = {
		.purpose = '1',
		.location = 'a',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 100,
};

t_unit_test test_with_error4 = {
		.purpose = 9,
		.loc1 = 1,
		.loc2 = 1,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans_e_4 = {
		.purpose = '1',
		.location = 'a',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test_with_error5 = {
		.purpose = 1,
		.loc1 = 9,
		.loc2 = 1,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans_e_5 = {
		.purpose = '1',
		.location = 'a',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

t_unit_test test_with_error6 = {
		.purpose = 1,
		.loc1 = 1,
		.loc2 = 9,
		.floors = 1,
		.spire = 1,
		.total = 1,
		.build_add = 'n',
};

t_height ans_e_6 = {
		.purpose = '1',
		.location = 'a',
		.floors_nmb = 1,
		.spire_height = 1,
		.tot_height = 1,
};

int cmp_not_create(t_height *height, t_height ans) {
	if (height->purpose == ans.purpose && height->location == ans.location &&
		height->tot_height == ans.tot_height && height->floors_nmb == ans.floors_nmb
		&& height->spire_height == ans.spire_height) {
		return (0);
	}
	return (1);
}

int cmp_structs(t_unit_test *test, t_height ans) {
	t_building *build;
	t_height *height;
	
	build = create_build_list(test);
	if (!build)
		return (-1);
	height = build->height;
	if (cmp_not_create(height, ans) == 0) {
		print_struct(build);
		free_struct(build);
		return (0);
	}
	return (1);
}

int cmp_sort_lists() {
	t_building *build;
	t_height *temp;
	t_height array_of_tests[] = {
			ans1, ans7, ans8, ans9, ans2,
			ans3, ans4, ans5, ans6,
	};
	int i = -1;
	
	test1.build_add = 'n';
	test2.build_add = 'y';
	test3.build_add = 'y';
	test4.build_add = 'y';
	test5.build_add = 'y';
	test6.build_add = 'y';
	test7.build_add = 'y';
	test8.build_add = 'y';
	test9.build_add = 'y';
	build = create_build_list(&test9);
	if (!build)
		return (-1);
	temp = build->height;
	while (++i < 9) {
		if (cmp_not_create(build->height, array_of_tests[i]))
			return (1);
		build->height = build->height->next;
	}
	build->height = temp;
	print_struct(build);
	free_struct(build);
	return (0);
}

void ft_check_one() {
	int i = -1;
	int size = 29;
	t_unit_test tests[] = {
			test1, test2, test3, test4, test5, test6, test7, test8, test9, test10,
			test11, test12, test13, test14, test15, test16, test17, test18, test19,
			test20, test21, test22, test23, test_with_error1, test_with_error2,
			test_with_error3, test_with_error4, test_with_error5, test_with_error6
	};
	t_height ans[] = {
			ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8, ans9, ans10,
			ans11, ans12, ans13, ans14, ans15, ans16, ans17, ans18, ans19,
			ans20, ans21, ans22, ans23, ans_e_1, ans_e_2, ans_e_3, ans_e_4, ans_e_5, ans_e_6
	};
	
	printf("              Simple tests:\n");
	while (++i < size) {
		assert(cmp_structs(&tests[i], ans[i]) == 0);
		printf("test № %d          OK!\n", i + 1);
	}
	printf("\n\n\n     Difficult test with sort struct:\n");
	assert(cmp_sort_lists() == 0);
	printf("Difficult test № %d          OK!\n", i + 1);
}