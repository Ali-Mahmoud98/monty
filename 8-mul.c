#include "monty.h"
/**
 * mul - multiplies the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	ptr1 = arguments->stackHead;
	ptr2 = ptr1->next;

	if (ptr1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	ptr2->n = ptr2->n * ptr1->n;
	delete_stack_Top_node();

	arguments->stack_length -= 1;
}
