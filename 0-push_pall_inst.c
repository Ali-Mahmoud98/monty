#include "monty.h"
/**
 * push - Pushes an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the push function is called.
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (arguments->n_tokens <= 1 || !(is_number(arguments->line_strs[1])))
	{
		free_args();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();
	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = (int) atoi(arguments->line_strs[1]);

	if (arguments->stackHead == NULL)
	{
		arguments->stackHead = *stack;
	}
	else
	{
		if (arguments->stack)
		{
			(*stack)->next = arguments->stackHead;
			arguments->stackHead->prev = *stack;
			arguments->stackHead = *stack;
		}
		else
		{
			stack_t *tmp = arguments->stackHead;

			while (tmp->next)
				tmp = tmp->next;
			tmp->next = *stack;
			(*stack)->prev = tmp;
		}
	}
	arguments->stack_length += 1;
}

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pall function is called.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (arguments->stackHead == NULL)
		return;

	(void) line_number;
	(void) stack;

	tmp = arguments->stackHead;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}