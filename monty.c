#include "monty.h"

/**
 * main - entry point
 * @argc: nb of arguments
 * @argv: array of strings
 * Return: 0 if success, EXIT_FAILURE if fail
 */
int p = 0;
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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file  == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
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
				fprintf(stderr, "L%d: unknown instruction %s\n", linenum, token);
		}
	}
	free(line);
	fclose(file);
	return (0);
}
