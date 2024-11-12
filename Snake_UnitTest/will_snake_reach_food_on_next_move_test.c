#include <stdio.h>
#include <stdint.h>
#include "../Snake_Lib/snake.h"
#include "test_defs.h"

int will_snake_reach_food_on_next_move__When_left()
{
	//arrange
	direction_t growth_directions_expected[2] = { DOWN, DOWN };
	snake_t snake = create_long_snake(10, 10, growth_directions_expected, 2);
	uint8_t food[2];
	food[0] = 9;
	food[1] = 12;
	//print_snake(snake, 3);
	//act
	bool result = will_snake_reach_food_on_next_move(snake, 3, food, LEFT);
	//assert
	ASSERT(result); return TEST_PASS;

}

int will_snake_reach_food_on_next_move__When_right()
{
	//arrange
	direction_t growth_directions_expected[2] = { DOWN, DOWN };
	snake_t snake = create_long_snake(10, 10, growth_directions_expected, 2);
	uint8_t food[2];
	food[0] = 11;
	food[1] = 12;
	//print_snake(snake, 3);

	//act
	bool result = will_snake_reach_food_on_next_move(snake, 3, food, RIGHT);
	//assert
	ASSERT(result); return TEST_PASS;
}

int will_snake_reach_food_on_next_move__When_up()
{
	//arrange
	direction_t growth_directions_expected[2] = { DOWN, LEFT };
	snake_t snake = create_long_snake(10, 10, growth_directions_expected, 2);
	uint8_t food[2];
	food[0] = 9;
	food[1] = 10;
	//print_snake(snake, 3);
	//act
	bool result = will_snake_reach_food_on_next_move(snake, 3, food, UP);
	//assert
	ASSERT(result); return TEST_PASS;
}

int will_snake_reach_food_on_next_move__When_down()
{
	//arrange
	direction_t growth_directions_expected[2] = { DOWN, DOWN };
	snake_t snake = create_long_snake(10, 10, growth_directions_expected, 2);
	uint8_t food[2];
	food[0] = 10;
	food[1] = 13;
	//print_snake(snake, 3);
	//act
	bool result = will_snake_reach_food_on_next_move(snake, 3, food, DOWN);
	//assert
	ASSERT(result); return TEST_PASS;
}

int will_snake_reach_food_on_next_move_main()
{
	INIT_TESTS();
	RUN_TEST(will_snake_reach_food_on_next_move__When_left);
	RUN_TEST(will_snake_reach_food_on_next_move__When_right);
	RUN_TEST(will_snake_reach_food_on_next_move__When_up);
	RUN_TEST(will_snake_reach_food_on_next_move__When_down);
	FINISH_TESTS();
}