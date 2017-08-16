#include "monty.h"

/**
 * add_two_nodes - add top 2 nodes in stack
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void add_two_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *current_head = NULL, *next = NULL;
	int first = 0, second = 0, sum = 0;

	if (tracker.node_count < 2)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current_head = *stack;
	next = current_head->next;

	first = current_head->n;
	second = next->n;
	sum = first + second;

	pop_node(stack, line_number);
	next->n = sum;
}

/**
 * sub_two_nodes - add top 2 nodes in stack
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void sub_two_nodes(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * mul_two_nodes - add top 2 nodes in stack
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void mul_two_nodes(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * div_two_nodes - add top 2 nodes in stack
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void div_two_nodes(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * mod_two_nodes - add top 2 nodes in stack
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void mod_two_nodes(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
