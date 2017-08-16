#include "monty.h"

tracker_t tracker;

/**
 * cleanup - Cleanup, cleanup
 *
 * Return: None
 */
void cleanup(void)
{
	if (tracker.node_count > 0)
		free_list();
	if (tracker.buffer)
		free(tracker.buffer);
	if (tracker.file)
		fclose(tracker.file);
}

/**
 * main - Entry Point
 * @argc: Number of arguments
 * @argv: The arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *bytecode_file = NULL;

	check_argument_error(argc);
	bytecode_file = fopen(argv[1], "r");
	if (!bytecode_file)
		execute_file_read_error(argv[1]);
	atexit(cleanup);
	init_tracker(bytecode_file);
	parse_file(bytecode_file);
	return (0);
}
