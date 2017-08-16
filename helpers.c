#include "monty.h"

/**
 * _isdigit - Checks if operand is a digit for push opcode
 * @operand: The operand in question
 *
 * Return: 1 if true, 0 if false
 */
char *_isdigit(char *operand)
{
	char c;
	size_t i = 0;

	if (operand[0] == '-')
		i++;
	for (; operand[i]; i++)
	{
		c = operand[i];
		if (c == '\n')
		{
			c = '\0';
			break;
		}
		if ((c < '0') || (c > '9'))
			return (NULL);
	}
	return (operand);
}

/**
 * traverse_to_tail - Traverses to tail of list
 * @head: The head of the list
 *
 * Return: Adddress of the tail node
 */
stack_t *traverse_to_tail(stack_t *head)
{
	size_t i;

	if (head == NULL)
		return (NULL);
	for (i = 0; head->next; i++)
	{
		if (head->next)
			head = head->next;
	}
	return (head);
}

/**
 * print_head_cell - Prints the data in head
 * @head: The head node
 *
 * Return: None
 */
void print_head_cell(stack_t *head)
{
	printf("%i\n", head->n);
}
