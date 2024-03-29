#include "monty.h"

/**
 * mod - computes head->n % head->next->n
 * element of the stack by the top element of the stack
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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

	ptr2->n = ptr2->n % ptr1->n;
	delete_stack_Top_node();

	arguments->stack_length -= 1;
}
