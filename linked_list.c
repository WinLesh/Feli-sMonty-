#include "monty.h"

/**
 * create_cell - Creates a new node
 * @n: The data
 * @prev: The previous node
 * @next: The next node
 *
 * Return: The address of the node or NULL
 */
stack_t *create_cell(int n, stack_t *prev, stack_t *next)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = prev;
	node->next = next;

	return (node);
}

/**
 * add_cell_to_start - Adds node to head of linked list
 * @head: Double pointer to head of linked list
 * @n: The number to instantiate the new head with
 *
 * Return: Address of the new head
 */
stack_t *add_cell_to_start(stack_t **head, int n)
{
	stack_t *new_node = NULL, *current_head = NULL;

	if (head == NULL)
		return (NULL);
	new_node = create_cell(n, NULL, NULL);
	if (new_node == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	current_head = *head;
	current_head->prev = new_node;
	new_node->next = current_head;
	*head = new_node;
	return (*head);
}

/**
 * add_cell_to_end - Add node to the tail of list
 * @head: The head of the list
 * @n: The data to instantiate new node with
 *
 * Return: The new node's address or NULL
 */
stack_t *add_cell_to_end(stack_t **head, int n)
{
	stack_t *new_node = NULL, *current_tail = NULL;

	if (head == NULL)
		return (NULL);
	new_node = create_cell(n, NULL, NULL);
	if (new_node == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	current_tail = traverse_to_tail(*head);
	current_tail->next = new_node;
	new_node->prev = current_tail;
	return (new_node);
}

/**
 * print_cells - Print out all elements of a list
 * @h: The head of a list
 *
 * Return: The number of elements in a list
 */
size_t print_cells(stack_t *h)
{
	size_t i;

	for (i = 0; h; i++)
	{
		printf("%i\n", h->n);
		h = h->next;
	}
	return (i);
}

/**
 * free_cells - Frees the entire linked list
 * @head: The head of the list
 *
 * Return: Void
 */
void free_cells(stack_t *head)
{
	stack_t *current_head = NULL;

	while (head)
	{
		current_head = head;
		head = head->next;
		free(current_head);
	}
}
