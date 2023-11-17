#include "monty.h"
/**
 * validate_args - argument validation function.
 * @argc: number of command line args
*/
void validate_args(int argc)
{
	if (argc == 2)
		return;
	perror("USAGE: monty file\n");
	exit(EXIT_FAILURE);
}