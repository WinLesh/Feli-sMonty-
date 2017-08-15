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
		return (NULL);
	node->n = n;
	node->prev = prev;
	node->next = next;

	return (node);
}

/**
 * add_cell - Adds node to head of linked list
 * @head: Double pointer to head of linked list
 * @n: The number to instantiate the new head with
 *
 * Return: Address of the new head
 */
stack_t *add_cell(stack_t **head, const int n)
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
