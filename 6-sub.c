#include "monty.h"
/**
  *sub- sustration
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int sus, nodes;

	aux = *stack;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		closeStream();
		free_args();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*stack = aux->next;
	free(aux);
}