#include "../include/buildings.h"

char purpose_variants(int *test_flag)
{
	int n = 0;
	static char c = '0';
	
	if (!*test_flag) {
		printf("Purpose variants:\n");
		printf("1 - office,\n2 - hotel,\n3 - residental,\n4 - shopping centre,\n5 - industrial,\n6 - leisure building.\n");
		printf("Enter the appropriate number.\n");
		scanf("%1d", &n);
		while (getchar() != '\n');
	}
	else
		n = *test_flag;
	switch (n)
	{
		case -1:
			break;
		case 1:
			c = '1';
			break;
		case 2:
			c = '2';
			break;
		case 3:
			c = '3';
			break;
		case 4:
			c = '4';
			break;
		case 5:
			c = '5';
			break;
		case 6:
			c = '6';
			break;
		default:
			printf("Error!:\nthere are no instructions for your input!\n");
			if (*test_flag)
			{
				printf("Erorr detected in test! Default variant - office(1)\n");
				*test_flag = 1;
			}
			purpose_variants(test_flag);
			n = 1;
			break;
	}
	return (c);
}