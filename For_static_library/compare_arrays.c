#include "../includes/arrays.h"

int compare_arrays(const int *array_A, const int size_A,
					const int *array_B, const int size_B)
{
	if (size_A != size_B)
		return (0);
	for (int i = 0; i < size_A; ++i)
		if (array_A[i] != array_B[size_A - i - 1])
			return (0);
	return 1;
}