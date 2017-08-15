#include "monty.h"

/**
 * free_list - Frees the list
 *
 * Return: None
 */
void free_list(void)
{
	free_cells(tracker.head);
	tracker.head = NULL;
	tracker.node_count = 0;
}
