#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define GAME_WIDTH (20) 
#define GAME_HEIGHT (20) 
#define WALLS_COLOR (176)
#define SNAKE_COLOR (178)

enum directions_enum
{
	UP, DOWN, RIGHT, LEFT, INVALID_DIRECTION
};
#define direction_t enum directions_enum
#define snake_t uint8_t** 


void print_snake(snake_t snake, size_t snake_size);

snake_t create_snake(uint8_t x, uint8_t y);
void free_snake(snake_t snake, size_t snake_size);
uint8_t* snake_head(snake_t snake, size_t snake_size);
void get_next_snake_head_location(snake_t snake, size_t snake_size, direction_t direction, uint8_t next_snake_head_pos[2]);
// returns the new snake size
size_t grow_snake(snake_t *snake_ptr, size_t snake_size, direction_t direction);
bool are_snakes_equal(snake_t a, size_t a_size, snake_t b, size_t b_size);
void draw_borders();
bool will_snake_collide_border_on_next_move(snake_t snake, size_t snake_size, direction_t direction);
snake_t create_long_snake(uint8_t x, uint8_t y, direction_t* growth_directions,size_t growth_directions_size);
void move_snake(snake_t snake, size_t snake_size, direction_t to_where);
// Returns true if snakes will reach food after a single move in the given direction. 
bool will_snake_reach_food_on_next_move(snake_t snake, size_t snake_size, uint8_t * food,direction_t direction);
bool is_food_on_snake(snake_t snake, size_t snake_size, uint8_t food[2]);
void set_new_food_location(snake_t snake, size_t snake_size, uint8_t food[2]);
bool will_snake_collide_with_itself_on_next_move(snake_t snake, size_t snake_size, direction_t direction);
void gotoxy(int x, int y);
void draw_snake(snake_t snake, size_t snake_size);
void erase_snake_tail(snake_t snake, size_t snake_size);
void clear_snake(snake_t snake, size_t snake_size);
void draw_food(uint8_t* food);
void draw_borders();
bool will_snake_collide_border_on_next_move(snake_t snake, size_t snake_size, direction_t direction);
bool can_snake_move_in_direction(direction_t current_direction, direction_t requested_direction);