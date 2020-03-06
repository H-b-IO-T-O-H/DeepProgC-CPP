#include "../include/buildings.h"

char	var_Continents(int flag, int *test_flag2)
{
	int n;
	int error = 0;
	static char c = '0';
	
	if (!*test_flag2)
	{
		printf("Enter the appropriate number.\n");
		if (flag == 1 || flag == 2 || flag == 3)
			printf("1 - West,\n2 - East,\n3 - North,\n4 - South\n");
		if (flag == 2)
			printf("5 - Central\n");
		if (flag == 3)
			printf("5 - Central,\n6 - South-East\n");
		if (flag == 4)
			printf("1 - Central,\n2 - Caribian,\n3 - North,\n4 - South.\n");
		if (flag == 5)
			printf("1 - Australia,\n2 - Melanesia,\n3 - Micronesia,\n4 - Polynesia\n");
		scanf("%d", &n);
		while (getchar() != '\n');
	}
	else
		n = *test_flag2;
	switch (n)
	{
		case -1:
			break;
		case 1:
			if (flag == 1)
				c ='a';
			else if (flag == 2)
				c ='b';
			else if (flag == 4)
				c ='c';
			else if (flag == 5)
				c ='d';
			else if (flag == 3)
				c ='e';
			else
				error = 1;
			break;
		case 2:
			if (flag == 1)
				c ='f';
			else if (flag == 2)
				c ='g';
			else if (flag == 4)
				c ='h';
			else if (flag == 5)
				c ='i';
			else if (flag == 3)
				c ='j';
			else
				error = 1;
			break;
		case 3:
			if (flag == 1)
				c ='k';
			else if (flag == 2)
				c ='l';
			else if (flag == 4)
				c ='m';
			else if (flag == 5)
				c ='n';
			else if (flag == 3)
				c ='o';
			else
				error = 1;
			break;
		case 4:
			if (flag == 1)
				c ='p';
			else if (flag == 2)
				c ='q';
			else if (flag == 4)
				c ='r';
			else if (flag == 5)
				c ='s';
			else if (flag == 3)
				c ='t';
			else
				error = 1;
			break;
		case 5:
			if (flag == 2)
				c ='u';
			else if (flag == 3)
				c ='v';
			else
				error = 1;
			break;
		case 6:
			if (flag == 3)
				c ='w';
			else
				error = 1;
			break;
		default:
			error = 1;
			break;
	}
	if (error)
	{
		if (*test_flag2)
		{
			printf("Erorr detected in test! Default variant - West\n");
			*test_flag2 = 1;
		}
		printf("Error!:\nthere are no instructions for your input!\nRepeat input!\n");
		location_variants(test_flag2, test_flag2);
	}
	return c;
}

char location_variants(int *test_flag, int *test_flag2)
{
	int n = 0;
	static char c = '0';
	
	if (!*test_flag) {
		printf("1 - Europe,\n2 - Africa,\n3 - Asia,\n4 - America,\n5 - Australia and Oceania.\n");
		printf("Enter the appropriate number.\n");
		scanf("%d", &n);
		while (getchar() != '\n');
	}
	else
		n = *test_flag;
	switch (n)
	{
		case -1:
			break;
		case 1:
			c = var_Continents(1, test_flag2);
			break;
		case 2:
			c = var_Continents(2, test_flag2);
			break;
		case 3:
			c = var_Continents(3, test_flag2);
			break;
		case 4:
			c = var_Continents(4, test_flag2);
			break;
		case 5:
			c = var_Continents(5, test_flag2);
			break;
		default:
			printf("Error!:\nthere are no instructions for your input!\n");
			if (*test_flag)
			{
				printf("Erorr detected in test! Default variant - Europe\n");
				*test_flag = 1;
			}
			location_variants(test_flag, test_flag2);
			n = 1;
			break;
	}
	return (c);
}
