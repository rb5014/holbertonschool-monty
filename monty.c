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
	int linenum, i;
	size_t len = 0;
	char *line = NULL, *delim = " \n", *token, *token2;
	instruction_t k[] = {{"push", fpush}, {"pall", fpall}, {NULL, NULL}};
	stack_t *s = NULL;


	if (argc != 2)
		print_error(NULL, NULL, 1, 0);
	file = fopen(argv[1], "r");
	if (file  == NULL)
		print_error(NULL, argv[1], 2, 0);
	for (linenum = 1; getline(&line, &len, file) != EOF; linenum++)
	{
		token = strtok(line, delim);
		if (!(token))
			continue;
		for (i = 0; k[i].opcode != NULL; i++)
		{
			if (strcmp(token, "push") == 0)
			{
				token2 = strtok(NULL, delim);
				if (token2 != NULL && is_number(token2))
					p = atoi(token2);
				else
					print_error(NULL, NULL, 5, linenum);
			}
			if (strcmp(token, k[i].opcode) == 0)
			{
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
