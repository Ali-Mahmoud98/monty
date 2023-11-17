#include "monty.h"

/**
 * pstr - printing the string starting at the top of the stack,
 * followed by a new line
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr2str;

	(void) stack;
	(void) line_number;

	ptr2str = arguments->stackHead;

	while (ptr2str != NULL)
	{
		if (ptr2str->n <= 0 || ptr2str->n > 127)
			break;
		printf("%c", ptr2str->n);
		ptr2str = ptr2str->next;
	}

	printf("\n");
}