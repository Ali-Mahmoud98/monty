#include "monty.h"
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	arguments->stack = 0;
}
/**
 * stack - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	arguments->stack = 1;
}
