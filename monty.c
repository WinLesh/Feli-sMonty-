#include "monty.h"

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
	init_tracker();
	parse_file(bytecode_file);
	free_list();
	fclose(bytecode_file);
	return (0);
}
