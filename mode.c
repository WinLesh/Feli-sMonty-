#include "monty.h"

/**
 * enable_stack_mode - turn list into a stack
 * @stack: Address of the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void enable_stack_mode(stack_t **stack, unsigned int line_number)
{
	tracker.mode = 's';
	stack = stack;
	line_number = line_number;
}

/**
 * enable_queue_mode - turn list into a queue
 * @stack: Address of the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void enable_queue_mode(stack_t **stack, unsigned int line_number)
{
	tracker.mode = 'q';
	stack = stack;
	line_number = line_number;
}
