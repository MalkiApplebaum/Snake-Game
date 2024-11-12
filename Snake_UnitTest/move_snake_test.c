#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../Snake_Lib/snake.h"
#include "test_defs.h"

int move_snake_test()
{
	//arrange
	direction_t growth_directions[2] = { UP,UP };
	snake_t actual_snake = create_long_snake(10, 10, growth_directions, 2);
	ASSERT(actual_snake != NULL);
	//print_snake(actual_snake, 2);
	direction_t growth_directions_expected[2] = { RIGHT, UP };
	snake_t expected_snake = create_long_snake(9, 10, growth_directions_expected, 2);
	ASSERT(expected_snake != NULL);
	//print_snake(expected_snake, 2);

	//act
	move_snake(expected_snake, 3, UP);

	//assert
	int result = are_snakes_equal(actual_snake, 3, expected_snake, 3);
	ASSERT(result);
	return TEST_PASS;
}

int move_snake_main()
{
	INIT_TESTS();
	RUN_TEST(move_snake_test);
	FINISH_TESTS();
}