#include "monty.h"
/**
 * free_arg - Frees the memory allocated for the argument
 * structure and its members.
 */
void free_args(void)
{
	if (arguments == NULL)
		return;

	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction = NULL;
	}

	free_stackHead();

	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}

	free(arguments);
}

/**
 * closeStream - Closes the file stream and sets it to NULL.
 */
void closeStream(void)
{
	if (arguments->stream)
	{
		fclose(arguments->stream);
		arguments->stream = NULL;
	}
}
/**
 * free_toks - Frees the allocated memory for tokens.
 */
void free_toks(void)
{
	int i = 0;

	if (arguments->line_strs)
	{
		while (arguments->line_strs[i])
		{
			free(arguments->line_strs[i]);
			i++;
		}
		free(arguments->line_strs);
	}
}

/**
 * free_all_args - Frees all allocated memory for arguments.
 */
void free_all_args(void)
{
	closeStream();
	free_toks();
	free_args();
}
/**
 * free_stackHead - Frees the memory allocated for the stackHead and
 * sets it to NULL.
 */
void free_stackHead(void)
{
	if (arguments->stackHead)
		free_stack(arguments->stackHead);

	arguments->stackHead = NULL;
}
/**
* free_stack - free the nodes in a stack list
* @head: first node of a dlistint link
* Return: void
*/
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack(head->next);
	}

	free(head);
}
