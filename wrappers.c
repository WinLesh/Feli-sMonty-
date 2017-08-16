#include "monty.h"

/**
 * add_cell - Creates a node and adds onto stack
 * @head: The address of the head pointer
 * @value: The value to instantiate node with
 *
 * Return: None
 */
void add_cell(stack_t **head, int value)
{
	if (tracker.mode == 's')
		add_cell_to_start(head, value);
	else if (tracker.mode == 'q')
		add_cell_to_end(head, value);
	tracker.node_count++;
}
