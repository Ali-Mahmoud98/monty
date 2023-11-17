#include "monty.h"
/**
 * rotr - The last element of the stack becomes the top element of the stack.
 * @stack: pointer to pointer to stack_t.
 * @line_number: number.
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	(void) stack;
	(void) line_number;
	if (arguments->stack_length < 2)
		return;
	ptr1 = arguments->stackHead;
	ptr2 = ptr1->next;
	while (ptr2)
	{
		if (!ptr2->next)
		{
			ptr2->next = ptr1;
			ptr2->prev->next = NULL;
			ptr2->prev = NULL;
			ptr1->prev = ptr2;
			arguments->stackHead = ptr2;
			break;
		}
		ptr2 = ptr2->next;
	}
	
}
