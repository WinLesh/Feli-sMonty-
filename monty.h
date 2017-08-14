#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct stack_tracker - holds global program state
 * @head: The head of our linked list
 * @node_count: The number of nodes our list has
 * @mode: Whether our stack is a stack or queue
 *
 * Description: global variable that tracks information
 * critical to our program
 */

typedef struct stack_tracker
{
	stack_t *head;
	size_t node_count;
	char mode;
} tracker_t;

extern tracker_t tracker;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Wrapper */
typedef void (*op_handler)(stack_t **stack, unsigned int line_number);
void process(op_handler handler, unsigned int linenum, int val);

/* Errors */
void check_argument_error(int argc);
void execute_file_read_error(char *filename);
void execute_push_error(unsigned int linenum);
void execute_invalid_opcode_error(unsigned int linenum);

/* Initialization */
void init_tracker();
instruction_t **init_instructions();

/* Parser */
void parse_file(FILE *monty_file);

#endif
