#include "monty.h"
/**
 * tokenize - Tokenizes the input line.
 */
void tokenize(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *linecpy = NULL;

	linecpy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	strcpy(linecpy, arguments->line);
	arguments->n_tokens = 0;
	token = strtok(linecpy, delims);
	while (token)
	{
		arguments->n_tokens += 1;
		token = strtok(NULL, delims);
	}

	arguments->line_strs = malloc(sizeof(char *) *
			(arguments->n_tokens + 1));
	strcpy(linecpy, arguments->line);
	token = strtok(linecpy, delims);
	while (token)
	{
		arguments->line_strs[i] = malloc(sizeof(char) *
				(strlen(token) + 1));
		if (arguments->line_strs[i] == NULL)
			malloc_failed();
		strcpy(arguments->line_strs[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	arguments->line_strs[i] = NULL;
	free(linecpy);
}