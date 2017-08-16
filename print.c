#include "monty.h"

/**
 * print_all - print all nodes in linked list
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	print_cells(*stack);
	line_number = line_number;
}

/**
 * print_top - print node at top of stack
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (tracker.node_count == 0)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	print_head_cell(*stack);
}

/**
 * print_top_char - print first char at top node of stack
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void print_top_char(stack_t **stack, unsigned int line_number)
{
	stack_t *current_head = NULL;
	int value = 0;

	if (tracker.node_count == 0)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	current_head = *stack;
	value = current_head->n;
	if (value < 0 || value > 127)
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(value);
	putchar('\n');
}

/**
 * print_string - print string in node
 * @stack: Address to the head pointer
 * @line_number: The current line number
 *
 * Return: None
 */
void print_string(stack_t **stack, unsigned int line_number)
{
	size_t i;
	stack_t *current;

	line_number = line_number;
	current = *stack;
	for (i = 0; current; i++)
	{
		if ((current->n < 1) || (current->n > 127))
		{
			putchar('\n');
			return;
		}
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
