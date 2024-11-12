#include "snake.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#include "snake.h"


/// /// /// /// Your best friend for debuggnign: /// /// /// /// 
void print_snake(snake_t snake, size_t snake_size)
{
	for (int i = 0; i < snake_size; i++)
	{
		printf("%d) %d %d \n", i, snake[i][0], snake[i][1]);
	}
	printf("\n");
}

/// /// /// /// Drawing functions: /// /// /// /// 

#define WALLS_COLOR 176
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(consoleHandle, coord);

}
void clear_cursor()
{
	gotoxy(GAME_WIDTH + 1, 0);
}

void draw_borders()
{
	// vertical walls:
	for (int i = 0; i <= GAME_HEIGHT; i++)
	{
		gotoxy(0, i);
		printf("%c", WALLS_COLOR);
		gotoxy(GAME_WIDTH, i);
		printf("%c", WALLS_COLOR);
	}

	// Horizontal walls:
	for (int i = 0; i <= GAME_WIDTH; i++)
	{
		gotoxy(i, 0);
		printf("%c", WALLS_COLOR);
		gotoxy(i, GAME_HEIGHT);
		printf("%c", WALLS_COLOR);
	}
}


void draw_food(uint8_t* food)
{
	gotoxy(food[0], food[1]);
	printf("%c", '*');
	// TODO: Draw the food here!
	clear_cursor();
}

bool will_snake_collide_border_on_next_move(snake_t snake, size_t snake_size, direction_t direction)
{
	switch (direction)
	{
	case UP:
	{
		if (snake[snake_size - 1][1] - 1 == 0)
			return true;
		break;
	}
	case DOWN:
	{
		if (snake[snake_size - 1][1] + 1 == GAME_HEIGHT)
			return true;
		break;
	}
	case LEFT:
	{
		if (snake[snake_size - 1][0] - 1 == 0)
			return true;
		break;
	}
	case  RIGHT:
	{
		if (snake[snake_size - 1][0] + 1 == GAME_WIDTH)
			return true;
		break;
	}
	case INVALID_DIRECTION:
	{
		break;
	}
	}
	return false;
}

bool can_snake_move_in_direction(direction_t current_direction, direction_t requested_direction)
{
	switch (current_direction) 
	{
	case UP:
	{
		if (requested_direction == DOWN)
			return false;
		break;
	}
	case DOWN:
	{
		if (requested_direction == UP)
			return false;
		break;
	}
	case RIGHT:
	{
		if (requested_direction == LEFT)
			return false;
		break;
	}
	case LEFT:
	{
		if (requested_direction == RIGHT)
			return false;
		break;
	}
	case INVALID_DIRECTION:
	{
		break;
	}
	}
	return true;
}
bool will_snake_collide_with_itself_on_next_move(snake_t snake, size_t snake_size, direction_t direction)
{
	for (int i = 0; i < snake_size; i++)
	{
		switch (direction)
		{
		case UP:
		{
			if (snake[snake_size - 1][0] == snake[i][0] && snake[snake_size - 1][1] - 1 == snake[i][1])
				return true;
			break;
		}
		case DOWN:
		{
			if (snake[snake_size - 1][0] == snake[i][0] && snake[snake_size - 1][1] + 1 == snake[i][1])
				return true;
			break;
		}
		case RIGHT:
		{
			if (snake[snake_size - 1][0]+1 == snake[i][0] && snake[snake_size - 1][1] == snake[i][1])
				return true;
			break;
		}
		case LEFT:
		{
			if (snake[snake_size - 1][0] - 1 == snake[i][0] && snake[snake_size - 1][1] == snake[i][1])
				return true;
			break;
		}
		case INVALID_DIRECTION:
		{
			if (snake[snake_size - 1][0] == snake[i][0] && snake[snake_size - 1][1] == snake[i][1])
				return true;
			break;
		}
		}
	}
	return false;
}

void draw_snake(snake_t snake, size_t snake_size)
{
	for (int i = 0; i < snake_size; i++)
	{
		gotoxy(snake[i][0], snake[i][1]);
		printf("%c", SNAKE_COLOR);
	}
}
void erase_snake_tail(snake_t snake, size_t snake_size)
{
	gotoxy(snake[0][0], snake[0][1]);
	printf(" ");
}
void clear_snake(snake_t snake, size_t snake_size)
{
	// TODO !
}

snake_t create_snake(uint8_t x, uint8_t y)
{
	snake_t snake = malloc(sizeof(uint8_t*));
	*snake = malloc(sizeof(uint8_t) * 2);
	**snake = x;
	*(*snake + 1) = y;
	return snake;
}
void free_snake(snake_t snake, size_t snake_size)
{
	for (int i = 0; i < snake_size; i++)
	{
		free(*(snake + i));
	}
	free(snake);

}

