#include <gtest/gtest.h>

extern "C" {
#include "../includes/arrays.h"
}
t_data data = {PTHREAD_MUTEX_INITIALIZER,
			   NULL, NULL,
			   NULL, 0,
			   0, 0 , 0, 1};

#define UNIT_TESTS_SIZE 1000
#define UNIT_TEST_MULT 100
#define STRESS_TEST_SIZE 10
#define STRESS_TEST_MULT 30000000

void check_static(int mult_factor)
{
	int *array_A;
	int *array_B;
	int size;
	mult_factor == UNIT_TEST_MULT ? size = UNIT_TESTS_SIZE : (size = STRESS_TEST_SIZE);
	int sizes_for_tests[size];
	
	for (int i = 1; i < size; ++i)
		sizes_for_tests[i] = i * mult_factor;
	for (int i = 1; i < size; ++i)
	{
		array_A = ft_fill_array(sizes_for_tests[i], 1);//создаем изначально правильные массивы
		array_B = ft_fill_array(sizes_for_tests[i], -1);
		ASSERT_EQ( compare_arrays(array_A, array_B, sizes_for_tests[i]), 1);
		free_all(array_A, array_B, NULL, NULL);
	}
	for (int i = 1; i < size; ++i)
	{
		array_A = ft_fill_array(sizes_for_tests[i], 1);//создаем изначально правильные массивы
		array_B = ft_fill_array(sizes_for_tests[i], -1);//но меняем один из элементов на любое число, функция сравнения должна вернуть 0 во всех случаях
		array_B[i] = -1;
		ASSERT_EQ( compare_arrays(array_A, array_B, sizes_for_tests[i]), 0);
		free_all(array_A, array_B, NULL, NULL);
	}
}

void check_dynamic(int mult_factor)
{
	int	*array_A;
	int	*array_B;
	int size;
	mult_factor == UNIT_TEST_MULT ? size = UNIT_TESTS_SIZE : (size = STRESS_TEST_SIZE);
	int sizes_for_tests[size];
	
	for (int i = 1; i < size; ++i)
		sizes_for_tests[i] = i * mult_factor;
	for (int i = 1; i < size; ++i)
	{
		array_A = ft_create_array(sizes_for_tests[i]);
		array_B = ft_create_array(sizes_for_tests[i]);
		ASSERT_EQ( create_threads_and_cmp(array_A, array_B, sizes_for_tests[i], 1), 0);
		free_all(array_A,array_B, data.info.distribution, NULL);
	}
	for (int i = 1; i < size; ++i)
	{
		array_A = ft_create_array(sizes_for_tests[i]);
		array_B = ft_create_array(sizes_for_tests[i]);
		data.info.test_mode = i;// меняем один из элементов  второго заведомо верного массивана любое число, функция сравнения должна вернуть 0 во всех случаях
		ASSERT_EQ( create_threads_and_cmp(array_A, array_B, sizes_for_tests[i], -1), 0);
		free_all(array_A,array_B, data.info.distribution, NULL);
	}
}

TEST(STATIC, unit_tests) {
	
	check_static(UNIT_TEST_MULT);
}

TEST(DYNAMIC, unit_tests) {
	
	check_dynamic(UNIT_TEST_MULT);
}

TEST(STATIC, stress_tests) {
	
	check_static(STRESS_TEST_MULT);
}

TEST(DYNAMIC, stress_tests) {
	
	check_dynamic(STRESS_TEST_MULT);
	free_all(NULL, NULL, NULL, &data.mutex);
}
