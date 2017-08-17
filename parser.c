#include "monty.h"

/**
 * find_code - Tries to find the correct opcode and does respective action
 * @token: The current token
 * @linenum: The current line number
 *
 * Return: None
 */
void find_code(char *token, unsigned int linenum)
{
	size_t i = 0;
	instruction_t codes[] = {
		{"push", push_node}, {"pall", print_all},
		{"pint", print_top}, {"pop", pop_node},
		{"swap", swap_two_nodes}, {"add", add_two_nodes},
		{"nop", do_nothing}, {"sub", sub_two_nodes},
		{"div", div_two_nodes}, {"mul", mul_two_nodes},
		{"mod", mod_two_nodes}, {"pchar", print_top_char},
		{"pstr", print_string}, {"rotl", rotate_top_to_bottom},
		{"rotr", rotate_bottom_to_top}, {"stack", enable_stack_mode},
		{"queue", enable_queue_mode}, {NULL, NULL}
	};

	while (codes[i].opcode)
	{
		if (!strcmp(token, codes[i].opcode))
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
	size_t n_buf = 0;
	unsigned int linenum = 0;
	ssize_t n_chars = 0;
	char *token = NULL;

	while ((n_chars = getline(&(tracker.buffer), &n_buf, monty_file)) != -1)
	{
		linenum++;
		token = strtok(tracker.buffer, "\n \r\t");
		if (!token || (!strncmp(token, "#", 1)) || (n_chars == 0))
			continue;
		find_code(token, linenum);
	}
	free(tracker.buffer);
	tracker.buffer = NULL;
}
