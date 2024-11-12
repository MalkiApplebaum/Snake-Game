#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../Snake_Lib/snake.h"
#include "test_defs.h"

int are_snakes_equal__WhenOfLength_1_test()
{
	//arrange
	snake_t snake_a = create_snake(10, 10);
	snake_t snake_b = create_snake(10, 10);
	ASSERT(snake_a != NULL);
	ASSERT(snake_b != NULL);
	bool expected = true;
	//act
	bool actual = are_snakes_equal(snake_a, 1, snake_b, 1);

	//assert
	ASSERT(actual == expected);
	return TEST_PASS;
}

int are_snakes_equal__WhenOfLength_4_test()
{
	//arrange
	direction_t growth_directions[3] = { RIGHT,RIGHT,DOWN };
	snake_t snake_a = create_long_snake(10,10, growth_directions, 3);
	snake_t snake_b = create_long_snake(10,10, growth_directions, 3);
	ASSERT(snake_a != NULL);
	ASSERT(snake_b != NULL);
	bool expected = true;
	//act
	bool actual = are_snakes_equal(snake_a, 3, snake_b, 3);
	
	//assert
	ASSERT(actual == expected);
	return TEST_PASS;
}

int are_snakes_equal__WhenNotEqual_OfLength_1_test()
{
	//arrange
	snake_t snake_a = create_snake(10, 10);
	snake_t snake_b = create_snake(10, 11);
	ASSERT(snake_a != NULL);
	ASSERT(snake_b != NULL);
	bool expected = false;
	
	//act
	bool actual = are_snakes_equal(snake_a, 1, snake_b, 1);

	//assert
	ASSERT(actual == expected);
	return TEST_PASS;
}

int are_snakes_equal__WhenNotEqual_OfLength_4_test()
{
	//arrange
	direction_t growth_directions_1[3] = { RIGHT,RIGHT,DOWN };
	direction_t growth_directions_2[3] = { RIGHT,UP,LEFT };
	snake_t snake_a = create_long_snake(10, 10, growth_directions_1, 3);
	snake_t snake_b = create_long_snake(10, 10, growth_directions_2, 3);
	ASSERT(snake_a != NULL);
	ASSERT(snake_b != NULL);
	bool expected = false;
	//act
	bool actual = are_snakes_equal(snake_a, 3, snake_b, 3);

	//assert
	ASSERT(actual == expected);
	return TEST_PASS;
}

int are_snakes_equal_main()
{
	INIT_TESTS();
	RUN_TEST(are_snakes_equal__WhenOfLength_1_test);
	RUN_TEST(are_snakes_equal__WhenOfLength_4_test);
	RUN_TEST(are_snakes_equal__WhenNotEqual_OfLength_1_test);
	RUN_TEST(are_snakes_equal__WhenNotEqual_OfLength_4_test);
	FINISH_TESTS();
}