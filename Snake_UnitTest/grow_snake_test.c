#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../Snake_Lib/snake.h"
#include "test_defs.h"

int grow_snake__When_UP()
{
	//arrange:
	snake_t snake = create_snake(10, 10);
	ASSERT(snake != NULL);
	uint8_t expected_x = 10, expected_y = 9;
	size_t snake_size;

	//act
	snake_size = grow_snake(&snake, 1, UP);
	ASSERT(snake != NULL);
	ASSERT(snake_size > 1);
	uint8_t actual_x = snake[1][0];
	uint8_t actual_y = snake[1][1];
	free_snake(snake, 2);

	//assert
	ASSERT(actual_x == expected_x && actual_y == expected_y);
	return TEST_PASS;
}

int grow_snake__When_DOWN()
{
	//arrange:
	snake_t snake = create_snake(10, 10);
	ASSERT(snake != NULL);
	uint8_t expected_x = 10, expected_y = 11;
	size_t snake_size;

	//act
	snake_size = grow_snake(&snake, 1, DOWN);
	ASSERT(snake != NULL);
	ASSERT(snake_size > 1); uint8_t actual_x = snake[1][0];
	uint8_t actual_y = snake[1][1];
	free_snake(snake, 2);

	//assert
	ASSERT(actual_x == expected_x && actual_y == expected_y);
	return TEST_PASS;
}

int grow_snake__When_RIGHT()
{
	//arrange:
	snake_t snake = create_snake(10, 10);
	ASSERT(snake != NULL);
	uint8_t expected_x = 11, expected_y = 10;
	size_t snake_size;

	//act
	snake_size = grow_snake(&snake, 1, RIGHT);
	ASSERT(snake != NULL);
	ASSERT(snake_size > 1); uint8_t actual_x = snake[1][0];
	uint8_t actual_y = snake[1][1];
	free_snake(snake, 2);

	//assert
	ASSERT(actual_x == expected_x && actual_y == expected_y);
	return TEST_PASS;
}

int grow_snake__When_LEFT()
{
	//arrange:
	snake_t snake = create_snake(10, 10);
	ASSERT(snake != NULL);
	uint8_t expected_x = 9, expected_y = 10;
	size_t snake_size;

	//act
	snake_size = grow_snake(&snake, 1, LEFT);
	ASSERT(snake != NULL);
	ASSERT(snake_size > 1); uint8_t actual_x = snake[1][0];
	uint8_t actual_y = snake[1][1];
	free_snake(snake, 2);

	//assert
	ASSERT(actual_x == expected_x && actual_y == expected_y);
	return TEST_PASS;
}

int grow_snake__When_SeveralTimes()
{
	// arrange
	snake_t snake = create_snake(10, 10);
	ASSERT(snake != NULL);
	uint8_t expected_snake[][2] = { {10,10},{9,10},{9,9},{9,8},{10,8} };
	size_t snake_size;

	//act 
	snake_size = grow_snake(&snake, 1, LEFT);
	ASSERT(snake != NULL);
	ASSERT(snake_size > 1); 
	snake_size = grow_snake(&snake, snake_size, UP);
	ASSERT(snake != NULL);
	ASSERT(snake_size > 1); 
	snake_size = grow_snake(&snake, snake_size, UP);
	ASSERT(snake != NULL);
	ASSERT(snake_size > 1); 
	snake_size = grow_snake(&snake, snake_size, RIGHT);
	ASSERT(snake != NULL);
	ASSERT(snake_size > 1);

	// assert
	for (int i = 0; i < 5; i++)
	{
		for (int coord = 0; coord < 2; coord++) {
			if (snake[i][coord] != expected_snake[i][coord])
				return TEST_FAILED;
		}
	}
	return TEST_PASS;
}


int grow_snake_main()
{
	INIT_TESTS();
	RUN_TEST(grow_snake__When_UP);
	RUN_TEST(grow_snake__When_DOWN);
	RUN_TEST(grow_snake__When_RIGHT);
	RUN_TEST(grow_snake__When_LEFT);
	RUN_TEST(grow_snake__When_SeveralTimes);
	FINISH_TESTS();
}
