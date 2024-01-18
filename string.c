#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @tack: Pointer to a pointer pointing to top node of the stack.
 * @fi_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **tack, unsigned int fi_number)
{
	int tota;

	if (tack == NULL || *tack == NULL)
		string_err(11, fi_number);

	tota = (*tack)->n;
	if (tota < 0 || tota > 127)
		string_err(10, fi_number);
	printf("%c\n", tota);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asky;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		asky = tmp->n;
		if (asky <= 0 || asky > 127)
			break;
		printf("%c", asky);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @mem: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **mem, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (mem == NULL || *mem == NULL || (*mem)->next == NULL)
		return;

	tmp = *mem;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *mem;
	(*mem)->prev = tmp;
	*mem = (*mem)->next;
	(*mem)->prev->next = NULL;
	(*mem)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @non: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **non, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (non == NULL || *non == NULL || (*non)->next == NULL)
		return;

	tmp = *non;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *non;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*non)->prev = tmp;
	(*non) = tmp;
}
