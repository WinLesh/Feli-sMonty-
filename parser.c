#include "monty.h"

/**
 * _isdigit - Checks if operand is a digit for push opcode
 * @operand: The operand in question
 *
 * Return: 1 if true, 0 if false
 */
int _isdigit(char *operand)
{
	char c;
	size_t i = 0;

	if (operand[0] == '-')
		i++;
	for (; operand[i]; i++)
	{
		c = operand[i];
		if ((c < '0') || (c > '9'))
			return (0);
	}
	return (1);
}

/**
 * find_code - Tries to find the correct opcode and does respective action
 * @code: The instruction struct
 * @token: The current token
 * @linenum: The current line number
 *
 * Return: None
 */
void find_code(instruction_t code, char *token, unsigned int linenum)
{
	char *operand = NULL;

	if (!strcmp(token, "push"))
	{
		operand = strtok(NULL, " ");
		if (_isdigit(operand))
			process(codes[i].f, linenum, atoi(operand));
		else
			execute_push_error(linenum);
	}
	else if (!strcmp(token, code.opcode))
		code.f(&(tracker.head), linenum);
	else
		execute_invalid_opcode_error(linenum);
}

/**
 * parse_file - Parses the file
 * @monty_file: Pointer to the file stream
 *
 * Return: None
 */
void parse_file(FILE *monty_file)
{
	instruction_t **codes = init_instructions();
	char *buffer = NULL;
	size_t *buffer_size = NULL;
	size_t i = 0;
	unsigned int linenum = 0;
	ssize_t chars_read = 0;
	char *token = NULL;

	while ((chars_read = getline(&buffer, &buffer_size, monty_file)) != -1)
	{
		num_lines++;
		token = strtok(buffer, " ");
		if ((!strncmp(token, "#", 1)) || (chars_read == 0))
			continue;
		while (codes[i].opcode)
		{
			find_code(codes[i], token, linenum);
			i++;
		}
	}
}
