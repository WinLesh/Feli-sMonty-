#include "monty.h"

/**
 * init_tracker - Initializes the tracker
 *
 * Return: None
 */
void init_tracker(void)
{
	stack_t *head;

	head = NULL;
	tracker.head = head;
	tracker.node_count = 0;
	tracker.mode = 's';
	tracker.buffer = NULL;
}
