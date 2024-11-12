#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../Snake_Lib/snake.h"
#include "test_defs.h"

int create_long_snake_test()
{
	//arrange
	direction_t growth_directions[] = { LEFT,UP,UP,RIGHT };
	snake_t expected_snake = create_snake(10, 10);
	ASSERT(expected_snake != NULL);
	grow_snake(&expected_snake, 1, LEFT);
	grow_snake(&expected_snake, 2, UP);
	grow_snake(&expected_snake, 3, UP);
	grow_snake(&expected_snake, 4, RIGHT);

	//act
	snake_t actual_snake = create_long_snake(10, 10, growth_directions, 4);
	ASSERT(actual_snake != NULL);

	//assert
	bool result = are_snakes_equal(actual_snake, 5, expected_snake, 5);
	ASSERT(result);
	return TEST_PASS;
}

int create_long_snake_main()
{
	INIT_TESTS();
	RUN_TEST(create_long_snake_test);
	FINISH_TESTS();
}
