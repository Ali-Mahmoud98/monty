#include "monty.h"
/**
 * divn - divides the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void divn(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		closeStream();
		free_args();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		closeStream();
		free(arguments->line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*stack = h->next;
	free(h);
}
