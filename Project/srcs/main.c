#include "../include/buildings.h"

int main() {
	if (test_mode == 0) //set mode in buildings.h, default - test_mode
	{
		t_building *building;
		
		building = create_build_list(NULL);
		print_struct_and_free(building);
	}
	else
		ft_check_one();
	return 0;
}
