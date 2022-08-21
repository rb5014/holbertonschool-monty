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
	{
		print_error(filename, 2, 0);
		return (NULL);
	}
	return (file);
}

/**
 * _read - read the line
 * @file: file opened that will be red
 * Return: Errstatus, 0 if success, -1 otherwise
 */

 int _read(FILE *file)
{
	int linenum, errstatus;
	size_t len = 0;
	char *line = NULL;
	stack_t *s = NULL;
	instruction_t list[] = {{"push", fpush}, {"pall", fpall}, {"pint", fpint},
			     {"pop", fpop}, {"add", fadd}, {"nop", fnop},
			     {"swap", fswap}, {NULL, NULL}}; 

	for (linenum = 1; getline(&line, &len, file) != EOF; linenum++)
	{
		errstatus = _find_f(&s, list, &line, linenum);
		if (errstatus == 0)
			continue;
	}
	free_all(s, line, file);
	return (errstatus);
}
/**
 * _find_function - define the array of structures with the names of the functions 
 * Return: 0 if success, -1 otherwise
 */

int _find_f(stack_t **s, instruction_t list[], char **line, int linenum)
{
	int i;
	char *delim = " \n";

	token = strtok(*line, delim);
	if (!(token))
		return (0);
	for (i = 0; list[i].opcode != NULL; i++)
	{
		if (strcmp(token, list[i].opcode) == 0)
		{
			if (i == 0)
			{
				token = strtok(NULL, delim);
				if (is_number(token) == 0)
				{
					print_error(NULL, 5, linenum);
					return (-1);
				}
			}
			list[i].f(s, linenum);
			return(0);
		}
	}
	if (list[i].opcode == NULL)
	{
		print_error(token, 3, linenum);
		return (-1);	
	}
	return (0);
}