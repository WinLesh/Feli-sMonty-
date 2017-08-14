#include "monty.h"

/**
 * init_tracker - Initializes the tracker
 *
 * Return: None
 */
void init_tracker()
{
	tracker_t tracker = { NULL, 0, 's' };
}

/**
 * init_instructions - Initializes all of the opcodes/functions
 *
 * Return: Array of instructions
 */
instruction_t **init_instructions()
{
	instruction_t **instructions = {
		{"push", push_node},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop_node},
		{"swap", swap_two_nodes}
		{"add", add_two_nodes},
		{"nop", do_nothing},
		{"sub", sub_two_nodes},
		{"div", div_two_nodes},
		{"mul", mul_two_nodes},
		{"mod", mod_two_nodes},
		{"pchr", print_top_char},
		{"pstr", print_string},
		{"rotl", rotate_top_to_bottom},
		{"rotr", rotate_bottom_to_top},
		{"stack", enable_stack_mode},
		{"queue", enable_queue_mode},
		{NULL, NULL}
	};
	return (instructions);
}
