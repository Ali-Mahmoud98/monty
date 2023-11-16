#include "monty.h"
/**
 * swap - swap the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	ptr1 = arguments->stackHead;
	ptr2 = ptr1->next;
	if (ptr1->next)
		ptr1->next->prev = ptr1;
	ptr2->next = ptr1;
	ptr2->prev = NULL;
	ptr1->prev = ptr2;
	arguments->stackHead = ptr2;
}
