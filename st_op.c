#include "monty.h"

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **rock, unsigned int line_number)
{
	int over;

	if (rock == NULL || *rock == NULL || (*rock)->next == NULL)
		more_err(8, line_number, "mul");

	(*rock) = (*rock)->next;
	over = (*rock)->n * (*rock)->prev->n;
	(*rock)->n = over;
	free((*rock)->prev);
	(*rock)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **ack, unsigned int li_num)
{
	int over;

	if (ack == NULL || *ack == NULL || (*ack)->next == NULL)

		more_err(8, li_num, "mod");


	if ((*ack)->n == 0)
		more_err(9, li_num);
	(*ack) = (*ack)->next;
	over = (*ack)->n % (*ack)->prev->n;
	(*ack)->n = over;
	free((*ack)->prev);
	(*ack)->prev = NULL;
}
