#ifndef TECHNO_DZ1_TEST_H
#define TECHNO_DZ1_TEST_H

typedef struct		s_unit_test{
	short				total;
	short				spire;
	short				floors;
	int					purpose;
	int					loc1;
	int					loc2;
	char				build_add;
	struct s_unit_test	*next;
}					t_unit_test;

void ft_check_one();
#endif //TECHNO_DZ1_TEST_H
