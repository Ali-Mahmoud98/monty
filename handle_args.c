#include "monty.h"
/**
 * malloc_faild - handle the failure of allocation.
*/
void malloc_faild()
{
    dprintf(2, "Error: malloc failed\n");
    free_args();
    exit(EXIT_FAILURE);
}
/**
 * init_args - initializing arguments.
*/
void init_args()
{
    arguments = malloc(sizeof(args_t));
    if (arguments == NULL)
        malloc_faild();
    
    arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_failed();

	arguments->stackHead = NULL;
	arguments->line = NULL;

	arguments->n_tokens = 0;
	arguments->isComment = 0;
	arguments->line_number = 0;
	arguments->stack = 1;
	arguments->stack_length = 0;
	arguments->stream = NULL;
}

/**
 * read_failed - Handles the error when reading a file fails.
 * @fileName: The name of the file that failed to open.
 */
void read_failed(char *fileName)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	free_arg();
	exit(EXIT_FAILURE);
}
