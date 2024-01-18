#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **tack, unsigned int line_first)
{
	(void)tack;
	(void)line_first;
}


/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int first_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, first_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **ack, unsigned int line_number)
{
	int over;

	if (ack == NULL || *ack == NULL || (*ack)->next == NULL)
		more_err(8, line_number, "add");

	(*ack) = (*ack)->next;
	over = (*ack)->n + (*ack)->prev->n;
	(*ack)->n = over;
	free((*ack)->prev);
	(*ack)->prev = NULL;
}


/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int l_num)
{
	int over;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, l_num, "sub");


	(*stack) = (*stack)->next;
	over = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = over;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int one_number)
{
	int over;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, one_number, "div");

	if ((*stack)->n == 0)
		more_err(9, one_number);
	(*stack) = (*stack)->next;
	over = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = over;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
