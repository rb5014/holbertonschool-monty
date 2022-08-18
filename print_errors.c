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
		fprintf(stderr, "L%u: unknown instruction %s\n", linenum, tok);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		break;
	case 5:
		fprintf(stderr, "L%u: usage: push integer\n", linenum);
		exit(EXIT_FAILURE);
		break;
	case 6:
		fprintf(stderr, "L%u: can't pint, stack empty\n", linenum);
		exit(EXIT_FAILURE);
		break;
	case 7:
		fprintf(stderr, "L%u: can't pop an empty stack\n", linenum);
		exit(EXIT_FAILURE);
		break;
	case 8:
		fprintf(stderr, "L%u: can't swap, stack too short\n", linenum);
		exit(EXIT_FAILURE);
		break;
	case 9:
		fprintf(stderr, "L%u: can't add, stack too short\n", linenum);
		exit(EXIT_FAILURE);
		break;
	}
}