uint8_t* snake_head(snake_t snake, size_t snake_size)
{
	return NULL;
}

void get_next_snake_head_location(snake_t snake, size_t snake_size, direction_t direction, uint8_t next_snake_head_pos[2])
{
	switch (direction)
	{
	case UP:
	{
		next_snake_head_pos[1] -= 1; break;
	}
	case DOWN:
	{
		next_snake_head_pos[1] += 1; break;
	}
	case RIGHT:
	{
		next_snake_head_pos[0] += 1; break;
	}
	case LEFT:
	{
		next_snake_head_pos[0] -= 1; break;
	}
	}
}
size_t grow_snake(snake_t* snake_ptr, size_t snake_size, direction_t direction)
{
	(*snake_ptr) = realloc(*snake_ptr, (snake_size + 1) * sizeof(uint8_t*));
	(*snake_ptr)[snake_size] = malloc(sizeof(uint8_t) * 2);

	switch (direction)
	{
	case UP:
	{
		(*snake_ptr)[snake_size][0] = (*snake_ptr)[snake_size - 1][0];
		(*snake_ptr)[snake_size][1] = (*snake_ptr)[snake_size - 1][1] - 1; break;
	}
	case DOWN:
	{
		(*snake_ptr)[snake_size][0] = (*snake_ptr)[snake_size - 1][0];
		(*snake_ptr)[snake_size][1] = (*snake_ptr)[snake_size - 1][1] + 1; break;
	}
	case RIGHT:
	{
		(*snake_ptr)[snake_size][0] = (*snake_ptr)[snake_size - 1][0]+1;
		(*snake_ptr)[snake_size][1] = (*snake_ptr)[snake_size - 1][1] ; break;
	}
	case LEFT:
	{
		(*snake_ptr)[snake_size][0] = (*snake_ptr)[snake_size - 1][0]-1;
		(*snake_ptr)[snake_size][1] = (*snake_ptr)[snake_size - 1][1]; break;
	}
	case INVALID_DIRECTION:
	{
		(*snake_ptr)[snake_size][0] = (*snake_ptr)[snake_size - 1][0];
		(*snake_ptr)[snake_size][1] = (*snake_ptr)[snake_size - 1][1]; break;
	}
	}

	return snake_size+1;
}

// correctly implemented, don't touch:
bool are_snakes_equal(snake_t a, size_t a_size, snake_t b, size_t b_size)
{
	if (a_size != b_size)
	{
		return false;
	}
	for (int i = 0; i < a_size; i++)
	{
		if (a[i][0] != b[i][0] || a[i][1] != b[i][1])
		{
			return false;
		}
	}
	return true;
}

void move_snake(snake_t snake, size_t snake_size, direction_t to_where)
{
	for (int i = 0; i < snake_size-1; i++)
	{
		snake[i][0] = snake[i+1][0];
		snake[i][1] = snake[i + 1][1];
	}
	get_next_snake_head_location(snake, snake_size, to_where, snake[snake_size - 1]);
}


snake_t create_long_snake(uint8_t x, uint8_t y, direction_t* growth_directions, size_t growth_directions_size)
{
	snake_t snake = create_snake(x, y);
	for (int i = 0; i < growth_directions_size; i++)
	{
		grow_snake(&snake, (i + 1), growth_directions[i]);
	}
	return snake;
}

bool will_snake_reach_food_on_next_move(snake_t snake, size_t snake_size, uint8_t* food, direction_t direction)
{
	switch (direction)
	{
	case UP:
	{
		if (snake[snake_size - 1][0] == food[0] && snake[snake_size - 1][1] - 1 == food[1])
			return true; break;
	}
	case DOWN:
	{
		if (snake[snake_size - 1][0] == food[0] && snake[snake_size - 1][1] + 1 == food[1])
			return true; break;
	}
	case RIGHT:
	{
		if (snake[snake_size - 1][0]+ 1 == food[0] && snake[snake_size - 1][1]  == food[1])
			return true; break;
	}
	case LEFT:
	{
		if (snake[snake_size - 1][0]- 1 == food[0] && snake[snake_size - 1][1]  == food[1])
			return true; break;
	}
	case INVALID_DIRECTION:
	{
		if (snake[snake_size - 1][0] == food[0] && snake[snake_size - 1][1] == food[1])
			return true; break;
	}
	}
	return false;
}

bool is_food_on_snake(snake_t snake, size_t snake_size, uint8_t food[2])
{
	for (int i = 0; i < snake_size; i++)
	{
		if (snake[i][0] == food[0] && snake[i][1] == food[1])
			return true;
	}
	return false;
}
void set_new_food_location(snake_t snake, size_t snake_size, uint8_t food[2])
{
	food[0] = rand()% (GAME_WIDTH - 1)+1;
	food[1] = rand() % (GAME_HEIGHT - 1) + 1;
	
}