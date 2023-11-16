#include "monty.h"

args_t *arguments = NULL;
/**
 * main - entry point.
 * @argc: number of args.
 * @argv: array of strings.
 *
 * Return: 0 means SUCCESS
*/
int main(int argc, char** argv)
{
	ssize_t lines_read = 0;
	size_t n = 0;

	validate_args(argc);
	init_args();
	get_stream(argv[1]);

	arguments = malloc(sizeof(args_t));
	if (arguments == NULL)
		malloc_failed();

	init_arg();
	setStream(argv[1]);

	while ((lines_read = getline(&arguments->line, &n, arguments->stream)) != -1)
	{
		arguments->line_number += 1;
		tokenize();
		setInstruction();
		runInstruction();
		free_toks();
	}

	closeStream();
	free_arg();

	return (0);
}
