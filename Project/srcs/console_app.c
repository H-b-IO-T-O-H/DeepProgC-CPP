#include "../include/buildings.h"

int main() {
	
	t_building *building;
	
	building = create_build_list(NULL);
	print_struct(building);
	free_struct(building);
	return 0;
}
