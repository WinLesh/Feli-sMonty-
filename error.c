#include "monty.h"

/**
 * check_argument_error - Checks number of arguments
 * @argc: The number of arguments
 *
 * Return: None
 */
void check_argument_error(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_file_read_error - Errors out if file can't be read
 * @filename: The name of the file
 *
 * Return: None
 */
void execute_file_read_error(char *filename)
{
	printf("Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
