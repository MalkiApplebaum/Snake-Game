#include <stdbool.h>
#include <stdio.h>
#include "grow_snake_test.h"
#include "are_snakes_equal_test.h"
#include "move_snake_test.h"
#include "create_long_snake_test.h"
#include "will_snake_reach_food_on_next_move_test.h"
#include "collision_with_itself_test.h"
#include "will_snake_collide_with_border_test.h"
#include "can_snake_move_in_direction.h"
#include "test_defs.h"

int main()
{
	INIT_TESTS();
	RUN_TESTS_SUITE(grow_snake_main);
	RUN_TESTS_SUITE(are_snakes_equal_main);
	RUN_TESTS_SUITE(create_long_snake_main);
	RUN_TESTS_SUITE(move_snake_main);
	RUN_TESTS_SUITE(will_snake_reach_food_on_next_move_main);
	RUN_TESTS_SUITE(collision_with_itself_main);
	RUN_TESTS_SUITE(will_snake_collide_with_border_main);
	RUN_TESTS_SUITE(can_snake_move_in_direction_main);
	//RUN_TESTS_SUITE(read_write_snake_main);
	PRINT_ALL_TESTS_RES();
	FINISH_TESTS();
}