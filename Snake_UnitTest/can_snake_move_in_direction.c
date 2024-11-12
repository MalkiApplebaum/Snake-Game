#include "../Snake_Lib/snake.h"
#include "test_defs.h"

int can_snake_move_in_direction_up_test()
{
	//arrange
	snake_t snake = create_snake(10,10);
	ASSERT(snake != NULL);
	grow_snake(&snake, 1, DOWN);

	//act
	bool result = can_snake_move_in_direction(DOWN, UP);

	//assert
	ASSERT(false == result);
	return TEST_PASS;
}
int can_snake_move_in_direction_down_test()
{
	//arrange
	snake_t snake = create_snake(10, 10);
	ASSERT(snake != NULL);
	grow_snake(&snake, 1, UP);

	//act
	bool result = can_snake_move_in_direction(UP, DOWN);
	//assert
	ASSERT(false == result);
	return TEST_PASS;

}
int can_snake_move_in_direction_left_test()
{
	//arrange
	snake_t snake = create_snake(10, 10);
	ASSERT(snake != NULL);
	grow_snake(&snake, 1, RIGHT);

	//act
	bool result = can_snake_move_in_direction(RIGHT, LEFT);
	//assert
	ASSERT(false == result);
	return TEST_PASS;

}
int can_snake_move_in_direction_right_test()
{
	//arrange
	snake_t snake = create_snake(10, 10);
	ASSERT(snake != NULL);
	grow_snake(&snake, 1, LEFT);

	//act
	bool result = can_snake_move_in_direction(LEFT, RIGHT);
	//assert
	ASSERT(false == result);
	return TEST_PASS;

}

int can_snake_move_in_direction_main()
{
	INIT_TESTS();
	RUN_TEST(can_snake_move_in_direction_up_test);
	RUN_TEST(can_snake_move_in_direction_down_test);
	RUN_TEST(can_snake_move_in_direction_left_test);
	RUN_TEST(can_snake_move_in_direction_right_test);
	FINISH_TESTS();
}