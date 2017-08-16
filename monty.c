#include "monty.h"

tracker_t tracker;

void cleanup(void)
{
	free_list();
	free(tracker.buffer);
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
	free_list();
	fclose(bytecode_file);
	return (0);
}
