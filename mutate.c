#include "monty.h"

/**
 * push_node - Pushes node onto stack/queue
 * @stack: Address of the head pointer
 * @line_number: The current line number
 * @val: The value to instantiate node with
 *
 * Return: None
 */
void push_node(stack_t **stack, unsigned int line_number)
{
	char *operand = NULL;
	int value = 0;

	operand = strtok(NULL, " \t\r\n");
	if (_isdigit(operand))
	{
		value = atoi(operand);
		add_cell(stack, value);
	}
	else
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_node - Pops node from stack/queue
 * @stack: Address of the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void pop_node(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * swap_two_nodes - Swaps two nodes from stack/queue
 * @stack: Address of the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void swap_two_nodes(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * rotate_top_to_bottom - Moves top node to last node
 * @stack: Address of the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void rotate_top_to_bottom(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * rotate_bottom_to_top - Moves last node to top node
 * @stack: Address of the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void rotate_bottom_to_top(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
