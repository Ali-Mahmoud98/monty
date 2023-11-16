#include "monty.h"
/**
 * swap - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		arguments->stack_length++;
	}
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		closeStream();
		free_args();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
