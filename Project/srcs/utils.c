#include "../include/buildings.h"

void convert_purp_loc(char purp, char loc)
{
	printf("purpose : ");
	if (purp == '1')
		printf("office\n");
	else if (purp == '2')
		printf("hotel\n");
	else if (purp == '3')
		printf("residental\n");
	else if (purp == '4')
		printf("shopping centre\n");
	else if (purp == '5')
		printf("industrial\n");
	else
		printf("leisure building\n");
	printf("location : ");
	if (loc == 'a')
		printf("West Europe\n");
	else if (loc == 'b')
		printf("West Africa\n");
	else if (loc == 'c')
		printf("West America\n");
	else if (loc == 'd')
		printf("Australia\n");
	else if (loc == 'e')
		printf("West Asia\n");
	else if (loc == 'f')
		printf("East Europe\n");
	else if (loc == 'g')
		printf("East Africa\n");
	else if (loc == 'h')
		printf("Caribian America\n");
	else if (loc == 'i')
		printf("Melanesia\n");
	else if (loc == 'j')
		printf("East Asia\n");
	else if (loc == 'k')
		printf("North Europe\n");
	else if (loc == 'l')
		printf("North Africa\n");
	else if (loc == 'm')
		printf("North America\n");
	else if (loc == 'n')
		printf("Micronesia\n");
	else if (loc == 'o')
		printf("North Asia\n");
	else if (loc == 'p')
		printf("South Europe\n");
	else if (loc == 'q')
		printf("South Africa\n");
	else if (loc == 'r')
		printf("South America\n");
	else if (loc == 's')
		printf("Polynesia\n");
	else if (loc == 't')
		printf("South Asia\n");
	else if (loc == 'u')
		printf("Central Africa\n");
	else if (loc == 'v')
		printf("Central Asia\n");
	else
		printf("South-East\n");
}

void print_struct(const t_building *build)
{
	int i = 0;
	t_height *temp = NULL;
	
	if (!build) {
		printf("No buildings!\n");
		return ;
	}
	temp = build->height;
	while(temp)
	{
		printf("______________Building № %d______________\n", i + 1);
		printf("Tot_height = %d, spire = %d, floors = %d\n",temp->tot_height, temp->spire_height, temp->floors_nmb);
		convert_purp_loc( temp->purpose, temp->location);
		temp = temp->next;
		++i;
	}
}

void free_struct(t_building *build)
{
	t_height *temp = NULL;
	
	if (!build)
		return ;
	while(build->height)
	{
		temp = build->height->next;
		free(build->height);
		build->height = temp;
	}
	free(build);
}