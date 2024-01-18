#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **nice_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (nice_node == NULL || *nice_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nice_node;
		return;
	}
	tmp = head;
	head = *nice_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **tack, unsigned int rof_number)
{
	stack_t *tmp;

	(void) rof_number;
	if (tack == NULL)
		exit(EXIT_FAILURE);
	tmp = *tack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **tack, unsigned int rof_number)
{
	stack_t *tmp;

	if (tack == NULL || *tack == NULL)
		more_err(7, rof_number);

	tmp = *tack;
	*tack = tmp->next;
	if (*tack != NULL)
		(*tack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **ack, unsigned int li_number)
{
	if (ack == NULL || *ack == NULL)
		more_err(6, li_number);
	printf("%d\n", (*ack)->n);
}
