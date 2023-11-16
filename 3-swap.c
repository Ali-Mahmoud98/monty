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
	int len = 0;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(arguments->stream);
		free(arguments->line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = (*stack)->next;
	(*stack)->prev = h->prev;
	h->prev = *stack;
	*stack = h;
}
