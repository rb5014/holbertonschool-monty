#include "monty.h"
char *token;
/**
 * _fopen - fopen a file stream
 * @filename: name of the file to open
 *
 * Return: pointer to the file opened, exit_failure if failed
 */

FILE *_fopen(char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
	if (file  == NULL)
		print_error(NULL, filename, 2, 0);
	return (file);
}

/**
 * _read - read the line
 * @file: file opened that will be red
 */

void _read(FILE *file)
{
	int linenum, i;
	size_t len = 0;
	char *line = NULL, *delim = " \n";
	instruction_t k[] = {{"push", fpush}, {"pall", fpall}, {"pint", fpint},
			     {"pop", fpop}, {"add", fadd}, {"nop", fnop},
			     {"swap", fswap}, {NULL, NULL}};
	stack_t *s = NULL;

	for (linenum = 1; getline(&line, &len, file) != EOF; linenum++)
	{
		token = strtok(line, delim);
		if (!(token))
			continue;
		for (i = 0; k[i].opcode != NULL; i++)
		{
			if (strcmp(token, k[i].opcode) == 0)
			{
				if (i == 0)
				{
					token = strtok(NULL, delim);
					if (is_number(token) == 0)
					{
						free_all(s, line, file);
						print_error(NULL, NULL, 5, linenum);
					}
				}
				k[i].f(&s, linenum);
				break;
			}
		}
		if (k[i].opcode == NULL)
		{
			print_error(token, NULL, 3, linenum);
			free_all(s, line, file);
		}
	}
	free_all(s, line, file);
}
