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
 * strip_newline - Strips the newline
 * @token: The token
 *
 * Return: None
 */
void strip_newline(char *token)
{
	size_t i = 0;

	for (; token[i] != '\n'; i++)
		;
	token[i] = '\0';
}

/**
 * find_code - Tries to find the correct opcode and does respective action
 * @code: The instruction struct
 * @token: The current token
 * @linenum: The current line number
 *
 * Return: None
 */
void find_code(char *token, unsigned int linenum)
{
	char *operand = NULL;
	tracker_t tracker;
	int oper_int = 0;
	size_t i = 0;
	instruction_t codes[] = {
		{"push", dummy_handler},
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop_node},
		{"swap", swap_two_nodes},
		{"add", add_two_nodes},
		{"nop", do_nothing},
		{"sub", sub_two_nodes},
		{"div", div_two_nodes},
		{"mul", mul_two_nodes},
		{"mod", mod_two_nodes},
		{"pchr", print_top_char},
		{"pstr", print_string},
		{"rotl", rotate_top_to_bottom},
		{"rotr", rotate_bottom_to_top},
		{"stack", enable_stack_mode},
		{"queue", enable_queue_mode},
		{NULL, NULL}
	};

	strip_newline(token);
	while (codes[i].opcode)
	{
		if (!strcmp(token, "push"))
		{
			operand = strtok(NULL, " ");
			printf("find_code %s\n", operand);
			if (_isdigit(operand))
			{
				oper_int = atoi(operand);
				push_node(&(tracker.head), linenum, oper_int);
				return;
			}
			else
				execute_push_error(linenum);
		}
		else if (!strcmp(token, codes[i].opcode))
		{
			codes[i].f(&(tracker.head), linenum);
			return;
		}
		i++;
	}
	execute_invalid_opcode_error(linenum, token);
}

/**
 * parse_file - Parses the file
 * @monty_file: Pointer to the file stream
 *
 * Return: None
 */
void parse_file(FILE *monty_file)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	unsigned int linenum = 0;
	ssize_t chars_read = 0;
	char *token = NULL;

	while ((chars_read = getline(&buffer, &buffer_size, monty_file)) != -1)
	{
		linenum++;
		token = strtok(buffer, " ");
		printf("parse_file %s\n", token);
		if ((!strncmp(token, "#", 1)) || (chars_read == 0))
			continue;
		find_code(token, linenum);
	}
	free(buffer);
}
