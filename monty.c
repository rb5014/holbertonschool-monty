#include "monty.h"

/**
 * main - entry point
 * @argc: nb of arguments
 * @argv: array of strings
 * Return: 0 if success, EXIT_FAILURE if fail
 */
int main(int argc, char **argv)
{
	FILE  *file;
	int linenum = 0, i;
	size_t len = 0;
	char *line = NULL, *delim = " \n", *token;
	instruction_t k[] = {{"push", fpush}, {"pall", fpall}, {NULL, NULL}};
	stack_t *s = NULL;


	if (argc != 2)
	{
		print_error(NULL, NULL, 1, linenum);
	}
	file = fopen(argv[1], "r");
	if (file  == NULL)
	{
		print_error(NULL, argv[1], 2, linenum);
	}
	while (getline(&line, &len, file) != EOF)
	{
		linenum++;
		token = strtok(line, delim);
		for (i = 0; k[i].opcode != NULL; i++)
		{
			if (strcmp(token, k[i].opcode) == 0)
			{
				token = strtok(NULL, delim);
				if (token != NULL)
					p = atoi(token);
				k[i].f(&s, linenum);
				break;
			}
			if (k[i + 1].opcode == NULL)
				print_error(token, NULL, 3, linenum);
		}
	}
	free(line);
	fclose(file);
	return (0);
}
