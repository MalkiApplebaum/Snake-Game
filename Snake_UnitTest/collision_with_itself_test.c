#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "../Snake_Lib/snake.h"
#include "test_defs.h"

int will_snake_collide_with_itself_on_next_move__WhenIndeedCollides_test()
{
	//arrange
	direction_t direction[] = { UP,UP,RIGHT,DOWN,DOWN };
	snake_t snake = create_long_snake(10, 10, direction, 5);
	ASSERT(snake != NULL);

	bool expected__will_collide = true;
	//act
	bool actual__will_collide = will_snake_collide_with_itself_on_next_move(snake, 6, LEFT);

	//assert
	ASSERT(actual__will_collide == expected__will_collide);
	return TEST_PASS;
}

int will_snake_collide_with_itself_on_next_move__WhenDoesNotCollides_test()
{
	//arrange
	direction_t direction[] = { UP,UP,RIGHT,DOWN,DOWN };
	snake_t snake = create_long_snake(10, 10, direction, 5);
	ASSERT(snake != NULL);
	bool expected__will_collide = false;
	//act
	bool actual__will_collide = will_snake_collide_with_itself_on_next_move(snake, 6, RIGHT);

	//assert
	ASSERT(actual__will_collide == expected__will_collide);
	return TEST_PASS;
}


int will_snake_collide_with_itself_on_next_move__WhenCollidesInMiddleOfBody_test()
{
	//arrange
	direction_t direction[] = { UP,UP,UP,UP,RIGHT,DOWN,DOWN };
	snake_t snake = create_long_snake(10, 10, direction, 7);
	ASSERT(snake != NULL);
	bool expected__will_collide = true;
	//act
	bool actual__will_collide = will_snake_collide_with_itself_on_next_move(snake, 8, LEFT);

	//assert
	ASSERT(actual__will_collide == expected__will_collide);
	return TEST_PASS;
}

int collision_with_itself_main()
{
	INIT_TESTS();
	RUN_TEST(will_snake_collide_with_itself_on_next_move__WhenIndeedCollides_test);
	RUN_TEST(will_snake_collide_with_itself_on_next_move__WhenDoesNotCollides_test);
	RUN_TEST(will_snake_collide_with_itself_on_next_move__WhenCollidesInMiddleOfBody_test);
	FINISH_TESTS();
}