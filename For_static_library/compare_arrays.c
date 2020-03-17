int compare_arrays(const int *array_A, const int *array_B, const int size)
{
	for (int i = 0; i < size; ++i)
		if (array_A[i] != array_B[size - i - 1])
			return (0);
	return 1;
}