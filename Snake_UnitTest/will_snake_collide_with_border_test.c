#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../Snake_Lib/snake.h"
#include "test_defs.h"

int will_snake_collide_when_collide_with_border_up_test()
{
	//arrange
	snake_t snake = create_snake(56, 1);
	ASSERT(snake != NULL);
	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, UP);

	//assert
	ASSERT(result);
	return TEST_PASS;

}

int will_snake_collide_when_collide_with_border_down_test()
{
	//arrange
	snake_t snake = create_snake(46, GAME_HEIGHT - 1);
	ASSERT(snake != NULL);

	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, DOWN);
	//assert
	ASSERT(result);
	return TEST_PASS;

}
int will_snake_collide_when_collide_with_border_right_test()
{
	//arrange
	snake_t snake = create_snake(GAME_WIDTH - 1, 12);
	ASSERT(snake != NULL);

	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, RIGHT);
	//assert
	ASSERT(result);
	return TEST_PASS;

}

int will_snake_collide_when_collide_with_border_left_test()
{
	//arrange
	snake_t snake = create_snake(1, 42);
	ASSERT(snake != NULL);

	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, LEFT);
	//assert
	ASSERT(result);
	return TEST_PASS;

}

int will_snake_collide_when_will_not_collide_test()
{
	//arrange
	snake_t snake = create_snake(78, 78);
	ASSERT(snake != NULL);

	//act 
	bool result = will_snake_collide_border_on_next_move(snake, 1, DOWN);
	//assert
	ASSERT(false == result);
	return TEST_PASS;

}


int will_snake_collide_with_border_main()
{
	INIT_TESTS();
	RUN_TEST(will_snake_collide_when_collide_with_border_up_test);
	RUN_TEST(will_snake_collide_when_collide_with_border_down_test);
	RUN_TEST(will_snake_collide_when_collide_with_border_right_test);
	RUN_TEST(will_snake_collide_when_collide_with_border_left_test);
	RUN_TEST(will_snake_collide_when_will_not_collide_test);
	FINISH_TESTS();
}