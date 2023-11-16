#include "monty.h"
/**
* is_comment - checks the line_strs if it starts with #"
* Return: 0 or 1
*/
int is_comment(void)
{
	if (
		arguments->line_strs &&
		arguments->line_strs[0] &&
		arguments->line_strs[0][0] == '#'
	)
		return (1);

	return (0);
}
