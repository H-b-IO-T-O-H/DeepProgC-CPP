#include <gtest/gtest.h>

extern "C" {
#include "../includes/arrays.h"
}

#define UNIT_TESTS_SIZE 1000
#define UNIT_TEST_MULT 100
#define STRESS_TEST_SIZE 10
#define STRESS_TEST_MULT 30000000

void check_static(int mult_factor)
{
	t_data *arrays_info;
	int size = (mult_factor == UNIT_TEST_MULT)? UNIT_TESTS_SIZE :
												STRESS_TEST_SIZE;
	int sizes_for_tests[size];
	
	for (int i = 1; i < size; ++i)
		sizes_for_tests[i] = i * mult_factor;
	for (int i = 1; i < size; ++i)
	{
		create_all_data_about_arrays(&arrays_info,  TEST_MODE,  SINGLE_TREAD, sizes_for_tests[i], NOT_EQUAL);
		ft_fill_array(arrays_info->info.arr_A, sizes_for_tests[i], EQUAL);//создаем изначально правильные массивы
		ft_fill_array(arrays_info->info.arr_B, sizes_for_tests[i], -EQUAL);
		ASSERT_EQ( compare_arrays(arrays_info), EQUAL);
		free_all(&arrays_info, SINGLE_TREAD);
	}
	for (int i = 1; i < size; ++i)
	{
		create_all_data_about_arrays(&arrays_info,  TEST_MODE,  SINGLE_TREAD, sizes_for_tests[i], NOT_EQUAL);
		ft_fill_array(arrays_info->info.arr_A, sizes_for_tests[i], EQUAL);//создаем изначально правильные массивы
		ft_fill_array(arrays_info->info.arr_B, sizes_for_tests[i], -EQUAL);//но меняем один из элементов на любое число, функция сравнения должна вернуть 0 во всех случаях
		arrays_info->info.arr_B[i] = -666;//но меняем один из элементов на любое число, функция сравнения должна вернуть 0 во всех случаях
		ASSERT_EQ( compare_arrays(arrays_info), NOT_EQUAL);
		free_all(&arrays_info, SINGLE_TREAD);
	}
}

void check_dynamic(int mult_factor)
{
	t_data *arrays_info;
	int size = (mult_factor == UNIT_TEST_MULT)? UNIT_TESTS_SIZE :
			   									STRESS_TEST_SIZE;
	int sizes_for_tests[size];
	
	for (int i = 1; i < size; ++i)
		sizes_for_tests[i] = i * mult_factor;
	for (int i = 1; i < size; ++i)
	{
		create_all_data_about_arrays(&arrays_info, TEST_MODE, MULTI_THREADS, sizes_for_tests[i], EQUAL);
		fill_arrays_via_treads(arrays_info);
		ASSERT_EQ( compare_arrays_via_threads(arrays_info), NOT_EQUAL);
		free_all(&arrays_info, MULTI_THREADS);
	}
	for (int i = 1; i < size; ++i)
	{
		create_all_data_about_arrays(&arrays_info, TEST_MODE, MULTI_THREADS, sizes_for_tests[i], NOT_EQUAL);
		fill_arrays_via_treads(arrays_info);//создаем изначально правильные массивы
		arrays_info->info.arr_B[i] = -666;//но меняем один из элементов на любое число, функция сравнения должна вернуть 0 во всех случаях
		ASSERT_EQ( compare_arrays_via_threads(arrays_info), NOT_EQUAL);
		free_all(&arrays_info, MULTI_THREADS);
	}
}

TEST(STATIC, unit_tests) {
	
	check_static(UNIT_TEST_MULT);
}

TEST(DYNAMIC, unit_tests) {
	
	check_dynamic(UNIT_TEST_MULT);
}
/*
TEST(STATIC, stress_tests) {
	
	check_static(STRESS_TEST_MULT);
}*/

TEST(DYNAMIC, stress_tests) {
	
	check_dynamic(STRESS_TEST_MULT);
}
