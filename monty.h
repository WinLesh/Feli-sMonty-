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
	char *buffer;
	FILE *file;
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

/* Nothing */
void do_nothing(stack_t **stack, unsigned int line_number);

/* Errors */
void check_argument_error(int argc);
void execute_file_read_error(char *filename);
void execute_invalid_opcode_error(unsigned int linenum, char *opcode);

/* Initialization */
void init_tracker(FILE *file);

/* Free */
void free_list();

/* Helpers */
char *_isdigit(char *operand);
stack_t *traverse_to_tail(stack_t *head);
void print_head_cell(stack_t *head);

/* Wrappers */
void add_cell(stack_t **head, int value);

/* Linked List implementation */
stack_t *create_cell(int n, stack_t *prev, stack_t *next);
stack_t *add_cell_to_start(stack_t **head, const int n);
stack_t *add_cell_to_end(stack_t **head, int n);
size_t print_cells(stack_t *h);
void free_cells(stack_t *head);

/* Parser */
void parse_file(FILE *monty_file);

/* Print */
void print_all(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void print_top_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);

/* Calculator */
void add_two_nodes(stack_t **stack, unsigned int line_number);
void sub_two_nodes(stack_t **stack, unsigned int line_number);
void div_two_nodes(stack_t **stack, unsigned int line_number);
void mul_two_nodes(stack_t **stack, unsigned int line_number);
void mod_two_nodes(stack_t **stack, unsigned int line_number);

/* Mutate */
void push_node(stack_t **stack, unsigned int line_number);
void pop_node(stack_t **stack, unsigned int line_number);
void swap_two_nodes(stack_t **stack, unsigned int line_number);
void rotate_top_to_bottom(stack_t **stack, unsigned int line_number);
void rotate_bottom_to_top(stack_t **stack, unsigned int line_number);

/* Mode */
void enable_stack_mode(stack_t **stack, unsigned int line_number);
void enable_queue_mode(stack_t **stack, unsigned int line_number);
#endif
