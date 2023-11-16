#include "monty.h"
/**
 * run_instruction - Runs the instruction specified by the arguments.
 */

void run_instruction(void)
{
	stack_t *stack = NULL;

	if (arguments->n_tokens == 0 || arguments->isComment)
		return;

	arguments->instruction->f(&stack, arguments->line_number);
}

/**
 * invalid_instruction - Handles an unknown instruction error.
 */

void invalid_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			arguments->line_number, arguments->line_strs[0]);
	closeStream();
	free_toks();
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * setStream - Sets the stream for reading from the specified file.
 * @fileName: Name of the file to open and set as the stream.
 */

void setStream(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		read_failed(fileName);

	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		read_failed(fileName);
	}
}

/**
 * setInstruction - Sets the instruction based on the first token
 * in the input line.
 */

void setInstruction(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &div},
		{"mul", &mul},
		{NULL, NULL}
	};

	if (arguments->n_tokens == 0) /* no instructions */
		return;

	arguments->isComment = 0;
	if (is_comment())
	{
		arguments->isComment = 1;
		return;
	}

	for (; instructions[i].opcode != NULL; i++)
	{
		/* compare opcode of instruction to first token (instruct..) */
		if (strcmp(instructions[i].opcode, arguments->line_strs[0])
				== 0)
		{
			arguments->instruction->opcode = instructions[i].opcode;
			arguments->instruction->f = instructions[i].f;
			return;
		}
	}

	invalid_instruction();
}
