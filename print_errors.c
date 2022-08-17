#include "monty.h"

/**
 * print_error - print error with line number
 * @errornum: error identifier
 * @linenum: line number where error was found
 * @tok: token that isn't an instruction
 * @arg: arg that isn't a file
 */

void print_error(char *tok, char *arg, int errornum, unsigned int linenum)
{
	switch (errornum)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
		break;
	case 3:
		fprintf(stderr, "L%d: unknown instruction %s\n", linenum, tok);
		exit(EXIT_FAILURE);
		break;
	}
}
