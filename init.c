#include "monty.h"

/**
 * init_tracker - Initializes the tracker
 * @file: Pointer to Monty ByteCode file
 * Return: None
 */
void init_tracker(FILE *file)
{
	stack_t *head;

	head = NULL;
	tracker.head = head;
	tracker.node_count = 0;
	tracker.mode = 's';
	tracker.buffer = NULL;
	tracker.file = file;
}
