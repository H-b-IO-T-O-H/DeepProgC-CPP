#ifndef TECHNO_DZ1_2_BUILDINGS_H
#define TECHNO_DZ1_2_BUILDINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define test_mode  1

typedef struct		s_height{
	short			floors_nmb;
	short			tot_height;
	short			spire_height;
	char			purpose;
	char 			location;
	struct s_height *next;
}					t_height;

typedef struct s_building {
	t_height 	*height;
	int			count;
} t_building;

typedef struct s_unit_test{
	
	short				total;
	short 				spire;
	short 				floors;
	int					purpose;
	int					loc1;
	int					loc2;
	char				build_add;
	struct s_unit_test	*next;
	}				t_unit_test;

t_building*	create_build_list(t_unit_test *test);
char		purpose_variants(int *test_flag);
char		location_variants(int *test_flag, int *test_flag2);
void		print_struct_and_free(t_building *build);
void		ft_check_one();
#endif //TECHNO_DZ1_2_BUILDINGS_H
