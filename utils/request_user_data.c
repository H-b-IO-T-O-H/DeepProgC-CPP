#include "../includes/arrays.h"

int request_data(int argc, char **argv, int *size, int *flag_fill)
{
	int size_A;
	int size_B;
	
	if (argc != 4 || ((*flag_fill = atoi(argv[3])) != 1 && *flag_fill != -1)) {
		printf("\033[031mError! Wrong number or values of arguments!\033[032m\nUsage:\033[039m./dz_2 size of array_A, size of array_B,"
		 "fill flag. Max size of each array: ~ 100 000 000\n");
		printf("fill flag =  1 - array_A = [0; size_A], array_B = [0; size_B]\n");
		printf("fill flag = -1 - array_A = [0; size_A], array_B = [size_B; 0] - array B reversed\n");
		return 1;
	}
	size_A = atoi(argv[1]);
	size_B = atoi(argv[2]);
	if (size_A > MAX_SIZE || size_B > MAX_SIZE) {
		printf("Error! Size limit exceeded!\n");
		return 1;
	}
	if (size_A != size_B) {
		printf("Arrays have different sizes!\n");
		return 1;
	}
	*size = size_A;
	return 0;
}