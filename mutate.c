#include "monty.h"

/**
 * push_node - Pushes node onto stack/queue
 * @stack: Address of the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void push_node(stack_t **stack, unsigned int line_number)
{
	char *operand = NULL;
	int value = 0;

	operand = strtok(NULL, " \t\r\n");
	if (operand != NULL)
	{
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
	stack_t *current_head = NULL, *next = NULL;

	if (tracker.node_count == 0)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current_head = *stack;
		next = current_head->next;
		if (next)
		{
			current_head->next = NULL;
			next->prev = NULL;
			*stack = next;
		}
		else
			*stack = NULL;
		free(current_head);
		tracker.node_count--;
	}
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
	stack_t *current_head = NULL, *next = NULL;
	int temp = 0;

	if (tracker.node_count < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current_head = *stack;
	next = current_head->next;

	temp = next->n;
	next->n = current_head->n;
	current_head->n = temp;
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
	stack_t *current = NULL;
	size_t i = 0;
	int temp = 0;

	line_number = line_number;
	if (tracker.node_count < 2)
		return;
	current = *stack;
	temp = current->n;

	for (; current; i++)
	{
		if (current->next == NULL)
		{
			current->n = temp;
			return;
		}
		else
			current->n = (current->next)->n;
		current = current->next;
	}
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
	stack_t *current = NULL;
	size_t i = 0;
	int tail_temp = 0;

	line_number = line_number;

	if (tracker.node_count < 2)
		return;
	current = *stack;
	current = traverse_to_tail(current);
	tail_temp = current->n;

	for (; current; i++)
	{
		if (current->prev == NULL)
		{
			current->n = tail_temp;
			return;
		}
		else
			current->n = (current->prev)->n;
		current = current->prev;
	}
}
