#ifndef TECHNO_DZ1_2_BUILDINGS_H
#define TECHNO_DZ1_2_BUILDINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test.h"
#define TOTAL_HEIGHT 1
#define SPIRE_HEIGHT 2
#define FLOORS 3

typedef struct		s_height{
	short		floors_nmb;
	short		tot_height;
	short		spire_height;
	char		purpose;
	char 		location;
	struct s_height	*next;
}			t_height;

typedef struct		s_building {
	t_height 	*height;
	int		count;
}			t_building;

t_building*	create_build_list(t_unit_test *tes);
char		purpose_variants(int *test_flag);
char		location_variants(int *test_flag, int *test_flag2);
void		print_struct(const t_building *build);
void		free_struct(t_building *build);
#endif //TECHNO_DZ1_2_BUILDINGS_H
